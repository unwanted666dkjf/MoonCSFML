#ifndef MOON_CSFML_EXTRAS_MOON_FRECT_UTILS_H
#define MOON_CSFML_EXTRAS_MOON_FRECT_UTILS_H


#include "../graphics/moon_rect.h"


#include "../system/moon_vector2.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Returns position of left-top corner as 2D
 *vector.
 */
MOON_CSFML_API moon_Vector2f
moon_FRectUtils_get_lefttop(const moon_FloatRect* rect);

/**
 * Returns position of left-bottom corner as 2D
 *vector.
 */
MOON_CSFML_API moon_Vector2f
moon_FRectUtils_get_leftbottom(const moon_FloatRect* rect);

/**
 * Returns position of right-top corner as 2D
 *vector.
 */
MOON_CSFML_API moon_Vector2f
moon_FRectUtils_get_righttop(const moon_FloatRect* rect);

/**
 * Returns position of right-bottom corner as 2D
 *vector.
 */
MOON_CSFML_API moon_Vector2f
moon_FRectUtils_get_rightbottom(const moon_FloatRect* rect);

/**
 * Returns position of center as 2D
 *vector.
 */
MOON_CSFML_API moon_Vector2f
moon_FRectUtils_get_center(const moon_FloatRect* rect);


#ifdef __cplusplus
}
#endif


#endif
