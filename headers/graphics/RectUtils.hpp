#ifndef MOON_CSFML_GRAPHICS_RECT_UTILS_HPP
#define MOON_CSFML_GRAPHICS_RECT_UTILS_HPP


#include <algorithm>


template <typename Rect>
int moon_Rect_is_empty(const Rect* self) {
	return self->width <= 0 && self->height <= 0;
}

template <typename Rect, typename T>
int moon_Rect_contains(
	const Rect* self,
	T x, T y
) {
	return x >= self->left
		&& x <= self->left + self->width
		&& y >= self->top
		&& y <= self->top + self->height;
}

template <typename Rect>
int moon_Rect_is_eq(
	const Rect* self,
	const Rect* other
) {
	return self->left 	== other->left
		&& self->top 	== other->top
		&& self->width 	== other->width
		&& self->height == other->height;
}

template <typename Rect>
int moon_Rect_is_ne(
	const Rect* self,
	const Rect* other
) {
	return !moon_Rect_is_eq<Rect>(self, other);
}

template <typename Rect>
Rect moon_Rect_create_empty() {
	return Rect{0, 0, 0, 0};
}

template <typename Rect>
Rect moon_Rect_get_intersection(
	const Rect* self,
	const Rect* other
) {
	const auto left = std::max(self->left, other->left);
	const auto top = std::max(self->top, other->top);

	const auto right = std::min(
		self->left + self->width,
		other->left + other->width
	);

	const auto bottom = std::min(
		self->top + self->height,
		other->top + other->height
	);

	const auto width = right - left;
	const auto height = bottom - top;

	if (width <= 0 || height <= 0) {
		return moon_Rect_create_empty<Rect>();
	}

	return Rect{left, top, width, height};
}

template<typename TypeFrom, typename TypeTo, typename VartypeTo>
TypeTo moon_Rect_convert(const TypeFrom* self) {
	return TypeTo{
		static_cast<VartypeTo>(self->left),
		static_cast<VartypeTo>(self->top),
		static_cast<VartypeTo>(self->width),
		static_cast<VartypeTo>(self->height)
	};
}


#endif
