#include "../../headers/window/Converters.hpp"


moon_VideoMode
video_mode_sf_to_moon(const sf::VideoMode& mode) {
	return {
		mode.width,
		mode.height,
		mode.bitsPerPixel
	};
}

sf::VideoMode
video_mode_moon_to_sf(const moon_VideoMode& mode) {
	return sf::VideoMode(
		mode.width,
		mode.height,
		mode.bits_per_pixel
	);
}


moon_ContextSettings
context_settings_sf_to_moon(const sf::ContextSettings& settings) {
	return {
		settings.depthBits,
		settings.stencilBits,
		settings.antialiasingLevel,
		settings.majorVersion,
		settings.minorVersion,
		settings.attributeFlags,
		settings.sRgbCapable
	};
}

sf::ContextSettings
context_settings_moon_to_sf(const moon_ContextSettings& settings) {
	return sf::ContextSettings(
		settings.depth_bits,
		settings.stencil_bits,
		settings.antialiasing_level,
		settings.major_version,
		settings.minor_version,
		settings.attribute_flags,
		settings.srgb_capable
	);
}
