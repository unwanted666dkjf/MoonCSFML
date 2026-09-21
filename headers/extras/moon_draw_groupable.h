#ifndef MOON_CSFML_EXTRAS_MOON_DRAW_GROUPABLE_H
#define MOON_CSFML_EXTRAS_MOON_DRAW_GROUPABLE_H


#include "../import_macro.h"


#ifdef __cplusplus
extern "C" {
#endif


enum {
	moon_Draw_Groupable_Text,
	moon_Draw_Groupable_Sprite,
	moon_Draw_Groupable_TextWrite,
	moon_Draw_Groupable_guiFpsCntr,
	moon_Draw_Groupable_ConvexShape,
	moon_Draw_Groupable_CircleShape,
	moon_Draw_Groupable_RectangleShape,
	moon_Draw_Groupable_SlideAnimation
};


/**
 * Structure for storing groupable objects for drawing.
 * Only for internal usage.
 * Groupable: Text, Sprite, ConvexShape, CircleShape,
 *RectangleShape, SlideAnimation, guiFpsCntr.
 */
typedef struct MOON_CSFML_API moon_DrawGroupable {
	int type;
	const void* body;
} moon_DrawGroupable;


/**
 * Returns 1 if this 'type' can be a member of DrawGroup.
 * Otherwise, returns 0.
 * Groupable: Text, Sprite, ConvexShape, CircleShape,
 *RectangleShape, SlideAnimation, guiFpsCntr.
 */
MOON_CSFML_API int
moon_Draw_is_groupable(int type);


#ifdef __cplusplus
}
#endif


#endif
