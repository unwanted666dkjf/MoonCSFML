#ifndef MOON_CSFML_GRAPHICS_CONVEX_SHAPE_STRUCT_HPP
#define MOON_CSFML_GRAPHICS_CONVEX_SHAPE_STRUCT_HPP


#include <SFML/Graphics/ConvexShape.hpp>


#include "./BoundedDrawable.hpp"


struct moon_ConvexShape : public sf::ConvexShape, public moon_BoundedDrawable {

	moon_ConvexShape(unsigned long point_count);

	virtual moon_FloatRect get_global_bounds() const;

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};


#endif
