#ifndef MOON_CSFML_WINDOW_MOON_EVENT_H
#define MOON_CSFML_WINDOW_MOON_EVENT_H


#include "../import_macro.h"


#ifdef __cplusplus
extern "C" {
#endif


enum
{
//	moon_Event_Type_Unknown = -1,			//!< Value for unknown event.
	moon_Event_Type_Closed,                 //!< The window requested to be closed (no data)
	moon_Event_Type_Resized,                //!< The window was resized (data in event.size)
	moon_Event_Type_LostFocus,              //!< The window lost the focus (no data)
	moon_Event_Type_GainedFocus,            //!< The window gained the focus (no data)
	moon_Event_Type_TextEntered,            //!< A character was entered (data in event.text)
	moon_Event_Type_KeyPressed,             //!< A key was pressed (data in event.key)
	moon_Event_Type_KeyReleased,            //!< A key was released (data in event.key)
	moon_Event_Type_MouseWheelMoved,        //!< The mouse wheel was scrolled (data in event.mouseWheel) (deprecated)
	moon_Event_Type_MouseWheelScrolled,     //!< The mouse wheel was scrolled (data in event.mouseWheelScroll)
	moon_Event_Type_MouseButtonPressed,     //!< A mouse button was pressed (data in event.mouseButton)
	moon_Event_Type_MouseButtonReleased,    //!< A mouse button was released (data in event.mouseButton)
	moon_Event_Type_MouseMoved,             //!< The mouse cursor moved (data in event.mouseMove)
	moon_Event_Type_MouseEntered,           //!< The mouse cursor entered the area of the window (no data)
	moon_Event_Type_MouseLeft,              //!< The mouse cursor left the area of the window (no data)
	moon_Event_Type_JoystickButtonPressed,  //!< A joystick button was pressed (data in event.joystickButton)
	moon_Event_Type_JoystickButtonReleased, //!< A joystick button was released (data in event.joystickButton)
	moon_Event_Type_JoystickMoved,          //!< The joystick moved along an axis (data in event.joystickMove)
	moon_Event_Type_JoystickConnected,      //!< A joystick was connected (data in event.joystickConnect)
	moon_Event_Type_JoystickDisconnected,   //!< A joystick was disconnected (data in event.joystickConnect)
	moon_Event_Type_TouchBegan,             //!< A touch event began (data in event.touch)
	moon_Event_Type_TouchMoved,             //!< A touch moved (data in event.touch)
	moon_Event_Type_TouchEnded,             //!< A touch event ended (data in event.touch)
	moon_Event_Type_SensorChanged,          //!< A sensor value changed (data in event.sensor)

	moon_Event_Type_Count                   //!< Keep last -- the total number of event types
};


struct MOON_CSFML_API moon_Event;


/**
 * Defines a system event and its parameters.
 */
typedef struct moon_Event moon_Event;


/**
 * Creates new event object.
 */
MOON_CSFML_API moon_Event*
moon_Event_create();

/**
 * Destroys event object.
 */
MOON_CSFML_API void
moon_Event_destroy(moon_Event* self);

/**
 * Resets event(sets type to 'moon_Event_Type_Count').
 */
MOON_CSFML_API void
moon_Event_reset(moon_Event* self);

/**
 * Returns type of the event.
 */
MOON_CSFML_API int
moon_Event_get_type(const moon_Event* self);

/**
 * Size events parameters (Resized).
 * New width, in pixels.
 */
MOON_CSFML_API unsigned int
moon_Event_get_size_width(const moon_Event* self);

/**
 * Size events parameters (Resized).
 * New height, in pixels.
 */
MOON_CSFML_API unsigned int
moon_Event_get_size_height(const moon_Event* self);

/**
 * Keyboard event parameters (KeyPressed, KeyReleased).
 * Code of the key that has been pressed.
 */
MOON_CSFML_API int
moon_Event_get_key_keycode(const moon_Event* self);

/**
 * Keyboard event parameters (KeyPressed, KeyReleased).
 * Physical code of the key that has been pressed.
 */
MOON_CSFML_API int
moon_Event_get_key_scancode(const moon_Event* self);

/**
 * Keyboard event parameters (KeyPressed, KeyReleased).
 * Is the Alt key pressed?
 */
MOON_CSFML_API int
moon_Event_get_key_is_alt(const moon_Event* self);

/**
 * Keyboard event parameters (KeyPressed, KeyReleased).
 * Is the Control key pressed?
 */
MOON_CSFML_API int
moon_Event_get_key_is_control(const moon_Event* self);

/**
 * Keyboard event parameters (KeyPressed, KeyReleased).
 * Is the Shift key pressed?
 */
MOON_CSFML_API int
moon_Event_get_key_is_shift(const moon_Event* self);

/**
 * Keyboard event parameters (KeyPressed, KeyReleased).
 * Is the System key pressed?
 */
MOON_CSFML_API int
moon_Event_get_key_is_system(const moon_Event* self);

/**
 * Text event parameters (TextEntered).
 * UTF-32 Unicode value of the character.
 */
MOON_CSFML_API unsigned int
moon_Event_get_text_unicode(const moon_Event* self);

/**
 * Mouse move event parameters (MouseMoved).
 * X position of the mouse pointer, relative to the top of the owner window.
 */
MOON_CSFML_API int
moon_Event_get_mouse_move_x(const moon_Event* self);

/**
 * Mouse move event parameters (MouseMoved).
 * Y position of the mouse pointer, relative to the top of the owner window.
 */
MOON_CSFML_API int
moon_Event_get_mouse_move_y(const moon_Event* self);

/**
 * Mouse buttons events parameters(MouseButtonPressed, MouseButtonReleased).
 * Code of the button that has been pressed.
 */
MOON_CSFML_API int
moon_Event_get_mouse_button_button(const moon_Event* self);

/**
 * Mouse buttons events parameters(MouseButtonPressed, MouseButtonReleased).
 * X position of the mouse pointer, relative to the top of the owner window.
 */
MOON_CSFML_API int
moon_Event_get_mouse_button_x(const moon_Event* self);

/**
 * Mouse buttons events parameters(MouseButtonPressed, MouseButtonReleased).
 * Y position of the mouse pointer, relative to the top of the owner window.
 */
MOON_CSFML_API int
moon_Event_get_mouse_button_y(const moon_Event* self);

/**
 * Mouse wheel events parameters (MouseWheelMoved).
 * This event is deprecated and potentially inaccurate.
 * Use MouseWheelScrollEvent instead.
 * Number of ticks the wheel has moved (positive is up, negative is down).
 */
MOON_CSFML_API int
moon_Event_get_mouse_wheel_delta(const moon_Event* self);

/**
 * Mouse wheel events parameters (MouseWheelMoved).
 * This event is deprecated and potentially inaccurate.
 * Use MouseWheelScrollEvent instead.
 * X position of the mouse pointer, relative to the top of the owner window.
 */
MOON_CSFML_API int
moon_Event_get_mouse_wheel_x(const moon_Event* self);

/**
 * Mouse wheel events parameters (MouseWheelMoved).
 * This event is deprecated and potentially inaccurate.
 * Use MouseWheelScrollEvent instead.
 * Y position of the mouse pointer, relative to the top of the owner window.
 */
MOON_CSFML_API int
moon_Event_get_mouse_wheel_y(const moon_Event* self);

/**
 * Mouse wheel events parameters (MouseWheelScrolled).
 * Which wheel (for mice with multiple ones).
 */
MOON_CSFML_API int
moon_Event_get_mouse_wheel_scroll_wheel(const moon_Event* self);

/**
 * Mouse wheel events parameters (MouseWheelScrolled).
 * Wheel offset (positive is up/left, negative is down/right). High-precision mice may use non-integral offsets.
 */
MOON_CSFML_API float
moon_Event_get_mouse_wheel_scroll_delta(const moon_Event* self);

/**
 * Mouse wheel events parameters (MouseWheelScrolled).
 * X position of the mouse pointer, relative to the top of the owner.
 */
MOON_CSFML_API int
moon_Event_get_mouse_wheel_scroll_x(const moon_Event* self);

/**
 * Mouse wheel events parameters (MouseWheelScrolled).
 * Y position of the mouse pointer, relative to the top of the owner.
 */
MOON_CSFML_API int
moon_Event_get_mouse_wheel_scroll_y(const moon_Event* self);

/**
 * Touch events parameters (TouchBegan, TouchMoved, TouchEnded).
 * Index of the finger in case of multi-touch events.
 */
MOON_CSFML_API unsigned int
moon_Event_get_touch_finger(const moon_Event* self);

/**
 * Touch events parameters (TouchBegan, TouchMoved, TouchEnded).
 * X position of the touch, relative to the top of the owner window.
 */
MOON_CSFML_API int
moon_Event_get_touch_x(const moon_Event* self);

/**
 * Touch events parameters (TouchBegan, TouchMoved, TouchEnded).
 * Y position of the touch, relative to the top of the owner window.
 */
MOON_CSFML_API int
moon_Event_get_touch_y(const moon_Event* self);

/**
 * Sensor event parameters (SensorChanged).
 * Type of the sensor.
 */
MOON_CSFML_API int
moon_Event_get_sensor_type(const moon_Event* self);

/**
 * Sensor event parameters (SensorChanged).
 * Current value of the sensor on X axis.
 */
MOON_CSFML_API float
moon_Event_get_sensor_x(const moon_Event* self);

/**
 * Sensor event parameters (SensorChanged).
 * Current value of the sensor on Y axis.
 */
MOON_CSFML_API float
moon_Event_get_sensor_y(const moon_Event* self);

/**
 * Sensor event parameters (SensorChanged).
 * Current value of the sensor on Z axis.
 */
MOON_CSFML_API float
moon_Event_get_sensor_z(const moon_Event* self);


#ifdef __cplusplus
}
#endif


#endif
