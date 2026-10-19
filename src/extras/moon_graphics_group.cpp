#include <vector>

#include <algorithm>



#include "../../headers/extras/moon_bounds_type.h"

#include "../../headers/extras/moon_useful_funcs.h"

#include "../../headers/extras/moon_graphics_group.h"


struct moon_GraphicsGroup {
	std::vector<moon_Sprite*> 			sprite_objs;
	std::vector<moon_SlideShow*> 		slideshow_objs;
	std::vector<moon_SlideAnimation*> 	slideanimation_objs;
	std::vector<moon_Text*> 			text_objs;
	std::vector<moon_RectangleShape*> 	rectshape_objs;
	std::vector<moon_CircleShape*> 		circleshape_objs;
	std::vector<moon_ConvexShape*> 		convexshape_objs;
	std::vector<moon_TextWrite*> 		textwrite_objs;
	std::vector<moon_guiFpsCntr*> 		guifpscntr_objs;
};


moon_GraphicsGroup*
moon_GraphicsGroup_create() {
	moon_GraphicsGroup* self = new moon_GraphicsGroup();
	return self;
}

moon_GraphicsGroup*
moon_GraphicsGroup_create_ex(
	unsigned long num_sprites,
	unsigned long num_slideshow,
	unsigned long num_slideanimation,
	unsigned long num_text,
	unsigned long num_rectshapes,
	unsigned long num_circleshapes,
	unsigned long num_convexshapes,
	unsigned long num_textwrites,
	unsigned long num_guifpscntrs
) {
	moon_GraphicsGroup* self = moon_GraphicsGroup_create();
	self->sprite_objs			.reserve(num_sprites);
	self->slideshow_objs		.reserve(num_slideshow);
	self->slideanimation_objs	.reserve(num_slideanimation);
	self->text_objs				.reserve(num_text);
	self->rectshape_objs		.reserve(num_rectshapes);
	self->circleshape_objs		.reserve(num_circleshapes);
	self->convexshape_objs		.reserve(num_convexshapes);
	self->textwrite_objs		.reserve(num_textwrites);
	self->guifpscntr_objs		.reserve(num_guifpscntrs);
	return self;
}

void
moon_GraphicsGroup_destroy(moon_GraphicsGroup* self) {
	delete self;
}


int
moon_GraphicsGroup_text_is_empty(const moon_GraphicsGroup* self) {
	return self->text_objs.empty();
}

int
moon_GraphicsGroup_sprite_is_empty(const moon_GraphicsGroup* self) {
	return self->sprite_objs.empty();
}

int
moon_GraphicsGroup_rectshape_is_empty(const moon_GraphicsGroup* self) {
	return self->rectshape_objs.empty();
}

int
moon_GraphicsGroup_circleshape_is_empty(const moon_GraphicsGroup* self) {
	return self->circleshape_objs.empty();
}

int
moon_GraphicsGroup_convexshape_is_empty(const moon_GraphicsGroup* self) {
	return self->convexshape_objs.empty();
}

int
moon_GraphicsGroup_textwrite_is_empty(const moon_GraphicsGroup* self) {
	return self->textwrite_objs.empty();
}

int
moon_GraphicsGroup_guifpscntr_is_empty(const moon_GraphicsGroup* self) {
	return self->guifpscntr_objs.empty();
}

int
moon_GraphicsGroup_slideshow_is_empty(const moon_GraphicsGroup* self) {
	return self->slideshow_objs.empty();
}

int
moon_GraphicsGroup_slideanimation_is_empty(const moon_GraphicsGroup* self) {
	return self->slideanimation_objs.empty();
}


unsigned long
moon_GraphicsGroup_text_size(const moon_GraphicsGroup* self) {
	return self->text_objs.capacity();
}

unsigned long
moon_GraphicsGroup_sprite_size(const moon_GraphicsGroup* self) {
	return self->sprite_objs.capacity();
}

unsigned long
moon_GraphicsGroup_rectshape_size(const moon_GraphicsGroup* self) {
	return self->rectshape_objs.capacity();
}

unsigned long
moon_GraphicsGroup_circleshape_size(const moon_GraphicsGroup* self) {
	return self->circleshape_objs.capacity();
}

unsigned long
moon_GraphicsGroup_convexshape_size(const moon_GraphicsGroup* self) {
	return self->convexshape_objs.capacity();
}

unsigned long
moon_GraphicsGroup_textwrite_size(const moon_GraphicsGroup* self) {
	return self->textwrite_objs.capacity();
}

unsigned long
moon_GraphicsGroup_guifpscntr_size(const moon_GraphicsGroup* self) {
	return self->guifpscntr_objs.capacity();
}

unsigned long
moon_GraphicsGroup_slideshow_size(const moon_GraphicsGroup* self) {
	return self->slideshow_objs.capacity();
}

unsigned long
moon_GraphicsGroup_slideanimation_size(const moon_GraphicsGroup* self) {
	return self->slideanimation_objs.capacity();
}


unsigned long
moon_GraphicsGroup_text_length(const moon_GraphicsGroup* self) {
	return self->text_objs.size();
}

unsigned long
moon_GraphicsGroup_sprite_length(const moon_GraphicsGroup* self) {
	return self->sprite_objs.size();
}

unsigned long
moon_GraphicsGroup_rectshape_length(const moon_GraphicsGroup* self) {
	return self->rectshape_objs.size();
}

unsigned long
moon_GraphicsGroup_circleshape_length(const moon_GraphicsGroup* self) {
	return self->circleshape_objs.size();
}

unsigned long
moon_GraphicsGroup_convexshape_length(const moon_GraphicsGroup* self) {
	return self->convexshape_objs.size();
}

unsigned long
moon_GraphicsGroup_textwrite_length(const moon_GraphicsGroup* self) {
	return self->textwrite_objs.size();
}

unsigned long
moon_GraphicsGroup_guifpscntr_length(const moon_GraphicsGroup* self) {
	return self->guifpscntr_objs.size();
}

unsigned long
moon_GraphicsGroup_slideshow_length(const moon_GraphicsGroup* self) {
	return self->slideshow_objs.size();
}

unsigned long
moon_GraphicsGroup_slideanimation_length(const moon_GraphicsGroup* self) {
	return self->slideanimation_objs.size();
}


int
moon_GraphicsGroup_text_reserve(
	moon_GraphicsGroup* self,
	unsigned long capacity
) {
	if (self->text_objs.capacity() >= capacity) {
		return 0;
	}
	self->text_objs.reserve(capacity);
	return 1;
}

int
moon_GraphicsGroup_sprite_reserve(
	moon_GraphicsGroup* self,
	unsigned long capacity
) {
	if (self->sprite_objs.capacity() >= capacity) {
		return 0;
	}
	self->sprite_objs.reserve(capacity);
	return 1;
}

int
moon_GraphicsGroup_rectshape_reserve(
	moon_GraphicsGroup* self,
	unsigned long capacity
) {
	if (self->rectshape_objs.capacity() >= capacity) {
		return 0;
	}
	self->rectshape_objs.reserve(capacity);
	return 1;
}

int
moon_GraphicsGroup_circleshape_reserve(
	moon_GraphicsGroup* self,
	unsigned long capacity
) {
	if (self->circleshape_objs.capacity() >= capacity) {
		return 0;
	}
	self->circleshape_objs.reserve(capacity);
	return 1;
}

int
moon_GraphicsGroup_convexshape_reserve(
	moon_GraphicsGroup* self,
	unsigned long capacity
) {
	if (self->convexshape_objs.capacity() >= capacity) {
		return 0;
	}
	self->convexshape_objs.reserve(capacity);
	return 1;
}

int
moon_GraphicsGroup_textwrite_reserve(
	moon_GraphicsGroup* self,
	unsigned long capacity
) {
	if (self->textwrite_objs.capacity() >= capacity) {
		return 0;
	}
	self->textwrite_objs.reserve(capacity);
	return 1;
}

int
moon_GraphicsGroup_guifpscntr_reserve(
	moon_GraphicsGroup* self,
	unsigned long capacity
) {
	if (self->guifpscntr_objs.capacity() >= capacity) {
		return 0;
	}
	self->guifpscntr_objs.reserve(capacity);
	return 1;
}

int
moon_GraphicsGroup_slideshow_reserve(
	moon_GraphicsGroup* self,
	unsigned long capacity
) {
	if (self->slideshow_objs.capacity() >= capacity) {
		return 0;
	}
	self->slideshow_objs.reserve(capacity);
	return 1;
}

int
moon_GraphicsGroup_slideanimation_reserve(
	moon_GraphicsGroup* self,
	unsigned long capacity
) {
	if (self->slideanimation_objs.capacity() >= capacity) {
		return 0;
	}
	self->slideanimation_objs.reserve(capacity);
	return 1;
}


int
moon_GraphicsGroup_text_resize(
	moon_GraphicsGroup* self,
	unsigned long new_size
) {
	if (self->text_objs.size() >= new_size) {
		return 0;
	}
	self->text_objs.resize(new_size);
	return 1;
}

int
moon_GraphicsGroup_sprite_resize(
	moon_GraphicsGroup* self,
	unsigned long new_size
) {
	if (self->sprite_objs.size() >= new_size) {
		return 0;
	}
	self->sprite_objs.resize(new_size);
	return 1;
}

int
moon_GraphicsGroup_rectshape_resize(
	moon_GraphicsGroup* self,
	unsigned long new_size
) {
	if (self->rectshape_objs.size() >= new_size) {
		return 0;
	}
	self->rectshape_objs.resize(new_size);
	return 1;
}

int
moon_GraphicsGroup_circleshape_resize(
	moon_GraphicsGroup* self,
	unsigned long new_size
) {
	if (self->circleshape_objs.size() >= new_size) {
		return 0;
	}
	self->circleshape_objs.resize(new_size);
	return 1;
}

int
moon_GraphicsGroup_convexshape_resize(
	moon_GraphicsGroup* self,
	unsigned long new_size
) {
	if (self->convexshape_objs.size() >= new_size) {
		return 0;
	}
	self->convexshape_objs.resize(new_size);
	return 1;
}

int
moon_GraphicsGroup_textwrite_resize(
	moon_GraphicsGroup* self,
	unsigned long new_size
) {
	if (self->textwrite_objs.size() >= new_size) {
		return 0;
	}
	self->textwrite_objs.resize(new_size);
	return 1;
}

int
moon_GraphicsGroup_guifpscntr_resize(
	moon_GraphicsGroup* self,
	unsigned long new_size
) {
	if (self->guifpscntr_objs.size() >= new_size) {
		return 0;
	}
	self->guifpscntr_objs.resize(new_size);
	return 1;
}

int
moon_GraphicsGroup_slideshow_resize(
	moon_GraphicsGroup* self,
	unsigned long new_size
) {
	if (self->slideshow_objs.size() >= new_size) {
		return 0;
	}
	self->slideshow_objs.resize(new_size);
	return 1;
}

int
moon_GraphicsGroup_slideanimation_resize(
	moon_GraphicsGroup* self,
	unsigned long new_size
) {
	if (self->slideanimation_objs.size() >= new_size) {
		return 0;
	}
	self->slideanimation_objs.resize(new_size);
	return 1;
}


int
moon_GraphicsGroup_text_erase(
	moon_GraphicsGroup* self,
	unsigned long start_ind,
	unsigned long num_elements
) {
	if (
		(start_ind > self->text_objs.size())
		|| (
			static_cast<long long>(num_elements)
			>
			(
				static_cast<long long>(self->text_objs.size())
				- static_cast<long long>(start_ind)
			)
		)
	) {
		return 0;
	}
	self->text_objs.erase(
		self->text_objs.begin() + start_ind,
		self->text_objs.begin() + start_ind + num_elements
	);
	return 1;
}

int
moon_GraphicsGroup_sprite_erase(
	moon_GraphicsGroup* self,
	unsigned long start_ind,
	unsigned long num_elements
) {
	if (
		(start_ind > self->sprite_objs.size())
		|| (
			static_cast<long long>(num_elements)
			>
			(
				static_cast<long long>(self->sprite_objs.size())
				- static_cast<long long>(start_ind)
			)
		)
	) {
		return 0;
	}
	self->sprite_objs.erase(
		self->sprite_objs.begin() + start_ind,
		self->sprite_objs.begin() + start_ind + num_elements
	);
	return 1;
}

int
moon_GraphicsGroup_rectshape_erase(
	moon_GraphicsGroup* self,
	unsigned long start_ind,
	unsigned long num_elements
) {
	if (
		(start_ind > self->rectshape_objs.size())
		|| (
			static_cast<long long>(num_elements)
			>
			(
				static_cast<long long>(self->rectshape_objs.size())
				- static_cast<long long>(start_ind)
			)
		)
	) {
		return 0;
	}
	self->rectshape_objs.erase(
		self->rectshape_objs.begin() + start_ind,
		self->rectshape_objs.begin() + start_ind + num_elements
	);
	return 1;
}

int
moon_GraphicsGroup_circleshape_erase(
	moon_GraphicsGroup* self,
	unsigned long start_ind,
	unsigned long num_elements
) {
	if (
		(start_ind > self->circleshape_objs.size())
		|| (
			static_cast<long long>(num_elements)
			>
			(
				static_cast<long long>(self->circleshape_objs.size())
				- static_cast<long long>(start_ind)
			)
		)
	) {
		return 0;
	}
	self->circleshape_objs.erase(
		self->circleshape_objs.begin() + start_ind,
		self->circleshape_objs.begin() + start_ind + num_elements
	);
	return 1;
}

int
moon_GraphicsGroup_convexshape_erase(
	moon_GraphicsGroup* self,
	unsigned long start_ind,
	unsigned long num_elements
) {
	if (
		(start_ind > self->convexshape_objs.size())
		|| (
			static_cast<long long>(num_elements)
			>
			(
				static_cast<long long>(self->convexshape_objs.size())
				- static_cast<long long>(start_ind)
			)
		)
	) {
		return 0;
	}
	self->convexshape_objs.erase(
		self->convexshape_objs.begin() + start_ind,
		self->convexshape_objs.begin() + start_ind + num_elements
	);
	return 1;
}

int
moon_GraphicsGroup_textwrite_erase(
	moon_GraphicsGroup* self,
	unsigned long start_ind,
	unsigned long num_elements
) {
	if (
		(start_ind > self->textwrite_objs.size())
		|| (
			static_cast<long long>(num_elements)
			>
			(
				static_cast<long long>(self->textwrite_objs.size())
				- static_cast<long long>(start_ind)
			)
		)
	) {
		return 0;
	}
	self->textwrite_objs.erase(
		self->textwrite_objs.begin() + start_ind,
		self->textwrite_objs.begin() + start_ind + num_elements
	);
	return 1;
}

int
moon_GraphicsGroup_guifpscntr_erase(
	moon_GraphicsGroup* self,
	unsigned long start_ind,
	unsigned long num_elements
) {
	if (
		(start_ind > self->guifpscntr_objs.size())
		|| (
			static_cast<long long>(num_elements)
			>
			(
				static_cast<long long>(self->guifpscntr_objs.size())
				- static_cast<long long>(start_ind)
			)
		)
	) {
		return 0;
	}
	self->guifpscntr_objs.erase(
		self->guifpscntr_objs.begin() + start_ind,
		self->guifpscntr_objs.begin() + start_ind + num_elements
	);
	return 1;
}

int
moon_GraphicsGroup_slideshow_erase(
	moon_GraphicsGroup* self,
	unsigned long start_ind,
	unsigned long num_elements
) {
	if (
		(start_ind > self->slideshow_objs.size())
		|| (
			static_cast<long long>(num_elements)
			>
			(
				static_cast<long long>(self->slideshow_objs.size())
				- static_cast<long long>(start_ind)
			)
		)
	) {
		return 0;
	}
	self->slideshow_objs.erase(
		self->slideshow_objs.begin() + start_ind,
		self->slideshow_objs.begin() + start_ind + num_elements
	);
	return 1;
}

int
moon_GraphicsGroup_slideanimation_erase(
	moon_GraphicsGroup* self,
	unsigned long start_ind,
	unsigned long num_elements
) {
	if (
		(start_ind > self->slideanimation_objs.size())
		|| (
			static_cast<long long>(num_elements)
			>
			(
				static_cast<long long>(self->slideanimation_objs.size())
				- static_cast<long long>(start_ind)
			)
		)
	) {
		return 0;
	}
	self->slideanimation_objs.erase(
		self->slideanimation_objs.begin() + start_ind,
		self->slideanimation_objs.begin() + start_ind + num_elements
	);
	return 1;
}


moon_Text*
moon_GraphicsGroup_text_pop(
	moon_GraphicsGroup* self,
	unsigned long index
) {
	moon_Text* el = self->text_objs[index];
	self->text_objs.erase(self->text_objs.begin() + index);
	return el;
}

moon_Sprite*
moon_GraphicsGroup_sprite_pop(
	moon_GraphicsGroup* self,
	unsigned long index
) {
	moon_Sprite* el = self->sprite_objs[index];
	self->sprite_objs.erase(self->sprite_objs.begin() + index);
	return el;
}

moon_RectangleShape*
moon_GraphicsGroup_rectshape_pop(
	moon_GraphicsGroup* self,
	unsigned long index
) {
	moon_RectangleShape* el = self->rectshape_objs[index];
	self->rectshape_objs.erase(self->rectshape_objs.begin() + index);
	return el;
}

moon_CircleShape*
moon_GraphicsGroup_circleshape_pop(
	moon_GraphicsGroup* self,
	unsigned long index
) {
	moon_CircleShape* el = self->circleshape_objs[index];
	self->circleshape_objs.erase(self->circleshape_objs.begin() + index);
	return el;
}

moon_ConvexShape*
moon_GraphicsGroup_convexshape_pop(
	moon_GraphicsGroup* self,
	unsigned long index
) {
	moon_ConvexShape* el = self->convexshape_objs[index];
	self->convexshape_objs.erase(self->convexshape_objs.begin() + index);
	return el;
}

moon_TextWrite*
moon_GraphicsGroup_textwrite_pop(
	moon_GraphicsGroup* self,
	unsigned long index
) {
	moon_TextWrite* el = self->textwrite_objs[index];
	self->textwrite_objs.erase(self->textwrite_objs.begin() + index);
	return el;
}

moon_guiFpsCntr*
moon_GraphicsGroup_guifpscntr_pop(
	moon_GraphicsGroup* self,
	unsigned long index
) {
	moon_guiFpsCntr* el = self->guifpscntr_objs[index];
	self->guifpscntr_objs.erase(self->guifpscntr_objs.begin() + index);
	return el;
}

moon_SlideShow*
moon_GraphicsGroup_slideshow_pop(
	moon_GraphicsGroup* self,
	unsigned long index
) {
	moon_SlideShow* el = self->slideshow_objs[index];
	self->slideshow_objs.erase(self->slideshow_objs.begin() + index);
	return el;
}

moon_SlideAnimation*
moon_GraphicsGroup_slideanimation_pop(
	moon_GraphicsGroup* self,
	unsigned long index
) {
	moon_SlideAnimation* el = self->slideanimation_objs[index];
	self->slideanimation_objs.erase(self->slideanimation_objs.begin() + index);
	return el;
}


moon_Text*
moon_GraphicsGroup_text_get(
	moon_GraphicsGroup* self,
	unsigned long index
) {
	return self->text_objs[index];
}

moon_Sprite*
moon_GraphicsGroup_sprite_get(
	moon_GraphicsGroup* self,
	unsigned long index
) {
	return self->sprite_objs[index];
}

moon_RectangleShape*
moon_GraphicsGroup_rectshape_get(
	moon_GraphicsGroup* self,
	unsigned long index
) {
	return self->rectshape_objs[index];
}

moon_CircleShape*
moon_GraphicsGroup_circleshape_get(
	moon_GraphicsGroup* self,
	unsigned long index
) {
	return self->circleshape_objs[index];
}

moon_ConvexShape*
moon_GraphicsGroup_convexshape_get(
	moon_GraphicsGroup* self,
	unsigned long index
) {
	return self->convexshape_objs[index];
}

moon_TextWrite*
moon_GraphicsGroup_textwrite_get(
	moon_GraphicsGroup* self,
	unsigned long index
) {
	return self->textwrite_objs[index];
}

moon_guiFpsCntr*
moon_GraphicsGroup_guifpscntr_get(
	moon_GraphicsGroup* self,
	unsigned long index
) {
	return self->guifpscntr_objs[index];
}

moon_SlideShow*
moon_GraphicsGroup_slideshow_get(
	moon_GraphicsGroup* self,
	unsigned long index
) {
	return self->slideshow_objs[index];
}

moon_SlideAnimation*
moon_GraphicsGroup_slideanimation_get(
	moon_GraphicsGroup* self,
	unsigned long index
) {
	return self->slideanimation_objs[index];
}


void
moon_GraphicsGroup_text_set(
	moon_GraphicsGroup* self,
	unsigned long index,
	moon_Text* item
) {
	self->text_objs[index] = item;
}

void
moon_GraphicsGroup_sprite_set(
	moon_GraphicsGroup* self,
	unsigned long index,
	moon_Sprite* item
) {
	self->sprite_objs[index] = item;
}

void
moon_GraphicsGroup_rectshape_set(
	moon_GraphicsGroup* self,
	unsigned long index,
	moon_RectangleShape* item
) {
	self->rectshape_objs[index] = item;
}

void
moon_GraphicsGroup_circleshape_set(
	moon_GraphicsGroup* self,
	unsigned long index,
	moon_CircleShape* item
) {
	self->circleshape_objs[index] = item;
}

void
moon_GraphicsGroup_convexshape_set(
	moon_GraphicsGroup* self,
	unsigned long index,
	moon_ConvexShape* item
) {
	self->convexshape_objs[index] = item;
}

void
moon_GraphicsGroup_textwrite_set(
	moon_GraphicsGroup* self,
	unsigned long index,
	moon_TextWrite* item
) {
	self->textwrite_objs[index] = item;
}

void
moon_GraphicsGroup_guifpscntr_set(
	moon_GraphicsGroup* self,
	unsigned long index,
	moon_guiFpsCntr* item
) {
	self->guifpscntr_objs[index] = item;
}

void
moon_GraphicsGroup_slideshow_set(
	moon_GraphicsGroup* self,
	unsigned long index,
	moon_SlideShow* item
) {
	self->slideshow_objs[index] = item;
}

void
moon_GraphicsGroup_slideanimation_set(
	moon_GraphicsGroup* self,
	unsigned long index,
	moon_SlideAnimation* item
) {
	self->slideanimation_objs[index] = item;
}


moon_FRectLst*
moon_GraphicsGroup_text_get_bounds(
	const moon_GraphicsGroup* self,
	int bounds_type,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_FRectLst* bounds = moon_FRectLst_create(num_elements);
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		moon_FloatRect bound;
		const moon_Text* item = self->text_objs[first_index];
		switch(bounds_type) {
			case moon_BoundsType_Global:
				bound = moon_Text_get_global_bounds(item);
				break;
			case moon_BoundsType_Local:
				bound = moon_Text_get_local_bounds(item);
				break;
			case moon_BoundsType_World:
				bound = moon_Text_get_world_bounds(item);
				break;
			default:
				continue;
		}
		moon_FRectLst_push_back(bounds, &bound);
	}
	return bounds;
}

moon_FRectLst*
moon_GraphicsGroup_sprite_get_bounds(
	const moon_GraphicsGroup* self,
	int bounds_type,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_FRectLst* bounds = moon_FRectLst_create(num_elements);
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		moon_FloatRect bound;
		const moon_Sprite* item = self->sprite_objs[first_index];
		switch(bounds_type) {
			case moon_BoundsType_Global:
				bound = moon_Sprite_get_global_bounds(item);
				break;
			case moon_BoundsType_Local:
				bound = moon_Sprite_get_local_bounds(item);
				break;
			case moon_BoundsType_World:
				bound = moon_Sprite_get_world_bounds(item);
				break;
			default:
				continue;
		}
		moon_FRectLst_push_back(bounds, &bound);
	}
	return bounds;
}

moon_FRectLst*
moon_GraphicsGroup_rectshape_get_bounds(
	const moon_GraphicsGroup* self,
	int bounds_type,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_FRectLst* bounds = moon_FRectLst_create(num_elements);
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		moon_FloatRect bound;
		const moon_RectangleShape* item = self->rectshape_objs[first_index];
		switch(bounds_type) {
			case moon_BoundsType_Global:
				bound = moon_RectangleShape_get_global_bounds(item);
				break;
			case moon_BoundsType_Local:
				bound = moon_RectangleShape_get_local_bounds(item);
				break;
			case moon_BoundsType_World:
				bound = moon_RectangleShape_get_world_bounds(item);
				break;
			default:
				continue;
		}
		moon_FRectLst_push_back(bounds, &bound);
	}
	return bounds;
}

moon_FRectLst*
moon_GraphicsGroup_circleshape_get_bounds(
	const moon_GraphicsGroup* self,
	int bounds_type,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_FRectLst* bounds = moon_FRectLst_create(num_elements);
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		moon_FloatRect bound;
		const moon_CircleShape* item = self->circleshape_objs[first_index];
		switch(bounds_type) {
			case moon_BoundsType_Global:
				bound = moon_CircleShape_get_global_bounds(item);
				break;
			case moon_BoundsType_Local:
				bound = moon_CircleShape_get_local_bounds(item);
				break;
			case moon_BoundsType_World:
				bound = moon_CircleShape_get_world_bounds(item);
				break;
			default:
				continue;
		}
		moon_FRectLst_push_back(bounds, &bound);
	}
	return bounds;
}

moon_FRectLst*
moon_GraphicsGroup_convexshape_get_bounds(
	const moon_GraphicsGroup* self,
	int bounds_type,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_FRectLst* bounds = moon_FRectLst_create(num_elements);
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		moon_FloatRect bound;
		const moon_ConvexShape* item = self->convexshape_objs[first_index];
		switch(bounds_type) {
			case moon_BoundsType_Global:
				bound = moon_ConvexShape_get_global_bounds(item);
				break;
			case moon_BoundsType_Local:
				bound = moon_ConvexShape_get_local_bounds(item);
				break;
			case moon_BoundsType_World:
				bound = moon_ConvexShape_get_world_bounds(item);
				break;
			default:
				continue;
		}
		moon_FRectLst_push_back(bounds, &bound);
	}
	return bounds;
}

moon_FRectLst*
moon_GraphicsGroup_textwrite_get_bounds(
	const moon_GraphicsGroup* self,
	int bounds_type,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_FRectLst* bounds = moon_FRectLst_create(num_elements);
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		moon_FloatRect bound;
		const moon_TextWrite* item = self->textwrite_objs[first_index];
		switch(bounds_type) {
			case moon_BoundsType_Global:
				bound = moon_TextWrite_get_global_bounds(item);
				break;
			case moon_BoundsType_Local:
				bound = moon_TextWrite_get_local_bounds(item);
				break;
			case moon_BoundsType_World:
				bound = moon_TextWrite_get_world_bounds(item);
				break;
			default:
				continue;
		}
		moon_FRectLst_push_back(bounds, &bound);
	}
	return bounds;
}

moon_FRectLst*
moon_GraphicsGroup_guifpscntr_get_bounds(
	const moon_GraphicsGroup* self,
	int bounds_type,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_FRectLst* bounds = moon_FRectLst_create(num_elements);
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		moon_FloatRect bound;
		const moon_guiFpsCntr* item = self->guifpscntr_objs[first_index];
		switch(bounds_type) {
			case moon_BoundsType_Global:
				bound = moon_guiFpsCntr_get_global_bounds(item);
				break;
			case moon_BoundsType_Local:
				bound = moon_guiFpsCntr_get_local_bounds(item);
				break;
			case moon_BoundsType_World:
				bound = moon_guiFpsCntr_get_world_bounds(item);
				break;
			default:
				continue;
		}
		moon_FRectLst_push_back(bounds, &bound);
	}
	return bounds;
}

moon_FRectLst*
moon_GraphicsGroup_slideshow_get_bounds(
	const moon_GraphicsGroup* self,
	int bounds_type,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_FRectLst* bounds = moon_FRectLst_create(num_elements);
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		moon_FloatRect bound;
		const moon_SlideShow* item = self->slideshow_objs[first_index];
		switch(bounds_type) {
			case moon_BoundsType_Global:
				bound = moon_SlideShow_get_global_bounds(item);
				break;
			case moon_BoundsType_Local:
				bound = moon_SlideShow_get_local_bounds(item);
				break;
			case moon_BoundsType_World:
				bound = moon_SlideShow_get_world_bounds(item);
				break;
			default:
				continue;
		}
		moon_FRectLst_push_back(bounds, &bound);
	}
	return bounds;
}

moon_FRectLst*
moon_GraphicsGroup_slideanimation_get_bounds(
	const moon_GraphicsGroup* self,
	int bounds_type,
	unsigned long first_index,
	unsigned long num_elements
) {
	moon_FRectLst* bounds = moon_FRectLst_create(num_elements);
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		moon_FloatRect bound;
		const moon_SlideAnimation* item = self->slideanimation_objs[first_index];
		switch(bounds_type) {
			case moon_BoundsType_Global:
				bound = moon_SlideAnimation_get_global_bounds(item);
				break;
			case moon_BoundsType_Local:
				bound = moon_SlideAnimation_get_local_bounds(item);
				break;
			case moon_BoundsType_World:
				bound = moon_SlideAnimation_get_world_bounds(item);
				break;
			default:
				continue;
		}
		moon_FRectLst_push_back(bounds, &bound);
	}
	return bounds;
}


void
moon_GraphicsGroup_text_push_back(
	moon_GraphicsGroup* self,
	moon_Text* item
) {
	self->text_objs.push_back(item);
}

void
moon_GraphicsGroup_sprite_push_back(
	moon_GraphicsGroup* self,
	moon_Sprite* item
) {
	self->sprite_objs.push_back(item);
}

void
moon_GraphicsGroup_rectshape_push_back(
	moon_GraphicsGroup* self,
	moon_RectangleShape* item
) {
	self->rectshape_objs.push_back(item);
}

void
moon_GraphicsGroup_circleshape_push_back(
	moon_GraphicsGroup* self,
	moon_CircleShape* item
) {
	self->circleshape_objs.push_back(item);
}

void
moon_GraphicsGroup_convexshape_push_back(
	moon_GraphicsGroup* self,
	moon_ConvexShape* item
) {
	self->convexshape_objs.push_back(item);
}

void
moon_GraphicsGroup_textwrite_push_back(
	moon_GraphicsGroup* self,
	moon_TextWrite* item
) {
	self->textwrite_objs.push_back(item);
}

void
moon_GraphicsGroup_guifpscntr_push_back(
	moon_GraphicsGroup* self,
	moon_guiFpsCntr* item
) {
	self->guifpscntr_objs.push_back(item);
}

void
moon_GraphicsGroup_slideshow_push_back(
	moon_GraphicsGroup* self,
	moon_SlideShow* item
) {
	self->slideshow_objs.push_back(item);
}

void
moon_GraphicsGroup_slideanimation_push_back(
	moon_GraphicsGroup* self,
	moon_SlideAnimation* item
) {
	self->slideanimation_objs.push_back(item);
}


void
moon_GraphicsGroup_text_reverse(moon_GraphicsGroup* self) {
	std::reverse(
		self->text_objs.begin(),
		self->text_objs.end()
	);
}

void
moon_GraphicsGroup_sprite_reverse(moon_GraphicsGroup* self) {
	std::reverse(
		self->sprite_objs.begin(),
		self->sprite_objs.end()
	);
}

void
moon_GraphicsGroup_rectshape_reverse(moon_GraphicsGroup* self) {
	std::reverse(
		self->rectshape_objs.begin(),
		self->rectshape_objs.end()
	);
}

void
moon_GraphicsGroup_circleshape_reverse(moon_GraphicsGroup* self) {
	std::reverse(
		self->circleshape_objs.begin(),
		self->circleshape_objs.end()
	);
}

void
moon_GraphicsGroup_convexshape_reverse(moon_GraphicsGroup* self) {
	std::reverse(
		self->convexshape_objs.begin(),
		self->convexshape_objs.end()
	);
}

void
moon_GraphicsGroup_textwrite_reverse(moon_GraphicsGroup* self) {
	std::reverse(
		self->textwrite_objs.begin(),
		self->textwrite_objs.end()
	);
}

void
moon_GraphicsGroup_guifpscntr_reverse(moon_GraphicsGroup* self) {
	std::reverse(
		self->guifpscntr_objs.begin(),
		self->guifpscntr_objs.end()
	);
}

void
moon_GraphicsGroup_slideshow_reverse(moon_GraphicsGroup* self) {
	std::reverse(
		self->slideshow_objs.begin(),
		self->slideshow_objs.end()
	);
}

void
moon_GraphicsGroup_slideanimation_reverse(moon_GraphicsGroup* self) {
	std::reverse(
		self->slideanimation_objs.begin(),
		self->slideanimation_objs.end()
	);
}


void
moon_GraphicsGroup_text_clear(moon_GraphicsGroup* self) {
	self->text_objs.clear();
}

void
moon_GraphicsGroup_sprite_clear(moon_GraphicsGroup* self) {
	self->sprite_objs.clear();
}

void
moon_GraphicsGroup_rectshape_clear(moon_GraphicsGroup* self) {
	self->rectshape_objs.clear();
}

void
moon_GraphicsGroup_circleshape_clear(moon_GraphicsGroup* self) {
	self->circleshape_objs.clear();
}

void
moon_GraphicsGroup_convexshape_clear(moon_GraphicsGroup* self) {
	self->convexshape_objs.clear();
}

void
moon_GraphicsGroup_textwrite_clear(moon_GraphicsGroup* self) {
	self->textwrite_objs.clear();
}

void
moon_GraphicsGroup_guifpscntr_clear(moon_GraphicsGroup* self) {
	self->guifpscntr_objs.clear();
}

void
moon_GraphicsGroup_slideshow_clear(moon_GraphicsGroup* self) {
	self->slideshow_objs.clear();
}

void
moon_GraphicsGroup_slideanimation_clear(moon_GraphicsGroup* self) {
	self->slideanimation_objs.clear();
}


void
moon_GraphicsGroup_text_draw(
	const moon_GraphicsGroup* self,
	moon_RenderWindow* wnd,
	const moon_RenderStates* states,
	int check_visibility,
	unsigned long first_index,
	unsigned long num_elements
) {
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		const moon_Text* item = self->text_objs[first_index];
		if (check_visibility) {
			moon_FloatRect bounds = moon_Text_get_global_bounds(item);
			moon_FloatRect visibility_rect = moon_is_rect_visible(&bounds, wnd);
			if (moon_FloatRect_is_empty(&visibility_rect)) {
				continue;
			}
		}
		moon_Text_draw(item, wnd, states);
	}
}

void
moon_GraphicsGroup_sprite_draw(
	const moon_GraphicsGroup* self,
	moon_RenderWindow* wnd,
	const moon_RenderStates* states,
	int check_visibility,
	unsigned long first_index,
	unsigned long num_elements
) {
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		const moon_Sprite* item = self->sprite_objs[first_index];
		if (check_visibility) {
			moon_FloatRect bounds = moon_Sprite_get_global_bounds(item);
			moon_FloatRect visibility_rect = moon_is_rect_visible(&bounds, wnd);
			if (moon_FloatRect_is_empty(&visibility_rect)) {
				continue;
			}
		}
		moon_Sprite_draw(item, wnd, states);
	}
}

void
moon_GraphicsGroup_rectshape_draw(
	const moon_GraphicsGroup* self,
	moon_RenderWindow* wnd,
	const moon_RenderStates* states,
	int check_visibility,
	unsigned long first_index,
	unsigned long num_elements
) {
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		const moon_RectangleShape* item = self->rectshape_objs[first_index];
		if (check_visibility) {
			moon_FloatRect bounds = moon_RectangleShape_get_global_bounds(item);
			moon_FloatRect visibility_rect = moon_is_rect_visible(&bounds, wnd);
			if (moon_FloatRect_is_empty(&visibility_rect)) {
				continue;
			}
		}
		moon_RectangleShape_draw(item, wnd, states);
	}
}

void
moon_GraphicsGroup_circleshape_draw(
	const moon_GraphicsGroup* self,
	moon_RenderWindow* wnd,
	const moon_RenderStates* states,
	int check_visibility,
	unsigned long first_index,
	unsigned long num_elements
) {
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		const moon_CircleShape* item = self->circleshape_objs[first_index];
		if (check_visibility) {
			moon_FloatRect bounds = moon_CircleShape_get_global_bounds(item);
			moon_FloatRect visibility_rect = moon_is_rect_visible(&bounds, wnd);
			if (moon_FloatRect_is_empty(&visibility_rect)) {
				continue;
			}
		}
		moon_CircleShape_draw(item, wnd, states);
	}
}

void
moon_GraphicsGroup_convexshape_draw(
	const moon_GraphicsGroup* self,
	moon_RenderWindow* wnd,
	const moon_RenderStates* states,
	int check_visibility,
	unsigned long first_index,
	unsigned long num_elements
) {
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		const moon_ConvexShape* item = self->convexshape_objs[first_index];
		if (check_visibility) {
			moon_FloatRect bounds = moon_ConvexShape_get_global_bounds(item);
			moon_FloatRect visibility_rect = moon_is_rect_visible(&bounds, wnd);
			if (moon_FloatRect_is_empty(&visibility_rect)) {
				continue;
			}
		}
		moon_ConvexShape_draw(item, wnd, states);
	}
}

void
moon_GraphicsGroup_textwrite_draw(
	const moon_GraphicsGroup* self,
	moon_RenderWindow* wnd,
	const moon_RenderStates* states,
	int check_visibility,
	unsigned long first_index,
	unsigned long num_elements
) {
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		const moon_TextWrite* item = self->textwrite_objs[first_index];
		if (check_visibility) {
			moon_FloatRect bounds = moon_TextWrite_get_global_bounds(item);
			moon_FloatRect visibility_rect = moon_is_rect_visible(&bounds, wnd);
			if (moon_FloatRect_is_empty(&visibility_rect)) {
				continue;
			}
		}
		moon_TextWrite_draw(item, wnd, states);
	}
}

void
moon_GraphicsGroup_guifpscntr_draw(
	const moon_GraphicsGroup* self,
	moon_RenderWindow* wnd,
	const moon_RenderStates* states,
	int check_visibility,
	unsigned long first_index,
	unsigned long num_elements
) {
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		const moon_guiFpsCntr* item = self->guifpscntr_objs[first_index];
		if (check_visibility) {
			moon_FloatRect bounds = moon_guiFpsCntr_get_global_bounds(item);
			moon_FloatRect visibility_rect = moon_is_rect_visible(&bounds, wnd);
			if (moon_FloatRect_is_empty(&visibility_rect)) {
				continue;
			}
		}
		moon_guiFpsCntr_draw(item, wnd, states);
	}
}

void
moon_GraphicsGroup_slideshow_draw(
	const moon_GraphicsGroup* self,
	moon_RenderWindow* wnd,
	const moon_RenderStates* states,
	int check_visibility,
	unsigned long first_index,
	unsigned long num_elements
) {
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		const moon_SlideShow* item = self->slideshow_objs[first_index];
		if (check_visibility) {
			moon_FloatRect bounds = moon_SlideShow_get_global_bounds(item);
			moon_FloatRect visibility_rect = moon_is_rect_visible(&bounds, wnd);
			if (moon_FloatRect_is_empty(&visibility_rect)) {
				continue;
			}
		}
		moon_SlideShow_draw(item, wnd, states);
	}
}

void
moon_GraphicsGroup_slideanimation_draw(
	const moon_GraphicsGroup* self,
	moon_RenderWindow* wnd,
	const moon_RenderStates* states,
	int check_visibility,
	unsigned long first_index,
	unsigned long num_elements
) {
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		const moon_SlideAnimation* item = self->slideanimation_objs[first_index];
		if (check_visibility) {
			moon_FloatRect bounds = moon_SlideAnimation_get_global_bounds(item);
			moon_FloatRect visibility_rect = moon_is_rect_visible(&bounds, wnd);
			if (moon_FloatRect_is_empty(&visibility_rect)) {
				continue;
			}
		}
		moon_SlideAnimation_draw(item, wnd, states);
	}
}


void
moon_GraphicsGroup_text_set_color(
	const moon_GraphicsGroup* self,
	const moon_Color* color,
	unsigned long first_index,
	unsigned long num_elements
) {
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		moon_Text* item = self->text_objs[first_index];
		moon_Text_set_fill_color(item, color);
	}
}

void
moon_GraphicsGroup_sprite_set_color(
	const moon_GraphicsGroup* self,
	const moon_Color* color,
	unsigned long first_index,
	unsigned long num_elements
) {
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		moon_Sprite* item = self->sprite_objs[first_index];
		moon_Sprite_set_color(item, color);
	}
}

void
moon_GraphicsGroup_rectshape_set_color(
	const moon_GraphicsGroup* self,
	const moon_Color* color,
	unsigned long first_index,
	unsigned long num_elements
) {
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		moon_RectangleShape* item = self->rectshape_objs[first_index];
		moon_RectangleShape_set_fill_color(item, color);
	}
}

void
moon_GraphicsGroup_circleshape_set_color(
	const moon_GraphicsGroup* self,
	const moon_Color* color,
	unsigned long first_index,
	unsigned long num_elements
) {
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		moon_CircleShape* item = self->circleshape_objs[first_index];
		moon_CircleShape_set_fill_color(item, color);
	}
}

void
moon_GraphicsGroup_convexshape_set_color(
	const moon_GraphicsGroup* self,
	const moon_Color* color,
	unsigned long first_index,
	unsigned long num_elements
) {
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		moon_ConvexShape* item = self->convexshape_objs[first_index];
		moon_ConvexShape_set_fill_color(item, color);
	}
}

void
moon_GraphicsGroup_textwrite_set_color(
	const moon_GraphicsGroup* self,
	const moon_Color* color,
	unsigned long first_index,
	unsigned long num_elements
) {
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		moon_TextWrite* item = self->textwrite_objs[first_index];
		moon_TextWrite_set_fill_color(item, color);
	}
}

void
moon_GraphicsGroup_guifpscntr_set_color(
	const moon_GraphicsGroup* self,
	const moon_Color* color,
	unsigned long first_index,
	unsigned long num_elements
) {
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		moon_guiFpsCntr* item = self->guifpscntr_objs[first_index];
		moon_guiFpsCntr_set_fill_color(item, color);
	}
}

void
moon_GraphicsGroup_slideshow_set_color(
	const moon_GraphicsGroup* self,
	const moon_Color* color,
	unsigned long first_index,
	unsigned long num_elements
) {
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		moon_SlideShow* item = self->slideshow_objs[first_index];
		moon_SlideShow_set_color(item, color);
	}
}

void
moon_GraphicsGroup_slideanimation_set_color(
	const moon_GraphicsGroup* self,
	const moon_Color* color,
	unsigned long first_index,
	unsigned long num_elements
) {
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		moon_SlideAnimation* item = self->slideanimation_objs[first_index];
		moon_SlideAnimation_set_color(item, color);
	}
}


void
moon_GraphicsGroup_text_inverse_color(
	const moon_GraphicsGroup* self,
	unsigned long first_index,
	unsigned long num_elements
) {
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		moon_Text* item = self->text_objs[first_index];
		moon_Color clr = moon_Text_get_fill_color(item);
		clr.red 	= 255 - clr.red;
		clr.green 	= 255 - clr.green;
		clr.blue 	= 255 - clr.blue;
		moon_Text_set_fill_color(item, &clr);
	}
}

void
moon_GraphicsGroup_sprite_inverse_color(
	const moon_GraphicsGroup* self,
	unsigned long first_index,
	unsigned long num_elements
) {
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		moon_Sprite* item = self->sprite_objs[first_index];
		moon_Color clr = moon_Sprite_get_color(item);
		clr.red 	= 255 - clr.red;
		clr.green 	= 255 - clr.green;
		clr.blue 	= 255 - clr.blue;
		moon_Sprite_set_color(item, &clr);
	}
}

void
moon_GraphicsGroup_rectshape_inverse_color(
	const moon_GraphicsGroup* self,
	unsigned long first_index,
	unsigned long num_elements
) {
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		moon_RectangleShape* item = self->rectshape_objs[first_index];
		moon_Color clr = moon_RectangleShape_get_fill_color(item);
		clr.red 	= 255 - clr.red;
		clr.green 	= 255 - clr.green;
		clr.blue 	= 255 - clr.blue;
		moon_RectangleShape_set_fill_color(item, &clr);
	}
}

void
moon_GraphicsGroup_circleshape_inverse_color(
	const moon_GraphicsGroup* self,
	unsigned long first_index,
	unsigned long num_elements
) {
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		moon_CircleShape* item = self->circleshape_objs[first_index];
		moon_Color clr = moon_CircleShape_get_fill_color(item);
		clr.red 	= 255 - clr.red;
		clr.green 	= 255 - clr.green;
		clr.blue 	= 255 - clr.blue;
		moon_CircleShape_set_fill_color(item, &clr);
	}
}

void
moon_GraphicsGroup_convexshape_inverse_color(
	const moon_GraphicsGroup* self,
	unsigned long first_index,
	unsigned long num_elements
) {
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		moon_ConvexShape* item = self->convexshape_objs[first_index];
		moon_Color clr = moon_ConvexShape_get_fill_color(item);
		clr.red 	= 255 - clr.red;
		clr.green 	= 255 - clr.green;
		clr.blue 	= 255 - clr.blue;
		moon_ConvexShape_set_fill_color(item, &clr);
	}
}

void
moon_GraphicsGroup_textwrite_inverse_color(
	const moon_GraphicsGroup* self,
	unsigned long first_index,
	unsigned long num_elements
) {
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		moon_TextWrite* item = self->textwrite_objs[first_index];
		moon_Color clr = moon_TextWrite_get_fill_color(item);
		clr.red 	= 255 - clr.red;
		clr.green 	= 255 - clr.green;
		clr.blue 	= 255 - clr.blue;
		moon_TextWrite_set_fill_color(item, &clr);
	}
}

void
moon_GraphicsGroup_guifpscntr_inverse_color(
	const moon_GraphicsGroup* self,
	unsigned long first_index,
	unsigned long num_elements
) {
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		moon_guiFpsCntr* item = self->guifpscntr_objs[first_index];
		moon_Color clr = moon_guiFpsCntr_get_fill_color(item);
		clr.red 	= 255 - clr.red;
		clr.green 	= 255 - clr.green;
		clr.blue 	= 255 - clr.blue;
		moon_guiFpsCntr_set_fill_color(item, &clr);
	}
}

void
moon_GraphicsGroup_slideshow_inverse_color(
	const moon_GraphicsGroup* self,
	unsigned long first_index,
	unsigned long num_elements
) {
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		moon_SlideShow* item = self->slideshow_objs[first_index];
		moon_Color clr = moon_SlideShow_get_color(item);
		clr.red 	= 255 - clr.red;
		clr.green 	= 255 - clr.green;
		clr.blue 	= 255 - clr.blue;
		moon_SlideShow_set_color(item, &clr);
	}
}

void
moon_GraphicsGroup_slideanimation_inverse_color(
	const moon_GraphicsGroup* self,
	unsigned long first_index,
	unsigned long num_elements
) {
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		moon_SlideAnimation* item = self->slideanimation_objs[first_index];
		moon_Color clr = moon_SlideAnimation_get_color(item);
		clr.red 	= 255 - clr.red;
		clr.green 	= 255 - clr.green;
		clr.blue 	= 255 - clr.blue;
		moon_SlideAnimation_set_color(item, &clr);
	}
}


void
moon_GraphicsGroup_text_set_alpha(
	const moon_GraphicsGroup* self,
	unsigned char alpha,
	unsigned long first_index,
	unsigned long num_elements
) {
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		moon_Text* item = self->text_objs[first_index];
		moon_Color clr = moon_Text_get_fill_color(item);
		clr.alpha = alpha;
		moon_Text_set_fill_color(item, &clr);
	}
}

void
moon_GraphicsGroup_sprite_set_alpha(
	const moon_GraphicsGroup* self,
	unsigned char alpha,
	unsigned long first_index,
	unsigned long num_elements
) {
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		moon_Sprite* item = self->sprite_objs[first_index];
		moon_Color clr = moon_Sprite_get_color(item);
		clr.alpha = alpha;
		moon_Sprite_set_color(item, &clr);
	}
}

void
moon_GraphicsGroup_rectshape_set_alpha(
	const moon_GraphicsGroup* self,
	unsigned char alpha,
	unsigned long first_index,
	unsigned long num_elements
) {
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		moon_RectangleShape* item = self->rectshape_objs[first_index];
		moon_Color clr = moon_RectangleShape_get_fill_color(item);
		clr.alpha = alpha;
		moon_RectangleShape_set_fill_color(item, &clr);
	}
}

void
moon_GraphicsGroup_circleshape_set_alpha(
	const moon_GraphicsGroup* self,
	unsigned char alpha,
	unsigned long first_index,
	unsigned long num_elements
) {
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		moon_CircleShape* item = self->circleshape_objs[first_index];
		moon_Color clr = moon_CircleShape_get_fill_color(item);
		clr.alpha = alpha;
		moon_CircleShape_set_fill_color(item, &clr);
	}
}

void
moon_GraphicsGroup_convexshape_set_alpha(
	const moon_GraphicsGroup* self,
	unsigned char alpha,
	unsigned long first_index,
	unsigned long num_elements
) {
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		moon_ConvexShape* item = self->convexshape_objs[first_index];
		moon_Color clr = moon_ConvexShape_get_fill_color(item);
		clr.alpha = alpha;
		moon_ConvexShape_set_fill_color(item, &clr);
	}
}

void
moon_GraphicsGroup_textwrite_set_alpha(
	const moon_GraphicsGroup* self,
	unsigned char alpha,
	unsigned long first_index,
	unsigned long num_elements
) {
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		moon_TextWrite* item = self->textwrite_objs[first_index];
		moon_Color clr = moon_TextWrite_get_fill_color(item);
		clr.alpha = alpha;
		moon_TextWrite_set_fill_color(item, &clr);
	}
}

void
moon_GraphicsGroup_guifpscntr_set_alpha(
	const moon_GraphicsGroup* self,
	unsigned char alpha,
	unsigned long first_index,
	unsigned long num_elements
) {
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		moon_guiFpsCntr* item = self->guifpscntr_objs[first_index];
		moon_Color clr = moon_guiFpsCntr_get_fill_color(item);
		clr.alpha = alpha;
		moon_guiFpsCntr_set_fill_color(item, &clr);
	}
}

void
moon_GraphicsGroup_slideshow_set_alpha(
	const moon_GraphicsGroup* self,
	unsigned char alpha,
	unsigned long first_index,
	unsigned long num_elements
) {
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		moon_SlideShow* item = self->slideshow_objs[first_index];
		moon_Color clr = moon_SlideShow_get_color(item);
		clr.alpha = alpha;
		moon_SlideShow_set_color(item, &clr);
	}
}

void
moon_GraphicsGroup_slideanimation_set_alpha(
	const moon_GraphicsGroup* self,
	unsigned char alpha,
	unsigned long first_index,
	unsigned long num_elements
) {
	unsigned long end_index = first_index + num_elements;
	for (; first_index < end_index; first_index++) {
		moon_SlideAnimation* item = self->slideanimation_objs[first_index];
		moon_Color clr = moon_SlideAnimation_get_color(item);
		clr.alpha = alpha;
		moon_SlideAnimation_set_color(item, &clr);
	}
}


long long
moon_GraphicsGroup_text_get_minsize(
	const moon_GraphicsGroup* self,
	unsigned long first_index,
	unsigned long num_elements
) {
	/
}

long long
moon_GraphicsGroup_sprite_get_minsize(
	const moon_GraphicsGroup* self,
	unsigned long first_index,
	unsigned long num_elements
) {
	/
}
