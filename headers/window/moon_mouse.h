#ifndef MOON_CSFML_WINDOW_MOON_MOUSE_H
#define MOON_CSFML_WINDOW_MOON_MOUSE_H


#include "../system/moon_vector2.h"


#include "../graphics/moon_render_window.h"


#ifdef __cplusplus
extern "C" {
#endif


enum
{
	moon_Mouse_Button_Left,       //!< The left mouse button
	moon_Mouse_Button_Right,      //!< The right mouse button
	moon_Mouse_Button_Middle,     //!< The middle (wheel) mouse button
	moon_Mouse_Button_XButton1,   //!< The first extra mouse button
	moon_Mouse_Button_XButton2,   //!< The second extra mouse button

	moon_Mouse_Button_ButtonCount //!< Keep last -- the total number of mouse buttons
};

enum
{
	moon_Mouse_Wheel_VerticalWheel,  //!< The vertical mouse wheel
	moon_Mouse_Wheel_HorizontalWheel //!< The horizontal mouse wheel
};


/**
 * Check if a mouse button is pressed.
 * 1 if pressed, 0 otherwise.
 */
MOON_CSFML_API int
moon_Mouse_is_button_pressed(int button);

/**
 * Get the current position of the
 *mouse in desktop coordinate.
 */
MOON_CSFML_API moon_Vector2i
moon_Mouse_get_position();

/**
 * Get the current position of the
 *mouse in desktop coordinate,
 *relative to the given window.
 */
MOON_CSFML_API moon_Vector2i
moon_Mouse_get_position_relative(const moon_RenderWindow* relative_to);

/**
 * Set the current position of the
 *mouse in desktop coordinates.
 */
MOON_CSFML_API void
moon_Mouse_set_position(int x, int y);

/**
 * Set the current position of the
 *mouse in desktop coordinates,
 *relative to the given window.
 */
MOON_CSFML_API void
moon_Mouse_set_position_relative(
	int x, int y,
	const moon_RenderWindow* relative_to
);


#ifdef __cplusplus
}
#endif


#endif
