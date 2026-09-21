#ifndef MOON_CSFML_GRAPHICS_MOON_RENDER_STATES_H
#define MOON_CSFML_GRAPHICS_MOON_RENDER_STATES_H


#include "./moon_shader.h"

#include "./moon_texture.h"

#include "./moon_transform.h"

#include "./moon_blend_mode.h"


#ifdef __cplusplus
extern "C" {
#endif


struct MOON_CSFML_API moon_RenderStates;


/**
 * Defines the states used for drawing to a RenderWindow.
 */
typedef struct moon_RenderStates moon_RenderStates;


/**
 * Creates a default set of render states.
 * The default set defines:
 * \li the BlendAlph*a blend mode
 * \li the identity transform
 * \li a null texture
 * \li a null shader
 */
MOON_CSFML_API moon_RenderStates*
moon_RenderStates_default();

/**
 * Creates a default set of render states with a custom blend mode.
 */
MOON_CSFML_API moon_RenderStates*
moon_RenderStates_from_blend_mode(const moon_BlendMode* blend_mode);

/**
 * Creates a default set of render states with a custom transform.
 */
MOON_CSFML_API moon_RenderStates*
moon_RenderStates_from_transform(const moon_Transform* transform);

/**
 * Creates a default set of render states with a custom texture.
 */
MOON_CSFML_API moon_RenderStates*
moon_RenderStates_from_texture(const moon_Texture* texture);

/**
 * Creates a default set of render states with a custom shader.
 */
MOON_CSFML_API moon_RenderStates*
moon_RenderStates_from_shader(const moon_Shader* shader);

/**
 * Creates a set of render states with all its attributes.
 */
MOON_CSFML_API moon_RenderStates*
moon_RenderStates_create(
	const moon_BlendMode* 	blend_mode,
	const moon_Transform* 	transform,
	const moon_Texture* 	texture,
	const moon_Shader* 		shader
);

/**
 * Destroys render states.
 */
MOON_CSFML_API void
moon_RenderStates_destroy(moon_RenderStates* self);

/**
 * Returns copy of blending mode.
 */
MOON_CSFML_API moon_BlendMode
moon_RenderStates_get_blend_mode(const moon_RenderStates* self);

/**
 * Returns copy of transform.
 */
MOON_CSFML_API moon_Transform
moon_RenderStates_get_transform(const moon_RenderStates* self);

/**
 * Returns pointer to a texture.
 */
MOON_CSFML_API const moon_Texture*
moon_RenderStates_get_texture(const moon_RenderStates* self);

/**
 * Returns pointer to a shader.
 */
MOON_CSFML_API const moon_Shader*
moon_RenderStates_get_shader(const moon_RenderStates* self);


#ifdef __cplusplus
}
#endif


#endif
