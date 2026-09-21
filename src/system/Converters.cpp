#include "../../headers/system/Converters.hpp"


moon_Time
time_sf_to_moon(const sf::Time& time) {
	return moon_Time_from_microseconds(
		time.asMicroseconds()
	);
}

sf::Time
time_moon_to_sf(const moon_Time& time) {
	return sf::microseconds(
		moon_Time_as_microseconds(time)
	);
}
