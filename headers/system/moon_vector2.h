#ifndef MOON_CSFML_SYSTEM_MOON_VECTOR2_H
#define MOON_CSFML_SYSTEM_MOON_VECTOR2_H


#include "../import_macro.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * 2D vector internals
 */
#define moon_Vector2(Type)	\
	Type x;	\
	Type y;


/**
 * Utility structure for manipulating
 *2D vectors of unsigned integers.
 */
typedef struct MOON_CSFML_API moon_Vector2u {
	moon_Vector2(unsigned int)
} moon_Vector2u;

/**
 * Utility structure for manipulating
 *2D vectors of integers.
 */
typedef struct MOON_CSFML_API moon_Vector2i {
	moon_Vector2(int)
} moon_Vector2i;

/**
 * Utility structure for manipulating
 *2D vectors of floating point number.
 */
typedef struct MOON_CSFML_API moon_Vector2f {
	moon_Vector2(float)
} moon_Vector2f;


#ifdef __cplusplus
}
#endif


#endif
