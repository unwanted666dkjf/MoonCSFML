#include "../../headers/graphics/moon_vertex_buffer.h"

#include "../../headers/graphics/VertexBufferStruct.hpp"

#include "../../headers/graphics/RenderStatesStruct.hpp"

#include "../../headers/graphics/RenderWindowStruct.hpp"


moon_VertexBuffer*
moon_VertexBuffer_default() {
	return new moon_VertexBuffer();
}

moon_VertexBuffer*
moon_VertexBuffer_from_primitive_type(int primitive_type) {
	return new moon_VertexBuffer(primitive_type);
}

moon_VertexBuffer*
moon_VertexBuffer_from_usage(int usage) {
	return new moon_VertexBuffer(usage, 666);
}

moon_VertexBuffer*
moon_VertexBuffer_create(
	int primitive_type,
	int usage
) {
	return new moon_VertexBuffer(primitive_type, usage, 666);
}

void
moon_VertexBuffer_destroy(moon_VertexBuffer* self) {
	delete self;
}

moon_VertexBuffer*
moon_VertexBuffer_get_copy(const moon_VertexBuffer* self) {
	return new moon_VertexBuffer(self);
}

void
moon_VertexBuffer_draw(
	const moon_VertexBuffer* self,
	moon_RenderWindow* wnd,
	const moon_RenderStates* states
) {
	wnd->draw(*self, *states);
}

void
moon_VertexBuffer_draw_ex(
	const moon_VertexBuffer* self,
	moon_RenderWindow* wnd,
	const moon_RenderStates* states,
	unsigned long first_vertex,
	unsigned long vertex_count
) {
	wnd->draw(
		*self,
		static_cast<std::size_t>(first_vertex),
		static_cast<std::size_t>(vertex_count),
		*states
	);
}

int
moon_VertexBuffer_allocate(
	moon_VertexBuffer* self,
	unsigned long vertex_count
) {
	return self->create(static_cast<std::size_t>(vertex_count));
}

unsigned long
moon_VertexBuffer_get_vertex_count(const moon_VertexBuffer* self) {
	return self->getVertexCount();
}

int
moon_VertexBuffer_update(
	moon_VertexBuffer* self,
	const moon_Vertex* vertices
) {
	const auto sf_vertices = reinterpret_cast<const sf::Vertex*>(vertices);
	return self->update(sf_vertices);
}

int
moon_VertexBuffer_update_ex(
	moon_VertexBuffer* self,
	const moon_Vertex* vertices,
	unsigned long vertex_count,
	unsigned int offset
) {
	const auto sf_vertices = reinterpret_cast<const sf::Vertex*>(vertices);
	return self->update(
		sf_vertices,
		static_cast<std::size_t>(vertex_count),
		offset
	);
}

int
moon_VertexBuffer_copy_contents(
	moon_VertexBuffer* self,
	const moon_VertexBuffer* other
) {
	return self->update(*other);
}

void
moon_VertexBuffer_swap(
	moon_VertexBuffer* self,
	moon_VertexBuffer* other
) {
	self->swap(*other);
}

unsigned int
moon_VertexBuffer_get_native_handle(const moon_VertexBuffer* self) {
	return self->getNativeHandle();
}

void
moon_VertexBuffer_set_primitive_type(
	moon_VertexBuffer* self,
	int primitive_type
) {
	self->setPrimitiveType(
		static_cast<sf::PrimitiveType>(primitive_type)
	);
}

int
moon_VertexBuffer_get_primitive_type(const moon_VertexBuffer* self) {
	return static_cast<int>(self->getPrimitiveType());
}

void
moon_VertexBuffer_set_usage(
	moon_VertexBuffer* self,
	int usage
) {
	self->setUsage(
		static_cast<sf::VertexBuffer::Usage>(usage)
	);
}

int
moon_VertexBuffer_get_usage(const moon_VertexBuffer* self) {
	return static_cast<int>(self->getUsage());
}

void
moon_VertexBuffer_bind(const moon_VertexBuffer* self) {
	sf::VertexBuffer::bind(self);
}

int
moon_VertexBuffer_is_available() {
	return sf::VertexBuffer::isAvailable();
}


moon_VertexBuffer::moon_VertexBuffer() : sf::VertexBuffer() {
	//
}

moon_VertexBuffer::moon_VertexBuffer(
	const moon_VertexBuffer* other
) : sf::VertexBuffer(*other) {
	//
}

moon_VertexBuffer::moon_VertexBuffer(
	int primitive_type
) : sf::VertexBuffer(static_cast<sf::PrimitiveType>(primitive_type)) {
	//
}

moon_VertexBuffer::moon_VertexBuffer(
	int usage, int
) : sf::VertexBuffer(static_cast<sf::VertexBuffer::Usage>(usage)) {
	//
}

moon_VertexBuffer::moon_VertexBuffer(
	int primitive_type,
	int usage, int
) : sf::VertexBuffer(
	static_cast<sf::PrimitiveType>(primitive_type),
	static_cast<sf::VertexBuffer::Usage>(usage)
) {
	//
}
