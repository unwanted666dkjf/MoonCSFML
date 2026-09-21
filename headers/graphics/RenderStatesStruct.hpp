#ifndef MOON_CSFML_GRAPHICS_RENDER_STATES_STRUCT_HPP
#define MOON_CSFML_GRAPHICS_RENDER_STATES_STRUCT_HPP


#include <SFML/Graphics/RenderStates.hpp>



#include "./moon_shader.h"

#include "./moon_texture.h"

#include "./moon_transform.h"

#include "./moon_blend_mode.h"


struct moon_RenderStates : public sf::RenderStates {

	moon_RenderStates();

	moon_RenderStates(const moon_BlendMode* blend_mode);

	moon_RenderStates(const moon_Transform* transform);

	moon_RenderStates(const moon_Texture* 	texture);

	moon_RenderStates(const moon_Shader* 	shader);

	moon_RenderStates(
		const moon_BlendMode* 	blend_mode,
		const moon_Transform* 	transform,
		const moon_Texture* 	texture,
		const moon_Shader* 		shader
	);

};


#endif
