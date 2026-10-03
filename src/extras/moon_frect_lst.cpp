#include <vector>



#include "../../headers/graphics/VectorUtils.hpp"


#include "../../headers/extras/moon_frect_lst.h"


struct moon_FRectLst {
	std::vector<moon_FloatRect> rects;
};


moon_FRectLst*
moon_FRectLst_create(unsigned long initial_capacity) {
	moon_FRectLst* self = new moon_FRectLst();
	self->rects.reserve(initial_capacity);
	return self;
}

void
moon_FRectLst_destroy(moon_FRectLst* self) {
	delete self;
}

int
moon_FRectLst_is_empty(const moon_FRectLst* self) {
	return self->rects.empty();
}

int
moon_FRectLst_reserve(
	moon_FRectLst* self,
	unsigned long capacity
) {
	if (capacity <= self->rects.capacity()) {
		return 0;
	}
	self->rects.reserve(capacity);
	return 1;
}

unsigned long
moon_FRectLst_size(const moon_FRectLst* self) {
	return self->rects.capacity();
}

unsigned long
moon_FRectLst_length(const moon_FRectLst* self) {
	return self->rects.size();
}

void
moon_FRectLst_clear(moon_FRectLst* self) {
	self->rects.clear();
}

void
moon_FRectLst_reverse(moon_FRectLst* self) {
	moon_vector_reverse<moon_FloatRect>(self->rects);
}

void
moon_FRectLst_resize(
	moon_FRectLst* self,
	unsigned long new_size
) {
	self->rects.resize(new_size);
}

void
moon_FRectLst_set(
	moon_FRectLst* self,
	unsigned long index,
	const moon_FloatRect* rect
) {
	self->rects[index] = moon_FloatRect_get_copy(rect);
}

const moon_FloatRect*
moon_FRectLst_read(
	const moon_FRectLst* self,
	unsigned long index
) {
	return &self->rects[index];
}

moon_FloatRect
moon_FRectLst_get(
	const moon_FRectLst* self,
	unsigned long index
) {
	return moon_FloatRect_get_copy(&self->rects[index]);
}

moon_FloatRect
moon_FRectLst_pop(
	moon_FRectLst* self,
	unsigned long index
) {
	return moon_vector_pop<moon_FloatRect>(self->rects, index);
}

void
moon_FRectLst_push_back(
	moon_FRectLst* self,
	const moon_FloatRect* rect
) {
	self->rects.push_back(
		moon_FloatRect_get_copy(rect)
	);
}

void
moon_FRectLst_push_front(
	moon_FRectLst* self,
	const moon_FloatRect* rect
) {
	moon_vector_insert<moon_FloatRect>(
		self->rects, 0UL,
		moon_FloatRect_get_copy(rect)
	);
}

void
moon_FRectLst_extend(
	moon_FRectLst* self,
	const moon_FRectLst* other
) {
	moon_vector_extend<moon_FloatRect>(
		self->rects,
		other->rects
	);
}

void
moon_FRectLst_move(
	moon_FRectLst* self,
	float dx, float dy
) {
	for (unsigned long i = 0UL; i < self->rects.size(); i++) {
		self->rects[i].top  += dy;
		self->rects[i].left += dx;
	}
}

void
moon_FRectLst_set_position(
	moon_FRectLst* self,
	float left, float top
) {
	for (unsigned long i = 0UL; i < self->rects.size(); i++) {
		self->rects[i].top  = top;
		self->rects[i].left = left;
	}
}

moon_FRectLst*
moon_FRectLst_get_slice(
	const moon_FRectLst* self,
	long long start,
	long long stop,
	long long step
) {
	moon_FRectLst* slice = moon_FRectLst_create(0UL);
	slice->rects = moon_vector_slice<moon_FloatRect>(
		self->rects,
		start,
		stop,
		step
	);
	return slice;
}
