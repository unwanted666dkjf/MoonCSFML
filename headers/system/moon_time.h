#ifndef MOON_CSFML_SYSTEM_MOON_TIME_H
#define MOON_CSFML_SYSTEM_MOON_TIME_H


#include "../import_macro.h"


#ifdef __cplusplus
extern "C" {
#endif


#define moon_Time_NANOSEC_IN_SEC 		(1E9)

#define moon_Time_NANOSEC_IN_MILLISEC 	(1E6)

#define moon_Time_NANOSEC_IN_MICROSEC 	(1E3)


/**
 * Represents a time value.
 * Stores time as nanoseconds.
 * The buffer of type unsigned long long.
 * Alternative to sf::Time.
 */
typedef unsigned long long moon_Time;


/**
 * Returns time with value zero.

 */
MOON_CSFML_API moon_Time
moon_Time_zero();

/**
 * Creates time value from given seconds.
 */
MOON_CSFML_API moon_Time
moon_Time_from_seconds(float seconds);

/**
 * Creates time value from milliseconds.
 */
MOON_CSFML_API moon_Time
moon_Time_from_milliseconds(unsigned long milliseconds);

/**
 * Creates time value from microseconds.
 */
MOON_CSFML_API moon_Time
moon_Time_from_microseconds(unsigned long long microseconds);

/**
 * Creates time value from nanoseconds.
 */
MOON_CSFML_API moon_Time
moon_Time_from_nanoseconds(unsigned long long nanoseconds);

/**
 * Returns time value as seconds.
 */
MOON_CSFML_API float
moon_Time_as_seconds(moon_Time self);

/**
 * Returns time value as milliseconds.
 */
MOON_CSFML_API unsigned long
moon_Time_as_milliseconds(moon_Time self);

/**
 * Returns time value as microseconds.
 */
MOON_CSFML_API unsigned long long
moon_Time_as_microseconds(moon_Time self);

/**
 * Returns time value as nanoseconds.
 */
MOON_CSFML_API unsigned long long
moon_Time_as_nanoseconds(moon_Time self);


#ifdef __cplusplus
}
#endif


#endif
