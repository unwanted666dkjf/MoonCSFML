#include "../../headers/system/moon_time.h"


moon_Time
moon_Time_zero() {
	return 0ULL;
}

moon_Time
moon_Time_from_seconds(float seconds) {
	return static_cast<moon_Time>(
		seconds
		* static_cast<float>(moon_Time_NANOSEC_IN_SEC)
	);
}

moon_Time
moon_Time_from_milliseconds(unsigned long milliseconds) {
	return static_cast<moon_Time>(
		milliseconds
		* moon_Time_NANOSEC_IN_MILLISEC
	);
}

moon_Time
moon_Time_from_microseconds(unsigned long long microseconds) {
	return static_cast<moon_Time>(
		microseconds
		* moon_Time_NANOSEC_IN_MICROSEC
	);
}

moon_Time
moon_Time_from_nanoseconds(unsigned long long nanoseconds) {
	return nanoseconds;
}

float
moon_Time_as_seconds(moon_Time self) {
	return static_cast<float>(self)
		/ static_cast<float>(moon_Time_NANOSEC_IN_SEC);
}

unsigned long
moon_Time_as_milliseconds(moon_Time self) {
	return static_cast<unsigned long>(
		static_cast<double>(self)
		/ static_cast<double>(moon_Time_NANOSEC_IN_MILLISEC)
	);
}

unsigned long long
moon_Time_as_microseconds(moon_Time self) {
	return static_cast<unsigned long long>(
		static_cast<double>(self)
		/ static_cast<double>(moon_Time_NANOSEC_IN_MICROSEC)
	);
}

unsigned long long
moon_Time_as_nanoseconds(moon_Time self) {
	return self;
}
