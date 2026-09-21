#include <cmath>



#include "../../headers/system/moon_utils.h"


#include "../../headers/graphics/moon_transform.h"


moon_Transform
moon_Transform_create() {
	moon_Transform self;
	self.matrix[0] = 1.f; self.matrix[4] = 0.f; self.matrix[8]  = 0.f; self.matrix[12] = 0.f;
	self.matrix[1] = 0.f; self.matrix[5] = 1.f; self.matrix[9]  = 0.f; self.matrix[13] = 0.f;
	self.matrix[2] = 0.f; self.matrix[6] = 0.f; self.matrix[10] = 1.f; self.matrix[14] = 0.f;
	self.matrix[3] = 0.f; self.matrix[7] = 0.f; self.matrix[11] = 0.f; self.matrix[15] = 1.f;
	return self;
}

moon_Transform
moon_Transform_create_ex(
	float a00, float a01, float a02,
	float a10, float a11, float a12,
	float a20, float a21, float a22
) {
	moon_Transform self;
	self.matrix[0] = a00; self.matrix[4] = a01; self.matrix[8]  = 0.f; self.matrix[12] = a02;
	self.matrix[1] = a10; self.matrix[5] = a11; self.matrix[9]  = 0.f; self.matrix[13] = a12;
	self.matrix[2] = 0.f; self.matrix[6] = 0.f; self.matrix[10] = 1.f; self.matrix[14] = 0.f;
	self.matrix[3] = a20; self.matrix[7] = a21; self.matrix[11] = 0.f; self.matrix[15] = a22;
	return self;
}

moon_Transform
moon_Transform_get_copy(const moon_Transform* self) {
	moon_Transform form;
	moon_memcpy(
		form.matrix,
		self->matrix,
		moon_Transform_MatrixSize * sizeof(float)
	);
	return form;
}

const float*
moon_Transform_get_matrix(const moon_Transform* self) {
	return self->matrix;
}

moon_Transform
moon_Transform_get_inverse(const moon_Transform* self) {
	float det = self->matrix[0]
		* (self->matrix[15] * self->matrix[5] - self->matrix[7] * self->matrix[13])
		- self->matrix[1] * (self->matrix[15] * self->matrix[4] - self->matrix[7] * self->matrix[12])
		+ self->matrix[3] * (self->matrix[13] * self->matrix[4] - self->matrix[5] * self->matrix[12]);
	if (det == 0.f) {
		return moon_Transform_create();
	}
	return moon_Transform_create_ex(
		(self->matrix[15] * self->matrix[5] - self->matrix[7] * self->matrix[13]) / det,
		-(self->matrix[15] * self->matrix[4] - self->matrix[7] * self->matrix[12]) / det,
		(self->matrix[13] * self->matrix[4] - self->matrix[5] * self->matrix[12]) / det,
		-(self->matrix[15] * self->matrix[1] - self->matrix[3] * self->matrix[13]) / det,
		(self->matrix[15] * self->matrix[0] - self->matrix[3] * self->matrix[12]) / det,
		-(self->matrix[13] * self->matrix[0] - self->matrix[1] * self->matrix[12]) / det,
		(self->matrix[7]  * self->matrix[1] - self->matrix[3] * self->matrix[5])  / det,
		-(self->matrix[7]  * self->matrix[0] - self->matrix[3] * self->matrix[4])  / det,
		(self->matrix[5]  * self->matrix[0] - self->matrix[1] * self->matrix[4])  / det
	);
}

moon_Vector2f
moon_Transform_transform_point(
	const moon_Transform* self,
	float x, float y
) {
	return {
		self->matrix[0] * x + self->matrix[4] * y + self->matrix[12],
		self->matrix[1] * x + self->matrix[5] * y + self->matrix[13]
	};
}

moon_FloatRect
moon_Transform_transform_rectangle(
	const moon_Transform* self,
	const moon_FloatRect* rectangle
) {
	// Transform the 4 corners of the rectangle
	const moon_Vector2f points[] =
	{
		moon_Transform_transform_point(
			self, rectangle->left, rectangle->top
		),
		moon_Transform_transform_point(
			self, rectangle->left, rectangle->top + rectangle->height
		),
		moon_Transform_transform_point(
			self, rectangle->left + rectangle->width, rectangle->top
		),
		moon_Transform_transform_point(
			self, rectangle->left + rectangle->width, rectangle->top + rectangle->height
		)
	};

	// Compute the bounding rectangle of the transformed points
	const float* left 	= &points[0].x;
	const float* top 	= &points[0].y;
	const float* right 	= &points[0].x;
	const float* bottom = &points[0].y;
	for (int i = 1; i < 4; ++i) {
		if (points[i].x < (*left)) {
			left = &points[i].x;
		} else if (points[i].x > (*right))  {
			right = &points[i].x;
		}
		if (points[i].y < (*top)) {
			top = &points[i].y;
		} else if (points[i].y > (*bottom)) {
			bottom = &points[i].y;
		}
	}
	return {(*left), (*top), (*right) - (*left), (*bottom) - (*top)};
}

moon_Transform
moon_Transform_combine(
	const moon_Transform* self,
	const moon_Transform* other
) {
	const float* a = self->matrix;
	const float* b = other->matrix;

	return moon_Transform_create_ex(
		a[0] * b[0]  + a[4] * b[1]  + a[12] * b[3],
		a[0] * b[4]  + a[4] * b[5]  + a[12] * b[7],
		a[0] * b[12] + a[4] * b[13] + a[12] * b[15],
		a[1] * b[0]  + a[5] * b[1]  + a[13] * b[3],
		a[1] * b[4]  + a[5] * b[5]  + a[13] * b[7],
		a[1] * b[12] + a[5] * b[13] + a[13] * b[15],
		a[3] * b[0]  + a[7] * b[1]  + a[15] * b[3],
		a[3] * b[4]  + a[7] * b[5]  + a[15] * b[7],
		a[3] * b[12] + a[7] * b[13] + a[15] * b[15]
	);
}

moon_Transform
moon_Transform_translate(
	const moon_Transform* self,
	float x, float y
) {
	const moon_Transform translation = moon_Transform_create_ex(
		1.f, 0.f, x,
		0.f, 1.f, y,
		0.f, 0.f, 1.f
	);
	return moon_Transform_combine(self, &translation);
}

moon_Transform
moon_Transform_rotate(
	const moon_Transform* self,
	moon_Angle angle
) {
	float rad = moon_Angle_as_radians(angle);
	float cos = std::cos(rad);
	float sin = std::sin(rad);

	const moon_Transform rotation = moon_Transform_create_ex(
		cos, 	-sin, 	0.f,
		sin,  	cos, 	0.f,
		0.f,    0.f,   	1.f
	);

	return moon_Transform_combine(self, &rotation);
}

moon_Transform
moon_Transform_rotate_ex(
	const moon_Transform* self,
	moon_Angle angle,
	float cx, float cy
) {
	float rad = moon_Angle_as_radians(angle);
	float cos = std::cos(rad);
	float sin = std::sin(rad);

	const moon_Transform rotation = moon_Transform_create_ex(
		cos, 	-sin, 	cx * (1.f - cos) + cy * sin,
		sin,  	cos, 	cy * (1.f - cos) - cx * sin,
		0.f,    0.f,   	1.f
	);
	return moon_Transform_combine(self, &rotation);
}

moon_Transform
moon_Transform_scale(
	const moon_Transform* self,
	float scale_x, float scale_y
) {
	const moon_Transform scaling = moon_Transform_create_ex(
		scale_x, 	0.f,      	0.f,
		0.f,      	scale_y, 	0.f,
		0.f,      	0.f,      	1.f
	);
	return moon_Transform_combine(self, &scaling);
}

moon_Transform
moon_Transform_scale_ex(
	const moon_Transform* self,
	float scale_x, float scale_y,
	float cx, float cy
) {
	const moon_Transform scaling = moon_Transform_create_ex(
		scale_x, 	0.f,      	cx * (1.f - scale_x),
		0.f,      	scale_y, 	cy * (1.f - scale_y),
		0.f,      	0.f,      	1.f
	);
	return moon_Transform_combine(self, &scaling);
}

int
moon_Transform_is_eq(
	const moon_Transform* self,
	const moon_Transform* other
) {
	const float* a = self->matrix;
	const float* b = other->matrix;

	return (
		(a[0]  == b[0])  && (a[1]  == b[1])  && (a[3]  == b[3])
		&& (a[4]  == b[4])  && (a[5]  == b[5])  && (a[7]  == b[7])
		&& (a[12] == b[12]) && (a[13] == b[13]) && (a[15] == b[15])
	);
}

int
moon_Transform_is_ne(
	const moon_Transform* self,
	const moon_Transform* other
) {
	return !moon_Transform_is_eq(self, other);
}
