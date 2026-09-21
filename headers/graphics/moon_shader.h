#ifndef MOON_CSFML_GRAPHICS_MOON_SHADER_H
#define MOON_CSFML_GRAPHICS_MOON_SHADER_H


#include "./moon_texture.h"


#ifdef __cplusplus
extern "C" {
#endif


enum
{
	moon_Shader_Type_Vertex,   //!< %Vertex shader
	moon_Shader_Type_Geometry, //!< Geometry shader
	moon_Shader_Type_Fragment  //!< Fragment (pixel) shader
};


struct MOON_CSFML_API moon_Shader;


/**
 * Shader struct (vertex, geometry and fragment).
 */
typedef struct moon_Shader moon_Shader;


/**
 * Creates an invalid shader.
 */
MOON_CSFML_API moon_Shader*
moon_Shader_create();

/**
 * Destroys shader.
 */
MOON_CSFML_API void
moon_Shader_destroy(moon_Shader* self);

/**
 * Loads the vertex, geometry or fragment shader from a file.
 * This function loads a single shader, vertex, geometry or
 *fragment, identified by the second argument.
 * The source must be a text file containing a valid
 *shader in GLSL language. GLSL is a C-like language
 *dedicated to OpenGL shaders; you'll probably need to
 *read a good documentation for it before writing your
 *own shaders.
 * Returns 1 if loading succeeded, 0 if it failed.
 */
MOON_CSFML_API int
moon_Shader_load(
	moon_Shader* self,
	const char* filepath,
	int shader_type
);

/**
 * Specifies value for float uniform with name 'name'.
 */
MOON_CSFML_API void
moon_Shader_set_uniform1(
	moon_Shader* self,
	const char* name,
	float x
);

/**
 * Specifies value for vec2 uniform with name 'name'.
 */
MOON_CSFML_API void
moon_Shader_set_uniform2(
	moon_Shader* self,
	const char* name,
	float x, float y
);

/**
 * Specifies value for vec3 uniform with name 'name'.
 */
MOON_CSFML_API void
moon_Shader_set_uniform3(
	moon_Shader* self,
	const char* name,
	float x, float y, float z
);

/**
 * Specifies value for vec4 uniform with name 'name'.
 */
MOON_CSFML_API void
moon_Shader_set_uniform4(
	moon_Shader* self,
	const char* name,
	float x, float y, float z, float w
);

/**
 * Specifies a texture as \p sampler2D uniform with name 'name'.
 */
MOON_CSFML_API void
moon_Shader_set_uniform_tex(
	moon_Shader* self,
	const char* name,
	const moon_Texture* texture
);

/**
 * Returns the underlying OpenGL handle of the shader.
 * You shouldn't need to use this function, unless you have
 *very specific stuff to implement that SFML doesn't support,
 *or implement a temporary workaround until a bug is fixed.
 */
MOON_CSFML_API unsigned int
moon_Shader_get_native_handle(const moon_Shader* self);

/**
 * Binds a shader for rendering.
 * This function is not part of the graphics API, it mustn't be
 *used when drawing SFML entities. It must be used only if you
 *mix sf::Shader with OpenGL code.
 */
MOON_CSFML_API void
moon_Shader_bind(const moon_Shader* self);

/**
 * Tells whether or not the system supports shaders.
 *
 * This function should always be called before using
 *the shader features. If it returns 0, then
 *any attempt to use Shader will fail.
 * Returns 1 if shaders are supported, 0 otherwise.
 */
MOON_CSFML_API int
moon_Shader_is_available();

/**
 * Tells whether or not the system supports geometry shaders.
 *
 * This function should always be called before using
 *the geometry shader features. If it returns 0, then
 *any attempt to use sf::Shader geometry shader features will fail.
 *
 * This function can only return 1 if isAvailable() would also
 *return 1, since shaders in general have to be supported in
 *order for geometry shaders to be supported as well.
 *
 * Note: The first call to this function, whether by your
 *code or SFML will result in a context switch.
 * Returns 1 if geometry shaders are supported, 0 otherwise.
 */
MOON_CSFML_API int
moon_Shader_is_geometry_available();


#ifdef __cplusplus
}
#endif


#endif
