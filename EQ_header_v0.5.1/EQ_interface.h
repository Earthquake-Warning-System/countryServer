#ifndef __EQ_INTERFACE_H
#define __EQ_INTERFACE_H

#include <ev.h>
#include <pthread.h>
#include <sys/time.h>
#include <hiredis.h>

#define DEBUG // USE FOR DEBUG
/*
typedef struct keep_alive
{
    char packet_type;            //keep alive packet : 0
    char sensor_ID[11];          //sensor ID
    int alive_flag;
    char country_code[4];
    char city_code[4];

}kp_alive;

typedef struct earthquake_event
{
    char packet_type;            //earthquake event packet : 1
    char sensor_ID[11];          //sensor ID
    int event_output;
    time_t event_sec;
    suseconds_t event_usec;
}EQ_event;

typedef struct earthquake_occur
{
    char test[6];
}EQ_occur;

typedef struct Boot_kp
{
    char packet_type;            //earthquake occur packet : 4
    char server_ID[13];
}Boot_kp;
*/
typedef struct earthquake_judgement_timer
{
    ev_timer timer;
    redisContext *redis;
    int *stat_flag;
}judge_timer;

typedef struct earthquake_freeze_timer
{
    ev_timer timer;
    int *stat_flag;
}freeze_timer;


typedef struct server_input_output
{
    ev_io io;
    redisContext *redis;
    int *stat_flag;
}server_io;

int server_open(int s_port, int *stat_flag, redisContext *c);
int send_EQ_to_client(char *client_ip, int c_port);
void get_server_id(void);
void bootstrap_thread(void);

#endif
