#ifndef MOON_CSFML_AUDIO_MOON_SOUND_SOURCE_STATUS_H
#define MOON_CSFML_AUDIO_MOON_SOUND_SOURCE_STATUS_H


#ifdef __cplusplus
extern "C" {
#endif


enum
{
	moon_SoundSource_Status_Stopped, //!< Sound is not playing
	moon_SoundSource_Status_Paused,  //!< Sound is paused
	moon_SoundSource_Status_Playing  //!< Sound is playing
};


#ifdef __cplusplus
}
#endif


#endif
