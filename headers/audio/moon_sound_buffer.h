#ifndef MOON_CSFML_AUDIO_MOON_SOUND_BUFFER_H
#define MOON_CSFML_AUDIO_MOON_SOUND_BUFFER_H


#include "../system/moon_time.h"


#ifdef __cplusplus
extern "C" {
#endif


#define moon_SoundBuffer_SampleRateCD (44100)


struct MOON_CSFML_API moon_SoundBuffer;


/**
 * Storage for audio samples defining a sound.
 */
typedef struct moon_SoundBuffer moon_SoundBuffer;


/**
 * Creates empty buffer.
 */
MOON_CSFML_API moon_SoundBuffer*
moon_SoundBuffer_create();

/**
 * Destroys sound buffer.
 */
MOON_CSFML_API void
moon_SoundBuffer_destroy(moon_SoundBuffer* self);

/**
 * Creates a copy of this sound buffer.
 */
MOON_CSFML_API moon_SoundBuffer*
moon_SoundBuffer_get_copy(const moon_SoundBuffer* self);

/**
 * Loads the sound buffer from a file.
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
moon_SoundBuffer_load_from_file(
	moon_SoundBuffer* self,
	const char* filepath
);

/**
 * Loads the sound buffer from an array of audio samples.
 * The assumed format of the audio samples is 16 bits signed integer.
 *
 * Returns 1 if loading succeeded, 0 if it failed.
 */
MOON_CSFML_API int
moon_SoundBuffer_load_from_samples(
	moon_SoundBuffer* self,
	const short* samples,
	unsigned long sample_count,
	unsigned int channel_count,
	unsigned int sample_rate
);

/**
 * Saves the sound buffer to an audio file.
 * The supported audio formats are: WAV (PCM only), OGG/Vorbis, FLAC, MP3.
 * The supported sample sizes for FLAC and WAV are 8, 16, 24 and 32 bit.
 *
 * Because of minimp3_ex limitation, for MP3 files with big (>16kb) APEv2 tag,
 *it may not be properly removed, tag data will be treated as MP3 data
 *and there is a low chance of garbage decoded at the end of file.
 * Returns 1 if saving succeeded, 0 if it failed.
 */
MOON_CSFML_API int
moon_SoundBuffer_save(
	const moon_SoundBuffer* self,
	const char* filepath
);

/**
 * Returns the array of audio samples stored in the buffer.
 * The format of the returned samples is 16 bits signed integer.
 */
MOON_CSFML_API const short*
moon_SoundBuffer_get_samples(const moon_SoundBuffer* self);

/**
 * Returns the number of samples stored in the buffer.
 */
MOON_CSFML_API unsigned long
moon_SoundBuffer_get_sample_count(const moon_SoundBuffer* self);

/**
 * Returns the sample rate of the sound.
 * The sample rate is the number of samples played per second.
 * The higher, the better the quality (for example, 44100
 *samples/s is CD quality).
 */
MOON_CSFML_API unsigned int
moon_SoundBuffer_get_sample_rate(const moon_SoundBuffer* self);

/**
 * Returns the number of channels used by the sound.
 *
 * If the sound is mono then the number of channels will
 *be 1, 2 for stereo, etc.
 */
MOON_CSFML_API unsigned int
moon_SoundBuffer_get_channel_count(const moon_SoundBuffer* self);

/**
 * Returns the total duration of the sound.
 */
MOON_CSFML_API moon_Time
moon_SoundBuffer_get_duration(const moon_SoundBuffer* self);


#ifdef __cplusplus
}
#endif


#endif
