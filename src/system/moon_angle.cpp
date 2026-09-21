#include "../../headers/system/moon_angle.h"


moon_Angle
moon_Angle_from_degrees(float degrees) {
	return degrees;
}

moon_Angle
moon_Angle_from_radians(float radians) {
	return 180.f * radians / moon_Angle_M_PI;
}

float
moon_Angle_as_degrees(moon_Angle angle) {
	return angle;
}

float
moon_Angle_as_radians(moon_Angle angle) {
	return moon_Angle_M_PI * angle / 180.f;
}
