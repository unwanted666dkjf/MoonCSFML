#ifndef MOON_CSFML_EXTRAS_MOON_WINSTUFF_H
#define MOON_CSFML_EXTRAS_MOON_WINSTUFF_H


#ifdef __cplusplus
extern "C" {
#endif


#ifdef _WIN32


#include <wchar.h>



#include "../graphics/moon_render_window.h"


/**
 * Changes the desktop wallpaper.
 * The path to the wallpaper must
 *be ansi null-terminated string.
 * Returns 1 if success, 0 otherwise.
 */
MOON_CSFML_API int
moon_Winstuff_change_desktop_wallpaperA(const char* wp_path);

/**
 * Changes the desktop wallpaper.
 * The path to the wallpaper must
 *be wide null-terminated string.
 * Returns 1 if success, 0 otherwise.
 */
MOON_CSFML_API int
moon_Winstuff_change_desktop_wallpaperW(const wchar_t* wp_path);

/**
 * Places a window on top of other windows and gives it focus.
 * Returns 1 if it succeeds and 0 if it fails.
 */
MOON_CSFML_API int
moon_Winstuff_set_wnd_topmost(const moon_RenderWindow* wnd);

/**
 * Changes the transparency of the whole window.
 * 0 (fully transparent) to 255 (opaque).
 * Returns 1 if it succeeds and 0 if it fails.
 */
MOON_CSFML_API int
moon_Winstuff_set_wnd_alpha(
	const moon_RenderWindow* wnd,
	unsigned char alpha
);

/**
 * Makes transparent a specific color on the window.
 */
MOON_CSFML_API int
moon_Winstuff_make_wnd_clr_transparent(
	const moon_RenderWindow* wnd,
	const moon_Color* rgb_clr
);

#else

/**
 * Prints 'No Windows zone.'
 */
MOON_CSFML_API void
moon_bye_windows();


#endif


#ifdef __cplusplus
}
#endif


#endif
