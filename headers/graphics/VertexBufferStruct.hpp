#ifndef MOON_CSFML_GRAPHICS_VERTEX_BUFFER_STRUCT_HPP
#define MOON_CSFML_GRAPHICS_VERTEX_BUFFER_STRUCT_HPP


#include <SFML/Graphics/VertexBuffer.hpp>


struct moon_VertexBuffer : public sf::VertexBuffer {

	moon_VertexBuffer();

	moon_VertexBuffer(const moon_VertexBuffer* other);

	moon_VertexBuffer(int primitive_type);

	moon_VertexBuffer(int usage, int);

	moon_VertexBuffer(
		int primitive_type,
		int usage, int
	);

};


#endif
