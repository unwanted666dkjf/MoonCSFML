#include "../../headers/system/Converters.hpp"


#include "../../headers/audio/moon_sound.h"

#include "../../headers/audio/SoundStruct.hpp"

#include "../../headers/audio/SoundBufferStruct.hpp"


moon_Sound*
moon_Sound_create() {
	return new moon_Sound();
}

void
moon_Sound_destroy(moon_Sound* self) {
	self->stop();
	delete self;
}

moon_Sound*
moon_Sound_get_copy(const moon_Sound* self) {
	return new moon_Sound(self);
}

void
moon_Sound_set_buffer(
	moon_Sound* self,
	const moon_SoundBuffer* buffer
) {
	self->setBuffer(*buffer);
}

void
moon_Sound_set_loop(
	moon_Sound* self,
	int is_loop
) {
	self->setLoop(is_loop);
}

void
moon_Sound_set_playing_offset(
	moon_Sound* self,
	moon_Time offset
) {
	self->setPlayingOffset(time_moon_to_sf(offset));
}

const moon_SoundBuffer*
moon_Sound_get_buffer(const moon_Sound* self) {
	return static_cast<const moon_SoundBuffer*>(
		self->getBuffer()
	);
}

int
moon_Sound_is_loop(const moon_Sound* self) {
	return self->getLoop();
}

moon_Time
moon_Sound_get_playing_offset(const moon_Sound* self) {
	return time_sf_to_moon(
		self->getPlayingOffset()
	);
}

void
moon_Sound_reset_buffer(moon_Sound* self) {
	self->resetBuffer();
}


// SoundSource begin.

void
moon_Sound_set_pitch(
	moon_Sound* self,
	float pitch
) {
	self->setPitch(pitch);
}

void
moon_Sound_set_volume(
	moon_Sound* self,
	float volume
) {
	self->setVolume(volume);
}

void
moon_Sound_set_position(
	moon_Sound* self,
	float x, float y, float z
) {
	self->setPosition(x, y, z);
}

void
moon_Sound_set_relative_to_listener(
	moon_Sound* self,
	int is_relative
) {
	self->setRelativeToListener(is_relative);
}

void
moon_Sound_set_min_distance(
	moon_Sound* self,
	float distance
) {
	self->setMinDistance(distance);
}

void
moon_Sound_set_attenuation(
	moon_Sound* self,
	float attenuation
) {
	self->setAttenuation(attenuation);
}

float
moon_Sound_get_pitch(const moon_Sound* self) {
	return self->getPitch();
}

float
moon_Sound_get_volume(const moon_Sound* self) {
	return self->getVolume();
}

moon_Vector3f
moon_Sound_get_position(const moon_Sound* self) {
	sf::Vector3f pos = self->getPosition();
	return {pos.x, pos.y, pos.z};
}

int
moon_Sound_is_relative_to_listener(const moon_Sound* self) {
	return self->isRelativeToListener();
}

float
moon_Sound_get_min_distance(const moon_Sound* self) {
	return self->getMinDistance();
}

float
moon_Sound_get_attenuation(const moon_Sound* self) {
	return self->getAttenuation();
}

void
moon_Sound_play(moon_Sound* self) {
	self->play();
}

void
moon_Sound_pause(moon_Sound* self) {
	self->pause();
}

void
moon_Sound_stop(moon_Sound* self) {
	self->stop();
}

int
moon_Sound_get_status(const moon_Sound* self) {
	return static_cast<int>(self->getStatus());
}

// SoundSource end.


moon_Sound::moon_Sound() : sf::Sound() {
	//
}

moon_Sound::moon_Sound(const moon_Sound* other) : sf::Sound(*other) {
	//
}
