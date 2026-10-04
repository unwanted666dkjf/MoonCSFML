#include <stdio.h>

#include <stdlib.h>



#include "headers/system/system.h"

#include "headers/window/window.h"

#include "headers/graphics/graphics.h"

#include "headers/audio/audio.h"

#include "headers/extras/extras.h"


#include "large_map.h"


enum {
	Direction_Left,
	Direction_Right
};


#define NUM_EYE_TEXTURES (6)


#define MAP_ROWS 	(11)

#define MAP_COLS 	(17)


const char* map[MAP_ROWS] = {
	"BBBBBBBBBBBBBBBBB",
	"BBBBBBBBBBBBBBBBB",
	"BB             BB",
	"BB             BB",
	"BB             BB",
	"BB             BB",
	"BB             BB",
	"BB             BB",
	"BB             BB",
	"BBBBBBBBBBBBBBBBB",
	"BBBBBBBBBBBBBBBBB"
};


void example();

void collisions_test();


int main() {
	example();
	return 0;
}


// cmake .. -DCMAKE_BUILD_TYPE=Release
// cmake --build . --config Release --verbose -j $(nproc)


void collisions_test() {
	moon_Destroyer* destroyer = moon_Destroyer_create(15UL);
	moon_SpriteGroup* sprites = moon_SpriteGroup_create(1, 100UL);
	moon_Destroyer_push_back(destroyer, sprites, moon_Destroyable_SpriteGroup);

	moon_VideoMode desktop_mode = moon_VideoMode_get_desktop_mode();

	unsigned int fps 	= 60;
	unsigned int size 	= moon_StandardSizes_get_size(&desktop_mode);
	unsigned int wnd_w 	= size * 18, wnd_h = size * 11;
	//	float fps_k = 60.f / (float)((fps != 0) ? fps : 1.f);
	float block_size = (float)size;

	const char* block_texturep = "./Assets/download.jpg";
	moon_Texture* block_texture = moon_Texture_create();
	moon_Destroyer_push_back(destroyer, block_texture, moon_Destroyable_Texture);
	if (!moon_Texture_load_from_file(block_texture, block_texturep)) {
		moon_printf("Failed to load texture from %s\n", block_texturep);
		goto cleanup;
	}
	moon_Vector2u block_texture_size = moon_Texture_get_size(block_texture);
	float block_kx = block_size / ((float)block_texture_size.x);
	float block_ky = block_size / ((float)block_texture_size.y);

	moon_FRectLst* rectangles = moon_FRectLst_create(15UL);
	moon_Destroyer_push_back(destroyer, rectangles, moon_Destroyable_FRectLst);

	int n_rows = 0, n_cols = 0;
	for (; LARGE_MAP[0][n_cols] != '\0'; n_cols++);
	for (; LARGE_MAP[n_rows] != NULL; n_rows++) {
		for (int col = 0; LARGE_MAP[n_rows][col] != '\0'; col++) {
			if (LARGE_MAP[n_rows][col] != 'B') {
				continue;
			}
			moon_Sprite* block = moon_Sprite_create(block_texture);
			moon_Destroyer_push_back(destroyer, block, moon_Destroyable_Sprite);
			moon_Sprite_set_scale(block, block_kx, block_ky);
			moon_Sprite_set_position(block, col * size, n_rows * size);
			moon_SpriteGroup_push_back(sprites, block);

			moon_FloatRect sprite_bounds = moon_Sprite_get_global_bounds(block);
			moon_FRectLst_push_back(rectangles, &sprite_bounds);
		}
	}

	moon_Color rect_clr = moon_Colors_LightSteel(255);
	float shape_w = size * 2.f, shape_h = size * 3.f;
	moon_RectangleShape* rect_shape = moon_RectangleShape_create(
		shape_w, shape_h,
		&rect_clr
	);
	moon_Destroyer_push_back(destroyer, rect_shape, moon_Destroyable_RectangleShape);
	float shape_left 	= ((float)(n_cols) * block_size - shape_w) * .5f;
	float shape_top		= ((float)(n_rows) * block_size - shape_h) * .5f;
	moon_RectangleShape_set_position(
		rect_shape,
		shape_left,
		shape_top
	);
	float rect_speed   = 3.f * block_size;
	float rect_gravity = 4.f * block_size;
	int shape_direction = Direction_Left;
	float colis_distancex = shape_w + shape_w * 2.f;
	float colis_distancey = shape_h + shape_h * 2.f;
	float rlast_bottom = shape_top + shape_h;
	moon_Jump* rect_jump = moon_Jump_create(
		rect_gravity + block_size * 3.5f,
		shape_h * 3.f
	);
	moon_Destroyer_push_back(destroyer, rect_jump, moon_Destroyable_Jump);

	float view_w = (float)wnd_w;
	float view_h = (float)wnd_h;

	moon_View left_view 	= moon_View_create();
	moon_View right_view 	= moon_View_create();

	moon_View_set_size(&left_view, view_w, view_h);
	moon_View_set_size(&right_view, view_w, view_h);

	float view_offset = block_size * 5.f;
	moon_View_set_center(&left_view,  shape_left - view_offset, shape_top);
	moon_View_set_center(&right_view, shape_left + view_offset + shape_w, shape_top);

	moon_Image* wnd_icon = moon_Image_create();
	moon_Destroyer_push_back(destroyer, wnd_icon, moon_Destroyable_Image);
	if (!moon_Image_load(wnd_icon, "./Assets/luna_icon.png")) {
		moon_printf("Could not load icon!\n");
		goto cleanup;
	}
	moon_Vector2u icon_size = moon_Image_get_size(wnd_icon);

	moon_RenderWindow* wnd = moon_RenderWindow_createA(
		wnd_w, wnd_h,
		desktop_mode.bits_per_pixel,
		"MoonCSFML",
		moon_Window_Style_Titlebar
			| moon_Window_Style_Close
	);
	moon_Destroyer_push_back(destroyer, wnd, moon_Destroyable_RenderWindow);
	unsigned int wnd_x = (unsigned int)((desktop_mode.width - wnd_w) * .5f);
	unsigned int wnd_y = (unsigned int)((desktop_mode.height - wnd_h) * .5f);
	moon_RenderWindow_set_position(wnd, wnd_x, wnd_y);
	moon_RenderWindow_set_framerate_limit(wnd, fps);
	moon_RenderWindow_set_icon(
		wnd,
		icon_size.x, icon_size.y,
		wnd_icon
	);

	moon_Color bg_clr = moon_Colors_DarkPurple(255);
	moon_Event event;

	moon_RenderStates* states = moon_RenderStates_default();
	moon_Destroyer_push_back(destroyer, states, moon_Destroyable_RenderStates);

	moon_Font* font = moon_Font_create();
	const char* fontp = "./Assets/monsters.otf";
	moon_Destroyer_push_back(destroyer, font, moon_Destroyable_Font);
	if (!moon_Font_load(font, fontp)) {
		moon_printf("Could not load font from %s\n", fontp);
		goto cleanup;
	}
	unsigned int fnt_size = (unsigned int)(size * 1.25f);
	moon_Color cntr_color = moon_Colors_Black(255);
	moon_guiFpsCntr* fps_cntr = moon_guiFpsCntr_create_ex(
		2, .15f, font, fnt_size, &cntr_color
	);
	moon_Destroyer_push_back(destroyer, fps_cntr, moon_Destroyable_guiFpsCntr);
	moon_guiFpsCntr_set_position(fps_cntr, wnd_w - fnt_size, 0.f);
	moon_guiFpsCntr_set_style(fps_cntr, moon_Text_Style_Bold);

	moon_Clock* clock = moon_Clock_create();
	moon_Destroyer_push_back(destroyer, clock, moon_Destroyable_Clock);
	moon_Clock_start(clock);
	moon_guiFpsCntr_start(fps_cntr);
	int is_running = moon_RenderWindow_is_open(wnd);
	while (is_running) {
		moon_Event_reset(&event);
		while (moon_RenderWindow_poll_event(wnd, &event)) {
			if (event.type == moon_Event_Type_Closed) {
				is_running = 0;
			}
		}

		moon_RenderWindow_clear(wnd, &bg_clr);

		moon_SpriteGroup_draw(sprites, wnd, states);

		moon_RectangleShape_draw(rect_shape, wnd, states);

		moon_guiFpsCntr_draw(fps_cntr, wnd, states);

		moon_RenderWindow_display(wnd);

		moon_Vector2f shape_start = moon_RectangleShape_get_position(rect_shape);

		moon_Clock_wait(clock);
		float delta_seconds = moon_Time_as_seconds(
			moon_Clock_delta(clock)
		);

		int last_direction = shape_direction;
		if (moon_Keyboard_is_key_pressed(moon_Keyboard_Key_D)) {
			if (rect_speed < 0.f) {
				rect_speed *= -1.f;
			}
			shape_direction = Direction_Right;
			moon_RectangleShape_move(rect_shape, rect_speed * delta_seconds, 0.f);
		} else if (moon_Keyboard_is_key_pressed(moon_Keyboard_Key_A)) {
			if (rect_speed > 0.f) {
				rect_speed *= -1.f;
			}
			shape_direction = Direction_Left;
			moon_RectangleShape_move(rect_shape, rect_speed * delta_seconds, 0.f);
		}

		moon_RectangleShape_move(rect_shape, 0.f, rect_gravity * delta_seconds);

		moon_FloatRect rrect = moon_RectangleShape_get_global_bounds(rect_shape);
		moon_Vector2f col_offsets = moon_Collisions_rectangles_collision_many(
			&rrect,
			rectangles,
			colis_distancex,	// distance x
			colis_distancey,	// distance y
			"vh"
		);
		float rcur_bottom = rrect.top + rrect.height;
		if (rcur_bottom == rlast_bottom) {								// on ground
			if (moon_Keyboard_is_key_pressed(moon_Keyboard_Key_W)) {
				moon_Jump_start(rect_jump, rcur_bottom);
			}
		}
		rlast_bottom = rcur_bottom;
		float jump_offset = moon_Jump_update(rect_jump);
		moon_RectangleShape_move(
			rect_shape,
			col_offsets.x,
			col_offsets.y + jump_offset
		);

		moon_guiFpsCntr_update(fps_cntr);

		moon_Vector2f shape_end = moon_RectangleShape_get_position(rect_shape);

		float shape_offsetx = shape_end.x - shape_start.x;
		float shape_offsety = shape_end.y - shape_start.y;
		moon_View_move(&left_view, shape_offsetx, shape_offsety);
		moon_View_move(&right_view, shape_offsetx, shape_offsety);
		if (shape_direction == Direction_Left) {
			moon_RenderWindow_set_view(wnd, &left_view);
		} else {
			moon_RenderWindow_set_view(wnd, &right_view);
		}

		if (shape_direction != last_direction) {
			moon_Vector2f cntr_size = moon_guiFpsCntr_get_size(fps_cntr);
			float cntr_left, cntr_top;
			if (shape_direction == Direction_Left) {
				cntr_top  = left_view.center.y - left_view.size.y * .5f;
				cntr_left = left_view.center.x + left_view.size.x * .5f;
			} else {
				cntr_top  = right_view.center.y - right_view.size.y * .5f;
				cntr_left = right_view.center.x + right_view.size.x * .5f;
			}
			moon_guiFpsCntr_set_position(
				fps_cntr,
				cntr_left - cntr_size.x,
				cntr_top + cntr_size.y
			);
		}
		moon_guiFpsCntr_move(fps_cntr, shape_offsetx, shape_offsety);

	}
	moon_RenderWindow_close(wnd);

	goto cleanup;
	cleanup:
		moon_Destroyer_destroy(destroyer);
}


void example() {
	moon_Destroyer* destroyer = moon_Destroyer_create(15UL);
	moon_DrawGroup* draw_group = moon_DrawGroup_create(1, 15UL);
	moon_Destroyer_push_back(destroyer, draw_group, moon_Destroyable_DrawGroup);

	moon_VideoMode desktop_mode = moon_VideoMode_get_desktop_mode();

	unsigned int fps 	= 60;
	unsigned int size 	= moon_StandardSizes_get_size(&desktop_mode);
	unsigned int wnd_w 	= size * 18, wnd_h = size * 11;
//	float fps_k = 60.f / (float)((fps != 0) ? fps : 1.f);

	moon_Music* mus = moon_Music_create();
	moon_Destroyer_push_back(destroyer, mus, moon_Destroyable_Music);
	if (!moon_Music_open(mus, "./Assets/nasty_paradise.ogg")) {
		moon_printf("Could not load music!\n");
		goto cleanup;
	}

	moon_Font* font = moon_Font_create();
	moon_Destroyer_push_back(destroyer, font, moon_Destroyable_Font);
	if (!moon_Font_load(font, "./Assets/monsters.otf")) {
		moon_printf("Could not load font!\n");
		goto cleanup;
	}

	moon_Texture* luna_texture = moon_Texture_create();
	moon_Destroyer_push_back(destroyer, luna_texture, moon_Destroyable_Texture);
	if (!moon_Texture_load_from_file(luna_texture, "./Assets/Luna.png")) {
		moon_printf("Could not load texture!\n");
		goto cleanup;
	}
	moon_Vector2u ltexture_size = moon_Texture_get_size(luna_texture);

	moon_Image* wnd_icon = moon_Image_create();
	moon_Destroyer_push_back(destroyer, wnd_icon, moon_Destroyable_Image);
	if (!moon_Image_load(wnd_icon, "./Assets/luna_icon.png")) {
		moon_printf("Could not load icon!\n");
		goto cleanup;
	}
	moon_Vector2u icon_size = moon_Image_get_size(wnd_icon);

	moon_RenderWindow* wnd = moon_RenderWindow_createA(
		wnd_w, wnd_h,
		desktop_mode.bits_per_pixel,
		"MoonCSFML",
		moon_Window_Style_Titlebar
			| moon_Window_Style_Close
	);
	moon_Destroyer_push_back(destroyer, wnd, moon_Destroyable_RenderWindow);
	unsigned int wnd_x = (unsigned int)((desktop_mode.width - wnd_w) * .5f);
	unsigned int wnd_y = (unsigned int)((desktop_mode.height - wnd_h) * .5f);
	moon_RenderWindow_set_position(wnd, wnd_x, wnd_y);
	moon_RenderWindow_set_framerate_limit(wnd, fps);
	moon_RenderWindow_set_icon(
		wnd,
		icon_size.x, icon_size.y,
		wnd_icon
	);
#ifdef _WIN32
	moon_Winstuff_set_wnd_topmost(wnd);
	moon_Winstuff_set_wnd_alpha(wnd, (int)(255 * .8f));
#endif
	float wnd_speed = size * 6.f;
	moon_FloatRect wnd_rect = {0.f, 0.f, wnd_w, wnd_h};

	moon_Color moon_clr = moon_Colors_BloodRed(255);
	moon_CircleShape* moon = moon_CircleShape_create_ex(
		size * 1.5f,
		moon_CircleShape_DefaultPointCount,
		&moon_clr,
		0.f, 0.f
	);
	moon_DrawGroup_push_back(draw_group, moon, moon_Draw_Groupable_CircleShape);
	moon_Destroyer_push_back(destroyer, moon, moon_Destroyable_CircleShape);

	moon_Sprite* luna = moon_Sprite_create(luna_texture);
	moon_DrawGroup_push_back(draw_group, luna, moon_Draw_Groupable_Sprite);
	moon_Destroyer_push_back(destroyer, luna, moon_Destroyable_Sprite);
	float luna_h = 8.f * size;
	float ksize = luna_h / ltexture_size.y;
	moon_Sprite_set_scale(luna, ksize, ksize);
	moon_Vector2f luna_size = moon_Sprite_get_size(luna);
	moon_Sprite_set_position(
		luna,
		(wnd_w - luna_size.x) / 2.f,
		(wnd_h - luna_size.y) / 2.f
	);
	moon_Angle sprite_rot = 0.f;

	moon_Texture* eye_textures[NUM_EYE_TEXTURES];
	moon_Vector2f eye_size1 = {0.f, size * 2.f};
	moon_Vector2f eye_size2 = {0.f, size * 3.5f};
/**
	float anim_speed = .15f * fps_k;
	if (anim_speed <= 0.f) {
		anim_speed = 0.05f;
	}
	moon_SlideAnimation* animation = moon_SlideAnimation_create(
		NUM_EYE_TEXTURES,			// initial size
		eye_size1.x, eye_size1.y,	// width, height
		0, 	 1,						// fixed_w, fixed_h
		anim_speed
	);
	moon_DrawGroup_push_back(draw_group, animation, moon_Draw_Groupable_SlideAnimation);
	moon_Destroyer_push_back(destroyer, animation, moon_Destroyable_SlideAnimation);
*/
	moon_SlideShow* animation = moon_SlideShow_create(
		NUM_EYE_TEXTURES,			// initial size
		eye_size1.x, eye_size1.y,	// width, height
		0, 	 1,						// fixed_w, fixed_h
		.15f						// seconds per frame
	);
	moon_DrawGroup_push_back(draw_group, animation, moon_Draw_Groupable_SlideShow);
	moon_Destroyer_push_back(destroyer, animation, moon_Destroyable_SlideShow);
	unsigned long eye_ind = 0UL;
	const char* textures_path = "./Assets/LukasEye";
	moon_Pathgen* pathgen = moon_Pathgen_create(textures_path);
	moon_Destroyer_push_back(destroyer, pathgen, moon_Destroyable_Pathgen);
	while (moon_Pathgen_has_next(pathgen)) {
		char* rel_path = moon_Pathgen_next(pathgen);
		char* texture_path = moon_Path_concat(
			textures_path,
			rel_path,
			moon_Utils_StringLengthUnknown,
			moon_Utils_StringLengthUnknown
		);
		eye_textures[eye_ind] = moon_Texture_create();
		moon_Destroyer_push_back(destroyer, eye_textures[eye_ind], moon_Destroyable_Texture);
		int load_res = moon_Texture_load_from_file(
			eye_textures[eye_ind],
			texture_path
		);
		moon_free(rel_path);
		moon_free(texture_path);
		if (!load_res) {
			moon_printf(
				"Failed to load texture for eye animation."
				"Source dir: %s\n", textures_path
			);
			goto cleanup;
		} else {
//			moon_SlideAnimation_push_back(animation, eye_textures[eye_ind]);
			moon_SlideShow_push_back(animation, eye_textures[eye_ind]);
			eye_ind++;
		}
	}
	float eye_speed = 3.f * size;
	moon_Angle eye_rot = 0.f;

	moon_Color text_color = moon_Colors_White(255);
	unsigned int fnt_size = (unsigned int)(size * 1.25f);
	moon_TextWrite* text = moon_TextWrite_create(
		moon_TextWrite_DefaultTypingSpeed,
		font,
		fnt_size
	);
	moon_DrawGroup_push_back(draw_group, text, moon_Draw_Groupable_TextWrite);
	moon_Destroyer_push_back(destroyer, text, moon_Destroyable_TextWrite);
	moon_TextWrite_set_textA(text, "You are not safe");
	moon_TextWrite_set_style(text, moon_Text_Style_StrikeThrough);
	moon_TextWrite_set_fill_color(text, &text_color);
	moon_Vector2f text_size = moon_TextWrite_get_size(text);
	moon_TextWrite_set_position(
		text,
		(wnd_w - text_size.x) / 2.f,
		wnd_h - fnt_size * 2.f
	);

	moon_Color cntr_color = moon_Colors_MetallicGold(255);
	moon_guiFpsCntr* fps_cntr = moon_guiFpsCntr_create_ex(
		2, .15f, font, fnt_size, &cntr_color
	);
	moon_DrawGroup_push_back(draw_group, fps_cntr, moon_Draw_Groupable_guiFpsCntr);
	moon_Destroyer_push_back(destroyer, fps_cntr, moon_Destroyable_guiFpsCntr);
	moon_guiFpsCntr_set_position(fps_cntr, wnd_w - fnt_size, 0.f);
	moon_guiFpsCntr_set_style(fps_cntr, moon_Text_Style_Bold);

	moon_Color bg_clr = moon_Colors_DarkPurple(255);
	moon_Event event;

	moon_RenderStates* states = moon_RenderStates_default();
	moon_Destroyer_push_back(destroyer, states, moon_Destroyable_RenderStates);

	moon_Music_set_loop(mus, 1);
	moon_Music_set_volume(mus, 100);
	moon_Music_play(mus);

	moon_Clock* clock = moon_Clock_create();
	moon_Destroyer_push_back(destroyer, clock, moon_Destroyable_Clock);
	moon_Clock_start(clock);
	moon_TextWrite_start(text);
	moon_guiFpsCntr_start(fps_cntr);
	int is_running = moon_RenderWindow_is_open(wnd);
	while (is_running) {

		float elapsed_seconds = moon_Time_as_seconds(
			moon_Clock_wait(clock)
		);
		float delta_seconds = moon_Time_as_seconds(
			moon_Clock_delta(clock)
		);

		moon_Event_reset(&event);
		while (moon_RenderWindow_poll_event(wnd, &event)) {
			if (event.type == moon_Event_Type_Closed) {
				is_running = 0;
			} else if (event.type == moon_Event_Type_KeyPressed) {
				int key = event.evt.key.keycode;
				if (key == moon_Keyboard_Key_X) {
					moon_SpriteTransform_flip(luna, 1, 0);
				} else if (key == moon_Keyboard_Key_Y) {
					moon_SpriteTransform_flip(luna, 0, 1);
				}
			} else if (event.type == moon_Event_Type_MouseButtonPressed) {
				int button = event.evt.mouse_button.button;
				if (button == moon_Mouse_Button_Left) {
					moon_RenderWindow_set_position(wnd, 0, 0);
				} else if (button == moon_Mouse_Button_Right) {
					moon_RenderWindow_set_position(wnd, wnd_x, wnd_y);
				}
			}
		}

		moon_RenderWindow_clear(wnd, &bg_clr);

		moon_DrawGroup_draw(draw_group, wnd, states);

		moon_RenderWindow_display(wnd);

		if (sprite_rot > 360.f || sprite_rot < -360.f) {
			sprite_rot = 0.f;
		}
		if (eye_rot > 360.f || eye_rot < -360.f) {
			eye_rot = 0.f;
		}
		if (elapsed_seconds < 3.f) {
			eye_rot		= elapsed_seconds;
			sprite_rot 	= -elapsed_seconds;
		} else {
			eye_rot 	= -elapsed_seconds;
			sprite_rot 	= elapsed_seconds;
		}
		moon_SpriteTransform_rotate(luna, sprite_rot);
//		moon_SlideAnimation_rotate(animation, eye_rot);
		moon_SlideShow_rotate(animation, eye_rot);

		if (elapsed_seconds >= 5.f) {
			moon_Clock_restart(clock);
			sprite_rot = 0.f;
			wnd_speed *= -1;
			moon_SpriteTransform_set_rotation(luna, sprite_rot);
			if (moon_random(0, 1)) {
//				moon_SlideAnimation_reverse(animation);
				moon_SlideShow_reverse(animation);
			}
			if (moon_random(0, 1)) {
//				moon_SlideAnimation_flip(animation, 1, 0);
//				moon_SlideAnimation_resize(animation, eye_size1.x, eye_size1.y);
				moon_SlideShow_flip(animation, 1, 0);
				moon_SlideShow_resize(animation, eye_size1.x, eye_size1.y);
			} else {
//				moon_SlideAnimation_flip(animation, 0, 1);
//				moon_SlideAnimation_resize(animation, eye_size2.x, eye_size2.y);
				moon_SlideShow_flip(animation, 0, 1);
				moon_SlideShow_resize(animation, eye_size2.x, eye_size2.y);
			}
		}

		int wnd_dx = (int)(delta_seconds * wnd_speed);
		if (wnd_dx == 0) {
			if (elapsed_seconds >= 3.f) {
				wnd_dx = -1;
			} else {
				wnd_dx = 1;
			}
		}
		moon_RenderWindow_move(wnd, wnd_dx, 0);

//		moon_SlideAnimation_update(animation);
		moon_SlideShow_update(animation);

		float eye_offset = eye_speed * delta_seconds;
		int eye_dir = moon_random(0, 3);
		switch (eye_dir) {
			case 0:
//				moon_SlideAnimation_move(animation, eye_offset, 0.f);
				moon_SlideShow_move(animation, eye_offset, 0.f);
				break;
			case 1:
//				moon_SlideAnimation_move(animation, -eye_offset, 0.f);
				moon_SlideShow_move(animation, -eye_offset, 0.f);
				break;
			case 2:
//				moon_SlideAnimation_move(animation, 0.f, eye_offset);
				moon_SlideShow_move(animation, 0.f, eye_offset);
				break;
			default:
//				moon_SlideAnimation_move(animation, 0.f, -eye_offset);
				moon_SlideShow_move(animation, 0.f, -eye_offset);
		}
//		moon_FloatRect eye_bounds = moon_SlideAnimation_get_global_bounds(animation);
		moon_FloatRect eye_bounds = moon_SlideShow_get_global_bounds(animation);

		moon_FloatRect luna_bounds = moon_Sprite_get_global_bounds(luna);
		moon_FloatRect intersection = moon_FloatRect_get_intersection(
			&eye_bounds,
			&luna_bounds
		);
		if (!moon_FloatRect_is_empty(&intersection)) {
			int corner = moon_random(0, 3);
			switch (corner) {
				case 0:
//					moon_SlideAnimation_set_position(animation, 0, 0);
					moon_SlideShow_set_position(animation, 0, 0);
					break;
				case 1:
//					moon_SlideAnimation_set_position(animation, wnd_w, 0);
					moon_SlideShow_set_position(animation, wnd_w, 0);
					break;
				case 2:
//					moon_SlideAnimation_set_position(animation, 0, wnd_h);
					moon_SlideShow_set_position(animation, 0, wnd_h);
					break;
				default:
//					moon_SlideAnimation_set_position(animation, wnd_w, wnd_h);
					moon_SlideShow_set_position(animation, wnd_w, wnd_h);
			}
		}

//		eye_bounds = moon_SlideAnimation_get_global_bounds(animation);
		eye_bounds = moon_SlideShow_get_global_bounds(animation);
		moon_Vector2f eye_pos = moon_in_area_pos(&eye_bounds, &wnd_rect);
//		moon_SlideAnimation_set_position(animation, eye_pos.x, eye_pos.y);
		moon_SlideShow_set_position(animation, eye_pos.x, eye_pos.y);

		moon_TextWrite_update(text);
		moon_guiFpsCntr_update(fps_cntr);

		if (!moon_TextWrite_is_running(text)) {
			moon_TextWrite_restart(text);
		}

	}
	moon_RenderWindow_close(wnd);

	goto cleanup;
	cleanup:
		moon_Destroyer_destroy(destroyer);
}
