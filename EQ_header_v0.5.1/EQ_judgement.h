#ifndef __EQ_JUDGEMENT_H
#define __EQ_JUDGEMENT_H

extern enum status {
  NORMAL = 0,
  OBSERVE = 1,
  ALARM = 2,
  ERR = 3
}states;

int earthquake_judgement(redisContext *c , int* total_weighted_events);

#endif
