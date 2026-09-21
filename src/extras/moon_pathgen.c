#include "../../headers/system/moon_utils.h"

#include "../../headers/system/moon_strutils.h"


#include "../../headers/extras/moon_pathgen.h"


static char*
moon_Pathgen_get_curdir();


#ifndef _WIN32

#include <dirent.h>


struct moon_Pathgen {
	DIR* 			dir;
	struct dirent* 	entry;
};


moon_Pathgen*
moon_Pathgen_create(const char* start_dir) {
	moon_Pathgen* self = (moon_Pathgen*)moon_malloc(sizeof(moon_Pathgen));
	if (!self) {
		return NULL;
	}
	self->entry 	= NULL;
	self->dir 		= opendir(start_dir);
	if (!self->dir) {
		return self;
	}
	self->entry = readdir(self->dir);
	return self;
}

void
moon_Pathgen_destroy(moon_Pathgen* self) {
	if (self->dir) {
		closedir(self->dir);
	}
	moon_free(self);
}

int
moon_Pathgen_has_next(const moon_Pathgen* self) {
	if (!self->entry) {
		return 0;
	}
	return 1;
}

char*
moon_Pathgen_next(moon_Pathgen* self) {
	while (
		moon_str_is_equalA(self->entry->d_name, ".")
		|| moon_str_is_equalA(self->entry->d_name, "..")
	) {
		self->entry = readdir(self->dir);
		if (!self->entry) {
			break;
		}
	}
	if (!self->entry) {
		return moon_Pathgen_get_curdir();
	}
	char* res = moon_strcopyA(
		self->entry->d_name,
		moon_strlenA(self->entry->d_name)
	);
	self->entry = readdir(self->dir);
	return res;
}

#else


#include <windows.h>


struct moon_Pathgen {
	short 				has_next;
	HANDLE 				handle;
	WIN32_FIND_DATAA 	data;
};


moon_Pathgen*
moon_Pathgen_create(const char* start_dir) {
	moon_Pathgen* self = (moon_Pathgen*)moon_malloc(sizeof(moon_Pathgen));
	if (!self) {
		return NULL;
	}
	char pattern[MAX_PATH];
	unsigned long i = 0UL;
	for (; start_dir[i] != '\0' && i < MAX_PATH; i++) {
		pattern[i] = start_dir[i];
	}
	pattern[i++] 	= '\\';
	pattern[i++] 	= '*';
	pattern[i] 		= '\0';
	self->handle = FindFirstFileA(pattern, &self->data);
	if (self->handle == INVALID_HANDLE_VALUE) {
		self->has_next = 0;
	} else {
		self->has_next = 1;
	}
	return self;
}

void
moon_Pathgen_destroy(moon_Pathgen* self) {
	if (self->handle != INVALID_HANDLE_VALUE) {
		FindClose(self->handle);
	}
	moon_free(self);
}

int
moon_Pathgen_has_next(const moon_Pathgen* self) {
	return self->has_next;
}

char*
moon_Pathgen_next(moon_Pathgen* self) {
	while (
		moon_str_is_equalA(self->data.cFileName, ".")
		|| moon_str_is_equalA(self->data.cFileName, "..")
	) {
		self->has_next = FindNextFileA(self->handle, &self->data);
		if (!self->has_next) {
			break;
		}
	}
	if (!self->has_next) {
		return moon_Pathgen_get_curdir();
	}
	char* res = moon_strcopyA(
		self->data.cFileName,
		moon_strlenA(self->data.cFileName)
	);
	self->has_next = FindNextFileA(self->handle, &self->data);
	return res;
}

#endif


char*
moon_Pathgen_get_curdir() {
	char* res = (char*)moon_malloc(sizeof(char) * 2UL);
	res[0] = '.';
	res[1] = '\0';
	return res;
}
