#include "../../headers/graphics/moon_rect.h"


moon_IntRect
moon_IntRect_create_empty() {
	return moon_Rect_create_empty(moon_IntRect);
}

moon_IntRect
moon_IntRect_get_copy(const moon_IntRect* self) {
	return moon_Rect_convert(moon_IntRect, (*self));
}

int
moon_IntRect_is_empty(const moon_IntRect* self) {
	return moon_Rect_is_empty((*self));
}

int
moon_IntRect_contains(
	const moon_IntRect* self,
	int x, int y
) {
	return moon_Rect_contains((*self), x, y);
}

int
moon_IntRect_is_eq(
	const moon_IntRect* self,
	const moon_IntRect* other
) {
	return moon_Rect_is_eq((*self), (*other));
}

int
moon_IntRect_is_ne(
	const moon_IntRect* self,
	const moon_IntRect* other
) {
	return moon_Rect_is_ne((*self), (*other));
}

moon_IntRect
moon_IntRect_get_intersection(
	const moon_IntRect* self,
	const moon_IntRect* other
) {
	moon_IntRect res;
	moon_Rect_Procedure_intersection(res, int, (*self), (*other));
	return res;
}


moon_FloatRect
moon_FloatRect_create_empty() {
	return moon_Rect_create_empty(moon_FloatRect);
}

moon_FloatRect
moon_FloatRect_get_copy(const moon_FloatRect* self) {
	return moon_Rect_convert(moon_FloatRect, (*self));
}

int
moon_FloatRect_is_empty(const moon_FloatRect* self) {
	return moon_Rect_is_empty((*self));
}

int
moon_FloatRect_contains(
	const moon_FloatRect* self,
	float x, float y
) {
	return moon_Rect_contains((*self), x, y);
}

int
moon_FloatRect_is_eq(
	const moon_FloatRect* self,
	const moon_FloatRect* other
) {
	return moon_Rect_is_eq((*self), (*other));
}

int
moon_FloatRect_is_ne(
	const moon_FloatRect* self,
	const moon_FloatRect* other
) {
	return moon_Rect_is_ne((*self), (*other));
}

moon_FloatRect
moon_FloatRect_get_intersection(
	const moon_FloatRect* self,
	const moon_FloatRect* other
) {
	moon_FloatRect res;
	moon_Rect_Procedure_intersection(res, float, (*self), (*other));
	return res;
}


moon_IntRect
moon_Rect_ftoi(const moon_FloatRect* rect) {
	return moon_Rect_convert(moon_IntRect, (*rect));
}

moon_FloatRect
moon_Rect_itof(const moon_IntRect* rect) {
	return moon_Rect_convert(moon_FloatRect, (*rect));
}
