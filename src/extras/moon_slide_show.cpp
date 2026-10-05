#include "../../headers/extras/moon_colors.h"

#include "../../headers/extras/moon_slide_show.h"

#include "../../headers/extras/moon_sprite_transform.h"

#include "../../headers/extras/SlideShowStruct.hpp"


#include "../../headers/graphics/VectorUtils.hpp"

#include "../../headers/graphics/TextureStruct.hpp"

#include "../../headers/graphics/RenderStatesStruct.hpp"

#include "../../headers/graphics/RenderWindowStruct.hpp"


static void
moon_SlideShow_resize_sprite(
	const moon_SlideShow* self,
	moon_Sprite* sprite
);

static moon_Sprite*
moon_SlideShow_current(moon_SlideShow* self);

static const moon_Sprite*
moon_SlideShow_get_current_sprite(const moon_SlideShow* self);


moon_SlideShow*
moon_SlideShow_create(
	unsigned long initial_size,
	float width, float height,
	int fixed_w, int fixed_h,
	float secs_per_frame
) {
	return new moon_SlideShow(
		initial_size,
		width, height,
		fixed_w, fixed_h,
		secs_per_frame
	);
}

void
moon_SlideShow_destroy(moon_SlideShow* self) {
	if (self->clock) {
		moon_Clock_destroy(self->clock);
	}
	delete self;
}

void
moon_SlideShow_draw(
	const moon_SlideShow* self,
	moon_RenderWindow* wnd,
	const moon_RenderStates* states
) {
	wnd->draw(*self, *states);
}

int
moon_SlideShow_is_valid(const moon_SlideShow* self) {
	if (!self) {
		return 0;
	}
	return self->secs_per_frame >= 0.f;
}

int
moon_SlideShow_is_empty(const moon_SlideShow* self) {
	return self->sprites.empty();
}

int
moon_SlideShow_is_first(const moon_SlideShow* self) {
	if (moon_SlideShow_is_empty(self)) {
		return 0;
	}
	return self->ind == 0UL;
}

int
moon_SlideShow_is_last(const moon_SlideShow* self) {
	if (moon_SlideShow_is_empty(self)) {
		return 0;
	}
	return self->ind == (self->sprites.size() - 1UL);
}

int
moon_SlideShow_is_running(const moon_SlideShow* self) {
	if (moon_SlideShow_is_empty(self)) {
		return 0;
	}
	return moon_Clock_is_running(self->clock);
}

unsigned long
moon_SlideShow_size(const moon_SlideShow* self) {
	return self->sprites.capacity();
}

unsigned long
moon_SlideShow_length(const moon_SlideShow* self) {
	return self->sprites.size();
}

int
moon_SlideShow_reserve(
	moon_SlideShow* self,
	unsigned long new_cap
) {
	if (new_cap <= self->sprites.capacity()) {
		return 0;
	}
	self->sprites.reserve(new_cap);
	return 1;
}

int
moon_SlideShow_update(moon_SlideShow* self) {
	if (!moon_Clock_is_running(self->clock)) {
		moon_Clock_start(self->clock);
	}
	float elapsed_secs = moon_Time_as_seconds(
		moon_Clock_wait(self->clock)
	) + self->cum_time;
	if (elapsed_secs < self->secs_per_frame) {
		return 0;
	}
	moon_Clock_reset(self->clock);
	self->cum_time = elapsed_secs - self->secs_per_frame;
	const moon_Sprite* current = moon_SlideShow_get_current_sprite(self);
	if (!current) {
		return 0;
	}
	self->ind += 1UL;
	if (self->ind >= self->sprites.size()) {
		self->ind = 0UL;
	}
	moon_Sprite* next = moon_SlideShow_current(self);
	if (!next) {
		return 0;
	}

	moon_SpriteTransform_apply_orient(next, current);

	return 1;
}

int
moon_SlideShow_rotate(
	moon_SlideShow* self,
	moon_Angle angle
) {
	moon_Sprite* current = moon_SlideShow_current(self);
	if (!current) {
		return 0;
	}
	moon_SpriteTransform_rotate(current, angle);
	return 1;
}

int
moon_SlideShow_set_rotation(
	moon_SlideShow* self,
	moon_Angle angle
) {
	moon_Sprite* current = moon_SlideShow_current(self);
	if (!current) {
		return 0;
	}
	moon_SpriteTransform_set_rotation(current, angle);
	return 1;
}

int
moon_SlideShow_set_color(
	moon_SlideShow* self,
	const moon_Color* color
) {
	if (self->sprites.empty()) {
		return 0;
	}
	for (unsigned long i = 0UL; i < self->sprites.size(); i++) {
		moon_Sprite_set_color(&self->sprites[i], color);
	}
	return 1;
}

int
moon_SlideShow_move(
	moon_SlideShow* self,
	float dx, float dy
) {
	moon_Sprite* current = moon_SlideShow_current(self);
	if (!current) {
		return 0;
	}
	current->move(dx, dy);
	return 1;
}

int
moon_SlideShow_set_position(
	moon_SlideShow* self,
	float left, float top
) {
	moon_Sprite* current = moon_SlideShow_current(self);
	if (!current) {
		return 0;
	}
	moon_SpriteTransform_set_movepos(current, left, top);
	return 1;
}

int
moon_SlideShow_resize(
	moon_SlideShow* self,
	float width, float height
) {
	moon_Sprite* current = moon_SlideShow_current(self);
	if (!current) {
		return 0;
	}
	self->width		= width;
	self->height 	= height;
	sf::Vector2f pos = current->getPosition();
	for (unsigned long i = 0UL; i < self->sprites.size(); i++) {
		moon_SlideShow_resize_sprite(self, &self->sprites[i]);
	}
	current->setPosition(pos);
	return 1;
}

void
moon_SlideShow_reverse(moon_SlideShow* self) {
	const moon_Sprite* current = moon_SlideShow_get_current_sprite(self);
	if (!current) {
		return;
	}
	moon_vector_reverse<moon_Sprite>(self->sprites);
	moon_Sprite* next = moon_SlideShow_current(self);
	moon_SpriteTransform_apply_orient(next, current);
}

void
moon_SlideShow_clear(moon_SlideShow* self) {
	self->sprites.clear();
}

void
moon_SlideShow_flip(
	moon_SlideShow* self,
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
moon_SlideShow_push_back(
	moon_SlideShow* self,
	const moon_Texture* texture
) {
	moon_Sprite sprite(texture);
	moon_SlideShow_resize_sprite(self, &sprite);
	self->sprites.push_back(sprite);
}

moon_Angle
moon_SlideShow_get_rotation(const moon_SlideShow* self) {
	const moon_Sprite* current = moon_SlideShow_get_current_sprite(self);
	if (!current) {
		return 0.f;
	}
	return current->getRotation();
}

moon_Vector2f
moon_SlideShow_get_size(const moon_SlideShow* self) {
	const moon_Sprite* current = moon_SlideShow_get_current_sprite(self);
	if (!current) {
		return {0.f, 0.f};
	}
	return moon_Sprite_get_size(current);
}

moon_Vector2f
moon_SlideShow_get_position(const moon_SlideShow* self) {
	const moon_Sprite* current = moon_SlideShow_get_current_sprite(self);
	if (!current) {
		return {0.f, 0.f};
	}
	return moon_Sprite_get_position(current);
}

moon_Vector2f
moon_SlideShow_get_scale(const moon_SlideShow* self) {
	const moon_Sprite* current = moon_SlideShow_get_current_sprite(self);
	if (!current) {
		return {0.f, 0.f};
	}
	return moon_Sprite_get_scale(current);
}

moon_Color
moon_SlideShow_get_color(const moon_SlideShow* self) {
	const moon_Sprite* current = moon_SlideShow_get_current_sprite(self);
	if (!current) {
		return moon_Colors_Black(255);
	}
	return moon_Sprite_get_color(current);
}

moon_FloatRect
moon_SlideShow_get_local_bounds(const moon_SlideShow* self) {
	const moon_Sprite* current = moon_SlideShow_get_current_sprite(self);
	if (!current) {
		return moon_FloatRect_create_empty();
	}
	return moon_Sprite_get_local_bounds(current);
}

moon_FloatRect
moon_SlideShow_get_global_bounds(const moon_SlideShow* self) {
	const moon_Sprite* current = moon_SlideShow_get_current_sprite(self);
	if (!current) {
		return moon_FloatRect_create_empty();
	}
	return moon_Sprite_get_global_bounds(current);
}

moon_FloatRect
moon_SlideShow_get_world_bounds(const moon_SlideShow* self) {
	const moon_Sprite* current = moon_SlideShow_get_current_sprite(self);
	if (!current) {
		return moon_FloatRect_create_empty();
	}
	return moon_Sprite_get_world_bounds(current);
}


void
moon_SlideShow_resize_sprite(
	const moon_SlideShow* self,
	moon_Sprite* sprite
) {
	moon_SpriteTransform_scale(
		sprite,
		self->width, 		self->height,
		self->fixed_w, 		self->fixed_h
	);
}

moon_Sprite*
moon_SlideShow_current(moon_SlideShow* self) {
	if (self->sprites.empty()) {
		return nullptr;
	}
	return &self->sprites[self->ind];
}

const moon_Sprite*
moon_SlideShow_get_current_sprite(const moon_SlideShow* self) {
	if (self->sprites.empty()) {
		return nullptr;
	}
	return &self->sprites[self->ind];
}


moon_SlideShow::moon_SlideShow(
	unsigned long v_initial_size,
	float v_width, float v_heigth,
	int v_fixed_w, int v_fixed_h,
	float v_secs_per_frame
) {
	sprites.reserve(v_initial_size + 1UL);
	width 			= v_width;
	height 			= v_heigth;
	fixed_w 		= v_fixed_w;
	fixed_h 		= v_fixed_h;
	secs_per_frame	= v_secs_per_frame;
	cum_time 		= 0.f;
	ind 			= 0UL;
	clock 			= moon_Clock_create();
	if (!clock) {
		secs_per_frame = -1.f;
	}
}

void
moon_SlideShow::draw(
	sf::RenderTarget& target,
	sf::RenderStates states
) const {
	const moon_Sprite* current = moon_SlideShow_get_current_sprite(this);
	if (!current) {
		return;
	}
	target.draw(
		*(static_cast<const sf::Sprite*>(current)),
		states
	);
}

moon_FloatRect
moon_SlideShow::get_global_bounds() const {
	return moon_SlideShow_get_global_bounds(this);
}
