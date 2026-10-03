#ifndef MOON_CSFML_EXTRAS_MOON_JUMP_H
#define MOON_CSFML_EXTRAS_MOON_JUMP_H


#include "../import_macro.h"


#ifdef __cplusplus
extern "C" {
#endif


enum {
	moon_Jump_Status_Idle,
	moon_Jump_Status_Jumping
};


struct MOON_CSFML_API moon_Jump;


/**
 * Defines smooth jump motion.
 */
typedef struct moon_Jump moon_Jump;


/**
 * Creates new jump motion with given speed.
 * Speed always negative. And automatically
 *depends on the time in seconds.
 * 'jump_height' determines the jump height.
 *Always positive.
 * If creation fails, returns NULL.
 */
MOON_CSFML_API moon_Jump*
moon_Jump_create(
	float speed,
	float jump_height
);

/**
 * Destroys object.
 */
MOON_CSFML_API void
moon_Jump_destroy(moon_Jump* self);

/**
 * Returns jump status.
 */
MOON_CSFML_API int
moon_Jump_get_status(const moon_Jump* self);

/**
 * Returns jump speed.
 */
MOON_CSFML_API float
moon_Jump_get_speed(const moon_Jump* self);

/**
 * Sets jump speed.
 * You can change speed only
 *if current status is 'moon_Jump_Status_Idle'.
 * Speed is always negative.
 */
MOON_CSFML_API void
moon_Jump_set_speed(
	moon_Jump* self,
	float speed
);

/**
 * Returns the jump height.
 * Height is always positive.
 */
MOON_CSFML_API float
moon_Jump_get_height(const moon_Jump* self);

/**
 * Sets jump height.
 * You can change height only
 *if current status is 'moon_Jump_Status_Idle'.
 */
MOON_CSFML_API void
moon_Jump_set_height(
	moon_Jump* self,
	float height
);

/**
 * Returns the offset for the jump
 *or 0 if the jump is not started.
 */
MOON_CSFML_API float
moon_Jump_update(moon_Jump* self);

/**
 * Starts jumping
 *(sets status to 'moon_Jump_Status_Jumping').
 * You can start jumping only if status is
 *'moon_Jump_Status_Idle'.
 * 'ground_line' determines the initial height(bottom)
 *from which the jump will occur. Always positive.
 */
MOON_CSFML_API void
moon_Jump_start(
	moon_Jump* self,
	float ground_line
);

/**
 * Stops jumping
 *(sets status to 'moon_Jump_Status_Idle')
 */
MOON_CSFML_API void
moon_Jump_stop(moon_Jump* self);


#ifdef __cplusplus
}
#endif


#endif
