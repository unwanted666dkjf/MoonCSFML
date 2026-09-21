#ifndef MOON_CSFML_AUDIO_SOUND_STRUCT_HPP
#define MOON_CSFML_AUDIO_SOUND_STRUCT_HPP


#include <SFML/Audio/Sound.hpp>


struct moon_Sound : public sf::Sound {

	moon_Sound();

	moon_Sound(const moon_Sound* other);

};


#endif
