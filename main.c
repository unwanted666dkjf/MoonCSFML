#include <stdio.h>

#include <stdlib.h>



#include "headers/system/system.h"

#include "headers/window/window.h"

#include "headers/graphics/graphics.h"

#include "headers/audio/audio.h"

#include "headers/extras/extras.h"


#define NUM_EYE_TEXTURES (6)


int main() {
	moon_Destroyer* destroyer = moon_Destroyer_create(15UL);
	moon_DrawGroup* draw_group = moon_DrawGroup_create(1, 15UL);
	moon_Destroyer_push_back(destroyer, draw_group, moon_Destroyable_DrawGroup);

	moon_VideoMode desktop_mode = moon_VideoMode_get_desktop_mode();

	unsigned int fps 	= 60;
	unsigned int size 	= desktop_mode.height / 14;
	unsigned int wnd_w 	= size * 18, wnd_h = size * 11;
	float fps_k = 60.f / (float)((fps != 0) ? fps : 1.f);

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
	moon_RenderWindow_set_position(
		wnd,
		(desktop_mode.width - wnd_w) / 2,
		(desktop_mode.height - wnd_h) / 2
	);
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
	float anim_speed = .15f * fps_k;
	if (anim_speed <= 0.f) {
		anim_speed = 0.05f;
	}
	moon_Vector2f eye_size1 = {0.f, size * 2.f};
	moon_Vector2f eye_size2 = {0.f, size * 3.5f};
	moon_SlideAnimation* animation = moon_SlideAnimation_create(
		NUM_EYE_TEXTURES,			// initial size
		eye_size1.x, eye_size1.y,	// width, height
		0, 	 1,						// fixed_w, fixed_h
		anim_speed
	);
	moon_DrawGroup_push_back(draw_group, animation, moon_Draw_Groupable_SlideAnimation);
	moon_Destroyer_push_back(destroyer, animation, moon_Destroyable_SlideAnimation);
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
			moon_SlideAnimation_push_back(animation, eye_textures[eye_ind]);
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
	moon_Event* event = moon_Event_create();
	moon_RenderStates* states = moon_RenderStates_default();
	moon_Destroyer_push_back(destroyer, event, moon_Destroyable_Event);
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

		moon_Clock_wait(clock);
		float delta_seconds = moon_Time_as_seconds(
			moon_Clock_delta(clock)
		);
		float elapsed_seconds = moon_Time_as_seconds(
			moon_Clock_get_elapsed_time(clock)
		);

		moon_Event_reset(event);
		while (moon_RenderWindow_poll_event(wnd, event)) {
			int evt_type = moon_Event_get_type(event);
			if (evt_type == moon_Event_Type_Closed) {
				is_running = 0;
			} else if (evt_type == moon_Event_Type_KeyPressed) {
				int key = moon_Event_get_key_keycode(event);
				if (key == moon_Keyboard_Key_X) {
					moon_SpriteTransform_flip(luna, 1, 0);
				} else if (key == moon_Keyboard_Key_Y) {
					moon_SpriteTransform_flip(luna, 0, 1);
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
		moon_SlideAnimation_rotate(animation, eye_rot);

		if (elapsed_seconds >= 5.f) {
			moon_Clock_restart(clock);
			sprite_rot = 0.f;
			wnd_speed *= -1;
			moon_SpriteTransform_set_rotation(luna, sprite_rot);
			if (moon_random(0, 1)) {
				moon_SlideAnimation_reverse(animation);
			}
			if (moon_random(0, 1)) {
				moon_SlideAnimation_flip(animation, 1, 0);
				moon_SlideAnimation_resize(animation, eye_size1.x, eye_size1.y);
			} else {
				moon_SlideAnimation_flip(animation, 0, 1);
				moon_SlideAnimation_resize(animation, eye_size2.x, eye_size2.y);
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

		moon_SlideAnimation_update(animation);

		float eye_offset = eye_speed * delta_seconds;
		int eye_dir = moon_random(0, 3);
		switch (eye_dir) {
			case 0:
				moon_SlideAnimation_move(animation, eye_offset, 0.f);
				break;
			case 1:
				moon_SlideAnimation_move(animation, -eye_offset, 0.f);
				break;
			case 2:
				moon_SlideAnimation_move(animation, 0.f, eye_offset);
				break;
			default:
				moon_SlideAnimation_move(animation, 0.f, -eye_offset);
		}
		moon_FloatRect eye_bounds = moon_SlideAnimation_get_global_bounds(animation);

		moon_FloatRect luna_bounds = moon_Sprite_get_global_bounds(luna);
		moon_FloatRect intersection = moon_FloatRect_get_intersection(
			&eye_bounds,
			&luna_bounds
		);
		if (!moon_FloatRect_is_empty(&intersection)) {
			int corner = moon_random(0, 3);
			switch (corner) {
				case 0:
					moon_SlideAnimation_set_position(animation, 0, 0);
					break;
				case 1:
					moon_SlideAnimation_set_position(animation, wnd_w, 0);
					break;
				case 2:
					moon_SlideAnimation_set_position(animation, 0, wnd_h);
					break;
				default:
					moon_SlideAnimation_set_position(animation, wnd_w, wnd_h);
			}
		}

		eye_bounds = moon_SlideAnimation_get_global_bounds(animation);
		moon_Vector2f eye_pos = moon_in_area_pos(&eye_bounds, &wnd_rect);
		moon_SlideAnimation_set_position(animation, eye_pos.x, eye_pos.y);

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
	return 0;
}


// cmake .. -DCMAKE_BUILD_TYPE=Release
// cmake --build . --config Release --verbose -j $(nproc)
