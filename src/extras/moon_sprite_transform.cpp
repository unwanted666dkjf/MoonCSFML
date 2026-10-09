#include <SFML/Graphics/Texture.hpp>



#include "../../headers/extras/moon_useful_funcs.h"

#include "../../headers/extras/moon_sprite_transform.h"


#include "../../headers/graphics/SpriteStruct.hpp"


void
moon_SpriteTransform_flip(
	moon_Sprite* sprite,
	int flip_x, int flip_y
) {
	if (!(flip_x || flip_y)) {
		return;
	}
	sf::Vector2f current_scale = sprite->getScale();
	sf::FloatRect old_rect = sprite->getGlobalBounds();
	float* kx = &current_scale.x;
	float* ky = &current_scale.y;
	if (flip_x) {
		(*kx) *= -1;
	}
	if (flip_y) {
		(*ky) *= -1;
	}
	sprite->setScale((*kx), (*ky));
	sf::FloatRect new_rect = sprite->getGlobalBounds();
	sprite->move(
		old_rect.left - new_rect.left,
		old_rect.top - new_rect.top
	);
}

moon_Vector2f
moon_SpriteTransform_scale(
	moon_Sprite* sprite,
	float width, float height,
	int keep_w,  int keep_h
) {
	const sf::Texture* texture 	= sprite->getTexture();
	sf::Vector2u texture_size 	= texture->getSize();
	moon_Vector2f size = moon_new_size(
		texture_size.x, 	texture_size.y,
		width, 				height,
		keep_w,		 		keep_h
	);
	sprite->setScale(
		size.x / static_cast<float>(texture_size.x),
		size.y / static_cast<float>(texture_size.y)
	);
	return size;
}

moon_Angle
moon_SpriteTransform_rotate(
	moon_Sprite* sprite,
	moon_Angle angle
) {
	float current = sprite->getRotation();
	moon_Angle res = current + angle;
	moon_SpriteTransform_set_rotation(sprite, res);
	return res;
}

void
moon_SpriteTransform_set_rotation(
	moon_Sprite* sprite,
	moon_Angle angle
) {
	sf::FloatRect old_rect = sprite->getGlobalBounds();
	sf::Vector2f old_center(
		old_rect.left + old_rect.width * .5f,
		old_rect.top + old_rect.height * .5f
	);
	sprite->setRotation(angle);
	sf::FloatRect new_rect = sprite->getGlobalBounds();
	sf::Vector2f new_center(
		new_rect.left + new_rect.width * .5f,
		new_rect.top + new_rect.height * .5f
	);
	float dx = old_center.x - new_center.x;
	float dy = old_center.y - new_center.y;
	sprite->move(dx, dy);
}

void
moon_SpriteTransform_set_movepos(
	moon_Sprite* sprite,
	float left, float top
) {
	sf::FloatRect bounds = sprite->getGlobalBounds();
	sprite->move(
		left - bounds.left,
		top  - bounds.top
	);
}

void
moon_SpriteTransform_copy_transform(
	moon_Sprite* target,
	const moon_Sprite* source
) {
	target->setRotation(	source->getRotation());
	target->setScale(		source->getScale());
	target->setOrigin(		source->getOrigin());
	target->setPosition(	source->getPosition());
}

void
moon_SpriteTransform_apply_orient(
	moon_Sprite* target,
	const moon_Sprite* source
) {
	float old_rotation = source->getRotation();
	if (old_rotation != target->getRotation()) {
		target->setRotation(old_rotation);
	}
	const sf::Vector2f& old_pos = source->getPosition();
	const sf::Vector2f& nxt_pos = target->getPosition();
	if (nxt_pos != old_pos) {
		target->setPosition(old_pos.x, old_pos.y);
		float old_height = source->getGlobalBounds().height;
		float nxt_height = target->getGlobalBounds().height;
		target->move(0.f, old_height - nxt_height);
	}
}
