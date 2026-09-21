#ifndef MOON_CSFML_SYSTEM_CONVERTERS_HPP
#define MOON_CSFML_SYSTEM_CONVERTERS_HPP


#include <SFML/System/Time.hpp>



#include "./moon_time.h"


/**
 * Converts C++ time to C time.
 */
moon_Time
time_sf_to_moon(const sf::Time& time);

/**
 * Converts C time to C++ time.
 */
sf::Time
time_moon_to_sf(const moon_Time& time);


#endif
