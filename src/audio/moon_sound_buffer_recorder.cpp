#include "../../headers/system/moon_strutils.h"


#include "../../headers/audio/moon_sound_buffer_recorder.h"

#include "../../headers/audio/SoundBufferStruct.hpp"

#include "../../headers/audio/SoundBufferRecorderStruct.hpp"


moon_SoundBufferRecorder*
moon_SoundBufferRecorder_create() {
	return new moon_SoundBufferRecorder();
}

void
moon_SoundBufferRecorder_destroy(moon_SoundBufferRecorder* self) {
	self->stop();
	delete self;
}

const moon_SoundBuffer*
moon_SoundBufferRecorder_get_buffer(const moon_SoundBufferRecorder* self) {
	return static_cast<const moon_SoundBuffer*>(
		&self->getBuffer()
	);
}


// SoundRecorder begin.

int
moon_SoundBufferRecorder_start(
	moon_SoundBufferRecorder* self,
	unsigned int sample_rate
) {
	return self->start(sample_rate);
}

void
moon_SoundBufferRecorder_stop(moon_SoundBufferRecorder* self) {
	self->stop();
}

unsigned int
moon_SoundBufferRecorder_get_sample_rate(const moon_SoundBufferRecorder* self) {
	return self->getSampleRate();
}

char*
moon_SoundBufferRecorder_get_default_device() {
	std::string tmp = sf::SoundBufferRecorder::getDefaultDevice();
	return moon_strcopyA(tmp.c_str(), tmp.size());
}

int
moon_SoundBufferRecorder_set_device(
	moon_SoundBufferRecorder* self,
	const char* device_name
) {
	return self->setDevice(std::string(device_name));
}

const char*
moon_SoundBufferRecorder_get_device(const moon_SoundBufferRecorder* self) {
	return self->getDevice().c_str();
}

void
moon_SoundBufferRecorder_set_channel_count(
	moon_SoundBufferRecorder* self,
	unsigned int channel_count
) {
	self->setChannelCount(channel_count);
}

unsigned int
moon_SoundBufferRecorder_get_channel_count(const moon_SoundBufferRecorder* self) {
	return self->getChannelCount();
}

int
moon_SoundBufferRecorder_is_available() {
	return sf::SoundBufferRecorder::isAvailable();
}

// SoundRecorder end.


moon_SoundBufferRecorder::moon_SoundBufferRecorder(

) : sf::SoundBufferRecorder() {
	//
}
