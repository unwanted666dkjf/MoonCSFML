#include <cmath>



// Access modifiers? Never heard of.

#define private public

#define protected public


#include "../../headers/graphics/moon_sprite.h"

#include "../../headers/graphics/Converters.hpp"

#include "../../headers/graphics/SpriteStruct.hpp"

#include "../../headers/graphics/TextureStruct.hpp"

#include "../../headers/graphics/RenderStatesStruct.hpp"

#include "../../headers/graphics/RenderWindowStruct.hpp"

#include "../../headers/graphics/TransformableUtils.hpp"


moon_Sprite*
moon_Sprite_create(const moon_Texture* texture) {
	return new moon_Sprite(texture);
}

moon_Sprite*
moon_Sprite_create_ex(
	const moon_Texture* texture,
	const moon_IntRect* area
) {
	return new moon_Sprite(texture, area);
}

void
moon_Sprite_destroy(moon_Sprite* self) {
	delete self;
}

void
moon_Sprite_draw(
	const moon_Sprite* self,
	moon_RenderWindow* wnd,
	const moon_RenderStates* states
) {
	wnd->draw(
		*(static_cast<const sf::Sprite*>(self)),
		*states
	);
}

moon_Vector2f
moon_Sprite_get_size(const moon_Sprite* self) {
	sf::FloatRect bounds = self->getGlobalBounds();
	return {bounds.width, bounds.height};
}

moon_FloatRect
moon_Sprite_get_world_bounds(const moon_Sprite* self) {
	sf::FloatRect bounds = self->getGlobalBounds();
	return {
		self->m_position.x,
		self->m_position.y,
		bounds.width,
		bounds.height
	};
}

void
moon_Sprite_set_texture(
	moon_Sprite* self,
	const moon_Texture* texture,
	int reset_rect
) {
	self->setTexture(*texture, reset_rect);
}

void
moon_Sprite_set_texture_rect(
	moon_Sprite* self,
	const moon_IntRect* rect
) {
	self->setTextureRect(int_rect_moon_to_sf(*rect));
}

void
moon_Sprite_set_color(
	moon_Sprite* self,
	const moon_Color* color
) {
	self->setColor(color_moon_to_sf(*color));
}

const moon_Texture*
moon_Sprite_get_texture(const moon_Sprite* self) {
	return static_cast<const moon_Texture*>(self->getTexture());
}

moon_IntRect
moon_Sprite_get_texture_rect(const moon_Sprite* self) {
	return int_rect_sf_to_moon(self->getTextureRect());
}

moon_Color
moon_Sprite_get_color(const moon_Sprite* self) {
	return color_sf_to_moon(self->getColor());
}

moon_FloatRect
moon_Sprite_get_local_bounds(const moon_Sprite* self) {
	float width = static_cast<float>(std::abs(self->m_textureRect.width));
	float height = static_cast<float>(std::abs(self->m_textureRect.height));
	return {0.f, 0.f, width, height};
}

moon_FloatRect
moon_Sprite_get_global_bounds(const moon_Sprite* self) {
	return float_rect_sf_to_moon(self->getGlobalBounds());
}


// Transformable begin

void
moon_Sprite_set_position(
	moon_Sprite* self,
	float left, float top
) {
	self->setPosition(left, top);
}

void
moon_Sprite_set_rotation(
	moon_Sprite* self,
	moon_Angle angle
) {
	self->setRotation(angle);
}

void
moon_Sprite_set_scale(
	moon_Sprite* self,
	float scale_x, float scale_y
) {
	self->setScale(scale_x, scale_y);
}

void
moon_Sprite_set_origin(
	moon_Sprite* self,
	float x, float y
) {
	self->setOrigin(x, y);
}

moon_Vector2f
moon_Sprite_get_position(const moon_Sprite* self) {
	return moon_Transformable_get_position<moon_Sprite>(self);
}

moon_Angle
moon_Sprite_get_rotation(const moon_Sprite* self) {
	return self->getRotation();
}

moon_Vector2f
moon_Sprite_get_scale(const moon_Sprite* self) {
	return moon_Transformable_get_scale<moon_Sprite>(self);
}

moon_Vector2f
moon_Sprite_get_origin(const moon_Sprite* self) {
	return moon_Transformable_get_origin<moon_Sprite>(self);
}

void
moon_Sprite_move(
	moon_Sprite* self,
	float dx, float dy
) {
	self->move(dx, dy);
}

void
moon_Sprite_rotate(
	moon_Sprite* self,
	moon_Angle angle
) {
	self->rotate(angle);
}

void
moon_Sprite_scale(
	moon_Sprite* self,
	float scale_x, float scale_y
) {
	self->scale(scale_x, scale_y);
}

moon_Transform
moon_Sprite_get_transform(const moon_Sprite* self) {
	return moon_Transformable_get_transform<moon_Sprite>(self);
}

moon_Transform
moon_Sprite_get_inverse_transform(const moon_Sprite* self) {
	return moon_Transformable_get_inverse_transform<moon_Sprite>(self);
}

int
moon_Sprite_is_transform_updated(const moon_Sprite* self) {
	return self->m_transformNeedUpdate;
}

int
moon_Sprite_is_inversed_transform_updated(const moon_Sprite* self) {
	return self->m_inverseTransformNeedUpdate;
}

// Transformable end


moon_Sprite::moon_Sprite(const moon_Texture* texture) : sf::Sprite(
	*texture
) {
	//
}

moon_Sprite::moon_Sprite(
	const moon_Texture* texture,
	const moon_IntRect* area
) : sf::Sprite(
	*texture,
	int_rect_moon_to_sf(*area)
) {
	//
}

moon_FloatRect
moon_Sprite::get_global_bounds() const {
	return moon_Sprite_get_global_bounds(this);
}

void
moon_Sprite::draw(
	sf::RenderTarget& target,
	sf::RenderStates states
) const {
	sf::Sprite::draw(target, states);
}


#undef private

#undef protected
