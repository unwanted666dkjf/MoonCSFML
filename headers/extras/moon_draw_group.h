#ifndef MOON_CSFML_EXTRAS_MOON_DRAW_GROUP_H
#define MOON_CSFML_EXTRAS_MOON_DRAW_GROUP_H


#include "../graphics/moon_render_states.h"

#include "../graphics/moon_render_window.h"


#ifdef __cplusplus
extern "C" {
#endif


struct MOON_CSFML_API moon_DrawGroup;


/**
 * Structure for storing objects to be drawn.
 */
typedef struct moon_DrawGroup moon_DrawGroup;


/**
 * Creates a new group with initial capacity.
 *
 * The 'check_visibility' parameter determines
 *whether objects will be checked for being in
 *the visible zone of the window or not. If it is set to 1,
 *then only visible objects will be drawn.
 */
MOON_CSFML_API moon_DrawGroup*
moon_DrawGroup_create(
	int check_visibility,
	unsigned long initial_capacity
);

/**
 * Destroys group, but not it's members.
 */
MOON_CSFML_API void
moon_DrawGroup_destroy(moon_DrawGroup* self);

/**
 * Returns 1 if internal array has no elements
 *to be drawn. Otherwise, returns 0.
 */
MOON_CSFML_API int
moon_DrawGroup_is_empty(const moon_DrawGroup* self);

/**
 * Returns 1 if the check for the presence of the group's objects
 *in the visible area of the screen is enabled, otherwise 0.
 */
MOON_CSFML_API int
moon_DrawGroup_is_check_enabled(const moon_DrawGroup* self);

/**
 * Resizes group.
 * If 'new_size' is less than length(number of elements),
 *returns 0 and does nothing.
 * Otherwise, returns 1.
 */
MOON_CSFML_API int
moon_DrawGroup_resize(
	moon_DrawGroup* self,
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
moon_DrawGroup_reserve(
	moon_DrawGroup* self,
	unsigned long capacity
);

/**
 * Returns size(current capacity) of the group.
 */
MOON_CSFML_API unsigned long
moon_DrawGroup_size(const moon_DrawGroup* self);

/**
 * Returns length(number of elements) of the group.
 */
MOON_CSFML_API unsigned long
moon_DrawGroup_length(const moon_DrawGroup* self);

/**
 * Removes all elements from the group.
 */
MOON_CSFML_API void
moon_DrawGroup_clear(moon_DrawGroup* self);

/**
 * Reverses the order in which items will be drawn.
 */
MOON_CSFML_API void
moon_DrawGroup_reverse(moon_DrawGroup* self);

/**
 * Check(1) or not(0) check if objects are in the
 *visible area of the screen before rendering.
 */
MOON_CSFML_API void
moon_DrawGroup_set_check_enabled(
	moon_DrawGroup* self,
	int check_visibility
);

/**
 * Removes an element from the group by index.
 */
MOON_CSFML_API void
moon_DrawGroup_remove(
	moon_DrawGroup* self,
	unsigned long index
);

/**
 * Draws members of this group to the render window.
 * Rendering occurs in the same order in which the objects were added.
 */
MOON_CSFML_API void
moon_DrawGroup_draw(
	const moon_DrawGroup* self,
	moon_RenderWindow* wnd,
	const moon_RenderStates* states
);

/**
 * Appends new element for drawing to
 *the end of internal array.
 * No checks performed. If object is not
 *groupable, behaviour is undefined.
 * Groupable: Text, Sprite, ConvexShape, CircleShape,
 *RectangleShape, SlideAnimation, guiFpsCntr, TextWrite.
 * O(1)
 */
MOON_CSFML_API void
moon_DrawGroup_push_back(
	moon_DrawGroup* self,
	const void* groupable,
	int groupable_type
);

/**
 * Appends new element for drawing to
 *the head of internal array.
 * No checks performed. If object is not
 *groupable, behaviour is undefined.
 * Groupable: Text, Sprite, ConvexShape, CircleShape,
 *RectangleShape, SlideAnimation, guiFpsCntr, TextWrite.
 * O(n)
 */
MOON_CSFML_API void
moon_DrawGroup_push_front(
	moon_DrawGroup* self,
	const void* groupable,
	int groupable_type
);

/**
 * Appends (copies) elements from the 'other' group to
 *the end of 'self' group.
 */
MOON_CSFML_API void
moon_DrawGroup_extend(
	moon_DrawGroup* self,
	const moon_DrawGroup* other
);

/**
 * Returns a slice of this group.
 * Slicing is similar(but not the same) to python slicing.
 * Indexes can be negative, in that case
 *index will be recomputed('index' + 'vertex_count').
 * No bound checking.
 * If step is 0, returns empty slice.
 * If step is negative, elements will be in reverse and stop
 *index will be included in range.
 * Slice will contain copies of original's elements.
 * 'check_visibility' will be the same as original's.
 * Also can be used to copy current array: [0 : 'length' : 1].
 */
MOON_CSFML_API moon_DrawGroup*
moon_DrawGroup_get_slice(
	const moon_DrawGroup* self,
	long long start,
	long long stop,
	long long step
);


#ifdef __cplusplus
}
#endif


#endif
