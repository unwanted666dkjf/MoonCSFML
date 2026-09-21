#include <SFML/System/String.hpp>

#include <SFML/Window/Keyboard.hpp>


#include "../../headers/system/moon_strutils.h"

#include "../../headers/window/moon_keyboard.h"


int
moon_Keyboard_is_key_pressed(int key) {
	return sf::Keyboard::isKeyPressed(
		static_cast<sf::Keyboard::Key>(key)
	);
}

int
moon_Keyboard_is_scancode_pressed(int scancode) {
	return sf::Keyboard::isKeyPressed(
		static_cast<sf::Keyboard::Scancode>(scancode)
	);
}

int
moon_Keyboard_localize(int scancode) {
	return static_cast<int>(
		sf::Keyboard::localize(
			static_cast<sf::Keyboard::Scancode>(scancode)
		)
	);
}

int
moon_Keyboard_delocalize(int keycode) {
	return static_cast<int>(
		sf::Keyboard::delocalize(
			static_cast<sf::Keyboard::Key>(keycode)
		)
	);
}

char*
moon_Keyboard_get_descriptionA(int scancode) {
	sf::String description = sf::Keyboard::getDescription(
		static_cast<sf::Keyboard::Scancode>(scancode)
	);
	return moon_strcopyA(
		description.toAnsiString().c_str(),
		description.getSize()
	);
}

wchar_t*
moon_Keyboard_get_descriptionW(int scancode) {
	sf::String description = sf::Keyboard::getDescription(
		static_cast<sf::Keyboard::Scancode>(scancode)
	);
	return moon_strcopyW(
		description.toWideString().c_str(),
		description.getSize()
	);
}

void
moon_Keyboard_set_virtual_keyboard_visible(int visible) {
	sf::Keyboard::setVirtualKeyboardVisible(visible);
}
