#include <new>

#include <chrono>


#include "../../headers/system/moon_clock.h"


using nanoseconds = std::chrono::nanoseconds;

using steady_clock = std::chrono::steady_clock;


struct moon_Clock {
	int is_running;
	moon_Time dt;
	moon_Time buffer;
	steady_clock::time_point current;

	moon_Clock(
		int v_is_running,
		moon_Time v_dt,
		moon_Time v_buffer
	): is_running(v_is_running),
		dt(v_dt), buffer(v_buffer)
	{
		//
	}

};


moon_Clock*
moon_Clock_create() {
	return new moon_Clock(0, 0ULL, 0ULL);
}

void
moon_Clock_destroy(moon_Clock* self) {
	delete self;
}

void
moon_Clock_wait(moon_Clock* self) {
	if (!self->is_running) {
		return;
	}
	steady_clock::time_point current = steady_clock::now();
	const nanoseconds elapsed =
		std::chrono::duration_cast<nanoseconds>(current - self->current);
	self->dt = static_cast<unsigned long long>(elapsed.count());
	self->buffer += self->dt;
	self->current = current;
}

void
moon_Clock_start(moon_Clock* self) {
	self->is_running = 1;
	self->current = steady_clock::now();
}

void
moon_Clock_reset(moon_Clock* self) {
	self->buffer = 0ULL;
}

int
moon_Clock_is_running(const moon_Clock* self) {
	return self->is_running;
}

moon_Time
moon_Clock_stop(moon_Clock* self) {
	moon_Time buf_tm = self->buffer;
	self->dt 			= 0ULL;
	self->buffer 		= 0ULL;
	self->is_running 	= 0;
	return buf_tm;
}

moon_Time
moon_Clock_delta(const moon_Clock* self) {
	return self->dt;
}

moon_Time
moon_Clock_restart(moon_Clock* self) {
	moon_Time buf = self->buffer;
	self->buffer 		= 0ULL;
	if (!self->is_running) {
		moon_Clock_start(self);
	}
	return buf;
}

moon_Time
moon_Clock_get_elapsed_time(const moon_Clock* self) {
	return self->buffer;
}
