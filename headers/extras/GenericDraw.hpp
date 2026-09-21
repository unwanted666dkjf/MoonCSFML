#ifndef MOON_CSFML_EXTRAS_GENERIC_DRAW_HPP
#define MOON_CSFML_EXTRAS_GENERIC_DRAW_HPP


#include "./moon_useful_funcs.h"


#include "../graphics/BoundedDrawable.hpp"

#include "../graphics/RenderStatesStruct.hpp"

#include "../graphics/RenderWindowStruct.hpp"


// Generic, because drawable cannot be directly and safely upcasted to moon_BoundedDrawable
template <typename BoundedDrawable>
void moon_generic_draw(
	const BoundedDrawable* drawable,
	moon_RenderWindow* wnd,
	const moon_RenderStates* states,
	const int& check_visibility
) {
	const moon_BoundedDrawable* bounded = static_cast<const moon_BoundedDrawable*>(drawable);
	if (check_visibility) {
		moon_FloatRect bounds = bounded->get_global_bounds();
		moon_FloatRect visibility_rect = moon_is_rect_visible(&bounds, wnd);
		if (moon_FloatRect_is_empty(&visibility_rect)) {
			return;
		}
	}
	wnd->draw(*bounded, *states);
}


#endif
