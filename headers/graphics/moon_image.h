#ifndef MOON_CSFML_GRAPHICS_MOON_IMAGE_H
#define MOON_CSFML_GRAPHICS_MOON_IMAGE_H


#include "./moon_rect.h"

#include "./moon_color.h"


#include "../system/moon_vector2.h"


#ifdef __cplusplus
extern "C" {
#endif


struct MOON_CSFML_API moon_Image;


/**
 * Struct for loading, manipulating and saving images.
 */
typedef struct moon_Image moon_Image;


/**
 * Creates an empty image.
 */
MOON_CSFML_API moon_Image*
moon_Image_create();

/**
 * Creates the image and fills it with a unique color.
 */
MOON_CSFML_API moon_Image*
moon_Image_from_color(
	unsigned int width,
	unsigned int height,
	const moon_Color* color
);

/**
 * Creates the image from another image(array of pixels).
 * The \a pixel array is assumed to contain 32-bits RGBA pixels,
 *and have the given \a width and \a height. If no*t, this is
 *an undefined behavior.
 * If \a pixels is null, an empty image is created.
 */
MOON_CSFML_API moon_Image*
moon_Image_from_image(
	unsigned int width,
	unsigned int height,
	const moon_Image* image
);

/**
 * Destroys the image.
 */
MOON_CSFML_API void
moon_Image_destroy(moon_Image* self);

/**
 * Loads the image from a file on disk.
 * The supported image formats are bmp, png, tga, jpg, gif,
 *psd, hdr, pic and pnm. Some format options are not supported,
 *like jpeg with arithmetic coding or ASCII pnm.
 * If this function fails, the image is left unchanged.
 * Returns 1 if successful, 0 otherwise.
 */
MOON_CSFML_API int
moon_Image_load(
	moon_Image* self,
	const char* filepath
);

/**
 * Saves the image to a file on disk.
 * The format of the image is automatically deduced from
 *the extension. The supported image formats are bmp, png,
 *tga and jpg. The destination file is overwritten
 *if it already exists. This function fails if the image is empty.
 * Returns 1 if successful, 0 otherwise.
 */
MOON_CSFML_API int
moon_Image_save(
	const moon_Image* self,
	const char* filepath
);

/**
 * Returns the size (width and height) of the image.
 */
MOON_CSFML_API moon_Vector2u
moon_Image_get_size(const moon_Image* self);

/**
 * Creates a transparency mask from a specified color-key.
 * This function sets the alpha value of every pixel matching
 *the given color to alpha, so that they
 *become transparent.
 */
MOON_CSFML_API void
moon_Image_create_mask_from_color(
	moon_Image* self,
	const moon_Color* color,
	unsigned char alpha
);

/**
 * Copies pixels from another image onto this one.
 * The whole image is copied.
 * Copies pixels from another image onto this one.
 * This function does a slow pixel copy and should not be
 *used intensively. It can be used to prepare a complex
 *static image from several others.
 * If 'apply_alpha' is set to true, alpha blending is
 *applied from the source pixels to the destination pixels
 *using the \b over operator. If it is 0, the source
 *pixels are copied unchanged with their alpha value.
 */
MOON_CSFML_API void
moon_Image_copy_pixels(
	moon_Image* self,
	const moon_Image* source,
	unsigned int dest_x,
	unsigned int dest_y,
	int apply_alpha
);

/**
 * Copies pixels from another image onto this one.
 * This function does a slow pixel copy and should not be
 *used intensively. It can be used to prepare a complex
 *static image from several others, but if you need this
 *kind of feature in real-time you'd better use RenderTexture.
 *
 * If 'source_rect' is empty, the whole image is copied.
 * If 'apply_alpha' is set to true, alpha blending is
 *applied from the source pixels to the destination pixels
 *using the \b over operator. If it is 0, the source
 *pixels are copied unchanged with their alpha value.
 */
MOON_CSFML_API void
moon_Image_copy_pixels_ex(
	moon_Image* self,
	const moon_Image* source,
	unsigned int dest_x,
	unsigned int dest_y,
	int apply_alpha,
	const moon_IntRect* source_rect
);

/**
 * Changes the color of a pixel.
 * This function doesn't check the validity of the pixel
 *coordinates, using out-of-range values will result in
 *an undefined behavior.
 */
MOON_CSFML_API void
moon_Image_set_pixel(
	moon_Image* self,
	unsigned int x,
	unsigned int y,
	const moon_Color* color
);

/**
 * Returns the color of a pixel.
 * This function doesn't check the validity of the pixel
 *coordinates, using out-of-range values will result in
 *an undefined behavior.
 */
MOON_CSFML_API moon_Color
moon_Image_get_pixel(
	const moon_Image* self,
	unsigned int x,
	unsigned int y
);

/**
 * Flips the image horizontally (left <-> right).
 */
MOON_CSFML_API void
moon_Image_flip_horizontally(moon_Image* self);

/**
 * Flips the image vertically (top <-> bottom).
 */
MOON_CSFML_API void
moon_Image_flip_vertically(moon_Image* self);


#ifdef __cplusplus
}
#endif


#endif
