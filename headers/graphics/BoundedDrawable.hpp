#ifndef MOON_CSFML_GRAPHICS_BOUNDED_DRAWABLE_HPP
#define MOON_CSFML_GRAPHICS_BOUNDED_DRAWABLE_HPP


#include <SFML/Graphics/Drawable.hpp>



#include "../graphics/moon_rect.h"


class MOON_CSFML_API moon_BoundedDrawable : public sf::Drawable {
public:

	virtual ~moon_BoundedDrawable() = default;


	virtual moon_FloatRect get_global_bounds() const = 0;

};


#endif
