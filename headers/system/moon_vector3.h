#ifndef MOON_CSFML_SYSTEM_MOON_VECTOR3_H
#define MOON_CSFML_SYSTEM_MOON_VECTOR3_H


#include "../import_macro.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * 3D vector internals
 */
#define moon_Vector3(Type)	\
	Type x;	\
	Type y;	\
	Type z;


/**
 * Utility structure for manipulating
 *3D vectors of unsigned integers.
 */
typedef struct MOON_CSFML_API moon_Vector3u {
	moon_Vector3(unsigned int)
} moon_Vector3u;

/**
 * Utility structure for manipulating
 *3D vectors of integers.
 */
typedef struct MOON_CSFML_API moon_Vector3i {
	moon_Vector3(int)
} moon_Vector3i;

/**
 * Utility structure for manipulating
 *3D vectors of floating point number.
 */
typedef struct MOON_CSFML_API moon_Vector3f {
	moon_Vector3(float)
} moon_Vector3f;


#ifdef __cplusplus
}
#endif


#endif
