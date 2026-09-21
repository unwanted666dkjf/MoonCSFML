// Access modifiers won't save anyone.

#define private public

#define protected public


#include "../../headers/graphics/moon_rectangle_shape.h"

#include "../../headers/graphics/ShapeUtils.hpp"

#include "../../headers/graphics/TransformableUtils.hpp"

#include "../../headers/graphics/TextureStruct.hpp"

#include "../../headers/graphics/RenderStatesStruct.hpp"

#include "../../headers/graphics/RenderWindowStruct.hpp"

#include "../../headers/graphics/RectangleShapeStruct.hpp"


moon_RectangleShape*
moon_RectangleShape_default(float width, float height) {
	return new moon_RectangleShape(width, height);
}

moon_RectangleShape*
moon_RectangleShape_create(
	float width, float height,
	const moon_Color* fill_color
) {
	moon_RectangleShape* self = moon_RectangleShape_default(width, height);
	moon_RectangleShape_set_fill_color(self, fill_color);
	return self;
}

moon_RectangleShape*
moon_RectangleShape_create_ex(
	float width, float height,
	const moon_Color* fill_color,
	float left, float top
) {
	moon_RectangleShape* self = moon_RectangleShape_create(width, height, fill_color);
	moon_RectangleShape_set_position(self, left, top);
	return self;
}

void
moon_RectangleShape_destroy(moon_RectangleShape* self) {
	delete self;
}

void
moon_RectangleShape_draw(
	const moon_RectangleShape* self,
	moon_RenderWindow* wnd,
	const moon_RenderStates* states
) {
	wnd->draw(
		*(static_cast<const sf::RectangleShape*>(self)),
		*states
	);
}

void
moon_RectangleShape_set_size(
	moon_RectangleShape* self,
	float width, float height
) {
	self->setSize(sf::Vector2f(width, height));
}

moon_Vector2f
moon_RectangleShape_get_size(const moon_RectangleShape* self) {
	sf::FloatRect bounds = self->getGlobalBounds();
	return {bounds.width, bounds.height};
}


// Shape begin

void
moon_RectangleShape_set_texture(
	moon_RectangleShape* self,
	const moon_Texture* texture,
	int reset_rect
) {
	self->setTexture(texture, reset_rect);
}

void
moon_RectangleShape_set_texture_rect(
	moon_RectangleShape* self,
	const moon_IntRect* rect
) {
	moon_Shape_set_texture_rect<moon_RectangleShape>(self, rect);
}

void
moon_RectangleShape_set_fill_color(
	moon_RectangleShape* self,
	const moon_Color* color
) {
	moon_Shape_set_fill_color<moon_RectangleShape>(self, color);
}

void
moon_RectangleShape_set_outline_color(
	moon_RectangleShape* self,
	const moon_Color* color
) {
	moon_Shape_set_outline_color<moon_RectangleShape>(self, color);
}

void
moon_RectangleShape_set_outline_thickness(
	moon_RectangleShape* self,
	float thickness
) {
	self->setOutlineThickness(thickness);
}

const moon_Texture*
moon_RectangleShape_get_texture(const moon_RectangleShape* self) {
	return moon_Shape_get_texture<moon_RectangleShape>(self);
}

moon_IntRect
moon_RectangleShape_get_texture_rect(const moon_RectangleShape* self) {
	return moon_Shape_get_texture_rect<moon_RectangleShape>(self);
}

moon_Color
moon_RectangleShape_get_fill_color(const moon_RectangleShape* self) {
	return moon_Shape_get_fill_color<moon_RectangleShape>(self);
}

moon_Color
moon_RectangleShape_get_outline_color(const moon_RectangleShape* self) {
	return moon_Shape_get_outline_color<moon_RectangleShape>(self);
}

float
moon_RectangleShape_get_outline_thickness(const moon_RectangleShape* self) {
	return self->getOutlineThickness();
}

unsigned long
moon_RectangleShape_get_point_count(const moon_RectangleShape* self) {
	return moon_Shape_get_point_count<moon_RectangleShape>(self);
}

moon_Vector2f
moon_RectangleShape_get_point(
	const moon_RectangleShape* self,
	unsigned long index
) {
	return moon_Shape_get_point<moon_RectangleShape>(self, index);
}

moon_FloatRect
moon_RectangleShape_get_local_bounds(const moon_RectangleShape* self) {
	return moon_Shape_get_local_bounds<moon_RectangleShape>(self);
}

moon_FloatRect
moon_RectangleShape_get_global_bounds(const moon_RectangleShape* self) {
	return moon_Shape_get_global_bounds<moon_RectangleShape>(self);
}

// Shape end


// Transformable begin

void
moon_RectangleShape_set_position(
	moon_RectangleShape* self,
	float left, float top
) {
	self->setPosition(left, top);
}

void
moon_RectangleShape_set_rotation(
	moon_RectangleShape* self,
	moon_Angle angle
) {
	self->setRotation(angle);
}

void
moon_RectangleShape_set_scale(
	moon_RectangleShape* self,
	float scale_x, float scale_y
) {
	self->setScale(scale_x, scale_y);
}

void
moon_RectangleShape_set_origin(
	moon_RectangleShape* self,
	float x, float y
) {
	self->setOrigin(x, y);
}

moon_Vector2f
moon_RectangleShape_get_position(const moon_RectangleShape* self) {
	return moon_Transformable_get_position<moon_RectangleShape>(self);
}

moon_Angle
moon_RectangleShape_get_rotation(const moon_RectangleShape* self) {
	return self->getRotation();
}

moon_Vector2f
moon_RectangleShape_get_scale(const moon_RectangleShape* self) {
	return moon_Transformable_get_scale<moon_RectangleShape>(self);
}

moon_Vector2f
moon_RectangleShape_get_origin(const moon_RectangleShape* self) {
	return moon_Transformable_get_origin<moon_RectangleShape>(self);
}

void
moon_RectangleShape_move(
	moon_RectangleShape* self,
	float dx, float dy
) {
	self->move(dx, dy);
}

void
moon_RectangleShape_rotate(
	moon_RectangleShape* self,
	moon_Angle angle
) {
	self->rotate(angle);
}

void
moon_RectangleShape_scale(
	moon_RectangleShape* self,
	float scale_x, float scale_y
) {
	self->scale(scale_x, scale_y);
}

moon_Transform
moon_RectangleShape_get_transform(const moon_RectangleShape* self) {
	return moon_Transformable_get_transform<moon_RectangleShape>(self);
}

moon_Transform
moon_RectangleShape_get_inverse_transform(const moon_RectangleShape* self) {
	return moon_Transformable_get_inverse_transform<moon_RectangleShape>(self);
}

int
moon_RectangleShape_is_transform_updated(const moon_RectangleShape* self) {
	return self->m_transformNeedUpdate;
}

int
moon_RectangleShape_is_inversed_transform_updated(const moon_RectangleShape* self) {
	return self->m_inverseTransformNeedUpdate;
}

// Transformable end


moon_RectangleShape::moon_RectangleShape(
	float width, float height
) : sf::RectangleShape(sf::Vector2f(width, height)) {
	//
}

void
moon_RectangleShape::draw(
	sf::RenderTarget& target,
	sf::RenderStates states
) const {
	sf::RectangleShape::draw(target, states);
}

moon_FloatRect
moon_RectangleShape::get_global_bounds() const {
	return moon_RectangleShape_get_global_bounds(this);
}


#undef private

#undef protected
