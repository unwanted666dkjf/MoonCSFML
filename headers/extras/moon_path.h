#ifndef MOON_CSFML_EXTRAS_MOON_PATH_H
#define MOON_CSFML_EXTRAS_MOON_PATH_H


// 'We have 'std::filesystem::path' at home.'


#include "../import_macro.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Returns 1 if path exists, 0 otherwise.
 */
MOON_CSFML_API int
moon_Path_is_exists(const char* path);

/**
 * Returns 1 if path exists and it is
 *a directory.
 * Otherwise, returns 0.
 */
MOON_CSFML_API int
moon_Path_is_dir(const char* path);

/**
 * Returns 1 if path exists and it is
 *a file.
 * Otherwise, returns 0.
 */
MOON_CSFML_API int
moon_Path_is_file(const char* path);

/**
 * Creates a normalized version of the path.
 * Path -- null-terminated, preferably ansi, string.
 * If the path length is set to
 *'moon_Utils_StringLengthUnknown', it will
 *be calculated automatically.
 * Normalization proceeds as follows: first, spaces
 *are removed from the beginning and end of the line, as
 *well as the path separator from the end. Then the path
 *separator is replaced with the correct one for the current OS.
 * If the path consists only of path separators, it will simply be copied.
 * Returns NULL if fails.
 * Result will be null-terminated.
 * Result must be freed after usage.
 * May work incorrectly with multibyte unicode
 *strings.
 */
MOON_CSFML_API char*
moon_Path_get_normpath(
	const char* path,
	long long path_length
);

/**
 * Simply concatenates 2 paths.
 * If the path length is set to
 *'moon_Utils_StringLengthUnknown', it will
 *be calculated automatically.
 * Does not normalize paths.
 * Paths -- null-terminated, preferably ansi, strings.
 * For it to work correctly, 'path1' must
 *not end with '/' or '\\'.
 * Returns NULL if fails.
 * Result will be null-terminated.
 * Result must be freed after usage.
 * May work incorrectly with multibyte unicode
 *strings.
 */
MOON_CSFML_API char*
moon_Path_concat(
	const char* path1,
	const char* path2,
	long long path1_length,
	long long path2_length
);


#ifdef __cplusplus
}
#endif


#endif
