#ifndef MOON_CSFML_WINDOW_MOON_KEYBOARD_H
#define MOON_CSFML_WINDOW_MOON_KEYBOARD_H


#include "../import_macro.h"


#ifdef __cplusplus
extern "C" {
#endif


#include <wchar.h>


/**
 * Check if a key is pressed.
 * 1 if key is pressed, 0 otherwise.
 */
MOON_CSFML_API int
moon_Keyboard_is_key_pressed(int key);

/**
 * Check if scancode is pressed.
 * 1 if key is pressed, 0 otherwise.
 */
MOON_CSFML_API int
moon_Keyboard_is_scancode_pressed(int scancode);

/**
 * Localize a physical key to a logical one.
 * Scancode to keycode.
 */
MOON_CSFML_API int
moon_Keyboard_localize(int scancode);

/**
 * Identify the physical key corresponding to a logical one.
 * Keycode to scancode.
 */
MOON_CSFML_API int
moon_Keyboard_delocalize(int keycode);

/**
 * Provide ansi string representation for a given scancode.
 * Returns NULL or empty string if fails.
 * Result is null-terminated.
 * Result must be freed after usage.
 */
MOON_CSFML_API char*
moon_Keyboard_get_descriptionA(int scancode);

/**
 * Provide wide string representation for a given scancode.
 * Returns NULL or empty string if fails.
 * Result is null-terminated.
 * Result must be freed after usage.
 */
MOON_CSFML_API wchar_t*
moon_Keyboard_get_descriptionW(int scancode);

/**
 * Show or hide the virtual keyboard.
 * 1 to show, 0 to hide.
 */
MOON_CSFML_API void
moon_Keyboard_set_virtual_keyboard_visible(int visible);


enum
{
	moon_Keyboard_Key_Unknown = -1, //!< Unhandled key
	moon_Keyboard_Key_A = 0,        //!< The A key
	moon_Keyboard_Key_B,            //!< The B key
	moon_Keyboard_Key_C,            //!< The C key
	moon_Keyboard_Key_D,            //!< The D key
	moon_Keyboard_Key_E,            //!< The E key
	moon_Keyboard_Key_F,            //!< The F key
	moon_Keyboard_Key_G,            //!< The G key
	moon_Keyboard_Key_H,            //!< The H key
	moon_Keyboard_Key_I,            //!< The I key
	moon_Keyboard_Key_J,            //!< The J key
	moon_Keyboard_Key_K,            //!< The K key
	moon_Keyboard_Key_L,            //!< The L key
	moon_Keyboard_Key_M,            //!< The M key
	moon_Keyboard_Key_N,            //!< The N key
	moon_Keyboard_Key_O,            //!< The O key
	moon_Keyboard_Key_P,            //!< The P key
	moon_Keyboard_Key_Q,            //!< The Q key
	moon_Keyboard_Key_R,            //!< The R key
	moon_Keyboard_Key_S,            //!< The S key
	moon_Keyboard_Key_T,            //!< The T key
	moon_Keyboard_Key_U,            //!< The U key
	moon_Keyboard_Key_V,            //!< The V key
	moon_Keyboard_Key_W,            //!< The W key
	moon_Keyboard_Key_X,            //!< The X key
	moon_Keyboard_Key_Y,            //!< The Y key
	moon_Keyboard_Key_Z,            //!< The Z key
	moon_Keyboard_Key_Num0,         //!< The 0 key
	moon_Keyboard_Key_Num1,         //!< The 1 key
	moon_Keyboard_Key_Num2,         //!< The 2 key
	moon_Keyboard_Key_Num3,         //!< The 3 key
	moon_Keyboard_Key_Num4,         //!< The 4 key
	moon_Keyboard_Key_Num5,         //!< The 5 key
	moon_Keyboard_Key_Num6,         //!< The 6 key
	moon_Keyboard_Key_Num7,         //!< The 7 key
	moon_Keyboard_Key_Num8,         //!< The 8 key
	moon_Keyboard_Key_Num9,         //!< The 9 key
	moon_Keyboard_Key_Escape,       //!< The Escape key
	moon_Keyboard_Key_LControl,     //!< The left Control key
	moon_Keyboard_Key_LShift,       //!< The left Shift key
	moon_Keyboard_Key_LAlt,         //!< The left Alt key
	moon_Keyboard_Key_LSystem,      //!< The left OS specific key: window (Windows and Linux)
	moon_Keyboard_Key_RControl,     //!< The right Control key
	moon_Keyboard_Key_RShift,       //!< The right Shift key
	moon_Keyboard_Key_RAlt,         //!< The right Alt key
	moon_Keyboard_Key_RSystem,      //!< The right OS specific key: window (Windows and Linux)
	moon_Keyboard_Key_Menu,         //!< The Menu key
	moon_Keyboard_Key_LBracket,     //!< The [ key
	moon_Keyboard_Key_RBracket,     //!< The ] key
	moon_Keyboard_Key_Semicolon,    //!< The ; key
	moon_Keyboard_Key_Comma,        //!< The , key
	moon_Keyboard_Key_Period,       //!< The . key
	moon_Keyboard_Key_Apostrophe,   //!< The ' key
	moon_Keyboard_Key_Slash,        //!< The / key
	moon_Keyboard_Key_Backslash,    //!< The \ key
	moon_Keyboard_Key_Grave,        //!< The ` key
	moon_Keyboard_Key_Equal,        //!< The = key
	moon_Keyboard_Key_Hyphen,       //!< The - key (hyphen)
	moon_Keyboard_Key_Space,        //!< The Space key
	moon_Keyboard_Key_Enter,        //!< The Enter/Return keys
	moon_Keyboard_Key_Backspace,    //!< The Backspace key
	moon_Keyboard_Key_Tab,          //!< The Tabulation key
	moon_Keyboard_Key_PageUp,       //!< The Page up key
	moon_Keyboard_Key_PageDown,     //!< The Page down key
	moon_Keyboard_Key_End,          //!< The End key
	moon_Keyboard_Key_Home,         //!< The Home key
	moon_Keyboard_Key_Insert,       //!< The Insert key
	moon_Keyboard_Key_Delete,       //!< The Delete key
	moon_Keyboard_Key_Add,          //!< The + key
	moon_Keyboard_Key_Subtract,     //!< The - key (minus, usually from numpad)
	moon_Keyboard_Key_Multiply,     //!< The * key
	moon_Keyboard_Key_Divide,       //!< The / key
	moon_Keyboard_Key_Left,         //!< Left arrow
	moon_Keyboard_Key_Right,        //!< Right arrow
	moon_Keyboard_Key_Up,           //!< Up arrow
	moon_Keyboard_Key_Down,         //!< Down arrow
	moon_Keyboard_Key_Numpad0,      //!< The numpad 0 key
	moon_Keyboard_Key_Numpad1,      //!< The numpad 1 key
	moon_Keyboard_Key_Numpad2,      //!< The numpad 2 key
	moon_Keyboard_Key_Numpad3,      //!< The numpad 3 key
	moon_Keyboard_Key_Numpad4,      //!< The numpad 4 key
	moon_Keyboard_Key_Numpad5,      //!< The numpad 5 key
	moon_Keyboard_Key_Numpad6,      //!< The numpad 6 key
	moon_Keyboard_Key_Numpad7,      //!< The numpad 7 key
	moon_Keyboard_Key_Numpad8,      //!< The numpad 8 key
	moon_Keyboard_Key_Numpad9,      //!< The numpad 9 key
	moon_Keyboard_Key_F1,           //!< The F1 key
	moon_Keyboard_Key_F2,           //!< The F2 key
	moon_Keyboard_Key_F3,           //!< The F3 key
	moon_Keyboard_Key_F4,           //!< The F4 key
	moon_Keyboard_Key_F5,           //!< The F5 key
	moon_Keyboard_Key_F6,           //!< The F6 key
	moon_Keyboard_Key_F7,           //!< The F7 key
	moon_Keyboard_Key_F8,           //!< The F8 key
	moon_Keyboard_Key_F9,           //!< The F9 key
	moon_Keyboard_Key_F10,          //!< The F10 key
	moon_Keyboard_Key_F11,          //!< The F11 key
	moon_Keyboard_Key_F12,          //!< The F12 key
	moon_Keyboard_Key_F13,          //!< The F13 key
	moon_Keyboard_Key_F14,          //!< The F14 key
	moon_Keyboard_Key_F15,          //!< The F15 key
	moon_Keyboard_Key_Pause,        //!< The Pause key

	moon_Keyboard_Key_KeyCount,     //!< Keep last -- the total number of keyboard keys

		// Deprecated values:

	moon_Keyboard_Key_Tilde     = moon_Keyboard_Key_Grave,     //!< \deprecated Use Grave instead
	moon_Keyboard_Key_Dash      = moon_Keyboard_Key_Hyphen,    //!< \deprecated Use Hyphen instead
	moon_Keyboard_Key_BackSpace = moon_Keyboard_Key_Backspace, //!< \deprecated Use Backspace instead
	moon_Keyboard_Key_BackSlash = moon_Keyboard_Key_Backslash, //!< \deprecated Use Backslash instead
	moon_Keyboard_Key_SemiColon = moon_Keyboard_Key_Semicolon, //!< \deprecated Use Semicolon instead
	moon_Keyboard_Key_Return    = moon_Keyboard_Key_Enter,     //!< \deprecated Use Enter instead
	moon_Keyboard_Key_Quote     = moon_Keyboard_Key_Apostrophe //!< \deprecated Use Apostrophe
};

enum
{
	moon_Keyboard_Scancode_Unknown = -1,       //!< Represents any scancode not present in this enum
	moon_Keyboard_Scancode_A = 0,              //!< Keyboard a and A key
	moon_Keyboard_Scancode_B,                  //!< Keyboard b and B key
	moon_Keyboard_Scancode_C,                  //!< Keyboard c and C key
	moon_Keyboard_Scancode_D,                  //!< Keyboard d and D key
	moon_Keyboard_Scancode_E,                  //!< Keyboard e and E key
	moon_Keyboard_Scancode_F,                  //!< Keyboard f and F key
	moon_Keyboard_Scancode_G,                  //!< Keyboard g and G key
	moon_Keyboard_Scancode_H,                  //!< Keyboard h and H key
	moon_Keyboard_Scancode_I,                  //!< Keyboard i and I key
	moon_Keyboard_Scancode_J,                  //!< Keyboard j and J key
	moon_Keyboard_Scancode_K,                  //!< Keyboard k and K key
	moon_Keyboard_Scancode_L,                  //!< Keyboard l and L key
	moon_Keyboard_Scancode_M,                  //!< Keyboard m and M key
	moon_Keyboard_Scancode_N,                  //!< Keyboard n and N key
	moon_Keyboard_Scancode_O,                  //!< Keyboard o and O key
	moon_Keyboard_Scancode_P,                  //!< Keyboard p and P key
	moon_Keyboard_Scancode_Q,                  //!< Keyboard q and Q key
	moon_Keyboard_Scancode_R,                  //!< Keyboard r and R key
	moon_Keyboard_Scancode_S,                  //!< Keyboard s and S key
	moon_Keyboard_Scancode_T,                  //!< Keyboard t and T key
	moon_Keyboard_Scancode_U,                  //!< Keyboard u and U key
	moon_Keyboard_Scancode_V,                  //!< Keyboard v and V key
	moon_Keyboard_Scancode_W,                  //!< Keyboard w and W key
	moon_Keyboard_Scancode_X,                  //!< Keyboard x and X key
	moon_Keyboard_Scancode_Y,                  //!< Keyboard y and Y key
	moon_Keyboard_Scancode_Z,                  //!< Keyboard z and Z key
	moon_Keyboard_Scancode_Num1,               //!< Keyboard 1 and ! key
	moon_Keyboard_Scancode_Num2,               //!< Keyboard 2 and @ key
	moon_Keyboard_Scancode_Num3,               //!< Keyboard 3 and # key
	moon_Keyboard_Scancode_Num4,               //!< Keyboard 4 and $ key
	moon_Keyboard_Scancode_Num5,               //!< Keyboard 5 and % key
	moon_Keyboard_Scancode_Num6,               //!< Keyboard 6 and ^ key
	moon_Keyboard_Scancode_Num7,               //!< Keyboard 7 and & key
	moon_Keyboard_Scancode_Num8,               //!< Keyboard 8 and * key
	moon_Keyboard_Scancode_Num9,               //!< Keyboard 9 and ) key
	moon_Keyboard_Scancode_Num0,               //!< Keyboard 0 and ) key
	moon_Keyboard_Scancode_Enter,              //!< Keyboard Enter/Return key
	moon_Keyboard_Scancode_Escape,             //!< Keyboard Escape key
	moon_Keyboard_Scancode_Backspace,          //!< Keyboard Backspace key
	moon_Keyboard_Scancode_Tab,                //!< Keyboard Tab key
	moon_Keyboard_Scancode_Space,              //!< Keyboard Space key
	moon_Keyboard_Scancode_Hyphen,             //!< Keyboard - and _ key
	moon_Keyboard_Scancode_Equal,              //!< Keyboard = and +
	moon_Keyboard_Scancode_LBracket,           //!< Keyboard [ and { key
	moon_Keyboard_Scancode_RBracket,           //!< Keyboard ] and } key
	// For US keyboards mapped to key 29 (Microsoft Keyboard Scan Code Specification)
	// For Non-US keyboards mapped to key 42 (Microsoft Keyboard Scan Code Specification)
	// Typical language mappings: Belg:£µ` FrCa:<>} Dan:*' Dutch:`´ Fren:µ* Ger:'# Ital:§ù LatAm:[}` Nor:*@ Span:ç} Swed:*' Swiss:$£} UK:~# Brazil:}]
	moon_Keyboard_Scancode_Backslash,          //!< Keyboard \ and | key OR various keys for Non-US keyboards
	moon_Keyboard_Scancode_Semicolon,          //!< Keyboard ; and : key
	moon_Keyboard_Scancode_Apostrophe,         //!< Keyboard ' and " key
	moon_Keyboard_Scancode_Grave,              //!< Keyboard ` and ~ key
	moon_Keyboard_Scancode_Comma,              //!< Keyboard , and < key
	moon_Keyboard_Scancode_Period,             //!< Keyboard . and > key
	moon_Keyboard_Scancode_Slash,              //!< Keyboard / and ? key
	moon_Keyboard_Scancode_F1,                 //!< Keyboard F1 key
	moon_Keyboard_Scancode_F2,                 //!< Keyboard F2 key
	moon_Keyboard_Scancode_F3,                 //!< Keyboard F3 key
	moon_Keyboard_Scancode_F4,                 //!< Keyboard F4 key
	moon_Keyboard_Scancode_F5,                 //!< Keyboard F5 key
	moon_Keyboard_Scancode_F6,                 //!< Keyboard F6 key
	moon_Keyboard_Scancode_F7,                 //!< Keyboard F7 key
	moon_Keyboard_Scancode_F8,                 //!< Keyboard F8 key
	moon_Keyboard_Scancode_F9,                 //!< Keyboard F9 key
	moon_Keyboard_Scancode_F10,                //!< Keyboard F10 key
	moon_Keyboard_Scancode_F11,                //!< Keyboard F11 key
	moon_Keyboard_Scancode_F12,                //!< Keyboard F12 key
	moon_Keyboard_Scancode_F13,                //!< Keyboard F13 key
	moon_Keyboard_Scancode_F14,                //!< Keyboard F14 key
	moon_Keyboard_Scancode_F15,                //!< Keyboard F15 key
	moon_Keyboard_Scancode_F16,                //!< Keyboard F16 key
	moon_Keyboard_Scancode_F17,                //!< Keyboard F17 key
	moon_Keyboard_Scancode_F18,                //!< Keyboard F18 key
	moon_Keyboard_Scancode_F19,                //!< Keyboard F19 key
	moon_Keyboard_Scancode_F20,                //!< Keyboard F20 key
	moon_Keyboard_Scancode_F21,                //!< Keyboard F21 key
	moon_Keyboard_Scancode_F22,                //!< Keyboard F22 key
	moon_Keyboard_Scancode_F23,                //!< Keyboard F23 key
	moon_Keyboard_Scancode_F24,                //!< Keyboard F24 key
	moon_Keyboard_Scancode_CapsLock,           //!< Keyboard Caps %Lock key
	moon_Keyboard_Scancode_PrintScreen,        //!< Keyboard Print Screen key
	moon_Keyboard_Scancode_ScrollLock,         //!< Keyboard Scroll %Lock key
	moon_Keyboard_Scancode_Pause,              //!< Keyboard Pause key
	moon_Keyboard_Scancode_Insert,             //!< Keyboard Insert key
	moon_Keyboard_Scancode_Home,               //!< Keyboard Home key
	moon_Keyboard_Scancode_PageUp,             //!< Keyboard Page Up key
	moon_Keyboard_Scancode_Delete,             //!< Keyboard Delete Forward key
	moon_Keyboard_Scancode_End,                //!< Keyboard End key
	moon_Keyboard_Scancode_PageDown,           //!< Keyboard Page Down key
	moon_Keyboard_Scancode_Right,              //!< Keyboard Right Arrow key
	moon_Keyboard_Scancode_Left,               //!< Keyboard Left Arrow key
	moon_Keyboard_Scancode_Down,               //!< Keyboard Down Arrow key
	moon_Keyboard_Scancode_Up,                 //!< Keyboard Up Arrow key
	moon_Keyboard_Scancode_NumLock,            //!< Keypad Num %Lock and Clear key
	moon_Keyboard_Scancode_NumpadDivide,       //!< Keypad / key
	moon_Keyboard_Scancode_NumpadMultiply,     //!< Keypad * key
	moon_Keyboard_Scancode_NumpadMinus,        //!< Keypad - key
	moon_Keyboard_Scancode_NumpadPlus,         //!< Keypad + key
	moon_Keyboard_Scancode_NumpadEqual,        //!< keypad = key
	moon_Keyboard_Scancode_NumpadEnter,        //!< Keypad Enter/Return key
	moon_Keyboard_Scancode_NumpadDecimal,      //!< Keypad . and Delete key
	moon_Keyboard_Scancode_Numpad1,            //!< Keypad 1 and End key
	moon_Keyboard_Scancode_Numpad2,            //!< Keypad 2 and Down Arrow key
	moon_Keyboard_Scancode_Numpad3,            //!< Keypad 3 and Page Down key
	moon_Keyboard_Scancode_Numpad4,            //!< Keypad 4 and Left Arrow key
	moon_Keyboard_Scancode_Numpad5,            //!< Keypad 5 key
	moon_Keyboard_Scancode_Numpad6,            //!< Keypad 6 and Right Arrow key
	moon_Keyboard_Scancode_Numpad7,            //!< Keypad 7 and Home key
	moon_Keyboard_Scancode_Numpad8,            //!< Keypad 8 and Up Arrow key
	moon_Keyboard_Scancode_Numpad9,            //!< Keypad 9 and Page Up key
	moon_Keyboard_Scancode_Numpad0,            //!< Keypad 0 and Insert key
	// For US keyboards doesn't exist
	// For Non-US keyboards mapped to key 45 (Microsoft Keyboard Scan Code Specification)
	// Typical language mappings: Belg:<\> FrCa:«°» Dan:<\> Dutch:]|[ Fren:<> Ger:<|> Ital:<> LatAm:<> Nor:<> Span:<> Swed:<|> Swiss:<\> UK:\| Brazil: \|.
	moon_Keyboard_Scancode_NonUsBackslash,     //!< Keyboard Non-US \ and | key
	moon_Keyboard_Scancode_Application,        //!< Keyboard Application key
	moon_Keyboard_Scancode_Execute,            //!< Keyboard Execute key
	moon_Keyboard_Scancode_ModeChange,         //!< Keyboard Mode Change key
	moon_Keyboard_Scancode_Help,               //!< Keyboard Help key
	moon_Keyboard_Scancode_Menu,               //!< Keyboard Menu key
	moon_Keyboard_Scancode_Select,             //!< Keyboard Select key
	moon_Keyboard_Scancode_Redo,               //!< Keyboard Redo key
	moon_Keyboard_Scancode_Undo,               //!< Keyboard Undo key
	moon_Keyboard_Scancode_Cut,                //!< Keyboard Cut key
	moon_Keyboard_Scancode_Copy,               //!< Keyboard Copy key
	moon_Keyboard_Scancode_Paste,              //!< Keyboard Paste key
	moon_Keyboard_Scancode_VolumeMute,         //!< Keyboard Volume Mute key
	moon_Keyboard_Scancode_VolumeUp,           //!< Keyboard Volume Up key
	moon_Keyboard_Scancode_VolumeDown,         //!< Keyboard Volume Down key
	moon_Keyboard_Scancode_MediaPlayPause,     //!< Keyboard Media Play Pause key
	moon_Keyboard_Scancode_MediaStop,          //!< Keyboard Media Stop key
	moon_Keyboard_Scancode_MediaNextTrack,     //!< Keyboard Media Next Track key
	moon_Keyboard_Scancode_MediaPreviousTrack, //!< Keyboard Media Previous Track key
	moon_Keyboard_Scancode_LControl,           //!< Keyboard Left Control key
	moon_Keyboard_Scancode_LShift,             //!< Keyboard Left Shift key
	moon_Keyboard_Scancode_LAlt,               //!< Keyboard Left Alt key
	moon_Keyboard_Scancode_LSystem,            //!< Keyboard Left System key
	moon_Keyboard_Scancode_RControl,           //!< Keyboard Right Control key
	moon_Keyboard_Scancode_RShift,             //!< Keyboard Right Shift key
	moon_Keyboard_Scancode_RAlt,               //!< Keyboard Right Alt key
	moon_Keyboard_Scancode_RSystem,            //!< Keyboard Right System key
	moon_Keyboard_Scancode_Back,               //!< Keyboard Back key
	moon_Keyboard_Scancode_Forward,            //!< Keyboard Forward key
	moon_Keyboard_Scancode_Refresh,            //!< Keyboard Refresh key
	moon_Keyboard_Scancode_Stop,               //!< Keyboard Stop key
	moon_Keyboard_Scancode_Search,             //!< Keyboard Search key
	moon_Keyboard_Scancode_Favorites,          //!< Keyboard Favorites key
	moon_Keyboard_Scancode_HomePage,           //!< Keyboard Home Page key
	moon_Keyboard_Scancode_LaunchApplication1, //!< Keyboard Launch Application 1 key
	moon_Keyboard_Scancode_LaunchApplication2, //!< Keyboard Launch Application 2 key
	moon_Keyboard_Scancode_LaunchMail,         //!< Keyboard Launch Mail key
	moon_Keyboard_Scancode_LaunchMediaSelect,  //!< Keyboard Launch Media Select key

	moon_Keyboard_Scancode_ScancodeCount       //!< Keep last -- the total number of scancodes
};


#ifdef __cplusplus
}
#endif


#endif
