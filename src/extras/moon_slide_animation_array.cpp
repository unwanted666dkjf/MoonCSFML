#include "../../headers/extras/moon_slide_animation_array.h"

#include "../../headers/extras/GraphicsGroup.hpp"


struct moon_SlideAnimationArray {
	moon_GraphicsGroup_HEAD(moon_SlideAnimation)
};


moon_SlideAnimationArray*
moon_SlideAnimationArray_create(
	int check_visibility,
	unsigned long initial_capacity
) {
	return moon_GraphicsGroup_create<moon_SlideAnimationArray>(
		check_visibility,
		initial_capacity
	);
}

void
moon_SlideAnimationArray_destroy(moon_SlideAnimationArray* self) {
	moon_GraphicsGroup_destroy<moon_SlideAnimationArray>(self);
}

moon_SlideAnimationArray*
moon_SlideAnimationArray_get_slice(
	const moon_SlideAnimationArray* self,
	long long start,
	long long stop,
	long long step
) {
	return moon_GraphicsGroup_get_slice<moon_SlideAnimationArray, moon_SlideAnimation>(
		self,
		start,
		stop,
		step
	);
}

int
moon_SlideAnimationArray_is_empty(const moon_SlideAnimationArray* self) {
	return moon_GraphicsGroup_is_empty<moon_SlideAnimationArray>(self);
}

int
moon_SlideAnimationArray_is_check_enabled(const moon_SlideAnimationArray* self) {
	return moon_GraphicsGroup_is_check_enabled<moon_SlideAnimationArray>(self);
}

int
moon_SlideAnimationArray_resize(
	moon_SlideAnimationArray* self,
	unsigned long new_size
) {
	return moon_GraphicsGroup_resize<moon_SlideAnimationArray>(self, new_size);
}

int
moon_SlideAnimationArray_reserve(
	moon_SlideAnimationArray* self,
	unsigned long new_capacity
) {
	return moon_GraphicsGroup_reserve<moon_SlideAnimationArray>(self, new_capacity);
}

unsigned long
moon_SlideAnimationArray_get_size(const moon_SlideAnimationArray* self) {
	return moon_GraphicsGroup_get_size<moon_SlideAnimationArray>(self);
}

unsigned long
moon_SlideAnimationArray_get_length(const moon_SlideAnimationArray* self) {
	return moon_GraphicsGroup_get_length<moon_SlideAnimationArray>(self);
}

void
moon_SlideAnimationArray_clear(moon_SlideAnimationArray* self) {
	moon_GraphicsGroup_clear<moon_SlideAnimationArray>(self);
}

void
moon_SlideAnimationArray_reverse(
	moon_SlideAnimationArray* self,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_reverse<moon_SlideAnimationArray>(self, first_index, num_elements);
}

void
moon_SlideAnimationArray_remove(
	moon_SlideAnimationArray* self,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_remove<moon_SlideAnimationArray>(self, first_index, num_elements);
}

void
moon_SlideAnimationArray_push_back(
	moon_SlideAnimationArray* self,
	moon_SlideAnimation* element
) {
	moon_GraphicsGroup_push_back<moon_SlideAnimationArray, moon_SlideAnimation>(self, element);
}

void
moon_SlideAnimationArray_insert(
	moon_SlideAnimationArray* self,
	unsigned long index,
	moon_SlideAnimation* element
) {
	moon_GraphicsGroup_insert<moon_SlideAnimationArray, moon_SlideAnimation>(self, index, element);
}

void
moon_SlideAnimationArray_extend(
	moon_SlideAnimationArray* self,
	const moon_SlideAnimationArray* other,
	unsigned long other_first_index,
	unsigned long other_num_elements
) {
	moon_GraphicsGroup_extend<moon_SlideAnimationArray>(
		self,
		other,
		other_first_index,
		other_num_elements
	);
}

void
moon_SlideAnimationArray_set_check_enabled(
	moon_SlideAnimationArray* self,
	int check_visibility
) {
	moon_GraphicsGroup_set_check_enabled<moon_SlideAnimationArray>(self, check_visibility);
}

moon_SlideAnimation*
moon_SlideAnimationArray_set(
	moon_SlideAnimationArray* self,
	unsigned long index,
	moon_SlideAnimation* element
) {
	return moon_GraphicsGroup_set<moon_SlideAnimationArray, moon_SlideAnimation>(self, index, element);
}

moon_SlideAnimation*
moon_SlideAnimationArray_pop(
	moon_SlideAnimationArray* self,
	unsigned long index
) {
	return moon_GraphicsGroup_pop<moon_SlideAnimationArray, moon_SlideAnimation>(self, index);
}

moon_SlideAnimation*
moon_SlideAnimationArray_get(
	moon_SlideAnimationArray* self,
	unsigned long index
) {
	return moon_GraphicsGroup_get<moon_SlideAnimationArray, moon_SlideAnimation>(self, index);
}

void
moon_SlideAnimationArray_draw(
	const moon_SlideAnimationArray* self,
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
		moon_SlideAnimation_get_global_bounds,
		moon_SlideAnimation_draw
	)
}

void
moon_SlideAnimationArray_set_color(
	const moon_SlideAnimationArray* self,
	const moon_Color* color,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_color(
		self,
		color,
		first_index,
		num_elements,
		moon_SlideAnimation_set_color
	)
}

long long
moon_SlideAnimationArray_find_alpha(
	const moon_SlideAnimationArray* self,
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
		moon_SlideAnimation_get_color
	)
	return res;
}

long long
moon_SlideAnimationArray_find_color(
	const moon_SlideAnimationArray* self,
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
		moon_SlideAnimation_get_color
	)
	return res;
}

void
moon_SlideAnimationArray_inverse_color(
	const moon_SlideAnimationArray* self,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_inverse_color(
		self,
		first_index,
		num_elements,
		moon_SlideAnimation_set_color,
		moon_SlideAnimation_get_color
	)
}

void
moon_SlideAnimationArray_set_alpha(
	const moon_SlideAnimationArray* self,
	unsigned char alpha,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_alpha(
		self,
		alpha,
		first_index,
		num_elements,
		moon_SlideAnimation_set_color,
		moon_SlideAnimation_get_color
	)
}

moon_FRectLst*
moon_SlideAnimationArray_get_bounds(
	const moon_SlideAnimationArray* self,
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
		moon_SlideAnimation_get_global_bounds,
		moon_SlideAnimation_get_local_bounds,
		moon_SlideAnimation_get_world_bounds
	)
	return res;
}

long long
moon_SlideAnimationArray_find_elsize(
	const moon_SlideAnimationArray* self,
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
		moon_SlideAnimation_get_size
	)
	return res;
}

long long
moon_SlideAnimationArray_get_elsize(
	const moon_SlideAnimationArray* self,
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
		moon_SlideAnimation_get_size
	)
	return res;
}

long long
moon_SlideAnimationArray_find_elscale(
	const moon_SlideAnimationArray* self,
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
		moon_SlideAnimation_get_scale
	)
	return res;
}

long long
moon_SlideAnimationArray_get_elscale(
	const moon_SlideAnimationArray* self,
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
		moon_SlideAnimation_get_scale
	)
	return res;
}

long long
moon_SlideAnimationArray_find_elposition(
	const moon_SlideAnimationArray* self,
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
		moon_SlideAnimation_get_position
	)
	return res;
}

long long
moon_SlideAnimationArray_get_elposition(
	const moon_SlideAnimationArray* self,
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
		moon_SlideAnimation_get_position
	)
	return res;
}

void
moon_SlideAnimationArray_randomize_elposition(
	const moon_SlideAnimationArray* self,
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
		moon_SlideAnimation_set_position
	)
}

void
moon_SlideAnimationArray_set_elposition(
	const moon_SlideAnimationArray* self,
	float x, float y,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_vector2f(
		self,
		first_index,
		num_elements,
		x, y,
		moon_SlideAnimation_set_position
	)
}

void
moon_SlideAnimationArray_elmove(
	const moon_SlideAnimationArray* self,
	float dx, float dy,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_vector2f(
		self,
		first_index,
		num_elements,
		dx, dy,
		moon_SlideAnimation_move
	)
}

long long
moon_SlideAnimationArray_find_elrotation(
	const moon_SlideAnimationArray* self,
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
		moon_SlideAnimation_get_rotation
	)
	return res;
}

long long
moon_SlideAnimationArray_get_elrotation(
	const moon_SlideAnimationArray* self,
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
		moon_SlideAnimation_get_rotation
	)
	return res;
}

void
moon_SlideAnimationArray_randomize_elrotation(
	const moon_SlideAnimationArray* self,
	int min_angle, int max_angle,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_randomize_value(
		self,
		first_index,
		num_elements,
		min_angle, max_angle,
		moon_SlideAnimation_set_rotation
	)
}

void
moon_SlideAnimationArray_set_elrotation(
	const moon_SlideAnimationArray* self,
	moon_Angle angle,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_value(
		self,
		first_index,
		num_elements,
		angle,
		moon_SlideAnimation_set_rotation
	)
}

void
moon_SlideAnimationArray_elrotate(
	const moon_SlideAnimationArray* self,
	moon_Angle angle,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_GraphicsGroup_Procedure_set_value(
		self,
		first_index,
		num_elements,
		angle,
		moon_SlideAnimation_rotate
	)
}
