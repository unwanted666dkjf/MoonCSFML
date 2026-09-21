#ifndef MOON_CSFML_EXTRAS_MOON_PATHGEN_H
#define MOON_CSFML_EXTRAS_MOON_PATHGEN_H


#include "../import_macro.h"


#ifdef __cplusplus
extern "C" {
#endif


struct MOON_CSFML_API moon_Pathgen;


/**
 * Path generator. Non-recursively returns
 *relative paths to the contents of the start directory.
 */
typedef struct moon_Pathgen moon_Pathgen;


/**
 * Creates new path generator.
 * Generator will return contents of 'start_dir'.
 * If fails, returns NULL.
 * 'start_dir' must not end with '/' or '\\'.
 */
MOON_CSFML_API moon_Pathgen*
moon_Pathgen_create(const char* start_dir);

/**
 * Destroys generator.
 */
MOON_CSFML_API void
moon_Pathgen_destroy(moon_Pathgen* self);

/**
 * Returns 1 if if the directory still contains something.
 */
MOON_CSFML_API int
moon_Pathgen_has_next(const moon_Pathgen* self);

/**
 * Returns item from directory as ansi/multibyte string.
 * Result is null-terminated.
 * Result must be freed after usage.
 * Rarely can return NULL.
 */
MOON_CSFML_API char*
moon_Pathgen_next(moon_Pathgen* self);


#ifdef __cplusplus
}
#endif


#endif
