#include "../../headers/extras/moon_text_write_array.h"

#include "../../headers/extras/GraphicsGroup.hpp"


struct moon_TextWriteArray {
	moon_GraphicsGroup_HEAD(moon_TextWrite)
};


moon_TextWriteArray*
moon_TextWriteArray_create(
	int check_visibility,
	unsigned long initial_capacity
) {
	return moon_GraphicsGroup_create<moon_TextWriteArray>(
		check_visibility,
		initial_capacity
	);
}

void
moon_TextWriteArray_destroy(moon_TextWriteArray* self) {
	moon_GraphicsGroup_destroy<moon_TextWriteArray>(self);
}

moon_TextWriteArray*
moon_TextWriteArray_get_slice(
	const moon_TextWriteArray* self,
	long long start,
	long long stop,
	long long step
) {
	return moon_GraphicsGroup_get_slice<moon_TextWriteArray, moon_TextWrite>(
		self,
		start,
		stop,
		step
	);
}

int
moon_TextWriteArray_is_empty(const moon_TextWriteArray* self) {
	return moon_GraphicsGroup_is_empty<moon_TextWriteArray>(self);
}

int
moon_TextWriteArray_is_check_enabled(const moon_TextWriteArray* self) {
	return moon_GraphicsGroup_is_check_enabled<moon_TextWriteArray>(self);
}

int
moon_TextWriteArray_resize(
	moon_TextWriteArray* self,
	unsigned long new_size
) {
	return moon_GraphicsGroup_resize<moon_TextWriteArray>(self, new_size);
}

int
moon_TextWriteArray_reserve(
	moon_TextWriteArray* self,
	unsigned long new_capacity
) {
	return moon_GraphicsGroup_reserve<moon_TextWriteArray>(self, new_capacity);
}

unsigned long
moon_TextWriteArray_get_size(const moon_TextWriteArray* self) {
	return moon_GraphicsGroup_get_size<moon_TextWriteArray>(self);
}

unsigned long
moon_TextWriteArray_get_length(const moon_TextWriteArray* self) {
	return moon_GraphicsGroup_get_length<moon_TextWriteArray>(self);
}

void
moon_TextWriteArray_clear(moon_TextWriteArray* self) {
	moon_GraphicsGroup_clear<moon_TextWriteArray>(self);
}

void
moon_TextWriteArray_reverse(
	moon_TextWriteArray* self,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_reverse<moon_TextWriteArray>(self, first_index, num_elements);
}

void
moon_TextWriteArray_remove(
	moon_TextWriteArray* self,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_remove<moon_TextWriteArray>(self, first_index, num_elements);
}

void
moon_TextWriteArray_push_back(
	moon_TextWriteArray* self,
	moon_TextWrite* element
) {
	moon_GraphicsGroup_push_back<moon_TextWriteArray, moon_TextWrite>(self, element);
}

void
moon_TextWriteArray_insert(
	moon_TextWriteArray* self,
	unsigned long index,
	moon_TextWrite* element
) {
	moon_GraphicsGroup_insert<moon_TextWriteArray, moon_TextWrite>(self, index, element);
}

void
moon_TextWriteArray_extend(
	moon_TextWriteArray* self,
	const moon_TextWriteArray* other,
	unsigned long other_first_index,
	unsigned long other_num_elements
) {
	moon_GraphicsGroup_extend<moon_TextWriteArray>(
		self,
		other,
		other_first_index,
		other_num_elements
	);
}

void
moon_TextWriteArray_set_check_enabled(
	moon_TextWriteArray* self,
	int check_visibility
) {
	moon_GraphicsGroup_set_check_enabled<moon_TextWriteArray>(self, check_visibility);
}

moon_TextWrite*
moon_TextWriteArray_set(
	moon_TextWriteArray* self,
	unsigned long index,
	moon_TextWrite* element
) {
	return moon_GraphicsGroup_set<moon_TextWriteArray, moon_TextWrite>(self, index, element);
}

moon_TextWrite*
moon_TextWriteArray_pop(
	moon_TextWriteArray* self,
	unsigned long index
) {
	return moon_GraphicsGroup_pop<moon_TextWriteArray, moon_TextWrite>(self, index);
}

moon_TextWrite*
moon_TextWriteArray_get(
	moon_TextWriteArray* self,
	unsigned long index
) {
	return moon_GraphicsGroup_get<moon_TextWriteArray, moon_TextWrite>(self, index);
}

void
moon_TextWriteArray_draw(
	const moon_TextWriteArray* self,
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
		moon_TextWrite_get_global_bounds,
		moon_TextWrite_draw
	)
}

void
moon_TextWriteArray_set_color(
	const moon_TextWriteArray* self,
	const moon_Color* color,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_color(
		self,
		color,
		first_index,
		num_elements,
		moon_TextWrite_set_fill_color
	)
}

long long
moon_TextWriteArray_find_alpha(
	const moon_TextWriteArray* self,
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
		moon_TextWrite_get_fill_color
	)
	return res;
}

long long
moon_TextWriteArray_find_color(
	const moon_TextWriteArray* self,
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
		moon_TextWrite_get_fill_color
	)
	return res;
}

void
moon_TextWriteArray_inverse_color(
	const moon_TextWriteArray* self,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_inverse_color(
		self,
		first_index,
		num_elements,
		moon_TextWrite_set_fill_color,
		moon_TextWrite_get_fill_color
	)
}

void
moon_TextWriteArray_set_alpha(
	const moon_TextWriteArray* self,
	unsigned char alpha,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_alpha(
		self,
		alpha,
		first_index,
		num_elements,
		moon_TextWrite_set_fill_color,
		moon_TextWrite_get_fill_color
	)
}

moon_FRectLst*
moon_TextWriteArray_get_bounds(
	const moon_TextWriteArray* self,
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
		moon_TextWrite_get_global_bounds,
		moon_TextWrite_get_local_bounds,
		moon_TextWrite_get_world_bounds
	)
	return res;
}

long long
moon_TextWriteArray_find_elsize(
	const moon_TextWriteArray* self,
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
		moon_TextWrite_get_size
	)
	return res;
}

long long
moon_TextWriteArray_get_elsize(
	const moon_TextWriteArray* self,
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
		moon_TextWrite_get_size
	)
	return res;
}

long long
moon_TextWriteArray_find_elscale(
	const moon_TextWriteArray* self,
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
		moon_TextWrite_get_scale
	)
	return res;
}

long long
moon_TextWriteArray_get_elscale(
	const moon_TextWriteArray* self,
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
		moon_TextWrite_get_scale
	)
	return res;
}

void
moon_TextWriteArray_set_elscale(
	const moon_TextWriteArray* self,
	float scale_x, float scale_y,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_vector2f(
		self,
		first_index,
		num_elements,
		scale_x, scale_y,
		moon_TextWrite_set_scale
	)
}

void
moon_TextWriteArray_elscale(
	const moon_TextWriteArray* self,
	float scale_x, float scale_y,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_vector2f(
		self,
		first_index,
		num_elements,
		scale_x, scale_y,
		moon_TextWrite_scale
	)
}

long long
moon_TextWriteArray_find_elposition(
	const moon_TextWriteArray* self,
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
		moon_TextWrite_get_position
	)
	return res;
}

long long
moon_TextWriteArray_get_elposition(
	const moon_TextWriteArray* self,
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
		moon_TextWrite_get_position
	)
	return res;
}

void
moon_TextWriteArray_randomize_elposition(
	const moon_TextWriteArray* self,
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
		moon_TextWrite_set_position
	)
}

void
moon_TextWriteArray_set_elposition(
	const moon_TextWriteArray* self,
	float x, float y,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_vector2f(
		self,
		first_index,
		num_elements,
		x, y,
		moon_TextWrite_set_position
	)
}

void
moon_TextWriteArray_elmove(
	const moon_TextWriteArray* self,
	float dx, float dy,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_vector2f(
		self,
		first_index,
		num_elements,
		dx, dy,
		moon_TextWrite_move
	)
}

long long
moon_TextWriteArray_find_elorigin(
	const moon_TextWriteArray* self,
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
		moon_TextWrite_get_origin
	)
	return res;
}

long long
moon_TextWriteArray_get_elorigin(
	const moon_TextWriteArray* self,
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
		moon_TextWrite_get_origin
	)
	return res;
}

void
moon_TextWriteArray_randomize_elorigin(
	const moon_TextWriteArray* self,
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
		moon_TextWrite_set_origin
	)
}

void
moon_TextWriteArray_set_elorigin(
	const moon_TextWriteArray* self,
	float origin_x, float origin_y,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_vector2f(
		self,
		first_index,
		num_elements,
		origin_x, origin_y,
		moon_TextWrite_set_origin
	)
}

long long
moon_TextWriteArray_find_elrotation(
	const moon_TextWriteArray* self,
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
		moon_TextWrite_get_rotation
	)
	return res;
}

long long
moon_TextWriteArray_get_elrotation(
	const moon_TextWriteArray* self,
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
		moon_TextWrite_get_rotation
	)
	return res;
}

void
moon_TextWriteArray_randomize_elrotation(
	const moon_TextWriteArray* self,
	int min_angle, int max_angle,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_randomize_value(
		self,
		first_index,
		num_elements,
		min_angle, max_angle,
		moon_TextWrite_set_rotation
	)
}

void
moon_TextWriteArray_set_elrotation(
	const moon_TextWriteArray* self,
	moon_Angle angle,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_value(
		self,
		first_index,
		num_elements,
		angle,
		moon_TextWrite_set_rotation
	)
}

void
moon_TextWriteArray_elrotate(
	const moon_TextWriteArray* self,
	moon_Angle angle,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_value(
		self,
		first_index,
		num_elements,
		angle,
		moon_TextWrite_rotate
	)
}
