#include <cstddef>



#include "../../headers/graphics/moon_vertex.h"

#include "../../headers/graphics/RenderStatesStruct.hpp"

#include "../../headers/graphics/RenderWindowStruct.hpp"


void
moon_Vertex_draw(
	const moon_Vertex* vertices,
	unsigned long vertex_count,
	int primitive_type,
	moon_RenderWindow* wnd,
	const moon_RenderStates* states
) {
	const auto* sf_vertices = reinterpret_cast<const sf::Vertex*>(vertices);
	wnd->draw(
		sf_vertices,
		static_cast<std::size_t>(vertex_count),
		static_cast<sf::PrimitiveType>(primitive_type),
		*states
	);
}

moon_Vertex
moon_Vertex_get_copy(const moon_Vertex* self) {
	return {
		self->position,
		self->color,
		self->tex_coords
	};
}


#if MOON_CSFML_ASSERT_MOON_VERTEX_LAYOUT

// Maybe I am just a paranoid.


static_assert(
	sizeof(moon_Vertex) == sizeof(sf::Vertex),
	"moon_Vertex and sf::Vertex are binary incompatible."
	"Incompatible size."
);
static_assert(
	sizeof(moon_Color) == sizeof(sf::Color),
	"moon_Vertex and sf::Vertex are binary incompatible."
	"moon_Color is incompatible with sf::Color."
);
static_assert(
	sizeof(moon_Vector2f) == sizeof(sf::Vector2f),
	"moon_Vertex and sf::Vertex are binary incompatible."
	"moon_Vector2f is incompatible with sf::Vector2f"
);

static_assert(
	offsetof(moon_Vertex, position) == offsetof(sf::Vertex, position),
	"moon_Vertex and sf::Vertex are binary incompatible."
	"Incompatible offset of \'position\' field."
);
static_assert(
	offsetof(moon_Vertex, color) == offsetof(sf::Vertex, color),
	"moon_Vertex and sf::Vertex are binary incompatible."
	"Incompatible offset of \'color\' field."
);
static_assert(
	offsetof(moon_Vertex, tex_coords) == offsetof(sf::Vertex, texCoords),
	"moon_Vertex and sf::Vertex are binary incompatible."
	"Incompatible offset of \'tex_coords\' field."
);

static_assert(
	alignof(moon_Vertex) == alignof(sf::Vertex),
	"moon_Vertex and sf::Vertex are binary incompatible."
	"Incompatible alignment."
);
static_assert(
	alignof(moon_Color) == alignof(sf::Color),
	"moon_Vertex and sf::Vertex are binary incompatible."
	"moon_Color alignment is incompatible with sf::Color alignment."
);
static_assert(
	alignof(moon_Vector2f) == alignof(sf::Vector2f),
	"moon_Vertex and sf::Vertex are binary incompatible."
	"moon_Vector2f alignment is incompatible with sf::Vector2f alignment."
);

#endif
