#ifndef MOON_CSFML_GRAPHICS_MOON_TEXT_H
#define MOON_CSFML_GRAPHICS_MOON_TEXT_H


#include "./moon_rect.h"

#include "./moon_font.h"

#include "./moon_transform.h"

#include "./moon_render_states.h"

#include "./moon_render_window.h"


#include "../system/moon_angle.h"

#include "../system/moon_vector2.h"


#ifdef __cplusplus
extern "C" {
#endif


#include <wchar.h>


#define moon_Text_DefaultCharacterSize 			(30)

#define moon_Text_DefaultLineSpacingFactor 		(1)

#define moon_Text_DefaultLetterSpacingFactor 	(1)

#define moon_Text_DefaultOutlineThickness 		(0)


enum
{
	moon_Text_Style_Regular       = 0,      //!< Regular characters, no style
	moon_Text_Style_Bold          = 1 << 0, //!< Bold characters
	moon_Text_Style_Italic        = 1 << 1, //!< Italic characters
	moon_Text_Style_Underlined    = 1 << 2, //!< Underlined characters
	moon_Text_Style_StrikeThrough = 1 << 3  //!< Strike through characters
};


struct MOON_CSFML_API moon_Text;


/**
 * Graphical text that can be drawn to a render target.
 */
typedef struct moon_Text moon_Text;


/**
 * Creates an empty text.
 */
MOON_CSFML_API moon_Text*
moon_Text_default();

/**
 * Creates text from ansi string.
 */
MOON_CSFML_API moon_Text*
moon_Text_createA(
	const char* string,
	const moon_Font* font,
	unsigned int character_size
);

/**
 * Creates text from wide string.
 */
MOON_CSFML_API moon_Text*
moon_Text_createW(
	const wchar_t* string,
	const moon_Font* font,
	unsigned int character_size
);

/**
 * Destroys text.
 */
MOON_CSFML_API void
moon_Text_destroy(moon_Text* self);

/**
 * Draws text to the RenderWindow.
 */
MOON_CSFML_API void
moon_Text_draw(
	const moon_Text* self,
	moon_RenderWindow* wnd,
	const moon_RenderStates* states
);

/**
 * Returns size of text object.
 * Size is defined by global bounds.
 */
MOON_CSFML_API moon_Vector2f
moon_Text_get_size(const moon_Text* self);

/**
 * Sets the text's string(ansi)
 *if it's different from current.
 * String must be null-terminated.
 * A text's string is empty by default.
 * Returns 1 if string changed, 0 otherwise.
 */
MOON_CSFML_API int
moon_Text_set_stringA(
	moon_Text* self,
	const char* string
);

/**
 * Sets the text's string(wide)
 *if it's different from current.
 * String must be null-terminated.
 * A text's string is empty by default.
 * Returns 1 if string changed, 0 otherwise.
 */
MOON_CSFML_API int
moon_Text_set_stringW(
	moon_Text* self,
	const wchar_t* string
);

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
moon_Text_set_font(
	moon_Text* self,
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
moon_Text_set_character_size(
	moon_Text* self,
	unsigned int character_size
);

/**
 * Sets the line spacing factor.
 * The default spacing between lines is defined by the font.
 * This method enables you to set a factor for the spacing
 * between lines. By default the line spacing factor is 1.
 */
MOON_CSFML_API void
moon_Text_set_line_spacing(
	moon_Text* self,
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
moon_Text_set_letter_spacing(
	moon_Text* self,
	float spacing_factor
);

/**
 * Sets the text's style.
 * You can pass a combination of one or more styles, for
 *example(SFML) sf::Text::Bold | sf::Text::Italic.
 * The default style is sf::Text::Regular.
 */
MOON_CSFML_API void
moon_Text_set_style(
	moon_Text* self,
	unsigned int style
);

/**
 * Set the fill color of the text.
 * By default, the text's fill color is opaque white.
 * Setting the fill color to a transparent color with an outline
 *will cause the outline to be displayed in the fill area of the text.
 */
MOON_CSFML_API void
moon_Text_set_fill_color(
	moon_Text* self,
	const moon_Color* fill_color
);

/**
 * Sets the outline color of the text.
 * By default, the text's outline color is opaque black.
 */
MOON_CSFML_API void
moon_Text_set_outline_color(
	moon_Text* self,
	const moon_Color* outline_color
);

/**
 * Sets the thickness of the text's outline.
 * By default, the outline thickness is 0.
 * Be aware that using a negative value for the outline
 *thickness will cause distorted rendering.
 */
MOON_CSFML_API void
moon_Text_set_outline_thickness(
	moon_Text* self,
	float outline_thickness
);

/**
 * Returns the text's string(ansi).
 * String exists until text exists.
 * String is null-terminated.
 */
MOON_CSFML_API const char*
moon_Text_get_stringA(const moon_Text* self);

/**
 * Returns the text's string(wide).
 * String exists until text exists.
 * String is null-terminated.
 */
MOON_CSFML_API const wchar_t*
moon_Text_get_stringW(const moon_Text* self);

/**
 * Returns the text's font,
 * If the text has no font attached, a NULL pointer is returned.
 * The returned pointer is const, which means that you
 *cannot modify the font when you get it from this function.
 */
MOON_CSFML_API const moon_Font*
moon_Text_get_font(const moon_Text* self);

/**
 * Returns the character size.
 */
MOON_CSFML_API unsigned int
moon_Text_get_character_size(const moon_Text* self);

/**
 * Returns the size of the letter spacing factor.
 */
MOON_CSFML_API float
moon_Text_get_letter_spacing(const moon_Text* self);

/**
 * Returns the size of the line spacing factor.
 */
MOON_CSFML_API float
moon_Text_get_line_spacing(const moon_Text* self);

/**
 * Returns the text's style.
 */
MOON_CSFML_API unsigned int
moon_Text_get_style(const moon_Text* self);

/**
 * Returns copy of the fill color of the text.
 */
MOON_CSFML_API moon_Color
moon_Text_get_fill_color(const moon_Text* self);

/**
 * Returns copy of the outline color of the text.
 */
MOON_CSFML_API moon_Color
moon_Text_get_outline_color(const moon_Text* self);

/**
 * Returns the outline thickness of the text.
 */
MOON_CSFML_API float
moon_Text_get_outline_thickness(const moon_Text* self);

/**
 * Returns the position of the \a index-th character.
 * This function computes the visual position of a character
 *from its index in the string. The returned position is
 *in global coordinates (translation, rotation, scale and
 *origin are applied).
 * If \a index is out of range, the position of the end of
 *the string is returned.
 */
MOON_CSFML_API moon_Vector2f
moon_Text_find_character_position(
	const moon_Text* self,
	unsigned long index
);

/**
 * Returns the local bounding rectangle of the entity.
 * The returned rectangle is in local coordinates, which means
 *that it ignores the transformations (translation, rotation,
 *scale, ...) that are applied to the entity.
 * In other words, this function returns the bounds of the
 *entity in the entity's coordinate system.
 */
MOON_CSFML_API moon_FloatRect
moon_Text_get_local_bounds(const moon_Text* self);

/**
 * Returns the global bounding rectangle of the entity.
 * The returned rectangle is in global coordinates, which means
 *that it takes into account the transformations (translation,
 *rotation, scale, ...) that are applied to the entity.
 * In other words, this function returns the bounds of the
 *text in the global 2D world's coordinate system.
 */
MOON_CSFML_API moon_FloatRect
moon_Text_get_global_bounds(const moon_Text* self);


// Transformable begin

/**
 * Sets the position of the object.
 *
 * This function completely overwrites the previous position.
 * See the move function to apply an offset based on the previous position instead.
 * The default position of a transformable object is (0, 0).
 */
MOON_CSFML_API void
moon_Text_set_position(
	moon_Text* self,
	float left, float top
);

/**
 * Sets the orientation of the object.
 * This function completely overwrites the previous rotation.
 * See the rotate function to add an angle based on the previous rotation instead.
 * The default rotation of a transformable object is 0.
 */
MOON_CSFML_API void
moon_Text_set_rotation(
	moon_Text* self,
	moon_Angle angle
);

/**
 * Sets the scale factors of the object.
 * This function completely overwrites the previous scale.
 * See the scale function to add a factor based on the previous scale instead.
 * The default scale of a transformable object is (1, 1).
 */
MOON_CSFML_API void
moon_Text_set_scale(
	moon_Text* self,
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
moon_Text_set_origin(
	moon_Text* self,
	float x, float y
);

/**
 * Returns the position of the object.
 */
MOON_CSFML_API moon_Vector2f
moon_Text_get_position(const moon_Text* self);

/**
 * Returns the orientation of the object.
 *
 * The rotation is always in the range(degrees) [0, 360].
 */
MOON_CSFML_API moon_Angle
moon_Text_get_rotation(const moon_Text* self);

/**
 * Returns the current scale of the object.
 */
MOON_CSFML_API moon_Vector2f
moon_Text_get_scale(const moon_Text* self);

/**
 * Returns the local origin of the object.
 */
MOON_CSFML_API moon_Vector2f
moon_Text_get_origin(const moon_Text* self);

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
moon_Text_move(
	moon_Text* self,
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
moon_Text_rotate(
	moon_Text* self,
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
moon_Text_scale(
	moon_Text* self,
	float scale_x, float scale_y
);

/**
 * Returns transform combining the position/rotation/scale/origin of the object.
 * This operation is slow, because it copies SFML transform to C
 *compatible transform.
 */
MOON_CSFML_API moon_Transform
moon_Text_get_transform(const moon_Text* self);

/**
 * Returns inverse of the combined transformations applied to the object.
 * This operation is slow, because it copies SFML transform to C
 *compatible transform.
 */
MOON_CSFML_API moon_Transform
moon_Text_get_inverse_transform(const moon_Text* self);

/**
 * Returns 1 if internal transform is updated, 0 otherwise.
 * Use it if you want to cache C transform or/and C inversed
 *transform.
 */
MOON_CSFML_API int
moon_Text_is_transform_updated(const moon_Text* self);

/**
 * Returns 1 if internal inversed transform is updated, 0 otherwise.
 * Use it if you want to cache C inversed transform.
 */
MOON_CSFML_API int
moon_Text_is_inversed_transform_updated(const moon_Text* self);

//Transformable end


#ifdef __cplusplus
}
#endif


#endif
