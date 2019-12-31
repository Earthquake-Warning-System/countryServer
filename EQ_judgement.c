#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <hiredis.h>
#include "EQ_redis.h"
#include "EQ_judgement.h"
#include <sys/socket.h>

int earthquake_judgement(redisContext *c, int* total_weighted_events)
{
  int total_nodes ;
  int total_events ;

  total_nodes = get_num_alive_nodes(c);
  total_events = get_num_event_nodes(c);

  printf("NUM_ALIVE_NODES: %d\n", total_nodes);
  printf("NUM_EVENT_NODES: %d\n", total_events);
  printf("WEIGHTED_NUM_EVENT_NODES: %f\n", *total_weighted_events/100.0);

  if (total_events > total_nodes){
    printf("event_nodes > alive_nodes\n");
    printf("flush events...\n");
    flush_event(c);
    *total_weighted_events = 0;
    return ERR;
  }

  if ( *total_weighted_events/100.0 >= total_nodes/2.0){
    printf("[WARN] [REDIS]*** EARTHQUAKE *** \n");
    add_occur_node_into_db(c, AF_INET , total_nodes, total_events, 1);
    printf("flush events...\n");
    flush_event(c);
    *total_weighted_events = 0;
    return ALARM;
  }else{
    printf("flush events...\n");
    flush_event(c);
     add_occur_node_into_db(c, AF_INET , total_nodes, total_events, 0);
    //add_occur_to_sql(conn, total_nodes, total_events, 0);
    *total_weighted_events = 0;
    return NORMAL;
  }

  return ERR;
}
