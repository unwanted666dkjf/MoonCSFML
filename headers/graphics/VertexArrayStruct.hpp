#ifndef MOON_CSFML_GRAPHICS_VERTEX_ARRAY_STRUCT_HPP
#define MOON_CSFML_GRAPHICS_VERTEX_ARRAY_STRUCT_HPP


#include <SFML/Graphics/VertexArray.hpp>


struct moon_VertexArray : public sf::VertexArray {

	moon_VertexArray();

	moon_VertexArray(
		int primitive_type,
		unsigned long vertex_count
	);

};


#endif
