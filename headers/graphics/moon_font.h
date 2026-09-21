#ifndef MOON_CSFML_GRAPHICS_MOON_FONT_H
#define MOON_CSFML_GRAPHICS_MOON_FONT_H


#include "./moon_glyph.h"

#include "./moon_texture.h"


#ifdef __cplusplus
extern "C" {
#endif


struct MOON_CSFML_API moon_Font;


/**
 * Structure for loading and manipulating character fonts.
 */
typedef struct moon_Font moon_Font;


/**
 * Creates an empty font.
 */
MOON_CSFML_API moon_Font*
moon_Font_create();

/**
 * Destroys font.
 */
MOON_CSFML_API void
moon_Font_destroy(moon_Font* self);

/**
 * Creates copy of this font.
 */
MOON_CSFML_API moon_Font*
moon_Font_get_copy(const moon_Font* self);

/**
 * Loads the font from a file.
 *
 * The supported font formats are: TrueType, Type 1, CFF,
 *OpenType, SFNT, X11 PCF, Windows FNT, BDF, PFR and Type 42.
 * Note that this function knows nothing about the standard
 *fonts installed on the user's system, thus you can't
 *load them directly.
 *
 * \warning SFML cannot preload all the font data in this
 *function, so the file has to remain accessible until
 *the sf::Font object loads a new font or is destroyed.
 * Returns 1 if loading succeeded, 0 if it failed.
 */
MOON_CSFML_API int
moon_Font_load(
	moon_Font* self,
	const char* filepath
);

/**
 * Returns the font family.
 */
MOON_CSFML_API const char*
moon_Font_get_family(const moon_Font* self);

/**
 * Returns a copy of glyph of the font.
 * If the font is a bitmap font, not all character sizes
 *might be available. If the glyph is not available at the
 *requested size, an empty glyph is returned.
 *
 * You may want to use \ref has_glyph to determine if the
 *glyph exists before requesting it. If the glyph does not
 *exist, a font specific default is returned.
 *
 * Be aware that using a negative value for the outline
 *thickness will cause distorted rendering.
 *
 * 'code_point' 		-- Unicode code point of the character to get.
 * 'character_size' 	-- Reference character size.
 * 'is_bold' 			-- Retrieve the bold version or the regular one?.
 * 'outline_thickness' 	-- Thickness of outline (when != 0 the glyph will not be filled).
 */
MOON_CSFML_API moon_Glyph
moon_Font_get_glyph(
	const moon_Font* self,
	unsigned int code_point,
	unsigned int character_size,
	int is_bold,
	float outline_thickness
);

/**
 * Determines if this font has a glyph representing the requested code point.
 * Most fonts only include a very limited selection of glyphs from
 *specific Unicode subsets, like Latin, Cyrillic, or Asian characters.
 *
 * While code points without representation will return a font specific
 *default character, it might be useful to verify whether specific
 *code points are included to determine whether a font is suited
 *to display text in a specific language.
 * Returns 1 if the codepoint has a glyph representation, 0 otherwise.
 */
MOON_CSFML_API int
moon_Font_has_glyph(
	const moon_Font* self,
	unsigned int code_point
);

/**
 * Returns Get the kerning offset(pixels) of two glyphs.
 * The kerning is an extra offset (negative) to apply between two
 *glyphs when rendering them, to make the pair look more "natural".
 * For example, the pair "AV" have a special kerning to make them
 *closer than other characters. Most of the glyphs pairs have a
 *kerning offset of zero, though.
 *
 * \param first         Unicode code point of the first character
 * \param second        Unicode code point of the second character
 * \param character_size Reference character size
 */
MOON_CSFML_API float
moon_Font_get_kerning(
	const moon_Font* self,
	unsigned int first,
	unsigned int second,
	unsigned int character_size,
	int is_bold
);

/**
 * Returns the line spacing(in pixels).
 * Line spacing is the vertical offset to apply between two
 *consecutive lines of text.
 */
MOON_CSFML_API float
moon_Font_get_line_spacing(
	const moon_Font* self,
	unsigned int character_size
);

/**
 * Returns the position of the underline(in pixels).
 * Underline position is the vertical offset to apply between the
 *baseline and the underline.
 */
MOON_CSFML_API float
moon_Font_get_underline_position(
	const moon_Font* self,
	unsigned int character_size
);

/**
 * Returns the thickness of the underline(in pixels).
 * Underline thickness is the vertical size of the underline.
 */
MOON_CSFML_API float
moon_Font_get_underline_thickness(
	const moon_Font* self,
	unsigned int character_size
);

/**
 * Returns copy of the texture containing the loaded glyphs of a certain size.
 *
 * The contents of the returned texture changes as more glyphs
 *are requested, thus it is not very relevant. It is mainly
 *used internally by Text.
 */
MOON_CSFML_API moon_Texture*
moon_Font_get_texture(
	const moon_Font* self,
	unsigned int character_size
);

/**
 * Enable or disable the smooth filter.
 *
 * When the filter is activated, the font appears smoother
 *so that pixels are less noticeable. However if you want
 *the font to look exactly the same as its source file,
 *you should disable it.
 * The smooth filter is enabled by default.
 * Pass 1 to enable smoothing, 0 to disable it.
 */
MOON_CSFML_API void
moon_Font_set_smooth(
	moon_Font* self,
	int is_smooth
);

/**
 * Returns 1 if smoothing is enabled, 0 if it is disabled.
 */
MOON_CSFML_API int
moon_Font_is_smooth(const moon_Font* self);


#ifdef __cplusplus
}
#endif


#endif
