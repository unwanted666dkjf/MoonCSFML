#ifndef MOON_CSFML_AUDIO_MOON_AUDIO_CAPTURE_DEVICES_H
#define MOON_CSFML_AUDIO_MOON_AUDIO_CAPTURE_DEVICES_H


#include "../import_macro.h"


#ifdef __cplusplus
extern "C" {
#endif


struct MOON_CSFML_API moon_AudioCaptureDevices;


/**
 * Simply wrapper of sf::SoundRecorder::getAvailableDevices.
 * I could've write my own implementation using wasapi(Windows)
 *or pulseaudio(Linux), but I am a little bit tired.
 * Please don't use this at runtime, unless you want to slowdown
 *your app.
 * Generates names of all available audio capture devices.
 */
typedef struct moon_AudioCaptureDevices moon_AudioCaptureDevices;


/**
 * Creates new generator.
 */
MOON_CSFML_API moon_AudioCaptureDevices*
moon_AudioCaptureDevices_create();

/**
 * Destroys generator.
 */
MOON_CSFML_API void
moon_AudioCaptureDevices_destroy(moon_AudioCaptureDevices* self);

/**
 * Returns name of the next device.
 * Result will be null-terminated.
 * Result must be freed after usage.
 */
MOON_CSFML_API char*
moon_AudioCaptureDevices_next(moon_AudioCaptureDevices* self);

/**
 * Returns 1 if next device exists, 0 otherwise.
 */
MOON_CSFML_API int
moon_AudioCaptureDevices_has_next(const moon_AudioCaptureDevices* self);


#ifdef __cplusplus
}
#endif


#endif
