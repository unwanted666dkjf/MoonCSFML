#include <wchar.h>

#include <vector>



#include "../../headers/system/moon_utils.h"

#include "../../headers/system/moon_clock.h"


#include "../../headers/window/moon_event.h"

#include "../../headers/window/moon_video_modes_gen.h"


#include "../../headers/graphics/moon_font.h"

#include "../../headers/graphics/moon_text.h"

#include "../../headers/graphics/moon_image.h"

#include "../../headers/graphics/moon_texture.h"

#include "../../headers/graphics/moon_convex_shape.h"

#include "../../headers/graphics/moon_circle_shape.h"

#include "../../headers/graphics/moon_rectangle_shape.h"

#include "../../headers/graphics/moon_vertex_array.h"

#include "../../headers/graphics/moon_vertex_buffer.h"

#include "../../headers/graphics/moon_render_states.h"

#include "../../headers/graphics/moon_render_window.h"

#include "../../headers/graphics/VectorUtils.hpp"


#include "../../headers/audio/moon_music.h"

#include "../../headers/audio/moon_sound.h"

#include "../../headers/audio/moon_sound_buffer.h"

#include "../../headers/audio/moon_sound_buffer_recorder.h"

#include "../../headers/audio/moon_audio_capture_devices.h"


#include "../../headers/extras/moon_file.h"

#include "../../headers/extras/moon_filelines.h"

#include "../../headers/extras/moon_pathgen.h"

#include "../../headers/extras/moon_destroyer.h"

#include "../../headers/extras/moon_text_write.h"

#include "../../headers/extras/moon_draw_group.h"

#include "../../headers/extras/moon_destroyable.h"

#include "../../headers/extras/moon_gui_fpscntr.h"

#include "../../headers/extras/moon_slide_animation.h"


struct moon_Destroyer {
	std::vector<moon_Destroyable> victims;
};


static void
moon_Destroyer_kill(moon_Destroyable* victim);


moon_Destroyer*
moon_Destroyer_create(unsigned long initial_capacity) {
	moon_Destroyer* self = new moon_Destroyer();
	self->victims.reserve(initial_capacity + 1UL);
	return self;
}

void
moon_Destroyer_destroy(moon_Destroyer* self) {
	moon_Destroyer_annihilate(self);
	delete self;
}

int
moon_Destroyer_is_empty(const moon_Destroyer* self) {
	return self->victims.empty();
}

int
moon_Destroyer_resize(
	moon_Destroyer* self,
	unsigned long new_size
) {
	if (new_size <= self->victims.size()) {
		return 0;
	}
	self->victims.resize(new_size);
	return 1;
}

int
moon_Destroyer_reserve(
	moon_Destroyer* self,
	unsigned long capacity
) {
	if (capacity <= self->victims.capacity()) {
		return 0;
	}
	self->victims.reserve(capacity);
	return 1;
}

unsigned long
moon_Destroyer_size(const moon_Destroyer* self) {
	return self->victims.capacity();
}

unsigned long
moon_Destroyer_length(const moon_Destroyer* self) {
	return self->victims.size();
}

void
moon_Destroyer_clear(moon_Destroyer* self) {
	self->victims.clear();
}

void
moon_Destroyer_annihilate(moon_Destroyer* self) {
	while (!self->victims.empty()) {
		moon_Destroyable* victim = &self->victims.back();
		moon_Destroyer_kill(victim);
		self->victims.pop_back();
	}
}

void
moon_Destroyer_reverse(moon_Destroyer* self) {
	moon_vector_reverse<moon_Destroyable>(self->victims);
}

void
moon_Destroyer_push_back(
	moon_Destroyer* self,
	void* destroyable_body,
	int destroyable_type
) {
	self->victims.push_back(
		{destroyable_type, destroyable_body}
	);
}

void
moon_Destroyer_push_front(
	moon_Destroyer* self,
	void* destroyable_body,
	int destroyable_type
) {
	moon_vector_insert<moon_Destroyable>(
		self->victims,
		0UL,
		{destroyable_type, destroyable_body}
	);
}


void
moon_Destroyer_kill(moon_Destroyable* victim) {
	if (!victim || !victim->body) {
		return;
	}
	void* body = victim->body;
	switch (victim->type) {
		case moon_Destroyable_CharPtr:
		case moon_Destroyable_WCharPtr:
			moon_free(body);
			break;
		case moon_Destroyable_Clock:
			moon_Clock_destroy(static_cast<moon_Clock*>(body));
			break;

		case moon_Destroyable_Event:
			moon_Event_destroy(static_cast<moon_Event*>(body));
			break;
		case moon_Destroyable_VideoModesGen:
			moon_VideoModesGen_destroy(static_cast<moon_VideoModesGen*>(body));
			break;

		case moon_Destroyable_Font:
			moon_Font_destroy(static_cast<moon_Font*>(body));
			break;
		case moon_Destroyable_Text:
			moon_Text_destroy(static_cast<moon_Text*>(body));
			break;
		case moon_Destroyable_Image:
			moon_Image_destroy(static_cast<moon_Image*>(body));
			break;
		case moon_Destroyable_Shader:
			moon_Shader_destroy(static_cast<moon_Shader*>(body));
			break;
		case moon_Destroyable_Sprite:
			moon_Sprite_destroy(static_cast<moon_Sprite*>(body));
			break;
		case moon_Destroyable_Texture:
			moon_Texture_destroy(static_cast<moon_Texture*>(body));
			break;
		case moon_Destroyable_ConvexShape:
			moon_ConvexShape_destroy(static_cast<moon_ConvexShape*>(body));
			break;
		case moon_Destroyable_CircleShape:
			moon_CircleShape_destroy(static_cast<moon_CircleShape*>(body));
			break;
		case moon_Destroyable_RectangleShape:
			moon_RectangleShape_destroy(static_cast<moon_RectangleShape*>(body));
			break;
		case moon_Destroyable_VertexArray:
			moon_VertexArray_destroy(static_cast<moon_VertexArray*>(body));
			break;
		case moon_Destroyable_VertexBuffer:
			moon_VertexBuffer_destroy(static_cast<moon_VertexBuffer*>(body));
			break;
		case moon_Destroyable_RenderStates:
			moon_RenderStates_destroy(static_cast<moon_RenderStates*>(body));
			break;
		case moon_Destroyable_RenderWindow:
			moon_RenderWindow_destroy(static_cast<moon_RenderWindow*>(body));
			break;

		case moon_Destroyable_Music:
			moon_Music_destroy(static_cast<moon_Music*>(body));
			break;
		case moon_Destroyable_Sound:
			moon_Sound_destroy(static_cast<moon_Sound*>(body));
			break;
		case moon_Destroyable_SoundBuffer:
			moon_SoundBuffer_destroy(static_cast<moon_SoundBuffer*>(body));
			break;
		case moon_Destroyable_SoundBufferRecorder:
			moon_SoundBufferRecorder_destroy(static_cast<moon_SoundBufferRecorder*>(body));
			break;
		case moon_Destroyable_AudioCaptureDevices:
			moon_AudioCaptureDevices_destroy(static_cast<moon_AudioCaptureDevices*>(body));
			break;

		case moon_Destroyable_Destroyer:
			moon_Destroyer_destroy(static_cast<moon_Destroyer*>(body));
			break;
		case moon_Destroyable_Pathgen:
			moon_Pathgen_destroy(static_cast<moon_Pathgen*>(body));
			break;
		case moon_Destroyable_File:
			moon_File_close(static_cast<moon_File*>(body));
			break;
		case moon_Destroyable_Filelines:
			moon_Filelines_close(static_cast<moon_Filelines*>(body));
			break;
		case moon_Destroyable_TextWrite:
			moon_TextWrite_destroy(static_cast<moon_TextWrite*>(body));
			break;
		case moon_Destroyable_DrawGroup:
			moon_DrawGroup_destroy(static_cast<moon_DrawGroup*>(body));
			break;
		case moon_Destroyable_guiFpsCntr:
			moon_guiFpsCntr_destroy(static_cast<moon_guiFpsCntr*>(body));
			break;
		case moon_Destroyable_SlideAnimation:
			moon_SlideAnimation_destroy(static_cast<moon_SlideAnimation*>(body));
			break;
		default:
			moon_free(body);
	}
	victim->body = NULL;
}
