#include <chrono>

#include <thread>


#include "../../headers/system/moon_sleep.h"


void
moon_sleep(moon_Time time) {
	std::this_thread::sleep_for(
		std::chrono::nanoseconds(time)
	);
}
