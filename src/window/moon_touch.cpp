#include <SFML/System/Vector2.hpp>


#include <SFML/Window/Touch.hpp>



#include "../../headers/window/moon_touch.h"


#include "../../headers/graphics/RenderWindowStruct.hpp"


int
moon_Touch_is_down(unsigned int finger) {
	return sf::Touch::isDown(finger);
}

moon_Vector2i
moon_Touch_get_position(unsigned int finger) {
	sf::Vector2i v = sf::Touch::getPosition(finger);
	return {v.x, v.y};
}

moon_Vector2i
moon_Touch_get_position_relative(
	unsigned int finger,
	const moon_RenderWindow* relative_to
) {
	const sf::RenderWindow* wnd = static_cast<const sf::RenderWindow*>(relative_to);
	sf::Vector2i v = sf::Touch::getPosition(finger, *wnd);
	return {v.x, v.y};
}
