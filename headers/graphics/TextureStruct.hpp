#ifndef MOON_CSFML_GRAPHICS_TEXTURE_STRUCT_HPP
#define MOON_CSFML_GRAPHICS_TEXTURE_STRUCT_HPP


#include <SFML/Graphics/Texture.hpp>


struct moon_Texture : public sf::Texture {

	moon_Texture();

	moon_Texture(const sf::Texture& texture);

	moon_Texture(const moon_Texture* other);

};


#endif
