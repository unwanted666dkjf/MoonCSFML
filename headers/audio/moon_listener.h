#ifndef MOON_CSFML_AUDIO_MOON_LISTENER_H
#define MOON_CSFML_AUDIO_MOON_LISTENER_H


#include "../system/moon_vector3.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Changes the global volume of all the sounds and musics.
 * The volume is a number between 0 and 100; it is combined with
 *the individual volume of each sound / music.
 * The default value for the volume is 100 (maximum).
 */
MOON_CSFML_API void
moon_Listener_set_global_volume(float volume);

/**
 * Returns current global volume, in the range [0, 100].
 */
MOON_CSFML_API float
moon_Listener_get_global_volume();

/**
 * Sets the position of the listener in the scene.
 * The default listener's position is (0, 0, 0).
 */
MOON_CSFML_API void
moon_Listener_set_position(float x, float y, float z);

/**
 * Returns the current position of the listener in the scene.
 */
MOON_CSFML_API moon_Vector3f
moon_Listener_get_position();

/**
 * Sets the forward vector of the listener in the scene.
 *
 * The direction (also called "at vector") is the vector
 *pointing forward from the listener's perspective. Together
 *with the up vector, it defines the 3D orientation of the
 *listener in the scene. The direction vector doesn't
 *have to be normalized.
 * The default listener's direction is (0, 0, -1).
 */
MOON_CSFML_API void
moon_Listener_set_direction(float x, float y, float z);

/**
 * Returns the current forward vector of the listener in the scene.
 */
MOON_CSFML_API moon_Vector3f
moon_Listener_get_direction();

/**
 * Sets the upward vector of the listener in the scene.
 *
 * The up vector is the vector that points upward from the
 *listener's perspective. Together with the direction, it
 *defines the 3D orientation of the listener in the scene.
 * The up vector doesn't have to be normalized.
 * The default listener's up vector is (0, 1, 0). It is usually
 *not necessary to change it, especially in 2D scenarios.
 */
MOON_CSFML_API void
moon_Listener_set_up_vector(float x, float y, float z);

/**
 * Returns the current upward vector of the listener in the scene.
 */
MOON_CSFML_API moon_Vector3f
moon_Listener_get_up_vector();


#ifdef __cplusplus
}
#endif


#endif
