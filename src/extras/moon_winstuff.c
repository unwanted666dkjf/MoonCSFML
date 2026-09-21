#ifdef _WIN32


#include <windows.h>


#ifndef WIN32_LEAN_AND_MEAN
#	define WIN32_LEAN_AND_MEAN
#endif

#ifndef GWL_EXSTYLE
#	define GWL_EXSTYLE (-20)
#endif

#ifndef SWP_NOSIZE
#	define SWP_NOSIZE (0x0001)
#endif

#ifndef SWP_NOMOVE
#	define SWP_NOMOVE (0x0002)
#endif

#ifndef SWP_SHOWWINDOW
#	define SWP_SHOWWINDOW (0x0040)
#endif



#include "../../headers/extras/moon_winstuff.h"


int
moon_Winstuff_change_desktop_wallpaperA(const char* wp_path) {
	return SystemParametersInfoA(
		SPI_SETDESKWALLPAPER,
		0,
		(PVOID)wp_path,
		SPIF_UPDATEINIFILE | SPIF_SENDCHANGE
	);
}

int
moon_Winstuff_change_desktop_wallpaperW(const wchar_t* wp_path) {
	return SystemParametersInfoW(
		SPI_SETDESKWALLPAPER,
		0,
		(PVOID)wp_path,
		SPIF_UPDATEINIFILE | SPIF_SENDCHANGE
	);
}

int
moon_Winstuff_set_wnd_topmost(const moon_RenderWindow* wnd) {
	moon_WindowHandle hwnd = moon_RenderWindow_get_system_handle(wnd);
	if (IsIconic(hwnd)) {
		ShowWindow(hwnd, SW_RESTORE);
	}
	if (
		!SetWindowPos(
			hwnd, HWND_TOPMOST, 0, 0, 0, 0,
			SWP_NOMOVE
			| SWP_NOSIZE
			| SWP_SHOWWINDOW
		)
	) {
		return 0;
	}
	if (SetForegroundWindow(hwnd)) {
		return 1;
	}
	return 0;
}

int
moon_Winstuff_set_wnd_alpha(
	const moon_RenderWindow* wnd,
	unsigned char alpha
) {
	moon_WindowHandle hwnd = moon_RenderWindow_get_system_handle(wnd);
	LONG_PTR ex = GetWindowLongPtr(hwnd, GWL_EXSTYLE);
	SetWindowLongPtr(hwnd, GWL_EXSTYLE, ex | WS_EX_LAYERED);
	return SetLayeredWindowAttributes(hwnd, 0, alpha, LWA_ALPHA);
}

int
moon_Winstuff_make_wnd_clr_transparent(
	const moon_RenderWindow* wnd,
	const moon_Color* rgb_clr
) {
	moon_WindowHandle hwnd = moon_RenderWindow_get_system_handle(wnd);

	LONG_PTR ex = GetWindowLongPtr(hwnd, GWL_EXSTYLE);
	SetWindowLongPtr(hwnd, GWL_EXSTYLE, ex | WS_EX_LAYERED);

	COLORREF colorkey = (COLORREF)(rgb_clr->red)
		| ((COLORREF)(rgb_clr->green) << 8)
		| ((COLORREF)(rgb_clr->blue) << 16);
	return SetLayeredWindowAttributes(hwnd, colorkey, 0, LWA_COLORKEY) != 0;
}

#else


#include <stdio.h>


void
moon_bye_windows() {
	printf("No Windows zone! Fuck Microsoft!\n");
}


#endif
