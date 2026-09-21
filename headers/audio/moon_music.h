#ifndef MOON_CSFML_AUDIO_MOON_MUSIC_H
#define MOON_CSFML_AUDIO_MOON_MUSIC_H


#include "../system/moon_vector3.h"


#ifdef __cplusplus
extern "C" {
#endif


struct MOON_CSFML_API moon_Music;


/**
 * Streamed music played from an audio file.
 */
typedef struct moon_Music moon_Music;


/**
 * Creates empty music object.
 */
MOON_CSFML_API moon_Music*
moon_Music_create();

/**
 * Stops music and destroys object.
 */
MOON_CSFML_API void
moon_Music_destroy(moon_Music* self);

/**
 * Opens a music from an audio file.
 *
 * This function doesn't start playing the music (call play()
 *to do so).
 *
 * The supported audio formats are: WAV (PCM only), OGG/Vorbis, FLAC, MP3.
 * The supported sample sizes for FLAC and WAV are 8, 16, 24 and 32 bit.
 *
 * Because of minimp3_ex limitation, for MP3 files with big (>16kb) APEv2 tag,
 *it may not be properly removed, tag data will be treated as MP3 data
 *and there is a low chance of garbage decoded at the end of file.
 *
 * Returns 1 if loading succeeded, 0 if it failed.
 */
MOON_CSFML_API int
moon_Music_open(
	moon_Music* self,
	const char* filepath
);

/**
 * Returns the total duration of the music.
 */
MOON_CSFML_API moon_Time
moon_Music_get_duration(const moon_Music* self);


// SoundStream begin.

/**
 * Returns the number of channels of the stream.
 * 1 channel means a mono sound, 2 means stereo, etc.
 */
MOON_CSFML_API unsigned int
moon_Music_get_channel_count(const moon_Music* self);

/**
 * Returns the stream sample rate of the stream.
 *
 * The sample rate is the number of audio samples played per
 *second. The higher, the better the quality.
 */
MOON_CSFML_API unsigned int
moon_Music_get_sample_rate(const moon_Music* self);

/**
 * Changes the current playing position of the stream.
 *
 * The playing position can be changed when the stream is
 *either paused or playing. Changing the playing position
 *when the stream is stopped has no effect, since playing
 *the stream would reset its position.
 */
MOON_CSFML_API void
moon_Music_set_playing_offset(
	moon_Music* self,
	moon_Time offset
);

/**
 * Returns current playing position, from the beginning of the stream.
 */
MOON_CSFML_API moon_Time
moon_Music_get_playing_offset(const moon_Music* self);

/**
 * Sets whether or not the stream should loop after reaching the end.
 *
 * If set, the stream will restart from beginning after
 *reaching the end and so on, until it is stopped or
 *set_loop(0) is called.
 * Pass 1 to play in loop, 0 to play once.
 * The default looping state for streams is 0.
 */
MOON_CSFML_API void
moon_Music_set_loop(
	moon_Music* self,
	int is_loop
);

/**
 * Returns 1 if the stream is looping, 0 otherwise.
 */
MOON_CSFML_API int
moon_Music_is_loop(const moon_Music* self);

// SoundStream end.


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
moon_Music_set_pitch(
	moon_Music* self,
	float pitch
);

/**
 * Set the volume of the sound.
 *
 * The volume is a value between 0 (mute) and 100 (full volume).
 * The default value for the volume is 100.
 */
MOON_CSFML_API void
moon_Music_set_volume(
	moon_Music* self,
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
moon_Music_set_position(
	moon_Music* self,
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
moon_Music_set_relative_to_listener(
	moon_Music* self,
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
moon_Music_set_min_distance(
	moon_Music* self,
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
moon_Music_set_attenuation(
	moon_Music* self,
	float attenuation
);

/**
 * Returns the pitch of the sound.
 */
MOON_CSFML_API float
moon_Music_get_pitch(const moon_Music* self);

/**
 * Returns the volume of the sound, in the range [0, 100].
 */
MOON_CSFML_API float
moon_Music_get_volume(const moon_Music* self);

/**
 * Returns the 3D position of the sound in the audio scene.
 */
MOON_CSFML_API moon_Vector3f
moon_Music_get_position(const moon_Music* self);

/**
 * Tells whether the sound's position is relative to the
 *listener or is absolute.
 * Returns 1 if the position is relative, 0 if it's absolute.
 */
MOON_CSFML_API int
moon_Music_is_relative_to_listener(const moon_Music* self);

/**
 * Returns the minimum distance of the sound.
 */
MOON_CSFML_API float
moon_Music_get_min_distance(const moon_Music* self);

/**
 * Returns the attenuation factor of the sound.
 */
MOON_CSFML_API float
moon_Music_get_attenuation(const moon_Music* self);

/**
 * Start or resume playing the sound source.
 *
 * This function starts the source if it was stopped, resumes
 *it if it was paused, and restarts it from the beginning if
 *it was already playing.
 */
MOON_CSFML_API void
moon_Music_play(moon_Music* self);

/**
 * Pause the sound source.
 *
 * This function pauses the source if it was playing,
 *otherwise (source already paused or stopped) it has no effect.
 */
MOON_CSFML_API void
moon_Music_pause(moon_Music* self);

/**
 * Stop playing the sound source.
 *
 * This function stops the source if it was playing or paused,
 *and does nothing if it was already stopped.
 * It also resets the playing position (unlike pause()).
 */
MOON_CSFML_API void
moon_Music_stop(moon_Music* self);

/**
 * Returns the current status of the sound (stopped, paused, playing).
 */
MOON_CSFML_API int
moon_Music_get_status(const moon_Music* self);

// SoundSource end.


#ifdef __cplusplus
}
#endif


#endif
