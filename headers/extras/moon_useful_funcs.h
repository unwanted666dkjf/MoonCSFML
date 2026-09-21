#ifndef MOON_CSFML_EXTRAS_MOON_USEFUL_FUNCS_H
#define MOON_CSFML_EXTRAS_MOON_USEFUL_FUNCS_H


#include "../system/moon_time.h"

#include "../system/moon_angle.h"

#include "../system/moon_vector2.h"


#include "../graphics/moon_rect.h"

#include "../graphics/moon_render_window.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Checks if the rectangle is in the visible area of the screen.
 * For checking, it uses the current view of wnd.
 * Returns intersection rectangle(current view rectangle with given rect).
 * Intersection rectangle is empty if rectangle is not in visible area.
 */
MOON_CSFML_API moon_FloatRect
moon_is_rect_visible(
	const moon_FloatRect* rect,
	const moon_RenderWindow* wnd
);

/**
 * Checks if the rectangle is in the specified zone.
 * If not, calculates the new upper-left corner
 *position for the rectangle.
 * Returns the corrected upper-left corner
 *position for the rectangle.
 */
MOON_CSFML_API moon_Vector2f
moon_in_area_pos(
	const moon_FloatRect* rect,
	const moon_FloatRect* area
);

/**
 * Decomposes values along the X and Y axes using an angle.
 * Returns decomposed offset.
 */
MOON_CSFML_API moon_Vector2f
moon_get_angle_offset(
	float offset,
	moon_Angle angle
);

/**
 * Returns the position of the object as it moves along a circle.
 * 'cx' and 'cy' -- coordinates of the center of rotation.
 * 'radius'		 -- radius of rotation.
 * 'angle'       -- the angle that determines the position of an
 *object on a circle relative to its center.
 */
MOON_CSFML_API moon_Vector2f
moon_get_circle_point_position(
	float cx, float cy,
	float radius,
	moon_Angle angle
);

/**
 * Returns the position of an object moving along a sine wave.
 * 'x0' and 'y0' -- initial position of the object.
 * 'speed'       -- moving speed.
 * 'amplitude'   -- maximum vertical displacement from the center line.
 * 'wavelength'  -- horizontal distance between consecutive wave peaks.
 * 'time'        -- elapsed time since the start of the motion.
 * 'phase'       -- initial phase offset of the wave.
 */
moon_Vector2f
moon_get_sine_wave_position(
	float x0, float y0,
	float speed,
	float amplitude,
	float wavelength,
	moon_Time  time,
	moon_Angle phase
);

/**
 * Returns the position of an object moving along a cosine wave.
 * 'x0' and 'y0' -- initial position of the object.
 * 'speed'       -- moving speed.
 * 'amplitude'   -- maximum vertical displacement from the center line.
 * 'wavelength'  -- horizontal distance between consecutive wave peaks.
 * 'time'        -- elapsed time since the start of the motion.
 * 'phase'       -- initial phase offset of the wave.
 */
moon_Vector2f
moon_get_cosine_wave_position(
	float x0, float y0,
	float speed,
	float amplitude,
	float wavelength,
	moon_Time  time,
	moon_Angle phase
);

/**
 * Calculates and returns proportional size.
 * If 'old_width' or 'old_height' is 0, returns {'new_width', 'new_height'}.
 * If 'keep_w' is not 0, it will preserve the width-to-height ratio.
 * If 'keep_h' is not 0, it will preserve the height-to-width ratio.
 * If 'keep_w' and 'keep_h' are not 0, both will be ignored.
 * If 'keep_w' and 'keep_h' are 0, both will be ignored.
 */
MOON_CSFML_API moon_Vector2f
moon_new_size(
	float old_width, 	float old_height,
	float new_width, 	float new_height,
	int keep_w,			int keep_h
);


#ifdef __cplusplus
}
#endif


#endif
