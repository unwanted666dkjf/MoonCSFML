#ifndef MOON_CSFML_GRAPHICS_MOON_BLEND_MODE_H
#define MOON_CSFML_GRAPHICS_MOON_BLEND_MODE_H


#include "../import_macro.h"


#ifdef __cplusplus
extern "C" {
#endif


enum
{
	moon_BlendMode_Factor_Zero,             //!< (0, 0, 0, 0)
	moon_BlendMode_Factor_One,              //!< (1, 1, 1, 1)
	moon_BlendMode_Factor_SrcColor,         //!< (src.r, src.g, src.b, src.a)
	moon_BlendMode_Factor_OneMinusSrcColor, //!< (1, 1, 1, 1) - (src.r, src.g, src.b, src.a)
	moon_BlendMode_Factor_DstColor,         //!< (dst.r, dst.g, dst.b, dst.a)
	moon_BlendMode_Factor_OneMinusDstColor, //!< (1, 1, 1, 1) - (dst.r, dst.g, dst.b, dst.a)
	moon_BlendMode_Factor_SrcAlpha,         //!< (src.a, src.a, src.a, src.a)
	moon_BlendMode_Factor_OneMinusSrcAlpha, //!< (1, 1, 1, 1) - (src.a, src.a, src.a, src.a)
	moon_BlendMode_Factor_DstAlpha,         //!< (dst.a, dst.a, dst.a, dst.a)
	moon_BlendMode_Factor_OneMinusDstAlpha  //!< (1, 1, 1, 1) - (dst.a, dst.a, dst.a, dst.a)
};

enum
{
	moon_BlendMode_Equation_Add,             //!< Pixel = Src * SrcFactor + Dst * DstFactor
	moon_BlendMode_Equation_Subtract,        //!< Pixel = Src * SrcFactor - Dst * DstFactor
	moon_BlendMode_Equation_ReverseSubtract, //!< Pixel = Dst * DstFactor - Src * SrcFactor
	moon_BlendMode_Equation_Min,             //!< Pixel = min(Dst, Src)
	moon_BlendMode_Equation_Max              //!< Pixel = max(Dst, Src)
};


/**
 * Blending modes for drawing.
 * Use to create RenderStates.
 */
typedef struct MOON_CSFML_API moon_BlendMode {
	int   	color_src_factor; 	//!< Source blending factor for the color channels
	int   	color_dst_factor; 	//!< Destination blending factor for the color channels
	int 	color_equation;  	//!< Blending equation for the color channels
	int   	alpha_src_factor; 	//!< Source blending factor for the alpha channel
	int   	alpha_dst_factor; 	//!< Destination blending factor for the alpha channel
	int 	alpha_equation;  	//!< Blending equation for the alpha channel
} moon_BlendMode;


/**
 * Returns copy of this blend mode.
 */
MOON_CSFML_API moon_BlendMode
moon_BlendMode_get_copy(const moon_BlendMode* self);

/**
 * Returns 1 if blend modes are equal,
 *0 otherwise.
 * Blend modes are equal if their members
 *are equal.
 */
MOON_CSFML_API int
moon_BlendMode_is_eq(
	const moon_BlendMode* self,
	const moon_BlendMode* other
);

/**
 * Returns 1 if blend modes are equal,
 *0 otherwise.
 * Blend modes are equal if their members
 *are equal.
 */
MOON_CSFML_API int
moon_BlendMode_is_ne(
	const moon_BlendMode* self,
	const moon_BlendMode* other
);


#ifdef __cplusplus
}
#endif


#endif
