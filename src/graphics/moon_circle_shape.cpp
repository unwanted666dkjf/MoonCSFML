// Here goes total disrespect of access modifiers.

#define private public

#define protected public


#include "../../headers/graphics/moon_circle_shape.h"

#include "../../headers/graphics/ShapeUtils.hpp"

#include "../../headers/graphics/TransformableUtils.hpp"

#include "../../headers/graphics/TextureStruct.hpp"

#include "../../headers/graphics/RenderStatesStruct.hpp"

#include "../../headers/graphics/RenderWindowStruct.hpp"

#include "../../headers/graphics/CircleShapeStruct.hpp"


moon_CircleShape*
moon_CircleShape_default(
	float radius,
	unsigned long point_count
) {
	return new moon_CircleShape(radius, point_count);
}

moon_CircleShape*
moon_CircleShape_create(
	float radius,
	unsigned long point_count,
	const moon_Color* fill_color
) {
	moon_CircleShape* self = moon_CircleShape_default(radius, point_count);
	moon_CircleShape_set_fill_color(self, fill_color);
	return self;
}

moon_CircleShape*
moon_CircleShape_create_ex(
	float radius,
	unsigned long point_count,
	const moon_Color* fill_color,
	float left, float top
) {
	moon_CircleShape* self = moon_CircleShape_create(radius, point_count, fill_color);
	moon_CircleShape_set_position(self, left, top);
	return self;
}

void
moon_CircleShape_destroy(moon_CircleShape* self) {
	delete self;
}

void
moon_CircleShape_draw(
	const moon_CircleShape* self,
	moon_RenderWindow* wnd,
	const moon_RenderStates* states
) {
	wnd->draw(
		*(static_cast<const sf::CircleShape*>(self)),
		*states
	);
}

moon_Vector2f
moon_CircleShape_get_size(const moon_CircleShape* self) {
	sf::FloatRect bounds = self->getGlobalBounds();
	return {bounds.width, bounds.height};
}

void
moon_CircleShape_set_radius(
	moon_CircleShape* self,
	float radius
) {
	self->setRadius(radius);
}

float
moon_CircleShape_get_radius(const moon_CircleShape* self) {
	return self->getRadius();
}

void
moon_CircleShape_set_point_count(
	moon_CircleShape* self,
	unsigned long count
) {
	self->setPointCount(static_cast<std::size_t>(count));
}


// Shape begin

void
moon_CircleShape_set_texture(
	moon_CircleShape* self,
	const moon_Texture* texture,
	int reset_rect
) {
	self->setTexture(texture, reset_rect);
}

void
moon_CircleShape_set_texture_rect(
	moon_CircleShape* self,
	const moon_IntRect* rect
) {
	moon_Shape_set_texture_rect<moon_CircleShape>(self, rect);
}

void
moon_CircleShape_set_fill_color(
	moon_CircleShape* self,
	const moon_Color* color
) {
	moon_Shape_set_fill_color<moon_CircleShape>(self, color);
}

void
moon_CircleShape_set_outline_color(
	moon_CircleShape* self,
	const moon_Color* color
) {
	moon_Shape_set_outline_color<moon_CircleShape>(self, color);
}

void
moon_CircleShape_set_outline_thickness(
	moon_CircleShape* self,
	float thickness
) {
	self->setOutlineThickness(thickness);
}

const moon_Texture*
moon_CircleShape_get_texture(const moon_CircleShape* self) {
	return moon_Shape_get_texture<moon_CircleShape>(self);
}

moon_IntRect
moon_CircleShape_get_texture_rect(const moon_CircleShape* self) {
	return moon_Shape_get_texture_rect<moon_CircleShape>(self);
}

moon_Color
moon_CircleShape_get_fill_color(const moon_CircleShape* self) {
	return moon_Shape_get_fill_color<moon_CircleShape>(self);
}

moon_Color
moon_CircleShape_get_outline_color(const moon_CircleShape* self) {
	return moon_Shape_get_outline_color<moon_CircleShape>(self);
}

float
moon_CircleShape_get_outline_thickness(const moon_CircleShape* self) {
	return self->getOutlineThickness();
}

unsigned long
moon_CircleShape_get_point_count(const moon_CircleShape* self) {
	return moon_Shape_get_point_count<moon_CircleShape>(self);
}

moon_Vector2f
moon_CircleShape_get_point(
	const moon_CircleShape* self,
	unsigned long index
) {
	return moon_Shape_get_point<moon_CircleShape>(self, index);
}

moon_FloatRect
moon_CircleShape_get_local_bounds(const moon_CircleShape* self) {
	return moon_Shape_get_local_bounds<moon_CircleShape>(self);
}

moon_FloatRect
moon_CircleShape_get_global_bounds(const moon_CircleShape* self) {
	return moon_Shape_get_global_bounds<moon_CircleShape>(self);
}

// Shape end


// Transformable begin

void
moon_CircleShape_set_position(
	moon_CircleShape* self,
	float left, float top
) {
	self->setPosition(left, top);
}

void
moon_CircleShape_set_rotation(
	moon_CircleShape* self,
	moon_Angle angle
) {
	self->setRotation(angle);
}

void
moon_CircleShape_set_scale(
	moon_CircleShape* self,
	float scale_x, float scale_y
) {
	self->setScale(scale_x, scale_y);
}

void
moon_CircleShape_set_origin(
	moon_CircleShape* self,
	float x, float y
) {
	self->setOrigin(x, y);
}

moon_Vector2f
moon_CircleShape_get_position(const moon_CircleShape* self) {
	return moon_Transformable_get_position<moon_CircleShape>(self);
}

moon_Angle
moon_CircleShape_get_rotation(const moon_CircleShape* self) {
	return self->getRotation();
}

moon_Vector2f
moon_CircleShape_get_scale(const moon_CircleShape* self) {
	return moon_Transformable_get_scale<moon_CircleShape>(self);
}

moon_Vector2f
moon_CircleShape_get_origin(const moon_CircleShape* self) {
	return moon_Transformable_get_origin<moon_CircleShape>(self);
}

void
moon_CircleShape_move(
	moon_CircleShape* self,
	float dx, float dy
) {
	self->move(dx, dy);
}

void
moon_CircleShape_rotate(
	moon_CircleShape* self,
	moon_Angle angle
) {
	self->rotate(angle);
}

void
moon_CircleShape_scale(
	moon_CircleShape* self,
	float scale_x, float scale_y
) {
	self->scale(scale_x, scale_y);
}

moon_Transform
moon_CircleShape_get_transform(const moon_CircleShape* self) {
	return moon_Transformable_get_transform<moon_CircleShape>(self);
}

moon_Transform
moon_CircleShape_get_inverse_transform(const moon_CircleShape* self) {
	return moon_Transformable_get_inverse_transform<moon_CircleShape>(self);
}

int
moon_CircleShape_is_transform_updated(const moon_CircleShape* self) {
	return self->m_transformNeedUpdate;
}

int
moon_CircleShape_is_inversed_transform_updated(const moon_CircleShape* self) {
	return self->m_inverseTransformNeedUpdate;
}

// Transformable end


moon_CircleShape::moon_CircleShape(
	float radius,
	unsigned long point_count
) : sf::CircleShape(radius, static_cast<std::size_t>(point_count)) {
	//
}

moon_FloatRect
moon_CircleShape::get_global_bounds() const {
	return moon_CircleShape_get_global_bounds(this);
}

void
moon_CircleShape::draw(
	sf::RenderTarget& target,
	sf::RenderStates states
) const {
	sf::CircleShape::draw(target, states);
}


#undef private

#undef protected
