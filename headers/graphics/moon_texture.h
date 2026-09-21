#ifndef MOON_CSFML_GRAPHICS_MOON_TEXTURE_H
#define MOON_CSFML_GRAPHICS_MOON_TEXTURE_H


#include "./moon_rect.h"

#include "./moon_image.h"

#include "./moon_render_window.h"


#include "../system/moon_vector2.h"


#ifdef __cplusplus
extern "C" {
#endif


enum
{
	moon_Texture_CoordinateType_Normalized, //!< Texture coordinates in range [0 .. 1]
	moon_Texture_CoordinateType_Pixels      //!< Texture coordinates in range [0 .. size]
};


struct MOON_CSFML_API moon_Texture;


/**
 * Image living on the graphics card that can be used for drawing.
 */
typedef struct moon_Texture moon_Texture;


/**
 * Creates an empty texture.
 */
MOON_CSFML_API moon_Texture*
moon_Texture_create();

/**
 * Destroys the texture.
 */
MOON_CSFML_API void
moon_Texture_destroy(moon_Texture* self);

/**
 * Returns copy of this texture.
 */
MOON_CSFML_API moon_Texture*
moon_Texture_get_copy(const moon_Texture* self);

/**
 * Updates the texture from the contents of a window.
 *
 * Although the source window can be smaller than the texture,
 *this function is usually used for updating the whole texture.
 * The other overload, which has (x, y) additional arguments,
 *is more convenient for updating a sub-area of the texture.
 *
 * No additional check is performed on the size of the window,
 *passing a window bigger than the texture will lead to an
 *undefined behavior.
 *
 * This function does nothing if either the texture or the window
 *was not previously created.
 */
MOON_CSFML_API void
moon_Texture_screen_capture(
	moon_Texture* self,
	const moon_RenderWindow* wnd
);

/**
 * Adjusts size of the texture.
 * If this function fails, the texture is left unchanged.
 * Returns 1 if successful, 0 otherwise.
 * Inside, it just SFML
 *sf::Texture::create(unsigned int width, unsigned int height).
 */
MOON_CSFML_API int
moon_Texture_adjust_size(
	moon_Texture* self,
	unsigned int width,
	unsigned int height
);

/**
 * Loads the texture from a file on disk.
 * The whole image will be loaded.
 * The maximum size for a texture depends on the graphics
 *driver and can be retrieved with the getMaximumSize function.
 *
 * If this function fails, the texture is left unchanged.
 * Returns 1 if loading was successful, 0 otherwise.
 */
MOON_CSFML_API int
moon_Texture_load_from_file(
	moon_Texture* self,
	const char* filepath
);

/**
 * Loads the texture from a file on disk.
 * The \a area argument can be used to load only a sub-rectangle
 *of the whole image. If you want the entire image then pass
 *an empty rectangle.
 * If the \a area rectangle crosses the bounds of the image, it
 *is adjusted to fit the image size.
 *
 * The maximum size for a texture depends on the graphics
 *driver and can be retrieved with the getMaximumSize function.
 *
 * If this function fails, the texture is left unchanged.
 * Returns 1 if loading was successful, 0 otherwise.
 */
MOON_CSFML_API int
moon_Texture_load_from_file_ex(
	moon_Texture* self,
	const char* filepath,
	const moon_IntRect* area
);

/**
 * Loads the texture from an image.
 * The entire image will be loaded.
 *
 * The maximum size for a texture depends on the graphics
 *driver and can be retrieved with the getMaximumSize function.
 *
 * If this function fails, the texture is left unchanged.
 * Returns 1 if loading was successful, 0 otherwise.
 */
MOON_CSFML_API int
moon_Texture_load_from_image(
	moon_Texture* self,
	const moon_Image* image
);

/**
 * Loads the texture from an image.
 * The \a area argument can be used to load only a sub-rectangle
 *of the whole image. If you want the entire image then pass
 *an empty rectangle.
 * If the \a area rectangle crosses the bounds of the image, it
 *is adjusted to fit the image size.
 *
 * The maximum size for a texture depends on the graphics
 *driver and can be retrieved with the getMaximumSize function.
 *
 * If this function fails, the texture is left unchanged.
 * Returns 1 if loading was successful, 0 otherwise.
 */
MOON_CSFML_API int
moon_Texture_load_from_image_ex(
	moon_Texture* self,
	const moon_Image* image,
	const moon_IntRect* area
);

/**
 * Saves texture to a file on a disk.
 * Shortcut for, example:
 *    std::string fp = "./file.png";
 *    sf::Image img = self->copyToImage();
 *    img.saveToFile(fp);
 * Returns 1 if saving was successful, 0 otherwise.
 */
MOON_CSFML_API int
moon_Texture_save_to_file(
	const moon_Texture* self,
	const char* filepath
);

/**
 * Copies the texture pixels to an image.
 * Maybe slow because it first calls SFML clas method,
 *and after copies image object into pointer.
 * This function performs a slow operation that downloads
 *the texture's pixels from the graphics card and copies
 *them to a new image, potentially applying transformations
 *to pixels if necessary (texture may be padded or flipped).
 */
MOON_CSFML_API moon_Image*
moon_Texture_to_image(const moon_Texture* self);

/**
 * Returns the size of the texture.
 */
MOON_CSFML_API moon_Vector2u
moon_Texture_get_size(const moon_Texture* self);

/**
 * Updates a part of this texture from another texture.
 * Although the source texture can be smaller than this texture,
 *this function is usually used for updating the whole texture.
 * The other overload, which has (x, y) additional arguments,
 *is more convenient for updating a sub-area of this texture.
 *
 * No additional check is performed on the size of the passed
 *texture, passing a texture bigger than this texture
 *will lead to an undefined behavior.
 *
 * This function does nothing if either texture was not
 *previously created.
 */
MOON_CSFML_API void
moon_Texture_update_tex(
	moon_Texture* self,
	const moon_Texture* texture
);

/**
 * Updates a part of this texture from another texture.
 * No additional check is performed on the size of the texture,
 *passing an invalid combination of texture size and offset
 *will lead to an undefined behavior.
 *
 * This function does nothing if either texture was not
 *previously created.
 * x -- X offset in this texture where to copy the source texture.
 * y -- Y offset in this texture where to copy the source texture.
 */
MOON_CSFML_API void
moon_Texture_update_tex_ex(
	moon_Texture* self,
	const moon_Texture* texture,
	unsigned int x,
	unsigned int y
);

/**
 * Updates the texture from an image.
 * Although the source image can be smaller than the texture,
 *this function is usually used for updating the whole texture.
 * The other overload, which has (x, y) additional arguments,
 *is more convenient for updating a sub-area of the texture.
 *
 * No additional check is performed on the size of the image,
 *passing an image bigger than the texture will lead to an
 *undefined behavior.
 *
 * This function does nothing if the texture was not
 *previously created.
 */
MOON_CSFML_API void
moon_Texture_update_img(
	moon_Texture* self,
	const moon_Image* image
);

/**
 * Updates a part of the texture from an image.
 * No additional check is performed on the size of the image,
 *passing an invalid combination of image size and offset
 *will lead to an undefined behavior.
 *
 * This function does nothing if the texture was not
 *previously created.
 * x -- X offset in the texture where to copy the source image.
 * y -- Y offset in the texture where to copy the source image.
 */
MOON_CSFML_API void
moon_Texture_update_img_ex(
	moon_Texture* self,
	const moon_Image* image,
	unsigned int x,
	unsigned int y
);

/**
 * Enables or disables the smooth filter.
 * When the filter is activated, the texture appears smoother
 *so that pixels are less noticeable. However if you want
 *the texture to look exactly the same as its source file,
 *you should leave it disabled.
 * The smooth filter is disabled by default.
 * Pass 1 to enable smoothing, 0 to disable it.
 */
MOON_CSFML_API void
moon_Texture_set_smooth(
	moon_Texture* self,
	int is_smooth
);

/**
 * Tells whether the smooth filter is enabled or not.
 * Returns 1 if smoothing is enabled, 0 if it is disabled.
 */
MOON_CSFML_API int
moon_Texture_is_smooth(const moon_Texture* self);

/**
 * Enables or disables conversion from sRGB.
 * When providing texture data from an image file or memory, it can
 *either be stored in a linear color space or an sRGB color space.
 * Most digital images account for gamma correction already, so they
 *would need to be "uncorrected" back to linear color space before
 *being processed by the hardware. The hardware can automatically
 *convert it from the sRGB color space to a linear color space when
 *it gets sampled. When the rendered image gets output to the final
 *framebuffer, it gets converted back to sRGB.
 *
 * After enabling or disabling sRGB conversion, make sure to reload
 *the texture data in order for the setting to take effect.
 *
 * This option is only useful in conjunction with an sRGB capable
 *framebuffer. This can be requested during window creation.
 * Pass 1 to enable sRGB conversion, 0 to disable it.
 */
MOON_CSFML_API void
moon_Texture_set_srgb(
	moon_Texture* self,
	int is_srgb
);

/**
 * Tells whether the texture source is converted from sRGB or not.
 * Returns 1 if the texture source is converted from sRGB, 0 if not.
 */
MOON_CSFML_API int
moon_Texture_is_srgb(const moon_Texture* self);

/**
 * Enables or disables repeating.
 * Repeating is involved when using texture coordinates
 *outside the texture rectangle [0,* 0, width, height].
 * In this case, if repeat mode is enabled, the whole texture
 *will be repeated as many times as needed to reach the
 *coordinate (for example, if the X texture coordinate is
 *3 * width, the texture will be repeated 3 times).
 * If repeat mode is disabled, the "extra space" will instead
 *be filled with border pixels.
 * Warning: on very old graphics cards, white pixels may appear
 *when the texture is repeated. With such cards, repeat mode
 *can be used reliably only if the texture has power-of-two
 *dimensions (such as 256x128).
 * Repeating is disabled by default.
 * Pass 1 to repeat the texture, 0 to disable repeating.
 */
MOON_CSFML_API void
moon_Texture_set_repeated(
	moon_Texture* self,
	int is_repeated
);

/**
 * Tells whether the texture is repeated or not.
 * Returns 1 if repeat mode is enabled, false if it is disabled.
 */
MOON_CSFML_API int
moon_Texture_is_repeated(const moon_Texture* self);

/**
 * Generates a mipmap using the current texture data.
 * Mipmaps are pre-computed chains of optimized textures. Each
 *level of textu*re in a mipmap is generated by halving each of
 *the previous level's dimensions. This is done until the final
 *level has the size of 1x1. The textures generated in this process may
 *make use of more advanced filters which might improve the visual quality
 *of textures when they are applied to objects much smaller than they are.
 * This is known as minification. Because fewer texels (texture elements)
 *have to be sampled from when heavily minified, usage of mipmaps
 *can also improve rendering performance in certain scenarios.
 *
 * Mipmap generation relies on the necessary OpenGL extension being
 *available. If it is unavailable or generation fails due to another
 *reason, this function will return false. Mipmap data is only valid from
 *the time it is generated until the next time the base level image is
 *modified, at which point this function will have to be called again to
 *regenerate it.
 * Returns 1 if mipmap generation was successful, 0 if unsuccessful.
 */
MOON_CSFML_API int
moon_Texture_generate_mipmap(moon_Texture* self);

/**
 * Swaps the contents of this texture with those of another.
 */
MOON_CSFML_API void
moon_Texture_swap(
	moon_Texture* self,
	moon_Texture* other
);

/**
 * Returns the underlying OpenGL handle of the texture.
 * You shouldn't need to use this function, unless you have
 *very specific stuff to implement that SFML doesn't suppor*t,
 *or implement a temporary workaround until a bug is fixed.
 * Result: OpenGL handle of the texture or 0 if not yet created.
 */
MOON_CSFML_API unsigned int
moon_Texture_get_native_handle(const moon_Texture* self);

/**
 * Binds a texture for rendering.
 * This function is not part of the graphics API, it mustn't be
 *used when drawing SFML entities. It must be used only if you
 *mix sf::Texture with OpenGL code.
 *
 * SFML example:
 * \code
 * sf::Texture t1, t2;
 * ...
 * sf::Texture::bind(&t1);
 * // draw OpenGL stuff that use t1...
 * sf::Texture::bind(&t2);
 * // draw OpenGL stuff that use t2...
 * sf::Texture::bind(NULL);
 * // draw OpenGL stuff that use no texture...
 * \endcode
 *
 * The \a coordinateType argument controls how texture
 *coordinates will be interpret*ed. If Normalized (the default), they
 *must be in range [0 .. 1], which is the default way of handling
 *texture coordinates with OpenGL. If Pixels, they must be given
 *in pixels (range [0 .. size]). This mode is used internally by
 *the graphics classes of SFML, it makes the definition of texture
 *coordinates more intuitive for the high-level API, users don't need
 *to compute normalized values.
 */
MOON_CSFML_API void
moon_Texture_bind(
	const moon_Texture* self,
	int coordinate_type
);

/**
 * Returns the maximum texture size allowed.
 * This maximum size is defined by the graphics driver.
 * You can expect a value of 512 pixels for low-end graphics
 *card, and up to 8192 pixels or more for newer hardware.
 */
MOON_CSFML_API unsigned int
moon_Texture_get_maximum_size();


#ifdef __cplusplus
}
#endif


#endif
