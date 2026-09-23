#ifndef MOON_CSFML_SYSTEM_MOON_UTILS_H
#define MOON_CSFML_SYSTEM_MOON_UTILS_H


#include "../import_macro.h"


#ifdef __cplusplus
extern "C" {
#endif


#include <wchar.h>


/**
 * Custom 'printf'.
 * Used to print formatted output to the standard output
 *stream (stdout), which is usually the console.
 * It can print text, variables, expressions and formatted values.
 * Format specifiers control how different types of values are displayed.
 * Returns the number of characters printed after
 *successful execution. If an error occurs, a
 *negative value is returned.
 * format specifiers:
 * %d -- int;
 * %f -- double;
 * %c -- char;
 * %s -- string;
 * %x -- unsigned int in hex;
 * %p -- pointer;
 * %l -- long spicifers, fit fo int/float/double/string.
 */
MOON_CSFML_API int
moon_printf(const char* format, ...);

/**
 * Custom 'wprintf'.
 * Used to print formatted output to the standard output
 *stream (stdout), which is usually the console.
 * It can print text, variables, expressions and formatted values.
 * Format specifiers control how different types of values are displayed.
 * Returns the number of characters printed after
 *successful execution. If an error occurs, a
 *negative value is returned.
 * format specifiers:
 * %d -- int;
 * %f -- double;
 * %c -- char;
 * %s -- string;
 * %x -- unsigned int in hex;
 * %p -- pointer;
 * %l -- long spicifers, fit fo int/float/double/string.
 */
MOON_CSFML_API int
moon_wprintf(const wchar_t* format, ...);

/**
 * Custom 'scanf'.
 * Just because 'scanf' will be deprecated.
 * Reads formatted text from standard input (stdin)
 *and stores the results into variables you pass by pointer.
 *It uses a format string with conversion specifiers
 *(starting with %) to tell it how to interpret the input,
 *and it returns the number of items successfully read or
 *-1 on error/end of input.
 */
MOON_CSFML_API int
moon_scanf(const char* format, ...);

/**
 * Custom 'wscanf'.
 * Just because 'wscanf' will be deprecated.
 * Reads formatted text from standard input (stdin)
 *and stores the results into variables you pass by pointer.
 *It uses a format string with conversion specifiers
 *(starting with %) to tell it how to interpret the input,
 *and it returns the number of items successfully read or
 *-1 on error/end of input.
 */
MOON_CSFML_API int
moon_wscanf(const wchar_t* format, ...);

/**
 * Rounds a number to a specified number of decimal places.
 * Uses std::round under the hood.
 * Example: moon_round(23.4567, 2) --> 23.460000
 */
MOON_CSFML_API double
moon_round(double value, int digits);

/**
 * Rounds a number to a specified number of decimal places.
 * Uses std::round under the hood.
 * Example: moon_round(23.4567f, 2) --> 23.460000
 * Special variant for float.
 */
MOON_CSFML_API float
moon_roundf(float value, int digits);

/**
 * Rounds the number up.
 * Wrapper for std::ceil.
 */
MOON_CSFML_API double
moon_ceil(double value);

/**
 * Rounds the number up.
 * Wrapper for std::ceil.
 */
MOON_CSFML_API float
moon_ceilf(float value);

/**
 * Rounds the number down.
 * Wrapper for std::floor.
 */
MOON_CSFML_API double
moon_floor(double value);

/**
 * Rounds the number down.
 * Wrapper for std::floorf.
 */
MOON_CSFML_API float
moon_floorf(float value);

/**
 * Wrapper for std::memcpy.
 * std::memcpy copies a specified number of bytes from a source to a destination.
 * Performs the following operations in order:
 *
 * 1. Implicitly creates objects at dest.
 * 2. Copies count characters (as if of type unsigned char)
 *from the object pointed to by src into the object pointed to by dest.
 * If any of the following conditions is satisfied, the behavior is undefined:
 *
 * dest or src is a null pointer or invalid pointer.
 * Copying takes place between objects that overlap.
 */
MOON_CSFML_API void*
moon_memcpy(
	void* destination,
	const void* source,
	unsigned long count
);

/**
 * Special function for creatings arrays of type float.
 * Size is always greater than 0.
 * For creation uses 'new' keyword.
 * To destroy it you shoud use destroy function.
 */
MOON_CSFML_API float*
moon_farray_create(unsigned long size);

/**
 * Destroys array of floats.
 * Uses 'delete'.
 */
MOON_CSFML_API void
moon_farray_destroy(float* arr);

/**
 * Returns element from float array by index.
 * No bound checking.
 * Pretty useless in C/C++.
 */
MOON_CSFML_API float
moon_farray_get(
	const float* arr,
	unsigned long index
);

/**
 * Sets element by index in float array.
 * No bound checking.
 * Pretty useless in C/C++.
 */
MOON_CSFML_API void
moon_farray_set(
	float* arr,
	unsigned long index,
	float value
);


/**
 * Returns a random integer from inclusive range: [low; high].
 * Uses rand from cstdlib.
 * The rand() function returns a pseudo-random integer in the range 0
 *to RAND_MAX(>= 32767) inclusive (i.e., the mathematical range [0, RAND_MAX]).
 * The srand() function sets its argument as the seed for a new
 *sequence of pseudo-random integers to be returned by rand().
 *These sequences are repeatable by calling srand() with the same seed value.
 * If no seed value is provided, the rand() function is automatically
 *seeded with a value of 1.
 */
MOON_CSFML_API int
moon_random(int low, int high);

/**
 * return (unsigned int)time(NULL)
 */
MOON_CSFML_API unsigned int
moon_time_null_seed();

/**
 * Wrapper of srand.
 * The srand() function sets its argument as the seed for a new
 *sequence of pseudo-random integers to be returned by rand().
 * These sequences are repeatable by calling srand() with the same
 *seed value.
 */
MOON_CSFML_API void
moon_srand(unsigned int seed);

/**
 * Wrapper of C++ std::malloc.
 */
MOON_CSFML_API void*
moon_malloc(unsigned long size);

/**
 * Wrapper of C++ std::free.
 */
MOON_CSFML_API void
moon_free(void* ptr);

/**
 * Wrapper of C++ std::setlocale.
 */
MOON_CSFML_API void
moon_setlocale(int category, const char* locale_name);

/**
 * Returns category 'LC_ALL' for std::setlocale.
 */
MOON_CSFML_API int
moon_locale_LC_ALL();

/**
 * Returns category 'LC_CTYPE' for std::setlocale.
 */
MOON_CSFML_API int
moon_locale_LC_CTYPE();

/**
 * Returns category 'LC_NUMERIC' for std::setlocale.
 */
MOON_CSFML_API int
moon_locale_LC_NUMERIC();

/**
 * Returns category 'LC_TIME' for std::setlocale.
 */
MOON_CSFML_API int
moon_locale_LC_TIME();

/**
 * Returns category 'LC_COLLATE' for std::setlocale.
 */
MOON_CSFML_API int
moon_locale_LC_COLLATE();

/**
 * Returns category 'LC_MONETARY' for std::setlocale.
 */
MOON_CSFML_API int
moon_locale_LC_MONETARY();


#ifdef __cplusplus
}
#endif


#endif
