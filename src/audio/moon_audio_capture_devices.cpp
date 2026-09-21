#include <SFML/Audio/SoundRecorder.hpp>



#include "../../headers/system/moon_strutils.h"


#include "../../headers/audio/moon_audio_capture_devices.h"


struct moon_AudioCaptureDevices {

	moon_AudioCaptureDevices();

	mutable short 						in_use;
	mutable std::vector<std::string> 	devices;
};


moon_AudioCaptureDevices*
moon_AudioCaptureDevices_create() {
	return new moon_AudioCaptureDevices();
}

void
moon_AudioCaptureDevices_destroy(moon_AudioCaptureDevices* self) {
	delete self;
}

char*
moon_AudioCaptureDevices_next(moon_AudioCaptureDevices* self) {
	std::string* device = &self->devices.back();
	char* name = moon_strcopyA(
		device->c_str(),
		device->size()
	);
	self->devices.pop_back();
	return name;
}

int
moon_AudioCaptureDevices_has_next(const moon_AudioCaptureDevices* self) {
	if (!self->in_use) {
		self->in_use = 1;
		self->devices = sf::SoundRecorder::getAvailableDevices();
	}
	return !self->devices.empty();
}


moon_AudioCaptureDevices::moon_AudioCaptureDevices() {
	in_use 	= 0;
}
