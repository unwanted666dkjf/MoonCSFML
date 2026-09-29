#include "../../headers/window/moon_event.h"


void
moon_Event_reset(moon_Event* self) {
	self->type = moon_Event_Type_Count;
}
