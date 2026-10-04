#ifndef MOON_CSFML_EXTRAS_MOON_SLIDE_SHOW_H
#define MOON_CSFML_EXTRAS_MOON_SLIDE_SHOW_H


#include "../graphics/moon_sprite.h"

#include "../graphics/moon_render_states.h"

#include "../graphics/moon_render_window.h"


#ifdef __cplusplus
extern "C" {
#endif


struct MOON_CSFML_API moon_SlideShow;


/**
 * Structure for creating simple sprite animations.
 * Uses time instead of cpu-ticks.
 * In SFML there is another way to create animations,
 *but I am former SDL user.
 */
typedef struct moon_SlideShow moon_SlideShow;


/**
 * Creates new animation object.
 * 'width' and 'height' determine the size
 *of sprites in animation.
 * 'fixed_w' and 'fixed_h' determine which size
 *will be same for all sprites.
 * If 'fixed_w' and 'fixed_h' are both non-zero,
 *they will be ignored.
 * If 'fixed_w' is not zero, 'height' can be set
 *to zero.
 * If 'fixed_h' is not zero, 'width' can be set
 *to zero.
 * 'secs_per_frame' -- animation speed, seconds per frame.
 *
 * To check whether creation was successful or not,
 *you should use 'moon_SlideShow_is_valid'.
 */
MOON_CSFML_API moon_SlideShow*
moon_SlideShow_create(
	unsigned long initial_size,
	float width, float height,
	int fixed_w, int fixed_h,
	float secs_per_frame
);

/**
 * Destroys the animation object.
 */
MOON_CSFML_API void
moon_SlideShow_destroy(moon_SlideShow* self);

/**
 * Draws current sprite to the window.
 * If there is no sprites in animation yet,
 *does nothing.
 */
MOON_CSFML_API void
moon_SlideShow_draw(
	const moon_SlideShow* self,
	moon_RenderWindow* wnd,
	const moon_RenderStates* states
);

/**
 * Returns 1 if creation was successful, 0 otherwise.
 */
MOON_CSFML_API int
moon_SlideShow_is_valid(const moon_SlideShow* self);

/**
 * Returns 1 if animation has no sprites.
 * Otherwise, returns 0.
 */
MOON_CSFML_API int
moon_SlideShow_is_empty(const moon_SlideShow* self);

/**
 * Returns 1 if current sprite is the first sprite.
 * Otherwise, returns 0.
 * If animation is empty, returns 0.
 */
MOON_CSFML_API int
moon_SlideShow_is_first(const moon_SlideShow* self);

/**
 * Returns 1 if current sprite is the last sprite.
 * Otherwise, returns 0.
 * If animation is empty, returns 0.
 */
MOON_CSFML_API int
moon_SlideShow_is_last(const moon_SlideShow* self);

/**
 * Returns 1 if animation is running.
 * Otherwise, returns 0.
 * If animation is empty, returns 0.
 */
MOON_CSFML_API int
moon_SlideShow_is_running(const moon_SlideShow* self);

/**
 * Returns size(capacity of internal array) of
 *the animation.
 */
MOON_CSFML_API unsigned long
moon_SlideShow_size(const moon_SlideShow* self);

/**
 * Returns length(number of sprites) of
 *the animation.
 */
MOON_CSFML_API unsigned long
moon_SlideShow_length(const moon_SlideShow* self);

/**
 * Increases capacity of internal array.
 * If 'new_cap' is greater than current size(capacity),
 *new storage is allocated. Otherwise, function does nothing.
 * Returns 1 if successful, 0 otherwise.
 */
MOON_CSFML_API int
moon_SlideShow_reserve(
	moon_SlideShow* self,
	unsigned long new_cap
);

/**
 * Updates current sprite for drawing.
 * Can be slow if you update transformations frequently.
 * Returns 1 if current sprite updated, 0 otherwise.
 * If there is no sprites in animation yet,
 *does nothing.
 * The position and rotations of the previous
 *sprite will carry over to the next sprite.
 */
MOON_CSFML_API int
moon_SlideShow_update(moon_SlideShow* self);

/**
 * Rotates the current animation sprite.
 * Does not change the position of it's center.
 * Returns 1 if successful, 0 otherwise.
 * Always returns 1 if internal array is not empty.
 */
MOON_CSFML_API int
moon_SlideShow_rotate(
	moon_SlideShow* self,
	moon_Angle angle
);

/**
 * Sets rotation of the current animation sprite.
 * Does not change the position of it's center.
 * Returns 1 if successful, 0 otherwise.
 * Always returns 1 if internal array is not empty.
 */
MOON_CSFML_API int
moon_SlideShow_set_rotation(
	moon_SlideShow* self,
	moon_Angle angle
);

/**
 * Sets the global color of all sprites in animation.
 *
 * This color is modulated (multiplied) with the sprite's
 *texture. It can be used to colorize the sprite, or change
 *its global opacity.
 * By default, the sprite's color is opaque white.
 *
 * Returns 1 if successful, 0 otherwise.
 * Always returns 1 if internal array is not empty.
 */
MOON_CSFML_API int
moon_SlideShow_set_color(
	moon_SlideShow* self,
	const moon_Color* color
);

/**
 * Moves current animation sprite.
 * Returns 1 if successful, 0 otherwise.
 * Always returns 1 if internal array is not empty.
 */
MOON_CSFML_API int
moon_SlideShow_move(
	moon_SlideShow* self,
	float dx, float dy
);

/**
 * Sets position of current animation sprite.
 * Returns 1 if successful, 0 otherwise.
 * Always returns 1 if internal array is not empty.
 */
MOON_CSFML_API int
moon_SlideShow_set_position(
	moon_SlideShow* self,
	float left, float top
);

/**
 * Resizes all sprites in animation.
 * The proportions remain the same.
 * If there is no sprites, returns 0. Otherwise, returns 1.
 */
MOON_CSFML_API int
moon_SlideShow_resize(
	moon_SlideShow* self,
	float width, float height
);

/**
 * Reverses the order of slides in an animation.
 */
MOON_CSFML_API void
moon_SlideShow_reverse(moon_SlideShow* self);

/**
 * Removes all sprites from animation.
 */
MOON_CSFML_API void
moon_SlideShow_clear(moon_SlideShow* self);

/**
 * Flips all animation sprites.
 * Does not change the 'origin' of sprites.
 * If 'flip_x' and 'flip_y' are 0, does nothing.
 */
MOON_CSFML_API void
moon_SlideShow_flip(
	moon_SlideShow* self,
	int flip_x, int flip_y
);

/**
 * Creates and adds new sprite to the end
 *of animation array.
 */
MOON_CSFML_API void
moon_SlideShow_push_back(
	moon_SlideShow* self,
	const moon_Texture* texture
);

/**
 * Returns rotation of current sprite.
 * If animation has no sprites, returns 0.
 */
MOON_CSFML_API moon_Angle
moon_SlideShow_get_rotation(const moon_SlideShow* self);

/**
 * Returns size(depends on global bounds) of current sprite.
 * If animation has no sprites, returns {0, 0}.
 */
MOON_CSFML_API moon_Vector2f
moon_SlideShow_get_size(const moon_SlideShow* self);

/**
 * Returns position of current sprite.
 * If animation has no sprites, returns {0, 0}.
 */
MOON_CSFML_API moon_Vector2f
moon_SlideShow_get_position(const moon_SlideShow* self);

/**
 * Returns the local bounding rectangle of the
 *current animation sprite.
 * If there is no sprites, returns empty rectangle.
 *
 * The returned rectangle is in local coordinates, which means
 *that it ignores the transformations (translation, rotation,
 *scale, ...) that are applied to the entity.
 * In other words, this function returns the bounds of the
 *entity in the entity's coordinate system.
 */
MOON_CSFML_API moon_FloatRect
moon_SlideShow_get_local_bounds(const moon_SlideShow* self);

/**
 * Returns the global bounding rectangle of the
 *current animation sprite.
 * If there is no sprites, returns empty rectangle.
 *
 * The returned rectangle is in global coordinates, which means
 *that it takes into account the transformations (translation,
 *rotation, scale, ...) that are applied to the entity.
 * In other words, this function returns the bounds of the
 *sprite in the global 2D world's coordinate system.
 */
MOON_CSFML_API moon_FloatRect
moon_SlideShow_get_global_bounds(const moon_SlideShow* self);

/**
 * Returns world bounds of current animation sprite.
 * If there is no sprites, returns empty rectangle.
 *
 * What is world bounds?
 * It is position of the object and size of the object.
 * {left(x), top(y), width, height}
 * For some reason position from global bounds and
 *position from getPosition are different. This is why
 *this function exist.
 */
MOON_CSFML_API moon_FloatRect
moon_SlideShow_get_world_bounds(const moon_SlideShow* self);


#ifdef __cplusplus
}
#endif


#endif
