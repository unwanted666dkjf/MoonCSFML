#ifndef MOON_CSFML_EXTRAS_SLIDE_ANIMATION_STRUCT_HPP
#define MOON_CSFML_EXTRAS_SLIDE_ANIMATION_STRUCT_HPP


#include <vector>



#include "../../headers/graphics/SpriteStruct.hpp"

#include "../../headers/graphics/BoundedDrawable.hpp"


struct moon_SlideAnimation : public moon_BoundedDrawable {

	moon_SlideAnimation(
		unsigned long v_initial_size,
		float v_width, float v_heigth,
		int v_fixed_w, int v_fixed_h,
		float v_anim_speed
	);

	virtual moon_FloatRect get_global_bounds() const;


	int 						fixed_w;
	int 						fixed_h;
	float 						width;
	float 						height;
	float 						ind;
	float 						anim_speed;
	unsigned long 				cur_ind;
	std::vector<moon_Sprite> 	sprites;

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};


#endif
