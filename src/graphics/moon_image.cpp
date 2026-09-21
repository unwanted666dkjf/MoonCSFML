#include "../../headers/graphics/moon_image.h"

#include "../../headers/graphics/Converters.hpp"

#include "../../headers/graphics/ImageStruct.hpp"


moon_Image*
moon_Image_create() {
	return new moon_Image();
}

moon_Image*
moon_Image_from_color(
	unsigned int width,
	unsigned int height,
	const moon_Color* color
) {
	moon_Image* self = moon_Image_create();
	self->create(width, height, color_moon_to_sf(*color));
	return self;
}

moon_Image*
moon_Image_from_image(
	unsigned int width,
	unsigned int height,
	const moon_Image* image
) {
	moon_Image* self = moon_Image_create();
	self->create(width, height, image->getPixelsPtr());
	return self;
}

void
moon_Image_destroy(moon_Image* self) {
	delete self;
}

int
moon_Image_load(
	moon_Image* self,
	const char* filepath
) {
	return self->loadFromFile(std::string(filepath));
}

int
moon_Image_save(
	const moon_Image* self,
	const char* filepath
) {
	return self->saveToFile(std::string(filepath));
}

moon_Vector2u
moon_Image_get_size(const moon_Image* self) {
	sf::Vector2u size = self->getSize();
	return {size.x, size.y};
}

void
moon_Image_create_mask_from_color(
	moon_Image* self,
	const moon_Color* color,
	unsigned char alpha
) {
	self->createMaskFromColor(color_moon_to_sf(*color), alpha);
}

void
moon_Image_copy_pixels(
	moon_Image* self,
	const moon_Image* source,
	unsigned int dest_x,
	unsigned int dest_y,
	int apply_alpha
) {
	const sf::Image* src = static_cast<const sf::Image*>(source);
	self->copy(*src, dest_x, dest_y, sf::IntRect(0, 0, 0, 0), apply_alpha);
}

void
moon_Image_copy_pixels_ex(
	moon_Image* self,
	const moon_Image* source,
	unsigned int dest_x,
	unsigned int dest_y,
	int apply_alpha,
	const moon_IntRect* source_rect
) {
	const sf::Image* src = static_cast<const sf::Image*>(source);
	sf::IntRect src_rect = int_rect_moon_to_sf(*source_rect);
	self->copy(*src, dest_x, dest_y, src_rect, apply_alpha);
}

void
moon_Image_set_pixel(
	moon_Image* self,
	unsigned int x,
	unsigned int y,
	const moon_Color* color
) {
	self->setPixel(x, y, color_moon_to_sf(*color));
}

moon_Color
moon_Image_get_pixel(
	const moon_Image* self,
	unsigned int x,
	unsigned int y
) {
	sf::Color clr = self->getPixel(x, y);
	return color_sf_to_moon(clr);
}

void
moon_Image_flip_horizontally(moon_Image* self) {
	self->flipHorizontally();
}

void
moon_Image_flip_vertically(moon_Image* self) {
	self->flipVertically();
}


moon_Image::moon_Image() : sf::Image() {
	//
}
