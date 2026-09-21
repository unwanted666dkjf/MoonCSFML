#include "../../headers/window/moon_context_settings.h"


moon_ContextSettings
moon_ContextSettings_get_copy(const moon_ContextSettings* self) {
	return {
		self->depth_bits,
		self->stencil_bits,
		self->antialiasing_level,
		self->major_version,
		self->minor_version,
		self->attribute_flags,
		self->srgb_capable
	};
}

int
moon_ContextSettings_is_eq(
	const moon_ContextSettings* self,
	const moon_ContextSettings* other
) {
	return self->depth_bits 			== other->depth_bits
		&& self->stencil_bits 			== other->stencil_bits
		&& self->antialiasing_level 	== other->antialiasing_level
		&& self->major_version 			== other->major_version
		&& self->minor_version 			== other->minor_version
		&& self->attribute_flags 		== other->attribute_flags
		&& self->srgb_capable 			== other->srgb_capable;
}

int
moon_ContextSettings_is_ne(
	const moon_ContextSettings* self,
	const moon_ContextSettings* other
) {
	return !moon_ContextSettings_is_eq(self, other);
}
