#include "../../headers/extras/moon_rectangle_shape_array.h"

#include "../../headers/extras/GraphicsGroup.hpp"


struct moon_RectangleShapeArray {
	moon_GraphicsGroup_HEAD(moon_RectangleShape)
};


moon_RectangleShapeArray*
moon_RectangleShapeArray_create(
	int check_visibility,
	unsigned long initial_capacity
) {
	return moon_GraphicsGroup_create<moon_RectangleShapeArray>(
		check_visibility,
		initial_capacity
	);
}

void
moon_RectangleShapeArray_destroy(moon_RectangleShapeArray* self) {
	moon_GraphicsGroup_destroy<moon_RectangleShapeArray>(self);
}

moon_RectangleShapeArray*
moon_RectangleShapeArray_get_slice(
	const moon_RectangleShapeArray* self,
	long long start,
	long long stop,
	long long step
) {
	return moon_GraphicsGroup_get_slice<moon_RectangleShapeArray, moon_RectangleShape>(
		self,
		start,
		stop,
		step
	);
}

int
moon_RectangleShapeArray_is_empty(const moon_RectangleShapeArray* self) {
	return moon_GraphicsGroup_is_empty<moon_RectangleShapeArray>(self);
}

int
moon_RectangleShapeArray_is_check_enabled(const moon_RectangleShapeArray* self) {
	return moon_GraphicsGroup_is_check_enabled<moon_RectangleShapeArray>(self);
}

int
moon_RectangleShapeArray_resize(
	moon_RectangleShapeArray* self,
	unsigned long new_size
) {
	return moon_GraphicsGroup_resize<moon_RectangleShapeArray>(self, new_size);
}

int
moon_RectangleShapeArray_reserve(
	moon_RectangleShapeArray* self,
	unsigned long new_capacity
) {
	return moon_GraphicsGroup_reserve<moon_RectangleShapeArray>(self, new_capacity);
}

unsigned long
moon_RectangleShapeArray_get_size(const moon_RectangleShapeArray* self) {
	return moon_GraphicsGroup_get_size<moon_RectangleShapeArray>(self);
}

unsigned long
moon_RectangleShapeArray_get_length(const moon_RectangleShapeArray* self) {
	return moon_GraphicsGroup_get_length<moon_RectangleShapeArray>(self);
}

void
moon_RectangleShapeArray_clear(moon_RectangleShapeArray* self) {
	moon_GraphicsGroup_clear<moon_RectangleShapeArray>(self);
}

void
moon_RectangleShapeArray_reverse(
	moon_RectangleShapeArray* self,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_reverse<moon_RectangleShapeArray>(self, first_index, num_elements);
}

void
moon_RectangleShapeArray_remove(
	moon_RectangleShapeArray* self,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_remove<moon_RectangleShapeArray>(self, first_index, num_elements);
}

void
moon_RectangleShapeArray_push_back(
	moon_RectangleShapeArray* self,
	moon_RectangleShape* element
) {
	moon_GraphicsGroup_push_back<moon_RectangleShapeArray, moon_RectangleShape>(self, element);
}

void
moon_RectangleShapeArray_insert(
	moon_RectangleShapeArray* self,
	unsigned long index,
	moon_RectangleShape* element
) {
	moon_GraphicsGroup_insert<moon_RectangleShapeArray, moon_RectangleShape>(self, index, element);
}

void
moon_RectangleShapeArray_extend(
	moon_RectangleShapeArray* self,
	const moon_RectangleShapeArray* other,
	unsigned long other_first_index,
	unsigned long other_num_elements
) {
	moon_GraphicsGroup_extend<moon_RectangleShapeArray>(
		self,
		other,
		other_first_index,
		other_num_elements
	);
}

void
moon_RectangleShapeArray_set_check_enabled(
	moon_RectangleShapeArray* self,
	int check_visibility
) {
	moon_GraphicsGroup_set_check_enabled<moon_RectangleShapeArray>(self, check_visibility);
}

moon_RectangleShape*
moon_RectangleShapeArray_set(
	moon_RectangleShapeArray* self,
	unsigned long index,
	moon_RectangleShape* element
) {
	return moon_GraphicsGroup_set<moon_RectangleShapeArray, moon_RectangleShape>(self, index, element);
}

moon_RectangleShape*
moon_RectangleShapeArray_pop(
	moon_RectangleShapeArray* self,
	unsigned long index
) {
	return moon_GraphicsGroup_pop<moon_RectangleShapeArray, moon_RectangleShape>(self, index);
}

moon_RectangleShape*
moon_RectangleShapeArray_get(
	moon_RectangleShapeArray* self,
	unsigned long index
) {
	return moon_GraphicsGroup_get<moon_RectangleShapeArray, moon_RectangleShape>(self, index);
}

void
moon_RectangleShapeArray_draw(
	const moon_RectangleShapeArray* self,
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
		moon_RectangleShape_get_global_bounds,
		moon_RectangleShape_draw
	)
}

void
moon_RectangleShapeArray_set_color(
	const moon_RectangleShapeArray* self,
	const moon_Color* color,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_color(
		self,
		color,
		first_index,
		num_elements,
		moon_RectangleShape_set_fill_color
	)
}

long long
moon_RectangleShapeArray_find_alpha(
	const moon_RectangleShapeArray* self,
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
		moon_RectangleShape_get_fill_color
	)
	return res;
}

long long
moon_RectangleShapeArray_find_color(
	const moon_RectangleShapeArray* self,
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
		moon_RectangleShape_get_fill_color
	)
	return res;
}

void
moon_RectangleShapeArray_inverse_color(
	const moon_RectangleShapeArray* self,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_inverse_color(
		self,
		first_index,
		num_elements,
		moon_RectangleShape_set_fill_color,
		moon_RectangleShape_get_fill_color
	)
}

void
moon_RectangleShapeArray_set_alpha(
	const moon_RectangleShapeArray* self,
	unsigned char alpha,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_alpha(
		self,
		alpha,
		first_index,
		num_elements,
		moon_RectangleShape_set_fill_color,
		moon_RectangleShape_get_fill_color
	)
}

moon_FRectLst*
moon_RectangleShapeArray_get_bounds(
	const moon_RectangleShapeArray* self,
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
		moon_RectangleShape_get_global_bounds,
		moon_RectangleShape_get_local_bounds,
		moon_RectangleShape_get_world_bounds
	)
	return res;
}

long long
moon_RectangleShapeArray_find_elsize(
	const moon_RectangleShapeArray* self,
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
		moon_RectangleShape_get_size
	)
	return res;
}

long long
moon_RectangleShapeArray_get_elsize(
	const moon_RectangleShapeArray* self,
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
		moon_RectangleShape_get_size
	)
	return res;
}

long long
moon_RectangleShapeArray_find_elscale(
	const moon_RectangleShapeArray* self,
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
		moon_RectangleShape_get_scale
	)
	return res;
}

long long
moon_RectangleShapeArray_get_elscale(
	const moon_RectangleShapeArray* self,
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
		moon_RectangleShape_get_scale
	)
	return res;
}

void
moon_RectangleShapeArray_set_elscale(
	const moon_RectangleShapeArray* self,
	float scale_x, float scale_y,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_vector2f(
		self,
		first_index,
		num_elements,
		scale_x, scale_y,
		moon_RectangleShape_set_scale
	)
}

void
moon_RectangleShapeArray_elscale(
	const moon_RectangleShapeArray* self,
	float scale_x, float scale_y,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_vector2f(
		self,
		first_index,
		num_elements,
		scale_x, scale_y,
		moon_RectangleShape_scale
	)
}

long long
moon_RectangleShapeArray_find_elposition(
	const moon_RectangleShapeArray* self,
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
		moon_RectangleShape_get_position
	)
	return res;
}

long long
moon_RectangleShapeArray_get_elposition(
	const moon_RectangleShapeArray* self,
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
		moon_RectangleShape_get_position
	)
	return res;
}

void
moon_RectangleShapeArray_randomize_elposition(
	const moon_RectangleShapeArray* self,
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
		moon_RectangleShape_set_position
	)
}

void
moon_RectangleShapeArray_set_elposition(
	const moon_RectangleShapeArray* self,
	float x, float y,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_vector2f(
		self,
		first_index,
		num_elements,
		x, y,
		moon_RectangleShape_set_position
	)
}

void
moon_RectangleShapeArray_elmove(
	const moon_RectangleShapeArray* self,
	float dx, float dy,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_vector2f(
		self,
		first_index,
		num_elements,
		dx, dy,
		moon_RectangleShape_move
	)
}

long long
moon_RectangleShapeArray_find_elorigin(
	const moon_RectangleShapeArray* self,
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
		moon_RectangleShape_get_origin
	)
	return res;
}

long long
moon_RectangleShapeArray_get_elorigin(
	const moon_RectangleShapeArray* self,
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
		moon_RectangleShape_get_origin
	)
	return res;
}

void
moon_RectangleShapeArray_randomize_elorigin(
	const moon_RectangleShapeArray* self,
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
		moon_RectangleShape_set_origin
	)
}

void
moon_RectangleShapeArray_set_elorigin(
	const moon_RectangleShapeArray* self,
	float origin_x, float origin_y,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_vector2f(
		self,
		first_index,
		num_elements,
		origin_x, origin_y,
		moon_RectangleShape_set_origin
	)
}

long long
moon_RectangleShapeArray_find_elrotation(
	const moon_RectangleShapeArray* self,
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
		moon_RectangleShape_get_rotation
	)
	return res;
}

long long
moon_RectangleShapeArray_get_elrotation(
	const moon_RectangleShapeArray* self,
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
		moon_RectangleShape_get_rotation
	)
	return res;
}

void
moon_RectangleShapeArray_randomize_elrotation(
	const moon_RectangleShapeArray* self,
	int min_angle, int max_angle,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_randomize_value(
		self,
		first_index,
		num_elements,
		min_angle, max_angle,
		moon_RectangleShape_set_rotation
	)
}

void
moon_RectangleShapeArray_set_elrotation(
	const moon_RectangleShapeArray* self,
	moon_Angle angle,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_value(
		self,
		first_index,
		num_elements,
		angle,
		moon_RectangleShape_set_rotation
	)
}

void
moon_RectangleShapeArray_elrotate(
	const moon_RectangleShapeArray* self,
	moon_Angle angle,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_value(
		self,
		first_index,
		num_elements,
		angle,
		moon_RectangleShape_rotate
	)
}
