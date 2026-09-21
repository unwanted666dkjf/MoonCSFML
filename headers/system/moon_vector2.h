#ifndef MOON_CSFML_SYSTEM_MOON_VECTOR2_H
#define MOON_CSFML_SYSTEM_MOON_VECTOR2_H


#include "../import_macro.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Utility structure for manipulating
 *2D vectors of unsigned integers.
 */
typedef struct MOON_CSFML_API moon_Vector2u {
	unsigned int x;
	unsigned int y;
} moon_Vector2u;

/**
 * Utility structure for manipulating
 *2D vectors of integers.
 */
typedef struct MOON_CSFML_API moon_Vector2i {
	int x;
	int y;
} moon_Vector2i;

/**
 * Utility structure for manipulating
 *2D vectors of floating point number.
 */
typedef struct MOON_CSFML_API moon_Vector2f {
	float x;
	float y;
} moon_Vector2f;


#ifdef __cplusplus
}
#endif


#endif
