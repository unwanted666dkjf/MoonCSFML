#ifndef MOON_CSFML_GRAPHICS_RENDER_WINDOW_STRUCT_HPP
#define MOON_CSFML_GRAPHICS_RENDER_WINDOW_STRUCT_HPP


#include <wchar.h>



#include <SFML/Graphics/RenderWindow.hpp>



#include "../window/moon_context_settings.h"


struct moon_RenderWindow : public sf::RenderWindow {

	moon_RenderWindow();

	moon_RenderWindow(
		unsigned int width,
		unsigned int height,
		unsigned int bits_per_pixel,
		const char* title,
		unsigned int style
	);

	moon_RenderWindow(
		unsigned int width,
		unsigned int height,
		unsigned int bits_per_pixel,
		const char* title,
		unsigned int style,
		const moon_ContextSettings* settings
	);

	moon_RenderWindow(
		unsigned int width,
		unsigned int height,
		unsigned int bits_per_pixel,
		const wchar_t* title,
		unsigned int style
	);

	moon_RenderWindow(
		unsigned int width,
		unsigned int height,
		unsigned int bits_per_pixel,
		const wchar_t* title,
		unsigned int style,
		const moon_ContextSettings* settings
	);

};


#endif
