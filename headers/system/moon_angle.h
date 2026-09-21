#ifndef MOON_CSFML_SYSTEM_MOON_ANGLE_H
#define MOON_CSFML_SYSTEM_MOON_ANGLE_H


#include "../import_macro.h"


#ifdef __cplusplus
extern "C" {
#endif


// Like in python2.7.18, btw
#define moon_Angle_M_PI (3.141592653589793f)


/**
 * Represents angle value.
 * Stores angle in degrees.
 * The buffer of type float.
 * Alternative to sf::Angle from SFML3.
 */
typedef float moon_Angle;


/**
 * Creates angle value from degrees.
 */
MOON_CSFML_API moon_Angle
moon_Angle_from_degrees(float degrees);

/**
 * Creates angle value from radians.
 */
MOON_CSFML_API moon_Angle
moon_Angle_from_radians(float radians);

/**
 * Returns angle value as degrees.
 */
MOON_CSFML_API float
moon_Angle_as_degrees(moon_Angle angle);

/**
 * Returns angle value as radians.
 */
MOON_CSFML_API float
moon_Angle_as_radians(moon_Angle angle);


#ifdef __cplusplus
}
#endif


#endif
