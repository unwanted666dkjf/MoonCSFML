#include <SFML/System/Vector3.hpp>


#include <SFML/Window/Sensor.hpp>



#include "../../headers/window/moon_sensor.h"


int
moon_Sensor_is_available(int sensor_type) {
	return sf::Sensor::isAvailable(
		static_cast<sf::Sensor::Type>(sensor_type)
	);
}

void
moon_Sensor_set_enabled(int sensor_type, int enabled) {
	sf::Sensor::setEnabled(
		static_cast<sf::Sensor::Type>(sensor_type),
		enabled
	);
}

moon_Vector3f
moon_Sensor_get_value(int sensor_type) {
	sf::Vector3f v = sf::Sensor::getValue(
		static_cast<sf::Sensor::Type>(sensor_type)
	);
	return {v.x, v.y, v.z};
}
