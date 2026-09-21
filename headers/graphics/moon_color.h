#ifndef MOON_CSFML_GRAPHICS_MOON_COLOR_H
#define MOON_CSFML_GRAPHICS_MOON_COLOR_H


#include "../import_macro.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Utility struct for manipulating RGBA colors.
 */
typedef struct MOON_CSFML_API moon_Color {
	unsigned char red;
	unsigned char green;
	unsigned char blue;
	unsigned char alpha;
} moon_Color;


/**
 * Returns copy of this color.
 */
MOON_CSFML_API moon_Color
moon_Color_get_copy(const moon_Color* self);

/**
 * Creates color from it's
 *32-bit unsigned integer representation.
 */
MOON_CSFML_API moon_Color
moon_Color_from_integer(unsigned int color);

/**
 * Creates new color from rgb values.
 */
MOON_CSFML_API moon_Color
moon_Color_from_rgb(
	unsigned char red,
	unsigned char green,
	unsigned char blue
);

/**
 * Creates new color from rgba values.
 */
MOON_CSFML_API moon_Color
moon_Color_from_rgba(
	unsigned char red,
	unsigned char green,
	unsigned char blue,
	unsigned char alpha
);

/**
 * Returns inverted version of the color.
 * Like:
 * 	255 - color.r,
 * 	255 - color.g,
 * 	255 - color.b
 * Alpha stays the same.
 */
MOON_CSFML_API moon_Color
moon_Color_get_inverse(const moon_Color* self);

/**
 * Returns color represented as a 32-bit unsigned integer.
 */
MOON_CSFML_API unsigned int
moon_Color_to_integer(const moon_Color* self);

/**
 * Returns 1 if colors are equal, 0 otherwise.
 * Colors are equal if their rgba components are
 *equal.
 */
MOON_CSFML_API int
moon_Color_is_eq(
	const moon_Color* self,
	const moon_Color* other
);

/**
 * Returns 1 if colors are not equal, 0 otherwise.
 * Colors are equal if their rgba components are
 *equal.
 */
MOON_CSFML_API int
moon_Color_is_ne(
	const moon_Color* self,
	const moon_Color* other
);

/**
 * Returns 1 if colors are equal, 0 otherwise.
 * Colors are equal if their rgb components are
 *equal.
 */
MOON_CSFML_API int
moon_Color_is_rgb_eq(
	const moon_Color* self,
	const moon_Color* other
);

/**
 * Returns 1 if colors are not equal, 0 otherwise.
 * Colors are equal if their rgb components are
 *equal.
 */
MOON_CSFML_API int
moon_Color_is_rgb_ne(
	const moon_Color* self,
	const moon_Color* other
);


#ifdef __cplusplus
}
#endif


#endif
