#ifndef MOON_CSFML_EXTRAS_MOON_VEC2UTILS_H
#define MOON_CSFML_EXTRAS_MOON_VEC2UTILS_H


#include "../system/moon_vector2.h"


#ifdef __cplusplus
extern "C" {
#endif


#include <math.h>


/**
 * Returns length(module) of 2D vector.
 */
#define moon_Vec2utils_length(vec2_v)	\
	(hypotf(vec2_v.x, vec2_v.y))

/**
 * Performs a simple multiplication of a 2D vector by a number.
 */
#define moon_Vec2utils_num_multiply(	\
	ResTypeV2,							\
	num,								\
	vec2_v								\
)	\
	(ResTypeV2){(num) * vec2_v.x, (num) * vec2_v.y}

/**
 * Simple sum of 2D vectors.
 */
#define moon_Vec2utils_sum(	\
	ResTypeV2,				\
	vec2_v1,				\
	vec2_v2					\
)	\
	(ResTypeV2){vec2_v1.x + vec2_v2.x, vec2_v1.y + vec2_v2.y}

/**
 * Simple subtraction of 2D vectors.
 */
#define moon_Vec2utils_sub(	\
	ResTypeV2,				\
	vec2_v1,				\
	vec2_v2					\
)	\
	(ResTypeV2){vec2_v1.x - vec2_v2.x, vec2_v1.y - vec2_v2.y}

/**
 * Computes the dot product of 2D vectors.
 */
#define moon_Vec2utils_dot_product(	\
	vec2_v1,						\
	vec2_v2							\
)	\
	(vec2_v1.x * vec2_v2.x + vec2_v1.y * vec2_v2.y)

/**
 * Returns the z coordinate of the cross product
 *of two 2D vectors.
 * For 2D vectors in vector product, the
 *result coordinates x and y are zero.
 */
#define moon_Vec2utils_cross_product(	\
	vec2_v1,							\
	vec2_v2								\
)	\
	(vec2_v1.x * vec2_v2.y - vec2_v1.y * vec2_v2.x)

/**
 * Performs vector reflection from the surface.
 * The result will be written in 'moon_Vector2f_res'.
 * 'vec2_normal'	-- normal of the surface from which the vector is reflected.
 * 'vec2_velocity' 	-- vector to be reflected.
 */
#define moon_Vec2utils_Procedure_reflection(	\
	moon_Vector2f_res,							\
	vec2_normal,								\
	vec2_velocity								\
)	\
{	\
	moon_Vector2f* res_Procedure__ = &(moon_Vector2f_res);							\
	float dot_Procedure__ = (float)(												\
		moon_Vec2utils_dot_product(													\
			vec2_velocity, vec2_normal												\
		)																			\
	);																				\
	res_Procedure__->x = vec2_velocity.x - 2.f * dot_Procedure__ * vec2_normal.x;	\
	res_Procedure__->y = vec2_velocity.y - 2.f * dot_Procedure__ * vec2_normal.y;	\
}

/**
 * Normalizes the vector.
 * Result will be written in 'moon_Vector2f_res'.
 * If the vector is of zero length, the result is a null vector.
 */
#define moon_Vec2utils_Procedure_normalization(	\
	moon_Vector2f_res,							\
	vec2_v										\
)	\
{	\
	moon_Vector2f* res_Procedure__ = &(moon_Vector2f_res);				\
	float length_Procedure__ = (float)(moon_Vec2utils_length(vec2_v));	\
	if (length_Procedure__ == 0.f) {									\
		res_Procedure__->x = 0.f;										\
		res_Procedure__->y = 0.f;										\
	} else {															\
		res_Procedure__->x = vec2_v.x / length_Procedure__;				\
		res_Procedure__->y = vec2_v.y / length_Procedure__;				\
	}																	\
}


#ifdef __cplusplus
}
#endif


#endif
