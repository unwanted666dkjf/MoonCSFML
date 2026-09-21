#ifndef MOON_CSFML_GRAPHICS_MOON_VERTEX_ARRAY_H
#define MOON_CSFML_GRAPHICS_MOON_VERTEX_ARRAY_H


#include "./moon_vertex.h"

#include "./moon_render_states.h"

#include "./moon_render_window.h"


#ifdef __cplusplus
extern "C" {
#endif


struct MOON_CSFML_API moon_VertexArray;


/**
 * Defines a set of one or more 2D primitives.
 */
typedef struct moon_VertexArray moon_VertexArray;


/**
 * Creates an empty vertex array.
 */
MOON_CSFML_API moon_VertexArray*
moon_VertexArray_create();

/**
 * Creates the vertex array with a type and an initial number of vertices.
 */
MOON_CSFML_API moon_VertexArray*
moon_VertexArray_create_ex(
	int primitive_type,
	unsigned long vertex_count
);

/**
 * Destroys the vertex array.
 */
MOON_CSFML_API void
moon_VertexArray_destroy(moon_VertexArray* self);

/**
 * Draws array of vertices to the RenderWindow.
 */
MOON_CSFML_API void
moon_VertexArray_draw(
	const moon_VertexArray* self,
	moon_RenderWindow* wnd,
	const moon_RenderStates* states
);

/**
 * Reverses vertex array.
 */
MOON_CSFML_API void
moon_VertexArray_reverse(moon_VertexArray* self);

/**
 * Returns number of vertices in the array.
 */
MOON_CSFML_API unsigned long
moon_VertexArray_get_vertex_count(const moon_VertexArray* self);

/**
 * Pops element at index from the array.
 * Returns removed element.
 */
MOON_CSFML_API moon_Vertex
moon_VertexArray_pop(
	moon_VertexArray* self,
	unsigned long index
);

/**
 * Returns copy of vertex at index.
 * This function doesn't check \a index, it must be in range
 *[0, vertex_count - 1]. The behavior is undefined
 *otherwise.
 */
MOON_CSFML_API moon_Vertex
moon_VertexArray_get(
	const moon_VertexArray* self,
	unsigned long index
);

/**
 * Sets new value(copy) to the element at index.
 * This function doesn't check \a index, it must be in range
 *[0, vertex_count - 1]. The behavior is undefined
 *otherwise.
 */
MOON_CSFML_API void
moon_VertexArray_set(
	moon_VertexArray* self,
	unsigned long index,
	const moon_Vertex* vertex
);

/**
 * Returns copy of the position of the vertex at index.
 * This function doesn't check \a index, it must be in range
 *[0, vertex_count - 1]. The behavior is undefined
 *otherwise.
 */
MOON_CSFML_API moon_Vector2f
moon_VertexArray_get_vposition(
	const moon_VertexArray* self,
	unsigned long index
);

/**
 * Sets position of the vertex at index.
 * This function doesn't check \a index, it must be in range
 *[0, vertex_count - 1]. The behavior is undefined
 *otherwise.
 */
MOON_CSFML_API void
moon_VertexArray_set_vposition(
	moon_VertexArray* self,
	unsigned long index,
	float x, float y
);

/**
 * Returns copy of the color of the vertex at index.
 * This function doesn't check \a index, it must be in range
 *[0, vertex_count - 1]. The behavior is undefined
 *otherwise.
 */
MOON_CSFML_API moon_Color
moon_VertexArray_get_vcolor(
	const moon_VertexArray* self,
	unsigned long index
);

/**
 * Sets color of the vertex at index.
 * This function doesn't check \a index, it must be in range
 *[0, vertex_count - 1]. The behavior is undefined
 *otherwise.
 */
MOON_CSFML_API void
moon_VertexArray_set_vcolor(
	moon_VertexArray* self,
	unsigned long index,
	const moon_Color* color
);

/**
 * Returns copy of coordinates of the texture's pixel of the vertex at index.
 * This function doesn't check \a index, it must be in range
 *[0, vertex_count - 1]. The behavior is undefined
 *otherwise.
 */
MOON_CSFML_API moon_Vector2f
moon_VertexArray_get_vtex_coords(
	const moon_VertexArray* self,
	unsigned long index
);

/**
 * Sets coordinates of the texture's pixel of the vertex at index.
 * This function doesn't check \a index, it must be in range
 *[0, vertex_count - 1]. The behavior is undefined
 *otherwise.
 */
MOON_CSFML_API void
moon_VertexArray_set_vtex_coords(
	moon_VertexArray* self,
	unsigned long index,
	float x, float y
);

/**
 * Clears the vertex array.
 * This function removes all the vertices from the array.
 * It doesn't deallocate the corresponding memory, so that
 *adding new vertices after clearing doesn't involve
 *reallocating all the memory.
 */
MOON_CSFML_API void
moon_VertexArray_clear(moon_VertexArray* self);

/**
 * Resizes the vertex array.
 *
 * If \a vertex_count is greater than the current size, the previous
 *vertices are kept and new (default-constructed) vertices are
 *added.
 * If \a vertex_count is less than the current size, existing vertices
 * are removed from the array.
 */
MOON_CSFML_API void
moon_VertexArray_resize(
	moon_VertexArray* self,
	unsigned long vertex_count
);

/**
 * This function appends a copy of vertex to the array.
 */
MOON_CSFML_API void
moon_VertexArray_append(
	moon_VertexArray* self,
	const moon_Vertex* vertex
);

/**
 * Sets the type of primitives to draw.
 * This function defines how the vertices must be interpreted
 *when it's time to draw them.
 */
MOON_CSFML_API void
moon_VertexArray_set_primitive_type(
	moon_VertexArray* self,
	int primitive_type
);

/**
 * Returns the type of primitives drawn by the vertex array.
 */
MOON_CSFML_API int
moon_VertexArray_get_primitive_type(const moon_VertexArray* self);

/**
 * Appends(copy) vertices from 'other' to the end of 'self'.
 */
MOON_CSFML_API void
moon_VertexArray_extend(
	moon_VertexArray* self,
	const moon_VertexArray* other
);

/**
 * Computes the bounding rectangle of the vertex array.
 * Returns the minimal axis-aligned rectangle
 *that contains all the vertices of the array.
 */
MOON_CSFML_API moon_FloatRect
moon_VertexArray_get_bounds(const moon_VertexArray* self);

/**
 * Returns a slice of this vertex array.
 * Slicing is similar(but not the same) to python slicing.
 * Indexes can be negative, in that case
 *index will be recomputed('index' + 'vertex_count').
 * No bound checking.
 * If step is 0, returns empty slice.
 * If step is negative, elements will be in reverse and stop
 *index will be included in range.
 * Slice will contain copies of original's vertices.
 * Also can be used to copy current array: [0 : 'vertex_count' : 1].
 */
MOON_CSFML_API moon_VertexArray*
moon_VertexArray_get_slice(
	const moon_VertexArray* self,
	long long start,
	long long stop,
	long long step
);


#ifdef __cplusplus
}
#endif


#endif
