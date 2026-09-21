#ifndef MOON_CSFML_WINDOW_MOON_TOUCH_H
#define MOON_CSFML_WINDOW_MOON_TOUCH_H


#include "../system/moon_vector2.h"


#include "../graphics/moon_render_window.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Check if a touch event is currently down.
 * 1 if finger with index 'finger'
 *is currently touching the screen,
 *0 otherwise.
 */
MOON_CSFML_API int
moon_Touch_is_down(unsigned int finger);

/**
 * Get the current position of a touch in desktop coordinates.
 * Returns position of finger with index 'finger'.
 */
MOON_CSFML_API moon_Vector2i
moon_Touch_get_position(unsigned int finger);

/**
 * Get the current position of a touch in desktop coordinates.
 * Returns position of finger with index 'finger',
 *relative to the given window.
 */
MOON_CSFML_API moon_Vector2i
moon_Touch_get_position_relative(
	unsigned int finger,
	const moon_RenderWindow* relative_to
);


#ifdef __cplusplus
}
#endif


#endif
