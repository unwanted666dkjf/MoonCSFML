#ifndef MOON_CSFML_EXTRAS_TEXT_WRITE_STRUCT_HPP
#define MOON_CSFML_EXTRAS_TEXT_WRITE_STRUCT_HPP


#include <SFML/System/String.hpp>



#include "../system/moon_clock.h"


#include "../graphics/FontStruct.hpp"

#include "../graphics/TextStruct.hpp"

#include "../graphics/BoundedDrawable.hpp"


struct moon_TextWrite : public moon_BoundedDrawable {

	moon_TextWrite(
		float v_typing_speed,
		const moon_Font* v_font,
		unsigned int v_character_size
	);

	~moon_TextWrite();

	virtual moon_FloatRect get_global_bounds() const;

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


	unsigned long cur_ind;

	float typing_speed;

	sf::String text_to_type;			// Because it has better unicode support

	moon_Text* text;

	moon_Clock* clock;

};


#endif
