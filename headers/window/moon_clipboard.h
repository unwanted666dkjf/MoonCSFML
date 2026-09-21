#ifndef MOON_CSFML_WINDOW_MOON_CLIPBOARD_H
#define MOON_CSFML_WINDOW_MOON_CLIPBOARD_H


#include "../import_macro.h"


#ifdef __cplusplus
extern "C" {
#endif


#include <wchar.h>


/**
 * Sets the content of the clipboard as ansi string.
 * This function sets the content of the clipboard as a
 *string.
 * Due to limitations on some operating systems,
 *setting the clipboard contents is only
 *guaranteed to work if there is currently an
 *open window for which events are being handled.
 */
MOON_CSFML_API void
moon_Clipboard_set_stringA(const char* str);

/**
 * Sets the content of the clipboard as wide string.
 * This function sets the content of the clipboard as a
 *string.
 * Due to limitations on some operating systems,
 *setting the clipboard contents is only
 *guaranteed to work if there is currently an
 *open window for which events are being handled.
 */
MOON_CSFML_API void
moon_Clipboard_set_stringW(const wchar_t* str);

/**
 * Returns the content of the clipboard as ansi string.
 * Result must be freed after usage.
 * Result is null-terminated.
 * This function returns the content of the clipboard
 *as a string. If the clipboard does not contain string
 *it returns an empty string.
 */
MOON_CSFML_API char*
moon_Clipboard_get_stringA();

/**
 * Returns the content of the clipboard as wide string.
 * Result must be freed after usage.
 * Result is null-terminated.
 * This function returns the content of the clipboard
 *as a string. If the clipboard does not contain string
 *it returns an empty string.
 */
MOON_CSFML_API wchar_t*
moon_Clipboard_get_stringW();


#ifdef __cplusplus
}
#endif


#endif
