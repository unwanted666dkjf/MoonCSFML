#include <SFML/System/Vector2.hpp>


#include <SFML/Window/Mouse.hpp>



#include "../../headers/system/moon_vector2.h"


#include "../../headers/window/moon_mouse.h"


#include "../../headers/graphics/RenderWindowStruct.hpp"


int
moon_Mouse_is_button_pressed(int button) {
	return sf::Mouse::isButtonPressed(
		static_cast<sf::Mouse::Button>(button)
	);
}

moon_Vector2i
moon_Mouse_get_position() {
	sf::Vector2i v = sf::Mouse::getPosition();
	return {v.x, v.y};
}

moon_Vector2i
moon_Mouse_get_position_relative(const moon_RenderWindow* relative_to) {
	const sf::RenderWindow* wnd = static_cast<const sf::RenderWindow*>(relative_to);
	sf::Vector2i v = sf::Mouse::getPosition(*wnd);
	return {v.x, v.y};
}

void
moon_Mouse_set_position(int x, int y) {
	sf::Mouse::setPosition(sf::Vector2i(x, y));
}

void
moon_Mouse_set_position_relative(
	int x, int y,
	const moon_RenderWindow* relative_to
) {
	const sf::RenderWindow* wnd = static_cast<const sf::RenderWindow*>(relative_to);
	sf::Mouse::setPosition(sf::Vector2i(x, y), *wnd);
}
