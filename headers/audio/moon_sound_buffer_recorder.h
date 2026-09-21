#ifndef MOON_CSFML_AUDIO_MOON_SOUND_BUFFER_RECORDER_H
#define MOON_CSFML_AUDIO_MOON_SOUND_BUFFER_RECORDER_H


#include "./moon_sound_buffer.h"


#ifdef __cplusplus
extern "C" {
#endif


#define moon_SoundBufferRecorder_DefaultSampleRate (44100)


struct MOON_CSFML_API moon_SoundBufferRecorder;


/**
 * Specialized SoundRecorder which stores the captured
 *audio data into a sound buffer.
 */
typedef struct moon_SoundBufferRecorder moon_SoundBufferRecorder;


/**
 * Creates new sound recorder.
 */
MOON_CSFML_API moon_SoundBufferRecorder*
moon_SoundBufferRecorder_create();

/**
 * Stops recording and destroys sound recorder.
 */
MOON_CSFML_API void
moon_SoundBufferRecorder_destroy(moon_SoundBufferRecorder* self);

/**
 * Returns the sound buffer containing the captured audio data.
 *
 * The sound buffer is valid only after the capture has ended.
 * This function provides a read-only access to the internal
 *sound buffer, but it can be copied if you need to
 *make any modification to it.
 */
MOON_CSFML_API const moon_SoundBuffer*
moon_SoundBufferRecorder_get_buffer(const moon_SoundBufferRecorder* self);


// SoundRecorder begin.

/**
 * Starts the capture.
 *
 * The \a sample_rate parameter defines the number of audio samples
 *captured per second. The higher, the better the quality
 *(for example, 44100 samples/sec is CD quality).
 * This function uses its own thread so that it doesn't block
 *the rest of the program while the capture runs.
 * Please note that only one capture can happen at the same time.
 * You can select which capture device will be used, by passing
 *the name to the setDevice() method. If none was selected
 *before, the default capture device will be used. You can get a
 *list of the names of all available capture devices by calling
 *getAvailableDevices().
 *
 * Returns 1 if start of capture was successful, 0 otherwise.
 */
MOON_CSFML_API int
moon_SoundBufferRecorder_start(
	moon_SoundBufferRecorder* self,
	unsigned int sample_rate
);

/**
 * Stops the capture.
 */
MOON_CSFML_API void
moon_SoundBufferRecorder_stop(moon_SoundBufferRecorder* self);

/**
 * Returns sample rate.
 *
 * The sample rate defines the number of audio samples
 *captured per second. The higher, the better the quality
 *(for example, 44100 samples/sec is CD quality).
 */
MOON_CSFML_API unsigned int
moon_SoundBufferRecorder_get_sample_rate(const moon_SoundBufferRecorder* self);

/**
 * Returns the name of the default audio capture device.
 * This function returns the name of the default audio
 *capture device. If none is available, an empty string
 *is returned.
 * String will be null-terminated.
 * Result must be freed after usage.
 */
MOON_CSFML_API char*
moon_SoundBufferRecorder_get_default_device();

/**
 * Sets the audio capture device.
 *
 * This function sets the audio capture device to the device
 *with the given \a device_name. It can be called on the fly (i.e:
 *while recording). If you do so while recording and
 *opening the device fails, it stops the recording.
 */
MOON_CSFML_API int
moon_SoundBufferRecorder_set_device(
	moon_SoundBufferRecorder* self,
	const char* device_name
);

/**
 * Returns the name of the current audio capture device.
 */
MOON_CSFML_API const char*
moon_SoundBufferRecorder_get_device(const moon_SoundBufferRecorder* self);

/**
 * Sets the channel count of the audio capture device.
 *
 * This method allows you to specify the number of channels
 *used for recording. Currently only 16-bit mono(1) and
 *16-bit stereo(2) are supported.
 */
MOON_CSFML_API void
moon_SoundBufferRecorder_set_channel_count(
	moon_SoundBufferRecorder* self,
	unsigned int channel_count
);

/**
 * Returns the number of channels used by this recorder.
 * Currently only mono and stereo are supported, so the
 *value is either 1 (for mono) or 2 (for stereo).
 */
MOON_CSFML_API unsigned int
moon_SoundBufferRecorder_get_channel_count(const moon_SoundBufferRecorder* self);

/**
 * Checks if the system supports audio capture.
 *
 * This function should always be called before using
 * the audio capture features. If it returns 0, then
 * any attempt to use SoundRecorder or one of its derived
 * classes will fail.
 * Returns 1 if audio capture is supported, 0 otherwise.
 */
MOON_CSFML_API int
moon_SoundBufferRecorder_is_available();

// SoundRecorder end.


#ifdef __cplusplus
}
#endif


#endif
