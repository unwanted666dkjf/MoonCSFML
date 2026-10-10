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
 * Returns the Euclidean distance between 2D vectors.
 */
MOON_CSFML_API float
moon_Vec2f_utils_distance_to(
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
 * Returns copy of the vector.
 */
MOON_CSFML_API moon_Vector2f
moon_Vec2f_utils_copy(const moon_Vector2f* self);

/**
 * Returns a representation of a vector in polar coordinates.
 * For 2D vector: {length, theta}.
 * Note: 'theta' -- angle in radians.
 */
MOON_CSFML_API moon_Vector2f
moon_Vec2f_utils_as_polar(const moon_Vector2f* self);

/**
 * Creates a vector in Euclidean coordinates
 *from polar coordinates.
 */
MOON_CSFML_API moon_Vector2f
moon_Vec2f_utils_from_polar(
	float length,
	float angle_in_radians
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
 * Returns the projection of the vector 'self' onto the vector 'other'.
 * If the 'other' vector is zero, then the
 *result will be the zero vector.
 */
MOON_CSFML_API moon_Vector2f
moon_Vec2f_utils_project(
	const moon_Vector2f* self,
	const moon_Vector2f* other
);

/**
 * Returns the distance between vector 1 and vector 2 on the x and y axes.
 */
MOON_CSFML_API moon_Vector2f
moon_Vec2f_utils_distance(
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

/**
 * Returns the linear interpolation of 'self' to 'other'.
 * t is a parameter in range: [0 ; 1]
 */
MOON_CSFML_API moon_Vector2f
moon_Vec2f_utils_lerp(
	const moon_Vector2f* self,
	const moon_Vector2f* other,
	float t
);

/**
 * Returns the spherical interpolation of the first vector to the second.
 * t is a parameter in range: [0 ; 1].
 * Vectors must not be null.
 */
MOON_CSFML_API moon_Vector2f
moon_Vec2f_utils_slerp(
	const moon_Vector2f* self,
	const moon_Vector2f* other,
	float t
);


#ifdef __cplusplus
}
#endif


#endif
