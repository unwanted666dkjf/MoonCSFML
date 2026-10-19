#include "../../headers/extras/moon_text_array.h"

#include "../../headers/extras/GraphicsGroup.hpp"


struct moon_TextArray {
	moon_GraphicsGroup_HEAD(moon_Text)
};


moon_TextArray*
moon_TextArray_create(
	int check_visibility,
	unsigned long initial_capacity
) {
	return moon_GraphicsGroup_create<moon_TextArray>(
		check_visibility,
		initial_capacity
	);
}

void
moon_TextArray_destroy(moon_TextArray* self) {
	moon_GraphicsGroup_destroy<moon_TextArray>(self);
}

moon_TextArray*
moon_TextArray_get_slice(
	const moon_TextArray* self,
	long long start,
	long long stop,
	long long step
) {
	return moon_GraphicsGroup_get_slice<moon_TextArray, moon_Text>(
		self,
		start,
		stop,
		step
	);
}

int
moon_TextArray_is_empty(const moon_TextArray* self) {
	return moon_GraphicsGroup_is_empty<moon_TextArray>(self);
}

int
moon_TextArray_is_check_enabled(const moon_TextArray* self) {
	return moon_GraphicsGroup_is_check_enabled<moon_TextArray>(self);
}

int
moon_TextArray_resize(
	moon_TextArray* self,
	unsigned long new_size
) {
	return moon_GraphicsGroup_resize<moon_TextArray>(self, new_size);
}

int
moon_TextArray_reserve(
	moon_TextArray* self,
	unsigned long new_capacity
) {
	return moon_GraphicsGroup_reserve<moon_TextArray>(self, new_capacity);
}

unsigned long
moon_TextArray_get_size(const moon_TextArray* self) {
	return moon_GraphicsGroup_get_size<moon_TextArray>(self);
}

unsigned long
moon_TextArray_get_length(const moon_TextArray* self) {
	return moon_GraphicsGroup_get_length<moon_TextArray>(self);
}

void
moon_TextArray_clear(moon_TextArray* self) {
	moon_GraphicsGroup_clear<moon_TextArray>(self);
}

void
moon_TextArray_reverse(
	moon_TextArray* self,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_reverse<moon_TextArray>(self, first_index, num_elements);
}

void
moon_TextArray_remove(
	moon_TextArray* self,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_remove<moon_TextArray>(self, first_index, num_elements);
}

void
moon_TextArray_push_back(
	moon_TextArray* self,
	moon_Text* element
) {
	moon_GraphicsGroup_push_back<moon_TextArray, moon_Text>(self, element);
}

void
moon_TextArray_insert(
	moon_TextArray* self,
	unsigned long index,
	moon_Text* element
) {
	moon_GraphicsGroup_insert<moon_TextArray, moon_Text>(self, index, element);
}

void
moon_TextArray_extend(
	moon_TextArray* self,
	const moon_TextArray* other,
	unsigned long other_first_index,
	unsigned long other_num_elements
) {
	moon_GraphicsGroup_extend<moon_TextArray>(
		self,
		other,
		other_first_index,
		other_num_elements
	);
}

void
moon_TextArray_set_check_enabled(
	moon_TextArray* self,
	int check_visibility
) {
	moon_GraphicsGroup_set_check_enabled<moon_TextArray>(self, check_visibility);
}

moon_Text*
moon_TextArray_set(
	moon_TextArray* self,
	unsigned long index,
	moon_Text* element
) {
	return moon_GraphicsGroup_set<moon_TextArray, moon_Text>(self, index, element);
}

moon_Text*
moon_TextArray_pop(
	moon_TextArray* self,
	unsigned long index
) {
	return moon_GraphicsGroup_pop<moon_TextArray, moon_Text>(self, index);
}

moon_Text*
moon_TextArray_get(
	moon_TextArray* self,
	unsigned long index
) {
	return moon_GraphicsGroup_get<moon_TextArray, moon_Text>(self, index);
}

void
moon_TextArray_draw(
	const moon_TextArray* self,
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
		moon_Text_get_global_bounds,
		moon_Text_draw
	)
}

void
moon_TextArray_set_color(
	const moon_TextArray* self,
	const moon_Color* color,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_color(
		self,
		color,
		first_index,
		num_elements,
		moon_Text_set_fill_color
	)
}

long long
moon_TextArray_find_alpha(
	const moon_TextArray* self,
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
		moon_Text_get_fill_color
	)
	return res;
}

long long
moon_TextArray_find_color(
	const moon_TextArray* self,
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
		moon_Text_get_fill_color
	)
	return res;
}

void
moon_TextArray_inverse_color(
	const moon_TextArray* self,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_inverse_color(
		self,
		first_index,
		num_elements,
		moon_Text_set_fill_color,
		moon_Text_get_fill_color
	)
}

void
moon_TextArray_set_alpha(
	const moon_TextArray* self,
	unsigned char alpha,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_alpha(
		self,
		alpha,
		first_index,
		num_elements,
		moon_Text_set_fill_color,
		moon_Text_get_fill_color
	)
}

moon_FRectLst*
moon_TextArray_get_bounds(
	const moon_TextArray* self,
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
		moon_Text_get_global_bounds,
		moon_Text_get_local_bounds,
		moon_Text_get_world_bounds
	)
	return res;
}

long long
moon_TextArray_find_elsize(
	const moon_TextArray* self,
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
		moon_Text_get_size
	)
	return res;
}

long long
moon_TextArray_get_elsize(
	const moon_TextArray* self,
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
		moon_Text_get_size
	)
	return res;
}

long long
moon_TextArray_find_elscale(
	const moon_TextArray* self,
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
		moon_Text_get_scale
	)
	return res;
}

long long
moon_TextArray_get_elscale(
	const moon_TextArray* self,
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
		moon_Text_get_scale
	)
	return res;
}

void
moon_TextArray_set_elscale(
	const moon_TextArray* self,
	float scale_x, float scale_y,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_vector2f(
		self,
		first_index,
		num_elements,
		scale_x, scale_y,
		moon_Text_set_scale
	)
}

void
moon_TextArray_elscale(
	const moon_TextArray* self,
	float scale_x, float scale_y,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_vector2f(
		self,
		first_index,
		num_elements,
		scale_x, scale_y,
		moon_Text_scale
	)
}

long long
moon_TextArray_find_elposition(
	const moon_TextArray* self,
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
		moon_Text_get_position
	)
	return res;
}

long long
moon_TextArray_get_elposition(
	const moon_TextArray* self,
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
		moon_Text_get_position
	)
	return res;
}

void
moon_TextArray_randomize_elposition(
	const moon_TextArray* self,
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
		moon_Text_set_position
	)
}

void
moon_TextArray_set_elposition(
	const moon_TextArray* self,
	float x, float y,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_vector2f(
		self,
		first_index,
		num_elements,
		x, y,
		moon_Text_set_position
	)
}

void
moon_TextArray_elmove(
	const moon_TextArray* self,
	float dx, float dy,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_vector2f(
		self,
		first_index,
		num_elements,
		dx, dy,
		moon_Text_move
	)
}

long long
moon_TextArray_find_elorigin(
	const moon_TextArray* self,
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
		moon_Text_get_origin
	)
	return res;
}

long long
moon_TextArray_get_elorigin(
	const moon_TextArray* self,
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
		moon_Text_get_origin
	)
	return res;
}

void
moon_TextArray_randomize_elorigin(
	const moon_TextArray* self,
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
		moon_Text_set_origin
	)
}

void
moon_TextArray_set_elorigin(
	const moon_TextArray* self,
	float origin_x, float origin_y,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_vector2f(
		self,
		first_index,
		num_elements,
		origin_x, origin_y,
		moon_Text_set_origin
	)
}

long long
moon_TextArray_find_elrotation(
	const moon_TextArray* self,
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
		moon_Text_get_rotation
	)
	return res;
}

long long
moon_TextArray_get_elrotation(
	const moon_TextArray* self,
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
		moon_Text_get_rotation
	)
	return res;
}

void
moon_TextArray_randomize_elrotation(
	const moon_TextArray* self,
	int min_angle, int max_angle,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_randomize_value(
		self,
		first_index,
		num_elements,
		min_angle, max_angle,
		moon_Text_set_rotation
	)
}

void
moon_TextArray_set_elrotation(
	const moon_TextArray* self,
	moon_Angle angle,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_value(
		self,
		first_index,
		num_elements,
		angle,
		moon_Text_set_rotation
	)
}

void
moon_TextArray_elrotate(
	const moon_TextArray* self,
	moon_Angle angle,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_value(
		self,
		first_index,
		num_elements,
		angle,
		moon_Text_rotate
	)
}
