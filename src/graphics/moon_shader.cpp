#include "../../headers/graphics/moon_shader.h"

#include "../../headers/graphics/ShaderStruct.hpp"

#include "../../headers/graphics/TextureStruct.hpp"


moon_Shader*
moon_Shader_create() {
	return new moon_Shader();
}

void
moon_Shader_destroy(moon_Shader* self) {
	delete self;
}

int
moon_Shader_load(
	moon_Shader* self,
	const char* filepath,
	int shader_type
) {
	return self->loadFromFile(
		std::string(filepath),
		static_cast<sf::Shader::Type>(shader_type)
	);
}

void
moon_Shader_set_uniform1(
	moon_Shader* self,
	const char* name,
	float x
) {
	self->setUniform(std::string(name), x);
}

void
moon_Shader_set_uniform2(
	moon_Shader* self,
	const char* name,
	float x, float y
) {
	self->setUniform(std::string(name), sf::Glsl::Vec2(x, y));
}

void
moon_Shader_set_uniform3(
	moon_Shader* self,
	const char* name,
	float x, float y, float z
) {
	self->setUniform(std::string(name), sf::Glsl::Vec3(x, y, z));
}

void
moon_Shader_set_uniform4(
	moon_Shader* self,
	const char* name,
	float x, float y, float z, float w
) {
	self->setUniform(std::string(name), sf::Glsl::Vec4(x, y, z, w));
}

void
moon_Shader_set_uniform_tex(
	moon_Shader* self,
	const char* name,
	const moon_Texture* texture
) {
	const sf::Texture* tex = static_cast<const sf::Texture*>(texture);
	self->setUniform(std::string(name), *tex);
}

unsigned int
moon_Shader_get_native_handle(const moon_Shader* self) {
	return self->getNativeHandle();
}

void
moon_Shader_bind(const moon_Shader* self) {
	const sf::Shader* sha = static_cast<const sf::Shader*>(self);
	sf::Shader::bind(sha);
}

int
moon_Shader_is_available() {
	return sf::Shader::isAvailable();
}

int
moon_Shader_is_geometry_available() {
	return sf::Shader::isGeometryAvailable();
}


moon_Shader::moon_Shader() : sf::Shader() {
	//
}
