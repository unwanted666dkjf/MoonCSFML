#include "../../headers/extras/moon_useful_funcs.h"

#include "../../headers/extras/moon_slide_animation.h"

#include "../../headers/extras/moon_sprite_transform.h"

#include "../../headers/extras/SlideAnimationStruct.hpp"


#include "../../headers/graphics/VectorUtils.hpp"

#include "../../headers/graphics/TextureStruct.hpp"

#include "../../headers/graphics/RenderStatesStruct.hpp"

#include "../../headers/graphics/RenderWindowStruct.hpp"


static void
moon_SlideAnimation_resize_sprite(
	const moon_SlideAnimation* self,
	moon_Sprite* sprite
);

static void
moon_SlideAnimation_apply_nxt(
	const moon_Sprite* current,
	moon_Sprite* next
);

static moon_Sprite*
moon_SlideAnimation_current(moon_SlideAnimation* self);

static const moon_Sprite*
moon_SlideAnimation_get_current_sprite(const moon_SlideAnimation* self);


moon_SlideAnimation*
moon_SlideAnimation_create(
	unsigned long initial_size,
	float width, float height,
	int fixed_w, int fixed_h,
	float anim_speed
) {
	return new moon_SlideAnimation(
		initial_size,
		width, height,
		fixed_w, fixed_h,
		anim_speed
	);
}

void
moon_SlideAnimation_destroy(moon_SlideAnimation* self) {
	delete self;
}

void
moon_SlideAnimation_draw(
	const moon_SlideAnimation* self,
	moon_RenderWindow* wnd,
	const moon_RenderStates* states
) {
	wnd->draw(*self, *states);
}

int
moon_SlideAnimation_is_empty(const moon_SlideAnimation* self) {
	return self->sprites.empty();
}

int
moon_SlideAnimation_is_first(const moon_SlideAnimation* self) {
	if (moon_SlideAnimation_is_empty(self)) {
		return 0;
	}
	return self->cur_ind == 0UL;
}

int
moon_SlideAnimation_is_last(const moon_SlideAnimation* self) {
	if (moon_SlideAnimation_is_empty(self)) {
		return 0;
	}
	return self->cur_ind == (self->sprites.size() - 1UL);
}

int
moon_SlideAnimation_is_running(const moon_SlideAnimation* self) {
	if (moon_SlideAnimation_is_empty(self)) {
		return 0;
	}
	return self->ind > 0.f;
}

unsigned long
moon_SlideAnimation_size(const moon_SlideAnimation* self) {
	return self->sprites.capacity();
}

unsigned long
moon_SlideAnimation_length(const moon_SlideAnimation* self) {
	return self->sprites.size();
}

int
moon_SlideAnimation_reserve(
	moon_SlideAnimation* self,
	unsigned long new_cap
) {
	if (new_cap <= self->sprites.capacity()) {
		return 0;
	}
	self->sprites.reserve(new_cap);
	return 1;
}

int
moon_SlideAnimation_update(moon_SlideAnimation* self) {
	self->ind += self->anim_speed;
	unsigned long ind = static_cast<unsigned long>(self->ind);
	if (ind >= self->sprites.size()) {
		self->ind = 0.f;
		ind = static_cast<unsigned long>(self->ind);
	}
	if (ind == self->cur_ind) {
		return 0;
	}
	const moon_Sprite* current = moon_SlideAnimation_get_current_sprite(self);
	if (!current) {
		return 0;
	}
	self->cur_ind = ind;
	moon_Sprite* next = moon_SlideAnimation_current(self);
	if (!next) {
		return 0;
	}

	moon_SlideAnimation_apply_nxt(current, next);

	return 1;
}

int
moon_SlideAnimation_rotate(
	moon_SlideAnimation* self,
	moon_Angle angle
) {
	moon_Sprite* current = moon_SlideAnimation_current(self);
	if (!current) {
		return 0;
	}
	moon_SpriteTransform_rotate(current, angle);
	return 1;
}

int
moon_SlideAnimation_set_rotation(
	moon_SlideAnimation* self,
	moon_Angle angle
) {
	moon_Sprite* current = moon_SlideAnimation_current(self);
	if (!current) {
		return 0;
	}
	moon_SpriteTransform_set_rotation(current, angle);
	return 1;
}

int
moon_SlideAnimation_move(
	moon_SlideAnimation* self,
	float dx, float dy
) {
	moon_Sprite* current = moon_SlideAnimation_current(self);
	if (!current) {
		return 0;
	}
	current->move(dx, dy);
	return 1;
}

int
moon_SlideAnimation_set_position(
	moon_SlideAnimation* self,
	float left, float top
) {
	moon_Sprite* current = moon_SlideAnimation_current(self);
	if (!current) {
		return 0;
	}
	moon_FloatRect bounds = moon_Sprite_get_global_bounds(current);
	current->move(
		left - bounds.left,
		top  - bounds.top
	);
	return 1;
}

int
moon_SlideAnimation_resize(
	moon_SlideAnimation* self,
	float width, float height
) {
	moon_Sprite* current = moon_SlideAnimation_current(self);
	if (!current) {
		return 0;
	}
	self->width		= width;
	self->height 	= height;
	sf::Vector2f pos = current->getPosition();
	for (unsigned long i = 0UL; i < self->sprites.size(); i++) {
		moon_SlideAnimation_resize_sprite(self, &self->sprites[i]);
	}
	current->setPosition(pos);
	return 1;
}

void
moon_SlideAnimation_reverse(moon_SlideAnimation* self) {
	const moon_Sprite* current = moon_SlideAnimation_get_current_sprite(self);
	if (!current) {
		return;
	}
	moon_vector_reverse<moon_Sprite>(self->sprites);
	moon_Sprite* next = moon_SlideAnimation_current(self);
	moon_SlideAnimation_apply_nxt(current, next);
}

void
moon_SlideAnimation_clear(moon_SlideAnimation* self) {
	self->sprites.clear();
}

void
moon_SlideAnimation_flip(
	moon_SlideAnimation* self,
	int flip_x, int flip_y
) {
	if (!(flip_x || flip_y)) {
		return;
	}
	for (unsigned long i = 0UL; i < self->sprites.size(); i++) {
		moon_SpriteTransform_flip(&self->sprites[i], flip_x, flip_y);
	}
}

void
moon_SlideAnimation_push_back(
	moon_SlideAnimation* self,
	const moon_Texture* texture
) {
	moon_Sprite sprite(texture);
	moon_SlideAnimation_resize_sprite(self, &sprite);
	self->sprites.push_back(sprite);
}

moon_Angle
moon_SlideAnimation_get_rotation(const moon_SlideAnimation* self) {
	const moon_Sprite* current = moon_SlideAnimation_get_current_sprite(self);
	if (!current) {
		return 0.f;
	}
	return current->getRotation();
}

moon_Vector2f
moon_SlideAnimation_get_size(const moon_SlideAnimation* self) {
	const moon_Sprite* current = moon_SlideAnimation_get_current_sprite(self);
	if (!current) {
		return {0.f, 0.f};
	}
	return moon_Sprite_get_size(current);
}

moon_Vector2f
moon_SlideAnimation_get_position(const moon_SlideAnimation* self) {
	const moon_Sprite* current = moon_SlideAnimation_get_current_sprite(self);
	if (!current) {
		return {0.f, 0.f};
	}
	return moon_Sprite_get_position(current);
}

moon_FloatRect
moon_SlideAnimation_get_local_bounds(const moon_SlideAnimation* self) {
	const moon_Sprite* current = moon_SlideAnimation_get_current_sprite(self);
	if (!current) {
		return moon_FloatRect_create_empty();
	}
	return moon_Sprite_get_local_bounds(current);
}

moon_FloatRect
moon_SlideAnimation_get_global_bounds(const moon_SlideAnimation* self) {
	const moon_Sprite* current = moon_SlideAnimation_get_current_sprite(self);
	if (!current) {
		return moon_FloatRect_create_empty();
	}
	return moon_Sprite_get_global_bounds(current);
}

moon_FloatRect
moon_SlideAnimation_get_world_bounds(const moon_SlideAnimation* self) {
	const moon_Sprite* current = moon_SlideAnimation_get_current_sprite(self);
	if (!current) {
		return moon_FloatRect_create_empty();
	}
	return moon_Sprite_get_world_bounds(current);
}


void
moon_SlideAnimation_resize_sprite(
	const moon_SlideAnimation* self,
	moon_Sprite* sprite
) {
	const sf::Texture* texture = sprite->getTexture();
	sf::Vector2u texture_size = texture->getSize();
	moon_Vector2f size = moon_new_size(
		texture_size.x, 	texture_size.y,
		self->width, 		self->height,
		self->fixed_w, 		self->fixed_h
	);
	sprite->setScale(
		size.x / texture_size.x,
		size.y / texture_size.y
	);
}

void
moon_SlideAnimation_apply_nxt(
	const moon_Sprite* current,
	moon_Sprite* next
) {
	float old_rotation = current->getRotation();
	if (old_rotation != next->getRotation()) {
		next->setRotation(old_rotation);
	}
	const sf::Vector2f& old_pos = current->getPosition();
	const sf::Vector2f& nxt_pos = next->getPosition();
	if (nxt_pos != old_pos) {
		next->setPosition(old_pos.x, old_pos.y);
		float old_height = current->getGlobalBounds().height;
		float nxt_height = next->getGlobalBounds().height;
		next->move(0.f, old_height - nxt_height);
	}
}

moon_Sprite*
moon_SlideAnimation_current(moon_SlideAnimation* self) {
	if (self->sprites.empty()) {
		return nullptr;
	}
	return &self->sprites[self->cur_ind];
}

const moon_Sprite*
moon_SlideAnimation_get_current_sprite(const moon_SlideAnimation* self) {
	if (self->sprites.empty()) {
		return nullptr;
	}
	return &self->sprites[self->cur_ind];
}


moon_SlideAnimation::moon_SlideAnimation(
	unsigned long v_initial_size,
	float v_width, float v_heigth,
	int v_fixed_w, int v_fixed_h,
	float v_anim_speed
) {
	sprites.reserve(v_initial_size + 1UL);
	width 		= v_width;
	height 		= v_heigth;
	fixed_w 	= v_fixed_w;
	fixed_h 	= v_fixed_h;
	anim_speed	= v_anim_speed;
	ind 		= 0.f;
	cur_ind		= static_cast<unsigned long>(ind);
}

void
moon_SlideAnimation::draw(
	sf::RenderTarget& target,
	sf::RenderStates states
) const {
	const moon_Sprite* current = moon_SlideAnimation_get_current_sprite(this);
	if (!current) {
		return;
	}
	target.draw(
		*(static_cast<const sf::Sprite*>(current)),
		states
	);
}

moon_FloatRect
moon_SlideAnimation::get_global_bounds() const {
	return moon_SlideAnimation_get_global_bounds(this);
}
