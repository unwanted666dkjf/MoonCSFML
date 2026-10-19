#include "../../headers/extras/moon_gui_fpscntr_array.h"

#include "../../headers/extras/GraphicsGroup.hpp"


struct moon_guiFpsCntrArray {
	moon_GraphicsGroup_HEAD(moon_guiFpsCntr)
};


moon_guiFpsCntrArray*
moon_guiFpsCntrArray_create(
	int check_visibility,
	unsigned long initial_capacity
) {
	return moon_GraphicsGroup_create<moon_guiFpsCntrArray>(
		check_visibility,
		initial_capacity
	);
}

void
moon_guiFpsCntrArray_destroy(moon_guiFpsCntrArray* self) {
	moon_GraphicsGroup_destroy<moon_guiFpsCntrArray>(self);
}

moon_guiFpsCntrArray*
moon_guiFpsCntrArray_get_slice(
	const moon_guiFpsCntrArray* self,
	long long start,
	long long stop,
	long long step
) {
	return moon_GraphicsGroup_get_slice<moon_guiFpsCntrArray, moon_guiFpsCntr>(
		self,
		start,
		stop,
		step
	);
}

int
moon_guiFpsCntrArray_is_empty(const moon_guiFpsCntrArray* self) {
	return moon_GraphicsGroup_is_empty<moon_guiFpsCntrArray>(self);
}

int
moon_guiFpsCntrArray_is_check_enabled(const moon_guiFpsCntrArray* self) {
	return moon_GraphicsGroup_is_check_enabled<moon_guiFpsCntrArray>(self);
}

int
moon_guiFpsCntrArray_resize(
	moon_guiFpsCntrArray* self,
	unsigned long new_size
) {
	return moon_GraphicsGroup_resize<moon_guiFpsCntrArray>(self, new_size);
}

int
moon_guiFpsCntrArray_reserve(
	moon_guiFpsCntrArray* self,
	unsigned long new_capacity
) {
	return moon_GraphicsGroup_reserve<moon_guiFpsCntrArray>(self, new_capacity);
}

unsigned long
moon_guiFpsCntrArray_get_size(const moon_guiFpsCntrArray* self) {
	return moon_GraphicsGroup_get_size<moon_guiFpsCntrArray>(self);
}

unsigned long
moon_guiFpsCntrArray_get_length(const moon_guiFpsCntrArray* self) {
	return moon_GraphicsGroup_get_length<moon_guiFpsCntrArray>(self);
}

void
moon_guiFpsCntrArray_clear(moon_guiFpsCntrArray* self) {
	moon_GraphicsGroup_clear<moon_guiFpsCntrArray>(self);
}

void
moon_guiFpsCntrArray_reverse(
	moon_guiFpsCntrArray* self,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_reverse<moon_guiFpsCntrArray>(self, first_index, num_elements);
}

void
moon_guiFpsCntrArray_remove(
	moon_guiFpsCntrArray* self,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_remove<moon_guiFpsCntrArray>(self, first_index, num_elements);
}

void
moon_guiFpsCntrArray_push_back(
	moon_guiFpsCntrArray* self,
	moon_guiFpsCntr* element
) {
	moon_GraphicsGroup_push_back<moon_guiFpsCntrArray, moon_guiFpsCntr>(self, element);
}

void
moon_guiFpsCntrArray_insert(
	moon_guiFpsCntrArray* self,
	unsigned long index,
	moon_guiFpsCntr* element
) {
	moon_GraphicsGroup_insert<moon_guiFpsCntrArray, moon_guiFpsCntr>(self, index, element);
}

void
moon_guiFpsCntrArray_extend(
	moon_guiFpsCntrArray* self,
	const moon_guiFpsCntrArray* other,
	unsigned long other_first_index,
	unsigned long other_num_elements
) {
	moon_GraphicsGroup_extend<moon_guiFpsCntrArray>(
		self,
		other,
		other_first_index,
		other_num_elements
	);
}

void
moon_guiFpsCntrArray_set_check_enabled(
	moon_guiFpsCntrArray* self,
	int check_visibility
) {
	moon_GraphicsGroup_set_check_enabled<moon_guiFpsCntrArray>(self, check_visibility);
}

moon_guiFpsCntr*
moon_guiFpsCntrArray_set(
	moon_guiFpsCntrArray* self,
	unsigned long index,
	moon_guiFpsCntr* element
) {
	return moon_GraphicsGroup_set<moon_guiFpsCntrArray, moon_guiFpsCntr>(self, index, element);
}

moon_guiFpsCntr*
moon_guiFpsCntrArray_pop(
	moon_guiFpsCntrArray* self,
	unsigned long index
) {
	return moon_GraphicsGroup_pop<moon_guiFpsCntrArray, moon_guiFpsCntr>(self, index);
}

moon_guiFpsCntr*
moon_guiFpsCntrArray_get(
	moon_guiFpsCntrArray* self,
	unsigned long index
) {
	return moon_GraphicsGroup_get<moon_guiFpsCntrArray, moon_guiFpsCntr>(self, index);
}

void
moon_guiFpsCntrArray_draw(
	const moon_guiFpsCntrArray* self,
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
		moon_guiFpsCntr_get_global_bounds,
		moon_guiFpsCntr_draw
	)
}

void
moon_guiFpsCntrArray_set_color(
	const moon_guiFpsCntrArray* self,
	const moon_Color* color,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_color(
		self,
		color,
		first_index,
		num_elements,
		moon_guiFpsCntr_set_fill_color
	)
}

long long
moon_guiFpsCntrArray_find_alpha(
	const moon_guiFpsCntrArray* self,
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
		moon_guiFpsCntr_get_fill_color
	)
	return res;
}

long long
moon_guiFpsCntrArray_find_color(
	const moon_guiFpsCntrArray* self,
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
		moon_guiFpsCntr_get_fill_color
	)
	return res;
}

void
moon_guiFpsCntrArray_inverse_color(
	const moon_guiFpsCntrArray* self,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_inverse_color(
		self,
		first_index,
		num_elements,
		moon_guiFpsCntr_set_fill_color,
		moon_guiFpsCntr_get_fill_color
	)
}

void
moon_guiFpsCntrArray_set_alpha(
	const moon_guiFpsCntrArray* self,
	unsigned char alpha,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_alpha(
		self,
		alpha,
		first_index,
		num_elements,
		moon_guiFpsCntr_set_fill_color,
		moon_guiFpsCntr_get_fill_color
	)
}

moon_FRectLst*
moon_guiFpsCntrArray_get_bounds(
	const moon_guiFpsCntrArray* self,
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
		moon_guiFpsCntr_get_global_bounds,
		moon_guiFpsCntr_get_local_bounds,
		moon_guiFpsCntr_get_world_bounds
	)
	return res;
}

long long
moon_guiFpsCntrArray_find_elsize(
	const moon_guiFpsCntrArray* self,
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
		moon_guiFpsCntr_get_size
	)
	return res;
}

long long
moon_guiFpsCntrArray_get_elsize(
	const moon_guiFpsCntrArray* self,
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
		moon_guiFpsCntr_get_size
	)
	return res;
}

long long
moon_guiFpsCntrArray_find_elscale(
	const moon_guiFpsCntrArray* self,
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
		moon_guiFpsCntr_get_scale
	)
	return res;
}

long long
moon_guiFpsCntrArray_get_elscale(
	const moon_guiFpsCntrArray* self,
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
		moon_guiFpsCntr_get_scale
	)
	return res;
}

void
moon_guiFpsCntrArray_set_elscale(
	const moon_guiFpsCntrArray* self,
	float scale_x, float scale_y,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_vector2f(
		self,
		first_index,
		num_elements,
		scale_x, scale_y,
		moon_guiFpsCntr_set_scale
	)
}

void
moon_guiFpsCntrArray_elscale(
	const moon_guiFpsCntrArray* self,
	float scale_x, float scale_y,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_vector2f(
		self,
		first_index,
		num_elements,
		scale_x, scale_y,
		moon_guiFpsCntr_scale
	)
}

long long
moon_guiFpsCntrArray_find_elposition(
	const moon_guiFpsCntrArray* self,
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
		moon_guiFpsCntr_get_position
	)
	return res;
}

long long
moon_guiFpsCntrArray_get_elposition(
	const moon_guiFpsCntrArray* self,
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
		moon_guiFpsCntr_get_position
	)
	return res;
}

void
moon_guiFpsCntrArray_randomize_elposition(
	const moon_guiFpsCntrArray* self,
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
		moon_guiFpsCntr_set_position
	)
}

void
moon_guiFpsCntrArray_set_elposition(
	const moon_guiFpsCntrArray* self,
	float x, float y,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_vector2f(
		self,
		first_index,
		num_elements,
		x, y,
		moon_guiFpsCntr_set_position
	)
}

void
moon_guiFpsCntrArray_elmove(
	const moon_guiFpsCntrArray* self,
	float dx, float dy,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_vector2f(
		self,
		first_index,
		num_elements,
		dx, dy,
		moon_guiFpsCntr_move
	)
}

long long
moon_guiFpsCntrArray_find_elorigin(
	const moon_guiFpsCntrArray* self,
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
		moon_guiFpsCntr_get_origin
	)
	return res;
}

long long
moon_guiFpsCntrArray_get_elorigin(
	const moon_guiFpsCntrArray* self,
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
		moon_guiFpsCntr_get_origin
	)
	return res;
}

void
moon_guiFpsCntrArray_randomize_elorigin(
	const moon_guiFpsCntrArray* self,
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
		moon_guiFpsCntr_set_origin
	)
}

void
moon_guiFpsCntrArray_set_elorigin(
	const moon_guiFpsCntrArray* self,
	float origin_x, float origin_y,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_vector2f(
		self,
		first_index,
		num_elements,
		origin_x, origin_y,
		moon_guiFpsCntr_set_origin
	)
}

long long
moon_guiFpsCntrArray_find_elrotation(
	const moon_guiFpsCntrArray* self,
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
		moon_guiFpsCntr_get_rotation
	)
	return res;
}

long long
moon_guiFpsCntrArray_get_elrotation(
	const moon_guiFpsCntrArray* self,
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
		moon_guiFpsCntr_get_rotation
	)
	return res;
}

void
moon_guiFpsCntrArray_randomize_elrotation(
	const moon_guiFpsCntrArray* self,
	int min_angle, int max_angle,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_randomize_value(
		self,
		first_index,
		num_elements,
		min_angle, max_angle,
		moon_guiFpsCntr_set_rotation
	)
}

void
moon_guiFpsCntrArray_set_elrotation(
	const moon_guiFpsCntrArray* self,
	moon_Angle angle,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_value(
		self,
		first_index,
		num_elements,
		angle,
		moon_guiFpsCntr_set_rotation
	)
}

void
moon_guiFpsCntrArray_elrotate(
	const moon_guiFpsCntrArray* self,
	moon_Angle angle,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_value(
		self,
		first_index,
		num_elements,
		angle,
		moon_guiFpsCntr_rotate
	)
}
