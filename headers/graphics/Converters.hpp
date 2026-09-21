#ifndef MOON_CSFML_GRAPHICS_CONVERTERS_HPP
#define MOON_CSFML_GRAPHICS_CONVERTERS_HPP


#include <SFML/Graphics/View.hpp>

#include <SFML/Graphics/Rect.hpp>

#include <SFML/Graphics/Color.hpp>

#include <SFML/Graphics/Glyph.hpp>

#include <SFML/Graphics/Vertex.hpp>

#include <SFML/Graphics/Transform.hpp>

#include <SFML/Graphics/BlendMode.hpp>



#include "./moon_view.h"

#include "./moon_rect.h"

#include "./moon_color.h"

#include "./moon_glyph.h"

#include "./moon_vertex.h"

#include "./moon_transform.h"

#include "./moon_blend_mode.h"


/**
 * Converts C++ vertex to C vertex.
 */
moon_Vertex
vertex_sf_to_moon(const sf::Vertex& vertex);

/**
 * Converts C vertex to C++ vertex.
 */
sf::Vertex
vertex_moon_to_sf(const moon_Vertex& vertex);


/**
 * Converts C++ glyph to C glyph.
 */
moon_Glyph
glyph_sf_to_moon(const sf::Glyph& glyph);

/**
 * Converts C glyph to C++ glyph.
 */
sf::Glyph
glyph_moon_to_sf(const moon_Glyph& glyph);


/**
 * Converts C++ view to C view.
 */
moon_View
view_sf_to_moon(const sf::View& view);

/**
 * Converts C view to C++ view.
 */
sf::View
view_moon_to_sf(const moon_View& view);


/**
 * Converts C++ color to C color.
 */
moon_Color
color_sf_to_moon(const sf::Color& color);

/**
 * Converts C color to C++ color.
 */
sf::Color
color_moon_to_sf(const moon_Color& color);


/**
 * Converts C++ transform to C transform.
 */
moon_Transform
transform_sf_to_moon(const sf::Transform& transform);

/**
 * Converts C transform to C++ transform.
 */
sf::Transform
transform_moon_to_sf(const moon_Transform& transform);


/**
 * Converts C++ BlendMode to C BlendMode.
 */
moon_BlendMode
blend_mode_sf_to_moon(const sf::BlendMode& blend_mode);

/**
 * Converts C BlendMode to C++ BlendMode.
 */
sf::BlendMode
blend_mode_moon_to_sf(const moon_BlendMode& blend_mode);


/**
 * Converts C++ IntRect to C IntRect.
 */
moon_IntRect
int_rect_sf_to_moon(const sf::IntRect& rect);

/**
 * Converts C IntRect to C++ IntRect.
 */
sf::IntRect
int_rect_moon_to_sf(const moon_IntRect& rect);


/**
 * Converts C++ FloatRect to C FloatRect.
 */
moon_FloatRect
float_rect_sf_to_moon(const sf::FloatRect& rect);

/**
 * Converts C++ FloatRect to C FloatRect.
 */
sf::FloatRect
float_rect_moon_to_sf(const moon_FloatRect& rect);


#endif
