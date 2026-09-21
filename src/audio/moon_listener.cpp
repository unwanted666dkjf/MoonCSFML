#include <SFML/Audio/Listener.hpp>



#include "../../headers/audio/moon_listener.h"


void
moon_Listener_set_global_volume(float volume) {
	sf::Listener::setGlobalVolume(volume);
}

float
moon_Listener_get_global_volume() {
	return sf::Listener::getGlobalVolume();
}

void
moon_Listener_set_position(float x, float y, float z) {
	sf::Listener::setPosition(x, y, z);
}

moon_Vector3f
moon_Listener_get_position() {
	sf::Vector3f res = sf::Listener::getPosition();
	return {res.x, res.y, res.z};
}

void
moon_Listener_set_direction(float x, float y, float z) {
	sf::Listener::setDirection(x, y, z);
}

moon_Vector3f
moon_Listener_get_direction() {
	sf::Vector3f res = sf::Listener::getDirection();
	return {res.x, res.y, res.z};
}

void
moon_Listener_set_up_vector(float x, float y, float z) {
	sf::Listener::setUpVector(x, y, z);
}

moon_Vector3f
moon_Listener_get_up_vector() {
	sf::Vector3f res = sf::Listener::getUpVector();
	return {res.x, res.y, res.z};
}
