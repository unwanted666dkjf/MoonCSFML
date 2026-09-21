#ifndef MOON_CSFML_EXTRAS_MOON_FILELINES_H
#define MOON_CSFML_EXTRAS_MOON_FILELINES_H


#include "../import_macro.h"


#ifdef __cplusplus
extern "C" {
#endif


struct MOON_CSFML_API moon_Filelines;


/**
 * Specialized wrapper of 'std::ifstream'
 *for reading the file line by line.
 */
typedef struct moon_Filelines moon_Filelines;


/**
 * Returns generator.
 * Opens the file in reader mode (not binary).
 * If opening the file fails, returns NULL.
 */
MOON_CSFML_API moon_Filelines*
moon_Filelines_open(const char* filepath);

/**
 * Closes stream and destroys object.
 */
MOON_CSFML_API void
moon_Filelines_close(moon_Filelines* self);

/**
 * Returns 1 if there is a next line in a file.
 */
MOON_CSFML_API int
moon_Filelines_has_next(const moon_Filelines* self);

/**
 * Returns next line as null-terminated ansi string.
 * Result must be freed after usage.
 */
MOON_CSFML_API char*
moon_Filelines_next(moon_Filelines* self);


#ifdef __cplusplus
}
#endif


#endif
