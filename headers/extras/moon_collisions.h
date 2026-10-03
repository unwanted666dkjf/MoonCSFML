#ifndef MOON_CSFML_GRAPHICS_MOON_COLLISIONS_H
#define MOON_CSFML_GRAPHICS_MOON_COLLISIONS_H


#include "./moon_frect_lst.h"

#include "./moon_sprite_group.h"


#ifdef __cplusplus
extern "C" {
#endif


#define moon_Collisions_ResolveBoth 		('x')

#define moon_Collisions_ResolveVertical 	('v')

#define moon_Collisions_ResolveHorizontal 	('h')

#define moon_Collisions_UnlimitedDistance 	(0.f)


/**
 * Resolves collisions between 'ptr_float_rectangle'
 *and 'ptr_sprites_or_rects'.
 * Changes the position of the 'ptr_float_rectangle' rectangle.
 *
 * Returns horizontal and vertical offsets by
 *which the first rectangle must be moved, so that
 *it does not touch sprites's global bounds rectangles.
 * Checks intersections itself and resolve collisions only
 *if rectangles have intersction.
 * The resulting offsets will be written to the variable 'vector2f_res_offsets'.
 *
 * 'vector2f_res_offsets' must have type 'moon_Vector2f'.
 *
 * 'ptr_float_rectangle' must have type 'moon_FloatRect*'.
 *
 * 'ptr_sprites_or_rects' must have type(const) 'moon_SpriteGroup*'
 *or 'moon_FRectLst'.
 *
 * 'float_distx' and 'float_disty' -- floating point numbers.
 *
 * 'ptr_char_which_collisions' -- string 'char*' or 'const char*'.
 *
 * 'sprite_or_rects_collision_function' -- 'moon_Collisions_sprites_collision'
 *or 'moon_Collisions_rectangles_collision'.
 *
 * The 'float_distx' and 'float_disty' define the horizontal
 *or vertical axis distances for the rectangles. These
 *are the distances between their centers. If the actual
 *distance is greater than or equal to, the collision
 *resolution will be ignored.
 * If the distance is negative or equal to
 *'moon_Collisions_UnlimitedDistance', the parameter will be ignored.
 *
 * 'ptr_char_which_collisions' must contain characters which collisions
 *need to resolve, example: "vh" -- first it resolves vertical, then horizontal.
 * v -- resolve vertical;
 * h -- resolve horizontal;
 * x -- resolve both, not recommended;
 * 'ptr_char_which_collisions' must be null-terminated.
 *
 * It doesn't work perfectly, but it's the best I've come up with.
 */
#define moon_Collisions_Procedure_CollisionMany( 	\
	vector2f_res_offsets, 							\
	ptr_float_rectangle,							\
	ptr_sprites_or_rects, 							\
	float_distx, float_disty, 						\
	ptr_char_which_collisions,						\
	sprite_or_rects_collision_function				\
)	\
{	\
	float distance_x_Procedure__ 				= (float)(float_distx);				\
	float distance_y_Procedure__ 				= (float)(float_disty);				\
	moon_Vector2f* res_offsets_Procedure__ 		= &(vector2f_res_offsets);			\
	const char* which_collisions_Procedure__ 	= (ptr_char_which_collisions);		\
	unsigned long i_Procedure__ 				= 0UL;								\
	while (which_collisions_Procedure__[i_Procedure__] != '\0') {					\
		moon_Vector2f offsets_Procedure__;											\
		switch (which_collisions_Procedure__[i_Procedure__]) {						\
			case moon_Collisions_ResolveVertical: {									\
				offsets_Procedure__ = sprite_or_rects_collision_function(			\
					(ptr_float_rectangle),											\
					(ptr_sprites_or_rects),											\
					distance_x_Procedure__,											\
					distance_y_Procedure__,											\
					0, 1															\
				);																	\
				break;																\
			}																		\
			case moon_Collisions_ResolveHorizontal: {								\
				offsets_Procedure__ = sprite_or_rects_collision_function(			\
					(ptr_float_rectangle),											\
					(ptr_sprites_or_rects),											\
					distance_x_Procedure__,											\
					distance_y_Procedure__,											\
					1, 0															\
				);																	\
				break;																\
			}																		\
			case moon_Collisions_ResolveBoth: {										\
				offsets_Procedure__ = sprite_or_rects_collision_function(			\
					(ptr_float_rectangle),											\
					(ptr_sprites_or_rects),											\
					distance_x_Procedure__,											\
					distance_y_Procedure__,											\
					1, 1															\
				);																	\
				break;																\
			}																		\
			default:																\
				i_Procedure__++;													\
				continue;															\
		}																			\
		res_offsets_Procedure__->x += offsets_Procedure__.x;						\
		res_offsets_Procedure__->y += offsets_Procedure__.y;						\
		i_Procedure__++;															\
	}																				\
}


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
 * It doesn't work perfectly, but it's the best I've come up with.
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
 * Resolves collisions between rectangle 'self'
 *and rectangle group.
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
 * It doesn't work perfectly, but it's the best I've come up with.
 */
MOON_CSFML_API moon_Vector2f
moon_Collisions_rectangles_collision(
	moon_FloatRect* self,
	const moon_FRectLst* rectangles,
	float distance_x,
	float distance_y,
	int resolve_horizontal,
	int resolve_vertical
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
 * 'which_collisions' must contain characters which collisions
 *need to resolve, example: "vh" -- first it resolves vertical, then horizontal.
 * v -- resolve vertical;
 * h -- resolve horizontal;
 * x -- resolve both, not recommended;
 * 'which_collisions' must be null-terminated.
 *
 * It doesn't work perfectly, but it's the best I've come up with.
 */
MOON_CSFML_API moon_Vector2f
moon_Collisions_sprites_collision_many(
	moon_FloatRect* self,
	const moon_SpriteGroup* sprites,
	float distance_x,
	float distance_y,
	const char* which_collisions
);

/**
 * Resolves collisions between rectangle 'self'
 *and rectangle group.
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
 * 'which_collisions' must contain characters which collisions
 *need to resolve, example: "vh" -- first it resolves vertical, then horizontal.
 * 'which_collisions' must be null-terminated.
 *
 * It doesn't work perfectly, but it's the best I've come up with.
 */
MOON_CSFML_API moon_Vector2f
moon_Collisions_rectangles_collision_many(
	moon_FloatRect* self,
	const moon_FRectLst* rectangles,
	float distance_x,
	float distance_y,
	const char* which_collisions
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

/**
 * Returns 1 if rectangle 'self' collides
 *with any rectangle in rectangle list.
 * Otherwise, returns 0.
 */
MOON_CSFML_API int
moon_Collisions_is_any_frect_collision(
	const moon_FloatRect* self,
	const moon_FRectLst* rectangles
);


#ifdef __cplusplus
}
#endif


#endif
