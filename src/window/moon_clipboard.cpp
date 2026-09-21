#include <SFML/System/String.hpp>


#include <SFML/Window/Clipboard.hpp>



#include "../../headers/system/moon_strutils.h"


#include "../../headers/window/moon_clipboard.h"


void
moon_Clipboard_set_stringA(const char* str) {
	sf::Clipboard::setString(sf::String(str));
}

void
moon_Clipboard_set_stringW(const wchar_t* str) {
	sf::Clipboard::setString(sf::String(str));
}

char*
moon_Clipboard_get_stringA() {
	sf::String content = sf::Clipboard::getString();
	return moon_strcopyA(
		content.toAnsiString().c_str(),
		content.getSize()
	);
}

wchar_t*
moon_Clipboard_get_stringW() {
	sf::String content = sf::Clipboard::getString();
	return moon_strcopyW(
		content.toWideString().c_str(),
		content.getSize()
	);
}
