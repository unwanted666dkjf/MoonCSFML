#include <vector>



#include "../../headers/extras/GenericDraw.hpp"

#include "../../headers/extras/moon_sprite_group.h"

#include "../../headers/extras/moon_sprite_transform.h"


#include "../../headers/graphics/VectorUtils.hpp"

#include "../../headers/graphics/SpriteStruct.hpp"


struct moon_SpriteGroup {

	moon_SpriteGroup(
		int v_check_visibility,
		unsigned long v_initial_capacity
	);


	int check_visibility;
	std::vector<moon_Sprite*> sprites;

};


moon_SpriteGroup*
moon_SpriteGroup_create(
	int check_visibility,
	unsigned long initial_capacity
) {
	return new moon_SpriteGroup(
		check_visibility,
		initial_capacity
	);
}

void
moon_SpriteGroup_destroy(moon_SpriteGroup* self) {
	delete self;
}

void
moon_SpriteGroup_set_color(
	const moon_SpriteGroup* self,
	const moon_Color* color
) {
	for (unsigned long i = 0UL; i < self->sprites.size(); i++) {
		moon_Sprite_set_color(self->sprites[i], color);
	}
}

moon_FloatRect
moon_SpriteGroup_get_world_bounds(
	const moon_SpriteGroup* self,
	unsigned long index
) {
	return moon_Sprite_get_world_bounds(self->sprites[index]);
}

moon_FloatRect
moon_SpriteGroup_get_local_bounds(
	const moon_SpriteGroup* self,
	unsigned long index
) {
	return moon_Sprite_get_local_bounds(self->sprites[index]);
}

moon_FloatRect
moon_SpriteGroup_get_global_bounds(
	const moon_SpriteGroup* self,
	unsigned long index
) {
	return moon_Sprite_get_global_bounds(self->sprites[index]);
}

moon_FRectLst*
moon_SpriteGroup_get_rectangles(
	const moon_SpriteGroup* self,
	int as_global_bounds
) {
	moon_FRectLst* rects = moon_FRectLst_create(self->sprites.size());
	for (unsigned long i = 0UL; i < self->sprites.size(); i++) {
		if (as_global_bounds) {
			moon_FloatRect bounds = moon_Sprite_get_global_bounds(self->sprites[i]);
			moon_FRectLst_push_back(rects, &bounds);
		} else {
			moon_FloatRect bounds = moon_Sprite_get_local_bounds(self->sprites[i]);
			moon_FRectLst_push_back(rects, &bounds);
		}
	}
	return rects;
}

// moon_SpriteTransform begin.

void
moon_SpriteGroup_flipX(
	const moon_SpriteGroup* self,
	int flip_x, int flip_y
) {
	for (unsigned long i = 0UL; i < self->sprites.size(); i++) {
		moon_SpriteTransform_flip(self->sprites[i], flip_x, flip_y);
	}
}

void
moon_SpriteGroup_rotateX(
	const moon_SpriteGroup* self,
	moon_Angle angle
) {
	for (unsigned long i = 0UL; i < self->sprites.size(); i++) {
		moon_SpriteTransform_rotate(self->sprites[i], angle);
	}
}

void
moon_SpriteGroup_set_rotationX(
	const moon_SpriteGroup* self,
	moon_Angle angle
) {
	for (unsigned long i = 0UL; i < self->sprites.size(); i++) {
		moon_SpriteTransform_set_rotation(self->sprites[i], angle);
	}
}

void
moon_SpriteGroup_copy_transformX(
	const moon_SpriteGroup* self,
	const moon_Sprite* source
) {
	for (unsigned long i = 0UL; i < self->sprites.size(); i++) {
		moon_SpriteTransform_copy_transform(self->sprites[i], source);
	}
}

// moon_SpriteTransform end.

// Sprite begin.

void
moon_SpriteGroup_set_position(
	const moon_SpriteGroup* self,
	float left, float top
) {
	for (unsigned long i = 0UL; i < self->sprites.size(); i++) {
		moon_Sprite_set_position(self->sprites[i], left, top);
	}
}

void
moon_SpriteGroup_set_rotation(
	const moon_SpriteGroup* self,
	moon_Angle angle
) {
	for (unsigned long i = 0UL; i < self->sprites.size(); i++) {
		moon_Sprite_set_rotation(self->sprites[i], angle);
	}
}

void
moon_SpriteGroup_set_scale(
	const moon_SpriteGroup* self,
	float scale_x, float scale_y
) {
	for (unsigned long i = 0UL; i < self->sprites.size(); i++) {
		moon_Sprite_set_scale(self->sprites[i], scale_x, scale_y);
	}
}

void
moon_SpriteGroup_set_origin(
	const moon_SpriteGroup* self,
	float x, float y
) {
	for (unsigned long i = 0UL; i < self->sprites.size(); i++) {
		moon_Sprite_set_origin(self->sprites[i], x, y);
	}
}

void
moon_SpriteGroup_move(
	const moon_SpriteGroup* self,
	float dx, float dy
) {
	for (unsigned long i = 0UL; i < self->sprites.size(); i++) {
		moon_Sprite_move(self->sprites[i], dx, dy);
	}
}

void
moon_SpriteGroup_rotate(
	const moon_SpriteGroup* self,
	moon_Angle angle
) {
	for (unsigned long i = 0UL; i < self->sprites.size(); i++) {
		moon_Sprite_rotate(self->sprites[i], angle);
	}
}

void
moon_SpriteGroup_scale(
	const moon_SpriteGroup* self,
	float scale_x, float scale_y
) {
	for (unsigned long i = 0UL; i < self->sprites.size(); i++) {
		moon_Sprite_scale(self->sprites[i], scale_x, scale_y);
	}
}

// Sprite end.

//DrawGroup begin.

int
moon_SpriteGroup_is_empty(const moon_SpriteGroup* self) {
	return self->sprites.empty();
}

int
moon_SpriteGroup_is_check_enabled(const moon_SpriteGroup* self) {
	return self->check_visibility;
}

int
moon_SpriteGroup_resize(
	moon_SpriteGroup* self,
	unsigned long new_size
) {
	if (new_size <= self->sprites.size()) {
		return 0;
	}
	self->sprites.resize(new_size);
	return 1;
}

int
moon_SpriteGroup_reserve(
	moon_SpriteGroup* self,
	unsigned long capacity
) {
	if (capacity <= self->sprites.capacity()) {
		return 0;
	}
	self->sprites.reserve(capacity);
	return 1;
}

unsigned long
moon_SpriteGroup_size(const moon_SpriteGroup* self) {
	return self->sprites.capacity();
}

unsigned long
moon_SpriteGroup_length(const moon_SpriteGroup* self) {
	return self->sprites.size();
}

void
moon_SpriteGroup_clear(moon_SpriteGroup* self) {
	self->sprites.clear();
}

void
moon_SpriteGroup_reverse(moon_SpriteGroup* self) {
	moon_vector_reverse<moon_Sprite*>(self->sprites);
}

void
moon_SpriteGroup_set_check_enabled(
	moon_SpriteGroup* self,
	int check_visibility
) {
	self->check_visibility = check_visibility;
}

void
moon_SpriteGroup_remove(
	moon_SpriteGroup* self,
	unsigned long index
) {
	moon_vector_remove<moon_Sprite*>(self->sprites, index);
}

void
moon_SpriteGroup_draw(
	const moon_SpriteGroup* self,
	moon_RenderWindow* wnd,
	const moon_RenderStates* states
) {
	for (unsigned long i = 0UL; i < self->sprites.size(); i++) {
		moon_generic_draw<moon_Sprite>(
			self->sprites[i],
			wnd,
			states,
			self->check_visibility
		);
	}
}

void
moon_SpriteGroup_push_back(
	moon_SpriteGroup* self,
	moon_Sprite* sprite
) {
	self->sprites.push_back(sprite);
}

void
moon_SpriteGroup_push_front(
	moon_SpriteGroup* self,
	moon_Sprite* sprite
) {
	moon_vector_insert<moon_Sprite*>(self->sprites, 0UL, sprite);
}

void
moon_SpriteGroup_extend(
	moon_SpriteGroup* self,
	const moon_SpriteGroup* other
) {
	moon_vector_extend<moon_Sprite*>(
		self->sprites,
		other->sprites
	);
}

moon_SpriteGroup*
moon_SpriteGroup_get_slice(
	const moon_SpriteGroup* self,
	long long start,
	long long stop,
	long long step
) {
	moon_SpriteGroup* slice = moon_SpriteGroup_create(
		self->check_visibility,
		0UL
	);
	slice->sprites = moon_vector_slice<moon_Sprite*>(
		self->sprites,
		start,
		stop,
		step
	);
	return slice;
}

// DrawGroup end.


moon_Sprite*
moon_SpriteGroup_get(
	const moon_SpriteGroup* self,
	unsigned long index
) {
	return self->sprites[index];
}


moon_SpriteGroup::moon_SpriteGroup(
	int v_check_visibility,
	unsigned long v_initial_capacity
) {
	check_visibility = v_check_visibility;
	sprites.reserve(v_initial_capacity + 1UL);
}
