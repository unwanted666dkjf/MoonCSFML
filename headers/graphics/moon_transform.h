#ifndef MOON_CSFML_GRAPHICS_MOON_TRANSFORM_H
#define MOON_CSFML_GRAPHICS_MOON_TRANSFORM_H


#include "./moon_rect.h"


#include "../system/moon_angle.h"

#include "../system/moon_vector2.h"


#ifdef __cplusplus
extern "C" {
#endif


#define moon_Transform_MatrixSize (16)


/**
 * Defines a 3x3 transform matrix.
 */
typedef struct MOON_CSFML_API moon_Transform {
	float matrix[moon_Transform_MatrixSize];
} moon_Transform;


/**
 * Creates an identity transform (a transform that does nothing).
 */
MOON_CSFML_API moon_Transform
moon_Transform_create();

/**
 * Creates a transform from a 3x3 matrix.
 */
MOON_CSFML_API moon_Transform
moon_Transform_create_ex(
	float a00, float a01, float a02,
	float a10, float a11, float a12,
	float a20, float a21, float a22
);

/**
 * Returns copy of this transform.
 */
MOON_CSFML_API moon_Transform
moon_Transform_get_copy(const moon_Transform* self);

/**
 * Returns the transform as a 4x4 matrix.
 * Internal matrix as a constant.
 * This function returns a pointer to an array of 16 floats
 *containing the transform elements as a 4x4 matrix, which
 *is directly compatible with OpenGL functions.
 */
MOON_CSFML_API const float*
moon_Transform_get_matrix(const moon_Transform* self);

/**
 * Returns the inverse of the transform.
 * If the inverse cannot be computed, an identity transform
 *is returned.
 */
MOON_CSFML_API moon_Transform
moon_Transform_get_inverse(const moon_Transform* self);

/**
 * Transforms a 2D point.
 * Returns transformed point.
 */
MOON_CSFML_API moon_Vector2f
moon_Transform_transform_point(
	const moon_Transform* self,
	float x, float y
);

/**
 * Transforms a rectangle.
 * Since SFML doesn't provide support for oriented rectangles,
 *the result o*f this function is always an axis-aligned
 *rectangle. Which means that if the transform contains a
 *rotation, the bounding rectangle of the transformed rectangle
 *is returned.
 * Returns transformed rectangle.
 */
MOON_CSFML_API moon_FloatRect
moon_Transform_transform_rectangle(
	const moon_Transform* self,
	const moon_FloatRect* rectangle
);

/**
 * Combines the current transform with another one.
 * Mathematically, it is equivalent to a matrix
 *multiplication 'self' * 'other'.
 * Returns new transform as a result.
 */
MOON_CSFML_API moon_Transform
moon_Transform_combine(
	const moon_Transform* self,
	const moon_Transform* other
);

/**
 * Combines the current transform with a translation.
 * Returns new transform as a result.
 */
MOON_CSFML_API moon_Transform
moon_Transform_translate(
	const moon_Transform* self,
	float x, float y
);

/**
 * Combines the current transform with a rotation.
 * Returns new transform as a result.
 */
MOON_CSFML_API moon_Transform
moon_Transform_rotate(
	const moon_Transform* self,
	moon_Angle angle
);

/**
 * Combine the current transform with a rotation.
 * The center of rotation is provided for convenience as a second
 *argument, so that you can build rotations around arbitrary points
 *more easily (and efficiently) than the usual
 *translate(-center).rotate(angle).translate(center).
 * Returns new transform as a result.
 */
MOON_CSFML_API moon_Transform
moon_Transform_rotate_ex(
	const moon_Transform* self,
	moon_Angle angle,
	float cx, float cy
);

/**
 * Combines the current transform with a scaling.
 * Returns new transform as a result.
 */
MOON_CSFML_API moon_Transform
moon_Transform_scale(
	const moon_Transform* self,
	float scale_x, float scale_y
);

/**
 * Combines the current transform with a scaling.
 * The center of scaling is provided for convenience as a second
 *argument, so that you can build scaling around arbitrary points
 *more easily (and efficiently) than the usual
 *translate(-center).scale(factors).translate(center).
 * Returns new transform as a result.
 */
MOON_CSFML_API moon_Transform
moon_Transform_scale_ex(
	const moon_Transform* self,
	float scale_x, float scale_y,
	float cx, float cy
);

/**
 * Returns 1 if transforms are equal, 0 otherwise.
 * Transforms are equal if their matrices are equal.
 * Matrices are equal if they have same numbers.
 */
MOON_CSFML_API int
moon_Transform_is_eq(
	const moon_Transform* self,
	const moon_Transform* other
);

/**
 * Returns 1 if transforms are not equal, 0 otherwise.
 * Transforms are equal if their matrices are equal.
 * Matrices are equal if they have same numbers.
 */
MOON_CSFML_API int
moon_Transform_is_ne(
	const moon_Transform* self,
	const moon_Transform* other
);


#ifdef __cplusplus
}
#endif


#endif
