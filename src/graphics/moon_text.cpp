// Access modifiers are dead now.

#define private public

#define protected public


#include "../../headers/system/moon_strutils.h"


#include "../../headers/graphics/moon_text.h"

#include "../../headers/graphics/Converters.hpp"

#include "../../headers/graphics/FontStruct.hpp"

#include "../../headers/graphics/TextStruct.hpp"

#include "../../headers/graphics/RenderStatesStruct.hpp"

#include "../../headers/graphics/RenderWindowStruct.hpp"

#include "../../headers/graphics/TransformableUtils.hpp"


static void
moon_Text_clear_cache(moon_Text* self);


moon_Text*
moon_Text_createA(
	const char* string,
	const moon_Font* font,
	unsigned int character_size
) {
	return new moon_Text(string, font, character_size);
}

moon_Text*
moon_Text_createW(
	const wchar_t* string,
	const moon_Font* font,
	unsigned int character_size
) {
	return new moon_Text(string, font, character_size);
}

void
moon_Text_destroy(moon_Text* self) {
	delete self;
}

void
moon_Text_draw(
	const moon_Text* self,
	moon_RenderWindow* wnd,
	const moon_RenderStates* states
) {
	wnd->draw(
		*(static_cast<const sf::Text*>(self)),
		*states
	);
}

moon_Vector2f
moon_Text_get_size(const moon_Text* self) {
	sf::FloatRect bounds = self->getGlobalBounds();
	return {bounds.width, bounds.height};
}

moon_FloatRect
moon_Text_get_world_bounds(const moon_Text* self) {
	sf::FloatRect bounds = self->getGlobalBounds();
	return {
		self->m_position.x,
		self->m_position.y,
		bounds.width,
		bounds.height
	};
}

int
moon_Text_set_stringA(
	moon_Text* self,
	const char* string
) {
	if (
		!moon_str_is_equalA(
			string, moon_Text_get_stringA(self)
		)
	) {
		self->m_string = sf::String(string);
		self->m_geometryNeedUpdate = true;
		moon_Text_clear_cache(self);
		return 1;
	}
	return 0;
}

int
moon_Text_set_stringW(
	moon_Text* self,
	const wchar_t* string
) {
	if (
		!moon_str_is_equalW(
			string, moon_Text_get_stringW(self)
		)
	) {
		self->m_string = sf::String(string);
		self->m_geometryNeedUpdate = true;
		moon_Text_clear_cache(self);
		return 1;
	}
	return 0;
}

void
moon_Text_set_font(
	moon_Text* self,
	const moon_Font* font
) {
	self->setFont(*font);
}

void
moon_Text_set_character_size(
	moon_Text* self,
	unsigned int character_size
) {
	self->setCharacterSize(character_size);
}

void
moon_Text_set_line_spacing(
	moon_Text* self,
	float spacing_factor
) {
	self->setLineSpacing(spacing_factor);
}

void
moon_Text_set_letter_spacing(
	moon_Text* self,
	float spacing_factor
) {
	self->setLetterSpacing(spacing_factor);
}

void
moon_Text_set_style(
	moon_Text* self,
	unsigned int style
) {
	self->setStyle(style);
}

void
moon_Text_set_fill_color(
	moon_Text* self,
	const moon_Color* fill_color
) {
	self->setFillColor(color_moon_to_sf(*fill_color));
}

void
moon_Text_set_outline_color(
	moon_Text* self,
	const moon_Color* outline_color
) {
	self->setOutlineColor(color_moon_to_sf(*outline_color));
}

void
moon_Text_set_outline_thickness(
	moon_Text* self,
	float outline_thickness
) {
	self->setOutlineThickness(outline_thickness);
}

const char*
moon_Text_get_stringA(const moon_Text* self) {
	if (self->ansi_cache.empty()) {
		self->ansi_cache.append(
			self->getString()
			.toAnsiString()
			.c_str()
		);
	}
	return self->ansi_cache.c_str();
}

const wchar_t*
moon_Text_get_stringW(const moon_Text* self) {
	if (self->wide_cache.empty()) {
		self->wide_cache.append(
			self->getString()
			.toWideString()
			.c_str()
		);
	}
	return self->wide_cache.c_str();
}

const moon_Font*
moon_Text_get_font(const moon_Text* self) {
	return static_cast<const moon_Font*>(self->getFont());
}

unsigned int
moon_Text_get_character_size(const moon_Text* self) {
	return self->getCharacterSize();
}

float
moon_Text_get_letter_spacing(const moon_Text* self) {
	return self->getLetterSpacing();
}

float
moon_Text_get_line_spacing(const moon_Text* self) {
	return self->getLineSpacing();
}

unsigned int
moon_Text_get_style(const moon_Text* self) {
	return self->getStyle();
}

moon_Color
moon_Text_get_fill_color(const moon_Text* self) {
	return color_sf_to_moon(self->getFillColor());
}

moon_Color
moon_Text_get_outline_color(const moon_Text* self) {
	return color_sf_to_moon(self->getOutlineColor());
}

float
moon_Text_get_outline_thickness(const moon_Text* self) {
	return self->getOutlineThickness();
}

moon_Vector2f
moon_Text_find_character_position(
	const moon_Text* self,
	unsigned long index
) {
	sf::Vector2f pos = self->findCharacterPos(static_cast<std::size_t>(index));
	return {pos.x, pos.y};
}

moon_FloatRect
moon_Text_get_local_bounds(const moon_Text* self) {
	return float_rect_sf_to_moon(self->getLocalBounds());
}

moon_FloatRect
moon_Text_get_global_bounds(const moon_Text* self) {
	return float_rect_sf_to_moon(self->getGlobalBounds());
}


// Transformable begin

void
moon_Text_set_position(
	moon_Text* self,
	float left, float top
) {
	self->setPosition(left, top);
}

void
moon_Text_set_rotation(
	moon_Text* self,
	moon_Angle angle
) {
	self->setRotation(angle);
}

void
moon_Text_set_scale(
	moon_Text* self,
	float scale_x, float scale_y
) {
	self->setScale(scale_x, scale_y);
}

void
moon_Text_set_origin(
	moon_Text* self,
	float x, float y
) {
	self->setOrigin(x, y);
}

moon_Vector2f
moon_Text_get_position(const moon_Text* self) {
	return moon_Transformable_get_position<moon_Text>(self);
}

moon_Angle
moon_Text_get_rotation(const moon_Text* self) {
	return self->getRotation();
}

moon_Vector2f
moon_Text_get_scale(const moon_Text* self) {
	return moon_Transformable_get_scale<moon_Text>(self);
}

moon_Vector2f
moon_Text_get_origin(const moon_Text* self) {
	return moon_Transformable_get_origin<moon_Text>(self);
}

void
moon_Text_move(
	moon_Text* self,
	float dx, float dy
) {
	self->move(dx, dy);
}

void
moon_Text_rotate(
	moon_Text* self,
	moon_Angle angle
) {
	self->rotate(angle);
}

void
moon_Text_scale(
	moon_Text* self,
	float scale_x, float scale_y
) {
	self->scale(scale_x, scale_y);
}

moon_Transform
moon_Text_get_transform(const moon_Text* self) {
	return moon_Transformable_get_transform<moon_Text>(self);
}

moon_Transform
moon_Text_get_inverse_transform(const moon_Text* self) {
	return moon_Transformable_get_inverse_transform<moon_Text>(self);
}

int
moon_Text_is_transform_updated(const moon_Text* self) {
	return self->m_transformNeedUpdate;
}

int
moon_Text_is_inversed_transform_updated(const moon_Text* self) {
	return self->m_inverseTransformNeedUpdate;
}

// Transformable end


void
moon_Text_clear_cache(moon_Text* self) {
	self->ansi_cache.clear();
	self->wide_cache.clear();
}


moon_Text::moon_Text(
	const char* string,
	const moon_Font* font,
	unsigned int character_size
) : sf::Text(
	sf::String(string),
	*font,
	character_size
) {
	//
}

moon_Text::moon_Text(
	const wchar_t* string,
	const moon_Font* font,
	unsigned int character_size
) : sf::Text(
	sf::String(string),
	*font,
	character_size
) {
	//
}

moon_FloatRect
moon_Text::get_global_bounds() const {
	return moon_Text_get_global_bounds(this);
}

void
moon_Text::draw(
	sf::RenderTarget& target,
	sf::RenderStates states
) const {
	sf::Text::draw(target, states);
}


#undef private

#undef protected
