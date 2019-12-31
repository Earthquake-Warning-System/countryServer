#include <sys/time.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <ev.h>
#include <hiredis.h>
#include "EQ_redis.h"
#include "EQ_judgement.h"
#include "EQ_interface.h"
#include "EQ_config.h"
#include "interface.pb-c.h"

int init_weighted_events = 0;
int* total_weighted_events = &init_weighted_events;
int s_fd; //socket's fd of local server
char s_id[13];//server macaddress(server_id)
freeze_timer freeze;
judge_timer judge;
int bs_response ;

void die(char *s)
{
    perror(s);
    exit(1);
}

int send_kp_to_client(char *client_ip, int c_port)
{
    KpAlive respond_kp;
    int len_of_pack;
    struct sockaddr_in c_outland;
    int c_len = sizeof(c_outland);
    kp_alive__init(&respond_kp);
    respond_kp.packet_type = "0";
    len_of_pack = kp_alive__get_packed_size(&respond_kp);
    char buf_send[len_of_pack];
    memset( buf_send ,'\0',sizeof(buf_send));
    int size = kp_alive__pack(&respond_kp, (uint8_t *)buf_send);
    memset((char *)&c_outland, 0, sizeof(c_outland));
    c_outland.sin_family = AF_INET;
    c_outland.sin_port = htons(c_port);
    inet_aton(client_ip, &c_outland.sin_addr);

    while(sendto(s_fd, buf_send, size , 0, (struct sockaddr *)&c_outland, c_len)==-1){
      printf("send_kp_to_client ip:%s port:%d Failed!!!", client_ip, c_port);
      usleep(100);
    }
    return 0;
}

int send_ack_to_client(char *client_ip, int c_port)
{
    KpAliveAck respond_ack;
    int len_of_pack;
    struct sockaddr_in c_outland;
    int c_len = sizeof(c_outland);

    kp_alive_ack__init(&respond_ack);
    respond_ack.packet_type = "5";
    respond_ack.role = 1;
    respond_ack.version = "1.0.0";
    respond_ack.server_id = s_id;
    len_of_pack = kp_alive_ack__get_packed_size(&respond_ack);
    char buf_send[len_of_pack];
    memset( buf_send ,'\0',sizeof(buf_send));
    int size = kp_alive_ack__pack(&respond_ack, (uint8_t *)buf_send);

    memset((char *)&c_outland, 0, sizeof(c_outland));
    c_outland.sin_family = AF_INET;
    c_outland.sin_port = htons(c_port);
    inet_aton(client_ip, &c_outland.sin_addr);

    while(sendto(s_fd, buf_send, size , 0, (struct sockaddr *)&c_outland, c_len)==-1){
      printf("send_ack_to_client ip:%s port:%d Failed!!!", client_ip, c_port);
      usleep(100);
    }
    
    return 0;
}

int send_EQ_to_client(char *client_ip, int c_port)
{
    EQOccur occur_msg;
    int len_of_pack;
    struct sockaddr_in c_outland;
    int c_len = sizeof(c_outland);

    // Fill in message information and pack it
    eq_occur__init(&occur_msg);
    occur_msg.packet_type = "2";
    occur_msg.information = "alarm";
    occur_msg.version = "1.0.0";
    len_of_pack = eq_occur__get_packed_size(&occur_msg);
    char buf_send[len_of_pack];
    memset( buf_send ,'\0',sizeof(buf_send));
    int size = eq_occur__pack(&occur_msg, (uint8_t *)buf_send);

    memset((char *)&c_outland, 0, sizeof(c_outland));
    c_outland.sin_family = AF_INET;
    c_outland.sin_port = htons(c_port);
    inet_aton(client_ip, &c_outland.sin_addr);

    while(sendto(s_fd, buf_send, size , 0, (struct sockaddr *)&c_outland, c_len)==-1){
      printf("send_EQ_to_client ip:%s port:%d Failed!!!", client_ip, c_port);
      usleep(100);
    }
    
    return 0;
}

void timeout_cb_freeze(EV_P_ ev_timer *watcher, int revents)
{
    freeze_timer *w = (freeze_timer*)watcher;
    printf("=====stop freeze time(%ld)=====\n",mytime());
    *(w->stat_flag) = NORMAL;
    printf("stat_flag : %d\n", *(w->stat_flag));
    ev_timer_stop (loop, &(w->timer));
    ev_timer_set (&(w->timer), FREEZE_TIME, 0.);
}

//timeout when receive an event packet after 1s
void timeout_cb_judgement(EV_P_ ev_timer *watcher, int revents)
{
    judge_timer *w = (judge_timer*)watcher;

    printf("=====redis judgement here(%ld)=====\n",mytime());
    *(w->stat_flag) = earthquake_judgement(w->redis, total_weighted_events);
    printf("stat_flag : %d\n", *(w->stat_flag));

    if (*(w->stat_flag) == ALARM){
      printf("=====start freeze time(%ld)=====\n",mytime());
      ev_timer_start(loop, &freeze.timer);
      printf("send eq occur(%ld)\n",mytime());
      earthquake_send(w->redis);
      printf("finish sending(%ld)\n",mytime());
    }else if (*(w->stat_flag) == ERR){
    	*(w->stat_flag) = NORMAL;
    }

    printf("stat_flag : %d\n", *(w->stat_flag));

    ev_timer_stop (loop, &(w->timer));
    ev_timer_set (&(w->timer), OBSERVE_TIME, 0.);
}

/* event receive callback */
void recv_cb(struct ev_loop *loop, struct ev_io *watcher, int revents)
{
    if(EV_ERROR & revents){
      perror("got invalid event");
      return;
    }

    struct sockaddr_in client_sensor;
    socklen_t s_len = sizeof(client_sensor);
    int recv_len;
    char buf[BUFLEN] = {};
    KpAlive *recv_alive;
    EQEvent *recv_event;
    KpAliveAck *request_ack;
    BootKp *recv_kp_response;
    server_io *w = (server_io*)watcher;

#ifdef DEBUG // defined in interface.h
    static int recv_count = 0;
    recv_count++;
    printf("\n# [%d] rcev_cb in...\n", recv_count);
#endif

    PacketType *packet;
    memset(buf,'\0',BUFLEN);
    recv_len = recvfrom(watcher->fd, buf, BUFLEN, 0, (struct sockaddr *) &client_sensor, &s_len);
    packet = packet_type__unpack(NULL, recv_len, (uint8_t *)buf);
	
    printf("Received packet from %s:%d\n", inet_ntoa(client_sensor.sin_addr), ntohs(client_sensor.sin_port));
    char *type = packet->packet_type;  
    printf("status : %d\n" , *(w->stat_flag));
    mytime();

    if ( *(w->stat_flag) == NORMAL || *(w->stat_flag) == OBSERVE ){
      switch (*type){
        //Received keepalive packet from client_sensor
        case '0':
          
          recv_alive = kp_alive__unpack(NULL, recv_len,(uint8_t*)buf);
#ifdef DEBUG // defined in interface.h
          printf("sensor ID : %s\n" , recv_alive->sensor_id);
          printf("alive flag : %d\n" , recv_alive->alive_flag);
          printf("country : %s\n" , recv_alive->country_code);
          printf("city : %s\n" , recv_alive->city_code);
#endif
          add_keepalive_node_into_db(w->redis, AF_INET, recv_alive->sensor_id, recv_alive->country_code,\
             recv_alive->city_code, inet_ntoa(client_sensor.sin_addr), ntohs(client_sensor.sin_port));
          send_kp_to_client(inet_ntoa(client_sensor.sin_addr), ntohs(client_sensor.sin_port));
          kp_alive__free_unpacked(recv_alive, NULL);
          break;

        //Received earthquake event packet from client_sensor
        case '1':
          
          recv_event = eq_event__unpack(NULL, recv_len,(uint8_t *) buf);
#ifdef DEBUG // defined in interface.h
          printf("sensor ID : %s\n" , recv_event->sensor_id);
          printf("event output(credi) :%d\n" , recv_event->event_output);
          printf("second : %d\n" , (int)recv_event->event_sec);
          printf("microsecond : %d\n" , (int)recv_event->event_usec);
#endif
          add_event_node_into_db(w->redis, AF_INET, recv_event->sensor_id, recv_event->event_output);
          if ( *(w->stat_flag) == NORMAL){
              printf("\n\n=====recv first event packet(%ld)=====\n",mytime());
              ev_timer_start(loop, &judge.timer);
              *(w->stat_flag) = OBSERVE;
          }
          if ( *(w->stat_flag) == OBSERVE)
              *total_weighted_events += recv_event->event_output;
          eq_event__free_unpacked(recv_event, NULL);
          break;

        //check kpalive with bootstrap server
        case '4':
          bs_response = 1;
          printf("Received bs ack\n");
          recv_kp_response = boot_kp__unpack(NULL, recv_len, (uint8_t *)buf);
	  boot_kp__free_unpacked(recv_kp_response, NULL);
          break;

        // receive keep alive packet from user and do ack
        case '5':
          request_ack = kp_alive_ack__unpack(NULL, recv_len, (uint8_t *)buf);
#ifdef DEBUG
          printf("role : %d\n", request_ack->role);
#endif
          if(request_ack->role == 0)
             send_ack_to_client(inet_ntoa(client_sensor.sin_addr), ntohs(client_sensor.sin_port));
             kp_alive_ack__free_unpacked(request_ack, NULL);
          break;

        default:
          fprintf(stderr, "receive unknown packet...\n");
          break;
      }
      packet_type__free_unpacked(packet, NULL);
    }
}

int server_open(int s_port, int *stat_flag, redisContext *c)
{
    struct ev_loop *loop = ev_default_loop(0);
    struct sockaddr_in s_local;

    freeze.stat_flag = stat_flag;

    judge.redis = c;
    judge.stat_flag = stat_flag;

    server_io s_io;
    s_io.redis = c;
    s_io.stat_flag = stat_flag;

    if ((s_fd=socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
      die("socket");

    memset((char *) &s_local, 0, sizeof(s_local));
    s_local.sin_family = AF_INET;
    s_local.sin_port = htons(s_port);
    s_local.sin_addr.s_addr = htonl(INADDR_ANY);

    int on = 1;
    setsockopt(s_fd, SOL_SOCKET, SO_REUSEADDR, (char *) &on, sizeof(on));

    if( bind(s_fd , (struct sockaddr*)&s_local, sizeof(s_local) ) == -1)
      die("bind");

    printf("Waiting for event on port %d ...\n", s_port);

    int ret;
    pthread_t t_id;

    ret = pthread_create(&t_id, NULL, (void*)bootstrap_thread, NULL);
    if(ret != 0){
        printf("can't create thread: %s\n",strerror(ret));
        exit(1);
    }

    ev_io_init(&s_io.io, recv_cb, s_fd, EV_READ);
    ev_io_start(loop, &s_io.io);

    ev_timer_init(&judge.timer, timeout_cb_judgement, OBSERVE_TIME, 0.);
    ev_timer_init(&freeze.timer, timeout_cb_freeze, FREEZE_TIME, 0.);

    while (1){
      ev_loop(loop, 0);
    }

    close(s_fd);
    return 0;
}

void get_server_id(void)
{
    struct ifreq ifr;
    struct ifconf ifc;
    char buf[1024];
    int success = 0;
    
    memset(buf,'\0',sizeof(buf));

    int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP);
    if (sock == -1)
        die("socket");

    ifc.ifc_len = sizeof(buf);
    ifc.ifc_buf = buf;
    //Return a list of interface (transport layer) addresses
    if (ioctl(sock, SIOCGIFCONF, &ifc) == -1)
        die("ioctl SIOCGIFCONF");

    struct ifreq* it = ifc.ifc_req;
    const struct ifreq* const end = it + (ifc.ifc_len / sizeof(struct ifreq));

    for (; it != end; ++it) {
        strcpy(ifr.ifr_name, it->ifr_name);
        //Get the active flag word of the device
        if (ioctl(sock, SIOCGIFFLAGS, &ifr) == 0) {
            if (! (ifr.ifr_flags & IFF_LOOPBACK)) {
                if (ioctl(sock, SIOCGIFHWADDR, &ifr) == 0) {
                    success = 1;
                    break;
                }
            }
        }else {
            die("ioctl SIOCGIFHWADDR");
        }
    }

    unsigned char mac[6];
    memset(mac , '\0' , sizeof(mac));
    if (success) memcpy(mac, ifr.ifr_hwaddr.sa_data, 6);
    char *server_id = s_id;
    snprintf(server_id, 13, "%.2X%.2X%.2X%.2X%.2X%.2X", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
    close(sock);
}

int kp_alive_to_bootstrap(const char *boot_ip, const int b_port)
{
    BootKp alive_msg;
    struct sockaddr_in c_outland;
    int c_len = sizeof(c_outland);
    int len_of_pack;

    boot_kp__init(&alive_msg);
    alive_msg.packet_type = "4";
    alive_msg.server_id = s_id;
    alive_msg.token = "test123";
    len_of_pack = boot_kp__get_packed_size(&alive_msg);
    char buf_send[len_of_pack+1];
    memset(buf_send,'\0',sizeof(buf_send));
    int size =  boot_kp__pack(&alive_msg, (uint8_t *)buf_send);
    
    memset((char *)&c_outland, 0, sizeof(c_outland));
    c_outland.sin_family = AF_INET;
    c_outland.sin_port = htons(b_port);
    inet_aton(boot_ip, &c_outland.sin_addr);

    while(sendto(s_fd, buf_send, size , 0, (struct sockaddr *)&c_outland, c_len)==-1){
      usleep(100);
    }
     
    printf("send to bs\n");

    return 0;
}

/* keep alive to the bootstrap server */
void bootstrap_thread(void)
{
    const char *boot_ip = "140.115.153.209";
    const int boot_port = 7777;
    int i ;
    get_server_id();
    
    while(1){
      bs_response = 0;
      kp_alive_to_bootstrap(boot_ip, boot_port);
      sleep(120);
      for(i = 0 ; i<4 ; i++){ 
         if(bs_response!=1){
             kp_alive_to_bootstrap(boot_ip, boot_port);
             sleep(120);
         }
      }
      sleep(3600);
    }
}
