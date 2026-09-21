#include "../../headers/graphics/moon_blend_mode.h"


moon_BlendMode
moon_BlendMode_get_copy(const moon_BlendMode* self) {
	return {
		self->color_src_factor,
		self->color_dst_factor,
		self->color_equation,
		self->alpha_src_factor,
		self->alpha_dst_factor,
		self->alpha_equation
	};
}

int
moon_BlendMode_is_eq(
	const moon_BlendMode* self,
	const moon_BlendMode* other
) {
	return self->color_src_factor 	== other->color_src_factor
		&& self->color_dst_factor 	== other->color_dst_factor
		&& self->color_equation 	== other->color_equation
		&& self->alpha_src_factor 	== other->alpha_src_factor
		&& self->alpha_dst_factor 	== other->alpha_dst_factor
		&& self->alpha_equation 	== other->alpha_equation;
}

int
moon_BlendMode_is_ne(
	const moon_BlendMode* self,
	const moon_BlendMode* other
) {
	return !moon_BlendMode_is_eq(self, other);
}
