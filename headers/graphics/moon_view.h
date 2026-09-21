#ifndef MOON_CSFML_GRAPHICS_MOON_VIEW_H
#define MOON_CSFML_GRAPHICS_MOON_VIEW_H


#include "./moon_rect.h"

#include "./moon_transform.h"


#include "../system/moon_angle.h"

#include "../system/moon_vector2.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * 2D camera that defines what region is shown on screen.
 */
typedef struct MOON_CSFML_API moon_View {
	moon_Angle 		rotation;
	moon_Vector2f 	center;
	moon_Vector2f 	size;
	moon_FloatRect 	viewport;
} moon_View;


/**
 * Creates a default view of (0, 0, 1000, 1000).
 */
MOON_CSFML_API moon_View
moon_View_create();

/*
 * Creates the view from its center and size.
 */
MOON_CSFML_API moon_View
moon_View_create_ex(
	float cx, 		float cy,
	float width, 	float height
);

/**
 * Sets the center of the view.
 * Shortcut for:
 *     self->center.x = cx;
 *     self->center.y = cy;
 */
MOON_CSFML_API void
moon_View_set_center(
	moon_View* self,
	float cx, float cy
);

/**
 * Sets the size of the view.
 * Shortcut for:
 *     self->size.x = width;
 *     self->size.y = height;
 */
MOON_CSFML_API void
moon_View_set_size(
	moon_View* self,
	float width, float height
);

/**
 * Sets the orientation of the view.
 * The default rotation of a view is 0 degree.
 * Handles negative angles.
 */
MOON_CSFML_API void
moon_View_set_rotation(
	moon_View* self,
	moon_Angle angle
);

/**
 * Moves the view relatively to its current position.
 * Shortcut for:
 *     self->center.x += dx;
 *     self->center.y += dy;
 */
MOON_CSFML_API void
moon_View_move(
	moon_View* self,
	float dx, float dy
);

/**
 * Rotates the view relatively to its current orientation.
 * Handles negative angles.
 */
MOON_CSFML_API void
moon_View_rotate(
	moon_View* self,
	moon_Angle angle
);

/**
 * Resizes the view rectangle relatively to its current size.
 * Resizing the view simulates a zoom, as the zone displayed on
 *screen grows or shrinks.
 * \a factor is a multiplier:
 * \li 1 keeps the size unchanged
 * \li > 1 makes the view bigger (objects appear smaller)
 * \li < 1 makes the view smaller (objects appear bigger)
 */
MOON_CSFML_API void
moon_View_zoom(
	moon_View* self,
	float factor
);

/**
 * Resets the view to the given rectangle.
 * Note: that this function resets the rotation angle to 0.
 */
MOON_CSFML_API void
moon_View_reset(
	moon_View* self,
	const moon_FloatRect* rectangle
);

/**
 * Returns copy of this view.
 */
MOON_CSFML_API moon_View
moon_View_get_copy(const moon_View* self);

/**
 * Returns the projection transform of the view.
 */
MOON_CSFML_API moon_Transform
moon_View_get_transform(const moon_View* self);

/**
 * Returns 1 if views are equal, 0 otherwise.
 * Views are equal if their members are equal.
 */
MOON_CSFML_API int
moon_View_is_eq(
	const moon_View* self,
	const moon_View* other
);

/**
 * Returns 1 if views are not equal, 0 otherwise.
 * Views are equal if their members are equal.
 */
MOON_CSFML_API int
moon_View_is_ne(
	const moon_View* self,
	const moon_View* other
);


#ifdef __cplusplus
}
#endif


#endif
