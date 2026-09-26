// Who even need access modifiers?

#define private public

#define protected public


#include "../../headers/graphics/moon_convex_shape.h"

#include "../../headers/graphics/ShapeUtils.hpp"

#include "../../headers/graphics/TransformableUtils.hpp"

#include "../../headers/graphics/TextureStruct.hpp"

#include "../../headers/graphics/RenderStatesStruct.hpp"

#include "../../headers/graphics/RenderWindowStruct.hpp"

#include "../../headers/graphics/ConvexShapeStruct.hpp"


moon_ConvexShape*
moon_ConvexShape_default(unsigned long point_count) {
	return new moon_ConvexShape(point_count);
}

moon_ConvexShape*
moon_ConvexShape_create(
	unsigned long point_count,
	const moon_Color* fill_color
) {
	moon_ConvexShape* self = moon_ConvexShape_default(point_count);
	moon_ConvexShape_set_fill_color(self, fill_color);
	return self;
}

moon_ConvexShape*
moon_ConvexShape_create_ex(
	unsigned long point_count,
	const moon_Color* fill_color,
	float left, float top
) {
	moon_ConvexShape* self = moon_ConvexShape_create(point_count, fill_color);
	moon_ConvexShape_set_position(self, left, top);
	return self;
}

void
moon_ConvexShape_destroy(moon_ConvexShape* self) {
	delete self;
}

void
moon_ConvexShape_draw(
	const moon_ConvexShape* self,
	moon_RenderWindow* wnd,
	const moon_RenderStates* states
) {
	wnd->draw(
		*(static_cast<const sf::ConvexShape*>(self)),
		*states
	);
}

moon_Vector2f
moon_ConvexShape_get_size(const moon_ConvexShape* self) {
	sf::FloatRect bounds = self->getGlobalBounds();
	return {bounds.width, bounds.height};
}

moon_FloatRect
moon_ConvexShape_get_world_bounds(const moon_ConvexShape* self) {
	sf::FloatRect bounds = self->getGlobalBounds();
	return {
		self->m_position.x,
		self->m_position.y,
		bounds.width,
		bounds.height
	};
}

void
moon_ConvexShape_set_point_count(
	moon_ConvexShape* self,
	unsigned long count
) {
	self->setPointCount(static_cast<std::size_t>(count));
}

void
moon_ConvexShape_set_point(
	moon_ConvexShape* self,
	unsigned long index,
	float x, float y
) {
	self->setPoint(static_cast<std::size_t>(index), sf::Vector2f(x, y));
}


// Shape begin

void
moon_ConvexShape_set_texture(
	moon_ConvexShape* self,
	const moon_Texture* texture,
	int reset_rect
) {
	self->setTexture(texture, reset_rect);
}

void
moon_ConvexShape_set_texture_rect(
	moon_ConvexShape* self,
	const moon_IntRect* rect
) {
	moon_Shape_set_texture_rect<moon_ConvexShape>(self, rect);
}

void
moon_ConvexShape_set_fill_color(
	moon_ConvexShape* self,
	const moon_Color* color
) {
	moon_Shape_set_fill_color<moon_ConvexShape>(self, color);
}

void
moon_ConvexShape_set_outline_color(
	moon_ConvexShape* self,
	const moon_Color* color
) {
	moon_Shape_set_outline_color<moon_ConvexShape>(self, color);
}

void
moon_ConvexShape_set_outline_thickness(
	moon_ConvexShape* self,
	float thickness
) {
	self->setOutlineThickness(thickness);
}

const moon_Texture*
moon_ConvexShape_get_texture(const moon_ConvexShape* self) {
	return moon_Shape_get_texture<moon_ConvexShape>(self);
}

moon_IntRect
moon_ConvexShape_get_texture_rect(const moon_ConvexShape* self) {
	return moon_Shape_get_texture_rect<moon_ConvexShape>(self);
}

moon_Color
moon_ConvexShape_get_fill_color(const moon_ConvexShape* self) {
	return moon_Shape_get_fill_color<moon_ConvexShape>(self);
}

moon_Color
moon_ConvexShape_get_outline_color(const moon_ConvexShape* self) {
	return moon_Shape_get_outline_color<moon_ConvexShape>(self);
}

float
moon_ConvexShape_get_outline_thickness(const moon_ConvexShape* self) {
	return self->getOutlineThickness();
}

unsigned long
moon_ConvexShape_get_point_count(const moon_ConvexShape* self) {
	return moon_Shape_get_point_count<moon_ConvexShape>(self);
}

moon_Vector2f
moon_ConvexShape_get_point(
	const moon_ConvexShape* self,
	unsigned long index
) {
	return moon_Shape_get_point<moon_ConvexShape>(self, index);
}

moon_FloatRect
moon_ConvexShape_get_local_bounds(const moon_ConvexShape* self) {
	return moon_Shape_get_local_bounds<moon_ConvexShape>(self);
}

moon_FloatRect
moon_ConvexShape_get_global_bounds(const moon_ConvexShape* self) {
	return moon_Shape_get_global_bounds<moon_ConvexShape>(self);
}

// Shape end


// Transformable begin.

void
moon_ConvexShape_set_position(
	moon_ConvexShape* self,
	float left, float top
) {
	self->setPosition(left, top);
}

void
moon_ConvexShape_set_rotation(
	moon_ConvexShape* self,
	moon_Angle angle
) {
	self->setRotation(angle);
}

void
moon_ConvexShape_set_scale(
	moon_ConvexShape* self,
	float scale_x, float scale_y
) {
	self->setScale(scale_x, scale_y);
}

void
moon_ConvexShape_set_origin(
	moon_ConvexShape* self,
	float x, float y
) {
	self->setOrigin(x, y);
}

moon_Vector2f
moon_ConvexShape_get_position(const moon_ConvexShape* self) {
	return moon_Transformable_get_position<moon_ConvexShape>(self);
}

moon_Angle
moon_ConvexShape_get_rotation(const moon_ConvexShape* self) {
	return self->getRotation();
}

moon_Vector2f
moon_ConvexShape_get_scale(const moon_ConvexShape* self) {
	return moon_Transformable_get_scale<moon_ConvexShape>(self);
}

moon_Vector2f
moon_ConvexShape_get_origin(const moon_ConvexShape* self) {
	return moon_Transformable_get_origin<moon_ConvexShape>(self);
}

void
moon_ConvexShape_move(
	moon_ConvexShape* self,
	float dx, float dy
) {
	self->move(dx, dy);
}

void
moon_ConvexShape_rotate(
	moon_ConvexShape* self,
	moon_Angle angle
) {
	self->rotate(angle);
}

void
moon_ConvexShape_scale(
	moon_ConvexShape* self,
	float scale_x, float scale_y
) {
	self->scale(scale_x, scale_y);
}

moon_Transform
moon_ConvexShape_get_transform(const moon_ConvexShape* self) {
	return moon_Transformable_get_transform<moon_ConvexShape>(self);
}

moon_Transform
moon_ConvexShape_get_inverse_transform(const moon_ConvexShape* self) {
	return moon_Transformable_get_inverse_transform<moon_ConvexShape>(self);
}

int
moon_ConvexShape_is_transform_updated(const moon_ConvexShape* self) {
	return self->m_transformNeedUpdate;
}

int
moon_ConvexShape_is_inversed_transform_updated(const moon_ConvexShape* self) {
	return self->m_inverseTransformNeedUpdate;
}

// Transformable end


moon_ConvexShape::moon_ConvexShape(
	unsigned long point_count
) : sf::ConvexShape(static_cast<std::size_t>(point_count)) {
	//
}

moon_FloatRect
moon_ConvexShape::get_global_bounds() const {
	return moon_ConvexShape_get_global_bounds(this);
}

void
moon_ConvexShape::draw(
	sf::RenderTarget& target,
	sf::RenderStates states
) const {
	sf::ConvexShape::draw(target, states);
}


#undef private

#undef protected
