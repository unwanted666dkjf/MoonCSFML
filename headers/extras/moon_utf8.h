#ifndef MOON_CSFML_EXTRAS_MOON_UTF8_H
#define MOON_CSFML_EXTRAS_MOON_UTF8_H


#include "../import_macro.h"


#ifdef __cplusplus
extern "C" {
#endif


#include <wchar.h>


/**
 * Converts wide string to multibyte utf-8 char string.
 * On Windows, uses WideCharToMultiByte and CP_UTF8.
 * On Linux uses iconv.
 * Result is null-terminated.
 * Caller must free result string after usage.
 */
MOON_CSFML_API char*
moon_UTF8_wstr_to_utf8(const wchar_t* wstr);

/**
 * Converts utf-8 multibyte string to wide string.
 * On Windows, uses MultiByteToWideChar and CP_UTF8.
 * On Linux uses iconv.
 * Result is null-terminated.
 * Caller must free result string after usage.
 */
MOON_CSFML_API wchar_t*
moon_UTF8_utf8_to_wstr(const char* utf8);


#ifdef __cplusplus
}
#endif


#endif
