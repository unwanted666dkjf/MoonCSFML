#include "../../headers/system/Converters.hpp"


#include "../../headers/audio/moon_sound_buffer.h"

#include "../../headers/audio/SoundBufferStruct.hpp"


moon_SoundBuffer*
moon_SoundBuffer_create() {
	return new moon_SoundBuffer();
}

void
moon_SoundBuffer_destroy(moon_SoundBuffer* self) {
	delete self;
}

moon_SoundBuffer*
moon_SoundBuffer_get_copy(const moon_SoundBuffer* self) {
	return new moon_SoundBuffer(self);
}

int
moon_SoundBuffer_load_from_file(
	moon_SoundBuffer* self,
	const char* filepath
) {
	return self->loadFromFile(std::string(filepath));
}

int
moon_SoundBuffer_load_from_samples(
	moon_SoundBuffer* self,
	const short* samples,
	unsigned long sample_count,
	unsigned int channel_count,
	unsigned int sample_rate
) {
	return self->loadFromSamples(
		samples,
		sample_count,
		channel_count,
		sample_rate
	);
}

int
moon_SoundBuffer_save(
	const moon_SoundBuffer* self,
	const char* filepath
) {
	return self->saveToFile(std::string(filepath));
}

const short*
moon_SoundBuffer_get_samples(const moon_SoundBuffer* self) {
	return self->getSamples();
}

unsigned long
moon_SoundBuffer_get_sample_count(const moon_SoundBuffer* self) {
	return self->getSampleCount();
}

unsigned int
moon_SoundBuffer_get_sample_rate(const moon_SoundBuffer* self) {
	return self->getSampleRate();
}

unsigned int
moon_SoundBuffer_get_channel_count(const moon_SoundBuffer* self) {
	return self->getChannelCount();
}

moon_Time
moon_SoundBuffer_get_duration(const moon_SoundBuffer* self) {
	return time_sf_to_moon(self->getDuration());
}


moon_SoundBuffer::moon_SoundBuffer() : sf::SoundBuffer() {
	//
}

moon_SoundBuffer::moon_SoundBuffer(
	const moon_SoundBuffer* other
) : sf::SoundBuffer(*other) {
	//
}
