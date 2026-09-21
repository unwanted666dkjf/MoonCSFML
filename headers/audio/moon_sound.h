#ifndef MOON_CSFML_AUDIO_MOON_SOUND_H
#define MOON_CSFML_AUDIO_MOON_SOUND_H


#include "./moon_sound_buffer.h"


#include "../system/moon_vector3.h"


#ifdef __cplusplus
extern "C" {
#endif


struct MOON_CSFML_API moon_Sound;


/**
 * Regular sound that can be played in the audio environment.
 */
typedef struct moon_Sound moon_Sound;


/**
 * Creates empty sound object.
 */
MOON_CSFML_API moon_Sound*
moon_Sound_create();

/**
 * Stops sound and destroys object.
 */
MOON_CSFML_API void
moon_Sound_destroy(moon_Sound* self);

/**
 * Creates a xopy of this sound.
 */
MOON_CSFML_API moon_Sound*
moon_Sound_get_copy(const moon_Sound* self);

/**
 * Sets the source buffer containing the audio data to play.
 *
 * It is important to note that the sound buffer is not copied,
 *thus the SoundBuffer instance must remain alive as long
 *as it is attached to the sound.
 */
MOON_CSFML_API void
moon_Sound_set_buffer(
	moon_Sound* self,
	const moon_SoundBuffer* buffer
);

/**
 * Sets whether or not the sound should loop after reaching the end.
 * If set, the sound will restart from beginning after
 *reaching the end and so on, until it is stopped or
 *set_loop(0) is called.
 * The default looping state for sound is 0.
 * Pass 1 to play in loop, 0 to play once.
 */
MOON_CSFML_API void
moon_Sound_set_loop(
	moon_Sound* self,
	int is_loop
);

/**
 * Changes the current playing position of the sound.
 *
 * The playing position can be changed when the sound is
 *either paused or playing. Changing the playing position
 *when the sound is stopped has no effect, since playing
 *the sound will reset its position.
 */
MOON_CSFML_API void
moon_Sound_set_playing_offset(
	moon_Sound* self,
	moon_Time offset
);

/**
 * Returns sound buffer attached to the sound (can be NULL).
 */
MOON_CSFML_API const moon_SoundBuffer*
moon_Sound_get_buffer(const moon_Sound* self);

/**
 * Returns 1 if the sound is looping, 0 otherwise.
 */
MOON_CSFML_API int
moon_Sound_is_loop(const moon_Sound* self);

/**
 * Returns the current playing position of the sound.
 */
MOON_CSFML_API moon_Time
moon_Sound_get_playing_offset(const moon_Sound* self);

/**
 * Resets the internal buffer of the sound.
 * This function is for internal use only, you don't have
 *to use it. It is called by the SoundBuffer that
 *this sound uses, when it is destroyed in order to prevent
 *the sound from using a dead buffer.
 */
MOON_CSFML_API void
moon_Sound_reset_buffer(moon_Sound* self);


// SoundSource begin.

/**
 * Sets the pitch of the sound.
 *
 * The pitch represents the perceived fundamental frequency
 *of a sound; thus you can make a sound more acute or grave
 *by changing its pitch. A side effect of changing the pitch
 *is to modify the playing speed of the sound as well.
 * The default value for the pitch is 1.
 */
MOON_CSFML_API void
moon_Sound_set_pitch(
	moon_Sound* self,
	float pitch
);

/**
 * Set the volume of the sound.
 *
 * The volume is a value between 0 (mute) and 100 (full volume).
 * The default value for the volume is 100.
 */
MOON_CSFML_API void
moon_Sound_set_volume(
	moon_Sound* self,
	float volume
);

/**
 * Sets the 3D position of the sound in the audio scene.
 *
 * Only sounds with one channel (mono sounds) can be
 *spatialized.
 * The default position of a sound is (0, 0, 0).
 */
MOON_CSFML_API void
moon_Sound_set_position(
	moon_Sound* self,
	float x, float y, float z
);

/**
 * Makes the sound's position relative to the listener or absolute.
 *
 * Making a sound relative to the listener will ensure that it will always
 *be played the same way regardless of the position of the listener.
 * This can be useful for non-spatialized sounds, sounds that are
 *produced by the listener, or sounds attached to it.
 * The default value is false (position is absolute).
 *
 * Pass 1 to set the position relative, 0 to set it absolute.
 */
MOON_CSFML_API void
moon_Sound_set_relative_to_listener(
	moon_Sound* self,
	int is_relative
);

/**
 * Set the minimum distance of the sound.
 *
 * The "minimum distance" of a sound is the maximum
 *distance at which it is heard at its maximum volume. Further
 *than the minimum distance, it will start to fade out according
 *to its attenuation factor. A value of 0 ("inside the head
 *of the listener") is an invalid value and is forbidden.
 * The default value of the minimum distance is 1.
 */
MOON_CSFML_API void
moon_Sound_set_min_distance(
	moon_Sound* self,
	float distance
);

/**
 * Set the attenuation factor of the sound.
 *
 * The attenuation is a multiplicative factor which makes
 *the sound more or less loud according to its distance
 *from the listener. An attenuation of 0 will produce a
 *non-attenuated sound, i.e. its volume will always be the same
 *whether it is heard from near or from far. On the other hand,
 *an attenuation value such as 100 will make the sound fade out
 *very quickly as it gets further from the listener.
 * The default value of the attenuation is 1.
 */
MOON_CSFML_API void
moon_Sound_set_attenuation(
	moon_Sound* self,
	float attenuation
);

/**
 * Returns the pitch of the sound.
 */
MOON_CSFML_API float
moon_Sound_get_pitch(const moon_Sound* self);

/**
 * Returns the volume of the sound, in the range [0, 100].
 */
MOON_CSFML_API float
moon_Sound_get_volume(const moon_Sound* self);

/**
 * Returns the 3D position of the sound in the audio scene.
 */
MOON_CSFML_API moon_Vector3f
moon_Sound_get_position(const moon_Sound* self);

/**
 * Tells whether the sound's position is relative to the
 *listener or is absolute.
 * Returns 1 if the position is relative, 0 if it's absolute.
 */
MOON_CSFML_API int
moon_Sound_is_relative_to_listener(const moon_Sound* self);

/**
 * Returns the minimum distance of the sound.
 */
MOON_CSFML_API float
moon_Sound_get_min_distance(const moon_Sound* self);

/**
 * Returns the attenuation factor of the sound.
 */
MOON_CSFML_API float
moon_Sound_get_attenuation(const moon_Sound* self);

/**
 * Start or resume playing the sound source.
 *
 * This function starts the source if it was stopped, resumes
 *it if it was paused, and restarts it from the beginning if
 *it was already playing.
 */
MOON_CSFML_API void
moon_Sound_play(moon_Sound* self);

/**
 * Pause the sound source.
 *
 * This function pauses the source if it was playing,
 *otherwise (source already paused or stopped) it has no effect.
 */
MOON_CSFML_API void
moon_Sound_pause(moon_Sound* self);

/**
 * Stop playing the sound source.
 *
 * This function stops the source if it was playing or paused,
 *and does nothing if it was already stopped.
 * It also resets the playing position (unlike pause()).
 */
MOON_CSFML_API void
moon_Sound_stop(moon_Sound* self);

/**
 * Returns the current status of the sound (stopped, paused, playing).
 */
MOON_CSFML_API int
moon_Sound_get_status(const moon_Sound* self);

// SoundSource end.


#ifdef __cplusplus
}
#endif


#endif
