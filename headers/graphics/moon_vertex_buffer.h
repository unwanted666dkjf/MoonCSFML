#ifndef MOON_CSFML_GRAPHICS_MOON_VERTEX_BUFFER_H
#define MOON_CSFML_GRAPHICS_MOON_VERTEX_BUFFER_H


#include "./moon_vertex.h"

#include "./moon_render_states.h"

#include "./moon_render_window.h"


#ifdef __cplusplus
extern "C" {
#endif


enum
{
	moon_VertexBuffer_Usage_Stream,  //!< Constantly changing data
	moon_VertexBuffer_Usage_Dynamic, //!< Occasionally changing data
	moon_VertexBuffer_Usage_Static   //!< Rarely changing data
};


struct MOON_CSFML_API moon_VertexBuffer;


/**
 * Vertex buffer storage for one or more 2D primitives.
 */
typedef struct moon_VertexBuffer moon_VertexBuffer;


/**
 * Creates an empty vertex buffer.
 */
MOON_CSFML_API moon_VertexBuffer*
moon_VertexBuffer_default();

/**
 * Creates an empty vertex buffer and sets
 *its primitive type to \p primitive_type.
 */
MOON_CSFML_API moon_VertexBuffer*
moon_VertexBuffer_from_primitive_type(int primitive_type);

/**
 * Creates an empty vertex buffer and sets its usage to \p usage.
 */
MOON_CSFML_API moon_VertexBuffer*
moon_VertexBuffer_from_usage(int usage);

/**
 * Creates an empty vertex buffer and sets its primitive type
 *to \p primitive_type and usage to \p usage.
 */
MOON_CSFML_API moon_VertexBuffer*
moon_VertexBuffer_create(
	int primitive_type,
	int usage
);

/**
 * Destroys vertex buffer.
 */
MOON_CSFML_API void
moon_VertexBuffer_destroy(moon_VertexBuffer* self);

/**
 * Returns copy of this buffer.
 */
MOON_CSFML_API moon_VertexBuffer*
moon_VertexBuffer_get_copy(const moon_VertexBuffer* self);

/**
 * Draws primitives defined by a vertex buffer to
 *the RenderWindow.
 */
MOON_CSFML_API void
moon_VertexBuffer_draw(
	const moon_VertexBuffer* self,
	moon_RenderWindow* wnd,
	const moon_RenderStates* states
);

/**
 * Draws primitives defined by a vertex buffer to
 *the RenderWindow.
 * 'first_vertex' -- index of the first vertex to render.
 * 'vertex_count' -- number of vertices to render.
 */
MOON_CSFML_API void
moon_VertexBuffer_draw_ex(
	const moon_VertexBuffer* self,
	moon_RenderWindow* wnd,
	const moon_RenderStates* states,
	unsigned long first_vertex,
	unsigned long vertex_count
);

/**
 * Creates the vertex buffer.
 *
 * Creates the vertex buffer and allocates enough graphics
 *memory to hold \p vertex_count vertices. Any previously
 *allocated memory is freed in the process.
 *
 * In order to deallocate previously allocated memory pass 0
 *as \p vertex_count. Don't forget to recreate with a non-zero
 *value when graphics memory should be allocated again.
 *
 * Returns 1 if creation was successful, 0 otherwise.
 */
MOON_CSFML_API int
moon_VertexBuffer_allocate(
	moon_VertexBuffer* self,
	unsigned long vertex_count
);

/**
 * Returns number of vertices in the vertex buffer.
 */
MOON_CSFML_API unsigned long
moon_VertexBuffer_get_vertex_count(const moon_VertexBuffer* self);

/**
 * Updates the whole buffer from an array of vertices.
 *
 * The \a vertex array is assumed to have the same size as
 *the \a created buffer.
 *
 * No additional check is performed on the size of the vertex
 *array, passing invalid arguments will lead to undefined
 *behavior.
 *
 * This function does nothing if \a vertices is null or if the
 *buffer was not previously created.
 *
 * Returns 1 if the update was successful, 0 otherwise.
 *
 * Warning: reinterpret_cast.
 */
MOON_CSFML_API int
moon_VertexBuffer_update(
	moon_VertexBuffer* self,
	const moon_Vertex* vertices
);

/**
 * Updates a part of the buffer from an array of vertices.
 *\p offset is specified as the number of vertices to skip
 *from the beginning of the buffer.
 *
 * If \p offset is 0 and \p vertexCount is equal to the size of
 *the currently created buffer, its whole contents are replaced.
 *
 * If \p offset is 0 and \p vertex_count is greater than the
 *size of the currently created buffer, a new buffer is created
 *containing the vertex data.
 *
 * If \p offset is 0 and \p vertex_count is less than the size of
 *the currently created buffer, only the corresponding region
 *is updated.
 *
 * If \p offset is not 0 and \p offset + \p vertex_count is greater
 *than the size of the currently created buffer, the update fails.
 *
 * No additional check is performed on the size of the vertex
 *array, passing invalid arguments will lead to undefined
 *behavior.
 *
 * Returns 1 if the update was successful, 0 otherwise.
 *
 * Warning: reinterpret_cast.
 */
MOON_CSFML_API int
moon_VertexBuffer_update_ex(
	moon_VertexBuffer* self,
	const moon_Vertex* vertices,
	unsigned long vertex_count,
	unsigned int offset
);

/**
 * Copies the contents of another buffer into this buffer.
 * Returns 1 if the copy was successful, 0 otherwise.
 */
MOON_CSFML_API int
moon_VertexBuffer_copy_contents(
	moon_VertexBuffer* self,
	const moon_VertexBuffer* other
);

/**
 * Swaps the contents of this vertex buffer with those of another.
 */
MOON_CSFML_API void
moon_VertexBuffer_swap(
	moon_VertexBuffer* self,
	moon_VertexBuffer* other
);

/**
 * Returns the underlying OpenGL handle of the vertex buffer
 *or 0 if not yet created.
 *
 * You shouldn't need to use this function, unless you have
 *very specific stuff to implement that SFML doesn't support,
 *or implement a temporary workaround until a bug is fixed.
 */
MOON_CSFML_API unsigned int
moon_VertexBuffer_get_native_handle(const moon_VertexBuffer* self);

/**
 * Sets the type of primitives to draw.
 * This function defines how the vertices must be interpreted
 *when it's time to draw them.
 *
 * The default primitive type is Points.
 */
MOON_CSFML_API void
moon_VertexBuffer_set_primitive_type(
	moon_VertexBuffer* self,
	int primitive_type
);

/**
 * Returns the type of primitives drawn by the vertex buffer.
 */
MOON_CSFML_API int
moon_VertexBuffer_get_primitive_type(const moon_VertexBuffer* self);

/**
 * Sets the usage specifier of this vertex buffer.
 *
 * This function provides a hint about how this vertex buffer is
 *going to be used in terms of data update frequency.
 *
 * After changing the usage specifier, the vertex buffer has
 *to be updated with new data for the usage specifier to
 *take effect.
 *
 * The default usage is sf::VertexBuffer::Stream.
 */
MOON_CSFML_API void
moon_VertexBuffer_set_usage(
	moon_VertexBuffer* self,
	int usage
);

/**
 * Returns the usage specifier of this vertex buffer.
 */
MOON_CSFML_API int
moon_VertexBuffer_get_usage(const moon_VertexBuffer* self);

/**
 * Binds a vertex buffer for rendering.
 *
 * This function is not part of the graphics API, it mustn't be
 *used when drawing SFML entities. It must be used only if you
 *mix sf::VertexBuffer with OpenGL code.
 * SFML example:
 * \code
 * sf::VertexBuffer vb1, vb2;
 * ...
 * sf::VertexBuffer::bind(&vb1);
 * // draw OpenGL stuff that use vb1...
 * sf::VertexBuffer::bind(&vb2);
 * // draw OpenGL stuff that use vb2...
 * sf::VertexBuffer::bind(NULL);
 * // draw OpenGL stuff that use no vertex buffer...
 * \endcode
 */
MOON_CSFML_API void
moon_VertexBuffer_bind(const moon_VertexBuffer* self);

/**
 * Tells whether or not the system supports vertex buffers.
 *
 * This function should always be called before using
 *the vertex buffer features. If it returns false, then
 *any attempt to use sf::VertexBuffer will fail.
 *
 * Returns 1 if vertex buffers are supported, 0 otherwise.
 */
MOON_CSFML_API int
moon_VertexBuffer_is_available();


#ifdef __cplusplus
}
#endif


#endif
