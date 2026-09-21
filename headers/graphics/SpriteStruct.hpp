#ifndef MOON_CSFML_GRAPHICS_SPRITE_STRUCT_HPP
#define MOON_CSFML_GRAPHICS_SPRITE_STRUCT_HPP


#include <SFML/Graphics/Sprite.hpp>



#include "./moon_texture.h"

#include "./BoundedDrawable.hpp"


struct moon_Sprite : public sf::Sprite, public moon_BoundedDrawable {

	moon_Sprite(const moon_Texture* texture);

	moon_Sprite(
		const moon_Texture* texture,
		const moon_IntRect* area
	);

	virtual moon_FloatRect get_global_bounds() const;

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};


#endif
