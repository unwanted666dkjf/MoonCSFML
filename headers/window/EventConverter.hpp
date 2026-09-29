#ifndef MOON_CSFML_WINDOW_EVENT_CONVERTER_HPP
#define MOON_CSFML_WINDOW_EVENT_CONVERTER_HPP


#include <SFML/Window/Event.hpp>



#include "./moon_event.h"


/**
 * Converts sf::Event to moon_Event.
 */
void
event_sf_to_moon(const sf::Event& src, moon_Event* dst);


#endif
