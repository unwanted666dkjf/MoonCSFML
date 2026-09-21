#include "../../headers/system/Converters.hpp"


#include "../../headers/audio/moon_music.h"

#include "../../headers/audio/MusicStruct.hpp"


moon_Music*
moon_Music_create() {
	return new moon_Music();
}

void
moon_Music_destroy(moon_Music* self) {
	self->stop();
	delete self;
}

int
moon_Music_open(
	moon_Music* self,
	const char* filepath
) {
	return self->openFromFile(std::string(filepath));
}

moon_Time
moon_Music_get_duration(const moon_Music* self) {
	return time_sf_to_moon(self->getDuration());
}


// SoundStream begin.

unsigned int
moon_Music_get_channel_count(const moon_Music* self) {
	return self->getChannelCount();
}

unsigned int
moon_Music_get_sample_rate(const moon_Music* self) {
	return self->getSampleRate();
}

void
moon_Music_set_playing_offset(
	moon_Music* self,
	moon_Time offset
) {
	self->setPlayingOffset(time_moon_to_sf(offset));
}

moon_Time
moon_Music_get_playing_offset(const moon_Music* self) {
	return time_sf_to_moon(self->getPlayingOffset());
}

void
moon_Music_set_loop(
	moon_Music* self,
	int is_loop
) {
	self->setLoop(is_loop);
}

int
moon_Music_is_loop(const moon_Music* self) {
	return self->getLoop();
}

// SoundStream end.


// SoundSource begin.

void
moon_Music_set_pitch(
	moon_Music* self,
	float pitch
) {
	self->setPitch(pitch);
}

void
moon_Music_set_volume(
	moon_Music* self,
	float volume
) {
	self->setVolume(volume);
}

void
moon_Music_set_position(
	moon_Music* self,
	float x, float y, float z
) {
	self->setPosition(x, y, z);
}

void
moon_Music_set_relative_to_listener(
	moon_Music* self,
	int is_relative
) {
	self->setRelativeToListener(is_relative);
}

void
moon_Music_set_min_distance(
	moon_Music* self,
	float distance
) {
	self->setMinDistance(distance);
}

void
moon_Music_set_attenuation(
	moon_Music* self,
	float attenuation
) {
	self->setAttenuation(attenuation);
}

float
moon_Music_get_pitch(const moon_Music* self) {
	return self->getPitch();
}

float
moon_Music_get_volume(const moon_Music* self) {
	return self->getVolume();
}

moon_Vector3f
moon_Music_get_position(const moon_Music* self) {
	sf::Vector3f pos = self->getPosition();
	return {pos.x, pos.y, pos.z};
}

int
moon_Music_is_relative_to_listener(const moon_Music* self) {
	return self->isRelativeToListener();
}

float
moon_Music_get_min_distance(const moon_Music* self) {
	return self->getMinDistance();
}

float
moon_Music_get_attenuation(const moon_Music* self) {
	return self->getAttenuation();
}

void
moon_Music_play(moon_Music* self) {
	self->play();
}

void
moon_Music_pause(moon_Music* self) {
	self->pause();
}

void
moon_Music_stop(moon_Music* self) {
	self->stop();
}

int
moon_Music_get_status(const moon_Music* self) {
	return static_cast<int>(self->getStatus());
}

// SoundSource end.


moon_Music::moon_Music() : sf::Music() {
	//
}
