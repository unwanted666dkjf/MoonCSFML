#ifndef MOON_CSFML_EXTRAS_MOON_FILE_H
#define MOON_CSFML_EXTRAS_MOON_FILE_H


#include "../import_macro.h"


#ifdef __cplusplus
extern "C" {
#endif


#define moon_File_EOF (-1)


enum {
	moon_File_Position_Beg,				// From the beginning of the file.
	moon_File_Position_Cur,				// From the current position.
	moon_File_Position_End,				// From the end of the file.
	moon_File_Position_Invalid = -1 	// Only for internal usage, useless.
};

enum {
	moon_File_Mode_Read		= 1 << 0,
	moon_File_Mode_Write	= 1 << 1,
	moon_File_Mode_Append	= 1 << 2,
	moon_File_Mode_Binary	= 1 << 3,
	moon_File_Mode_Unknown  = 13
};


struct MOON_CSFML_API moon_File;


/**
 * Basically, wrapper of 'std::ifstream'
 *and 'std::ofstream'.
 * Why not just use the built-in 'FILE'? I am a masochist, but not that much.
 */
typedef struct moon_File moon_File;


/**
 * Opens a file using given mode.
 * Mode should be valid, otherwise behaviour is undefined.
 * Available modes: 'moon_File_Mode_Read',
 *'moon_File_Mode_Write', 'moon_File_Mode_Append'.
 * If you need to perform operations in binary mode,
 *you can add a flag, for example:
 *     'moon_File_Mode_Read | moon_File_Mode_Binary'.
 * If the file could not be opened, it will return NULL.
 * If you open a file in write mode (but not append), it will be overwritten.
 * If the file is opened in reading mode and does not exist, it will be created.
 * Currently, simultaneous reading from and writing to the file is not supported.
 */
MOON_CSFML_API moon_File*
moon_File_open(
	const char* filepath,
	unsigned int mode
);

/**
 * Closes streams and destroys file object.
 */
MOON_CSFML_API void
moon_File_close(moon_File* self);

/**
 * Returns 1 if the file is open for reading.
 * Otherwise, returns 0.
 */
MOON_CSFML_API int
moon_File_is_mode_read(const moon_File* self);

/**
 * Returns 1 if the file is open for writing.
 * Otherwise, returns 0.
 */
MOON_CSFML_API int
moon_File_is_mode_write(const moon_File* self);

/**
 * Returns 1 if the file is open for appending.
 * Otherwise, returns 0.
 */
MOON_CSFML_API int
moon_File_is_mode_append(const moon_File* self);

/**
 * Returns 1 if the file is open
 *for writing or appending.
 * Otherwise, returns 0.
 */
MOON_CSFML_API int
moon_File_is_writable(const moon_File* self);

/**
 * Returns 1 if the file is open in binary mode.
 * Otherwise, returns 0.
 */
MOON_CSFML_API int
moon_File_is_binary(const moon_File* self);

/**
 * Writes whole ansi/multibyte string
 *to a file.
 */
MOON_CSFML_API void
moon_File_write(
	moon_File* self,
	const char* str
);

/**
 * Writes length characters from
 * ansi/multibyte string to a file.
 */
MOON_CSFML_API void
moon_File_write_ex(
	moon_File* self,
	const char* str,
	unsigned long length
);

/**
 * Reads the entire file and returns its contents.
 * The size of the content will be written to 'res_length'.
 * Result must be freed after usage.
 * If mode is not binary, result string is null-terminated.
 */
MOON_CSFML_API char*
moon_File_read(
	moon_File* self,
	unsigned long* res_length
);

/**
 * Reads and returns length characters from file.
 * Number of bytes actually read will be written to 'res_length'.
 * Result must be freed after usage.
 * If mode is not binary, result string is null-terminated.
 */
MOON_CSFML_API char*
moon_File_read_ex(
	moon_File* self,
	unsigned long* res_length,
	unsigned long length
);

/**
 * Returns the next character from the file
 *if it is open in read mode.
 * If the end of the file is reached,
 *it will return 'moon_File_EOF'.
 */
MOON_CSFML_API int
moon_File_next_char(moon_File* self);

/**
 * Sets the position in the file using the 'offset'
 *offset and the 'position' reference point.
 * 'position' can have these values: 'moon_File_Position_Beg',
 *'moon_File_Position_Cur', 'moon_File_Position_End'.
 * If any of arguments is invalid, behaviour is undefined.
 */
MOON_CSFML_API void
moon_File_seek(
	moon_File* self,
	long long offset,
	int position
);

/**
 * Returns the current position in the file relative to its beginning.
 * In case of an error or end of the file, it will return 'moon_File_EOF'.
 */
MOON_CSFML_API long long
moon_File_tell(moon_File* self);


#ifdef __cplusplus
}
#endif


#endif
