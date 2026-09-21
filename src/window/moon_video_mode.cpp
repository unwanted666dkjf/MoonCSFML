#include <SFML/Window/VideoMode.hpp>



#include "../../headers/window/moon_video_mode.h"

#include "../../headers/window/Converters.hpp"


moon_VideoMode
moon_VideoMode_get_copy(const moon_VideoMode* self) {
	return {self->width, self->height, self->bits_per_pixel};
}

moon_VideoMode
moon_VideoMode_get_desktop_mode() {
	sf::VideoMode desktop_mode = sf::VideoMode::getDesktopMode();
	return video_mode_sf_to_moon(desktop_mode);
}

int
moon_VideoMode_is_valid(const moon_VideoMode* mode) {
	return video_mode_moon_to_sf(*mode).isValid();
}
