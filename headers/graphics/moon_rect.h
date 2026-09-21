#ifndef MOON_CSFML_GRAPHICS_MOON_RECT_H
#define MOON_CSFML_GRAPHICS_MOON_RECT_H


#include "../import_macro.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Utility struct for manipulating 2D axis aligned rectangles
 *of integers.
 */
typedef struct MOON_CSFML_API moon_IntRect {
	int left;
	int top;
	int width;
	int height;
} moon_IntRect;

/**
 * Utility struct for manipulating 2D axis aligned rectangles
 *of floats.
 */
typedef struct MOON_CSFML_API moon_FloatRect {
	float left;
	float top;
	float width;
	float height;
} moon_FloatRect;


/**
 * Creates empty IntRect.
 */
MOON_CSFML_API moon_IntRect
moon_IntRect_create_empty();

/**
 * Creates copy of this rectangle.
 */
MOON_CSFML_API moon_IntRect
moon_IntRect_get_copy(const moon_IntRect* self);

/**
 * Returns 1 if rectangle is empty, 0 otherwise.
 * Rectangle is empty if it's width and height both
 *are less or equal than 0.
 */
MOON_CSFML_API int
moon_IntRect_is_empty(const moon_IntRect* self);

/**
 * Returns 1 if rectangle contains point with
 *given coordinates. Otherwise, returns 0.
 */
MOON_CSFML_API int
moon_IntRect_contains(
	const moon_IntRect* self,
	int x, int y
);

/**
 * Returns 1 if rectangles are equal, 0 otherwise.
 * Rectangles are equal if theirs positions and size
 *are equal.
 */
MOON_CSFML_API int
moon_IntRect_is_eq(
	const moon_IntRect* self,
	const moon_IntRect* other
);

/**
 * Returns 1 if rectangles are not equal, 0 otherwise.
 * Rectangles are equal if theirs positions and size
 *are equal.
 */
MOON_CSFML_API int
moon_IntRect_is_ne(
	const moon_IntRect* self,
	const moon_IntRect* other
);

/**
 * Returns intersection of two rectangles.
 * If there was no intersection, returns
 *empty rectangle.
 */
MOON_CSFML_API moon_IntRect
moon_IntRect_get_intersection(
	const moon_IntRect* self,
	const moon_IntRect* other
);


/**
 * Creates empty FloatRect.
 */
MOON_CSFML_API moon_FloatRect
moon_FloatRect_create_empty();

/**
 * Creates copy of this rectangle.
 */
MOON_CSFML_API moon_FloatRect
moon_FloatRect_get_copy(const moon_FloatRect* self);

/**
 * Returns 1 if rectangle is empty, 0 otherwise.
 * Rectangle is empty if it's width and height both
 *are less or equal than 0.
 */
MOON_CSFML_API int
moon_FloatRect_is_empty(const moon_FloatRect* self);

/**
 * Returns 1 if rectangle contains point with
 *given coordinates. Otherwise, returns 0.
 */
MOON_CSFML_API int
moon_FloatRect_contains(
	const moon_FloatRect* self,
	float x, float y
);

/**
 * Returns 1 if rectangles are equal, 0 otherwise.
 * Rectangles are equal if theirs positions and size
 *are equal.
 */
MOON_CSFML_API int
moon_FloatRect_is_eq(
	const moon_FloatRect* self,
	const moon_FloatRect* other
);

/**
 * Returns 1 if rectangles are not equal, 0 otherwise.
 * Rectangles are equal if theirs positions and size
 *are equal.
 */
MOON_CSFML_API int
moon_FloatRect_is_ne(
	const moon_FloatRect* self,
	const moon_FloatRect* other
);

/**
 * Returns intersection of two rectangles.
 * If there was no intersection, returns
 *empty rectangle.
 */
MOON_CSFML_API moon_FloatRect
moon_FloatRect_get_intersection(
	const moon_FloatRect* self,
	const moon_FloatRect* other
);


/**
 * Converts FloatRect to IntRect.
 */
MOON_CSFML_API moon_IntRect
moon_Rect_ftoi(const moon_FloatRect* rect);

/**
 * Converts IntRect to FloatRect.
 */
MOON_CSFML_API moon_FloatRect
moon_Rect_itof(const moon_IntRect* rect);


#ifdef __cplusplus
}
#endif


#endif
