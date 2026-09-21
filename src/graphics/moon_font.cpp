#include "../../headers/graphics/moon_font.h"

#include "../../headers/graphics/Converters.hpp"

#include "../../headers/graphics/FontStruct.hpp"

#include "../../headers/graphics/TextureStruct.hpp"


moon_Font*
moon_Font_create() {
	return new moon_Font();
}

void
moon_Font_destroy(moon_Font* self) {
	delete self;
}

moon_Font*
moon_Font_get_copy(const moon_Font* self) {
	return new moon_Font(self);
}

int
moon_Font_load(
	moon_Font* self,
	const char* filepath
) {
	return self->loadFromFile(std::string(filepath));
}

const char*
moon_Font_get_family(const moon_Font* self) {
	return self->getInfo().family.c_str();
}

moon_Glyph
moon_Font_get_glyph(
	const moon_Font* self,
	unsigned int code_point,
	unsigned int character_size,
	int is_bold,
	float outline_thickness
) {
	return glyph_sf_to_moon(
		self->getGlyph(
			code_point,
			character_size,
			is_bold,
			outline_thickness
		)
	);
}

int
moon_Font_has_glyph(
	const moon_Font* self,
	unsigned int code_point
) {
	return self->hasGlyph(code_point);
}

float
moon_Font_get_kerning(
	const moon_Font* self,
	unsigned int first,
	unsigned int second,
	unsigned int character_size,
	int is_bold
) {
	return self->getKerning(first, second, character_size, is_bold);
}

float
moon_Font_get_line_spacing(
	const moon_Font* self,
	unsigned int character_size
) {
	return self->getLineSpacing(character_size);
}

float
moon_Font_get_underline_position(
	const moon_Font* self,
	unsigned int character_size
) {
	return self->getUnderlinePosition(character_size);
}

float
moon_Font_get_underline_thickness(
	const moon_Font* self,
	unsigned int character_size
) {
	return self->getUnderlineThickness(character_size);
}

moon_Texture*
moon_Font_get_texture(
	const moon_Font* self,
	unsigned int character_size
) {
	return new moon_Texture(self->getTexture(character_size));
}

void
moon_Font_set_smooth(
	moon_Font* self,
	int is_smooth
) {
	self->setSmooth(is_smooth);
}

int
moon_Font_is_smooth(const moon_Font* self) {
	return self->isSmooth();
}


moon_Font::moon_Font() : sf::Font() {
	//
}

moon_Font::moon_Font(
	const moon_Font* other
) : sf::Font(*other) {
	//
}
