#ifndef MOON_CSFML_EXTRAS_MOON_GUI_FPSCNTR_H
#define MOON_CSFML_EXTRAS_MOON_GUI_FPSCNTR_H


#include "../system/moon_angle.h"

#include "../system/moon_vector2.h"


#include "../graphics/moon_rect.h"

#include "../graphics/moon_font.h"

#include "../graphics/moon_color.h"

#include "../graphics/moon_transform.h"

#include "../graphics/moon_render_states.h"

#include "../graphics/moon_render_window.h"


#ifdef __cplusplus
extern "C" {
#endif


#include <wchar.h>


struct MOON_CSFML_API moon_guiFpsCntr;


/**
 * Structure for graphically displaying
 *the current FPS (frames per second).
 */
typedef struct moon_guiFpsCntr moon_guiFpsCntr;


/**
 * Creates a counter with font and character size.
 * 'precision' is the number of digits after the
 *decimal point for FPS rounding.
 * 'update_time' determines the number of seconds
 *until the next text update.
 * Counter is stopped by default.
 */
MOON_CSFML_API moon_guiFpsCntr*
moon_guiFpsCntr_create(
	int precision,
	float update_time,
	const moon_Font* font,
	unsigned int character_size
);

/**
 * Creates a counter with font, character size
 *and fill color.
 * 'precision' is the number of digits after the
 *decimal point for FPS rounding.
 * 'update_time' determines the number of seconds
 *until the next text update.
 * Counter is stopped by default.
 */
MOON_CSFML_API moon_guiFpsCntr*
moon_guiFpsCntr_create_ex(
	int precision,
	float update_time,
	const moon_Font* font,
	unsigned int character_size,
	const moon_Color* fill_color
);

/**
 * Stops and destroys the counter.
 */
MOON_CSFML_API void
moon_guiFpsCntr_destroy(moon_guiFpsCntr* self);

/**
 * Returns 1 if counter is running, 0 otherwise.
 */
MOON_CSFML_API int
moon_guiFpsCntr_is_running(const moon_guiFpsCntr* self);

/**
 * Stops fps counter.
 * Counter is stopped by default.
 */
MOON_CSFML_API void
moon_guiFpsCntr_stop(moon_guiFpsCntr* self);

/**
 * Starts counter.
 * Counter is stopped by default.
 */
MOON_CSFML_API void
moon_guiFpsCntr_start(moon_guiFpsCntr* self);

/**
 * Updates the counter if it is not stopped.
 * For it to work correctly, the function must
 *be called in the game loop.
 * The text will be realigned automatically.
 * The orientation preserves the original right-top
 *corner position in global coordinates.
 */
MOON_CSFML_API void
moon_guiFpsCntr_update(moon_guiFpsCntr* self);

/**
 * Draws object to the RenderWindow.
 */
MOON_CSFML_API void
moon_guiFpsCntr_draw(
	const moon_guiFpsCntr* self,
	moon_RenderWindow* wnd,
	const moon_RenderStates* states
);

/**
 * Returns current fps(frames per second).
 */
MOON_CSFML_API float
moon_guiFpsCntr_get_fps(const moon_guiFpsCntr* self);

/**
 * Returns current fps(frames per second)
 *as ansi string.
 */
MOON_CSFML_API const char*
moon_guiFpsCntr_get_fps_strA(const moon_guiFpsCntr* self);

/**
 * Returns current fps(frames per second)
 *as wide string.
 */
MOON_CSFML_API const wchar_t*
moon_guiFpsCntr_get_fps_strW(const moon_guiFpsCntr* self);

// Text begin.

/**
 * Returns size of text object.
 * Size is defined by global bounds.
 */
MOON_CSFML_API moon_Vector2f
moon_guiFpsCntr_get_size(const moon_guiFpsCntr* self);

/**
 * Sets the text's font.
 *
 * The \a font argument refers to a font that must
 *exist as long as the text uses it. Indeed, the text
 *doesn't store its own copy of the font, but rather keeps
 *a pointer to the one that you passed to this function.
 * If the font is destroyed and the text tries to
 *use it, the behavior is undefined.
 */
MOON_CSFML_API void
moon_guiFpsCntr_set_font(
	moon_guiFpsCntr* self,
	const moon_Font* font
);

/**
 * Sets the character size.
 *
 * The default size is 30.
 *
 * Note that if the used font is a bitmap font, it is not
 *scalable, thus not all requested sizes will be available
 *to use. This needs to be taken into consideration when
 *setting the character size. If you need to display text
 *of a certain size, make sure the corresponding bitmap
 *font that supports that size is used.
 */
MOON_CSFML_API void
moon_guiFpsCntr_set_character_size(
	moon_guiFpsCntr* self,
	unsigned int character_size
);

/**
 * Sets the line spacing factor.
 * The default spacing between lines is defined by the font.
 * This method enables you to set a factor for the spacing
 * between lines. By default the line spacing factor is 1.
 */
MOON_CSFML_API void
moon_guiFpsCntr_set_line_spacing(
	moon_guiFpsCntr* self,
	float spacing_factor
);

/**
 * Sets the letter spacing factor.
 *
 * The default spacing between letters is defined by the font.
 * This factor doesn't directly apply to the existing
 *spacing between each character, it rather adds a fixed
 *space between them which is calculated from the font
 *metrics and the character size.
 * Note that factors below 1 (including negative numbers) bring
 *characters closer to each other.
 * By default the letter spacing factor is 1.
 */
MOON_CSFML_API void
moon_guiFpsCntr_set_letter_spacing(
	moon_guiFpsCntr* self,
	float spacing_factor
);

/**
 * Sets the text's style.
 * You can pass a combination of one or more styles, for
 *example(SFML) sf::Text::Bold | sf::Text::Italic.
 * The default style is sf::Text::Regular.
 */
MOON_CSFML_API void
moon_guiFpsCntr_set_style(
	moon_guiFpsCntr* self,
	unsigned int style
);

/**
 * Set the fill color of the text.
 * By default, the text's fill color is opaque white.
 * Setting the fill color to a transparent color with an outline
 *will cause the outline to be displayed in the fill area of the text.
 */
MOON_CSFML_API void
moon_guiFpsCntr_set_fill_color(
	moon_guiFpsCntr* self,
	const moon_Color* fill_color
);

/**
 * Sets the outline color of the text.
 * By default, the text's outline color is opaque black.
 */
MOON_CSFML_API void
moon_guiFpsCntr_set_outline_color(
	moon_guiFpsCntr* self,
	const moon_Color* outline_color
);

/**
 * Sets the thickness of the text's outline.
 * By default, the outline thickness is 0.
 * Be aware that using a negative value for the outline
 *thickness will cause distorted rendering.
 */
MOON_CSFML_API void
moon_guiFpsCntr_set_outline_thickness(
	moon_guiFpsCntr* self,
	float outline_thickness
);

/**
 * Returns the text's font,
 * If the text has no font attached, a NULL pointer is returned.
 * The returned pointer is const, which means that you
 *cannot modify the font when you get it from this function.
 */
MOON_CSFML_API const moon_Font*
moon_guiFpsCntr_get_font(const moon_guiFpsCntr* self);

/**
 * Returns the character size.
 */
MOON_CSFML_API unsigned int
moon_guiFpsCntr_get_character_size(const moon_guiFpsCntr* self);

/**
 * Returns the size of the letter spacing factor.
 */
MOON_CSFML_API float
moon_guiFpsCntr_get_letter_spacing(const moon_guiFpsCntr* self);

/**
 * Returns the size of the line spacing factor.
 */
MOON_CSFML_API float
moon_guiFpsCntr_get_line_spacing(const moon_guiFpsCntr* self);

/**
 * Returns the text's style.
 */
MOON_CSFML_API unsigned int
moon_guiFpsCntr_get_style(const moon_guiFpsCntr* self);

/**
 * Returns copy of the fill color of the text.
 */
MOON_CSFML_API moon_Color
moon_guiFpsCntr_get_fill_color(const moon_guiFpsCntr* self);

/**
 * Returns copy of the outline color of the text.
 */
MOON_CSFML_API moon_Color
moon_guiFpsCntr_get_outline_color(const moon_guiFpsCntr* self);

/**
 * Returns the outline thickness of the text.
 */
MOON_CSFML_API float
moon_guiFpsCntr_get_outline_thickness(const moon_guiFpsCntr* self);

/**
 * Returns the local bounding rectangle of the entity.
 * The returned rectangle is in local coordinates, which means
 *that it ignores the transformations (translation, rotation,
 *scale, ...) that are applied to the entity.
 * In other words, this function returns the bounds of the
 *entity in the entity's coordinate system.
 */
MOON_CSFML_API moon_FloatRect
moon_guiFpsCntr_get_local_bounds(const moon_guiFpsCntr* self);

/**
 * Returns the global bounding rectangle of the entity.
 * The returned rectangle is in global coordinates, which means
 *that it takes into account the transformations (translation,
 *rotation, scale, ...) that are applied to the entity.
 * In other words, this function returns the bounds of the
 *text in the global 2D world's coordinate system.
 */
MOON_CSFML_API moon_FloatRect
moon_guiFpsCntr_get_global_bounds(const moon_guiFpsCntr* self);

/**
 * Sets the position of the counter.
 */
MOON_CSFML_API void
moon_guiFpsCntr_set_position(
	moon_guiFpsCntr* self,
	float left, float top
);

/**
 * Sets the orientation of the object.
 * This function completely overwrites the previous rotation.
 * See the rotate function to add an angle based on the previous rotation instead.
 * The default rotation of a transformable object is 0.
 */
MOON_CSFML_API void
moon_guiFpsCntr_set_rotation(
	moon_guiFpsCntr* self,
	moon_Angle angle
);

/**
 * Sets the scale factors of the object.
 * This function completely overwrites the previous scale.
 * See the scale function to add a factor based on the previous scale instead.
 * The default scale of a transformable object is (1, 1).
 */
MOON_CSFML_API void
moon_guiFpsCntr_set_scale(
	moon_guiFpsCntr* self,
	float scale_x, float scale_y
);

/**
 * Sets the local origin of the object.
 * The origin of an object defines the center point for
 * all transformations (position, scale, rotation).
 * The coordinates of this point must be relative to the
 * top-left corner of the object, and ignore all
 * transformations (position, scale, rotation).
 * The default origin of a transformable object is (0, 0).
 */
MOON_CSFML_API void
moon_guiFpsCntr_set_origin(
	moon_guiFpsCntr* self,
	float x, float y
);

/**
 * Returns the position of the object.
 */
MOON_CSFML_API moon_Vector2f
moon_guiFpsCntr_get_position(const moon_guiFpsCntr* self);

/**
 * Returns the orientation of the object.
 *
 * The rotation is always in the range(degrees) [0, 360].
 */
MOON_CSFML_API moon_Angle
moon_guiFpsCntr_get_rotation(const moon_guiFpsCntr* self);

/**
 * Returns the current scale of the object.
 */
MOON_CSFML_API moon_Vector2f
moon_guiFpsCntr_get_scale(const moon_guiFpsCntr* self);

/**
 * Returns the local origin of the object.
 */
MOON_CSFML_API moon_Vector2f
moon_guiFpsCntr_get_origin(const moon_guiFpsCntr* self);

/**
 * Moves the object by a given offset.
 * This function adds to the current position of the object,
 *unlike setPosition which overwrites it.
 * Thus, it is equivalent to the following code(SFML example):
 * \code
 * sf::Vector2f pos = object.getPosition();
 * object.setPosition(pos.x + offsetX, pos.y + offsetY);
 * \endcode
 */
MOON_CSFML_API void
moon_guiFpsCntr_move(
	moon_guiFpsCntr* self,
	float dx, float dy
);

/**
 * Rotates the object.
 * This function adds to the current rotation of the object,
 *unlike setRotation which overwrites it.
 * Thus, it is equivalent to the following code(SFML example):
 * \code
 * object.setRotation(object.getRotation() + angle);
 * \endcode
 */
MOON_CSFML_API void
moon_guiFpsCntr_rotate(
	moon_guiFpsCntr* self,
	moon_Angle angle
);

/**
 * Scales the object.
 * This function multiplies the current scale of the object,
 *unlike setScale which overwrites it.
 * Thus, it is equivalent to the following code(SFML example):
 * \code
 * sf::Vector2f scale = object.getScale();
 * object.setScale(scale.x * factorX, scale.y * factorY);
 * \endcode
 */
MOON_CSFML_API void
moon_guiFpsCntr_scale(
	moon_guiFpsCntr* self,
	float scale_x, float scale_y
);

/**
 * Returns transform combining the position/rotation/scale/origin of the object.
 * This operation is slow, because it copies SFML transform to C
 *compatible transform.
 */
MOON_CSFML_API moon_Transform
moon_guiFpsCntr_get_transform(const moon_guiFpsCntr* self);

/**
 * Returns inverse of the combined transformations applied to the object.
 * This operation is slow, because it copies SFML transform to C
 *compatible transform.
 */
MOON_CSFML_API moon_Transform
moon_guiFpsCntr_get_inverse_transform(const moon_guiFpsCntr* self);

/**
 * Returns 1 if internal transform is updated, 0 otherwise.
 * Use it if you want to cache C transform or/and C inversed
 *transform.
 */
MOON_CSFML_API int
moon_guiFpsCntr_is_transform_updated(const moon_guiFpsCntr* self);

/**
 * Returns 1 if internal inversed transform is updated, 0 otherwise.
 * Use it if you want to cache C inversed transform.
 */
MOON_CSFML_API int
moon_guiFpsCntr_is_inversed_transform_updated(const moon_guiFpsCntr* self);

// Text end.


#ifdef __cplusplus
}
#endif


#endif
