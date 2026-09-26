#ifndef MOON_CSFML_EXTRAS_MOON_SLIDE_ANIMATION_H
#define MOON_CSFML_EXTRAS_MOON_SLIDE_ANIMATION_H


#include "../graphics/moon_sprite.h"

#include "../graphics/moon_render_states.h"

#include "../graphics/moon_render_window.h"


#ifdef __cplusplus
extern "C" {
#endif


struct MOON_CSFML_API moon_SlideAnimation;


typedef struct moon_SlideAnimation moon_SlideAnimation;


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
 * 'anim_speed' -- animation speed.
 */
MOON_CSFML_API moon_SlideAnimation*
moon_SlideAnimation_create(
	unsigned long initial_size,
	float width, float height,
	int fixed_w, int fixed_h,
	float anim_speed
);

/**
 * Destroys the animation object.
 */
MOON_CSFML_API void
moon_SlideAnimation_destroy(moon_SlideAnimation* self);

/**
 * Draws current sprite to the window.
 * If there is no sprites in animation yet,
 *does nothing.
 */
MOON_CSFML_API void
moon_SlideAnimation_draw(
	const moon_SlideAnimation* self,
	moon_RenderWindow* wnd,
	const moon_RenderStates* states
);

/**
 * Returns 1 if animation has no sprites.
 * Otherwise, returns 0.
 */
MOON_CSFML_API int
moon_SlideAnimation_is_empty(const moon_SlideAnimation* self);

/**
 * Returns 1 if current sprite is the first sprite.
 * Otherwise, returns 0.
 * If animation is empty, returns 0.
 */
MOON_CSFML_API int
moon_SlideAnimation_is_first(const moon_SlideAnimation* self);

/**
 * Returns 1 if current sprite is the last sprite.
 * Otherwise, returns 0.
 * If animation is empty, returns 0.
 */
MOON_CSFML_API int
moon_SlideAnimation_is_last(const moon_SlideAnimation* self);

/**
 * Returns 1 if animation is running.
 * Otherwise, returns 0.
 * If animation is empty, returns 0.
 */
MOON_CSFML_API int
moon_SlideAnimation_is_running(const moon_SlideAnimation* self);

/**
 * Returns size(capacity of internal array) of
 *the animation.
 */
MOON_CSFML_API unsigned long
moon_SlideAnimation_size(const moon_SlideAnimation* self);

/**
 * Returns length(number of sprites) of
 *the animation.
 */
MOON_CSFML_API unsigned long
moon_SlideAnimation_length(const moon_SlideAnimation* self);

/**
 * Increases capacity of internal array.
 * If 'new_cap' is greater than current size(capacity),
 *new storage is allocated. Otherwise, function does nothing.
 * Returns 1 if successful, 0 otherwise.
 */
MOON_CSFML_API int
moon_SlideAnimation_reserve(
	moon_SlideAnimation* self,
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
moon_SlideAnimation_update(moon_SlideAnimation* self);

/**
 * Rotates the current animation sprite.
 * Does not change the position of it's center.
 * Returns 1 if successful, 0 otherwise.
 * Always returns 1 if internal array is not empty.
 */
MOON_CSFML_API int
moon_SlideAnimation_rotate(
	moon_SlideAnimation* self,
	moon_Angle angle
);

/**
 * Sets rotation of the current animation sprite.
 * Does not change the position of it's center.
 * Returns 1 if successful, 0 otherwise.
 * Always returns 1 if internal array is not empty.
 */
MOON_CSFML_API int
moon_SlideAnimation_set_rotation(
	moon_SlideAnimation* self,
	moon_Angle angle
);

/**
 * Moves current animation sprite.
 * Returns 1 if successful, 0 otherwise.
 * Always returns 1 if internal array is not empty.
 */
MOON_CSFML_API int
moon_SlideAnimation_move(
	moon_SlideAnimation* self,
	float dx, float dy
);

/**
 * Sets position of current animation sprite.
 * Returns 1 if successful, 0 otherwise.
 * Always returns 1 if internal array is not empty.
 */
MOON_CSFML_API int
moon_SlideAnimation_set_position(
	moon_SlideAnimation* self,
	float left, float top
);

/**
 * Resizes all sprites in animation.
 * The proportions remain the same.
 * If there is no sprites, returns 0. Otherwise, returns 1.
 */
MOON_CSFML_API int
moon_SlideAnimation_resize(
	moon_SlideAnimation* self,
	float width, float height
);

/**
 * Reverses the order of slides in an animation.
 */
MOON_CSFML_API void
moon_SlideAnimation_reverse(moon_SlideAnimation* self);

/**
 * Removes all sprites from animation.
 */
MOON_CSFML_API void
moon_SlideAnimation_clear(moon_SlideAnimation* self);

/**
 * Flips all animation sprites.
 * Does not change the 'origin' of sprites.
 * If 'flip_x' and 'flip_y' are 0, does nothing.
 */
MOON_CSFML_API void
moon_SlideAnimation_flip(
	moon_SlideAnimation* self,
	int flip_x, int flip_y
);

/**
 * Creates and adds new sprite to the end
 *of animation array.
 */
MOON_CSFML_API void
moon_SlideAnimation_push_back(
	moon_SlideAnimation* self,
	const moon_Texture* texture
);

/**
 * Returns rotation of current sprite.
 * If animation has no sprites, returns 0.
 */
MOON_CSFML_API moon_Angle
moon_SlideAnimation_get_rotation(const moon_SlideAnimation* self);

/**
 * Returns size(depends on global bounds) of current sprite.
 * If animation has no sprites, returns {0, 0}.
 */
MOON_CSFML_API moon_Vector2f
moon_SlideAnimation_get_size(const moon_SlideAnimation* self);

/**
 * Returns position of current sprite.
 * If animation has no sprites, returns {0, 0}.
 */
MOON_CSFML_API moon_Vector2f
moon_SlideAnimation_get_position(const moon_SlideAnimation* self);

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
moon_SlideAnimation_get_local_bounds(const moon_SlideAnimation* self);

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
moon_SlideAnimation_get_global_bounds(const moon_SlideAnimation* self);

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
moon_SlideAnimation_get_world_bounds(const moon_SlideAnimation* self);


#ifdef __cplusplus
}
#endif


#endif
