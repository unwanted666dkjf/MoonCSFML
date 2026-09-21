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
 * Rotates the sprite without changing the position of it's center.
 * Useful when you don't want to set 'origin'.
 */
MOON_CSFML_API void
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
 * Copies transformations of 'source' to a 'target'.
 * Transformations: position, rotation, scale and origin.
 */
MOON_CSFML_API void
moon_SpriteTransform_copy_transform(
	moon_Sprite* target,
	const moon_Sprite* source
);


#ifdef __cplusplus
}
#endif


#endif
