#include "../../headers/extras/moon_circle_shape_array.h"

#include "../../headers/extras/GraphicsGroup.hpp"


struct moon_CircleShapeArray {
	moon_GraphicsGroup_HEAD(moon_CircleShape)
};


moon_CircleShapeArray*
moon_CircleShapeArray_create(
	int check_visibility,
	unsigned long initial_capacity
) {
	return moon_GraphicsGroup_create<moon_CircleShapeArray>(
		check_visibility,
		initial_capacity
	);
}

void
moon_CircleShapeArray_destroy(moon_CircleShapeArray* self) {
	moon_GraphicsGroup_destroy<moon_CircleShapeArray>(self);
}

moon_CircleShapeArray*
moon_CircleShapeArray_get_slice(
	const moon_CircleShapeArray* self,
	long long start,
	long long stop,
	long long step
) {
	return moon_GraphicsGroup_get_slice<moon_CircleShapeArray, moon_CircleShape>(
		self,
		start,
		stop,
		step
	);
}

int
moon_CircleShapeArray_is_empty(const moon_CircleShapeArray* self) {
	return moon_GraphicsGroup_is_empty<moon_CircleShapeArray>(self);
}

int
moon_CircleShapeArray_is_check_enabled(const moon_CircleShapeArray* self) {
	return moon_GraphicsGroup_is_check_enabled<moon_CircleShapeArray>(self);
}

int
moon_CircleShapeArray_resize(
	moon_CircleShapeArray* self,
	unsigned long new_size
) {
	return moon_GraphicsGroup_resize<moon_CircleShapeArray>(self, new_size);
}

int
moon_CircleShapeArray_reserve(
	moon_CircleShapeArray* self,
	unsigned long new_capacity
) {
	return moon_GraphicsGroup_reserve<moon_CircleShapeArray>(self, new_capacity);
}

unsigned long
moon_CircleShapeArray_get_size(const moon_CircleShapeArray* self) {
	return moon_GraphicsGroup_get_size<moon_CircleShapeArray>(self);
}

unsigned long
moon_CircleShapeArray_get_length(const moon_CircleShapeArray* self) {
	return moon_GraphicsGroup_get_length<moon_CircleShapeArray>(self);
}

void
moon_CircleShapeArray_clear(moon_CircleShapeArray* self) {
	moon_GraphicsGroup_clear<moon_CircleShapeArray>(self);
}

void
moon_CircleShapeArray_reverse(
	moon_CircleShapeArray* self,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_reverse<moon_CircleShapeArray>(self, first_index, num_elements);
}

void
moon_CircleShapeArray_remove(
	moon_CircleShapeArray* self,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_remove<moon_CircleShapeArray>(self, first_index, num_elements);
}

void
moon_CircleShapeArray_push_back(
	moon_CircleShapeArray* self,
	moon_CircleShape* element
) {
	moon_GraphicsGroup_push_back<moon_CircleShapeArray, moon_CircleShape>(self, element);
}

void
moon_CircleShapeArray_insert(
	moon_CircleShapeArray* self,
	unsigned long index,
	moon_CircleShape* element
) {
	moon_GraphicsGroup_insert<moon_CircleShapeArray, moon_CircleShape>(self, index, element);
}

void
moon_CircleShapeArray_extend(
	moon_CircleShapeArray* self,
	const moon_CircleShapeArray* other,
	unsigned long other_first_index,
	unsigned long other_num_elements
) {
	moon_GraphicsGroup_extend<moon_CircleShapeArray>(
		self,
		other,
		other_first_index,
		other_num_elements
	);
}

void
moon_CircleShapeArray_set_check_enabled(
	moon_CircleShapeArray* self,
	int check_visibility
) {
	moon_GraphicsGroup_set_check_enabled<moon_CircleShapeArray>(self, check_visibility);
}

moon_CircleShape*
moon_CircleShapeArray_set(
	moon_CircleShapeArray* self,
	unsigned long index,
	moon_CircleShape* element
) {
	return moon_GraphicsGroup_set<moon_CircleShapeArray, moon_CircleShape>(self, index, element);
}

moon_CircleShape*
moon_CircleShapeArray_pop(
	moon_CircleShapeArray* self,
	unsigned long index
) {
	return moon_GraphicsGroup_pop<moon_CircleShapeArray, moon_CircleShape>(self, index);
}

moon_CircleShape*
moon_CircleShapeArray_get(
	moon_CircleShapeArray* self,
	unsigned long index
) {
	return moon_GraphicsGroup_get<moon_CircleShapeArray, moon_CircleShape>(self, index);
}

void
moon_CircleShapeArray_draw(
	const moon_CircleShapeArray* self,
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
		moon_CircleShape_get_global_bounds,
		moon_CircleShape_draw
	)
}

void
moon_CircleShapeArray_set_color(
	const moon_CircleShapeArray* self,
	const moon_Color* color,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_color(
		self,
		color,
		first_index,
		num_elements,
		moon_CircleShape_set_fill_color
	)
}

long long
moon_CircleShapeArray_find_alpha(
	const moon_CircleShapeArray* self,
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
		moon_CircleShape_get_fill_color
	)
	return res;
}

long long
moon_CircleShapeArray_find_color(
	const moon_CircleShapeArray* self,
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
		moon_CircleShape_get_fill_color
	)
	return res;
}

void
moon_CircleShapeArray_inverse_color(
	const moon_CircleShapeArray* self,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_inverse_color(
		self,
		first_index,
		num_elements,
		moon_CircleShape_set_fill_color,
		moon_CircleShape_get_fill_color
	)
}

void
moon_CircleShapeArray_set_alpha(
	const moon_CircleShapeArray* self,
	unsigned char alpha,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_alpha(
		self,
		alpha,
		first_index,
		num_elements,
		moon_CircleShape_set_fill_color,
		moon_CircleShape_get_fill_color
	)
}

moon_FRectLst*
moon_CircleShapeArray_get_bounds(
	const moon_CircleShapeArray* self,
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
		moon_CircleShape_get_global_bounds,
		moon_CircleShape_get_local_bounds,
		moon_CircleShape_get_world_bounds
	)
	return res;
}

long long
moon_CircleShapeArray_find_elsize(
	const moon_CircleShapeArray* self,
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
		moon_CircleShape_get_size
	)
	return res;
}

long long
moon_CircleShapeArray_get_elsize(
	const moon_CircleShapeArray* self,
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
		moon_CircleShape_get_size
	)
	return res;
}

long long
moon_CircleShapeArray_find_elscale(
	const moon_CircleShapeArray* self,
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
		moon_CircleShape_get_scale
	)
	return res;
}

long long
moon_CircleShapeArray_get_elscale(
	const moon_CircleShapeArray* self,
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
		moon_CircleShape_get_scale
	)
	return res;
}

void
moon_CircleShapeArray_set_elscale(
	const moon_CircleShapeArray* self,
	float scale_x, float scale_y,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_vector2f(
		self,
		first_index,
		num_elements,
		scale_x, scale_y,
		moon_CircleShape_set_scale
	)
}

void
moon_CircleShapeArray_elscale(
	const moon_CircleShapeArray* self,
	float scale_x, float scale_y,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_vector2f(
		self,
		first_index,
		num_elements,
		scale_x, scale_y,
		moon_CircleShape_scale
	)
}

long long
moon_CircleShapeArray_find_elposition(
	const moon_CircleShapeArray* self,
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
		moon_CircleShape_get_position
	)
	return res;
}

long long
moon_CircleShapeArray_get_elposition(
	const moon_CircleShapeArray* self,
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
		moon_CircleShape_get_position
	)
	return res;
}

void
moon_CircleShapeArray_randomize_elposition(
	const moon_CircleShapeArray* self,
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
		moon_CircleShape_set_position
	)
}

void
moon_CircleShapeArray_set_elposition(
	const moon_CircleShapeArray* self,
	float x, float y,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_vector2f(
		self,
		first_index,
		num_elements,
		x, y,
		moon_CircleShape_set_position
	)
}

void
moon_CircleShapeArray_elmove(
	const moon_CircleShapeArray* self,
	float dx, float dy,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_vector2f(
		self,
		first_index,
		num_elements,
		dx, dy,
		moon_CircleShape_move
	)
}

long long
moon_CircleShapeArray_find_elorigin(
	const moon_CircleShapeArray* self,
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
		moon_CircleShape_get_origin
	)
	return res;
}

long long
moon_CircleShapeArray_get_elorigin(
	const moon_CircleShapeArray* self,
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
		moon_CircleShape_get_origin
	)
	return res;
}

void
moon_CircleShapeArray_randomize_elorigin(
	const moon_CircleShapeArray* self,
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
		moon_CircleShape_set_origin
	)
}

void
moon_CircleShapeArray_set_elorigin(
	const moon_CircleShapeArray* self,
	float origin_x, float origin_y,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_vector2f(
		self,
		first_index,
		num_elements,
		origin_x, origin_y,
		moon_CircleShape_set_origin
	)
}

long long
moon_CircleShapeArray_find_elrotation(
	const moon_CircleShapeArray* self,
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
		moon_CircleShape_get_rotation
	)
	return res;
}

long long
moon_CircleShapeArray_get_elrotation(
	const moon_CircleShapeArray* self,
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
		moon_CircleShape_get_rotation
	)
	return res;
}

void
moon_CircleShapeArray_randomize_elrotation(
	const moon_CircleShapeArray* self,
	int min_angle, int max_angle,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_randomize_value(
		self,
		first_index,
		num_elements,
		min_angle, max_angle,
		moon_CircleShape_set_rotation
	)
}

void
moon_CircleShapeArray_set_elrotation(
	const moon_CircleShapeArray* self,
	moon_Angle angle,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_value(
		self,
		first_index,
		num_elements,
		angle,
		moon_CircleShape_set_rotation
	)
}

void
moon_CircleShapeArray_elrotate(
	const moon_CircleShapeArray* self,
	moon_Angle angle,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_value(
		self,
		first_index,
		num_elements,
		angle,
		moon_CircleShape_rotate
	)
}
