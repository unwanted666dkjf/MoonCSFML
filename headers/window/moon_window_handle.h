#ifndef MOON_CSFML_WINDOW_MOON_WINDOW_HANDLE_H
#define MOON_CSFML_WINDOW_MOON_WINDOW_HANDLE_H


#ifdef __cplusplus
extern "C" {
#endif


#if defined(_WIN32) || defined(_WIN64)

#	include <windows.h>


	typedef HWND moon_WindowHandle;
#elif defined(__linux__)
	typedef unsigned long moon_WindowHandle;
#else
	typedef void* moon_WindowHandle;
#endif


#ifdef __cplusplus
}
#endif


#endif
