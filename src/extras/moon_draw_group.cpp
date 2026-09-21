#include <vector>



#include "../../headers/extras/moon_draw_group.h"

#include "../../headers/extras/moon_draw_groupable.h"

#include "../../headers/extras/GenericDraw.hpp"

#include "../../headers/extras/TextWriteStruct.hpp"

#include "../../headers/extras/guiFpsCntrStruct.hpp"

#include "../../headers/extras/SlideAnimationStruct.hpp"


#include "../../headers/graphics/VectorUtils.hpp"

#include "../../headers/graphics/TextStruct.hpp"

#include "../../headers/graphics/SpriteStruct.hpp"

#include "../../headers/graphics/ConvexShapeStruct.hpp"

#include "../../headers/graphics/CircleShapeStruct.hpp"

#include "../../headers/graphics/RectangleShapeStruct.hpp"


struct moon_DrawGroup {

	moon_DrawGroup(
		int v_check_visibility,
		unsigned long v_initial_capacity
	);


	int check_visibility;
	std::vector<moon_DrawGroupable> drawables;

};


static void
moon_DrawGroupable_draw(
	const moon_DrawGroupable& drawable,
	moon_RenderWindow* wnd,
	const moon_RenderStates* states,
	const int& check_visibility
);


moon_DrawGroup*
moon_DrawGroup_create(
	int check_visibility,
	unsigned long initial_capacity
) {
	return new moon_DrawGroup(
		check_visibility,
		initial_capacity
	);
}

void
moon_DrawGroup_destroy(moon_DrawGroup* self) {
	delete self;
}

int
moon_DrawGroup_is_empty(const moon_DrawGroup* self) {
	return self->drawables.empty();
}

int
moon_DrawGroup_is_check_enabled(const moon_DrawGroup* self) {
	return self->check_visibility;
}

int
moon_DrawGroup_resize(
	moon_DrawGroup* self,
	unsigned long new_size
) {
	if (new_size <= self->drawables.size()) {
		return 0;
	}
	self->drawables.resize(new_size);
	return 1;
}

int
moon_DrawGroup_reserve(
	moon_DrawGroup* self,
	unsigned long capacity
) {
	if (capacity <= self->drawables.capacity()) {
		return 0;
	}
	self->drawables.reserve(capacity);
	return 1;
}

unsigned long
moon_DrawGroup_size(const moon_DrawGroup* self) {
	return self->drawables.capacity();
}

unsigned long
moon_DrawGroup_length(const moon_DrawGroup* self) {
	return self->drawables.size();
}

void
moon_DrawGroup_clear(moon_DrawGroup* self) {
	self->drawables.clear();
}

void
moon_DrawGroup_reverse(moon_DrawGroup* self) {
	moon_vector_reverse<moon_DrawGroupable>(self->drawables);
}

void
moon_DrawGroup_set_check_enabled(
	moon_DrawGroup* self,
	int check_visibility
) {
	self->check_visibility = check_visibility;
}

void
moon_DrawGroup_remove(
	moon_DrawGroup* self,
	unsigned long index
) {
	moon_vector_remove<moon_DrawGroupable>(self->drawables, index);
}

void
moon_DrawGroup_draw(
	const moon_DrawGroup* self,
	moon_RenderWindow* wnd,
	const moon_RenderStates* states
) {
	for (unsigned long i = 0UL; i < self->drawables.size(); i++) {
		moon_DrawGroupable_draw(
			self->drawables[i],
			wnd,
			states,
			self->check_visibility
		);
	}
}

void
moon_DrawGroup_push_back(
	moon_DrawGroup* self,
	const void* groupable,
	int groupable_type
) {
	self->drawables.push_back(
		{groupable_type, groupable}
	);
}

void
moon_DrawGroup_push_front(
	moon_DrawGroup* self,
	const void* groupable,
	int groupable_type
) {
	moon_vector_insert<moon_DrawGroupable>(
		self->drawables, 0UL,
		{groupable_type, groupable}
	);
}

void
moon_DrawGroup_extend(
	moon_DrawGroup* self,
	const moon_DrawGroup* other
) {
	moon_vector_extend<moon_DrawGroupable>(
		self->drawables,
		other->drawables
	);
}

moon_DrawGroup*
moon_DrawGroup_get_slice(
	const moon_DrawGroup* self,
	long long start,
	long long stop,
	long long step
) {
	moon_DrawGroup* slice = moon_DrawGroup_create(
		self->check_visibility,
		0UL
	);
	slice->drawables = moon_vector_slice<moon_DrawGroupable>(
		self->drawables,
		start,
		stop,
		step
	);
	return slice;
}


moon_DrawGroup::moon_DrawGroup(
	int v_check_visibility,
	unsigned long v_initial_capacity
) {
	check_visibility = v_check_visibility;
	drawables.reserve(v_initial_capacity + 1UL);
}


void
moon_DrawGroupable_draw(
	const moon_DrawGroupable& drawable,
	moon_RenderWindow* wnd,
	const moon_RenderStates* states,
	const int& check_visibility
) {
	const void* body = drawable.body;
	switch (drawable.type) {
		case moon_Draw_Groupable_Text: {
			const moon_Text* drawable = static_cast<const moon_Text*>(body);
			moon_generic_draw<moon_Text>(
				drawable, wnd, states, check_visibility
			);
			break;
		}
		case moon_Draw_Groupable_guiFpsCntr: {
			const moon_guiFpsCntr* drawable = static_cast<const moon_guiFpsCntr*>(body);
			moon_generic_draw<moon_guiFpsCntr>(
				drawable, wnd, states, check_visibility
			);
			break;
		}
		case moon_Draw_Groupable_Sprite: {
			const moon_Sprite* drawable = static_cast<const moon_Sprite*>(body);
			moon_generic_draw<moon_Sprite>(
				drawable, wnd, states, check_visibility
			);
			break;
		}
		case moon_Draw_Groupable_TextWrite: {
			const moon_TextWrite* drawable = static_cast<const moon_TextWrite*>(body);
			moon_generic_draw<moon_TextWrite>(
				drawable, wnd, states, check_visibility
			);
			break;
		}
		case moon_Draw_Groupable_ConvexShape: {
			const moon_ConvexShape* drawable = static_cast<const moon_ConvexShape*>(body);
			moon_generic_draw<moon_ConvexShape>(
				drawable, wnd, states, check_visibility
			);
			break;
		}
		case moon_Draw_Groupable_CircleShape: {
			const moon_CircleShape* drawable = static_cast<const moon_CircleShape*>(body);
			moon_generic_draw<moon_CircleShape>(
				drawable, wnd, states, check_visibility
			);
			break;
		}
		case moon_Draw_Groupable_RectangleShape: {
			const moon_RectangleShape* drawable = static_cast<const moon_RectangleShape*>(body);
			moon_generic_draw<moon_RectangleShape>(
				drawable, wnd, states, check_visibility
			);
			break;
		}
		case moon_Draw_Groupable_SlideAnimation: {
			const moon_SlideAnimation* drawable = static_cast<const moon_SlideAnimation*>(body);
			moon_generic_draw<moon_SlideAnimation>(
				drawable, wnd, states, check_visibility
			);
			break;
		}
		default:
			return;
	}
}
