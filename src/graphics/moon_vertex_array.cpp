// Fuck access modifiers

#define private public

#define protected public


#include "../../headers/graphics/moon_vertex_array.h"

#include "../../headers/graphics/Converters.hpp"

#include "../../headers/graphics/VectorUtils.hpp"

#include "../../headers/graphics/VertexArrayStruct.hpp"

#include "../../headers/graphics/RenderStatesStruct.hpp"

#include "../../headers/graphics/RenderWindowStruct.hpp"


moon_VertexArray*
moon_VertexArray_create() {
	return new moon_VertexArray();
}

moon_VertexArray*
moon_VertexArray_create_ex(
	int primitive_type,
	unsigned long vertex_count
) {
	return new moon_VertexArray(primitive_type, vertex_count);
}

void
moon_VertexArray_destroy(moon_VertexArray* self) {
	delete self;
}

void
moon_VertexArray_draw(
	const moon_VertexArray* self,
	moon_RenderWindow* wnd,
	const moon_RenderStates* states
) {
	wnd->draw(*self, *states);
}

void
moon_VertexArray_reverse(moon_VertexArray* self) {
	moon_vector_reverse<sf::Vertex>(self->m_vertices);
}

unsigned long
moon_VertexArray_get_vertex_count(const moon_VertexArray* self) {
	return static_cast<unsigned long>(self->getVertexCount());
}

moon_Vertex
moon_VertexArray_pop(
	moon_VertexArray* self,
	unsigned long index
) {
	return vertex_sf_to_moon(
		moon_vector_pop<sf::Vertex>(
			self->m_vertices,
			index
		)
	);
}

moon_Vertex
moon_VertexArray_get(
	const moon_VertexArray* self,
	unsigned long index
) {
	return vertex_sf_to_moon((*self)[index]);
}

void
moon_VertexArray_set(
	moon_VertexArray* self,
	unsigned long index,
	const moon_Vertex* vertex
) {
	self->m_vertices[index] = vertex_moon_to_sf(*vertex);
}

moon_Vector2f
moon_VertexArray_get_vposition(
	const moon_VertexArray* self,
	unsigned long index
) {
	return {
		self->m_vertices[index].position.x,
		self->m_vertices[index].position.y
	};
}

void
moon_VertexArray_set_vposition(
	moon_VertexArray* self,
	unsigned long index,
	float x, float y
) {
	self->m_vertices[index].position.x = x;
	self->m_vertices[index].position.y = y;
}

moon_Color
moon_VertexArray_get_vcolor(
	const moon_VertexArray* self,
	unsigned long index
) {
	return color_sf_to_moon(self->m_vertices[index].color);
}

void
moon_VertexArray_set_vcolor(
	moon_VertexArray* self,
	unsigned long index,
	const moon_Color* color
) {
	self->m_vertices[index].color = color_moon_to_sf(*color);
}

moon_Vector2f
moon_VertexArray_get_vtex_coords(
	const moon_VertexArray* self,
	unsigned long index
) {
	return {
		self->m_vertices[index].texCoords.x,
		self->m_vertices[index].texCoords.y
	};
}

void
moon_VertexArray_set_vtex_coords(
	moon_VertexArray* self,
	unsigned long index,
	float x, float y
) {
	self->m_vertices[index].texCoords.x = x;
	self->m_vertices[index].texCoords.y = y;
}

void
moon_VertexArray_clear(moon_VertexArray* self) {
	self->clear();
}

void
moon_VertexArray_resize(
	moon_VertexArray* self,
	unsigned long vertex_count
) {
	self->resize(static_cast<std::size_t>(vertex_count));
}

void
moon_VertexArray_append(
	moon_VertexArray* self,
	const moon_Vertex* vertex
) {
	self->append(vertex_moon_to_sf(*vertex));
}

void
moon_VertexArray_set_primitive_type(
	moon_VertexArray* self,
	int primitive_type
) {
	self->setPrimitiveType(
		static_cast<sf::PrimitiveType>(primitive_type)
	);
}

int
moon_VertexArray_get_primitive_type(const moon_VertexArray* self) {
	return static_cast<int>(
		self->getPrimitiveType()
	);
}

void
moon_VertexArray_extend(
	moon_VertexArray* self,
	const moon_VertexArray* other
) {
	moon_vector_extend<sf::Vertex>(self->m_vertices, other->m_vertices);
}

moon_FloatRect
moon_VertexArray_get_bounds(const moon_VertexArray* self) {
	if (self->m_vertices.empty()) {
		// Array is empty
		return moon_FloatRect_create_empty();
	}
	const float* left   = &self->m_vertices[0].position.x;
	const float* top    = &self->m_vertices[0].position.y;
	const float* right  = &self->m_vertices[0].position.x;
	const float* bottom = &self->m_vertices[0].position.y;

	for (unsigned long i = 1UL; i < self->m_vertices.size(); ++i)
	{
		const sf::Vector2f* position = &self->m_vertices[i].position;

		// Update left and right
		if (position->x < (*left)) {
			left = &position->x;
		} else if (position->x > (*right)) {
			right = &position->x;
		}

		// Update top and bottom
		if (position->y < (*top)) {
			top = &position->y;
		} else if (position->y > (*bottom)) {
			bottom = &position->y;
		}
	}
	return {
		*left, *top,
		(*right) - (*left), (*bottom) - (*top)
	};
}

moon_VertexArray*
moon_VertexArray_get_slice(
	const moon_VertexArray* self,
	long long start,
	long long stop,
	long long step
) {
	moon_VertexArray* slice = moon_VertexArray_create();
	slice->m_vertices = moon_vector_slice<sf::Vertex>(
		self->m_vertices,
		start,
		stop,
		step
	);
	return slice;
}


moon_VertexArray::moon_VertexArray() : sf::VertexArray() {
	//
}

moon_VertexArray::moon_VertexArray(
	int primitive_type,
	unsigned long vertex_count
) : sf::VertexArray(
	static_cast<sf::PrimitiveType>(primitive_type),
	static_cast<std::size_t>(vertex_count)
) {
	//
}


#undef private

#undef protected
