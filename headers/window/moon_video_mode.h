#ifndef MOON_CSFML_WINDOW_MOON_VIDEO_MODE_H
#define MOON_CSFML_WINDOW_MOON_VIDEO_MODE_H


#include "../import_macro.h"


#ifdef __cplusplus
extern "C" {
#endif


#define moon_VideoMode_DefaultBitsPerPixel 32


/**
 * VideoMode defines a video mode (width, height, bpp).
 */
typedef struct MOON_CSFML_API moon_VideoMode {
	unsigned int width;
	unsigned int height;
	unsigned int bits_per_pixel;
} moon_VideoMode;


/**
 * Returns copy of this video mode.
 */
MOON_CSFML_API moon_VideoMode
moon_VideoMode_get_copy(const moon_VideoMode* self);

/**
 * Returns the current desktop video mode.
 */
MOON_CSFML_API moon_VideoMode
moon_VideoMode_get_desktop_mode();

/**
 * Tells whether or not the video mode is valid.
 * Returns 1 if the video mode is valid for fullscreen mode,
 *otherwise returns 0.
 */
MOON_CSFML_API int
moon_VideoMode_is_valid(const moon_VideoMode* mode);


#ifdef __cplusplus
}
#endif


#endif
