#ifndef MOON_CSFML_GRAPHICS_RECTANGLE_SHAPE_STRUCT_HPP
#define MOON_CSFML_GRAPHICS_RECTANGLE_SHAPE_STRUCT_HPP


#include <SFML/Graphics/RectangleShape.hpp>


#include "./BoundedDrawable.hpp"


struct moon_RectangleShape : public sf::RectangleShape, public moon_BoundedDrawable {

	moon_RectangleShape(float width, float height);

	virtual moon_FloatRect get_global_bounds() const;

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};


#endif
