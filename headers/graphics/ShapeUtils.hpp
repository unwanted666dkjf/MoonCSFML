#ifndef MOON_CSFML_GRAPHICS_SHAPE_UTILS_HPP
#define MOON_CSFML_GRAPHICS_SHAPE_UTILS_HPP


#include <cstddef>



#include <SFML/System/Vector2.hpp>



#include "./Converters.hpp"

#include "./moon_texture.h"


#include "../system/moon_vector2.h"


template <typename Shape>
void moon_Shape_set_texture_rect(
	Shape* self,
	const moon_IntRect* rect
) {
	self->setTextureRect(int_rect_moon_to_sf(*rect));
}

template <typename Shape>
void moon_Shape_set_fill_color(
	Shape* self,
	const moon_Color* color
) {
	self->setFillColor(color_moon_to_sf(*color));
}

template <typename Shape>
void moon_Shape_set_outline_color(
	Shape* self,
	const moon_Color* color
) {
	self->setOutlineColor(color_moon_to_sf(*color));
}

template <typename Shape>
const moon_Texture* moon_Shape_get_texture(const Shape* self) {
	return static_cast<const moon_Texture*>(self->getTexture());
}

template <typename Shape>
moon_IntRect moon_Shape_get_texture_rect(const Shape* self) {
	return int_rect_sf_to_moon(self->getTextureRect());
}

template <typename Shape>
moon_Color moon_Shape_get_fill_color(const Shape* self) {
	return color_sf_to_moon(self->getFillColor());
}

template <typename Shape>
moon_Color moon_Shape_get_outline_color(const Shape* self) {
	return color_sf_to_moon(self->getOutlineColor());
}

template <typename Shape>
unsigned long moon_Shape_get_point_count(const Shape* self) {
	return static_cast<unsigned long>(self->getPointCount());
}

template <typename Shape>
moon_Vector2f moon_Shape_get_point(
	const Shape* self,
	unsigned long index
) {
	sf::Vector2f p = self->getPoint(static_cast<std::size_t>(index));
	return {p.x, p.y};
}

template <typename Shape>
moon_FloatRect moon_Shape_get_local_bounds(const Shape* self) {
	return float_rect_sf_to_moon(self->m_bounds);
}

template <typename Shape>
moon_FloatRect moon_Shape_get_global_bounds(const Shape* self) {
	return float_rect_sf_to_moon(self->getGlobalBounds());
}


#endif
