#ifndef MOON_CSFML_SYSTEM_MOON_STRUTILS_H
#define MOON_CSFML_SYSTEM_MOON_STRUTILS_H


#include "../import_macro.h"


#ifdef __cplusplus
extern "C" {
#endif


#include <wchar.h>


#define moon_Utils_StringLengthUnknown 		(-1)

#define moon_Utils_StringNullTerminator 	(0)


/**
 * Returns 1 if character is a whitespace character,
 *0 otherwise.
 * Whitespace characters: ' \t\n\r\x0b\x0c'.
 */
MOON_CSFML_API int
moon_char_is_whitespace(unsigned int c);

/**
 * Converts ansi string to float.
 * Wrapper of std::strtof.
 */
MOON_CSFML_API float
moon_strofA(const char* str);

/**
 * Converts wide string to float.
 * Wrapper of std::wcstof.
 */
MOON_CSFML_API float
moon_strofW(const wchar_t* str);

/**
 * Converts ansi string to double.
 * Wrapper of std::strtod.
 */
MOON_CSFML_API double
moon_strtodA(const char* str);

/**
 * Converts wide string to double.
 * Wrapper of std::wcstod.
 */
MOON_CSFML_API double
moon_strtodW(const wchar_t* str);

/**
 * Converts ansi string to long.
 * Takes the number base into account.
 * Wrapper of std::strtol.
 */
MOON_CSFML_API long
moon_strtolA(const char* str, int base);

/**
 * Converts ansi string to long.
 * Takes the number base into account.
 * Wrapper of std::wcstol.
 */
MOON_CSFML_API long
moon_strtolW(const wchar_t* str, int base);

/**
 * Returns length(number of characters) of
 *null-terminated ansi string.
 */
MOON_CSFML_API unsigned long
moon_strlenA(const char* str);

/**
 * Returns length(number of characters) of
 *null-terminated wide string.
 */
MOON_CSFML_API unsigned long
moon_strlenW(const wchar_t* str);

/**
 * Returns empty ansi string.
 * And that string is null-terminator.
 * Result must be freed after usage.
 */
MOON_CSFML_API char*
moon_strnullA();

/**
 * Returns empty wide string.
 * And that string is null-terminator.
 * Result must be freed after usage.
 */
MOON_CSFML_API wchar_t*
moon_strnullW();

/**
 * Converts float to ansi string.
 * Uses std::to_string and copies result to
 *C string.
 * Result will be null-terminated.
 * Result must be freed after usage.
 */
MOON_CSFML_API char*
moon_ftostrA(float number);

/**
 * Converts float to wide string.
 * Uses std::to_wstring and copies result to
 *C string.
 * Result will be null-terminated.
 * Result must be freed after usage.
 */
MOON_CSFML_API wchar_t*
moon_ftostrW(float number);

/**
 * Converts double to ansi string.
 * Uses std::to_string and copies result to
 *C string.
 * Result will be null-terminated.
 * Result must be freed after usage.
 */
MOON_CSFML_API char*
moon_dtostrA(double number);

/**
 * Converts double to wide string.
 * Uses std::to_wstring and copies result to
 *C string.
 * Result will be null-terminated.
 * Result must be freed after usage.
 */
MOON_CSFML_API wchar_t*
moon_dtostrW(double number);

/**
 * Converts a number of type 'float' to ansi string,
 *leaving no more than 'precision' characters
 *after the floating point.
 * Result will be null-terminated.
 * Result must be freed after usage.
 */
MOON_CSFML_API char*
moon_strprecfA(
	float number,
	int precision
);

/**
 * Converts a number of type 'float' to wide string,
 *leaving no more than 'precision' characters
 *after the floating point.
 * Result will be null-terminated.
 * Result must be freed after usage.
 */
MOON_CSFML_API wchar_t*
moon_strprecfW(
	float number,
	int precision
);

/**
 * Returns a slice of ansi string.
 * If fails, returns NULL.
 * Result will be null-terminated.
 * Result must be freed after usage.
 * Slicing is similar(but not the same) to python slicing.
 * Indexes must not be negative, but step can be.
 * No bound checking.
 * If step is 0, returns empty slice.
 * If step is negative, elements will be in reverse and stop
 *index will be included in range.
 * Also can be used to copy current string: [0 : 'strlen' : 1].
 */
MOON_CSFML_API char*
moon_strsliceA(
	const char* str,
	long long start,
	long long stop,
	long long step
);

/**
 * Returns a slice of wide string.
 * If fails, returns NULL.
 * Result will be null-terminated.
 * Result must be freed after usage.
 * Slicing is similar(but not the same) to python slicing.
 * Indexes must not be negative, but step can be.
 * No bound checking.
 * If step is 0, returns empty slice.
 * If step is negative, elements will be in reverse and stop
 *index will be included in range.
 * Also can be used to copy current string: [0 : 'strlen' : 1].
 */
MOON_CSFML_API wchar_t*
moon_strsliceW(
	const wchar_t* str,
	long long start,
	long long stop,
	long long step
);

/**
 * Performs simple string concatenation.
 * If the string size is set to
 *'moon_Utils_StringLengthUnknown', it will
 *be calculated automatically.
 * Strings must be ansi null-terminated strings.
 * Result will be null-terminated.
 * Result must be freed after usage.
 * If fails, returns NULL.
 */
MOON_CSFML_API char*
moon_strcatA(
	const char* str1,
	const char* str2,
	long long str1_length,
	long long str2_length
);

/**
 * Performs simple string concatenation.
 * If the string size is set to
 *'moon_Utils_StringLengthUnknown', it will
 *be calculated automatically.
 * Strings must be wide null-terminated strings.
 * Result will be null-terminated.
 * Result must be freed after usage.
 * If fails, returns NULL.
 */
MOON_CSFML_API const wchar_t*
moon_strcatW(
	const wchar_t* str1,
	const wchar_t* str2,
	long long str1_length,
	long long str2_length
);

/**
 * Creates a copy of ansi string.
 * Must be freed with 'moon_free' after usage.
 * Result will be null-terminated.
 * If fails, returns NULL.
 */
MOON_CSFML_API char*
moon_strcopyA(const char* ansi, unsigned long length);

/**
 * Creates a copy of wide string.
 * Must be freed with 'moon_free' after usage.
 * Result will be null-terminated.
 * If fails, returns NULL.
 */
MOON_CSFML_API wchar_t*
moon_strcopyW(const wchar_t* wide, unsigned long length);

/**
 * Returns 1 if ansi strings are equal, 0 otherwise.
 * Strings must be null-terminated.
 * Strings are equal if they have the same size and
 *same characters.
 */
MOON_CSFML_API int
moon_str_is_equalA(const char* str1, const char* str2);

/**
 * Returns 1 if wide strings are equal, 0 otherwise.
 * Strings must be null-terminated.
 * Strings are equal if they have the same size and
 *same characters.
 */
MOON_CSFML_API int
moon_str_is_equalW(const wchar_t* str1, const wchar_t* str2);

/**
 * String must be null-terminated.
 * If fails, returns NULL.
 * If length is is equal to 'moon_Utils_StringLengthUnknown', the length
 *will be calculated automatically.
 * Removes whitespace characters from the beginning of the string.
 * Uses range of codes instead of comparing with each character.
 * Deletion stops when a character is not a whitespace character.
 * The result string will be null-terminated.
 * New string should be freed after usage.
 */
MOON_CSFML_API char*
moon_str_lstrip_whitespaceA(
	const char* str,
	long long str_length
);

/**
 * String must be null-terminated.
 * If fails, returns NULL.
 * If length is is equal to 'moon_Utils_StringLengthUnknown', the length
 *will be calculated automatically.
 * Removes whitespace characters from the beginning of the string.
 * Uses range of codes instead of comparing with each character.
 * Deletion stops when a character is not a whitespace character.
 * The result string will be null-terminated.
 * New string should be freed after usage.
 */
MOON_CSFML_API wchar_t*
moon_str_lstrip_whitespaceW(
	const wchar_t* str,
	long long str_length
);

/**
 * String must be null-terminated.
 * If fails, returns NULL.
 * If length is is equal to 'moon_Utils_StringLengthUnknown', the length
 *will be calculated automatically.
 * Removes whitespace characters from the tail of the string.
 * Uses range of codes instead of comparing with each character.
 * Deletion stops when a character is not a whitespace character.
 * The result string will be null-terminated.
 * New string should be freed after usage.
 */
MOON_CSFML_API char*
moon_str_rstrip_whitespaceA(
	const char* str,
	long long str_length
);

/**
 * String must be null-terminated.
 * If fails, returns NULL.
 * If length is is equal to 'moon_Utils_StringLengthUnknown', the length
 *will be calculated automatically.
 * Removes whitespace characters from the tail of the string.
 * Uses range of codes instead of comparing with each character.
 * Deletion stops when a character is not a whitespace character.
 * The result string will be null-terminated.
 * New string should be freed after usage.
 */
MOON_CSFML_API wchar_t*
moon_str_rstrip_whitespaceW(
	const wchar_t* str,
	long long str_length
);

/**
 * Strings must be null-terminated.
 * If fails, returns NULL.
 * If length is is equal to 'moon_Utils_StringLengthUnknown', the length
 *will be calculated automatically.
 * Removes whitespace characters from the tail and head of the string.
 * Uses range of codes instead of comparing with each character.
 * Deletion stops when a character is not a whitespace character.
 * The result string will be null-terminated.
 * New string should be freed after usage.
 */
MOON_CSFML_API char*
moon_str_strip_whitespaceA(
	const char* str,
	long long str_length
);

/**
 * Strings must be null-terminated.
 * If fails, returns NULL.
 * If length is is equal to 'moon_Utils_StringLengthUnknown', the length
 *will be calculated automatically.
 * Removes whitespace characters from the tail and head of the string.
 * Uses range of codes instead of comparing with each character.
 * Deletion stops when a character is not a whitespace character.
 * The result string will be null-terminated.
 * New string should be freed after usage.
 */
MOON_CSFML_API wchar_t*
moon_str_strip_whitespaceW(
	const wchar_t* str,
	long long str_length
);


#ifdef __cplusplus
}
#endif


#endif
