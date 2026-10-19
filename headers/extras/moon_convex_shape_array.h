#ifndef MOON_CSFML_EXTRAS_MOON_CONVEX_SHAPE_ARRAY_H
#define MOON_CSFML_EXTRAS_MOON_CONVEX_SHAPE_ARRAY_H


#include "./moon_frect_lst.h"


#include "../graphics/moon_convex_shape.h"

#include "../graphics/moon_render_states.h"

#include "../graphics/moon_render_window.h"


#ifdef __cplusplus
extern "C" {
#endif


struct MOON_CSFML_API moon_ConvexShapeArray;


/**
 * Specialized array for manipulating moon_ConvexShape
 *elements(drawing and some tranformations).
 */
typedef struct moon_ConvexShapeArray moon_ConvexShapeArray;


/**
 * Creates new array with initial capacity.
 * 'check_visibility' determines whether to draw(1)
 *only those elements that are in the visible area, or
 *all(0) elements. This parameter is only for drawing.
 */
MOON_CSFML_API moon_ConvexShapeArray*
moon_ConvexShapeArray_create(
	int check_visibility,
	unsigned long initial_capacity
);

/**
 * Destroys array, but not the inner elements.
 */
MOON_CSFML_API void
moon_ConvexShapeArray_destroy(moon_ConvexShapeArray* self);

/**
 * Returns a slice of this array.
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
MOON_CSFML_API moon_ConvexShapeArray*
moon_ConvexShapeArray_get_slice(
	const moon_ConvexShapeArray* self,
	long long start,
	long long stop,
	long long step
);

/**
 * Returns 1 if array is empty, 0 otherwise.
 */
MOON_CSFML_API int
moon_ConvexShapeArray_is_empty(const moon_ConvexShapeArray* self);

/**
 * Returns 1 if checking whether element in visible area
 *of the screen is enabled, 0 otherwise.
 */
MOON_CSFML_API int
moon_ConvexShapeArray_is_check_enabled(const moon_ConvexShapeArray* self);

/**
 * Resizes inner array if new size is greater
 *than current size.
 * Returns 1 if array resized, 0 otherwise.
 */
MOON_CSFML_API int
moon_ConvexShapeArray_resize(
	moon_ConvexShapeArray* self,
	unsigned long new_size
);

/**
 * Changes the capacity of the array if
 *new capacity is greater than current number of elements.
 * Returns 1 if capacity changed, 0 otherwise.
 */
MOON_CSFML_API int
moon_ConvexShapeArray_reserve(
	moon_ConvexShapeArray* self,
	unsigned long new_capacity
);

/**
 * Returns size(capacity) of the array.
 */
MOON_CSFML_API unsigned long
moon_ConvexShapeArray_get_size(const moon_ConvexShapeArray* self);

/**
 * Returns length(number of elements) of the array.
 */
MOON_CSFML_API unsigned long
moon_ConvexShapeArray_get_length(const moon_ConvexShapeArray* self);

/**
 * Clears array from all elements.
 */
MOON_CSFML_API void
moon_ConvexShapeArray_clear(moon_ConvexShapeArray* self);

/**
 * Reverses order of elements of the array.
 * Operation starts from index 'first_index' and involves
 *maximum 'num_elements'.
 */
MOON_CSFML_API void
moon_ConvexShapeArray_reverse(
	moon_ConvexShapeArray* self,
	unsigned long first_index,
	unsigned long num_elements
);

/**
 * Removes(not destroys!) elements from the array.
 * Operation starts from index 'first_index' and involves
 *maximum 'num_elements'.
 */
MOON_CSFML_API void
moon_ConvexShapeArray_remove(
	moon_ConvexShapeArray* self,
	unsigned long first_index,
	unsigned long num_elements
);

/**
 * Append element to the end of the array.
 */
MOON_CSFML_API void
moon_ConvexShapeArray_push_back(
	moon_ConvexShapeArray* self,
	moon_ConvexShape* element
);

/**
 * Inserts element before index.
 */
MOON_CSFML_API void
moon_ConvexShapeArray_insert(
	moon_ConvexShapeArray* self,
	unsigned long index,
	moon_ConvexShape* element
);

/**
 * Append element from 'other' array to the end
 *of 'self' array.
 * Operation starts from index 'other_first_index' and involves
 *maximum 'other_num_elements'.
 */
MOON_CSFML_API void
moon_ConvexShapeArray_extend(
	moon_ConvexShapeArray* self,
	const moon_ConvexShapeArray* other,
	unsigned long other_first_index,
	unsigned long other_num_elements
);

/**
 * Enable(1) or disable(0) check for presence in visible
 *area of the screen.
 */
MOON_CSFML_API void
moon_ConvexShapeArray_set_check_enabled(
	moon_ConvexShapeArray* self,
	int check_visibility
);

/**
 * Sets element to the index.
 * Returns old element.
 */
MOON_CSFML_API moon_ConvexShape*
moon_ConvexShapeArray_set(
	moon_ConvexShapeArray* self,
	unsigned long index,
	moon_ConvexShape* element
);

/**
 * Removes and returns element at index.
 */
MOON_CSFML_API moon_ConvexShape*
moon_ConvexShapeArray_pop(
	moon_ConvexShapeArray* self,
	unsigned long index
);

/**
 * Returns element at index without removing.
 */
MOON_CSFML_API moon_ConvexShape*
moon_ConvexShapeArray_get(
	moon_ConvexShapeArray* self,
	unsigned long index
);

/**
 * Draws 'num_elements' of the array to the
 *RenderWindow, starting from index 'first_index'.
 */
MOON_CSFML_API void
moon_ConvexShapeArray_draw(
	const moon_ConvexShapeArray* self,
	moon_RenderWindow* wnd,
	moon_RenderStates* states,
	unsigned long first_index,
	unsigned long num_elements
);

/**
 * Sets color for 'num_elements' of the array, starting from
 *index 'first_index'.
 */
MOON_CSFML_API void
moon_ConvexShapeArray_set_color(
	const moon_ConvexShapeArray* self,
	const moon_Color* color,
	unsigned long first_index,
	unsigned long num_elements
);

/**
 * Returns index of first element with given alpha. If there
 *is no elements, returns negative value.
 * Operation starts from index 'first_index' and involves
 *maximum 'num_elements'.
 */
MOON_CSFML_API long long
moon_ConvexShapeArray_find_alpha(
	const moon_ConvexShapeArray* self,
	unsigned char alpha,
	unsigned long first_index,
	unsigned long num_elements
);

/**
 * Returns index of the first element with given color. If there is no
 *elements, returns negative value.
 * 'ignore_alpha' determines whether to ignore(1) or not(0) alpha value
 *of the color in comparisons.
 * Operation starts from index 'first_index' and involves
 *maximum 'num_elements'.
 */
MOON_CSFML_API long long
moon_ConvexShapeArray_find_color(
	const moon_ConvexShapeArray* self,
	const moon_Color* color,
	int ignore_alpha,
	unsigned long first_index,
	unsigned long num_elements
);

/**
 * Inverses color for 'num_elements' of the array,
 *starting from index 'first_index'.
 * Inversion does not include 'alpha'.
 */
MOON_CSFML_API void
moon_ConvexShapeArray_inverse_color(
	const moon_ConvexShapeArray* self,
	unsigned long first_index,
	unsigned long num_elements
);

/**
 * Sets alpha for 'num_elements' of the array,
 *starting from index 'first_index'.
 */
MOON_CSFML_API void
moon_ConvexShapeArray_set_alpha(
	const moon_ConvexShapeArray* self,
	unsigned char alpha,
	unsigned long first_index,
	unsigned long num_elements
);

/**
 * Returns bounds of 'num_elements' objects of the array,
 *starting from index 'first_index'.
 * Bounds types:
 * moon_BoundsType_Global;
 * moon_BoundsType_Local;
 * moon_BoundsType_World
 */
MOON_CSFML_API moon_FRectLst*
moon_ConvexShapeArray_get_bounds(
	const moon_ConvexShapeArray* self,
	int bounds_type,
	unsigned long first_index,
	unsigned long num_elements
);

/**
 * Returns index of element with given size or
 *negative value if there is no elements.
 * Operation starts from index 'first_index' and involves
 *maximum 'num_elements'.
 */
MOON_CSFML_API long long
moon_ConvexShapeArray_find_elsize(
	const moon_ConvexShapeArray* self,
	const moon_Vector2f* size,
	unsigned long first_index,
	unsigned long num_elements
);

/**
 * Returns index of element with maximum/minimal width/height or
 *negative value if there is no elements.
 * Operation starts from index 'first_index' and involves
 *maximum 'num_elements'.
 */
MOON_CSFML_API long long
moon_ConvexShapeArray_get_elsize(
	const moon_ConvexShapeArray* self,
	int is_get_min, int is_get_y,
	unsigned long first_index,
	unsigned long num_elements
);

/**
 * Returns index of first element with given scale if
 *there is any, otherwise returns negative value.
 * Operation starts from index 'first_index' and involves
 *maximum 'num_elements'.
 */
MOON_CSFML_API long long
moon_ConvexShapeArray_find_elscale(
	const moon_ConvexShapeArray* self,
	const moon_Vector2f* scale,
	unsigned long first_index,
	unsigned long num_elements
);

/**
 * Returns index of element with maximum/minimal scale_x/scale_y or
 *negative value if there is no elements.
 * Operation starts from index 'first_index' and involves
 *maximum 'num_elements'.
 */
MOON_CSFML_API long long
moon_ConvexShapeArray_get_elscale(
	const moon_ConvexShapeArray* self,
	int is_get_min, int is_get_y,
	unsigned long first_index,
	unsigned long num_elements
);

/**
 * Sets scale for array elements.
 * Operation starts from index 'first_index' and involves
 *maximum 'num_elements'.
 */
MOON_CSFML_API void
moon_ConvexShapeArray_set_elscale(
	const moon_ConvexShapeArray* self,
	float scale_x, float scale_y,
	unsigned long first_index,
	unsigned long num_elements
);

/**
 * Scales for array elements.
 * Operation starts from index 'first_index' and involves
 *maximum 'num_elements'.
 */
MOON_CSFML_API void
moon_ConvexShapeArray_elscale(
	const moon_ConvexShapeArray* self,
	float scale_x, float scale_y,
	unsigned long first_index,
	unsigned long num_elements
);

/**
 * Returns index of the first element with given position or
 *negative value if there is no any.
 * Operation starts from index 'first_index' and involves
 *maximum 'num_elements'.
 */
MOON_CSFML_API long long
moon_ConvexShapeArray_find_elposition(
	const moon_ConvexShapeArray* self,
	const moon_Vector2f* position,
	unsigned long first_index,
	unsigned long num_elements
);

/**
 * Returns index of element with maximum/minimal x/y or
 *negative value if there is no elements.
 * Operation starts from index 'first_index' and involves
 *maximum 'num_elements'.
 */
MOON_CSFML_API long long
moon_ConvexShapeArray_get_elposition(
	const moon_ConvexShapeArray* self,
	int is_get_min, int is_get_y,
	unsigned long first_index,
	unsigned long num_elements
);

/**
 * Randomizes positions of elements in the array.
 * Ranges are inclusive, i.e.: [min_x; max_x] and [min_y, max_y].
 * Operation starts from index 'first_index' and involves
 *maximum 'num_elements'.
 */
MOON_CSFML_API void
moon_ConvexShapeArray_randomize_elposition(
	const moon_ConvexShapeArray* self,
	int min_x, int max_x,
	int min_y, int max_y,
	unsigned long first_index,
	unsigned long num_elements
);

/**
 * Sets position for array elements.
 * Operation starts from index 'first_index' and involves
 *maximum 'num_elements'.
 */
MOON_CSFML_API void
moon_ConvexShapeArray_set_elposition(
	const moon_ConvexShapeArray* self,
	float x, float y,
	unsigned long first_index,
	unsigned long num_elements
);

/**
 * Moves array elements by given offsets.
 * Operation starts from index 'first_index' and involves
 *maximum 'num_elements'.
 */
MOON_CSFML_API void
moon_ConvexShapeArray_elmove(
	const moon_ConvexShapeArray* self,
	float dx, float dy,
	unsigned long first_index,
	unsigned long num_elements
);

/**
 * Returns index of the first element with given origin or
 *negative value if there is no any.
 * Operation starts from index 'first_index' and involves
 *maximum 'num_elements'.
 */
MOON_CSFML_API long long
moon_ConvexShapeArray_find_elorigin(
	const moon_ConvexShapeArray* self,
	const moon_Vector2f* origin,
	unsigned long first_index,
	unsigned long num_elements
);

/**
 * Returns index of element with maximum/minimal origin_x/origin_y or
 *negative value if there is no elements.
 * Operation starts from index 'first_index' and involves
 *maximum 'num_elements'.
 */
MOON_CSFML_API long long
moon_ConvexShapeArray_get_elorigin(
	const moon_ConvexShapeArray* self,
	int is_get_min, int is_get_y,
	unsigned long first_index,
	unsigned long num_elements
);

/**
 * Randomizes origins of elements in the array.
 * Ranges are inclusive, i.e.: [min_x; max_x] and [min_y, max_y].
 * Operation starts from index 'first_index' and involves
 *maximum 'num_elements'.
 */
MOON_CSFML_API void
moon_ConvexShapeArray_randomize_elorigin(
	const moon_ConvexShapeArray* self,
	int min_x, int max_x,
	int min_y, int max_y,
	unsigned long first_index,
	unsigned long num_elements
);

/**
 * Sets origin for array elements.
 * Operation starts from index 'first_index' and involves
 *maximum 'num_elements'.
 */
MOON_CSFML_API void
moon_ConvexShapeArray_set_elorigin(
	const moon_ConvexShapeArray* self,
	float origin_x, float origin_y,
	unsigned long first_index,
	unsigned long num_elements
);

/**
 * Returns index of the first element with given angle or
 *negative value if there is no any.
 * Operation starts from index 'first_index' and involves
 *maximum 'num_elements'.
 */
MOON_CSFML_API long long
moon_ConvexShapeArray_find_elrotation(
	const moon_ConvexShapeArray* self,
	moon_Angle angle,
	unsigned long first_index,
	unsigned long num_elements
);

/**
 * Returns index of element with maximum/minimum rotation or
 *negative value if there is no any.
 * Operation starts from index 'first_index' and involves
 *maximum 'num_elements'.
 */
MOON_CSFML_API long long
moon_ConvexShapeArray_get_elrotation(
	const moon_ConvexShapeArray* self,
	int is_get_min,
	unsigned long first_index,
	unsigned long num_elements
);

/**
 * Randomizes rotations for elements in the array.
 * Angles must be in degrees.
 * Operation starts from index 'first_index' and involves
 *maximum 'num_elements'.
 */
MOON_CSFML_API void
moon_ConvexShapeArray_randomize_elrotation(
	const moon_ConvexShapeArray* self,
	int min_angle, int max_angle,
	unsigned long first_index,
	unsigned long num_elements
);

/**
 * Sets rotation for elements of the array.
 * Operation starts from index 'first_index' and involves
 *maximum 'num_elements'.
 */
MOON_CSFML_API void
moon_ConvexShapeArray_set_elrotation(
	const moon_ConvexShapeArray* self,
	moon_Angle angle,
	unsigned long first_index,
	unsigned long num_elements
);

/**
 * Rotates elements of the array.
 * Operation starts from index 'first_index' and involves
 *maximum 'num_elements'.
 */
MOON_CSFML_API void
moon_ConvexShapeArray_elrotate(
	const moon_ConvexShapeArray* self,
	moon_Angle angle,
	unsigned long first_index,
	unsigned long num_elements
);


#ifdef __cplusplus
}
#endif


#endif
