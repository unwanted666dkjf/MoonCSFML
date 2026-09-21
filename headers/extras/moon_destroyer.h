#ifndef MOON_CSFML_EXTRAS_MOON_DESTROYER
#define MOON_CSFML_EXTRAS_MOON_DESTROYER


#include "../import_macro.h"


#ifdef __cplusplus
extern "C" {
#endif


struct MOON_CSFML_API moon_Destroyer;


/**
 * Structure for storing and destroying
 *destroyable objects.
 * It is preferable to create it before any destroyable objects.
 * A simple object destructor for this
 *library intended for a single-threaded environment.
 *
 * Why single-threaded?
 * 1. I am lazy.
 * 2. C99
 */
typedef struct moon_Destroyer moon_Destroyer;


/**
 * Creates destroyer with initial capacity.
 */
MOON_CSFML_API moon_Destroyer*
moon_Destroyer_create(unsigned long initial_capacity);

/**
 * Destroyes internal objects and itself.
 * Objects will be destroyed in the
 *reverse order of the addition.
 */
MOON_CSFML_API void
moon_Destroyer_destroy(moon_Destroyer* self);

/**
 * Returns 1 if there are no destroyables yet.
 * Otherwise, returns 0.
 */
MOON_CSFML_API int
moon_Destroyer_is_empty(const moon_Destroyer* self);

/**
 * Resizes destroyer.
 * If 'new_size' is less than length(number of elements),
 *returns 0 and does nothing.
 * Otherwise, returns 1.
 */
MOON_CSFML_API int
moon_Destroyer_resize(
	moon_Destroyer* self,
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
moon_Destroyer_reserve(
	moon_Destroyer* self,
	unsigned long capacity
);

/**
 * Returns size(capacity) of the object.
 */
MOON_CSFML_API unsigned long
moon_Destroyer_size(const moon_Destroyer* self);

/**
 * Returns length(number of elements) of the object.
 */
MOON_CSFML_API unsigned long
moon_Destroyer_length(const moon_Destroyer* self);

/**
 * Completely clears the internal array of
 *objects without destroying them.
 */
MOON_CSFML_API void
moon_Destroyer_clear(moon_Destroyer* self);

/**
 * Completely clears the inner array and destroys objects in it.
 * Objects will be destroyed in the
 *reverse order of the addition.
 */
MOON_CSFML_API void
moon_Destroyer_annihilate(moon_Destroyer* self);

/**
 * Reverses the order in which items are destroyed.
 */
MOON_CSFML_API void
moon_Destroyer_reverse(moon_Destroyer* self);

/**
 * Adds a destructible object to the end of the array.
 * No validation is performed. If the type is unknown or the
 *object is invalid, the behavior is undefined.
 * O(1).
 */
MOON_CSFML_API void
moon_Destroyer_push_back(
	moon_Destroyer* self,
	void* destroyable_body,
	int destroyable_type
);

/**
 * Adds a destructible object to the beginning of the array.
 * No validation is performed. If the type is unknown or
 *the object is invalid, the behavior is undefined.
 * O(n).
 */
MOON_CSFML_API void
moon_Destroyer_push_front(
	moon_Destroyer* self,
	void* destroyable_body,
	int destroyable_type
);


#ifdef __cplusplus
}
#endif


#endif
