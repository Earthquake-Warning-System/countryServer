#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>
#include <sys/socket.h>
#include <unistd.h>
#include "EQ_interface.h"
#include "EQ_judgement.h"
#include <hiredis.h>
#include "EQ_redis.h"
#include "EQ_config.h"

int main(int argc, char **argv){

    int cmd_fd;
    int server_port = 0; // port of this local EQ server
    int *stat_flag;
    int init_stat = NORMAL;


    redisContext *redis_conn = NULL;

    const char *redis_hostname = "127.0.0.1"; //redis server ip
    const int redis_srv_port = 6379;

    /* connect to redis */
    redis_conn = init_redis_conn(redis_hostname, redis_srv_port);
    if (redis_conn == NULL || redis_conn->err){
    	printf("connection to redis failed\n");
      exit(1);
    }

    /*int channel = 0;
    for (channel = 1; channel <= 12; channel++){
        flush_db_channel(redis_conn, channel);
    }*/
    
    stat_flag = &init_stat;

    while ((cmd_fd = getopt(argc, argv, "p:")) != -1){
        switch (cmd_fd){
            case 'p':
                server_port = atoi(optarg);
                break;
            default:
                fprintf(stderr, "usage: %s [-p port number]\n", *argv);
                exit(-1);
        }
    }

    if(server_port == 0){
        printf("You may have entered the wrong port number.\n");
        exit(1);
    }

    server_open(server_port, stat_flag, redis_conn);

    return 0;
}
