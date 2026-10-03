#ifndef MOON_CSFML_EXTRAS_MOON_SPRITE_GROUP_H
#define MOON_CSFML_EXTRAS_MOON_SPRITE_GROUP_H


#include "../graphics/moon_sprite.h"

#include "../graphics/moon_render_states.h"

#include "../graphics/moon_render_window.h"


#ifdef __cplusplus
extern "C" {
#endif


struct MOON_CSFML_API moon_SpriteGroup;


/**
 * Special struct for manipulating a group of sprites.
 */
typedef struct moon_SpriteGroup moon_SpriteGroup;


/**
 * Creates a new group with initial capacity.
 *
 * The 'check_visibility' parameter determines
 *whether objects will be checked for being in
 *the visible zone of the window or not. If it is set to 1,
 *then only visible objects will be drawn.
 */
MOON_CSFML_API moon_SpriteGroup*
moon_SpriteGroup_create(
	int check_visibility,
	unsigned long initial_capacity
);

/**
 * Destroys group, but not it's members.
 */
MOON_CSFML_API void
moon_SpriteGroup_destroy(moon_SpriteGroup* self);

/**
 * Sets the global color of sprites in the group.
 *
 * This color is modulated (multiplied) with the sprite's
 *texture. It can be used to colorize the sprite, or change
 *its global opacity.
 * By default, the sprite's color is opaque white.
 */
MOON_CSFML_API void
moon_SpriteGroup_set_color(
	const moon_SpriteGroup* self,
	const moon_Color* color
);

/**
 * Returns world bounds of the object at index.
 * If index out of bounds, behaviour is undefined.
 *
 * What is world bounds?
 * It is position of the object and size of the object.
 * {left(x), top(y), width, height}
 * For some reason position from global bounds and
 *position from getPosition are different. This is why
 *this function exist.
 */
MOON_CSFML_API moon_FloatRect
moon_SpriteGroup_get_world_bounds(
	const moon_SpriteGroup* self,
	unsigned long index
);

/**
 * Returns the local bounding rectangle of the entity at index.
 * If index out of bounds, behaviour is undefined.
 *
 * The returned rectangle is in local coordinates, which means
 *that it ignores the transformations (translation, rotation,
 *scale, ...) that are applied to the entity.
 * In other words, this function returns the bounds of the
 *entity in the entity's coordinate system.
 */
MOON_CSFML_API moon_FloatRect
moon_SpriteGroup_get_local_bounds(
	const moon_SpriteGroup* self,
	unsigned long index
);

/**
 * Returns the global bounding rectangle of the entity at index.
 * If index out of bounds, behaviour is undefined.
 *
 * The returned rectangle is in global coordinates, which means
 *that it takes into account the transformations (translation,
 *rotation, scale, ...) that are applied to the entity.
 * In other words, this function returns the bounds of the
 *sprite in the global 2D world's coordinate system.
 */
MOON_CSFML_API moon_FloatRect
moon_SpriteGroup_get_global_bounds(
	const moon_SpriteGroup* self,
	unsigned long index
);

// moon_SpriteTransform begin.

/**
 * Flips the sprites in the group about
 *the oX and oY axes, keeping it in its current position.
 * Does not change the 'origin' of the sprite.
 * If 'flip_x' and 'flip_y' are 0, does nothing.
 */
MOON_CSFML_API void
moon_SpriteGroup_flipX(
	const moon_SpriteGroup* self,
	int flip_x, int flip_y
);

/**
 * Rotates the sprites in group without
 *changing the position of their's center.
 * Useful when you don't want to set 'origin'.
 */
MOON_CSFML_API void
moon_SpriteGroup_rotateX(
	const moon_SpriteGroup* self,
	moon_Angle angle
);

/**
 * Sets the rotation angle of the sprites in group without
 *changing the position of their's center.
 * Useful when you don't want to set 'origin'.
 */
MOON_CSFML_API void
moon_SpriteGroup_set_rotationX(
	const moon_SpriteGroup* self,
	moon_Angle angle
);

/**
 * Copies transformations of 'source' to
 *sprites in group.
 * Transformations: position, rotation, scale and origin.
 */
MOON_CSFML_API void
moon_SpriteGroup_copy_transformX(
	const moon_SpriteGroup* self,
	const moon_Sprite* source
);

// moon_SpriteTransform end.

// Sprite begin.

/**
 * Sets the position of the objects in the group.
 *
 * This function completely overwrites the previous position.
 * See the move function to apply an offset based on the previous position instead.
 * The default position of a transformable object is (0, 0).
 */
MOON_CSFML_API void
moon_SpriteGroup_set_position(
	const moon_SpriteGroup* self,
	float left, float top
);

/**
 * Sets the orientation of the objects in the group.
 * This function completely overwrites the previous rotation.
 * See the rotate function to add an angle based on the previous rotation instead.
 * The default rotation of a transformable object is 0.
 */
MOON_CSFML_API void
moon_SpriteGroup_set_rotation(
	const moon_SpriteGroup* self,
	moon_Angle angle
);

/**
 * Sets the scale factors of the objects in the group.
 * This function completely overwrites the previous scale.
 * See the scale function to add a factor based on the previous scale instead.
 * The default scale of a transformable object is (1, 1).
 */
MOON_CSFML_API void
moon_SpriteGroup_set_scale(
	const moon_SpriteGroup* self,
	float scale_x, float scale_y
);

/**
 * Sets the local origin of the objects in the group.
 * The origin of an object defines the center point for
 * all transformations (position, scale, rotation).
 * The coordinates of this point must be relative to the
 * top-left corner of the object, and ignore all
 * transformations (position, scale, rotation).
 * The default origin of a transformable object is (0, 0).
 */
MOON_CSFML_API void
moon_SpriteGroup_set_origin(
	const moon_SpriteGroup* self,
	float x, float y
);

/**
 * Moves the objects in the group by a given offset.
 * This function adds to the current position of the object,
 *unlike setPosition which overwrites it.
 * Thus, it is equivalent to the following code(SFML example):
 * \code
 * sf::Vector2f pos = object.getPosition();
 * object.setPosition(pos.x + offsetX, pos.y + offsetY);
 * \endcode
 */
MOON_CSFML_API void
moon_SpriteGroup_move(
	const moon_SpriteGroup* self,
	float dx, float dy
);

/**
 * Rotates the objects in the group.
 * This function adds to the current rotation of the object,
 *unlike setRotation which overwrites it.
 * Thus, it is equivalent to the following code(SFML example):
 * \code
 * object.setRotation(object.getRotation() + angle);
 * \endcode
 */
MOON_CSFML_API void
moon_SpriteGroup_rotate(
	const moon_SpriteGroup* self,
	moon_Angle angle
);

/**
 * Scales the objects in the group.
 * This function multiplies the current scale of the object,
 *unlike setScale which overwrites it.
 * Thus, it is equivalent to the following code(SFML example):
 * \code
 * sf::Vector2f scale = object.getScale();
 * object.setScale(scale.x * factorX, scale.y * factorY);
 * \endcode
 */
MOON_CSFML_API void
moon_SpriteGroup_scale(
	const moon_SpriteGroup* self,
	float scale_x, float scale_y
);

// Sprite end.

// DrawGroup begin.

/**
 * Returns 1 if internal array has no elements
 *to be drawn. Otherwise, returns 0.
 */
MOON_CSFML_API int
moon_SpriteGroup_is_empty(const moon_SpriteGroup* self);

/**
 * Returns 1 if the check for the presence of the group's objects
 *in the visible area of the screen is enabled, otherwise 0.
 */
MOON_CSFML_API int
moon_SpriteGroup_is_check_enabled(const moon_SpriteGroup* self);

/**
 * Resizes group.
 * If 'new_size' is less than length(number of elements),
 *returns 0 and does nothing.
 * Otherwise, returns 1.
 */
MOON_CSFML_API int
moon_SpriteGroup_resize(
	moon_SpriteGroup* self,
	unsigned long new_size
);

/**
 * Reserves space(capacity) for new
 *elements.
 * If 'capacity' is greater than current size(capacity),
 *new storage is allocated. Otherwise, function does nothing.
 * Returns 1 if successful, 0 otherwise.
 */
MOON_CSFML_API int
moon_SpriteGroup_reserve(
	moon_SpriteGroup* self,
	unsigned long capacity
);

/**
 * Returns size(current capacity) of the group.
 */
MOON_CSFML_API unsigned long
moon_SpriteGroup_size(const moon_SpriteGroup* self);

/**
 * Returns length(number of elements) of the group.
 */
MOON_CSFML_API unsigned long
moon_SpriteGroup_length(const moon_SpriteGroup* self);

/**
 * Removes all elements from the group.
 */
MOON_CSFML_API void
moon_SpriteGroup_clear(moon_SpriteGroup* self);

/**
 * Reverses the order in which items will be drawn.
 */
MOON_CSFML_API void
moon_SpriteGroup_reverse(moon_SpriteGroup* self);

/**
 * Check(1) or not(0) check if objects are in the
 *visible area of the screen before rendering.
 */
MOON_CSFML_API void
moon_SpriteGroup_set_check_enabled(
	moon_SpriteGroup* self,
	int check_visibility
);

/**
 * Removes an element from the group by index.
 */
MOON_CSFML_API void
moon_SpriteGroup_remove(
	moon_SpriteGroup* self,
	unsigned long index
);

/**
 * Draws members of this group to the render window.
 * Rendering occurs in the same order in which the objects were added.
 */
MOON_CSFML_API void
moon_SpriteGroup_draw(
	const moon_SpriteGroup* self,
	moon_RenderWindow* wnd,
	const moon_RenderStates* states
);

/**
 * Appends new element for drawing to
 *the end of internal array.
 * No checks performed.
 * O(1)
 */
MOON_CSFML_API void
moon_SpriteGroup_push_back(
	moon_SpriteGroup* self,
	moon_Sprite* sprite
);

/**
 * Appends new element for drawing to
 *the head of internal array.
 * No checks performed.
 * O(n)
 */
MOON_CSFML_API void
moon_SpriteGroup_push_front(
	moon_SpriteGroup* self,
	moon_Sprite* sprite
);

/**
 * Appends (copies) elements(pointers) from the 'other' group to
 *the end of 'self' group.
 */
MOON_CSFML_API void
moon_SpriteGroup_extend(
	moon_SpriteGroup* self,
	const moon_SpriteGroup* other
);

/**
 * Returns a slice of this group.
 * Slicing is similar(but not the same) to python slicing.
 * Indexes can be negative, in that case
 *index will be recomputed('index' + 'length').
 * No bound checking.
 * If step is 0, returns empty slice.
 * If step is negative, elements will be in reverse and stop
 *index will be included in range.
 * Slice will contain copies of original's elements.
 * 'check_visibility' will be the same as original's.
 * Also can be used to copy current array: [0 : 'length' : 1].
 */
MOON_CSFML_API moon_SpriteGroup*
moon_SpriteGroup_get_slice(
	const moon_SpriteGroup* self,
	long long start,
	long long stop,
	long long step
);

// DrawGroup end


#ifdef __cplusplus
}
#endif


#endif
