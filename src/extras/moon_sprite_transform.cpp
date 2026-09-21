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

void
moon_SpriteTransform_rotate(
	moon_Sprite* sprite,
	moon_Angle angle
) {
	float current = sprite->getRotation();
	moon_SpriteTransform_set_rotation(sprite, current + angle);
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
moon_SpriteTransform_copy_transform(
	moon_Sprite* target,
	const moon_Sprite* source
) {
	target->setPosition(	source->getPosition());
	target->setRotation(	source->getRotation());
	target->setScale(		source->getScale());
	target->setOrigin(		source->getOrigin());
}
