#include "../../headers/system/moon_utils.h"


#include "../../headers/extras/moon_keymove.h"


struct moon_Keymove {
	moon_Keymove_HEAD
};

moon_Keymove*
moon_Keymove_create() {
	moon_Keymove* self = (moon_Keymove*)moon_malloc(sizeof(moon_Keymove));
	if (!self) {
		return NULL;
	}
	self->move_clock = moon_Clock_create();
	if (!self->move_clock) {
		moon_free(self);
		return NULL;
	}
	self->jump_move = moon_Jump_create(0.f, 0.f);
	if (!self->jump_move) {
		moon_Clock_destroy(self->move_clock);
		moon_free(self);
		return NULL;
	}
	self->gravity_force = 0.f;
	self->key_left	= moon_Keyboard_Key_Unknown;
	self->key_right	= moon_Keyboard_Key_Unknown;
	self->key_jump	= moon_Keyboard_Key_Unknown;
	self->key_up	= moon_Keyboard_Key_Unknown;
	self->key_down	= moon_Keyboard_Key_Unknown;
	self->hor_direction = moon_MoveDirection_Unknown;
	self->ver_direction = moon_MoveDirection_Unknown;
	return self;
}

void
moon_Keymove_destroy(moon_Keymove* self) {
	moon_Jump_destroy(self->jump_move);
	moon_Clock_destroy(self->move_clock);
	moon_free(self);
}

void
moon_Keymove_update_Text(
	moon_Keymove* self,
	moon_Text* text,
	int allow_jump
) {
	moon_Keymove_update_object(
		self,
		text,
		allow_jump,
		moon_Text_move,
		moon_Text_get_global_bounds
	);
}

void
moon_Keymove_update_TextWrite(
	moon_Keymove* self,
	moon_TextWrite* text,
	int allow_jump
) {
	moon_Keymove_update_object(
		self,
		text,
		allow_jump,
		moon_TextWrite_move,
		moon_TextWrite_get_global_bounds
	);
}

void
moon_Keymove_update_guiFpsCntr(
	moon_Keymove* self,
	moon_guiFpsCntr* cntr,
	int allow_jump
) {
	moon_Keymove_update_object(
		self,
		cntr,
		allow_jump,
		moon_guiFpsCntr_move,
		moon_guiFpsCntr_get_global_bounds
	);
}

void
moon_Keymove_update_Sprite(
	moon_Keymove* self,
	moon_Sprite* sprite,
	int allow_jump
) {
	moon_Keymove_update_object(
		self,
		sprite,
		allow_jump,
		moon_Sprite_move,
		moon_Sprite_get_global_bounds
	);
}

void
moon_Keymove_update_SpriteGroup(
	moon_Keymove* self,
	moon_SpriteGroup* sprites,
	int allow_jump
) {
	int is_up_pressed 		= moon_Keyboard_is_key_pressed(self->key_up);
	int is_down_pressed 	= moon_Keyboard_is_key_pressed(self->key_down);
	int is_left_pressed 	= moon_Keyboard_is_key_pressed(self->key_left);
	int is_right_pressed 	= moon_Keyboard_is_key_pressed(self->key_right);
	int is_jump_pressed 	= moon_Keyboard_is_key_pressed(self->key_jump);
	for (unsigned long i = 0UL; i < moon_SpriteGroup_length(sprites); i++) {
		moon_Sprite* sprite = moon_SpriteGroup_get(sprites, i);
		moon_Keymove_update_object_ex(
			self,
			sprite,
			allow_jump,
			is_left_pressed,
			is_right_pressed,
			is_up_pressed,
			is_down_pressed,
			is_jump_pressed,
			moon_Sprite_move,
			moon_Sprite_get_global_bounds
		);
	}
}

void
moon_Keymove_update_SlideShow(
	moon_Keymove* self,
	moon_SlideShow* animation,
	int allow_jump
) {
	moon_Keymove_update_object(
		self,
		animation,
		allow_jump,
		moon_SlideShow_move,
		moon_SlideShow_get_global_bounds
	);
}

void
moon_Keymove_update_SlideAnimation(
	moon_Keymove* self,
	moon_SlideAnimation* animation,
	int allow_jump
) {
	moon_Keymove_update_object(
		self,
		animation,
		allow_jump,
		moon_SlideAnimation_move,
		moon_SlideAnimation_get_global_bounds
	);
}

void
moon_Keymove_update_ConvexShape(
	moon_Keymove* self,
	moon_ConvexShape* shape,
	int allow_jump
) {
	moon_Keymove_update_object(
		self,
		shape,
		allow_jump,
		moon_ConvexShape_move,
		moon_ConvexShape_get_global_bounds
	);
}

void
moon_Keymove_update_CircleShape(
	moon_Keymove* self,
	moon_CircleShape* shape,
	int allow_jump
) {
	moon_Keymove_update_object(
		self,
		shape,
		allow_jump,
		moon_CircleShape_move,
		moon_CircleShape_get_global_bounds
	);
}

void
moon_Keymove_update_RectangleShape(
	moon_Keymove* self,
	moon_RectangleShape* shape,
	int allow_jump
) {
	moon_Keymove_update_object(
		self,
		shape,
		allow_jump,
		moon_RectangleShape_move,
		moon_RectangleShape_get_global_bounds
	);
}

void
moon_Keymove_set_key_up(
	moon_Keymove* self,
	int key
) {
	self->key_up = key;
}

void
moon_Keymove_set_key_down(
	moon_Keymove* self,
	int key
) {
	self->key_down = key;
}

void
moon_Keymove_set_key_right(
	moon_Keymove* self,
	int key
) {
	self->key_right = key;
}

void
moon_Keymove_set_key_left(
	moon_Keymove* self,
	int key
) {
	self->key_left = key;
}

void
moon_Keymove_set_key_jump(
	moon_Keymove* self,
	int key
) {
	self->key_jump = key;
}

void
moon_Keymove_set_up_speed(
	moon_Keymove* self,
	float speed
) {
	self->up_speed = -1.f * moon_utils_Abs(speed);
}

void
moon_Keymove_set_down_speed(
	moon_Keymove* self,
	float speed
) {
	self->down_speed = moon_utils_Abs(speed);
}

void
moon_Keymove_set_right_speed(
	moon_Keymove* self,
	float speed
) {
	self->right_speed = moon_utils_Abs(speed);
}

void
moon_Keymove_set_left_speed(
	moon_Keymove* self,
	float speed
) {
	self->left_speed = -1.f * moon_utils_Abs(speed);
}

void
moon_Keymove_set_jump_speed(
	moon_Keymove* self,
	float speed
) {
	moon_Jump_set_speed(self->jump_move, speed);
}

void
moon_Keymove_set_gravity_force(
	moon_Keymove* self,
	float speed
) {
	self->gravity_force = moon_utils_Abs(speed);
}

void
moon_Keymove_set_jump_height(
	moon_Keymove* self,
	float height
) {
	moon_Jump_set_height(self->jump_move, height);
}

int
moon_Keymove_get_key_up(const moon_Keymove* self) {
	return self->key_up;
}

int
moon_Keymove_get_key_down(const moon_Keymove* self) {
	return self->key_down;
}

int
moon_Keymove_get_key_right(const moon_Keymove* self) {
	return self->key_right;
}

int
moon_Keymove_get_key_left(const moon_Keymove* self) {
	return self->key_left;
}

int
moon_Keymove_get_key_jump(const moon_Keymove* self) {
	return self->key_jump;
}

int
moon_Keymove_get_hor_direction(const moon_Keymove* self) {
	return self->hor_direction;
}

int
moon_Keymove_get_ver_direction(const moon_Keymove* self) {
	return self->ver_direction;
}

float
moon_Keymove_get_up_speed(const moon_Keymove* self) {
	return self->up_speed;
}

float
moon_Keymove_get_down_speed(const moon_Keymove* self) {
	return self->down_speed;
}

float
moon_Keymove_get_left_speed(const moon_Keymove* self) {
	return self->left_speed;
}

float
moon_Keymove_get_right_speed(const moon_Keymove* self) {
	return self->right_speed;
}

float
moon_Keymove_get_jump_speed(const moon_Keymove* self) {
	return moon_Jump_get_speed(self->jump_move);
}

float
moon_Keymove_get_jump_height(const moon_Keymove* self) {
	return moon_Jump_get_height(self->jump_move);
}

float
moon_Keymove_get_gravity_force(const moon_Keymove* self) {
	return self->gravity_force;
}
