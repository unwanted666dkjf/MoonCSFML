#ifndef MOON_CSFML_SYSTEM_MOON_CLOCK_H
#define MOON_CSFML_SYSTEM_MOON_CLOCK_H


#include "./moon_time.h"


#ifdef __cplusplus
extern "C" {
#endif


struct MOON_CSFML_API moon_Clock;


/**
 * Stores elapsed time as moon_Time,
 *does not starts automatically.
 * Alternative to sf::Clock.
 */
typedef struct moon_Clock moon_Clock;


/**
 * Creates new clock.
 * If fails, behaviour is undefined.
 */
MOON_CSFML_API moon_Clock*
moon_Clock_create();

/**
 * Destroys the clock.
 */
MOON_CSFML_API void
moon_Clock_destroy(moon_Clock* self);

/**
 * Waits the clock.
 * You should always call it in a game loop. Otherwise,
 *clock won't work.
 * This function is not blocking.
 */
MOON_CSFML_API void
moon_Clock_wait(moon_Clock* self);

/**
 * Starts the clock.
 */
MOON_CSFML_API void
moon_Clock_start(moon_Clock* self);

/**
 * Resets the buffer of the clock.
 * Won't change delta.
 */
MOON_CSFML_API void
moon_Clock_reset(moon_Clock* self);

/**
 * Returns 1 if clock is running, 0 otherwise.
 */
MOON_CSFML_API int
moon_Clock_is_running(const moon_Clock* self);

/**
 * Stops the clock.
 * Clears time buffer.
 * Returns buffered time.
 */
MOON_CSFML_API moon_Time
moon_Clock_stop(moon_Clock* self);

/**
 * Returns delta time between iterations.
 */
MOON_CSFML_API moon_Time
moon_Clock_delta(const moon_Clock* self);

/**
 * Clears time buffer.
 * Returns buffered time.
 */
MOON_CSFML_API moon_Time
moon_Clock_restart(moon_Clock* self);

/**
 * Returns buffered time.
 */
MOON_CSFML_API moon_Time
moon_Clock_get_elapsed_time(const moon_Clock* self);


#ifdef __cplusplus
}
#endif


#endif
