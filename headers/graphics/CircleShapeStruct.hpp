#ifndef MOON_CSFML_GRAPHICS_CIRCLE_SHAPE_STRUCT_HPP
#define MOON_CSFML_GRAPHICS_CIRCLE_SHAPE_STRUCT_HPP


#include <SFML/Graphics/CircleShape.hpp>


#include "./BoundedDrawable.hpp"


struct moon_CircleShape : public sf::CircleShape, public moon_BoundedDrawable {

	moon_CircleShape(
		float radius,
		unsigned long point_count
	);

	virtual moon_FloatRect get_global_bounds() const;

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};


#endif
