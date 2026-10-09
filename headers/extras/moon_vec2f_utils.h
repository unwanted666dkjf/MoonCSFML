#ifndef MOON_CSFML_EXTRAS_MOON_VEC2F_UTILS_H
#define MOON_CSFML_EXTRAS_MOON_VEC2F_UTILS_H


#include "../system/moon_angle.h"

#include "../system/moon_vector2.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Returns length(module) of the vector.
 */
MOON_CSFML_API float
moon_Vec2f_utils_length(const moon_Vector2f* self);

/**
 * Computes the dot product of 2D vectors.
 */
MOON_CSFML_API float
moon_Vec2f_utils_dot_product(
	const moon_Vector2f* self,
	const moon_Vector2f* other
);

/**
 * Returns the z coordinate of the cross product
 *of two 2D vectors.
 * For 2D vectors in vector product, the
 *result coordinates x and y are zero.
 */
MOON_CSFML_API float
moon_Vec2f_utils_cross_product(
	const moon_Vector2f* self,
	const moon_Vector2f* other
);

/**
 * Returns the angle between vectors.
 * If at least one of the vectors is zero, it will return zero.
 */
MOON_CSFML_API moon_Angle
moon_Vec2f_utils_angle(
	const moon_Vector2f* self,
	const moon_Vector2f* other
);

/**
 * Returns normalized vector for 'self'.
 * If the vector is of zero length, the result is a null vector.
 */
MOON_CSFML_API moon_Vector2f
moon_Vec2f_utils_normalization(const moon_Vector2f* self);

/**
 * Performs a simple multiplication of a 2D vector by a number.
 */
MOON_CSFML_API moon_Vector2f
moon_Vec2f_utils_num_multiply(
	const moon_Vector2f* self,
	float num
);

/**
 * Simple sum of 2D vectors.
 */
MOON_CSFML_API moon_Vector2f
moon_Vec2f_utils_sum(
	const moon_Vector2f* self,
	const moon_Vector2f* other
);

/**
 * Simple subtraction of 2D vectors.
 */
MOON_CSFML_API moon_Vector2f
moon_Vec2f_utils_sub(
	const moon_Vector2f* self,
	const moon_Vector2f* other
);

/**
 * Returns the result of a vector reflection from a surface.
 * 'normal' -- normal of the surface from which the vector is reflected.
 */
MOON_CSFML_API moon_Vector2f
moon_Vec2f_utils_reflection(
	const moon_Vector2f* self,
	const moon_Vector2f* normal
);


#ifdef __cplusplus
}
#endif


#endif
