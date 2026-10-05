#ifndef MOON_CSFML_EXTRAS_MOON_FRECT_LST_H
#define MOON_CSFML_EXTRAS_MOON_FRECT_LST_H


#include "../graphics/moon_rect.h"


#ifdef __cplusplus
extern "C" {
#endif


#define moon_FRectLst_InitialCapacity (15UL)


struct MOON_CSFML_API moon_FRectLst;


/**
 * List of moon_FloatRect objects.
 * Inside, it uses std::vector.
 */
typedef struct moon_FRectLst moon_FRectLst;


/**
 * Creates new list with initial capacity.
 */
MOON_CSFML_API moon_FRectLst*
moon_FRectLst_create(unsigned long initial_capacity);

/**
 * Destroys list.
 */
MOON_CSFML_API void
moon_FRectLst_destroy(moon_FRectLst* self);

/**
 * Returns 1 if internal array is empty,
 *0 otherwise.
 */
MOON_CSFML_API int
moon_FRectLst_is_empty(const moon_FRectLst* self);

/**
 * Reserves space(capacity) for new
 *elements.
 * If 'capacity' is greater than current size(capacity),
 *new storage is allocated. Otherwise, function does nothing.
 * Returns 1 if successful, 0 otherwise.
 */
MOON_CSFML_API int
moon_FRectLst_reserve(
	moon_FRectLst* self,
	unsigned long capacity
);

/**
 * Returns size(current capacity) of the list.
 */
MOON_CSFML_API unsigned long
moon_FRectLst_size(const moon_FRectLst* self);

/**
 * Returns length(number of elements) of the list.
 */
MOON_CSFML_API unsigned long
moon_FRectLst_length(const moon_FRectLst* self);

/**
 * Removes all elements from the list.
 */
MOON_CSFML_API void
moon_FRectLst_clear(moon_FRectLst* self);

/**
 * Reverses the order.
 */
MOON_CSFML_API void
moon_FRectLst_reverse(moon_FRectLst* self);

/**
 * Resizes list.
 */
MOON_CSFML_API void
moon_FRectLst_resize(
	moon_FRectLst* self,
	unsigned long new_size
);

/**
 * Sets(copies) self[index] to rectangle.
 * No checks.
 */
MOON_CSFML_API void
moon_FRectLst_set(
	moon_FRectLst* self,
	unsigned long index,
	const moon_FloatRect* rect
);

/**
 * Returns read-only pointer to internal
 *rectangle.
 * Pointer exist until list exist.
 * No checks.
 */
MOON_CSFML_API const moon_FloatRect*
moon_FRectLst_read(
	const moon_FRectLst* self,
	unsigned long index
);

/**
 * Returns copy of element at index.
 * No checks.
 */
MOON_CSFML_API moon_FloatRect
moon_FRectLst_get(
	const moon_FRectLst* self,
	unsigned long index
);

/**
 * Removes an element from the group by index.
 * Returns removed rectangle.
 */
MOON_CSFML_API moon_FloatRect
moon_FRectLst_pop(
	moon_FRectLst* self,
	unsigned long index
);

/**
 * Appends(copies) new element to
 *the end of internal array.
 * O(1)
 */
MOON_CSFML_API void
moon_FRectLst_push_back(
	moon_FRectLst* self,
	const moon_FloatRect* rect
);

/**
 * Appends(copies) new element to
 *the head of internal array.
 * O(n)
 */
MOON_CSFML_API void
moon_FRectLst_push_front(
	moon_FRectLst* self,
	const moon_FloatRect* rect
);

/**
 * Appends (copies) elements from the 'other' group to
 *the end of 'self' group.
 */
MOON_CSFML_API void
moon_FRectLst_extend(
	moon_FRectLst* self,
	const moon_FRectLst* other
);

/**
 * Moves each rectangle in group
 *by given offsets.
 */
MOON_CSFML_API void
moon_FRectLst_move(
	moon_FRectLst* self,
	float dx, float dy
);

/**
 * Sets position for each rectangle in group.
 */
MOON_CSFML_API void
moon_FRectLst_set_position(
	moon_FRectLst* self,
	float left, float top
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
MOON_CSFML_API moon_FRectLst*
moon_FRectLst_get_slice(
	const moon_FRectLst* self,
	long long start,
	long long stop,
	long long step
);


#ifdef __cplusplus
}
#endif


#endif
