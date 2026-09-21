#include <cmath>



#include "../../headers/graphics/moon_view.h"


static const moon_FloatRect DefaultViewRect = {0, 0, 1000, 1000};


moon_View
moon_View_create() {
	moon_View self{
		0.f,					// rotation
		{0.f, 0.f},				// center
		{0.f, 0.f},				// size
		{0.f, 0.f, 1.f, 1.f}	// viewport
	};
	moon_View_reset(&self, &DefaultViewRect);
	return self;
}

moon_View
moon_View_create_ex(
	float cx, 		float cy,
	float width, 	float height
) {
	return {
		0.f,						// rotation
		{cx, cy},					// center
		{width, height},			// size
		{0.f, 0.f, 1.f, 1.f}		// viewport
	};
}

void
moon_View_set_center(
	moon_View* self,
	float cx, float cy
) {
	self->center.x = cx;
	self->center.y = cy;
}

void
moon_View_set_size(
	moon_View* self,
	float width, float height
) {
	self->size.x = width;
	self->size.y = height;
}

void
moon_View_set_rotation(
	moon_View* self,
	moon_Angle angle
) {
	self->rotation = std::fmod(angle, 360.f);
	if (self->rotation < 0.f) {
		self->rotation += 360.f;
	}
}

void
moon_View_move(
	moon_View* self,
	float dx, float dy
) {
	moon_View_set_center(self, self->center.x + dx, self->center.y + dy);
}

void
moon_View_rotate(
	moon_View* self,
	moon_Angle angle
) {
	moon_View_set_rotation(self, self->rotation + angle);
}

void
moon_View_zoom(
	moon_View* self,
	float factor
) {
	moon_View_set_size(self, self->size.x * factor, self->size.y * factor);
}

void
moon_View_reset(
	moon_View* self,
	const moon_FloatRect* rectangle
) {
	self->center.x = rectangle->left + rectangle->width / 2.f;
	self->center.y = rectangle->top + rectangle->height / 2.f;
	self->size.x   = rectangle->width;
	self->size.y   = rectangle->height;
	self->rotation = 0.f;
}

moon_Transform
moon_View_get_transform(const moon_View* self) {
	// Rotation components
	float angle  = moon_Angle_as_radians(self->rotation);
	float cosine = std::cos(angle);
	float sine   = std::sin(angle);
	float tx     = -self->center.x * cosine - self->center.y * sine + self->center.x;
	float ty     =  self->center.x * sine - self->center.y * cosine + self->center.y;

	// Projection components
	float a =  2.f / self->size.x;
	float b = -2.f / self->size.y;
	float c = -a * self->center.x;
	float d = -b * self->center.y;

	return moon_Transform_create_ex(
		a * cosine, 	a * sine,   a * tx + c,
		-b * sine,   	b * cosine, b * ty + d,
		0.f,        	0.f,        1.f
	);
}

moon_View
moon_View_get_copy(const moon_View* self) {
	return {
		self->rotation,
		self->center,
		self->size,
		self->viewport
	};
}

int
moon_View_is_eq(
	const moon_View* self,
	const moon_View* other
) {
	return self->rotation 	== other->rotation
		&& self->center.x 	== other->center.x
		&& self->center.y 	== other->center.y
		&& self->size.x 	== other->size.x
		&& self->size.y 	== other->size.y
		&& moon_FloatRect_is_eq(&self->viewport, &other->viewport);
}

int
moon_View_is_ne(
	const moon_View* self,
	const moon_View* other
) {
	return !moon_View_is_eq(self, other);
}
