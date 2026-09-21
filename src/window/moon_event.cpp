#include "../../headers/window/moon_event.h"

#include "../../headers/window/EventStruct.hpp"


moon_Event*
moon_Event_create() {
	return new moon_Event();
}

void
moon_Event_destroy(moon_Event* self) {
	delete self;
}

void
moon_Event_reset(moon_Event* self) {
	sf::Event* evt = static_cast<sf::Event*>(self);
	evt->type = sf::Event::EventType::Count;
}

int
moon_Event_get_type(const moon_Event* self) {
	const sf::Event* evt = static_cast<const sf::Event*>(self);
	return evt->type;
}

unsigned int
moon_Event_get_size_width(const moon_Event* self) {
	const sf::Event* evt = static_cast<const sf::Event*>(self);
	return evt->size.width;
}

unsigned int
moon_Event_get_size_height(const moon_Event* self) {
	const sf::Event* evt = static_cast<const sf::Event*>(self);
	return evt->size.height;
}

int
moon_Event_get_key_keycode(const moon_Event* self) {
	const sf::Event* evt = static_cast<const sf::Event*>(self);
	return evt->key.code;
}

int
moon_Event_get_key_scancode(const moon_Event* self) {
	const sf::Event* evt = static_cast<const sf::Event*>(self);
	return evt->key.scancode;
}

int
moon_Event_get_key_is_alt(const moon_Event* self) {
	const sf::Event* evt = static_cast<const sf::Event*>(self);
	return evt->key.alt;
}

int
moon_Event_get_key_is_control(const moon_Event* self) {
	const sf::Event* evt = static_cast<const sf::Event*>(self);
	return evt->key.control;
}

int
moon_Event_get_key_is_shift(const moon_Event* self) {
	const sf::Event* evt = static_cast<const sf::Event*>(self);
	return evt->key.shift;
}

int
moon_Event_get_key_is_system(const moon_Event* self) {
	const sf::Event* evt = static_cast<const sf::Event*>(self);
	return evt->key.system;
}

unsigned int
moon_Event_get_text_unicode(const moon_Event* self) {
	const sf::Event* evt = static_cast<const sf::Event*>(self);
	return evt->text.unicode;
}

int
moon_Event_get_mouse_move_x(const moon_Event* self) {
	const sf::Event* evt = static_cast<const sf::Event*>(self);
	return evt->mouseMove.x;
}

int
moon_Event_get_mouse_move_y(const moon_Event* self) {
	const sf::Event* evt = static_cast<const sf::Event*>(self);
	return evt->mouseMove.y;
}

int
moon_Event_get_mouse_button_button(const moon_Event* self) {
	const sf::Event* evt = static_cast<const sf::Event*>(self);
	return evt->mouseButton.button;
}

int
moon_Event_get_mouse_button_x(const moon_Event* self) {
	const sf::Event* evt = static_cast<const sf::Event*>(self);
	return evt->mouseButton.x;
}

int
moon_Event_get_mouse_button_y(const moon_Event* self) {
	const sf::Event* evt = static_cast<const sf::Event*>(self);
	return evt->mouseButton.y;
}

int
moon_Event_get_mouse_wheel_delta(const moon_Event* self) {
	const sf::Event* evt = static_cast<const sf::Event*>(self);
	return evt->mouseWheel.delta;
}

int
moon_Event_get_mouse_wheel_x(const moon_Event* self) {
	const sf::Event* evt = static_cast<const sf::Event*>(self);
	return evt->mouseWheel.x;
}

int
moon_Event_get_mouse_wheel_y(const moon_Event* self) {
	const sf::Event* evt = static_cast<const sf::Event*>(self);
	return evt->mouseWheel.y;
}

int
moon_Event_get_mouse_wheel_scroll_wheel(const moon_Event* self) {
	const sf::Event* evt = static_cast<const sf::Event*>(self);
	return evt->mouseWheelScroll.wheel;
}

float
moon_Event_get_mouse_wheel_scroll_delta(const moon_Event* self) {
	const sf::Event* evt = static_cast<const sf::Event*>(self);
	return evt->mouseWheelScroll.delta;
}

int
moon_Event_get_mouse_wheel_scroll_x(const moon_Event* self) {
	const sf::Event* evt = static_cast<const sf::Event*>(self);
	return evt->mouseWheelScroll.x;
}

int
moon_Event_get_mouse_wheel_scroll_y(const moon_Event* self) {
	const sf::Event* evt = static_cast<const sf::Event*>(self);
	return evt->mouseWheelScroll.y;
}

unsigned int
moon_Event_get_touch_finger(const moon_Event* self) {
	const sf::Event* evt = static_cast<const sf::Event*>(self);
	return evt->touch.finger;
}

int
moon_Event_get_touch_x(const moon_Event* self) {
	const sf::Event* evt = static_cast<const sf::Event*>(self);
	return evt->touch.x;
}

int
moon_Event_get_touch_y(const moon_Event* self) {
	const sf::Event* evt = static_cast<const sf::Event*>(self);
	return evt->touch.y;
}

int
moon_Event_get_sensor_type(const moon_Event* self) {
	const sf::Event* evt = static_cast<const sf::Event*>(self);
	return evt->sensor.type;
}

float
moon_Event_get_sensor_x(const moon_Event* self) {
	const sf::Event* evt = static_cast<const sf::Event*>(self);
	return evt->sensor.x;
}

float
moon_Event_get_sensor_y(const moon_Event* self) {
	const sf::Event* evt = static_cast<const sf::Event*>(self);
	return evt->sensor.y;
}

float
moon_Event_get_sensor_z(const moon_Event* self) {
	const sf::Event* evt = static_cast<const sf::Event*>(self);
	return evt->sensor.z;
}


moon_Event::moon_Event() : sf::Event() {
	//
}
