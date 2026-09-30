#ifndef MOON_CSFML_GRAPHICS_MOON_COLLISIONS_H
#define MOON_CSFML_GRAPHICS_MOON_COLLISIONS_H


#include "./moon_sprite_group.h"


#ifdef __cplusplus
extern "C" {
#endif


#define moon_Collisions_UnlimitedDistance (0.f)


/**
 * Returns the offset in the vertical axis by
 *which the first rectangle must be moved, so that
 *it does not touch the second.
 * Before using this function, you should still check
 *the rectangles for intersection. A correct result is only
 *possible if the rectangles do intersect.
 * It doesn't work perfectly, but it's the best I've come up with.
 */
MOON_CSFML_API float
moon_Collisions_resolve_vertical(
	const moon_FloatRect* self,
	const moon_FloatRect* other
);

/**
 * Returns the offset in the horizontal axis by
 *which the first rectangle must be moved, so that
 *it does not touch the second.
 * Before using this function, you should still check
 *the rectangles for intersection. A correct result is only
 *possible if the rectangles do intersect.
 * It doesn't work perfectly, but it's the best I've come up with.
 */
MOON_CSFML_API float
moon_Collisions_resolve_horizontal(
	const moon_FloatRect* self,
	const moon_FloatRect* other
);

/**
 * Returns horizontal and vertical offsets by
 *which the first rectangle must be moved, so that
 *it does not touch the second.
 * Before using this function, you should still check
 *the rectangles for intersection. A correct result is only
 *possible if the rectangles do intersect.
 * Changes the position of the 'self' rectangle.
 * It doesn't work perfectly, but it's the best I've come up with.
 */
MOON_CSFML_API moon_Vector2f
moon_Collisions_resolve_collisions(
	moon_FloatRect* self,
	const moon_FloatRect* other
);

/**
 * Resolves collisions between rectangle 'self'
 *and sprite group.
 * Changes the position of the 'self' rectangle.
 *
 * Returns horizontal and vertical offsets by
 *which the first rectangle must be moved, so that
 *it does not touch sprites's global bounds rectangles.
 * Checks intersections itself and resolve collisions only
 *if rectangles have intersction.
 *
 * The 'distance_x' and 'distance_y' define the horizontal
 *or vertical axis distances for the rectangles. These
 *are the distances between their centers. If the actual
 *distance is greater than or equal to, the collision
 *resolution will be ignored.
 * If the distance is negative or equal to
 *'moon_Collisions_UnlimitedDistance', the parameter will be ignored.
 *
 * 'resolve_horizontal' and 'resolve_vertical' determine
 *which axis to resolve collisions (horizontal, vertical, or both).
 *1 for collision resolution, 0 for skipping.
 *If both parameters are 0, returns {0, 0}.
 *
 */
MOON_CSFML_API moon_Vector2f
moon_Collisions_sprites_collision(
	moon_FloatRect* self,
	const moon_SpriteGroup* sprites,
	float distance_x,
	float distance_y,
	int resolve_horizontal,
	int resolve_vertical
);

/**
 * Returns 1 if rectangle 'self' collides
 *with global bounds rectangle of any
 *sprite in the group.
 * Otherwise, returns 0.
 */
MOON_CSFML_API int
moon_Collisions_is_any_collision(
	const moon_FloatRect* self,
	const moon_SpriteGroup* sprites
);


#ifdef __cplusplus
}
#endif


#endif
