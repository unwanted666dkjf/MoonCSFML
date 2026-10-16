#ifndef MOON_CSFML_EXTRAS_MOON_KEY_MOVE_H
#define MOON_CSFML_EXTRAS_MOON_KEY_MOVE_H


#include "./moon_jump.h"

#include "./moon_text_write.h"

#include "./moon_gui_fpscntr.h"

#include "./moon_sprite_group.h"

#include "./moon_slide_show.h"

#include "./moon_slide_animation.h"

#include "./moon_move_direction.h"


#include "../../headers/system/moon_time.h"

#include "../../headers/system/moon_clock.h"


#include "../../headers/window/moon_keyboard.h"


#include "../graphics/moon_text.h"

#include "../graphics/moon_circle_shape.h"

#include "../graphics/moon_convex_shape.h"

#include "../graphics/moon_rectangle_shape.h"


#ifdef __cplusplus
extern "C" {
#endif


#define moon_Keymove_HEAD	\
	int 		key_left;		\
	int 		key_right;		\
	int 		key_jump;		\
	int 		key_up;			\
	int 		key_down;		\
	int 		hor_direction;	\
	int 		ver_direction;	\
	float 		up_speed;		\
	float 		down_speed;		\
	float 		left_speed;		\
	float 		right_speed;	\
	float 		gravity_force;	\
	moon_Clock* move_clock;		\
	moon_Jump* 	jump_move;		\


/**
 * Macro to move the object based on pressed key.
 * This macro is for internal use only!
 * The object can be a sprite, text, or any shape.
 * 'moon_Keymove_self' -- pointer to structure, which controls
 *movements.
 * 'moon_object_ptr'				-- pointer to the object.
 * 'moon_Object_move' 				-- function to move object.
 * 'moon_Object_get_global_bounds' 	-- function for obtaining the
 *boundaries of an object in a global coordinate system, taking into
 *account object transformations.
 * 'int_is_jump_enabled' -- option that can be used to block(0) the jump
 *or allow(1) it.
 */
#define moon_Keymove_update_object(	\
	moon_Keymove_self,				\
	moon_object_ptr,				\
	int_is_jump_enabled,			\
	moon_Object_move,				\
	moon_Object_get_global_bounds	\
)	\
	moon_Keymove_update_object_ex(									\
		moon_Keymove_self,											\
		moon_object_ptr,											\
		int_is_jump_enabled,										\
		moon_Keyboard_is_key_pressed(moon_Keymove_self->key_left),	\
		moon_Keyboard_is_key_pressed(moon_Keymove_self->key_right),	\
		moon_Keyboard_is_key_pressed(moon_Keymove_self->key_up),	\
		moon_Keyboard_is_key_pressed(moon_Keymove_self->key_down),	\
		moon_Keyboard_is_key_pressed(moon_Keymove_self->key_jump),	\
		moon_Object_move,											\
		moon_Object_get_global_bounds								\
	)

/**
 * Macro to move the object based on pressed key.
 * This macro is for internal use only!
 * The object can be a sprite, text, or any shape.
 * 'moon_Keymove_self' -- pointer to structure, which controls
 *movements.
 * 'moon_object_ptr'				-- pointer to the object.
 * 'moon_Object_move' 				-- function to move object.
 * 'moon_Object_get_global_bounds' 	-- function for obtaining the
 *boundaries of an object in a global coordinate system, taking into
 *account object transformations.
 * 'int_is_jump_enabled' -- option that can be used to block(0) the jump
 *or allow(1) it.
 */
#define moon_Keymove_update_object_ex(	\
	moon_Keymove_self,					\
	moon_object_ptr,					\
	int_is_jump_enabled,				\
	int_is_key_left_pressed,			\
	int_is_key_right_pressed,			\
	int_is_key_up_pressed,				\
	int_is_key_down_pressed,			\
	int_is_key_jump_pressed,			\
	moon_Object_move,					\
	moon_Object_get_global_bounds		\
)	\
{	\
	moon_Keymove_self->hor_direction = moon_MoveDirection_Unknown;								\
	moon_Keymove_self->ver_direction = moon_MoveDirection_Unknown;								\
	if (!moon_Clock_is_running(moon_Keymove_self->move_clock)) {								\
		moon_Clock_start(moon_Keymove_self->move_clock);										\
	}																							\
	moon_Clock_wait(moon_Keymove_self->move_clock);												\
	float delta_secs_update_object__ = moon_Time_as_seconds(									\
		moon_Clock_delta(moon_Keymove_self->move_clock)											\
	);																							\
	float dx_update_object__ = 0.f;																\
	float dy_update_object__ = 0.f;																\
	if (int_is_key_left_pressed) {																\
		dx_update_object__ += moon_Keymove_self->left_speed * delta_secs_update_object__;		\
	}																							\
	if (int_is_key_right_pressed) {																\
		dx_update_object__ += moon_Keymove_self->right_speed * delta_secs_update_object__;		\
	}																							\
	if (																						\
		(int_is_jump_enabled)																	\
		&& int_is_key_jump_pressed																\
	) {																							\
		moon_FloatRect bounds_update_object__ = moon_Object_get_global_bounds(moon_object_ptr);	\
		moon_Jump_start(																		\
			moon_Keymove_self->jump_move,														\
			bounds_update_object__.top															\
			+ bounds_update_object__.height														\
		);																						\
	}																							\
	if (int_is_key_up_pressed) {																\
		dy_update_object__ += moon_Keymove_self->up_speed * delta_secs_update_object__;			\
	}																							\
	if (int_is_key_down_pressed) {																\
		dy_update_object__ += moon_Keymove_self->down_speed * delta_secs_update_object__;		\
	}																							\
	dy_update_object__ += moon_Jump_update(moon_Keymove_self->jump_move);						\
	dy_update_object__ += moon_Keymove_self->gravity_force * delta_secs_update_object__;		\
	moon_Object_move(																			\
		moon_object_ptr,																		\
		dx_update_object__,																		\
		dy_update_object__																		\
	);																							\
	if (dx_update_object__ > 0.f) {																\
		moon_Keymove_self->hor_direction = moon_MoveDirection_Right;							\
	} else if (dx_update_object__ < 0.f) {														\
		moon_Keymove_self->hor_direction = moon_MoveDirection_Left;								\
	}																							\
	if (dy_update_object__ > 0.f) {																\
		moon_Keymove_self->ver_direction = moon_MoveDirection_Down;								\
	} else if (dy_update_object__ < 0.f) {														\
		moon_Keymove_self->ver_direction = moon_MoveDirection_Up;								\
	}																							\
}


struct MOON_CSFML_API moon_Keymove;


/**
 * Structure for controlling the linear
 *movement of objects using the keyboard.
 */
typedef struct moon_Keymove moon_Keymove;


/**
 * Creates new layout with default values.
 * The speed of movement is always tied to time.
 * Defaults are useless:
 * 'left' 	-- 'moon_Keyboard_Key_Unknown'
 * 'right'	-- 'moon_Keyboard_Key_Unknown'
 * 'up'		-- 'moon_Keyboard_Key_Unknown'
 * 'down'	-- 'moon_Keyboard_Key_Unknown'
 * 'jump'	-- 'moon_Keyboard_Key_Unknown'
 */
MOON_CSFML_API moon_Keymove*
moon_Keymove_create();

/**
 * Destroys layout.
 */
MOON_CSFML_API void
moon_Keymove_destroy(moon_Keymove* self);

/**
 * Moves the object based on pressed key.
 * 'allow_jump' -- option that can be used to block(0) the jump
 *or allow(1) it.
 */
MOON_CSFML_API void
moon_Keymove_update_Text(
	moon_Keymove* self,
	moon_Text* text,
	int allow_jump
);

/**
 * Moves the object based on pressed key.
 * 'allow_jump' -- option that can be used to block(0) the jump
 *or allow(1) it.
 */
MOON_CSFML_API void
moon_Keymove_update_TextWrite(
	moon_Keymove* self,
	moon_TextWrite* text,
	int allow_jump
);

/**
 * Moves the object based on pressed key.
 * 'allow_jump' -- option that can be used to block(0) the jump
 *or allow(1) it.
 */
MOON_CSFML_API void
moon_Keymove_update_guiFpsCntr(
	moon_Keymove* self,
	moon_guiFpsCntr* cntr,
	int allow_jump
);

/**
 * Moves the object based on pressed key.
 * 'allow_jump' -- option that can be used to block(0) the jump
 *or allow(1) it.
 */
MOON_CSFML_API void
moon_Keymove_update_Sprite(
	moon_Keymove* self,
	moon_Sprite* sprite,
	int allow_jump
);

/**
 * Moves the object based on pressed key.
 * 'allow_jump' -- option that can be used to block(0) the jump
 *or allow(1) it.
 */
MOON_CSFML_API void
moon_Keymove_update_SpriteGroup(
	moon_Keymove* self,
	moon_SpriteGroup* sprites,
	int allow_jump
);

/**
 * Moves the object based on pressed key.
 * 'allow_jump' -- option that can be used to block(0) the jump
 *or allow(1) it.
 */
MOON_CSFML_API void
moon_Keymove_update_SlideShow(
	moon_Keymove* self,
	moon_SlideShow* animation,
	int allow_jump
);

/**
 * Moves the object based on pressed key.
 * 'allow_jump' -- option that can be used to block(0) the jump
 *or allow(1) it.
 */
MOON_CSFML_API void
moon_Keymove_update_SlideAnimation(
	moon_Keymove* self,
	moon_SlideAnimation* animation,
	int allow_jump
);

/**
 * Moves the object based on pressed key.
 * 'allow_jump' -- option that can be used to block(0) the jump
 *or allow(1) it.
 */
MOON_CSFML_API void
moon_Keymove_update_ConvexShape(
	moon_Keymove* self,
	moon_ConvexShape* shape,
	int allow_jump
);

/**
 * Moves the object based on pressed key.
 * 'allow_jump' -- option that can be used to block(0) the jump
 *or allow(1) it.
 */
MOON_CSFML_API void
moon_Keymove_update_CircleShape(
	moon_Keymove* self,
	moon_CircleShape* shape,
	int allow_jump
);

/**
 * Moves the object based on pressed key.
 * 'allow_jump' -- option that can be used to block(0) the jump
 *or allow(1) it.
 */
MOON_CSFML_API void
moon_Keymove_update_RectangleShape(
	moon_Keymove* self,
	moon_RectangleShape* shape,
	int allow_jump
);

/**
 * Sets key for up move.
 */
MOON_CSFML_API void
moon_Keymove_set_key_up(
	moon_Keymove* self,
	int key
);

/**
 * Sets key for down move.
 */
MOON_CSFML_API void
moon_Keymove_set_key_down(
	moon_Keymove* self,
	int key
);

/**
 * Sets key for right move
 */
MOON_CSFML_API void
moon_Keymove_set_key_right(
	moon_Keymove* self,
	int key
);

/**
 * Sets key for left move.
 */
MOON_CSFML_API void
moon_Keymove_set_key_left(
	moon_Keymove* self,
	int key
);

/**
 * Sets key for jump.
 */
MOON_CSFML_API void
moon_Keymove_set_key_jump(
	moon_Keymove* self,
	int key
);

/**
 * Sets up move speed.
 * Always negative.
 */
MOON_CSFML_API void
moon_Keymove_set_up_speed(
	moon_Keymove* self,
	float speed
);

/**
 * Sets down move speed.
 * Always positive.
 */
MOON_CSFML_API void
moon_Keymove_set_down_speed(
	moon_Keymove* self,
	float speed
);

/**
 * Sets right move speed.
 * Always positive.
 */
MOON_CSFML_API void
moon_Keymove_set_right_speed(
	moon_Keymove* self,
	float speed
);

/**
 * Sets left move speed.
 * Always negative.
 */
MOON_CSFML_API void
moon_Keymove_set_left_speed(
	moon_Keymove* self,
	float speed
);

/**
 * Sets jump speed.
 * Always negative.
 */
MOON_CSFML_API void
moon_Keymove_set_jump_speed(
	moon_Keymove* self,
	float speed
);

/**
 * Sets jump height.
 * Always positive.
 */
MOON_CSFML_API void
moon_Keymove_set_jump_height(
	moon_Keymove* self,
	float height
);

/**
 * Sets gravity force which will be applyied
 *to the object.
 * Always positive.
 * Adding gravity can cause a slight
 *jitter of the object at high fps(50 or over).
 */
MOON_CSFML_API void
moon_Keymove_set_gravity_force(
	moon_Keymove* self,
	float speed
);

/**
 * Returns keycode dedicated to up move.
 */
MOON_CSFML_API int
moon_Keymove_get_key_up(const moon_Keymove* self);

/**
 * Returns keycode dedicated to down move.
 */
MOON_CSFML_API int
moon_Keymove_get_key_down(const moon_Keymove* self);

/**
 * Returns keycode dedicated to right move.
 */
MOON_CSFML_API int
moon_Keymove_get_key_right(const moon_Keymove* self);

/**
 * Returns keycode dedicated to left move.
 */
MOON_CSFML_API int
moon_Keymove_get_key_left(const moon_Keymove* self);

/**
 * Returns keycode dedicated to jump.
 */
MOON_CSFML_API int
moon_Keymove_get_key_jump(const moon_Keymove* self);

/**
 * Returns current jump status.
 */
MOON_CSFML_API int
moon_Keymove_get_jump_status(const moon_Keymove* self);

/**
 * Returns horizontal direction.
 */
MOON_CSFML_API int
moon_Keymove_get_hor_direction(const moon_Keymove* self);

/**
 * Returns vertical direction.
 */
MOON_CSFML_API int
moon_Keymove_get_ver_direction(const moon_Keymove* self);

/**
 * Returns speed of up movement.
 */
MOON_CSFML_API float
moon_Keymove_get_up_speed(const moon_Keymove* self);

/**
 * Returns speed of down movement.
 */
MOON_CSFML_API float
moon_Keymove_get_down_speed(const moon_Keymove* self);

/**
 * Returns speed of left movement.
 */
MOON_CSFML_API float
moon_Keymove_get_left_speed(const moon_Keymove* self);

/**
 * Returns speed of right movement.
 */
MOON_CSFML_API float
moon_Keymove_get_right_speed(const moon_Keymove* self);

/**
 * Returns jump speed.
 */
MOON_CSFML_API float
moon_Keymove_get_jump_speed(const moon_Keymove* self);

/**
 * Returns jump height.
 */
MOON_CSFML_API float
moon_Keymove_get_jump_height(const moon_Keymove* self);

/**
 * Returns gravity force applyied to the object.
 */
MOON_CSFML_API float
moon_Keymove_get_gravity_force(const moon_Keymove* self);


#ifdef __cplusplus
}
#endif


#endif
