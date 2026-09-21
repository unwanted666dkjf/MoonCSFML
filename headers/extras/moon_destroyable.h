#ifndef MOON_CSFML_EXTRAS_MOON_DESTROYABLE_H
#define MOON_CSFML_EXTRAS_MOON_DESTROYABLE_H


#include "../import_macro.h"


#ifdef __cplusplus
extern "C" {
#endif


enum {

	// System

	moon_Destroyable_CharPtr,
	moon_Destroyable_WCharPtr,
	moon_Destroyable_Clock,

	// Window

	moon_Destroyable_Event,
	moon_Destroyable_VideoModesGen,

	// Graphics

	moon_Destroyable_Font,
	moon_Destroyable_Text,
	moon_Destroyable_Image,
	moon_Destroyable_Shader,
	moon_Destroyable_Sprite,
	moon_Destroyable_Texture,
	moon_Destroyable_ConvexShape,
	moon_Destroyable_CircleShape,
	moon_Destroyable_RectangleShape,
	moon_Destroyable_VertexArray,
	moon_Destroyable_VertexBuffer,
	moon_Destroyable_RenderStates,
	moon_Destroyable_RenderWindow,

	// Audio

	moon_Destroyable_Music,
	moon_Destroyable_Sound,
	moon_Destroyable_SoundBuffer,
	moon_Destroyable_SoundBufferRecorder,
	moon_Destroyable_AudioCaptureDevices,

	//Extras

	moon_Destroyable_Destroyer,			// lol
	moon_Destroyable_Pathgen,
	moon_Destroyable_File,
	moon_Destroyable_Filelines,
	moon_Destroyable_TextWrite,
	moon_Destroyable_DrawGroup,
	moon_Destroyable_guiFpsCntr,
	moon_Destroyable_SlideAnimation
};


/**
 * Structure for storing destroyable objects.
 * Only for internal usage.
 */
typedef struct MOON_CSFML_API moon_Destroyable {
	int type;
	void* body;
} moon_Destroyable;


/**
 * Returns 1 if type can be destroyed by Destroyer.
 * Otherwise, returns 0.
 */
MOON_CSFML_API int
moon_Destroyable_is_type_destroyable(int type);


#ifdef __cplusplus
}
#endif


#endif
