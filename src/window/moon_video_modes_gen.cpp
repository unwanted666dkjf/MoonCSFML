#include <SFML/Window/VideoMode.hpp>



#include "../../headers/window/moon_video_modes_gen.h"

#include "../../headers/window/Converters.hpp"


struct moon_VideoModesGen {

	mutable short in_use;
	mutable std::vector<sf::VideoMode> modes;

	moon_VideoModesGen();

};


moon_VideoModesGen*
moon_VideoModesGen_create() {
	return new moon_VideoModesGen();
}

void
moon_VideoModesGen_destroy(moon_VideoModesGen* self) {
	delete self;
}

int
moon_VideoModesGen_has_next(const moon_VideoModesGen* self) {
	if (!self->in_use) {
		self->modes = sf::VideoMode::getFullscreenModes();
		self->in_use = 1;
	}
	return !self->modes.empty();
}

moon_VideoMode
moon_VideoModesGen_next(moon_VideoModesGen* self) {
	const sf::VideoMode* nxt = &self->modes.back();
	moon_VideoMode res = video_mode_sf_to_moon(*nxt);
	self->modes.pop_back();
	return res;
}


moon_VideoModesGen::moon_VideoModesGen() {
	in_use = 0;
}
