#include "../../headers/extras/moon_slide_show_array.h"

#include "../../headers/extras/GraphicsGroup.hpp"


struct moon_SlideShowArray {
	moon_GraphicsGroup_HEAD(moon_SlideShow)
};


moon_SlideShowArray*
moon_SlideShowArray_create(
	int check_visibility,
	unsigned long initial_capacity
) {
	return moon_GraphicsGroup_create<moon_SlideShowArray>(
		check_visibility,
		initial_capacity
	);
}

void
moon_SlideShowArray_destroy(moon_SlideShowArray* self) {
	moon_GraphicsGroup_destroy<moon_SlideShowArray>(self);
}

moon_SlideShowArray*
moon_SlideShowArray_get_slice(
	const moon_SlideShowArray* self,
	long long start,
	long long stop,
	long long step
) {
	return moon_GraphicsGroup_get_slice<moon_SlideShowArray, moon_SlideShow>(
		self,
		start,
		stop,
		step
	);
}

int
moon_SlideShowArray_is_empty(const moon_SlideShowArray* self) {
	return moon_GraphicsGroup_is_empty<moon_SlideShowArray>(self);
}

int
moon_SlideShowArray_is_check_enabled(const moon_SlideShowArray* self) {
	return moon_GraphicsGroup_is_check_enabled<moon_SlideShowArray>(self);
}

int
moon_SlideShowArray_resize(
	moon_SlideShowArray* self,
	unsigned long new_size
) {
	return moon_GraphicsGroup_resize<moon_SlideShowArray>(self, new_size);
}

int
moon_SlideShowArray_reserve(
	moon_SlideShowArray* self,
	unsigned long new_capacity
) {
	return moon_GraphicsGroup_reserve<moon_SlideShowArray>(self, new_capacity);
}

unsigned long
moon_SlideShowArray_get_size(const moon_SlideShowArray* self) {
	return moon_GraphicsGroup_get_size<moon_SlideShowArray>(self);
}

unsigned long
moon_SlideShowArray_get_length(const moon_SlideShowArray* self) {
	return moon_GraphicsGroup_get_length<moon_SlideShowArray>(self);
}

void
moon_SlideShowArray_clear(moon_SlideShowArray* self) {
	moon_GraphicsGroup_clear<moon_SlideShowArray>(self);
}

void
moon_SlideShowArray_reverse(
	moon_SlideShowArray* self,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_reverse<moon_SlideShowArray>(self, first_index, num_elements);
}

void
moon_SlideShowArray_remove(
	moon_SlideShowArray* self,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_remove<moon_SlideShowArray>(self, first_index, num_elements);
}

void
moon_SlideShowArray_push_back(
	moon_SlideShowArray* self,
	moon_SlideShow* element
) {
	moon_GraphicsGroup_push_back<moon_SlideShowArray, moon_SlideShow>(self, element);
}

void
moon_SlideShowArray_insert(
	moon_SlideShowArray* self,
	unsigned long index,
	moon_SlideShow* element
) {
	moon_GraphicsGroup_insert<moon_SlideShowArray, moon_SlideShow>(self, index, element);
}

void
moon_SlideShowArray_extend(
	moon_SlideShowArray* self,
	const moon_SlideShowArray* other,
	unsigned long other_first_index,
	unsigned long other_num_elements
) {
	moon_GraphicsGroup_extend<moon_SlideShowArray>(
		self,
		other,
		other_first_index,
		other_num_elements
	);
}

void
moon_SlideShowArray_set_check_enabled(
	moon_SlideShowArray* self,
	int check_visibility
) {
	moon_GraphicsGroup_set_check_enabled<moon_SlideShowArray>(self, check_visibility);
}

moon_SlideShow*
moon_SlideShowArray_set(
	moon_SlideShowArray* self,
	unsigned long index,
	moon_SlideShow* element
) {
	return moon_GraphicsGroup_set<moon_SlideShowArray, moon_SlideShow>(self, index, element);
}

moon_SlideShow*
moon_SlideShowArray_pop(
	moon_SlideShowArray* self,
	unsigned long index
) {
	return moon_GraphicsGroup_pop<moon_SlideShowArray, moon_SlideShow>(self, index);
}

moon_SlideShow*
moon_SlideShowArray_get(
	moon_SlideShowArray* self,
	unsigned long index
) {
	return moon_GraphicsGroup_get<moon_SlideShowArray, moon_SlideShow>(self, index);
}

void
moon_SlideShowArray_draw(
	const moon_SlideShowArray* self,
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
		moon_SlideShow_get_global_bounds,
		moon_SlideShow_draw
	)
}

void
moon_SlideShowArray_set_color(
	const moon_SlideShowArray* self,
	const moon_Color* color,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_color(
		self,
		color,
		first_index,
		num_elements,
		moon_SlideShow_set_color
	)
}

long long
moon_SlideShowArray_find_alpha(
	const moon_SlideShowArray* self,
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
		moon_SlideShow_get_color
	)
	return res;
}

long long
moon_SlideShowArray_find_color(
	const moon_SlideShowArray* self,
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
		moon_SlideShow_get_color
	)
	return res;
}

void
moon_SlideShowArray_inverse_color(
	const moon_SlideShowArray* self,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_inverse_color(
		self,
		first_index,
		num_elements,
		moon_SlideShow_set_color,
		moon_SlideShow_get_color
	)
}

void
moon_SlideShowArray_set_alpha(
	const moon_SlideShowArray* self,
	unsigned char alpha,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_alpha(
		self,
		alpha,
		first_index,
		num_elements,
		moon_SlideShow_set_color,
		moon_SlideShow_get_color
	)
}

moon_FRectLst*
moon_SlideShowArray_get_bounds(
	const moon_SlideShowArray* self,
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
		moon_SlideShow_get_global_bounds,
		moon_SlideShow_get_local_bounds,
		moon_SlideShow_get_world_bounds
	)
	return res;
}

long long
moon_SlideShowArray_find_elsize(
	const moon_SlideShowArray* self,
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
		moon_SlideShow_get_size
	)
	return res;
}

long long
moon_SlideShowArray_get_elsize(
	const moon_SlideShowArray* self,
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
		moon_SlideShow_get_size
	)
	return res;
}

long long
moon_SlideShowArray_find_elscale(
	const moon_SlideShowArray* self,
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
		moon_SlideShow_get_scale
	)
	return res;
}

long long
moon_SlideShowArray_get_elscale(
	const moon_SlideShowArray* self,
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
		moon_SlideShow_get_scale
	)
	return res;
}

long long
moon_SlideShowArray_find_elposition(
	const moon_SlideShowArray* self,
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
		moon_SlideShow_get_position
	)
	return res;
}

long long
moon_SlideShowArray_get_elposition(
	const moon_SlideShowArray* self,
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
		moon_SlideShow_get_position
	)
	return res;
}

void
moon_SlideShowArray_randomize_elposition(
	const moon_SlideShowArray* self,
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
		moon_SlideShow_set_position
	)
}

void
moon_SlideShowArray_set_elposition(
	const moon_SlideShowArray* self,
	float x, float y,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_vector2f(
		self,
		first_index,
		num_elements,
		x, y,
		moon_SlideShow_set_position
	)
}

void
moon_SlideShowArray_elmove(
	const moon_SlideShowArray* self,
	float dx, float dy,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_vector2f(
		self,
		first_index,
		num_elements,
		dx, dy,
		moon_SlideShow_move
	)
}

long long
moon_SlideShowArray_find_elrotation(
	const moon_SlideShowArray* self,
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
		moon_SlideShow_get_rotation
	)
	return res;
}

long long
moon_SlideShowArray_get_elrotation(
	const moon_SlideShowArray* self,
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
		moon_SlideShow_get_rotation
	)
	return res;
}

void
moon_SlideShowArray_randomize_elrotation(
	const moon_SlideShowArray* self,
	int min_angle, int max_angle,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_randomize_value(
		self,
		first_index,
		num_elements,
		min_angle, max_angle,
		moon_SlideShow_set_rotation
	)
}

void
moon_SlideShowArray_set_elrotation(
	const moon_SlideShowArray* self,
	moon_Angle angle,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_value(
		self,
		first_index,
		num_elements,
		angle,
		moon_SlideShow_set_rotation
	)
}

void
moon_SlideShowArray_elrotate(
	const moon_SlideShowArray* self,
	moon_Angle angle,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_value(
		self,
		first_index,
		num_elements,
		angle,
		moon_SlideShow_rotate
	)
}
