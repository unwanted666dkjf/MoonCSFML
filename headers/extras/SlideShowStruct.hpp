#ifndef MOON_CSFML_EXTRAS_SLIDE_SHOW_STRUCT_HPP
#define MOON_CSFML_EXTRAS_SLIDE_SHOW_STRUCT_HPP


#include <vector>



#include "../../headers/system/moon_clock.h"


#include "../../headers/graphics/SpriteStruct.hpp"

#include "../../headers/graphics/BoundedDrawable.hpp"


struct moon_SlideShow : public moon_BoundedDrawable {

	moon_SlideShow(
		unsigned long v_initial_size,
		float v_width, float v_heigth,
		int v_fixed_w, int v_fixed_h,
		float v_secs_per_frame
	);

	virtual moon_FloatRect get_global_bounds() const;


	int 						fixed_w;
	int 						fixed_h;
	float 						width;
	float 						height;
	float 						cum_time;
	float 						secs_per_frame;
	unsigned long 				ind;
	moon_Clock* 				clock;
	std::vector<moon_Sprite> 	sprites;

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};


#endif
