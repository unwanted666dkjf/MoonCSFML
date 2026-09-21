#include "../../headers/graphics/moon_render_states.h"

#include "../../headers/graphics/Converters.hpp"

#include "../../headers/graphics/ShaderStruct.hpp"

#include "../../headers/graphics/TextureStruct.hpp"

#include "../../headers/graphics/RenderStatesStruct.hpp"


moon_RenderStates*
moon_RenderStates_default() {
	return new moon_RenderStates();
}

moon_RenderStates*
moon_RenderStates_from_blend_mode(const moon_BlendMode* blend_mode) {
	return new moon_RenderStates(blend_mode);
}

moon_RenderStates*
moon_RenderStates_from_transform(const moon_Transform* transform) {
	return new moon_RenderStates(transform);
}

moon_RenderStates*
moon_RenderStates_from_texture(const moon_Texture* texture) {
	return new moon_RenderStates(texture);
}

moon_RenderStates*
moon_RenderStates_from_shader(const moon_Shader* shader) {
	return new moon_RenderStates(shader);
}

moon_RenderStates*
moon_RenderStates_create(
	const moon_BlendMode* 	blend_mode,
	const moon_Transform* 	transform,
	const moon_Texture* 	texture,
	const moon_Shader* 		shader
) {
	return new moon_RenderStates(
		blend_mode,
		transform,
		texture,
		shader
	);
}

void
moon_RenderStates_destroy(moon_RenderStates* self) {
	delete self;
}

moon_BlendMode
moon_RenderStates_get_blend_mode(const moon_RenderStates* self) {
	return blend_mode_sf_to_moon(self->blendMode);
}

moon_Transform
moon_RenderStates_get_transform(const moon_RenderStates* self) {
	return transform_sf_to_moon(self->transform);
}

const moon_Texture*
moon_RenderStates_get_texture(const moon_RenderStates* self) {
	return static_cast<const moon_Texture*>(self->texture);
}

const moon_Shader*
moon_RenderStates_get_shader(const moon_RenderStates* self) {
	return static_cast<const moon_Shader*>(self->shader);
}


moon_RenderStates::moon_RenderStates() : sf::RenderStates() {
	//
}

moon_RenderStates::moon_RenderStates(const moon_BlendMode* blend_mode) : sf::RenderStates(
	blend_mode_moon_to_sf(*blend_mode)
) {
	//
}

moon_RenderStates::moon_RenderStates(const moon_Transform* transform) : sf::RenderStates(
	transform_moon_to_sf(*transform)
) {
	//
}

moon_RenderStates::moon_RenderStates(const moon_Texture* texture) : sf::RenderStates(
	static_cast<const sf::Texture*>(texture)
) {
	//
}

moon_RenderStates::moon_RenderStates(const moon_Shader* shader) : sf::RenderStates(
	static_cast<const sf::Shader*>(shader)
) {
	//
}

moon_RenderStates::moon_RenderStates(
	const moon_BlendMode* 	blend_mode,
	const moon_Transform* 	transform,
	const moon_Texture* 	texture,
	const moon_Shader* 		shader
) : sf::RenderStates(
	blend_mode_moon_to_sf(*blend_mode),
	transform_moon_to_sf(*transform),
	static_cast<const sf::Texture*>(texture),
	static_cast<const sf::Shader*>(shader)
) {
	//
}
