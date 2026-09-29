#include "../../headers/window/EventConverter.hpp"


static void
event_convert_key_evt(
	const sf::Event::KeyEvent& src,
	moon_KeyEvent& dst
);

static void
event_convert_button_evt(
	const sf::Event::MouseButtonEvent& src,
	moon_MouseButtonEvent& dst
);

static void
event_convert_move_evt(
	const sf::Event::MouseMoveEvent& src,
	moon_MouseMoveEvent& dst
);

static void
event_convert_wheel_evt(
	const sf::Event::MouseWheelEvent& src,
	moon_MouseWheelEvent& dst
);

static void
event_convert_wheel_scrolled_evt(
	const sf::Event::MouseWheelScrollEvent& src,
	moon_MouseWheelScrollEvent& dst
);

static void
event_convert_resized_evt(
	const sf::Event::SizeEvent& src,
	moon_SizeEvent& dst
);

static void
event_convert_text_entered_evt(
	const sf::Event::TextEvent& src,
	moon_TextEvent& dst
);

static void
event_convert_touch_evt(
	const sf::Event::TouchEvent& src,
	moon_TouchEvent& dst
);

static void
event_convert_sensor_evt(
	const sf::Event::SensorEvent& src,
	moon_SensorEvent& dst
);


void
event_sf_to_moon(const sf::Event& src, moon_Event* dst) {
	if (src.type == sf::Event::EventType::Closed) {
		dst->type = moon_Event_Type_Closed;
	} else if (
		src.type == sf::Event::EventType::KeyPressed
		|| src.type == sf::Event::EventType::KeyReleased
	) {
		if (src.type == sf::Event::EventType::KeyPressed) {
			dst->type = moon_Event_Type_KeyPressed;
		} else {
			dst->type = moon_Event_Type_KeyReleased;
		}
		event_convert_key_evt(src.key, dst->evt.key);
	} else if (
		src.type == sf::Event::EventType::MouseButtonPressed
		|| src.type == sf::Event::EventType::MouseButtonReleased
	) {
		if (src.type == sf::Event::EventType::MouseButtonPressed) {
			dst->type = moon_Event_Type_MouseButtonPressed;
		} else {
			dst->type = moon_Event_Type_MouseButtonReleased;
		}
		event_convert_button_evt(src.mouseButton, dst->evt.mouse_button);
	} else if (src.type == sf::Event::EventType::MouseMoved) {
		dst->type = moon_Event_Type_MouseMoved;
		event_convert_move_evt(src.mouseMove, dst->evt.mouse_move);
	} else if (src.type == sf::Event::EventType::MouseWheelScrolled) {
		dst->type = moon_Event_Type_MouseWheelScrolled;
		event_convert_wheel_scrolled_evt(src.mouseWheelScroll, dst->evt.mouse_wheel_scroll);
	} else if (src.type == sf::Event::EventType::MouseWheelMoved) {
		dst->type = moon_Event_Type_MouseWheelMoved;
		event_convert_wheel_evt(src.mouseWheel, dst->evt.mouse_wheel);
	} else if (src.type == sf::Event::EventType::Resized) {
		dst->type = moon_Event_Type_Resized;
		event_convert_resized_evt(src.size, dst->evt.size);
	} else if (src.type == sf::Event::EventType::TextEntered) {
		dst->type = moon_Event_Type_TextEntered;
		event_convert_text_entered_evt(src.text, dst->evt.text);
	} else if (
		src.type == sf::Event::EventType::TouchBegan
		|| src.type == sf::Event::EventType::TouchMoved
		|| src.type == sf::Event::EventType::TouchEnded
	) {
		if (src.type == sf::Event::EventType::TouchBegan) {
			dst->type = moon_Event_Type_TouchBegan;
		} else if (src.type == sf::Event::EventType::TouchMoved) {
			dst->type = moon_Event_Type_TouchMoved;
		} else {
			dst->type = moon_Event_Type_TouchEnded;
		}
		event_convert_touch_evt(src.touch, dst->evt.touch);
	} else if (src.type == sf::Event::EventType::SensorChanged) {
		dst->type = moon_Event_Type_SensorChanged;
		event_convert_sensor_evt(src.sensor, dst->evt.sensor);
	} else {
		dst->type = static_cast<int>(src.type);
	}
}


void
event_convert_key_evt(
	const sf::Event::KeyEvent& src,
	moon_KeyEvent& dst
) {
	dst.keycode 	= static_cast<int>(src.code);
	dst.scancode 	= static_cast<int>(src.scancode);
	dst.alt 		= static_cast<int>(src.alt);
	dst.control 	= static_cast<int>(src.control);
	dst.shift 		= static_cast<int>(src.shift);
	dst.system 		= static_cast<int>(src.system);
}

void
event_convert_button_evt(
	const sf::Event::MouseButtonEvent& src,
	moon_MouseButtonEvent& dst
) {
	dst.button 	= static_cast<int>(src.button);
	dst.x 		= src.x;
	dst.y		= src.y;
}

void
event_convert_move_evt(
	const sf::Event::MouseMoveEvent& src,
	moon_MouseMoveEvent& dst
) {
	dst.x = src.x;
	dst.y = src.y;
}

void
event_convert_wheel_evt(
	const sf::Event::MouseWheelEvent& src,
	moon_MouseWheelEvent& dst
) {
	dst.delta 	= src.delta;
	dst.x 		= src.x;
	dst.y 		= src.y;
}

void
event_convert_wheel_scrolled_evt(
	const sf::Event::MouseWheelScrollEvent& src,
	moon_MouseWheelScrollEvent& dst
) {
	dst.wheel 	= static_cast<int>(src.wheel);
	dst.delta 	= src.delta;
	dst.x 		= src.x;
	dst.y 		= src.y;
}

void
event_convert_resized_evt(
	const sf::Event::SizeEvent& src,
	moon_SizeEvent& dst
) {
	dst.width 	= src.width;
	dst.height 	= src.height;
}

void
event_convert_text_entered_evt(
	const sf::Event::TextEvent& src,
	moon_TextEvent& dst
) {
	dst.unicode = static_cast<unsigned int>(src.unicode);
}

void
event_convert_touch_evt(
	const sf::Event::TouchEvent& src,
	moon_TouchEvent& dst
) {
	dst.finger 	= src.finger;
	dst.x 		= src.x;
	dst.y 		= src.y;
}

void
event_convert_sensor_evt(
	const sf::Event::SensorEvent& src,
	moon_SensorEvent& dst
) {
	dst.type 	= static_cast<int>(src.type);
	dst.x 		= src.x;
	dst.y 		= src.y;
	dst.z 		= src.z;
}
