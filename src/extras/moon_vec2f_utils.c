#include "../../headers/extras/moon_vec2utils.h"

#include "../../headers/extras/moon_vec2f_utils.h"


float
moon_Vec2f_utils_length(const moon_Vector2f* self) {
	return (float)(moon_Vec2utils_length((*self)));
}

float
moon_Vec2f_utils_dot_product(
	const moon_Vector2f* self,
	const moon_Vector2f* other
) {
	return (float)(moon_Vec2utils_dot_product((*self), (*other)));
}

float
moon_Vec2f_utils_cross_product(
	const moon_Vector2f* self,
	const moon_Vector2f* other
) {
	return (float)(moon_Vec2utils_cross_product((*self), (*other)));
}

moon_Angle
moon_Vec2f_utils_angle(
	const moon_Vector2f* self,
	const moon_Vector2f* other
) {
	float mods = moon_Vec2f_utils_length(self) * moon_Vec2f_utils_length(other);
	if (mods == 0.f) {
		return 0.f;
	}
	float cosine = moon_Vec2f_utils_dot_product(self, other) / mods;
	if (cosine < -1.f) {
		cosine = -1.f;
	} else if (cosine > 1.f) {
		cosine = 1.f;
	}
	return moon_Angle_from_radians(
		acosf(cosine)
	);
}

moon_Vector2f
moon_Vec2f_utils_normalization(const moon_Vector2f* self) {
	moon_Vector2f res;
	moon_Vec2utils_Procedure_normalization(res, (*self));
	return res;
}

moon_Vector2f
moon_Vec2f_utils_num_multiply(
	const moon_Vector2f* self,
	float num
) {
	return moon_Vec2utils_num_multiply(moon_Vector2f, num, (*self));
}

moon_Vector2f
moon_Vec2f_utils_sum(
	const moon_Vector2f* self,
	const moon_Vector2f* other
) {
	return moon_Vec2utils_sum(moon_Vector2f, (*self), (*other));
}

moon_Vector2f
moon_Vec2f_utils_sub(
	const moon_Vector2f* self,
	const moon_Vector2f* other
) {
	return moon_Vec2utils_sub(moon_Vector2f, (*self), (*other));
}

moon_Vector2f
moon_Vec2f_utils_reflection(
	const moon_Vector2f* self,
	const moon_Vector2f* normal
) {
	moon_Vector2f res;
	moon_Vec2utils_Procedure_reflection(res, (*normal), (*self));
	return res;
}
