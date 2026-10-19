#include "../../headers/extras/moon_sprite_array.h"

#include "../../headers/extras/GraphicsGroup.hpp"


struct moon_SpriteArray {
	moon_GraphicsGroup_HEAD(moon_Sprite)
};


moon_SpriteArray*
moon_SpriteArray_create(
	int check_visibility,
	unsigned long initial_capacity
) {
	return moon_GraphicsGroup_create<moon_SpriteArray>(
		check_visibility,
		initial_capacity
	);
}

void
moon_SpriteArray_destroy(moon_SpriteArray* self) {
	moon_GraphicsGroup_destroy<moon_SpriteArray>(self);
}

moon_SpriteArray*
moon_SpriteArray_get_slice(
	const moon_SpriteArray* self,
	long long start,
	long long stop,
	long long step
) {
	return moon_GraphicsGroup_get_slice<moon_SpriteArray, moon_Sprite>(
		self,
		start,
		stop,
		step
	);
}

int
moon_SpriteArray_is_empty(const moon_SpriteArray* self) {
	return moon_GraphicsGroup_is_empty<moon_SpriteArray>(self);
}

int
moon_SpriteArray_is_check_enabled(const moon_SpriteArray* self) {
	return moon_GraphicsGroup_is_check_enabled<moon_SpriteArray>(self);
}

int
moon_SpriteArray_resize(
	moon_SpriteArray* self,
	unsigned long new_size
) {
	return moon_GraphicsGroup_resize<moon_SpriteArray>(self, new_size);
}

int
moon_SpriteArray_reserve(
	moon_SpriteArray* self,
	unsigned long new_capacity
) {
	return moon_GraphicsGroup_reserve<moon_SpriteArray>(self, new_capacity);
}

unsigned long
moon_SpriteArray_get_size(const moon_SpriteArray* self) {
	return moon_GraphicsGroup_get_size<moon_SpriteArray>(self);
}

unsigned long
moon_SpriteArray_get_length(const moon_SpriteArray* self) {
	return moon_GraphicsGroup_get_length<moon_SpriteArray>(self);
}

void
moon_SpriteArray_clear(moon_SpriteArray* self) {
	moon_GraphicsGroup_clear<moon_SpriteArray>(self);
}

void
moon_SpriteArray_reverse(
	moon_SpriteArray* self,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_reverse<moon_SpriteArray>(self, first_index, num_elements);
}

void
moon_SpriteArray_remove(
	moon_SpriteArray* self,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_remove<moon_SpriteArray>(self, first_index, num_elements);
}

void
moon_SpriteArray_push_back(
	moon_SpriteArray* self,
	moon_Sprite* element
) {
	moon_GraphicsGroup_push_back<moon_SpriteArray, moon_Sprite>(self, element);
}

void
moon_SpriteArray_insert(
	moon_SpriteArray* self,
	unsigned long index,
	moon_Sprite* element
) {
	moon_GraphicsGroup_insert<moon_SpriteArray, moon_Sprite>(self, index, element);
}

void
moon_SpriteArray_extend(
	moon_SpriteArray* self,
	const moon_SpriteArray* other,
	unsigned long other_first_index,
	unsigned long other_num_elements
) {
	moon_GraphicsGroup_extend<moon_SpriteArray>(
		self,
		other,
		other_first_index,
		other_num_elements
	);
}

void
moon_SpriteArray_set_check_enabled(
	moon_SpriteArray* self,
	int check_visibility
) {
	moon_GraphicsGroup_set_check_enabled<moon_SpriteArray>(self, check_visibility);
}

moon_Sprite*
moon_SpriteArray_set(
	moon_SpriteArray* self,
	unsigned long index,
	moon_Sprite* element
) {
	return moon_GraphicsGroup_set<moon_SpriteArray, moon_Sprite>(self, index, element);
}

moon_Sprite*
moon_SpriteArray_pop(
	moon_SpriteArray* self,
	unsigned long index
) {
	return moon_GraphicsGroup_pop<moon_SpriteArray, moon_Sprite>(self, index);
}

moon_Sprite*
moon_SpriteArray_get(
	moon_SpriteArray* self,
	unsigned long index
) {
	return moon_GraphicsGroup_get<moon_SpriteArray, moon_Sprite>(self, index);
}

void
moon_SpriteArray_draw(
	const moon_SpriteArray* self,
	moon_RenderWindow* wnd,
	moon_RenderStates* states,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_draw(
		self,
		wnd,
		states,
		first_index,
		num_elements,
		moon_Sprite_get_global_bounds,
		moon_Sprite_draw
	)
}

void
moon_SpriteArray_set_color(
	const moon_SpriteArray* self,
	const moon_Color* color,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_color(
		self,
		color,
		first_index,
		num_elements,
		moon_Sprite_set_color
	)
}

long long
moon_SpriteArray_find_alpha(
	const moon_SpriteArray* self,
	unsigned char alpha,
	unsigned long first_index,
	unsigned long num_elements
) {
	long long res;
	moon_GraphicsGroup_Procedure_find_alpha(
		self,
		res,
		first_index,
		num_elements,
		alpha,
		moon_Sprite_get_color
	)
	return res;
}

long long
moon_SpriteArray_find_color(
	const moon_SpriteArray* self,
	const moon_Color* color,
	int ignore_alpha,
	unsigned long first_index,
	unsigned long num_elements
) {
	long long res;
	moon_GraphicsGroup_Procedure_find_color(
		self,
		res,
		first_index,
		num_elements,
		color,
		ignore_alpha,
		moon_Sprite_get_color
	)
	return res;
}

void
moon_SpriteArray_inverse_color(
	const moon_SpriteArray* self,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_inverse_color(
		self,
		first_index,
		num_elements,
		moon_Sprite_set_color,
		moon_Sprite_get_color
	)
}

void
moon_SpriteArray_set_alpha(
	const moon_SpriteArray* self,
	unsigned char alpha,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_alpha(
		self,
		alpha,
		first_index,
		num_elements,
		moon_Sprite_set_color,
		moon_Sprite_get_color
	)
}

moon_FRectLst*
moon_SpriteArray_get_bounds(
	const moon_SpriteArray* self,
	int bounds_type,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_FRectLst* res = nullptr;
	moon_GraphicsGroup_Procedure_get_bounds(
		self,
		res,
		first_index,
		num_elements,
		bounds_type,
		moon_Sprite_get_global_bounds,
		moon_Sprite_get_local_bounds,
		moon_Sprite_get_world_bounds
	)
	return res;
}

long long
moon_SpriteArray_find_elsize(
	const moon_SpriteArray* self,
	const moon_Vector2f* size,
	unsigned long first_index,
	unsigned long num_elements
) {
	long long res;
	moon_GraphicsGroup_find_vector2f(
		self,
		res,
		first_index,
		num_elements,
		size,
		moon_Sprite_get_size
	)
	return res;
}

long long
moon_SpriteArray_get_elsize(
	const moon_SpriteArray* self,
	int is_get_min, int is_get_y,
	unsigned long first_index,
	unsigned long num_elements
) {
	long long res;
	moon_GraphicsGroup_Procedure_get_vector2f(
		self,
		res,
		first_index,
		num_elements,
		is_get_min,
		is_get_y,
		moon_Sprite_get_size
	)
	return res;
}

long long
moon_SpriteArray_find_elscale(
	const moon_SpriteArray* self,
	const moon_Vector2f* scale,
	unsigned long first_index,
	unsigned long num_elements
) {
	long long res;
	moon_GraphicsGroup_find_vector2f(
		self,
		res,
		first_index,
		num_elements,
		scale,
		moon_Sprite_get_scale
	)
	return res;
}

long long
moon_SpriteArray_get_elscale(
	const moon_SpriteArray* self,
	int is_get_min, int is_get_y,
	unsigned long first_index,
	unsigned long num_elements
) {
	long long res;
	moon_GraphicsGroup_Procedure_get_vector2f(
		self,
		res,
		first_index,
		num_elements,
		is_get_min,
		is_get_y,
		moon_Sprite_get_scale
	)
	return res;
}

void
moon_SpriteArray_set_elscale(
	const moon_SpriteArray* self,
	float scale_x, float scale_y,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_vector2f(
		self,
		first_index,
		num_elements,
		scale_x, scale_y,
		moon_Sprite_set_scale
	)
}

void
moon_SpriteArray_elscale(
	const moon_SpriteArray* self,
	float scale_x, float scale_y,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_vector2f(
		self,
		first_index,
		num_elements,
		scale_x, scale_y,
		moon_Sprite_scale
	)
}

long long
moon_SpriteArray_find_elposition(
	const moon_SpriteArray* self,
	const moon_Vector2f* position,
	unsigned long first_index,
	unsigned long num_elements
) {
	long long res;
	moon_GraphicsGroup_find_vector2f(
		self,
		res,
		first_index,
		num_elements,
		position,
		moon_Sprite_get_position
	)
	return res;
}

long long
moon_SpriteArray_get_elposition(
	const moon_SpriteArray* self,
	int is_get_min, int is_get_y,
	unsigned long first_index,
	unsigned long num_elements
) {
	long long res;
	moon_GraphicsGroup_Procedure_get_vector2f(
		self,
		res,
		first_index,
		num_elements,
		is_get_min,
		is_get_y,
		moon_Sprite_get_position
	)
	return res;
}

void
moon_SpriteArray_randomize_elposition(
	const moon_SpriteArray* self,
	int min_x, int max_x,
	int min_y, int max_y,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_randomize_vector2f(
		self,
		first_index,
		num_elements,
		min_x, max_x,
		min_y, max_y,
		moon_Sprite_set_position
	)
}

void
moon_SpriteArray_set_elposition(
	const moon_SpriteArray* self,
	float x, float y,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_vector2f(
		self,
		first_index,
		num_elements,
		x, y,
		moon_Sprite_set_position
	)
}

void
moon_SpriteArray_elmove(
	const moon_SpriteArray* self,
	float dx, float dy,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_vector2f(
		self,
		first_index,
		num_elements,
		dx, dy,
		moon_Sprite_move
	)
}

long long
moon_SpriteArray_find_elorigin(
	const moon_SpriteArray* self,
	const moon_Vector2f* origin,
	unsigned long first_index,
	unsigned long num_elements
) {
	long long res;
	moon_GraphicsGroup_find_vector2f(
		self,
		res,
		first_index,
		num_elements,
		origin,
		moon_Sprite_get_origin
	)
	return res;
}

long long
moon_SpriteArray_get_elorigin(
	const moon_SpriteArray* self,
	int is_get_min, int is_get_y,
	unsigned long first_index,
	unsigned long num_elements
) {
	long long res;
	moon_GraphicsGroup_Procedure_get_vector2f(
		self,
		res,
		first_index,
		num_elements,
		is_get_min,
		is_get_y,
		moon_Sprite_get_origin
	)
	return res;
}

void
moon_SpriteArray_randomize_elorigin(
	const moon_SpriteArray* self,
	int min_x, int max_x,
	int min_y, int max_y,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_randomize_vector2f(
		self,
		first_index,
		num_elements,
		min_x, max_x,
		min_y, max_y,
		moon_Sprite_set_origin
	)
}

void
moon_SpriteArray_set_elorigin(
	const moon_SpriteArray* self,
	float origin_x, float origin_y,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_vector2f(
		self,
		first_index,
		num_elements,
		origin_x, origin_y,
		moon_Sprite_set_origin
	)
}

long long
moon_SpriteArray_find_elrotation(
	const moon_SpriteArray* self,
	moon_Angle angle,
	unsigned long first_index,
	unsigned long num_elements
) {
	long long res;
	moon_GraphicsGroup_Procedure_find_value(
		self,
		res,
		first_index,
		num_elements,
		angle,
		moon_Sprite_get_rotation
	)
	return res;
}

long long
moon_SpriteArray_get_elrotation(
	const moon_SpriteArray* self,
	int is_get_min,
	unsigned long first_index,
	unsigned long num_elements
) {
	long long res;
	moon_GraphicsGroup_Procedure_get_value(
		self,
		res,
		first_index,
		num_elements,
		is_get_min,
		moon_Sprite_get_rotation
	)
	return res;
}

void
moon_SpriteArray_randomize_elrotation(
	const moon_SpriteArray* self,
	int min_angle, int max_angle,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_randomize_value(
		self,
		first_index,
		num_elements,
		min_angle, max_angle,
		moon_Sprite_set_rotation
	)
}

void
moon_SpriteArray_set_elrotation(
	const moon_SpriteArray* self,
	moon_Angle angle,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_value(
		self,
		first_index,
		num_elements,
		angle,
		moon_Sprite_set_rotation
	)
}

void
moon_SpriteArray_elrotate(
	const moon_SpriteArray* self,
	moon_Angle angle,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_value(
		self,
		first_index,
		num_elements,
		angle,
		moon_Sprite_rotate
	)
}
