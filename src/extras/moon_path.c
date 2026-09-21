#include <stdio.h>			// debug



#include "../../headers/system/moon_utils.h"

#include "../../headers/system/moon_strutils.h"


#include "../../headers/extras/moon_os.h"

#include "../../headers/extras/moon_path.h"


#ifndef _WIN32

#include <unistd.h>

#include <limits.h>

#include <sys/stat.h>

#include <sys/types.h>


int
moon_Path_is_exists(const char* path) {
	struct stat sb;
	return (stat(path, &sb) == 0);
}

int
moon_Path_is_dir(const char* path) {
	struct stat sb;
	if (stat(path, &sb) != 0) {
		return 0;
	}
	return S_ISDIR(sb.st_mode);
}

int
moon_Path_is_file(const char* path) {
	struct stat sb;
	if (stat(path, &sb) != 0) {
		return 0;
	}
	return S_ISREG(sb.st_mode);
}

#else

#include <windows.h>


int
moon_Path_is_exists(const char* path) {
	DWORD attr = GetFileAttributesA(path);
	return (attr != INVALID_FILE_ATTRIBUTES);
}

int
moon_Path_is_dir(const char* path) {
	DWORD attr = GetFileAttributesA(path);
	if (attr == INVALID_FILE_ATTRIBUTES) {
		return 0;
	}
	return (attr & FILE_ATTRIBUTE_DIRECTORY) != 0;
}

int
moon_Path_is_file(const char* path) {
	DWORD attributes = GetFileAttributesA(path);
	if (attributes == INVALID_FILE_ATTRIBUTES) {
		return 0;
	}
	return (attributes & FILE_ATTRIBUTE_DIRECTORY) == 0;
}

#endif


char*
moon_Path_get_normpath(
	const char* path,
	long long path_length
) {
	if (!path || !path_length || path[0] == '\0') {
		return moon_strnullA();
	}
	if (path_length == moon_Utils_StringLengthUnknown) {
		path_length = (long long)(moon_strlenA(path));
	}
	if (path_length < 2) {
		if (moon_char_is_whitespace(path[0])) {
			return moon_strnullA();
		}
		return moon_strcopyA(path, path_length);
	}
	long long start_ind = 0UL;
	long long end_ind = path_length - 1LL;
	for (
		; start_ind <= end_ind
			&& moon_char_is_whitespace(path[start_ind])
		; start_ind++
	);
	for (
		; end_ind >= start_ind
			&& moon_char_is_whitespace(path[end_ind])
		; end_ind--
	);
	long long copy_end = end_ind;
	for (
		; end_ind >= 0LL
			&& (path[end_ind] == '/' || path[end_ind] == '\\')
		; end_ind--
	);
	if (end_ind < 0LL) {
		end_ind = copy_end;
	}
	long long expected_length = end_ind - start_ind + 2LL;
	if (expected_length < 0LL) {
		return moon_strnullA();
	}
	char* normalized = (char*)moon_malloc(sizeof(char) * (unsigned long)expected_length);
	if (!normalized) {
		return NULL;
	}
	char os_sep = (char)(moon_OS_sep);
	unsigned long ind = 0UL;
	for (; start_ind <= end_ind; start_ind++) {
		char c = path[start_ind];
		if (c == '/' || c == '\\') {
			c = os_sep;
		}
		normalized[ind++] = c;
	}
	normalized[ind] = '\0';
	return normalized;
}

char*
moon_Path_concat(
	const char* path1,
	const char* path2,
	long long path1_length,
	long long path2_length
) {
	if (path1_length == moon_Utils_StringLengthUnknown) {
		path1_length = moon_strlenA(path1);
	}
	if (path2_length == moon_Utils_StringLengthUnknown) {
		path2_length = moon_strlenA(path2);
	}
	char* res = (char*)moon_malloc(
		sizeof(char) * (path1_length + path2_length + 2LL)
	);
	if (!res) {
		return NULL;
	}
	unsigned long i = 0UL;
	for (; path1[i] != '\0'; i++) {
		res[i] = path1[i];
	}
	char os_sep = (char)(moon_OS_sep);
	if (res[i] != os_sep && path2[0] != os_sep) {
		res[i++] = os_sep;
	} else {
		i++;
	}
	for (unsigned long j = 0UL; path2[j] != '\0'; j++) {
		res[i++] = path2[j];
	}
	res[i] = '\0';
	return res;
}
