// For the performance needs let's sacrifice access modifiers.

#define private public

#define protected public


#include "../../headers/system/moon_utils.h"


#include "../../headers/graphics/Converters.hpp"

#include "../../headers/graphics/RectUtils.hpp"


moon_Vertex
vertex_sf_to_moon(const sf::Vertex& vertex) {
	return {
		{vertex.position.x, vertex.position.y},
		color_sf_to_moon(vertex.color),
		{vertex.texCoords.x, vertex.texCoords.y}
	};
}

sf::Vertex
vertex_moon_to_sf(const moon_Vertex& vertex) {
	return sf::Vertex(
		sf::Vector2f(vertex.position.x, vertex.position.y),
		color_moon_to_sf(vertex.color),
		sf::Vector2f(vertex.tex_coords.x, vertex.tex_coords.y)
	);
}


moon_Glyph
glyph_sf_to_moon(const sf::Glyph& glyph) {
	return {
		glyph.advance,
		glyph.lsbDelta,
		glyph.rsbDelta,
		float_rect_sf_to_moon(glyph.bounds),
		int_rect_sf_to_moon(glyph.textureRect)
	};
}

sf::Glyph
glyph_moon_to_sf(const moon_Glyph& glyph) {
	sf::Glyph res;
	res.advance 		= glyph.advance;
	res.lsbDelta 		= glyph.lsb_delta;
	res.rsbDelta 		= glyph.rsb_delta;
	res.bounds 			= float_rect_moon_to_sf(glyph.bounds);
	res.textureRect 	= int_rect_moon_to_sf(glyph.texture_rect);
	return res;
}


moon_View
view_sf_to_moon(const sf::View& view) {
	return {
		view.m_rotation,							// rotation
		{view.m_center.x, 	view.m_center.y},		// center
		{view.m_size.x, 	view.m_size.y},			// size
		float_rect_sf_to_moon(view.m_viewport)		// viewport
	};
}

sf::View
view_moon_to_sf(const moon_View& view) {
	sf::View res(
		sf::Vector2f(view.center.x, view.center.y),	// center
		sf::Vector2f(view.size.x,	view.size.y)	// size
	);
	res.setRotation(view.rotation);
	res.setViewport(float_rect_moon_to_sf(view.viewport));
	return res;
}


moon_Color
color_sf_to_moon(const sf::Color& color) {
	return moon_Color_from_rgba(color.r, color.g, color.b, color.a);
}

sf::Color
color_moon_to_sf(const moon_Color& color) {
	return sf::Color(color.red, color.green, color.blue, color.alpha);
}


moon_Transform
transform_sf_to_moon(const sf::Transform& transform) {
	moon_Transform form;
	moon_memcpy(
		form.matrix,
		transform.getMatrix(),
		moon_Transform_MatrixSize * sizeof(float)
	);
	return form;
}

sf::Transform
transform_moon_to_sf(const moon_Transform& transform) {
	const float* matrix = transform.matrix;
	return sf::Transform(
		matrix[0], matrix[4], matrix[12],
		matrix[1], matrix[5], matrix[13],
		matrix[3], matrix[7], matrix[15]
	);
}


moon_BlendMode
blend_mode_sf_to_moon(const sf::BlendMode& blend_mode) {
	return {
		static_cast<int>(blend_mode.colorSrcFactor),
		static_cast<int>(blend_mode.colorDstFactor),
		static_cast<int>(blend_mode.colorEquation),
		static_cast<int>(blend_mode.alphaSrcFactor),
		static_cast<int>(blend_mode.alphaDstFactor),
		static_cast<int>(blend_mode.alphaEquation)
	};
}

sf::BlendMode
blend_mode_moon_to_sf(const moon_BlendMode& blend_mode) {
	return sf::BlendMode(
		static_cast<sf::BlendMode::Factor>		(blend_mode.color_src_factor),
		static_cast<sf::BlendMode::Factor>		(blend_mode.color_dst_factor),
		static_cast<sf::BlendMode::Equation>	(blend_mode.color_equation),
		static_cast<sf::BlendMode::Factor>		(blend_mode.alpha_src_factor),
		static_cast<sf::BlendMode::Factor>		(blend_mode.alpha_dst_factor),
		static_cast<sf::BlendMode::Equation>	(blend_mode.alpha_equation)
	);
}


moon_IntRect
int_rect_sf_to_moon(const sf::IntRect& rect) {
	return moon_Rect_convert<sf::IntRect, moon_IntRect, int>(&rect);
}

sf::IntRect
int_rect_moon_to_sf(const moon_IntRect& rect) {
	return moon_Rect_convert<moon_IntRect, sf::IntRect, int>(&rect);
}


moon_FloatRect
float_rect_sf_to_moon(const sf::FloatRect& rect) {
	return moon_Rect_convert<sf::FloatRect, moon_FloatRect, float>(&rect);
}

sf::FloatRect
float_rect_moon_to_sf(const moon_FloatRect& rect) {
	return moon_Rect_convert<moon_FloatRect, sf::FloatRect, float>(&rect);
}


#undef private

#undef protected
