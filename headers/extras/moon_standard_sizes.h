#ifndef MOON_CSFML_EXTRAS_MOON_STANDARD_SIZES_H
#define MOON_CSFML_EXTRAS_MOON_STANDARD_SIZES_H


#include "../window/moon_video_mode.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * A structure for storing information about the size
 *of the game window and cell (block) in the game world.
 * Note: the number of columns and/or rows can be 1 more
 *than it actually is.
 */
typedef struct MOON_CSFML_API moon_StandardSizes {
	unsigned int size;				// Cell size
	unsigned int rows;				// Number of lines (in cells) of the game window
	unsigned int cols;				// Number of columns (in cells) of the game window
} moon_StandardSizes;


/**
 * Returns standard sizes for current desktop video mode.
 */
MOON_CSFML_API moon_StandardSizes
moon_StandardSizes_get_desktop_sizes();

/**
 * Returns standard sizes for given video mode.
 */
MOON_CSFML_API moon_StandardSizes
moon_StandardSizes_get_sizes(const moon_VideoMode* video_mode);

/**
 * Returns size of the block(cell) for current video mode.
 */
MOON_CSFML_API unsigned int
moon_StandardSizes_get_size(const moon_VideoMode* video_mode);


#ifdef __cplusplus
}
#endif


#endif
