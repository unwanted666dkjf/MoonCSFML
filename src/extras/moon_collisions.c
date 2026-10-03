#include "../../headers/system/moon_utils.h"


#include "../../headers/extras/moon_collisions.h"


static void
moon_Collisions_shift_collision(
	moon_Vector2f* res_offsets,
	moon_FloatRect* self,
	const moon_FloatRect* bound,
	const float* distance_x,
	const float* distance_y,
	const int* resolve_horizontal,
	const int* resolve_vertical
);


float
moon_Collisions_resolve_vertical(
	const moon_FloatRect* self,
	const moon_FloatRect* other
) {
	float self_bottom 	= self->top + self->height;
	float other_bottom 	= other->top + other->height;

	if (self_bottom <= other->top || self->top >= other_bottom) {
		return 0.f;
	}

	float dbot = other->top - self_bottom;
	float dtop = other_bottom - self->top;

	if (moon_utils_Abs(dtop) < moon_utils_Abs(dbot)) {
		return dtop;
	}
	return dbot;
}

float
moon_Collisions_resolve_horizontal(
	const moon_FloatRect* self,
	const moon_FloatRect* other
) {
	float self_right 	= self->left + self->width;
	float other_right 	= other->left + other->width;

	if (self->left >= other_right || self_right <= other->left) {
		return 0.f;
	}

	float dleft 	= other_right - self->left;
	float dright 	= other->left - self_right;

	if (moon_utils_Abs(dleft) < moon_utils_Abs(dright)) {
		return dleft;
	}
	return dright;
}

moon_Vector2f
moon_Collisions_resolve_collisions(
	moon_FloatRect* self,
	const moon_FloatRect* other
) {
	moon_Vector2f offsets = {0.f, 0.f};

	float dy = moon_Collisions_resolve_vertical(self, other);
	self->top 	+= dy;
	offsets.y 	+= dy;

	float dx = moon_Collisions_resolve_horizontal(self, other);
	self->left 	+= dx;
	offsets.x 	+= dx;
	moon_FloatRect intersection = moon_FloatRect_get_intersection(self, other);
	if (moon_FloatRect_is_empty(&intersection)) {
		return offsets;
	}

	dy = moon_Collisions_resolve_vertical(self, other);
	self->top 	+= dy;
	offsets.y 	+= dy;

	return offsets;
}

moon_Vector2f
moon_Collisions_sprites_collision(
	moon_FloatRect* self,
	const moon_SpriteGroup* sprites,
	float distance_x,
	float distance_y,
	int resolve_horizontal,
	int resolve_vertical
) {
	moon_Vector2f res_offsets = {0.f, 0.f};
	if (!(resolve_vertical || resolve_horizontal)) {
		return res_offsets;
	}
	for (unsigned long i = 0UL; i < moon_SpriteGroup_length(sprites); i++) {
		moon_FloatRect bound = moon_SpriteGroup_get_global_bounds(sprites, i);
		moon_Collisions_shift_collision(
			&res_offsets,
			self, &bound,
			&distance_x, &distance_y,
			&resolve_horizontal, &resolve_vertical
		);
	}
	return res_offsets;
}

moon_Vector2f
moon_Collisions_rectangles_collision(
	moon_FloatRect* self,
	const moon_FRectLst* rectangles,
	float distance_x,
	float distance_y,
	int resolve_horizontal,
	int resolve_vertical
) {
	moon_Vector2f res_offsets = {0.f, 0.f};
	if (!(resolve_vertical || resolve_horizontal)) {
		return res_offsets;
	}
	for (unsigned long i = 0UL; i < moon_FRectLst_length(rectangles); i++) {
		const moon_FloatRect* bound = moon_FRectLst_read(rectangles, i);
		moon_Collisions_shift_collision(
			&res_offsets,
			self, bound,
			&distance_x, &distance_y,
			&resolve_horizontal, &resolve_vertical
		);
	}
	return res_offsets;
}

moon_Vector2f
moon_Collisions_sprites_collision_many(
	moon_FloatRect* self,
	const moon_SpriteGroup* sprites,
	float distance_x,
	float distance_y,
	const char* which_collisions
) {
	moon_Vector2f res_offsets = {0.f, 0.f};
	moon_Collisions_Procedure_CollisionMany(
		res_offsets,
		self,
		sprites,
		distance_x,
		distance_y,
		which_collisions,
		moon_Collisions_sprites_collision
	);
	return res_offsets;
}

moon_Vector2f
moon_Collisions_rectangles_collision_many(
	moon_FloatRect* self,
	const moon_FRectLst* rectangles,
	float distance_x,
	float distance_y,
	const char* which_collisions
) {
	moon_Vector2f res_offsets = {0.f, 0.f};
	moon_Collisions_Procedure_CollisionMany(
		res_offsets,
		self,
		rectangles,
		distance_x,
		distance_y,
		which_collisions,
		moon_Collisions_rectangles_collision
	);
	return res_offsets;
}

int
moon_Collisions_is_any_collision(
	const moon_FloatRect* self,
	const moon_SpriteGroup* sprites
) {
	int res = 0;
	for (unsigned long i = 0UL; i < moon_SpriteGroup_length(sprites); i++) {
		moon_FloatRect bound = moon_SpriteGroup_get_global_bounds(sprites, i);
		moon_FloatRect intersection = moon_FloatRect_get_intersection(self, &bound);
		if (!moon_FloatRect_is_empty(&intersection)) {
			res = 1;
			break;
		}
	}
	return res;
}

int
moon_Collisions_is_any_frect_collision(
	const moon_FloatRect* self,
	const moon_FRectLst* rectangles
) {
	int res = 0;
	for (unsigned long i = 0UL; i < moon_FRectLst_length(rectangles); i++) {
		const moon_FloatRect* bound = moon_FRectLst_read(rectangles, i);
		moon_FloatRect intersection = moon_FloatRect_get_intersection(self, bound);
		if (!moon_FloatRect_is_empty(&intersection)) {
			res = 1;
			break;
		}
	}
	return res;
}


void
moon_Collisions_shift_collision(
	moon_Vector2f* res_offsets,
	moon_FloatRect* self,
	const moon_FloatRect* bound,
	const float* distance_x,
	const float* distance_y,
	const int* resolve_horizontal,
	const int* resolve_vertical
) {
	if ((*distance_x) > moon_Collisions_UnlimitedDistance) {
		float self_centerx 	= self->left  + self->width * .5f;
		float bound_centerx = bound->left + bound->width * .5f;
		float dl = self_centerx - bound_centerx;
		float distance = moon_utils_Abs(dl);
		if (distance >= (*distance_x)) {
			return;
		}
	}
	if ((*distance_y) > moon_Collisions_UnlimitedDistance) {
		float self_centery 	= self->top  + self->height * .5f;
		float bound_centery = bound->top + bound->height * .5f;
		float dh = self_centery - bound_centery;
		float distance = moon_utils_Abs(dh);
		if (distance >= (*distance_y)) {
			return;
		}
	}
	moon_FloatRect intersection = moon_FloatRect_get_intersection(self, bound);
	if (moon_FloatRect_is_empty(&intersection)) {
		return;
	}
	if ((*resolve_vertical) && (*resolve_horizontal)) {
		moon_Vector2f offsets = moon_Collisions_resolve_collisions(self, bound);
		res_offsets->x += offsets.x;
		res_offsets->y += offsets.y;
	} else if ((*resolve_vertical)) {
		float dy = moon_Collisions_resolve_vertical(self, bound);
		self->top 		+= dy;
		res_offsets->y 	+= dy;
	} else {
		float dx = moon_Collisions_resolve_horizontal(self, bound);
		self->left 		+= dx;
		res_offsets->x 	+= dx;
	}
}
