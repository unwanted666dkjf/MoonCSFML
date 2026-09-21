#ifndef MOON_CSFML_AUDIO_SOUND_BUFFER_STRUCT_HPP
#define MOON_CSFML_AUDIO_SOUND_BUFFER_STRUCT_HPP


#include <SFML/Audio/SoundBuffer.hpp>


struct moon_SoundBuffer : public sf::SoundBuffer {

	moon_SoundBuffer();

	moon_SoundBuffer(const moon_SoundBuffer* other);

};


#endif
