// Deprived Text

#define private public

#define protected public


#include "../../headers/graphics/moon_text.h"

#include "../../headers/graphics/RenderStatesStruct.hpp"

#include "../../headers/graphics/RenderWindowStruct.hpp"


#include "../../headers/extras/moon_text_write.h"

#include "../../headers/extras/TextWriteStruct.hpp"


static void
moon_TextWrite_realign(
	moon_TextWrite* self,
	const sf::FloatRect& old_bounds
);


moon_TextWrite*
moon_TextWrite_create(
	float typing_speed,
	const moon_Font* font,
	unsigned int character_size
) {
	return new moon_TextWrite(
		typing_speed,
		font,
		character_size
	);
}

moon_TextWrite*
moon_TextWrite_create_ex(
	float typing_speed,
	const moon_Font* font,
	unsigned int character_size,
	const moon_Color* fill_color
) {
	moon_TextWrite* self = moon_TextWrite_create(
		typing_speed,
		font,
		character_size
	);
	moon_Text_set_fill_color(self->text, fill_color);
	return self;
}

void
moon_TextWrite_destroy(moon_TextWrite* self) {
	moon_TextWrite_stop(self);
	delete self;
}

int
moon_TextWrite_is_running(const moon_TextWrite* self) {
	return moon_Clock_is_running(self->clock);
}

void
moon_TextWrite_stop(moon_TextWrite* self) {
	moon_Clock_stop(self->clock);
}

void
moon_TextWrite_start(moon_TextWrite* self) {
	moon_Clock_start(self->clock);
}

void
moon_TextWrite_restart(moon_TextWrite* self) {
	moon_Clock_start(self->clock);
	self->cur_ind = 0UL;
}

void
moon_TextWrite_set_textA(
	moon_TextWrite* self,
	const char* text
) {
	self->text_to_type = sf::String(text);
}

void
moon_TextWrite_set_textW(
	moon_TextWrite* self,
	const wchar_t* text
) {
	self->text_to_type = sf::String(text);
}

void
moon_TextWrite_update(moon_TextWrite* self) {
	if (!moon_Clock_is_running(self->clock)) {
		return;
	}
	moon_Clock_wait(self->clock);
	if (self->cur_ind >= self->text_to_type.getSize()) {
		moon_Clock_stop(self->clock);
		return;
	}
	float elapsed_seconds = moon_Time_as_seconds(
		moon_Clock_get_elapsed_time(self->clock)
	);
	if (elapsed_seconds < self->typing_speed) {
		return;
	}
	moon_Clock_reset(self->clock);
	sf::String new_str = self->text_to_type.substring(0, ++self->cur_ind);
	sf::FloatRect old_bounds = self->text->getGlobalBounds();
	if(moon_Text_set_stringW(self->text, new_str.toWideString().c_str())) {
		moon_TextWrite_realign(self, old_bounds);
	}
}

void
moon_TextWrite_clear(moon_TextWrite* self) {
	sf::FloatRect old_bounds = self->text->getGlobalBounds();
	if (moon_Text_set_stringA(self->text, "")) {
		moon_TextWrite_realign(self, old_bounds);
	}
	self->cur_ind = 0UL;
}

void
moon_TextWrite_draw(
	const moon_TextWrite* self,
	moon_RenderWindow* wnd,
	const moon_RenderStates* states
) {
	moon_Text_draw(self->text, wnd, states);
}

const char*
moon_TextWrite_get_stringA(const moon_TextWrite* self) {
	return moon_Text_get_stringA(self->text);
}

const wchar_t*
moon_TextWrite_get_stringW(const moon_TextWrite* self) {
	return moon_Text_get_stringW(self->text);
}

// Text begin

moon_Vector2f
moon_TextWrite_get_size(const moon_TextWrite* self) {
	return moon_Text_get_size(self->text);
}

moon_FloatRect
moon_TextWrite_get_world_bounds(const moon_TextWrite* self) {
	return moon_Text_get_world_bounds(self->text);
}

void
moon_TextWrite_set_font(
	moon_TextWrite* self,
	const moon_Font* font
) {
	moon_Text_set_font(self->text, font);
}

void
moon_TextWrite_set_character_size(
	moon_TextWrite* self,
	unsigned int character_size
) {
	moon_Text_set_character_size(self->text, character_size);
}

void
moon_TextWrite_set_line_spacing(
	moon_TextWrite* self,
	float spacing_factor
) {
	moon_Text_set_line_spacing(self->text, spacing_factor);
}

void
moon_TextWrite_set_letter_spacing(
	moon_TextWrite* self,
	float spacing_factor
) {
	moon_Text_set_letter_spacing(self->text, spacing_factor);
}

void
moon_TextWrite_set_style(
	moon_TextWrite* self,
	unsigned int style
) {
	moon_Text_set_style(self->text, style);
}

void
moon_TextWrite_set_fill_color(
	moon_TextWrite* self,
	const moon_Color* fill_color
) {
	moon_Text_set_fill_color(self->text, fill_color);
}

void
moon_TextWrite_set_outline_color(
	moon_TextWrite* self,
	const moon_Color* outline_color
) {
	moon_Text_set_outline_color(self->text, outline_color);
}

void
moon_TextWrite_set_outline_thickness(
	moon_TextWrite* self,
	float outline_thickness
) {
	moon_Text_set_outline_thickness(self->text, outline_thickness);
}

const moon_Font*
moon_TextWrite_get_font(const moon_TextWrite* self) {
	return moon_Text_get_font(self->text);
}

unsigned int
moon_TextWrite_get_character_size(const moon_TextWrite* self) {
	return moon_Text_get_character_size(self->text);
}

float
moon_TextWrite_get_letter_spacing(const moon_TextWrite* self) {
	return moon_Text_get_letter_spacing(self->text);
}

float
moon_TextWrite_get_line_spacing(const moon_TextWrite* self) {
	return moon_Text_get_line_spacing(self->text);
}

unsigned int
moon_TextWrite_get_style(const moon_TextWrite* self) {
	return moon_Text_get_style(self->text);
}

moon_Color
moon_TextWrite_get_fill_color(const moon_TextWrite* self) {
	return moon_Text_get_fill_color(self->text);
}

moon_Color
moon_TextWrite_get_outline_color(const moon_TextWrite* self) {
	return moon_Text_get_outline_color(self->text);
}

float
moon_TextWrite_get_outline_thickness(const moon_TextWrite* self) {
	return moon_Text_get_outline_thickness(self->text);
}

moon_FloatRect
moon_TextWrite_get_local_bounds(const moon_TextWrite* self) {
	return moon_Text_get_local_bounds(self->text);
}

moon_FloatRect
moon_TextWrite_get_global_bounds(const moon_TextWrite* self) {
	return self->get_global_bounds();
}

void
moon_TextWrite_set_position(
	moon_TextWrite* self,
	float left, float top
) {
	moon_Text_set_position(self->text, left, top);
}

void
moon_TextWrite_set_rotation(
	moon_TextWrite* self,
	moon_Angle angle
) {
	moon_Text_set_rotation(self->text, angle);
}

void
moon_TextWrite_set_scale(
	moon_TextWrite* self,
	float scale_x, float scale_y
) {
	moon_Text_set_scale(self->text, scale_x, scale_y);
}

void
moon_TextWrite_set_origin(
	moon_TextWrite* self,
	float x, float y
) {
	moon_Text_set_origin(self->text, x, y);
}

moon_Vector2f
moon_TextWrite_get_position(const moon_TextWrite* self) {
	return moon_Text_get_position(self->text);
}

moon_Angle
moon_TextWrite_get_rotation(const moon_TextWrite* self) {
	return moon_Text_get_rotation(self->text);
}

moon_Vector2f
moon_TextWrite_get_scale(const moon_TextWrite* self) {
	return moon_Text_get_scale(self->text);
}

moon_Vector2f
moon_TextWrite_get_origin(const moon_TextWrite* self) {
	return moon_Text_get_origin(self->text);
}

void
moon_TextWrite_move(
	moon_TextWrite* self,
	float dx, float dy
) {
	moon_Text_move(self->text, dx, dy);
}

void
moon_TextWrite_rotate(
	moon_TextWrite* self,
	moon_Angle angle
) {
	moon_Text_rotate(self->text, angle);
}

void
moon_TextWrite_scale(
	moon_TextWrite* self,
	float scale_x, float scale_y
) {
	moon_Text_scale(self->text, scale_x, scale_y);
}

moon_Transform
moon_TextWrite_get_transform(const moon_TextWrite* self) {
	return moon_Text_get_transform(self->text);
}

moon_Transform
moon_TextWrite_get_inverse_transform(const moon_TextWrite* self) {
	return moon_Text_get_inverse_transform(self->text);
}

int
moon_TextWrite_is_transform_updated(const moon_TextWrite* self) {
	return moon_Text_is_transform_updated(self->text);
}

int
moon_TextWrite_is_inversed_transform_updated(const moon_TextWrite* self) {
	return moon_Text_is_inversed_transform_updated(self->text);
}

// Text end.

void
moon_TextWrite_realign(
	moon_TextWrite* self,
	const sf::FloatRect& old_bounds
) {
	sf::FloatRect new_bounds = self->text->getGlobalBounds();

	float old_centerx = old_bounds.left + old_bounds.width * .5f;
	float old_centery = old_bounds.top + old_bounds.height * .5f;

	float new_centerx = new_bounds.left + new_bounds.width * .5f;
	float new_centery = new_bounds.top + new_bounds.height * .5f;

	moon_Text_move(
		self->text,
		old_centerx - new_centerx,
		old_centery - new_centery
	);
}


moon_TextWrite::moon_TextWrite(
	float v_typing_speed,
	const moon_Font* v_font,
	unsigned int v_character_size
) {
	text = moon_Text_createA(
		"0",
		v_font,
		v_character_size
	);
	clock 			= moon_Clock_create();
	cur_ind 		= 0UL;
	typing_speed 	= v_typing_speed;
	text_to_type 	= sf::String("");
}

moon_TextWrite::~moon_TextWrite() {
	moon_Text_destroy(text);
	moon_Clock_destroy(clock);
}

moon_FloatRect
moon_TextWrite::get_global_bounds() const {
	return moon_Text_get_global_bounds(text);
}

void
moon_TextWrite::draw(
	sf::RenderTarget& target,
	sf::RenderStates states
) const {
	const sf::Text* sf_text = static_cast<const sf::Text*>(text);
	sf_text->draw(target, states);
}


#undef private

#undef protected
