#include "../../headers/extras/moon_draw_groupable.h"


int
moon_DrawGroup_is_groupable(int type) {
	return type >= moon_Draw_Groupable_Text
		&& type <= moon_Draw_Groupable_SlideAnimation;
}
