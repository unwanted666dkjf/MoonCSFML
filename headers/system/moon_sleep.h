#ifndef MOON_CSFML_SYSTEM_MOON_SLEEP_H
#define MOON_CSFML_SYSTEM_MOON_SLEEP_H


#include "./moon_time.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Make the current thread sleep for a given duration.
 */
MOON_CSFML_API void
moon_sleep(moon_Time time);


#ifdef __cplusplus
}
#endif


#endif
