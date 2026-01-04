#include "../include/timer.h"
#include <time.h>

void cLib_timer_start(Timer *timer) 
{
  timer->t = clock();
}
void cLib_timer_end(Timer* timer)
{
  timer->t = clock() - timer->t;
}
void cLib_timer_print(Timer* timer)
{
  printf("%f \n", (float)timer->t / CLOCKS_PER_SEC);
}

