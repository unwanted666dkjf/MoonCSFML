#ifndef MOON_CSFML_EXTRAS_MOON_SPRITE_TRANSFORM_H
#define MOON_CSFML_EXTRAS_MOON_SPRITE_TRANSFORM_H


#include "../graphics/moon_sprite.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Flips the sprite about the oX and oY axes, keeping it in its current position.
 * Does not change the 'origin' of the sprite.
 * If 'flip_x' and 'flip_y' are 0, does nothing.
 */
MOON_CSFML_API void
moon_SpriteTransform_flip(
	moon_Sprite* sprite,
	int flip_x, int flip_y
);

/**
 * Scales the sprite to fit the size.
 * Works only if sprite has texture.
 * Returns new size(in global coordinates) of the sprite.
 * The perculiarity is that the function
 *can recalculate the size if 'keep_w' or
 *'keep_h' are specified to preserve the
 *proportions of the object.
 * If 'keep_w' is not 0, it will preserve the width-to-height ratio.
 * If 'keep_h' is not 0, it will preserve the height-to-width ratio.
 * If 'keep_w' and 'keep_h' are not 0, both will be ignored.
 * If 'keep_w' and 'keep_h' are 0, both will be ignored.
 * Morever, 'width' can be set to zero if 'keep_h' is
 *equal to 1. The same is true for 'height'.
 */
MOON_CSFML_API moon_Vector2f
moon_SpriteTransform_scale(
	moon_Sprite* sprite,
	float width, float height,
	int keep_w,  int keep_h
);

/**
 * Rotates the sprite without changing the position of it's center.
 * Useful when you don't want to set 'origin'.
 * Returns new rotation angle of the sprite.
 */
MOON_CSFML_API moon_Angle
moon_SpriteTransform_rotate(
	moon_Sprite* sprite,
	moon_Angle angle
);

/**
 * Sets the rotation angle of the sprite without
 *changing the position of it's center.
 * Useful when you don't want to set 'origin'.
 */
MOON_CSFML_API void
moon_SpriteTransform_set_rotation(
	moon_Sprite* sprite,
	moon_Angle angle
);

/**
 * Sets the position of the sprite by moving
 *it by difference between the position of
 *global(global bounds) coordinates and the
 *passed parameters 'left' and 'top'.
 */
MOON_CSFML_API void
moon_SpriteTransform_set_movepos(
	moon_Sprite* sprite,
	float left, float top
);

/**
 * Copies transformations of 'source' to a 'target'.
 * Transformations: position, rotation, scale and origin.
 */
MOON_CSFML_API void
moon_SpriteTransform_copy_transform(
	moon_Sprite* target,
	const moon_Sprite* source
);

/**
 * Changes the rotation angle and position of 'target'
 *sprite, so that it's position relative to other objects
 *is similar to that of the 'source' sprite.
 */
MOON_CSFML_API void
moon_SpriteTransform_apply_orient(
	moon_Sprite* target,
	const moon_Sprite* source
);


#ifdef __cplusplus
}
#endif


#endif
