
#ifndef __EQ_REDIS_H
#define __EQ_REDIS_H


FILE *redis_debug;

redisContext *init_redis_conn(const char *hostname, int port);
unsigned int get_num_alive_nodes(redisContext *c);
unsigned int get_num_event_nodes(redisContext *c);
void flush_event(redisContext *c);
void add_occur_node_into_db(redisContext *c, unsigned short safamily,int alive_nodes ,int event_nodes,int result);
long int mytime(void);
void earthquake_send(redisContext *c);
void add_keepalive_node_into_db(redisContext *c, unsigned short safamily, const char *sensor_ID, const char *country_code, const char *city_code, const char *ipstr, unsigned short port);
void add_event_node_into_db(redisContext *c, unsigned short safamily, const char *sensor_ID, int event_output);
void flush_db_channel(redisContext *c, int db_channel);
void flush_db_all(redisContext *c);
void set_node_lifetime(int lifetime);

#endif
