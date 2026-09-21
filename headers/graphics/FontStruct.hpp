#ifndef MOON_CSFML_GRAPHICS_FONT_STRUCT_HPP
#define MOON_CSFML_GRAPHICS_FONT_STRUCT_HPP


#include <SFML/Graphics/Font.hpp>


struct moon_Font : public sf::Font {

	moon_Font();

	moon_Font(const moon_Font* other);

};


#endif
