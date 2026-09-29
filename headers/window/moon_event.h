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


/**
 * Size events parameters (Resized)
 */
typedef struct MOON_CSFML_API moon_SizeEvent {
	unsigned int width;  //!< New width, in pixels
	unsigned int height; //!< New height, in pixels
} moon_SizeEvent;

/**
 * Keyboard event parameters (KeyPressed, KeyReleased)
 */
typedef struct MOON_CSFML_API moon_KeyEvent {
	int keycode; 			//!< Code of the key that has been pressed
	int scancode; 			//!< Physical code of the key that has been pressed
	int alt;           		//!< Is the Alt key pressed?
	int control;       		//!< Is the Control key pressed?
	int shift;         		//!< Is the Shift key pressed?
	int system;        		//!< Is the System key pressed?
} moon_KeyEvent;

/**
 * Text event parameters (TextEntered)
 */
typedef struct MOON_CSFML_API moon_TextEvent {
	unsigned int unicode; //!< UTF-32 Unicode value of the character
} moon_TextEvent;

/**
 * Mouse move event parameters (MouseMoved)
 */
typedef struct MOON_CSFML_API moon_MouseMoveEvent {
	int x; //!< X position of the mouse pointer, relative to the left of the owner window
	int y; //!< Y position of the mouse pointer, relative to the top of the owner window
} moon_MouseMoveEvent;

/**
 * Mouse buttons events parameters.
 * (MouseButtonPressed, MouseButtonReleased)
 */
typedef struct MOON_CSFML_API moon_MouseButtonEvent {
	int button; //!< Code of the button that has been pressed
	int x;      //!< X position of the mouse pointer, relative to the left of the owner window
	int y;      //!< Y position of the mouse pointer, relative to the top of the owner window
} moon_MouseButtonEvent;

/**
 * Mouse wheel events parameters (MouseWheelMoved).
 * This event is deprecated and potentially inaccurate.
 * Use MouseWheelScrollEvent instead.
 */
typedef struct MOON_CSFML_API moon_MouseWheelEvent {
	int delta; //!< Number of ticks the wheel has moved (positive is up, negative is down)
	int x;     //!< X position of the mouse pointer, relative to the left of the owner window
	int y;     //!< Y position of the mouse pointer, relative to the top of the owner window
} moon_MouseWheelEvent;

/**
 * Mouse wheel events parameters (MouseWheelScrolled)
 */
typedef struct MOON_CSFML_API moon_MouseWheelScrollEvent {
	int 	wheel; //!< Which wheel (for mice with multiple ones)
	float 	delta; //!< Wheel offset (positive is up/left, negative is down/right). High-precision mice may use non-integral offsets.
	int 	x;     //!< X position of the mouse pointer, relative to the left of the owner window
	int 	y;     //!< Y position of the mouse pointer, relative to the top of the owner window
} moon_MouseWheelScrollEvent;

/**
 * Touch events parameters (TouchBegan, TouchMoved, TouchEnded)
 */
typedef struct MOON_CSFML_API moon_TouchEvent {
	unsigned int finger; //!< Index of the finger in case of multi-touch events
	int x;               //!< X position of the touch, relative to the left of the owner window
	int y;               //!< Y position of the touch, relative to the top of the owner window
} moon_TouchEvent;

/**
 * Sensor event parameters (SensorChanged)
 */
typedef struct MOON_CSFML_API moon_SensorEvent {
	int 	type; 	//!< Type of the sensor
	float 	x; 		//!< Current value of the sensor on X axis
	float 	y; 		//!< Current value of the sensor on Y axis
	float 	z; 		//!< Current value of the sensor on Z axis
} moon_SensorEvent;


/**
 * Defines a system event and its parameters.
 * After creation event type is moon_Event_Type_Closed, so you
 *have to use 'moon_Event_reset' before poll/wait event.
 */
typedef struct MOON_CSFML_API moon_Event {
	int type;	//!< Type of the event
	union
	{

		moon_KeyEvent key; //!< Key event parameters (Event::KeyPressed, Event::KeyReleased)

		moon_MouseButtonEvent mouse_button; 			//!< Mouse button event parameters (Event::MouseButtonPressed, Event::MouseButtonReleased)
		moon_MouseMoveEvent mouse_move;         		//!< Mouse move event parameters (Event::MouseMoved)
		moon_MouseWheelEvent mouse_wheel;        		//!< Mouse wheel event parameters (Event::MouseWheelMoved) (deprecated)
		moon_MouseWheelScrollEvent mouse_wheel_scroll;  //!< Mouse wheel event parameters (Event::MouseWheelScrolled)

		moon_SizeEvent size;              //!< Size event parameters (Event::Resized)

		moon_TextEvent text;              //!< Text event parameters (Event::TextEntered)

		moon_TouchEvent touch;             //!< Touch events parameters (Event::TouchBegan, Event::TouchMoved, Event::TouchEnded)
		moon_SensorEvent sensor;            //!< Sensor event parameters (Event::SensorChanged)
	} evt;
} moon_Event;


/**
 * Simply sets type to moon_Event_Type_Count.
 * Mandatory call before poll/wait event because
 *initial event type is 0, which is moon_Event_Type_Closed.
 */
MOON_CSFML_API void
moon_Event_reset(moon_Event* self);


#ifdef __cplusplus
}
#endif


#endif
