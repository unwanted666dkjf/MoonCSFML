#ifndef MOON_CSFML_GRAPHICS_TEXT_STRUCT_HPP
#define MOON_CSFML_GRAPHICS_TEXT_STRUCT_HPP


#include <wchar.h>



#include <SFML/Graphics/Text.hpp>



#include "./moon_font.h"

#include "./BoundedDrawable.hpp"


struct moon_Text : public sf::Text, public moon_BoundedDrawable {

	moon_Text(
		const char* string,
		const moon_Font* font,
		unsigned int character_size
	);

	moon_Text(
		const wchar_t* string,
		const moon_Font* font,
		unsigned int character_size
	);

	virtual moon_FloatRect get_global_bounds() const;


	mutable std::string 	ansi_cache;

	mutable std::wstring 	wide_cache;

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};


#endif
