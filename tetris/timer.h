/* By caft... ^!~
This head file is used to "count" time.
There are some macro can be used for counting
the run-time of some expressions.
@Author: caft0505@gmail.com
*/

#ifndef _TIMER_H_
#define _TIMER_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/select.h>

// Define the type of unit to get result.
typedef enum
{
    TIMER_UNIT_USEC = 1,
    TIMER_UNIT_MSEC = 1000, 
    TIMER_UNIT_SEC = 1000000
}TIMER_UNIT;

// This global variable is used for different result.
TIMER_UNIT  _UNIT = TIMER_UNIT_MSEC;

// Set the global variable unit.
#define TIMER_UNIT_SET(unit)    {_UNIT = unit;}

#define TIMER_T struct timeval

// Get value of the microseconds of the timer.
//#define TIMER_VAL(timer)    (timer.tv_usec)

// Get current time.
#define TIMER_GET(timer)    \
            {\
                if(-1 == gettimeofday(&timer, NULL) )\
                {\
                    perror("gettimeofday");\
                    exit(-1);\
                }\
            }

// Start the timer, get the start time.
#define TIMER_START(start) TIMER_GET(start)

// Stop the timer, get the stop time.
#define TIMER_STOP(stop) TIMER_GET(stop)\

// Get time distance between 'start' and 'stop'.
#define TIMER_DIFF(start, stop) \
                ( ((stop.tv_sec - start.tv_sec)*1000000 +\
                (stop.tv_usec - start.tv_usec) )*1.0 / _UNIT)

// Show time distance between 'start' and 'stop'.
#define TIMER_DIFF_SHOW(start, stop) \
                {\
                    if(TIMER_UNIT_USEC == _UNIT) \
                    {\
                        printf("use time: %ld us\n",\
                            (long)TIMER_DIFF(start, stop));\
                    }\
                    else if(TIMER_UNIT_MSEC == _UNIT) \
                    {\
                        printf("use time: %.3f ms\n",\
                            TIMER_DIFF(start, stop));\
                    }\
                    else \
                    {\
                        printf("use time: %.6f s\n",\
                            TIMER_DIFF(start, stop));\
                    }\
                }

// Run this function with 'delay' ms.
#define TIMER_DELAY(delay)  \
                {\
                    if(delay > 0)\
                    {\
                        TIMER_T tv = {delay/1000, (delay%1000)*1000};\
                        if(0 != select(0, NULL, NULL, NULL, &tv))\
                        {\
                            perror("select");\
                            exit(-1);\
                        }\
                    }\
                }

#endif
