#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include "EQ_interface.h"
#include <hiredis.h>
#include "EQ_redis.h"
#include "EQ_config.h"

static int node_lifetime = MIN_LIFETIME; // default, no less than 30s

static char *setname[6] = {"ERR", "PHONE", "ALIVE", "EVENT", "LIST_KA","LIST_EV"};

enum node_type {
  ERR = 0,
  PHONE = 1,
  ALIVE = 2,
  EVENT = 3,
  LIST_KA = 4,
  LIST_EV = 5,
  OCCUR = 12,
};

// DB Channels
enum db_channels {
HASH_DB_NODEINFO_V4 = 1,   	// DB for storing info of all nodes
HASH_DB_NODEINFO_V6 = 2,   	// DB for storing info of all nodes
HASH_DB_EVNODE_V4 = 3,   	// DB for storing info of all event nodes
HASH_DB_EVNODE_V6 = 4,   	// DB for storing info of all event nodes
HASH_DB_OCCUR = 12,
};

int last_channel = 0;

FILE *redis_debug = NULL;

int set_channel(redisContext *c, int channel);

void
debugf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    if(redis_debug) {
        vfprintf(redis_debug, format, args);
    }
    va_end(args);
    if(redis_debug)
        fflush(redis_debug);
}

#define BASETIME 1480049311 // 2016/11/25/12:51

/* get timestamp as the offset to BASETIME */
long int mytime(void)
{
    time_t now = time(NULL);
    struct tm * pTM;
    pTM = localtime(&now);

    printf("time: %s\n",asctime(pTM));    

    return now;
}


/* connect to DB */
redisContext *init_redis_conn(const char *hostname, int port)
{
    redisContext *c = NULL;
    struct timeval timeout = { 1, 500000 }; // 1.5 seconds
    c = redisConnectWithTimeout(hostname, port, timeout);
    if (c == NULL || c->err) {
        if (c) {
            debugf("Connection error: %s\n", c->errstr);
            redisFree(c);
        } else {
            debugf("Connection error: can't allocate redis context\n");
        }
        return c;
    }

    /* PING server */
    redisReply *reply = redisCommand(c,"PING");
    debugf("PING: %s\n", reply->str);
    freeReplyObject(reply);
    return c;
}


/* reset DB */
void flush_db_all(redisContext *c)
{
    redisReply *reply = redisCommand(c,"FLUSHALL");
    debugf("> FLUSHALL: %s\n", reply->str);
    freeReplyObject(reply);
}

/* reset channel */
void flush_db_channel(redisContext *c, int db_channel)
{
    if (set_channel(c, db_channel)) {
       redisReply *reply = redisCommand(c,"FLUSHDB");
       debugf("> FLUSHDB: %s\n", reply->str);
       freeReplyObject(reply);
    }
}


/* get channel no of HASH_DB_NODEINFO by safamily */
int get_HASH_DB_channel(unsigned short safamily, int type)
{
   switch (type) {
       case ALIVE:
           return (safamily == AF_INET) ? HASH_DB_NODEINFO_V4 : HASH_DB_NODEINFO_V6;
       case EVENT:
           return (safamily == AF_INET) ? HASH_DB_EVNODE_V4 : HASH_DB_EVNODE_V6;
       case OCCUR:
           return HASH_DB_OCCUR;
   }
   return -1;
}

int set_channel(redisContext *c, int channel)
{
    int success = 0;
    if (last_channel == channel)
       return 1;
    redisReply *reply = redisCommand(c,"SELECT %d", channel);
    debugf("> SELECT %d: %s\n", channel, reply->str);
    if (strcmp(reply->str, "OK") == 0)
       success = 1;
    freeReplyObject(reply);
    last_channel = channel;
    return success;
}


/* select and se tchannel of HASH_DB_NODEINFO by safamily */
int set_HASH_DB_channel(redisContext *c, unsigned short safamily, int type)
{
    return set_channel(c, get_HASH_DB_channel(safamily, type));
}



//-------------------
//  HASH_DB_NODEINFO
//-------------------

void add_hash_db_nodeinfo
(redisContext *c, unsigned short safamily, int type, const char *sensor_ID, const char *country_code, const char *city_code, const char *ipstr, unsigned short port)
{

   redisReply *reply = NULL;
   if (set_HASH_DB_channel(c, safamily, type)) {
      char portstr[6]={};
      snprintf(portstr, sizeof(portstr), "%d", port);
      reply = redisCommand(c, "HMSET %s country %s city %s ip %s port %s",
                           sensor_ID, country_code, city_code, ipstr, portstr);
      debugf("> HMSET %s country %s city %s ip %s port %s: %s\n",
                sensor_ID, country_code, city_code, ipstr, portstr, reply->str);
      freeReplyObject(reply);

      reply = redisCommand(c, "EXPIRE %s %d", sensor_ID, node_lifetime); // auto expiration
      debugf("> EXPIRE %d: %lld\n", node_lifetime, reply->integer);
      freeReplyObject(reply);
   }
}

void add_hash_db_evnode(redisContext *c, unsigned short safamily, int type, const char *sensor_ID, long int credi)
{
  redisReply *reply = NULL;
  if (set_HASH_DB_channel(c, safamily,type)) {

      reply = redisCommand(c, "HMSET %s credi %ld ",
                           sensor_ID, credi);
      debugf("> HMSET %s credi %ld: %s\n",
                sensor_ID, credi, reply->str);
      freeReplyObject(reply);

      reply = redisCommand(c, "EXPIRE %s %d", sensor_ID, node_lifetime); // auto expiration
      debugf("> EXPIRE %d: %lld\n", node_lifetime, reply->integer);
      freeReplyObject(reply);
   }
}



void add_hash_db_occurnode(redisContext *c, unsigned short safamily,int alive_nodes , int event_nodes , int result,int type)
{
redisReply *reply = NULL;
if (set_HASH_DB_channel(c,safamily,type)){ 
reply = redisCommand(c, " HMSET %ld  alive_nodes %d event_nodes %d result %d",mytime() , alive_nodes ,event_nodes,result);
debugf("> HMSET %ld alive_nodes %d event_nodes %d result %d",mytime(), alive_nodes ,event_nodes,result);
freeReplyObject(reply);
}
}



/* return country, city, ipstr and portstr of key sensor_ID from HASH_DB_NODEINFO */

int get_hash_db_nodeinfo
(redisContext *c, unsigned short safamily, int type, const char *sensor_ID, char *country_code, char *city_code, char *ipstr, char *portstr)
{

    int success = 0;
    if (set_HASH_DB_channel(c, safamily,type)) {
       redisReply *reply = redisCommand(c,"HMGET %s country city ip port", sensor_ID);
       debugf("> HMGET %s country city ip port\n", sensor_ID);
       if(reply->type == REDIS_REPLY_ARRAY){
          int j;
          for(j=0; j<reply->elements; j++){
             debugf("%d) %s \t", j+1, reply->element[j]->str);
          }
          strncpy(country_code, reply->element[0]->str, reply->element[0]->len);
          strncpy(city_code, reply->element[1]->str, reply->element[1]->len);
          strncpy(ipstr, reply->element[2]->str, reply->element[2]->len);
          strncpy(portstr, reply->element[3]->str, reply->element[3]->len);
          success = 1;
       }
       freeReplyObject(reply);
       debugf("\n");
    }
    return success;
}

int get_hash_db_evnode(redisContext *c, unsigned short safamily, int type, const char *sensor_ID, char* credi)
{
    int success = 0;
    if (set_HASH_DB_channel(c, safamily,type)) {
       redisReply *reply = redisCommand(c,"HMGET %s credi", sensor_ID);
       debugf("> HMGET %s credi\n", sensor_ID);
       if(reply->type == REDIS_REPLY_ARRAY){
          int j;
          for(j=0; j<reply->elements; j++){
             debugf("%d) %s \t", j+1, reply->element[j]->str);
          }
          strncpy(credi, reply->element[0]->str, reply->element[0]->len);
          success = 1;
       }
       freeReplyObject(reply);
       debugf("\n");
    }
    return success;
}



int get_node_type(const char *sensor_ID)
{
   return PHONE;
}

/*  rx keepalive pkt
    add one key (sensor_ID) into DB
    1. add node into HASH_DB_NODEINFO with fields and values
       (note: according to the first octect in sensor_ID) */
void add_keepalive_node_into_db
(redisContext *c, unsigned short safamily, const char *sensor_ID, const char *country_code, const char *city_code, const char *ipstr, unsigned short port)
{
    // add node into HASH_DB_NODEINFO
    add_hash_db_nodeinfo(c, safamily, ALIVE, sensor_ID, country_code, city_code, ipstr, port);
}

/*  rx event pkt
    add one key (sensor_ID) into DB
    1. add node into SET_DB_EVENT with credibility(score)*/
void add_event_node_into_db(redisContext *c, unsigned short safamily, const char *sensor_ID, int event_output)
{
    switch(get_node_type(sensor_ID)){
      case PHONE :
          add_hash_db_evnode(c, safamily, EVENT, sensor_ID, (long int)event_output);
          break;
    }
}


void add_occur_node_into_db(redisContext *c, unsigned short safamily,int alive_nodes ,int event_nodes,int result)
{
add_hash_db_occurnode(c, safamily , alive_nodes ,  event_nodes, result ,OCCUR );
}


/* reset event window */
void flush_event(redisContext *c)
{
    flush_db_channel(c, get_HASH_DB_channel(AF_INET, EVENT));
    flush_db_channel(c, get_HASH_DB_channel(AF_INET6, EVENT));
}


//---------------------
//  SEND EQ_OCCUR
//---------------------
void get_client(redisContext *c, unsigned short safamily, int type, const char *sensor_ID)
{
    if (set_HASH_DB_channel(c, safamily, type)) {
       redisReply *reply = redisCommand(c,"HMGET %s ip port", sensor_ID);

       if(reply->type == REDIS_REPLY_ARRAY){
          int j;
          for(j=0 ;j<reply->elements; j++){
             debugf("%d) %s \t", j+1, reply->element[j]->str);
          }
          send_EQ_to_client(reply->element[0]->str, atoi(reply->element[1]->str));
       }
       freeReplyObject(reply);
       debugf("\n");
    }
}


//--------------
//  DECISION
//--------------


unsigned int _get_num_alive_nodes(redisContext *c,  unsigned short safamily)
{
   redisReply *reply = redisCommand(c,"DBSIZE");
   debugf("> DBSIZE : %ld\n", reply->integer);
   unsigned int counter = reply->integer;
   freeReplyObject(reply);
   return counter;
}


unsigned int get_num_alive_nodes(redisContext *c)
{
    unsigned int counter = 0;
    if (set_HASH_DB_channel(c, AF_INET, ALIVE))
       counter += _get_num_alive_nodes(c, AF_INET);
    if (set_HASH_DB_channel(c, AF_INET6, ALIVE))
       counter += _get_num_alive_nodes(c, AF_INET6);
    return counter;
}


unsigned int get_num_event_nodes(redisContext *c)
{
    unsigned int counter = 0;
    if (set_HASH_DB_channel(c, AF_INET, EVENT))
       counter += _get_num_alive_nodes(c, AF_INET);
    if (set_HASH_DB_channel(c, AF_INET6, EVENT))
       counter += _get_num_alive_nodes(c, AF_INET6);
    return counter;
}

void earthquake_send(redisContext *c)
{
    if (set_HASH_DB_channel(c, AF_INET, ALIVE)) {
       redisReply *reply = redisCommand(c, "KEYS *");
       debugf("\tHASH_DB (keys: %d):\n", reply->elements);
       if(reply->type == REDIS_REPLY_ARRAY){
          int j;
          for(j=0; j<reply->elements; j++){
             debugf("%s \t", reply->element[j]->str);
             get_client(c, AF_INET, ALIVE, reply->element[j]->str);
          }
       }
       freeReplyObject(reply);
       debugf("\n");
    }
}
