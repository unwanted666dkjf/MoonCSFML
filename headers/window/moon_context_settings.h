#ifndef MOON_CSFML_WINDOW_MOON_CONTEXT_SETTINGS_H
#define MOON_CSFML_WINDOW_MOON_CONTEXT_SETTINGS_H


#include "../import_macro.h"


#ifdef __cplusplus
extern "C" {
#endif


enum
{
	moon_ContextSettings_Attribute_Default = 0,      //!< Non-debug, compatibility context (this and the core attribute are mutually exclusive)
	moon_ContextSettings_Attribute_Core    = 1 << 0, //!< Core attribute
	moon_ContextSettings_Attribute_Debug   = 1 << 2  //!< Debug attribute
};


/**
 * Structure defining the settings of the OpenGL
 *context attached to a window.
 */
typedef struct MOON_CSFML_API moon_ContextSettings {
	unsigned int depth_bits;			// Bits of the depth buffer
	unsigned int stencil_bits;			// Bits of the stencil buffer
	unsigned int antialiasing_level;	// Level of antialiasing
	unsigned int major_version;			// Major number of the context version to create
	unsigned int minor_version;			// Minor number of the context version to create
	unsigned int attribute_flags;		// The attribute flags to create the context with
	int srgb_capable;					// Whether the context framebuffer is sRGB capable
} moon_ContextSettings;


/**
 * Returns copy of this settings.
 */
MOON_CSFML_API moon_ContextSettings
moon_ContextSettings_get_copy(const moon_ContextSettings* self);

/**
 * Returns 1 if settings are equal, 0 otherwise.
 * Settings are equal if their parameters are equal.
 */
MOON_CSFML_API int
moon_ContextSettings_is_eq(
	const moon_ContextSettings* self,
	const moon_ContextSettings* other
);

/**
 * Returns 1 if settings are not equal, 0 otherwise.
 * Settings are equal if their parameters are equal.
 */
MOON_CSFML_API int
moon_ContextSettings_is_ne(
	const moon_ContextSettings* self,
	const moon_ContextSettings* other
);


#ifdef __cplusplus
}
#endif


#endif
