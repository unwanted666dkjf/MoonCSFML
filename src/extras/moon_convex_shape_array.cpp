#include "../../headers/extras/moon_convex_shape_array.h"

#include "../../headers/extras/GraphicsGroup.hpp"


struct moon_ConvexShapeArray {
	moon_GraphicsGroup_HEAD(moon_ConvexShape)
};


moon_ConvexShapeArray*
moon_ConvexShapeArray_create(
	int check_visibility,
	unsigned long initial_capacity
) {
	return moon_GraphicsGroup_create<moon_ConvexShapeArray>(
		check_visibility,
		initial_capacity
	);
}

void
moon_ConvexShapeArray_destroy(moon_ConvexShapeArray* self) {
	moon_GraphicsGroup_destroy<moon_ConvexShapeArray>(self);
}

moon_ConvexShapeArray*
moon_ConvexShapeArray_get_slice(
	const moon_ConvexShapeArray* self,
	long long start,
	long long stop,
	long long step
) {
	return moon_GraphicsGroup_get_slice<moon_ConvexShapeArray, moon_ConvexShape>(
		self,
		start,
		stop,
		step
	);
}

int
moon_ConvexShapeArray_is_empty(const moon_ConvexShapeArray* self) {
	return moon_GraphicsGroup_is_empty<moon_ConvexShapeArray>(self);
}

int
moon_ConvexShapeArray_is_check_enabled(const moon_ConvexShapeArray* self) {
	return moon_GraphicsGroup_is_check_enabled<moon_ConvexShapeArray>(self);
}

int
moon_ConvexShapeArray_resize(
	moon_ConvexShapeArray* self,
	unsigned long new_size
) {
	return moon_GraphicsGroup_resize<moon_ConvexShapeArray>(self, new_size);
}

int
moon_ConvexShapeArray_reserve(
	moon_ConvexShapeArray* self,
	unsigned long new_capacity
) {
	return moon_GraphicsGroup_reserve<moon_ConvexShapeArray>(self, new_capacity);
}

unsigned long
moon_ConvexShapeArray_get_size(const moon_ConvexShapeArray* self) {
	return moon_GraphicsGroup_get_size<moon_ConvexShapeArray>(self);
}

unsigned long
moon_ConvexShapeArray_get_length(const moon_ConvexShapeArray* self) {
	return moon_GraphicsGroup_get_length<moon_ConvexShapeArray>(self);
}

void
moon_ConvexShapeArray_clear(moon_ConvexShapeArray* self) {
	moon_GraphicsGroup_clear<moon_ConvexShapeArray>(self);
}

void
moon_ConvexShapeArray_reverse(
	moon_ConvexShapeArray* self,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_reverse<moon_ConvexShapeArray>(self, first_index, num_elements);
}

void
moon_ConvexShapeArray_remove(
	moon_ConvexShapeArray* self,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_remove<moon_ConvexShapeArray>(self, first_index, num_elements);
}

void
moon_ConvexShapeArray_push_back(
	moon_ConvexShapeArray* self,
	moon_ConvexShape* element
) {
	moon_GraphicsGroup_push_back<moon_ConvexShapeArray, moon_ConvexShape>(self, element);
}

void
moon_ConvexShapeArray_insert(
	moon_ConvexShapeArray* self,
	unsigned long index,
	moon_ConvexShape* element
) {
	moon_GraphicsGroup_insert<moon_ConvexShapeArray, moon_ConvexShape>(self, index, element);
}

void
moon_ConvexShapeArray_extend(
	moon_ConvexShapeArray* self,
	const moon_ConvexShapeArray* other,
	unsigned long other_first_index,
	unsigned long other_num_elements
) {
	moon_GraphicsGroup_extend<moon_ConvexShapeArray>(
		self,
		other,
		other_first_index,
		other_num_elements
	);
}

void
moon_ConvexShapeArray_set_check_enabled(
	moon_ConvexShapeArray* self,
	int check_visibility
) {
	moon_GraphicsGroup_set_check_enabled<moon_ConvexShapeArray>(self, check_visibility);
}

moon_ConvexShape*
moon_ConvexShapeArray_set(
	moon_ConvexShapeArray* self,
	unsigned long index,
	moon_ConvexShape* element
) {
	return moon_GraphicsGroup_set<moon_ConvexShapeArray, moon_ConvexShape>(self, index, element);
}

moon_ConvexShape*
moon_ConvexShapeArray_pop(
	moon_ConvexShapeArray* self,
	unsigned long index
) {
	return moon_GraphicsGroup_pop<moon_ConvexShapeArray, moon_ConvexShape>(self, index);
}

moon_ConvexShape*
moon_ConvexShapeArray_get(
	moon_ConvexShapeArray* self,
	unsigned long index
) {
	return moon_GraphicsGroup_get<moon_ConvexShapeArray, moon_ConvexShape>(self, index);
}

void
moon_ConvexShapeArray_draw(
	const moon_ConvexShapeArray* self,
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
		moon_ConvexShape_get_global_bounds,
		moon_ConvexShape_draw
	)
}

void
moon_ConvexShapeArray_set_color(
	const moon_ConvexShapeArray* self,
	const moon_Color* color,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_color(
		self,
		color,
		first_index,
		num_elements,
		moon_ConvexShape_set_fill_color
	)
}

long long
moon_ConvexShapeArray_find_alpha(
	const moon_ConvexShapeArray* self,
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
		moon_ConvexShape_get_fill_color
	)
	return res;
}

long long
moon_ConvexShapeArray_find_color(
	const moon_ConvexShapeArray* self,
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
		moon_ConvexShape_get_fill_color
	)
	return res;
}

void
moon_ConvexShapeArray_inverse_color(
	const moon_ConvexShapeArray* self,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_inverse_color(
		self,
		first_index,
		num_elements,
		moon_ConvexShape_set_fill_color,
		moon_ConvexShape_get_fill_color
	)
}

void
moon_ConvexShapeArray_set_alpha(
	const moon_ConvexShapeArray* self,
	unsigned char alpha,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_alpha(
		self,
		alpha,
		first_index,
		num_elements,
		moon_ConvexShape_set_fill_color,
		moon_ConvexShape_get_fill_color
	)
}

moon_FRectLst*
moon_ConvexShapeArray_get_bounds(
	const moon_ConvexShapeArray* self,
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
		moon_ConvexShape_get_global_bounds,
		moon_ConvexShape_get_local_bounds,
		moon_ConvexShape_get_world_bounds
	)
	return res;
}

long long
moon_ConvexShapeArray_find_elsize(
	const moon_ConvexShapeArray* self,
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
		moon_ConvexShape_get_size
	)
	return res;
}

long long
moon_ConvexShapeArray_get_elsize(
	const moon_ConvexShapeArray* self,
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
		moon_ConvexShape_get_size
	)
	return res;
}

long long
moon_ConvexShapeArray_find_elscale(
	const moon_ConvexShapeArray* self,
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
		moon_ConvexShape_get_scale
	)
	return res;
}

long long
moon_ConvexShapeArray_get_elscale(
	const moon_ConvexShapeArray* self,
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
		moon_ConvexShape_get_scale
	)
	return res;
}

void
moon_ConvexShapeArray_set_elscale(
	const moon_ConvexShapeArray* self,
	float scale_x, float scale_y,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_vector2f(
		self,
		first_index,
		num_elements,
		scale_x, scale_y,
		moon_ConvexShape_set_scale
	)
}

void
moon_ConvexShapeArray_elscale(
	const moon_ConvexShapeArray* self,
	float scale_x, float scale_y,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_vector2f(
		self,
		first_index,
		num_elements,
		scale_x, scale_y,
		moon_ConvexShape_scale
	)
}

long long
moon_ConvexShapeArray_find_elposition(
	const moon_ConvexShapeArray* self,
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
		moon_ConvexShape_get_position
	)
	return res;
}

long long
moon_ConvexShapeArray_get_elposition(
	const moon_ConvexShapeArray* self,
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
		moon_ConvexShape_get_position
	)
	return res;
}

void
moon_ConvexShapeArray_randomize_elposition(
	const moon_ConvexShapeArray* self,
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
		moon_ConvexShape_set_position
	)
}

void
moon_ConvexShapeArray_set_elposition(
	const moon_ConvexShapeArray* self,
	float x, float y,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_vector2f(
		self,
		first_index,
		num_elements,
		x, y,
		moon_ConvexShape_set_position
	)
}

void
moon_ConvexShapeArray_elmove(
	const moon_ConvexShapeArray* self,
	float dx, float dy,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_vector2f(
		self,
		first_index,
		num_elements,
		dx, dy,
		moon_ConvexShape_move
	)
}

long long
moon_ConvexShapeArray_find_elorigin(
	const moon_ConvexShapeArray* self,
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
		moon_ConvexShape_get_origin
	)
	return res;
}

long long
moon_ConvexShapeArray_get_elorigin(
	const moon_ConvexShapeArray* self,
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
		moon_ConvexShape_get_origin
	)
	return res;
}

void
moon_ConvexShapeArray_randomize_elorigin(
	const moon_ConvexShapeArray* self,
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
		moon_ConvexShape_set_origin
	)
}

void
moon_ConvexShapeArray_set_elorigin(
	const moon_ConvexShapeArray* self,
	float origin_x, float origin_y,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_vector2f(
		self,
		first_index,
		num_elements,
		origin_x, origin_y,
		moon_ConvexShape_set_origin
	)
}

long long
moon_ConvexShapeArray_find_elrotation(
	const moon_ConvexShapeArray* self,
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
		moon_ConvexShape_get_rotation
	)
	return res;
}

long long
moon_ConvexShapeArray_get_elrotation(
	const moon_ConvexShapeArray* self,
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
		moon_ConvexShape_get_rotation
	)
	return res;
}

void
moon_ConvexShapeArray_randomize_elrotation(
	const moon_ConvexShapeArray* self,
	int min_angle, int max_angle,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_randomize_value(
		self,
		first_index,
		num_elements,
		min_angle, max_angle,
		moon_ConvexShape_set_rotation
	)
}

void
moon_ConvexShapeArray_set_elrotation(
	const moon_ConvexShapeArray* self,
	moon_Angle angle,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_value(
		self,
		first_index,
		num_elements,
		angle,
		moon_ConvexShape_set_rotation
	)
}

void
moon_ConvexShapeArray_elrotate(
	const moon_ConvexShapeArray* self,
	moon_Angle angle,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_value(
		self,
		first_index,
		num_elements,
		angle,
		moon_ConvexShape_rotate
	)
}
