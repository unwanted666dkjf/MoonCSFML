#include <cmath>



#include "../../headers/extras/moon_useful_funcs.h"


#include "../../headers/graphics/RenderWindowStruct.hpp"


moon_FloatRect
moon_is_rect_visible(
	const moon_FloatRect* rect,
	const moon_RenderWindow* wnd
) {
	const sf::View& view 		= wnd->getView();
	const sf::Vector2f& size 	= view.getSize();
	const sf::Vector2f& center 	= view.getCenter();

	const moon_FloatRect visible_area = {
		center.x - size.x * 0.5f,
		center.y - size.y * 0.5f,
		size.x, size.y
	};

	return moon_FloatRect_get_intersection(rect, &visible_area);
}

moon_Vector2f
moon_in_area_pos(
	const moon_FloatRect* rect,
	const moon_FloatRect* area
) {
	float left 	= rect->left;
	float top 	= rect->top;
	if (left < area->left) {
		left = area->left;
	}
	if ((left + rect->width) > (area->left + area->width)) {
		left = area->left + area->width - rect->width;
	}
	if (top < area->top) {
		top = area->top;
	}
	if ((top + rect->height) > (area->top + area->height)) {
		top = area->top + area->height - rect->height;
	}
	return {left, top};
}

moon_Vector2f
moon_get_angle_offset(
	float offset,
	moon_Angle angle
) {
	const float radians = moon_Angle_as_radians(angle);
	return {
		offset * std::cos(radians),
		offset * std::sin(radians)
	};
}

moon_Vector2f
moon_get_circle_point_position(
	float cx, float cy,
	float radius,
	moon_Angle angle
) {
	const float radians = moon_Angle_as_radians(angle);
	return {
		cx + radius * std::cos(radians),
		cy + radius * std::sin(radians)
	};
}

moon_Vector2f
moon_get_sine_wave_position(
	float x0, float y0,
	float speed,
	float amplitude,
	float wavelength,
	moon_Time  time,
	moon_Angle phase
) {
	const float dt = speed * moon_Time_as_seconds(time);
	const float x = x0 + dt;
	const float radians = moon_Angle_as_radians(phase);
	const float y = y0 + amplitude * std::sin(
		2.f
		* moon_Angle_M_PI
		* dt
		/ wavelength + radians
	);

	return {x, y};
}

moon_Vector2f
moon_get_cosine_wave_position(
	float x0, float y0,
	float speed,
	float amplitude,
	float wavelength,
	moon_Time  time,
	moon_Angle phase
) {
	const float dt = speed * moon_Time_as_seconds(time);
	const float x = x0 + dt;
	const float radians = moon_Angle_as_radians(phase);
	const float y = y0 + amplitude * std::cos(
		2.f
		* moon_Angle_M_PI
		* dt
		/ wavelength + radians
	);

	return {x, y};
}

moon_Vector2f
moon_new_size(
	float old_width, 	float old_height,
	float new_width, 	float new_height,
	int keep_w,			int keep_h
) {
	if (!(keep_w || keep_h)) {
		return {new_width, new_height};
	}
	if (!(old_width && old_height)) {
		return {new_width, new_height};
	}
	if (keep_w && keep_h) {
		return {new_width, new_height};
	}
	if (keep_w) {
		float kwh = old_width / old_height;
		new_height = new_width / kwh;
	}
	if (keep_h) {
		float khw = old_height / old_width;
		new_width = new_height / khw;
	}
	return {new_width, new_height};
}
