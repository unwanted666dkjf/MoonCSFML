#ifndef MOON_CSFML_SYSTEM_MOON_VECTOR3_H
#define MOON_CSFML_SYSTEM_MOON_VECTOR3_H


#include "../import_macro.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Utility structure for manipulating
 *3D vectors of unsigned integers.
 */
typedef struct MOON_CSFML_API moon_Vector3u {
	unsigned int x;
	unsigned int y;
	unsigned int z;
} moon_Vector3u;

/**
 * Utility structure for manipulating
 *3D vectors of integers.
 */
typedef struct MOON_CSFML_API moon_Vector3i {
	int x;
	int y;
	int z;
} moon_Vector3i;

/**
 * Utility structure for manipulating
 *3D vectors of floating point number.
 */
typedef struct MOON_CSFML_API moon_Vector3f {
	float x;
	float y;
	float z;
} moon_Vector3f;


#ifdef __cplusplus
}
#endif


#endif
