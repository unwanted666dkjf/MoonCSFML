#include "../../headers/graphics/RectUtils.hpp"

#include "../../headers/graphics/moon_rect.h"


moon_IntRect
moon_IntRect_create_empty() {
	return moon_Rect_create_empty<moon_IntRect>();
}

moon_IntRect
moon_IntRect_get_copy(const moon_IntRect* self) {
	return moon_Rect_convert<moon_IntRect, moon_IntRect, int>(self);
}

int
moon_IntRect_is_empty(const moon_IntRect* self) {
	return moon_Rect_is_empty<moon_IntRect>(self);
}

int
moon_IntRect_contains(
	const moon_IntRect* self,
	int x, int y
) {
	return moon_Rect_contains<moon_IntRect, int>(self, x, y);
}

int
moon_IntRect_is_eq(
	const moon_IntRect* self,
	const moon_IntRect* other
) {
	return moon_Rect_is_eq<moon_IntRect>(self, other);
}

int
moon_IntRect_is_ne(
	const moon_IntRect* self,
	const moon_IntRect* other
) {
	return moon_Rect_is_ne<moon_IntRect>(self, other);
}

moon_IntRect
moon_IntRect_get_intersection(
	const moon_IntRect* self,
	const moon_IntRect* other
) {
	return moon_Rect_get_intersection<moon_IntRect>(self, other);
}


moon_FloatRect
moon_FloatRect_create_empty() {
	return moon_Rect_create_empty<moon_FloatRect>();
}

moon_FloatRect
moon_FloatRect_get_copy(const moon_FloatRect* self) {
	return moon_Rect_convert<moon_FloatRect, moon_FloatRect, float>(self);
}

int
moon_FloatRect_is_empty(const moon_FloatRect* self) {
	return moon_Rect_is_empty<moon_FloatRect>(self);
}

int
moon_FloatRect_contains(
	const moon_FloatRect* self,
	float x, float y
) {
	return moon_Rect_contains<moon_FloatRect, float>(self, x, y);
}

int
moon_FloatRect_is_eq(
	const moon_FloatRect* self,
	const moon_FloatRect* other
) {
	return moon_Rect_is_eq<moon_FloatRect>(self, other);
}

int
moon_FloatRect_is_ne(
	const moon_FloatRect* self,
	const moon_FloatRect* other
) {
	return moon_Rect_is_ne<moon_FloatRect>(self, other);
}

moon_FloatRect
moon_FloatRect_get_intersection(
	const moon_FloatRect* self,
	const moon_FloatRect* other
) {
	return moon_Rect_get_intersection<moon_FloatRect>(self, other);
}


moon_IntRect
moon_Rect_ftoi(const moon_FloatRect* rect) {
	return moon_Rect_convert<moon_FloatRect, moon_IntRect, int>(rect);
}

moon_FloatRect
moon_Rect_itof(const moon_IntRect* rect) {
	return moon_Rect_convert<moon_IntRect, moon_FloatRect, float>(rect);
}
