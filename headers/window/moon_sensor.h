#ifndef MOON_CSFML_WINDOW_MOON_SENSOR_H
#define MOON_CSFML_WINDOW_MOON_SENSOR_H


#include "../system/moon_vector3.h"


#ifdef __cplusplus
extern "C" {
#endif


enum
{
	moon_Sensor_Type_Accelerometer,    //!< Measures the raw acceleration (m/s^2)
	moon_Sensor_Type_Gyroscope,        //!< Measures the raw rotation rates (degrees/s)
	moon_Sensor_Type_Magnetometer,     //!< Measures the ambient magnetic field (micro-teslas)
	moon_Sensor_Type_Gravity,          //!< Measures the direction and intensity of gravity, independent of device acceleration (m/s^2)
	moon_Sensor_Type_UserAcceleration, //!< Measures the direction and intensity of device acceleration, independent of the gravity (m/s^2)
	moon_Sensor_Type_Orientation,      //!< Measures the absolute 3D orientation (degrees)

	moon_Sensor_Type_Count             //!< Keep last -- the total number of sensor types
};


/**
 * Check if a sensor is available on the underlying platform.
 * 1 if sensor is available, 0 otherwise.
 */
MOON_CSFML_API int
moon_Sensor_is_available(int sensor_type);

/**
 * Enable or disable a sensor.
 * All sensors are disabled by default, to avoid consuming too
 *much battery power. Once a sensor is enabled, it starts
 *sending events of the corresponding type.
 *
 *This function does nothing if the sensor is unavailable.
 * 1 to enable, 0 to disable.
 */
MOON_CSFML_API void
moon_Sensor_set_enabled(int sensor_type, int enabled);

/**
 * Returns the current sensor value.
 */
MOON_CSFML_API moon_Vector3f
moon_Sensor_get_value(int sensor_type);


#ifdef __cplusplus
}
#endif


#endif
