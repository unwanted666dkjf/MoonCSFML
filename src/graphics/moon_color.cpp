#include "../../headers/graphics/moon_color.h"


moon_Color
moon_Color_get_copy(const moon_Color* self) {
	return {
		self->red,
		self->green,
		self->blue,
		self->alpha
	};
}

moon_Color
moon_Color_from_integer(unsigned int color) {
	return moon_Color_from_rgba(
		(color >> 24) & 0xFF,
		(color >> 16) & 0xFF,
		(color >> 8) & 0xFF,
		color & 0xFF
	);
}

moon_Color
moon_Color_from_rgb(
	unsigned char red,
	unsigned char green,
	unsigned char blue
) {
	return moon_Color_from_rgba(red, green, blue, 255);
}

moon_Color
moon_Color_from_rgba(
	unsigned char red,
	unsigned char green,
	unsigned char blue,
	unsigned char alpha
) {
	return {red, green, blue, alpha};
}

moon_Color
moon_Color_get_inverse(const moon_Color* self) {
	return moon_Color_from_rgba(
		255 - self->red,
		255 - self->green,
		255 - self->blue,
		self->alpha
	);
}

unsigned int
moon_Color_to_integer(const moon_Color* self) {
	return 	(self->red 		<< 24)
		| 	(self->green 	<< 16)
		| 	(self->blue 	<< 8)
		| 	self->alpha;
}

int
moon_Color_is_eq(
	const moon_Color* self,
	const moon_Color* other
) {
	return moon_Color_is_rgb_eq(self, other)
		&& self->alpha == other->alpha;
}

int
moon_Color_is_ne(
	const moon_Color* self,
	const moon_Color* other
) {
	return !moon_Color_is_eq(self, other);
}

int
moon_Color_is_rgb_eq(
	const moon_Color* self,
	const moon_Color* other
) {
	return self->red 	== other->red
		&& self->green 	== other->green
		&& self->blue 	== other->blue;
}

int
moon_Color_is_rgb_ne(
	const moon_Color* self,
	const moon_Color* other
) {
	return !moon_Color_is_rgb_eq(self, other);
}
