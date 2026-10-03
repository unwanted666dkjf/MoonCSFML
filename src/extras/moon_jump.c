#include "../../headers/system/moon_utils.h"

#include "../../headers/system/moon_clock.h"


#include "../../headers/extras/moon_jump.h"


struct moon_Jump {
	int 		status;
	float 		speed;
	float 		jump_height;
	float 		dst_height;
	float 		cur_height;
	moon_Clock* clock;
};


moon_Jump*
moon_Jump_create(
	float speed,
	float jump_height
) {
	moon_Jump* self = (moon_Jump*)moon_malloc(sizeof(moon_Jump));
	if (!self) {
		return NULL;
	}
	self->clock = moon_Clock_create();
	if (!self->clock) {
		moon_free(self);
		return NULL;
	}
	self->status 		= moon_Jump_Status_Idle;
	self->speed 		= -1.f * moon_utils_Abs(speed);
	self->jump_height 	= moon_utils_Abs(jump_height);
	self->dst_height	= -1.f;
	self->cur_height 	= -1.f;
	return self;
}

void
moon_Jump_destroy(moon_Jump* self) {
	moon_Clock_destroy(self->clock);
	moon_free(self);
}

int
moon_Jump_get_status(const moon_Jump* self) {
	return self->status;
}

float
moon_Jump_get_speed(const moon_Jump* self) {
	return self->speed;
}

void
moon_Jump_set_speed(
	moon_Jump* self,
	float speed
) {
	if (self->status != moon_Jump_Status_Idle) {
		return;
	}
	self->speed = -1.f * moon_utils_Abs(speed);
}

float
moon_Jump_get_height(const moon_Jump* self) {
	return self->jump_height;
}

void
moon_Jump_set_height(
	moon_Jump* self,
	float height
) {
	if (self->status != moon_Jump_Status_Idle) {
		return;
	}
	self->jump_height = moon_utils_Abs(height);
}

float
moon_Jump_update(moon_Jump* self) {
	if (self->cur_height <= self->dst_height) {
		moon_Jump_stop(self);
	}
	if (self->status != moon_Jump_Status_Jumping) {
		return 0.f;
	}
	moon_Clock_wait(self->clock);
	float delta = moon_Time_as_seconds(
		moon_Clock_delta(self->clock)
	);
	float offsety 		= self->speed * delta;
	self->cur_height 	+= offsety;
	return offsety;
}

void
moon_Jump_start(
	moon_Jump* self,
	float ground_line
) {
	if (self->status != moon_Jump_Status_Idle) {
		return;
	}
	self->status 		= moon_Jump_Status_Jumping;
	self->cur_height	= moon_utils_Abs(ground_line);
	self->dst_height 	= self->cur_height - self->jump_height;
	if (!moon_Clock_is_running(self->clock)) {
		moon_Clock_start(self->clock);
	}
}

void
moon_Jump_stop(moon_Jump* self) {
	self->status = moon_Jump_Status_Idle;
	if (moon_Clock_is_running(self->clock)) {
		moon_Clock_stop(self->clock);
	}
}
