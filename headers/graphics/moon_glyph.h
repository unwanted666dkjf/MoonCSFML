#ifndef MOON_CSFML_GRAPHICS_MOON_GLYPH_H
#define MOON_CSFML_GRAPHICS_MOON_GLYPH_H


#include "./moon_rect.h"


#ifdef __cplusplus
extern "C" {
#endif


#define moon_Glyph_DefaultAdvance 	(0.f)

#define moon_Glyph_DefaultLsbDelta 	(0)

#define moon_Glyph_DefaultRsbDelta 	(0)


/**
 * Structure describing a glyph.
 */
typedef struct MOON_CSFML_API moon_Glyph {
	float 			advance;		//!< Offset to move horizontally to the next character
	int				lsb_delta;		//!< Left offset after forced autohint. Internally used by getKerning()
	int 			rsb_delta;		//!< Right offset after forced autohint. Internally used by getKerning()
	moon_FloatRect 	bounds;			//!< Bounding rectangle of the glyph, in coordinates relative to the baseline
	moon_IntRect 	texture_rect;	//!< Texture coordinates of the glyph inside the font's texture
} moon_Glyph;


/**
 * Returns default glyph.
 */
MOON_CSFML_API moon_Glyph
moon_Glyph_get_default();

/**
 * Returns copy of this glyph.
 */
MOON_CSFML_API moon_Glyph
moon_Glyph_get_copy(const moon_Glyph* self);


#ifdef __cplusplus
}
#endif


#endif
