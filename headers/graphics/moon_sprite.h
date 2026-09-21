#ifndef MOON_CSFML_GRAPHICS_MOON_SPRITE_H
#define MOON_CSFML_GRAPHICS_MOON_SPRITE_H


#include "./moon_rect.h"

#include "./moon_color.h"

#include "./moon_texture.h"

#include "./moon_transform.h"

#include "./moon_render_states.h"

#include "./moon_render_window.h"


#include "../system/moon_angle.h"

#include "../system/moon_vector2.h"


#ifdef __cplusplus
extern "C" {
#endif


struct MOON_CSFML_API moon_Sprite;


/**
 * Drawable representation of a texture, with its
 *own transformations, color, etc.
 */
typedef struct moon_Sprite moon_Sprite;


/**
 * Creates the sprite from a source texture.
 */
MOON_CSFML_API moon_Sprite*
moon_Sprite_create(const moon_Texture* texture);

/**
 * Creates the sprite from a sub-rectangle of a source texture.
 */
MOON_CSFML_API moon_Sprite*
moon_Sprite_create_ex(
	const moon_Texture* texture,
	const moon_IntRect* area
);

/**
 * Destroys the sprite.
 */
MOON_CSFML_API void
moon_Sprite_destroy(moon_Sprite* self);

/**
 * Draws a sprite to the render window.
 */
MOON_CSFML_API void
moon_Sprite_draw(
	const moon_Sprite* self,
	moon_RenderWindow* wnd,
	const moon_RenderStates* states
);

/**
 * Returns size of the object.
 * Size is defined by global bounds.
 */
MOON_CSFML_API moon_Vector2f
moon_Sprite_get_size(const moon_Sprite* self);

/**
 * Change the source texture of the sprite.
 *
 * The \a texture argument refers to a texture that must
 *exist as long as the sprite uses it. Indeed, the sprite
 *doesn't store its own copy of the texture, but rather keeps
 *a pointer to the one that you passed to this function.
 * If the source texture is destroyed and the sprite tries to
 *use it, the behavior is undefined.
 * If \a reset_rect is 1, the TextureRect property of
 *the sprite is automatically adjusted to the size of the new
 *texture. If it is 0, the texture rect is left unchanged.
 */
MOON_CSFML_API void
moon_Sprite_set_texture(
	moon_Sprite* self,
	const moon_Texture* texture,
	int reset_rect
);

/**
 * Set the sub-rectangle of the texture that the sprite will display.
 * The texture rect is useful when you don't want to display
 *the whole texture, but rather a part of it.
 * By default, the texture rect covers the entire texture.
 */
MOON_CSFML_API void
moon_Sprite_set_texture_rect(
	moon_Sprite* self,
	const moon_IntRect* rect
);

/**
 * Sets the global color of the sprite.
 *
 * This color is modulated (multiplied) with the sprite's
 *texture. It can be used to colorize the sprite, or change
 *its global opacity.
 * By default, the sprite's color is opaque white.
 */
MOON_CSFML_API void
moon_Sprite_set_color(
	moon_Sprite* self,
	const moon_Color* color
);

/**
 * Returns the source texture of the sprite.
 *
 * If the sprite has no source texture, a NULL pointer is returned.
 * The returned pointer is const, which means that you can't
 *modify the texture when you retrieve it with this function.
 */
MOON_CSFML_API const moon_Texture*
moon_Sprite_get_texture(const moon_Sprite* self);

/**
 * Returns copy of the sub-rectangle of the texture displayed by the sprite.
 */
MOON_CSFML_API moon_IntRect
moon_Sprite_get_texture_rect(const moon_Sprite* self);

/**
 * Returns copy of the global color of the sprite.
 */
MOON_CSFML_API moon_Color
moon_Sprite_get_color(const moon_Sprite* self);

/**
 * Returns the local bounding rectangle of the entity.
 *
 * The returned rectangle is in local coordinates, which means
 *that it ignores the transformations (translation, rotation,
 *scale, ...) that are applied to the entity.
 * In other words, this function returns the bounds of the
 *entity in the entity's coordinate system.
 */
MOON_CSFML_API moon_FloatRect
moon_Sprite_get_local_bounds(const moon_Sprite* self);

/**
 * Returns the global bounding rectangle of the entity.
 *
 * The returned rectangle is in global coordinates, which means
 *that it takes into account the transformations (translation,
 *rotation, scale, ...) that are applied to the entity.
 * In other words, this function returns the bounds of the
 *sprite in the global 2D world's coordinate system.
 */
MOON_CSFML_API moon_FloatRect
moon_Sprite_get_global_bounds(const moon_Sprite* self);


// Transformable begin

/**
 * Sets the position of the object.
 *
 * This function completely overwrites the previous position.
 * See the move function to apply an offset based on the previous position instead.
 * The default position of a transformable object is (0, 0).
 */
MOON_CSFML_API void
moon_Sprite_set_position(
	moon_Sprite* self,
	float left, float top
);

/**
 * Sets the orientation of the object.
 * This function completely overwrites the previous rotation.
 * See the rotate function to add an angle based on the previous rotation instead.
 * The default rotation of a transformable object is 0.
 */
MOON_CSFML_API void
moon_Sprite_set_rotation(
	moon_Sprite* self,
	moon_Angle angle
);

/**
 * Sets the scale factors of the object.
 * This function completely overwrites the previous scale.
 * See the scale function to add a factor based on the previous scale instead.
 * The default scale of a transformable object is (1, 1).
 */
MOON_CSFML_API void
moon_Sprite_set_scale(
	moon_Sprite* self,
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
moon_Sprite_set_origin(
	moon_Sprite* self,
	float x, float y
);

/**
 * Returns the position of the object.
 */
MOON_CSFML_API moon_Vector2f
moon_Sprite_get_position(const moon_Sprite* self);

/**
 * Returns the orientation of the object.
 *
 * The rotation is always in the range(degrees) [0, 360].
 */
MOON_CSFML_API moon_Angle
moon_Sprite_get_rotation(const moon_Sprite* self);

/**
 * Returns the current scale of the object.
 */
MOON_CSFML_API moon_Vector2f
moon_Sprite_get_scale(const moon_Sprite* self);

/**
 * Returns the local origin of the object.
 */
MOON_CSFML_API moon_Vector2f
moon_Sprite_get_origin(const moon_Sprite* self);

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
moon_Sprite_move(
	moon_Sprite* self,
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
moon_Sprite_rotate(
	moon_Sprite* self,
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
moon_Sprite_scale(
	moon_Sprite* self,
	float scale_x, float scale_y
);

/**
 * Returns transform combining the position/rotation/scale/origin of the object.
 * This operation is slow, because it copies SFML transform to C
 *compatible transform.
 */
MOON_CSFML_API moon_Transform
moon_Sprite_get_transform(const moon_Sprite* self);

/**
 * Returns inverse of the combined transformations applied to the object.
 * This operation is slow, because it copies SFML transform to C
 *compatible transform.
 */
MOON_CSFML_API moon_Transform
moon_Sprite_get_inverse_transform(const moon_Sprite* self);

/**
 * Returns 1 if internal transform is updated, 0 otherwise.
 * Use it if you want to cache C transform or/and C inversed
 *transform.
 */
MOON_CSFML_API int
moon_Sprite_is_transform_updated(const moon_Sprite* self);

/**
 * Returns 1 if internal inversed transform is updated, 0 otherwise.
 * Use it if you want to cache C inversed transform.
 */
MOON_CSFML_API int
moon_Sprite_is_inversed_transform_updated(const moon_Sprite* self);

// Transformable end


#ifdef __cplusplus
}
#endif


#endif
