#ifndef MOON_CSFML_GRAPHICS_MOON_VERTEX_H
#define MOON_CSFML_GRAPHICS_MOON_VERTEX_H


#include "./moon_render_states.h"

#include "./moon_render_window.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Defines a point with color and texture coordinates.
 */
typedef struct MOON_CSFML_API moon_Vertex {
	moon_Vector2f 	position;	//!< 2D position of the vertex
	moon_Color 		color;		//!< Color of the vertex
	moon_Vector2f 	tex_coords;	//!< Coordinates of the texture's pixel to map to the vertex
} moon_Vertex;


/**
 * Draws primitives defined by an array
 *of vertices to the RenderWindow.
 * Warning: reinterpret_cast. Why? We need performance, don't we?
 */
MOON_CSFML_API void
moon_Vertex_draw(
	const moon_Vertex* vertices,
	unsigned long vertex_count,
	int primitive_type,
	moon_RenderWindow* wnd,
	const moon_RenderStates* states
);

/**
 * Returns copy of this vertex.
 */
MOON_CSFML_API moon_Vertex
moon_Vertex_get_copy(const moon_Vertex* self);


#ifdef __cplusplus
}
#endif


#endif
