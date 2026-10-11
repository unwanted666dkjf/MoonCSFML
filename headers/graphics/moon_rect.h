#ifndef MOON_CSFML_GRAPHICS_MOON_RECT_H
#define MOON_CSFML_GRAPHICS_MOON_RECT_H


#include "../import_macro.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Rectangle internals.
 */
#define moon_Rect(Type)	\
	Type left;	\
	Type top;	\
	Type width;	\
	Type height;


/**
 * Returns 1 if rectangle is empty, 0 otherwise.
 * Rectangle is empty if it's width and height both
 *are less or equal than 0.
 */
#define moon_Rect_is_empty(rect)	\
	(rect.width <= 0 && rect.height <= 0)

/**
 * Returns 1 if rectangle contains point with
 *given coordinates. Otherwise, returns 0.
 */
#define moon_Rect_contains(rect, x, y)	\
	(										\
		(x) >= rect.left					\
		&& (x) <= (rect.left + rect.width)	\
		&& (y) >= rect.top					\
		&& (y) <= (rect.top + rect.height)	\
	)

/**
 * Returns 1 if rectangles are equal, 0 otherwise.
 * Rectangles are equal if theirs positions and size
 *are equal.
 */
#define moon_Rect_is_eq(rect1, rect2)	\
	(									\
		rect1.left 		== rect2.left	\
		&& rect1.top 	== rect2.top	\
		&& rect1.width 	== rect2.width	\
		&& rect1.height == rect2.height	\
	)

/**
 * Returns 1 if rectangles are not equal, 0 otherwise.
 * Rectangles are equal if theirs positions and size
 *are equal.
 */
#define moon_Rect_is_ne(rect1, rect2)	\
	(!moon_Rect_is_eq(rect1, rect2))

/**
 * Creates empty rectangle.
 */
#define moon_Rect_create_empty(RectType)	\
	(RectType){0, 0, 0, 0}

/**
 * Utility macros for converting one type of rectangle to another.
 */
#define moon_Rect_convert(RectTypeTo, rect)	\
	(RectTypeTo){rect.left, rect.top, rect.width, rect.height}

/**
 * Calculates intersection of two rectangles.
 * Result will be written into 'moon_Rect_res'.
 * 'VarType' is type of variables for calculating,
 *effects precision.
 * If there was no intersection, result is
 *empty rectangle.
 */
#define moon_Rect_Procedure_intersection(	\
	moon_Rect_res,							\
	VarType,								\
	rect1,									\
	rect2									\
)	\
{	\
	VarType left_Procedure__ 	= (rect1.left > rect2.left) ? rect1.left : rect2.left;	\
	VarType top_Procedure__		= (rect1.top > rect2.top) ? rect1.top : rect2.top;		\
																						\
	VarType rect1_right_Procedure__ = rect1.left + rect1.width;							\
	VarType rect2_right_Procedure__ = rect2.left + rect2.width;							\
	VarType right_Procedure__ = (														\
		(rect1_right_Procedure__ < rect2_right_Procedure__)								\
		? rect1_right_Procedure__														\
		: rect2_right_Procedure__														\
	);																					\
																						\
	VarType rect1_bottom_Procedure__ = rect1.top + rect1.height;						\
	VarType rect2_bottom_Procedure__ = rect2.top + rect2.height;						\
	VarType bottom_Procedure__ = (														\
		(rect1_bottom_Procedure__ < rect2_bottom_Procedure__)							\
		? rect1_bottom_Procedure__														\
		: rect2_bottom_Procedure__														\
	);																					\
																						\
	VarType width_Procedure__ 	= right_Procedure__  - left_Procedure__;				\
	VarType height_Procedure__ 	= bottom_Procedure__ - top_Procedure__;					\
																						\
	if (width_Procedure__ <= 0 || height_Procedure__ <= 0) {							\
		moon_Rect_res.left 		= 0;													\
		moon_Rect_res.top  		= 0;													\
		moon_Rect_res.width		= 0;													\
		moon_Rect_res.height	= 0;													\
	} else {																			\
		moon_Rect_res.left 		= left_Procedure__;										\
		moon_Rect_res.top  		= top_Procedure__;										\
		moon_Rect_res.width		= width_Procedure__;									\
		moon_Rect_res.height	= height_Procedure__;									\
	}																					\
}


/**
 * Utility struct for manipulating 2D axis aligned rectangles
 *of integers.
 */
typedef struct MOON_CSFML_API moon_IntRect {
	moon_Rect(int)
} moon_IntRect;

/**
 * Utility struct for manipulating 2D axis aligned rectangles
 *of floats.
 */
typedef struct MOON_CSFML_API moon_FloatRect {
	moon_Rect(float)
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
