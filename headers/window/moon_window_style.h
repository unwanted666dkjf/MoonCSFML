#ifndef MOON_CSFML_WINDOW_MOON_WINDOW_STYLE_H
#define MOON_CSFML_WINDOW_MOON_WINDOW_STYLE_H


#ifdef __cplusplus
extern "C" {
#endif


enum
{
	moon_Window_Style_None       = 0,      //!< No border / title bar (this flag and all others are mutually exclusive)
	moon_Window_Style_Titlebar   = 1 << 0, //!< Title bar + fixed border
	moon_Window_Style_Resize     = 1 << 1, //!< Title bar + resizable border + maximize button
	moon_Window_Style_Close      = 1 << 2, //!< Title bar + close button
	moon_Window_Style_Fullscreen = 1 << 3, //!< Fullscreen mode (this flag and all others are mutually exclusive)

	moon_Window_Style_Default = moon_Window_Style_Titlebar
		| moon_Window_Style_Resize
		| moon_Window_Style_Close //!< Default window style
};


#ifdef __cplusplus
}
#endif


#endif
