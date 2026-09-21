#ifndef MOON_CSFML_GRAPHICS_TRANSFORMABLE_UTILS_HPP
#define MOON_CSFML_GRAPHICS_TRANSFORMABLE_UTILS_HPP


#include "./Converters.hpp"

#include "./moon_transform.h"


#include "../system/moon_vector2.h"


template <typename Transformable>
moon_Vector2f moon_Transformable_get_position(const Transformable* self) {
	return {self->m_position.x, self->m_position.y};
}

template <typename Transformable>
moon_Vector2f moon_Transformable_get_scale(const Transformable* self) {
	return {self->m_scale.x, self->m_scale.y};
}

template <typename Transformable>
moon_Vector2f moon_Transformable_get_origin(const Transformable* self) {
	return {self->m_origin.x, self->m_origin.y};
}

template <typename Transformable>
moon_Transform moon_Transformable_get_transform(const Transformable* self) {
	// Not a complete rewrite because it modifies internal SFML transform.
	return transform_sf_to_moon(self->getTransform());
}

template <typename Transformable>
moon_Transform moon_Transformable_get_inverse_transform(const Transformable* self) {
	// Not a complete rewrite because it modifies internal SFML transform.
	return transform_sf_to_moon(self->getInverseTransform());
}


#endif
