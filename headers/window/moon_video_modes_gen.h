#ifndef MOON_CSFML_WINDOW_MOON_VIDEO_MODES_GEN_H
#define MOON_CSFML_WINDOW_MOON_VIDEO_MODES_GEN_H


#include "./moon_video_mode.h"


#ifdef __cplusplus
extern "C" {
#endif


struct MOON_CSFML_API moon_VideoModesGen;


/**
 * Generates available video modes.
 * On Linux, depth per pixel for modes will
 *always be default. Uses Xrandr.
 * On Windows may work faster. Even if Windows sucks,
 *winapi is cool.
 * Alternative to sf::VideoMode::getFullscreenModes().
 */
typedef struct moon_VideoModesGen moon_VideoModesGen;


/**
 * Creates new generator.
 */
MOON_CSFML_API moon_VideoModesGen*
moon_VideoModesGen_create();

/**
 * Destroys generator.
 */
void
moon_VideoModesGen_destroy(moon_VideoModesGen* self);

/**
 * Returns 1 if generator can create another one
 *item, 0 otherwise.
 */
MOON_CSFML_API int
moon_VideoModesGen_has_next(const moon_VideoModesGen* self);

/**
 * Creates new video mode.
 */
MOON_CSFML_API moon_VideoMode
moon_VideoModesGen_next(moon_VideoModesGen* self);


#ifdef __cplusplus
}
#endif


#endif
