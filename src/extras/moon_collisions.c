#include "../../headers/system/moon_utils.h"


#include "../../headers/extras/moon_collisions.h"


static int
moon_Collisions_dist_intersection(
	const moon_FloatRect* self,
	const moon_FloatRect* other,
	const float* distance_x,
	const float* distance_y
);

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
moon_Collisions_is_collide(
	const moon_FloatRect* self,
	const moon_FloatRect* other
) {
	moon_FloatRect intersection = moon_FloatRect_get_intersection(self, other);
	return !moon_FloatRect_is_empty(&intersection);
}

int
moon_Collisions_is_collide_ex(
	const moon_FloatRect* self,
	const moon_FloatRect* other,
	float distance_x,
	float distance_y
) {
	return moon_Collisions_dist_intersection(
		self, other,
		&distance_x,
		&distance_y
	);
}

moon_FRectLst*
moon_Collisions_rects_collide(
	const moon_FloatRect* self,
	moon_FRectLst* rectangles,
	float distance_x,
	float distance_y,
	int remove_collided
) {
	moon_FRectLst* res = moon_FRectLst_create(moon_FRectLst_InitialCapacity);
	for (unsigned long i = 0UL; i < moon_FRectLst_length(rectangles);) {
		const moon_FloatRect* bound = moon_FRectLst_read(rectangles, i);
		if (
			!moon_Collisions_dist_intersection(
				self, bound,
				&distance_x,
				&distance_y
			)
		) {
			i++;
			continue;
		}
		moon_FRectLst_push_back(res, bound);
		if (remove_collided) {
			moon_FRectLst_pop(rectangles, i);
		} else {
			i++;
		}
	}
	return res;
}

moon_SpriteGroup*
moon_Collisions_sprites_collide(
	const moon_FloatRect* self,
	moon_SpriteGroup* sprites,
	float distance_x,
	float distance_y,
	int remove_collided
) {
	moon_SpriteGroup* res = moon_SpriteGroup_create(
		moon_SpriteGroup_is_check_enabled(sprites),
		moon_SpriteGroup_InitialCapacity
	);
	for (unsigned long i = 0UL; i < moon_SpriteGroup_length(sprites);) {
		moon_FloatRect bound = moon_SpriteGroup_get_global_bounds(sprites, i);
		if (
			!moon_Collisions_dist_intersection(
				self, &bound,
				&distance_x,
				&distance_y
			)
		) {
			i++;
			continue;
		}
		moon_SpriteGroup_push_back(res, moon_SpriteGroup_get(sprites, i));
		if (remove_collided) {
			moon_SpriteGroup_remove(sprites, i);
		} else {
			i++;
		}
	}
	return res;
}

moon_FRectLst*
moon_Collisions_rects_groupcollide(
	moon_FRectLst* group1,
	const moon_FRectLst* group2,
	int remove_collided
) {
	moon_FRectLst* res = moon_FRectLst_create(moon_FRectLst_InitialCapacity);
	for (unsigned long i = 0UL; i < moon_FRectLst_length(group1);) {
		const moon_FloatRect* bound = moon_FRectLst_read(group1, i);
		if (!moon_Collisions_is_any_frect_collision(bound, group2)) {
			i++;
			continue;
		}
		moon_FRectLst_push_back(res, bound);
		if (remove_collided) {
			moon_FRectLst_pop(group1, i);
		} else {
			i++;
		}
	}
	return res;
}

moon_SpriteGroup*
moon_Collisions_sprites_groupcollide(
	moon_SpriteGroup* group1,
	const moon_SpriteGroup* group2,
	int remove_collided
) {
	moon_SpriteGroup* res = moon_SpriteGroup_create(
		moon_SpriteGroup_is_check_enabled(group1),
		moon_SpriteGroup_InitialCapacity
	);
	for (unsigned long i = 0UL; i < moon_SpriteGroup_length(group1);) {
		moon_FloatRect bound = moon_SpriteGroup_get_global_bounds(group1, i);
		if (!moon_Collisions_is_any_collision(&bound, group2)) {
			i++;
			continue;
		}
		moon_SpriteGroup_push_back(res, moon_SpriteGroup_get(group1, i));
		if (remove_collided) {
			moon_SpriteGroup_remove(group1, i);
		} else {
			i++;
		}
	}
	return res;
}

int
moon_Collisions_rects_deadly_groupcollide(
	moon_FRectLst* group1,
	moon_FRectLst* group2,
	int remove_collided1,
	int remove_collided2
) {
	moon_FRectLst* gr1_collided;
	if (remove_collided1) {
		gr1_collided = moon_Collisions_rects_groupcollide(group1, group2, 1);
	} else {
		gr1_collided = moon_Collisions_rects_groupcollide(group1, group2, 0);
	}
	if (moon_FRectLst_is_empty(gr1_collided)) {
		moon_FRectLst_destroy(gr1_collided);
		return 0;
	}
	moon_FRectLst* tmp;
	if (remove_collided2) {
		tmp = moon_Collisions_rects_groupcollide(group2, gr1_collided, 1);
	} else {
		tmp = moon_Collisions_rects_groupcollide(group2, gr1_collided, 0);
	}
	moon_FRectLst_destroy(tmp);
	moon_FRectLst_destroy(gr1_collided);
	return 1;
}

int
moon_Collisions_sprites_deadly_groupcollide(
	moon_SpriteGroup* group1,
	moon_SpriteGroup* group2,
	int remove_collided1,
	int remove_collided2
) {
	moon_SpriteGroup* gr1_collided;
	if (remove_collided1) {
		gr1_collided = moon_Collisions_sprites_groupcollide(group1, group2, 1);
	} else {
		gr1_collided = moon_Collisions_sprites_groupcollide(group1, group2, 0);
	}
	if (moon_SpriteGroup_is_empty(gr1_collided)) {
		moon_SpriteGroup_destroy(gr1_collided);
		return 0;
	}
	moon_SpriteGroup* tmp;
	if (remove_collided2) {
		tmp = moon_Collisions_sprites_groupcollide(group2, gr1_collided, 1);
	} else {
		tmp = moon_Collisions_sprites_groupcollide(group2, gr1_collided, 0);
	}
	moon_SpriteGroup_destroy(tmp);
	moon_SpriteGroup_destroy(gr1_collided);
	return 1;
}

int
moon_Collisions_is_any_collision(
	const moon_FloatRect* self,
	const moon_SpriteGroup* sprites
) {
	int res = 0;
	for (unsigned long i = 0UL; i < moon_SpriteGroup_length(sprites); i++) {
		moon_FloatRect bound = moon_SpriteGroup_get_global_bounds(sprites, i);
		if (moon_Collisions_is_collide(self, &bound)) {
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
		if (moon_Collisions_is_collide(self, bound)) {
			res = 1;
			break;
		}
	}
	return res;
}


int
moon_Collisions_dist_intersection(
	const moon_FloatRect* self,
	const moon_FloatRect* other,
	const float* distance_x,
	const float* distance_y
) {
	if ((*distance_x) > moon_Collisions_UnlimitedDistance) {
		float self_centerx  = self->left  + self->width * .5f;
		float other_centerx = other->left + other->width * .5f;
		float distx = self_centerx - other_centerx;
		if (moon_utils_Abs(distx) >= (*distance_x)) {
			return 0;
		}
	}
	if ((*distance_y) > moon_Collisions_UnlimitedDistance) {
		float self_centery  = self->top  + self->height * .5f;
		float other_centery = other->top + other->height * .5f;
		float disty = self_centery - other_centery;
		if (moon_utils_Abs(disty) >= (*distance_y)) {
			return 0;
		}
	}
	return moon_Collisions_is_collide(self, other);
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
	if (
		!moon_Collisions_dist_intersection(
			self, bound,
			distance_x,
			distance_y
		)
	) {
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
