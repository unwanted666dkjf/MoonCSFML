// For me, nothing is private

#define private public

#define protected public


#include "../../headers/system/moon_utils.h"

#include "../../headers/system/moon_strutils.h"


#include "../../headers/graphics/moon_text.h"

#include "../../headers/graphics/RenderStatesStruct.hpp"

#include "../../headers/graphics/RenderWindowStruct.hpp"


#include "../../headers/extras/moon_gui_fpscntr.h"

#include "../../headers/extras/guiFpsCntrStruct.hpp"


moon_guiFpsCntr*
moon_guiFpsCntr_create(
	int precision,
	float update_time,
	const moon_Font* font,
	unsigned int character_size
) {
	return new moon_guiFpsCntr(
		precision,
		update_time,
		font,
		character_size
	);
}

moon_guiFpsCntr*
moon_guiFpsCntr_create_ex(
	int precision,
	float update_time,
	const moon_Font* font,
	unsigned int character_size,
	const moon_Color* fill_color
) {
	moon_guiFpsCntr* self = moon_guiFpsCntr_create(
		precision,
		update_time,
		font,
		character_size
	);
	moon_Text_set_fill_color(self->gui_fps, fill_color);
	return self;
}

void
moon_guiFpsCntr_destroy(moon_guiFpsCntr* self) {
	moon_guiFpsCntr_stop(self);
	delete self;
}

int
moon_guiFpsCntr_is_running(const moon_guiFpsCntr* self) {
	return moon_Clock_is_running(self->clock);
}

void
moon_guiFpsCntr_stop(moon_guiFpsCntr* self) {
	moon_Clock_stop(self->clock);
}

void
moon_guiFpsCntr_start(moon_guiFpsCntr* self) {
	moon_Clock_start(self->clock);
}

void
moon_guiFpsCntr_update(moon_guiFpsCntr* self) {
	if (!moon_Clock_is_running(self->clock)) {
		return;
	}
	moon_Clock_wait(self->clock);
	float elapsed_secs = moon_Time_as_seconds(
		moon_Clock_get_elapsed_time(self->clock)
	);
	if (elapsed_secs < self->update_time) {
		return;
	}
	moon_Clock_reset(self->clock);
	float seconds = moon_Time_as_seconds(
		moon_Clock_delta(self->clock)
	);
	if (seconds == 0.f) {
		return;
	}
	self->cur_fps = moon_roundf(
		1.f / seconds, self->precision
	);
	char* fps_str = moon_strprecfA(self->cur_fps, self->precision);
	sf::FloatRect old_bounds = self->gui_fps->getGlobalBounds();
	if (moon_Text_set_stringA(self->gui_fps, fps_str)) {
		sf::FloatRect new_bounds = self->gui_fps->getGlobalBounds();
		moon_Text_move(
			self->gui_fps,
			old_bounds.width - new_bounds.width,
			-(old_bounds.height - new_bounds.height)
		);
	}
	moon_free(fps_str);
}

void
moon_guiFpsCntr_draw(
	const moon_guiFpsCntr* self,
	moon_RenderWindow* wnd,
	const moon_RenderStates* states
) {
	moon_Text_draw(self->gui_fps, wnd, states);
}

float
moon_guiFpsCntr_get_fps(const moon_guiFpsCntr* self) {
	return self->cur_fps;
}

const char*
moon_guiFpsCntr_get_fps_strA(const moon_guiFpsCntr* self) {
	return moon_Text_get_stringA(self->gui_fps);
}

const wchar_t*
moon_guiFpsCntr_get_fps_strW(const moon_guiFpsCntr* self) {
	return moon_Text_get_stringW(self->gui_fps);
}

// Text begin.

moon_Vector2f
moon_guiFpsCntr_get_size(const moon_guiFpsCntr* self) {
	return moon_Text_get_size(self->gui_fps);
}

moon_FloatRect
moon_guiFpsCntr_get_world_bounds(const moon_guiFpsCntr* self) {
	return moon_Text_get_world_bounds(self->gui_fps);
}

void
moon_guiFpsCntr_set_font(
	moon_guiFpsCntr* self,
	const moon_Font* font
) {
	moon_Text_set_font(self->gui_fps, font);
}

void
moon_guiFpsCntr_set_character_size(
	moon_guiFpsCntr* self,
	unsigned int character_size
) {
	moon_Text_set_character_size(self->gui_fps, character_size);
}

void
moon_guiFpsCntr_set_line_spacing(
	moon_guiFpsCntr* self,
	float spacing_factor
) {
	moon_Text_set_line_spacing(self->gui_fps, spacing_factor);
}

void
moon_guiFpsCntr_set_letter_spacing(
	moon_guiFpsCntr* self,
	float spacing_factor
) {
	moon_Text_set_letter_spacing(self->gui_fps, spacing_factor);
}

void
moon_guiFpsCntr_set_style(
	moon_guiFpsCntr* self,
	unsigned int style
) {
	moon_Text_set_style(self->gui_fps, style);
}

void
moon_guiFpsCntr_set_fill_color(
	moon_guiFpsCntr* self,
	const moon_Color* fill_color
) {
	moon_Text_set_fill_color(self->gui_fps, fill_color);
}

void
moon_guiFpsCntr_set_outline_color(
	moon_guiFpsCntr* self,
	const moon_Color* outline_color
) {
	moon_Text_set_outline_color(self->gui_fps, outline_color);
}

void
moon_guiFpsCntr_set_outline_thickness(
	moon_guiFpsCntr* self,
	float outline_thickness
) {
	moon_Text_set_outline_thickness(self->gui_fps, outline_thickness);
}

const moon_Font*
moon_guiFpsCntr_get_font(const moon_guiFpsCntr* self) {
	return moon_Text_get_font(self->gui_fps);
}

unsigned int
moon_guiFpsCntr_get_character_size(const moon_guiFpsCntr* self) {
	return moon_Text_get_character_size(self->gui_fps);
}

float
moon_guiFpsCntr_get_letter_spacing(const moon_guiFpsCntr* self) {
	return moon_Text_get_letter_spacing(self->gui_fps);
}

float
moon_guiFpsCntr_get_line_spacing(const moon_guiFpsCntr* self) {
	return moon_Text_get_line_spacing(self->gui_fps);
}

unsigned int
moon_guiFpsCntr_get_style(const moon_guiFpsCntr* self) {
	return moon_Text_get_style(self->gui_fps);
}

moon_Color
moon_guiFpsCntr_get_fill_color(const moon_guiFpsCntr* self) {
	return moon_Text_get_fill_color(self->gui_fps);
}

moon_Color
moon_guiFpsCntr_get_outline_color(const moon_guiFpsCntr* self) {
	return moon_Text_get_outline_color(self->gui_fps);
}

float
moon_guiFpsCntr_get_outline_thickness(const moon_guiFpsCntr* self) {
	return moon_Text_get_outline_thickness(self->gui_fps);
}

moon_FloatRect
moon_guiFpsCntr_get_local_bounds(const moon_guiFpsCntr* self) {
	return moon_Text_get_local_bounds(self->gui_fps);
}

moon_FloatRect
moon_guiFpsCntr_get_global_bounds(const moon_guiFpsCntr* self) {
	return self->get_global_bounds();
}

void
moon_guiFpsCntr_set_position(
	moon_guiFpsCntr* self,
	float left, float top
) {
	moon_Text_set_position(self->gui_fps, left, top);
}

void
moon_guiFpsCntr_set_rotation(
	moon_guiFpsCntr* self,
	moon_Angle angle
) {
	moon_Text_set_rotation(self->gui_fps, angle);
}

void
moon_guiFpsCntr_set_scale(
	moon_guiFpsCntr* self,
	float scale_x, float scale_y
) {
	moon_Text_set_scale(self->gui_fps, scale_x, scale_y);
}

void
moon_guiFpsCntr_set_origin(
	moon_guiFpsCntr* self,
	float x, float y
) {
	moon_Text_set_origin(self->gui_fps, x, y);
}

moon_Vector2f
moon_guiFpsCntr_get_position(const moon_guiFpsCntr* self) {
	return moon_Text_get_position(self->gui_fps);
}

moon_Angle
moon_guiFpsCntr_get_rotation(const moon_guiFpsCntr* self) {
	return moon_Text_get_rotation(self->gui_fps);
}

moon_Vector2f
moon_guiFpsCntr_get_scale(const moon_guiFpsCntr* self) {
	return moon_Text_get_scale(self->gui_fps);
}

moon_Vector2f
moon_guiFpsCntr_get_origin(const moon_guiFpsCntr* self) {
	return moon_Text_get_origin(self->gui_fps);
}

void
moon_guiFpsCntr_move(
	moon_guiFpsCntr* self,
	float dx, float dy
) {
	moon_Text_move(self->gui_fps, dx, dy);
}

void
moon_guiFpsCntr_rotate(
	moon_guiFpsCntr* self,
	moon_Angle angle
) {
	moon_Text_rotate(self->gui_fps, angle);
}

void
moon_guiFpsCntr_scale(
	moon_guiFpsCntr* self,
	float scale_x, float scale_y
) {
	moon_Text_scale(self->gui_fps, scale_x, scale_y);
}

moon_Transform
moon_guiFpsCntr_get_transform(const moon_guiFpsCntr* self) {
	return moon_Text_get_transform(self->gui_fps);
}

moon_Transform
moon_guiFpsCntr_get_inverse_transform(const moon_guiFpsCntr* self) {
	return moon_Text_get_inverse_transform(self->gui_fps);
}

int
moon_guiFpsCntr_is_transform_updated(const moon_guiFpsCntr* self) {
	return moon_Text_is_transform_updated(self->gui_fps);
}

int
moon_guiFpsCntr_is_inversed_transform_updated(const moon_guiFpsCntr* self) {
	return moon_Text_is_inversed_transform_updated(self->gui_fps);
}

// Text end.


moon_guiFpsCntr::moon_guiFpsCntr(
	int v_precision,
	float v_update_time,
	const moon_Font* v_font,
	unsigned int v_character_size
) {
	gui_fps = moon_Text_createA(
		"0",
		v_font,
		v_character_size
	);
	precision 	= v_precision;
	update_time = v_update_time;
	cur_fps 	= 0.f;
	clock 		= moon_Clock_create();
}

moon_guiFpsCntr::~moon_guiFpsCntr() {
	moon_Text_destroy(gui_fps);
	moon_Clock_destroy(clock);
}

moon_FloatRect
moon_guiFpsCntr::get_global_bounds() const {
	return moon_Text_get_global_bounds(gui_fps);
}

void
moon_guiFpsCntr::draw(
	sf::RenderTarget& target,
	sf::RenderStates states
) const {
	const sf::Text* text = static_cast<const sf::Text*>(gui_fps);
	text->draw(target, states);
}


#undef private

#undef protected
