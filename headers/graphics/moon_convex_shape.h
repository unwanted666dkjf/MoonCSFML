#ifndef MOON_CSFML_GRAPHICS_MOON_CONVEX_SHAPE_H
#define MOON_CSFML_GRAPHICS_MOON_CONVEX_SHAPE_H


#include "./moon_rect.h"

#include "./moon_texture.h"

#include "./moon_transform.h"

#include "./moon_render_states.h"

#include "./moon_render_window.h"


#include "../system/moon_angle.h"

#include "../system/moon_vector2.h"


#ifdef __cplusplus
extern "C" {
#endif


#define moon_ConvexShape_DefaultPointCount (0)


struct MOON_CSFML_API moon_ConvexShape;


/**
 * Specialized shape representing a convex polygon.
 */
typedef struct moon_ConvexShape moon_ConvexShape;


/**
 * Creates default polygon.
 */
MOON_CSFML_API moon_ConvexShape*
moon_ConvexShape_default(unsigned long point_count);

/**
 * Creates polygon from given values.
 */
MOON_CSFML_API moon_ConvexShape*
moon_ConvexShape_create(
	unsigned long point_count,
	const moon_Color* fill_color
);

/**
 * Creates polygon from given values.
 */
MOON_CSFML_API moon_ConvexShape*
moon_ConvexShape_create_ex(
	unsigned long point_count,
	const moon_Color* fill_color,
	float left, float top
);

/**
 * Destroys polygon.
 */
MOON_CSFML_API void
moon_ConvexShape_destroy(moon_ConvexShape* self);

/**
 * Draws polygon to the RenderWindow.
 */
MOON_CSFML_API void
moon_ConvexShape_draw(
	const moon_ConvexShape* self,
	moon_RenderWindow* wnd,
	const moon_RenderStates* states
);

/**
 * Returns size of the object.
 * Size is defined by global bounds.
 */
MOON_CSFML_API moon_Vector2f
moon_ConvexShape_get_size(const moon_ConvexShape* self);

/**
 * Returns world bounds of the object.
 *
 * What is world bounds?
 * It is position of the object and size of the object.
 * {left(x), top(y), width, height}
 * For some reason position from global bounds and
 *position from getPosition are different. This is why
 *this function exist.
 */
MOON_CSFML_API moon_FloatRect
moon_ConvexShape_get_world_bounds(const moon_ConvexShape* self);

/**
 * Sets the number of points of the polygon.
 * \a count must be greater than 2 to define a valid shape.
 */
MOON_CSFML_API void
moon_ConvexShape_set_point_count(
	moon_ConvexShape* self,
	unsigned long count
);

/**
 * Sets the position of a point.
 *
 * Don't forget that the polygon must remain convex, and
 *the points need to stay ordered!
 *setPointCount must be called first in order to set the total
 *number of points. The result is undefined if \a index is out
 *of the valid range.
 */
MOON_CSFML_API void
moon_ConvexShape_set_point(
	moon_ConvexShape* self,
	unsigned long index,
	float x, float y
);


// Shape begin

/**
 * Changes the source texture of the shape.
 *
 * The \a texture argument refers to a texture that must
 *exist as long as the shape uses it. Indeed, the shape
 *doesn't store its own copy of the texture, but rather keeps
 *a pointer to the one that you passed to this function.
 * If the source texture is destroyed and the shape tries to
 *use it, the behavior is undefined.
 * \a texture can be NULL to disable texturing.
 * If \a reset_rect is 1, the TextureRect property of
 * the shape is automatically adjusted to the size of the new
 * texture. If it is 0, the texture rect is left unchanged.
 */
MOON_CSFML_API void
moon_ConvexShape_set_texture(
	moon_ConvexShape* self,
	const moon_Texture* texture,
	int reset_rect
);

/**
 * Set the sub-rectangle of the texture that the shape will display.
 *
 * The texture rect is useful when you don't want to display
 *the whole texture, but rather a part of it.
 * By default, the texture rect covers the entire texture.
 */
MOON_CSFML_API void
moon_ConvexShape_set_texture_rect(
	moon_ConvexShape* self,
	const moon_IntRect* rect
);

/**
 * Sets the fill color of the shape.
 * This color is modulated (multiplied) with the shape's
 *texture if any. It can be used to colorize the shape,
 *or change its global opacity.
 * By default, the shape's fill color is opaque white.
 */
MOON_CSFML_API void
moon_ConvexShape_set_fill_color(
	moon_ConvexShape* self,
	const moon_Color* color
);

/**
 * Sets the outline color of the shape.
 * By default, the shape's outline color is opaque white.
 */
MOON_CSFML_API void
moon_ConvexShape_set_outline_color(
	moon_ConvexShape* self,
	const moon_Color* color
);

/**
 * Set the thickness of the shape's outline.
 * Note that negative values are allowed (so that the outline
 *expands towards the center of the shape), and using zero
 *disables the outline.
 * By default, the outline thickness is 0.
 */
MOON_CSFML_API void
moon_ConvexShape_set_outline_thickness(
	moon_ConvexShape* self,
	float thickness
);

/**
 * Returns the source texture of the shape.
 * If the shape has no source texture, a NULL pointer is returned.
 * The returned pointer is const, which means that you can't
 *modify the texture when you retrieve it with this function.
 */
MOON_CSFML_API const moon_Texture*
moon_ConvexShape_get_texture(const moon_ConvexShape* self);

/**
 * Returns copy of the sub-rectangle of the texture displayed by the shape.
 */
MOON_CSFML_API moon_IntRect
moon_ConvexShape_get_texture_rect(const moon_ConvexShape* self);

/**
 * Returns copy of the fill color of the shape.
 */
MOON_CSFML_API moon_Color
moon_ConvexShape_get_fill_color(const moon_ConvexShape* self);

/**
 * Returns copy of the outline color of the shape.
 */
MOON_CSFML_API moon_Color
moon_ConvexShape_get_outline_color(const moon_ConvexShape* self);

/**
 * Returns the outline thickness of the shape.
 */
MOON_CSFML_API float
moon_ConvexShape_get_outline_thickness(const moon_ConvexShape* self);

/**
 * Returns the total number of points of the shape.
 */
MOON_CSFML_API unsigned long
moon_ConvexShape_get_point_count(const moon_ConvexShape* self);

/**
 * Returns a point of the shape.
 * The returned point is in local coordinates, that is,
 *the shape's transforms (position, rotation, scale) are
 *not taken into account.
 * The result is undefined if \a index is out of the valid range.
 */
MOON_CSFML_API moon_Vector2f
moon_ConvexShape_get_point(
	const moon_ConvexShape* self,
	unsigned long index
);

/**
 * Returns the local bounding rectangle of the entity.
 * The returned rectangle is in local coordinates, which means
 *that it ignores the transformations (translation, rotation,
 *scale, ...) that are applied to the entity.
 * In other words, this function returns the bounds of the
 *entity in the entity's coordinate system.
 */
MOON_CSFML_API moon_FloatRect
moon_ConvexShape_get_local_bounds(const moon_ConvexShape* self);

/**
 * Returns the global (non-minimal) bounding rectangle of the entity.
 *
 * The returned rectangle is in global coordinates, which means
 *that it takes into account the transformations (translation,
 *rotation, scale, ...) that are applied to the entity.
 * In other words, this function returns the bounds of the
 *shape in the global 2D world's coordinate system.
 *
 * This function does not necessarily return the \a minimal
 *bounding rectangle. It merely ensures that the returned
 *rectangle covers all the vertices (but possibly more).
 * This allows for a fast approximation of the bounds as a
 *first check; you may want to use more precise checks
 *on top of that.
 */
MOON_CSFML_API moon_FloatRect
moon_ConvexShape_get_global_bounds(const moon_ConvexShape* self);

// Shape end


// Transformable begin

/**
 * Sets the position of the object.
 *
 * This function completely overwrites the previous position.
 * See the move function to apply an offset based on the previous position instead.
 * The default position of a transformable object is (0, 0).
 */
MOON_CSFML_API void
moon_ConvexShape_set_position(
	moon_ConvexShape* self,
	float left, float top
);

/**
 * Sets the orientation of the object.
 * This function completely overwrites the previous rotation.
 * See the rotate function to add an angle based on the previous rotation instead.
 * The default rotation of a transformable object is 0.
 */
MOON_CSFML_API void
moon_ConvexShape_set_rotation(
	moon_ConvexShape* self,
	moon_Angle angle
);

/**
 * Sets the scale factors of the object.
 * This function completely overwrites the previous scale.
 * See the scale function to add a factor based on the previous scale instead.
 * The default scale of a transformable object is (1, 1).
 */
MOON_CSFML_API void
moon_ConvexShape_set_scale(
	moon_ConvexShape* self,
	float scale_x, float scale_y
);

/**
 * Sets the local origin of the object.
 * The origin of an object defines the center point for
 * all transformations (position, scale, rotation).
 * The coordinates of this point must be relative to the
 * top-left corner of the object, and ignore all
 * transformations (position, scale, rotation).
 * The default origin of a transformable object is (0, 0).
 */
MOON_CSFML_API void
moon_ConvexShape_set_origin(
	moon_ConvexShape* self,
	float x, float y
);

/**
 * Returns the position of the object.
 */
MOON_CSFML_API moon_Vector2f
moon_ConvexShape_get_position(const moon_ConvexShape* self);

/**
 * Returns the orientation of the object.
 *
 * The rotation is always in the range(degrees) [0, 360].
 */
MOON_CSFML_API moon_Angle
moon_ConvexShape_get_rotation(const moon_ConvexShape* self);

/**
 * Returns the current scale of the object.
 */
MOON_CSFML_API moon_Vector2f
moon_ConvexShape_get_scale(const moon_ConvexShape* self);

/**
 * Returns the local origin of the object.
 */
MOON_CSFML_API moon_Vector2f
moon_ConvexShape_get_origin(const moon_ConvexShape* self);

/**
 * Moves the object by a given offset.
 * This function adds to the current position of the object,
 *unlike setPosition which overwrites it.
 * Thus, it is equivalent to the following code(SFML example):
 * \code
 * sf::Vector2f pos = object.getPosition();
 * object.setPosition(pos.x + offsetX, pos.y + offsetY);
 * \endcode
 */
MOON_CSFML_API void
moon_ConvexShape_move(
	moon_ConvexShape* self,
	float dx, float dy
);

/**
 * Rotates the object.
 * This function adds to the current rotation of the object,
 *unlike setRotation which overwrites it.
 * Thus, it is equivalent to the following code(SFML example):
 * \code
 * object.setRotation(object.getRotation() + angle);
 * \endcode
 */
MOON_CSFML_API void
moon_ConvexShape_rotate(
	moon_ConvexShape* self,
	moon_Angle angle
);

/**
 * Scales the object.
 * This function multiplies the current scale of the object,
 *unlike setScale which overwrites it.
 * Thus, it is equivalent to the following code(SFML example):
 * \code
 * sf::Vector2f scale = object.getScale();
 * object.setScale(scale.x * factorX, scale.y * factorY);
 * \endcode
 */
MOON_CSFML_API void
moon_ConvexShape_scale(
	moon_ConvexShape* self,
	float scale_x, float scale_y
);

/**
 * Returns transform combining the position/rotation/scale/origin of the object.
 * This operation is slow, because it copies SFML transform to C
 *compatible transform.
 */
MOON_CSFML_API moon_Transform
moon_ConvexShape_get_transform(const moon_ConvexShape* self);

/**
 * Returns inverse of the combined transformations applied to the object.
 * This operation is slow, because it copies SFML transform to C
 *compatible transform.
 */
MOON_CSFML_API moon_Transform
moon_ConvexShape_get_inverse_transform(const moon_ConvexShape* self);

/**
 * Returns 1 if internal transform is updated, 0 otherwise.
 * Use it if you want to cache C transform or/and C inversed
 *transform.
 */
MOON_CSFML_API int
moon_ConvexShape_is_transform_updated(const moon_ConvexShape* self);

/**
 * Returns 1 if internal inversed transform is updated, 0 otherwise.
 * Use it if you want to cache C inversed transform.
 */
MOON_CSFML_API int
moon_ConvexShape_is_inversed_transform_updated(const moon_ConvexShape* self);

// Transformable end


#ifdef __cplusplus
}
#endif


#endif
