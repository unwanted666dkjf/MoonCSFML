#include "../../headers/system/moon_utils.h"


#include "../../headers/extras/moon_standard_sizes.h"


moon_StandardSizes
moon_StandardSizes_get_desktop_sizes() {
	moon_VideoMode tmp = moon_VideoMode_get_desktop_mode();
	return moon_StandardSizes_get_sizes(&tmp);
}

moon_StandardSizes
moon_StandardSizes_get_sizes(const moon_VideoMode* video_mode) {
	unsigned int size = moon_StandardSizes_get_size(video_mode);
	float sizef = static_cast<float>(size);

	float rows = static_cast<float>(video_mode->height) / sizef;
	float cols = static_cast<float>(video_mode->width) / sizef;

	unsigned int expected_rows = static_cast<unsigned int>(rows);
	unsigned int expected_cols = static_cast<unsigned int>(cols);
	if (static_cast<float>(expected_rows) < rows) {
		expected_rows++;
	}
	if (static_cast<float>(expected_cols) < cols) {
		expected_cols++;
	}

	return {size, expected_rows, expected_cols};
}

unsigned int
moon_StandardSizes_get_size(const moon_VideoMode* video_mode) {
	float big_size, less_size;
	if (video_mode->width > video_mode->height) {
		big_size 	= static_cast<float>(video_mode->width);
		less_size 	= static_cast<float>(video_mode->height);
	} else {
		big_size 	= static_cast<float>(video_mode->height);
		less_size 	= static_cast<float>(video_mode->width);
	}
	float kwh = moon_roundf(
		big_size / less_size, 2
	);
	float divisor;
	if (kwh == 1.25f) {
		divisor = 19.f;
	} else if (kwh > 1.25f && kwh <= 1.33f) {
		divisor = 24.f;
	} else if (kwh > 1.33f && kwh <= 1.6f) {
		divisor = 20.f;
	} else if (kwh > 1.6f && kwh <= 1.78f) {
		divisor = 18.f;
	} else {
		divisor = 18.f;
	}
	return static_cast<unsigned int>(less_size / divisor);
}
