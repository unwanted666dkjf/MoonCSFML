#ifndef MOON_CSFML_EXTRAS_GRAPHICS_GROUP_HPP
#define MOON_CSFML_EXTRAS_GRAPHICS_GROUP_HPP


#include <vector>

#include <limits>

#include <algorithm>


#include "./moon_frect_lst.h"

#include "./moon_bounds_type.h"

#include "./moon_useful_funcs.h"


#include "../system/moon_utils.h"


#include "../graphics/VectorUtils.hpp"

#include "../graphics/moon_render_states.h"

#include "../graphics/moon_render_window.h"


#define moon_GraphicsGroup_HEAD(Type)	\
	int check_visibility;				\
	std::vector<Type*> objects;


template <typename GroupType>
GroupType* moon_GraphicsGroup_create(
	int check_visibility,
	unsigned long initial_capacity
) {
	GroupType* self = new GroupType();
	self->check_visibility = check_visibility;
	self->objects.reserve(initial_capacity);
	return self;
}

template <typename GroupType>
void moon_GraphicsGroup_destroy(GroupType* self) {
	delete self;
}

template <typename GroupType, typename ElementType>
GroupType* moon_GraphicsGroup_get_slice(
	const GroupType* self,
	long long start,
	long long stop,
	long long step
) {
	GroupType* slice = moon_GraphicsGroup_create<GroupType>(self->check_visibility, 1UL);
	slice->objects = moon_vector_slice<ElementType*>(
		self->objects,
		start,
		stop,
		step
	);
	return slice;
}

template <typename GroupType>
int moon_GraphicsGroup_is_empty(const GroupType* self) {
	return self->objects.empty();
}

template <typename GroupType>
int moon_GraphicsGroup_is_check_enabled(const GroupType* self) {
	return self->check_visibility;
}

template <typename GroupType>
int moon_GraphicsGroup_resize(
	GroupType* self,
	unsigned long new_size
) {
	if (new_size <= self->objects.size()) {
		return 0;
	}
	self->objects.resize(new_size);
	return 1;
}

template <typename GroupType>
int moon_GraphicsGroup_reserve(
	GroupType* self,
	unsigned long new_capacity
) {
	if (new_capacity <= self->objects.size()) {
		return 0;
	}
	self->objects.reserve(new_capacity);
	return 1;
}

template <typename GroupType>
unsigned long moon_GraphicsGroup_get_size(const GroupType* self) {
	return self->objects.capacity();
}

template <typename GroupType>
unsigned long moon_GraphicsGroup_get_length(const GroupType* self) {
	return self->objects.size();
}

template <typename GroupType>
void moon_GraphicsGroup_clear(GroupType* self) {
	self->objects.clear();
}

template <typename GroupType>
void moon_GraphicsGroup_reverse(
	GroupType* self,
	unsigned long first_index,
	unsigned long num_elements
) {
	std::reverse(
		self->objects.begin() + first_index,
		self->objects.begin() + first_index + num_elements
	);
}

template <typename GroupType>
void moon_GraphicsGroup_remove(
	GroupType* self,
	unsigned long first_index,
	unsigned long num_elements
) {
	self->objects.erase(
		self->objects.begin() + first_index,
		self->objects.begin() + first_index + num_elements
	);
}

template <typename GroupType, typename ElementType>
void moon_GraphicsGroup_push_back(
	GroupType* self,
	ElementType* element
) {
	self->objects.push_back(element);
}

template <typename GroupType, typename ElementType>
void moon_GraphicsGroup_insert(
	GroupType* self,
	unsigned long index,
	ElementType* element
) {
	self->objects.insert(
		self->objects.begin() + index,
		element
	);
}

template <typename GroupType>
void moon_GraphicsGroup_extend(
	GroupType* self,
	const GroupType* other,
	unsigned long other_first_index,
	unsigned long other_num_elements
) {
	unsigned long end_index = other_first_index + other_num_elements;
	for (; other_first_index < end_index; other_first_index++) {
		self->objects.push_back(other->objects[other_first_index]);
	}
}

template <typename GroupType>
void moon_GraphicsGroup_set_check_enabled(
	GroupType* self,
	int check_visibility
) {
	self->check_visibility = check_visibility;
}

template <typename GroupType, typename ElementType>
ElementType* moon_GraphicsGroup_set(
	GroupType* self,
	unsigned long index,
	ElementType* element
) {
	ElementType* old = self->objects[index];
	self->objects[index] = element;
	return old;
}

template <typename GroupType, typename ElementType>
ElementType* moon_GraphicsGroup_pop(
	GroupType* self,
	unsigned long index
) {
	ElementType* element = self->objects[index];
	self->objects.erase(self->objects.begin() + index);
	return element;
}

template <typename GroupType, typename ElementType>
ElementType* moon_GraphicsGroup_get(
	GroupType* self,
	unsigned long index
) {
	return self->objects[index];
}

#define moon_GraphicsGroup_Procedure_draw(	\
	const_group_pointer,					\
	wnd_pointer,							\
	render_states_pointer,					\
	first_index_ulong,						\
	num_elements_ulong,						\
	get_global_bounds_function,				\
	element_draw_function					\
) 	\
{	\
	unsigned long end_Procedure__ = first_index_ulong + num_elements_ulong;		\
	for (; first_index_ulong < end_Procedure__; first_index_ulong++) {			\
		if (const_group_pointer->check_visibility) {							\
			moon_FloatRect bounds_Procedure__ = get_global_bounds_function(		\
				const_group_pointer->objects[first_index_ulong]					\
			);																	\
			moon_FloatRect visibility_rect_Procedure__ = moon_is_rect_visible(	\
				&bounds_Procedure__, 											\
				wnd_pointer														\
			);																	\
			if (moon_FloatRect_is_empty(&visibility_rect_Procedure__)) {		\
				continue;														\
			}																	\
		}																		\
		element_draw_function(													\
			const_group_pointer->objects[first_index_ulong],					\
			wnd_pointer,														\
			render_states_pointer												\
		);																		\
	}																			\
}

#define moon_GraphicsGroup_Procedure_set_color(	\
	const_group_pointer,						\
	const_color_moon_Color_ptr,					\
	first_index_ulong,							\
	num_elements_ulong,							\
	set_color_function							\
)	\
{	\
	unsigned long end_Procedure__ = first_index_ulong + num_elements_ulong;	\
	for (; first_index_ulong < end_Procedure__; first_index_ulong++) {		\
		set_color_function(													\
			const_group_pointer->objects[first_index_ulong],				\
			const_color_moon_Color_ptr										\
		);																	\
	}																		\
}

#define moon_GraphicsGroup_Procedure_find_alpha(	\
	const_group_pointer,							\
	res_index_longlong,								\
	first_index_ulong,								\
	num_elements_ulong,								\
	alpha_uchar,									\
	get_color_function								\
)	\
{	\
	res_index_longlong = -1LL;													\
	unsigned long end_Procedure__ = first_index_ulong + num_elements_ulong;		\
	for (; first_index_ulong < end_Procedure__; first_index_ulong++) {			\
		moon_Color clr = get_color_function(									\
			const_group_pointer->objects[first_index_ulong]						\
		);																		\
		if (clr.alpha == alpha_uchar) {											\
			res_index_longlong = static_cast<long long>(first_index_ulong);		\
			break;																\
		}																		\
	}																			\
}

#define moon_GraphicsGroup_Procedure_find_color(	\
	const_group_pointer,							\
	res_index_longlong,								\
	first_index_ulong,								\
	num_elements_ulong,								\
	const_color_moon_Color_ptr,						\
	ignore_alpha,									\
	get_color_function								\
)	\
{	\
	res_index_longlong = -1LL;													\
	unsigned long end_Procedure__ = first_index_ulong + num_elements_ulong;		\
	for (; first_index_ulong < end_Procedure__; first_index_ulong++) {			\
		moon_Color clr = get_color_function(									\
			const_group_pointer->objects[first_index_ulong]						\
		);																		\
		if (ignore_alpha) {														\
			if (moon_Color_is_rgb_eq(&clr, const_color_moon_Color_ptr)) {		\
				res_index_longlong = static_cast<long long>(first_index_ulong);	\
				break;															\
			}																	\
		} else {																\
			if (moon_Color_is_eq(&clr, const_color_moon_Color_ptr)) {			\
				res_index_longlong = static_cast<long long>(first_index_ulong);	\
				break;															\
			}																	\
		}																		\
	}																			\
}

#define moon_GraphicsGroup_Procedure_inverse_color(	\
	const_group_pointer,							\
	first_index_ulong,								\
	num_elements_ulong,								\
	set_color_function,								\
	get_color_function								\
)	\
{	\
	unsigned long end_Procedure__ = first_index_ulong + num_elements_ulong;			\
	for (; first_index_ulong < end_Procedure__; first_index_ulong++) {				\
		moon_Color clr = get_color_function(										\
			const_group_pointer->objects[first_index_ulong]							\
		);																			\
		clr.red 	= 255 - clr.red;												\
		clr.green 	= 255 - clr.green;												\
		clr.blue 	= 255 - clr.blue;												\
		set_color_function(const_group_pointer->objects[first_index_ulong], &clr);	\
	}																				\
}

#define moon_GraphicsGroup_Procedure_set_alpha(		\
	const_group_pointer,							\
	alpha_uchar,									\
	first_index_ulong,								\
	num_elements_ulong,								\
	set_color_function,								\
	get_color_function								\
)	\
{	\
	unsigned long end_Procedure__ = first_index_ulong + num_elements_ulong;			\
	for (; first_index_ulong < end_Procedure__; first_index_ulong++) {				\
		moon_Color clr = get_color_function(										\
			const_group_pointer->objects[first_index_ulong]							\
		);																			\
		clr.alpha = alpha_uchar;													\
		set_color_function(const_group_pointer->objects[first_index_ulong], &clr);	\
	}																				\
}

#define moon_GraphicsGroup_Procedure_get_bounds(	\
	const_group_pointer,							\
	res_moon_FRectLst_ptr,							\
	first_index_ulong,								\
	num_elements_ulong,								\
	bounds_type_int,								\
	get_global_bounds_function,						\
	get_local_bounds_function,						\
	get_world_bounds_function						\
)	\
{	\
	if (!res_moon_FRectLst_ptr) {											\
		res_moon_FRectLst_ptr = moon_FRectLst_create(num_elements_ulong);	\
	}																		\
	unsigned long end_Procedure__ = first_index_ulong + num_elements_ulong;	\
	for (; first_index_ulong < end_Procedure__; first_index_ulong++) {		\
		moon_FloatRect bounds_Procedure__;									\
		switch (bounds_type_int) {											\
			case moon_BoundsType_Global:									\
				bounds_Procedure__ = get_global_bounds_function(			\
					const_group_pointer->objects[first_index_ulong]			\
				);															\
				break;														\
			case moon_BoundsType_Local:										\
				bounds_Procedure__ = get_local_bounds_function(				\
					const_group_pointer->objects[first_index_ulong]			\
				);															\
				break;														\
			case moon_BoundsType_World:										\
				bounds_Procedure__ = get_world_bounds_function(				\
					const_group_pointer->objects[first_index_ulong]			\
				);															\
				break;														\
			default:														\
				continue;													\
		}																	\
		moon_FRectLst_push_back(											\
			res_moon_FRectLst_ptr,											\
			&bounds_Procedure__												\
		);																	\
	}																		\
}

#define moon_GraphicsGroup_find_vector2f(	\
	const_group_pointer,					\
	res_index_longlong,						\
	first_index_ulong,						\
	num_elements_ulong,						\
	vector2f_moon_Vector2f_ptr,				\
	get_vector2f_function					\
)	\
{	\
	res_index_longlong = -1LL;													\
	unsigned long end_Procedure__ = first_index_ulong + num_elements_ulong;		\
	for (; first_index_ulong < end_Procedure__; first_index_ulong++) {			\
		moon_Vector2f v_Procedure__ = get_vector2f_function(					\
			const_group_pointer->objects[first_index_ulong]						\
		);																		\
		if (																	\
			(v_Procedure__.x == vector2f_moon_Vector2f_ptr->x)					\
				&& (v_Procedure__.y == vector2f_moon_Vector2f_ptr->y)			\
		) {																		\
			res_index_longlong = static_cast<long long>(first_index_ulong);		\
			break;																\
		}																		\
	}																			\
}

#define moon_GraphicsGroup_Procedure_get_vector2f(	\
	const_group_pointer,							\
	res_index_longlong,								\
	first_index_ulong,								\
	num_elements_ulong,								\
	is_get_min,										\
	is_get_y,										\
	get_vector2f_function							\
)	\
{	\
	res_index_longlong = -1LL;															\
	float value_Procedure__;															\
	if (is_get_min) {																	\
		value_Procedure__ = std::numeric_limits<float>::max();							\
	} else {																			\
		value_Procedure__ = std::numeric_limits<float>::lowest();						\
	}																					\
	unsigned long end_Procedure__ = first_index_ulong + num_elements_ulong;				\
	for (; first_index_ulong < end_Procedure__; first_index_ulong++) {					\
		moon_Vector2f size_Procedure__ = get_vector2f_function(							\
			const_group_pointer->objects[first_index_ulong]								\
		);																				\
		if (is_get_y) {																	\
			if (is_get_min) {															\
				if (size_Procedure__.y < value_Procedure__) {							\
					res_index_longlong 	= static_cast<long long>(first_index_ulong);	\
					value_Procedure__ 	= size_Procedure__.y;							\
				}																		\
			} else {																	\
				if (size_Procedure__.y > value_Procedure__) {							\
					res_index_longlong 	= static_cast<long long>(first_index_ulong);	\
					value_Procedure__ 	= size_Procedure__.y;							\
				}																		\
			}																			\
		} else {																		\
			if (is_get_min) {															\
				if (size_Procedure__.x < value_Procedure__) {							\
					res_index_longlong 	= static_cast<long long>(first_index_ulong);	\
					value_Procedure__ 	= size_Procedure__.x;							\
				}																		\
			} else {																	\
				if (size_Procedure__.x > value_Procedure__) {							\
					res_index_longlong 	= static_cast<long long>(first_index_ulong);	\
					value_Procedure__ 	= size_Procedure__.x;							\
				}																		\
			}																			\
		}																				\
	}																					\
}

#define moon_GraphicsGroup_Procedure_randomize_vector2f(	\
	const_group_pointer,									\
	first_index_ulong,										\
	num_elements_ulong,										\
	minval_x_int, maxval_x_int,								\
	minval_y_int, maxval_y_int,								\
	set_vector2f_function									\
)	\
{	\
	unsigned long end_Procedure__ = first_index_ulong + num_elements_ulong;	\
	for (; first_index_ulong < end_Procedure__; first_index_ulong++) {		\
		int x = moon_random(minval_x_int, maxval_x_int);					\
		int y = moon_random(minval_y_int, maxval_y_int);					\
		set_vector2f_function(												\
			const_group_pointer->objects[first_index_ulong],				\
			static_cast<float>(x),											\
			static_cast<float>(y)											\
		);																	\
	}																		\
}

#define moon_GraphicsGroup_Procedure_set_vector2f(	\
	const_group_pointer,							\
	first_index_ulong,								\
	num_elements_ulong,								\
	xvalue_float, yvalue_float,						\
	set_vector2f_function							\
)	\
{	\
	unsigned long end_Procedure__ = first_index_ulong + num_elements_ulong;	\
	for (; first_index_ulong < end_Procedure__; first_index_ulong++) {		\
		set_vector2f_function(												\
			const_group_pointer->objects[first_index_ulong],				\
			xvalue_float, yvalue_float										\
		);																	\
	}																		\
}

#define moon_GraphicsGroup_Procedure_find_value(	\
	const_group_pointer,							\
	res_index_longlong,								\
	first_index_ulong,								\
	num_elements_ulong,								\
	float_value,									\
	get_value_function								\
)	\
{	\
	res_index_longlong = -1LL;															\
	unsigned long end_Procedure__ = first_index_ulong + num_elements_ulong;				\
	for (; first_index_ulong < end_Procedure__; first_index_ulong++) {					\
		float value_Procedure__ = static_cast<float>(									\
			get_value_function(															\
				const_group_pointer->objects[first_index_ulong]							\
			)																			\
		);																				\
		if (value_Procedure__ == float_value) {											\
			res_index_longlong = static_cast<long long>(first_index_ulong);				\
			break;																		\
		}																				\
	}																					\
}

#define moon_GraphicsGroup_Procedure_get_value(	\
	const_group_pointer,						\
	res_index_longlong,							\
	first_index_ulong,							\
	num_elements_ulong,							\
	is_get_min,									\
	get_value_function							\
)	\
{	\
	res_index_longlong = -1LL;														\
	float value_Procedure__;														\
	if (is_get_min) {																\
		value_Procedure__ = std::numeric_limits<float>::max();						\
	} else {																		\
		value_Procedure__ = std::numeric_limits<float>::lowest();					\
	}																				\
	unsigned long end_Procedure__ = first_index_ulong + num_elements_ulong;			\
	for (; first_index_ulong < end_Procedure__; first_index_ulong++) {				\
		float v_Procedure__ = static_cast<float>(									\
			get_value_function(const_group_pointer->objects[first_index_ulong])		\
		);																			\
		if (is_get_min) {															\
			if (v_Procedure__ < value_Procedure__) {								\
				value_Procedure__ 	= v_Procedure__;								\
				res_index_longlong 	= static_cast<long long>(first_index_ulong);	\
			}																		\
		} else {																	\
			if (v_Procedure__ > value_Procedure__) {								\
				value_Procedure__ 	= v_Procedure__;								\
				res_index_longlong 	= static_cast<long long>(first_index_ulong);	\
			}																		\
		}																			\
	}																				\
}

#define moon_GraphicsGroup_Procedure_randomize_value(	\
	const_group_pointer,								\
	first_index_ulong,									\
	num_elements_ulong,									\
	minval_int, maxval_int,								\
	set_value_function									\
)	\
{	\
	unsigned long end_Procedure__ = first_index_ulong + num_elements_ulong;	\
	for (; first_index_ulong < end_Procedure__; first_index_ulong++) {		\
		int value = moon_random(minval_int, maxval_int);					\
		set_value_function(													\
			const_group_pointer->objects[first_index_ulong],				\
			static_cast<float>(value)										\
		);																	\
	}																		\
}

#define moon_GraphicsGroup_Procedure_set_value(	\
	const_group_pointer,						\
	first_index_ulong,							\
	num_elements_ulong,							\
	value_float,								\
	set_value_function							\
)	\
{	\
	unsigned long end_Procedure__ = first_index_ulong + num_elements_ulong;	\
	for (; first_index_ulong < end_Procedure__; first_index_ulong++) {		\
		set_value_function(													\
			const_group_pointer->objects[first_index_ulong],				\
			value_float														\
		);																	\
	}																		\
}


#endif
