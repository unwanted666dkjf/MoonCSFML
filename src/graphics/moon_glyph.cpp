#include "../../headers/graphics/moon_glyph.h"


moon_Glyph
moon_Glyph_get_default() {
	return {
		moon_Glyph_DefaultAdvance,	// advance
		moon_Glyph_DefaultLsbDelta,	// lsb_delta
		moon_Glyph_DefaultRsbDelta,	// rsb_delta
		{0.f, 0.f, 0.f, 0.f},		// bounds
		{0,   0,   0,   0}			// texture_rect
	};
}

moon_Glyph
moon_Glyph_get_copy(const moon_Glyph* self) {
	return {
		self->advance,
		self->lsb_delta,
		self->rsb_delta,
		self->bounds,
		self->texture_rect
	};
}
