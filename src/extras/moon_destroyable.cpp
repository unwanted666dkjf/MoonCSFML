#include "../../headers/extras/moon_destroyable.h"


int
moon_Destroyable_is_type_destroyable(int type) {
	return type >= moon_Destroyable_CharPtr
		&& type <= moon_Destroyable_SlideAnimation;
}
