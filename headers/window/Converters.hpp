#ifndef MOON_CSFML_WINDOW_CONVERTERS_HPP
#define MOON_CSFML_WINDOW_CONVERTERS_HPP


#include <SFML/Window/VideoMode.hpp>

#include <SFML/Window/ContextSettings.hpp>



#include "./moon_video_mode.h"

#include "./moon_context_settings.h"


/**
 * Converts C++ VideoMode to C VideoMode.
 */
moon_VideoMode
video_mode_sf_to_moon(const sf::VideoMode& mode);

/**
 * Converts C VideoMode to C++ VideoMode.
 */
sf::VideoMode
video_mode_moon_to_sf(const moon_VideoMode& mode);


/**
 * Converts C++ ContextSettings to C ContextSettings.
 */
moon_ContextSettings
context_settings_sf_to_moon(const sf::ContextSettings& settings);

/**
 * Converts C ContextSettings to C++ ContextSettings.
 */
sf::ContextSettings
context_settings_moon_to_sf(const moon_ContextSettings& settings);


#endif
