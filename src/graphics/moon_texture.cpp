#include "../../headers/graphics/moon_texture.h"

#include "../../headers/graphics/Converters.hpp"

#include "../../headers/graphics/ImageStruct.hpp"

#include "../../headers/graphics/TextureStruct.hpp"

#include "../../headers/graphics/RenderWindowStruct.hpp"


moon_Texture*
moon_Texture_create() {
	return new moon_Texture();
}

void
moon_Texture_destroy(moon_Texture* self) {
	delete self;
}

moon_Texture*
moon_Texture_get_copy(const moon_Texture* self) {
	return new moon_Texture(self);
}

void
moon_Texture_screen_capture(
	moon_Texture* self,
	const moon_RenderWindow* wnd
) {
	self->update(*wnd);
}

int
moon_Texture_adjust_size(
	moon_Texture* self,
	unsigned int width,
	unsigned int height
) {
	return self->create(width, height);
}

int
moon_Texture_load_from_file(
	moon_Texture* self,
	const char* filepath
) {
	return self->loadFromFile(std::string(filepath));
}

int
moon_Texture_load_from_file_ex(
	moon_Texture* self,
	const char* filepath,
	const moon_IntRect* area
) {
	sf::IntRect subrect = int_rect_moon_to_sf(*area);
	return self->loadFromFile(std::string(filepath), subrect);
}

int
moon_Texture_load_from_image(
	moon_Texture* self,
	const moon_Image* image
) {
	const sf::Image* img = static_cast<const sf::Image*>(image);
	return self->loadFromImage(*img);
}

int
moon_Texture_load_from_image_ex(
	moon_Texture* self,
	const moon_Image* image,
	const moon_IntRect* area
) {
	sf::IntRect subrect = int_rect_moon_to_sf(*area);
	const sf::Image* img = static_cast<const sf::Image*>(image);
	return self->loadFromImage(*img, subrect);
}

int
moon_Texture_save_to_file(
	const moon_Texture* self,
	const char* filepath
) {
	sf::Image img = self->copyToImage();
	return img.saveToFile(std::string(filepath));
}

moon_Image*
moon_Texture_to_image(const moon_Texture* self) {
	sf::Image img = self->copyToImage();
	sf::Vector2u img_size = img.getSize();
	return moon_Image_from_image(
		img_size.x, img_size.y,
		static_cast<const moon_Image*>(&img)
	);
}

moon_Vector2u
moon_Texture_get_size(const moon_Texture* self) {
	sf::Vector2u size = self->getSize();
	return {size.x, size.y};
}

void
moon_Texture_update_tex(
	moon_Texture* self,
	const moon_Texture* texture
) {
	const sf::Texture* tex = static_cast<const sf::Texture*>(texture);
	self->update(*tex);
}

void
moon_Texture_update_tex_ex(
	moon_Texture* self,
	const moon_Texture* texture,
	unsigned int x,
	unsigned int y
) {
	const sf::Texture* tex = static_cast<const sf::Texture*>(texture);
	self->update(*tex, x, y);
}

void
moon_Texture_update_img(
	moon_Texture* self,
	const moon_Image* image
) {
	const sf::Image* img = static_cast<const sf::Image*>(image);
	self->update(*img);
}

void
moon_Texture_update_img_ex(
	moon_Texture* self,
	const moon_Image* image,
	unsigned int x,
	unsigned int y
) {
	const sf::Image* img = static_cast<const sf::Image*>(image);
	self->update(*img, x, y);
}

void
moon_Texture_set_smooth(
	moon_Texture* self,
	int is_smooth
) {
	self->setSmooth(is_smooth);
}

int
moon_Texture_is_smooth(const moon_Texture* self) {
	return self->isSmooth();
}

void
moon_Texture_set_srgb(
	moon_Texture* self,
	int is_srgb
) {
	self->setSrgb(is_srgb);
}

int
moon_Texture_is_srgb(const moon_Texture* self) {
	return self->isSrgb();
}

void
moon_Texture_set_repeated(
	moon_Texture* self,
	int is_repeated
) {
	self->setRepeated(is_repeated);
}

int
moon_Texture_is_repeated(const moon_Texture* self) {
	return self->isRepeated();
}

int
moon_Texture_generate_mipmap(moon_Texture* self) {
	return self->generateMipmap();
}

void
moon_Texture_swap(
	moon_Texture* self,
	moon_Texture* other
) {
	sf::Texture* right = static_cast<sf::Texture*>(other);
	self->swap(*right);
}

unsigned int
moon_Texture_get_native_handle(const moon_Texture* self) {
	return self->getNativeHandle();
}

void
moon_Texture_bind(
	const moon_Texture* self,
	int coordinate_type
) {
	const sf::Texture* texture = static_cast<const sf::Texture*>(self);
	sf::Texture::bind(texture, static_cast<sf::Texture::CoordinateType>(coordinate_type));
}

unsigned int
moon_Texture_get_maximum_size() {
	return sf::Texture::getMaximumSize();
}


moon_Texture::moon_Texture() : sf::Texture() {
	//
}

moon_Texture::moon_Texture(
	const sf::Texture& texture
) : sf::Texture(texture) {
	//
}

moon_Texture::moon_Texture(
	const moon_Texture* other
) : sf::Texture(*other) {
	//
}
