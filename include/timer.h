#ifndef TIMER_H
#define TIMER_H
#include <time.h>
#include <stdio.h>
#include "types.h"

typedef struct 
{
  clock_t t;

} Timer;

void cLib_timer_start(Timer* timer);
void cLib_timer_end(Timer* timer);
void cLib_timer_print(Timer* timer);
#endif
