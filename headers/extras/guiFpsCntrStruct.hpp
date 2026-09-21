#ifndef MOON_CSFML_EXTRAS_GUI_FPSCNTR_STRUCT_HPP
#define MOON_CSFML_EXTRAS_GUI_FPSCNTR_STRUCT_HPP


#include "../system/moon_clock.h"


#include "../graphics/FontStruct.hpp"

#include "../graphics/TextStruct.hpp"

#include "../graphics/BoundedDrawable.hpp"


struct moon_guiFpsCntr : public moon_BoundedDrawable {

	moon_guiFpsCntr(
		int v_precision,
		float v_update_time,
		const moon_Font* v_font,
		unsigned int v_character_size
	);

	~moon_guiFpsCntr();

	virtual moon_FloatRect get_global_bounds() const;

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


	int 			precision;

	float 			cur_fps;

	float 			update_time;

	moon_Text* 		gui_fps;

	moon_Clock* 	clock;

};


#endif
