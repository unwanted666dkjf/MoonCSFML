#include <string>

#include <fstream>

#include <iostream>



#include "../../headers/system/moon_strutils.h"


#include "../../headers/extras/moon_filelines.h"


struct moon_Filelines {

	moon_Filelines(const char* filepath);

	~moon_Filelines();


	short has_next;
	std::ifstream* file;

};


moon_Filelines*
moon_Filelines_open(const char* filepath) {
	moon_Filelines* self = new moon_Filelines(filepath);
	if (!self->has_next) {
		delete self;
		return NULL;
	}
	return self;
}

void
moon_Filelines_close(moon_Filelines* self) {
	delete self;
}

int
moon_Filelines_has_next(const moon_Filelines* self) {
	return self->has_next;
}

char*
moon_Filelines_next(moon_Filelines* self) {
	std::string line;
	if (std::getline(*self->file, line)) {
		self->has_next = 1;
	} else {
		self->has_next = 0;
	}
	return moon_strcopyA(line.c_str(), line.size());
}


moon_Filelines::moon_Filelines(const char* filepath) {
	file = new std::ifstream(filepath);
	if (!file->is_open()) {
		delete file;
		file = nullptr;
		has_next = 0;
	} else {
		has_next = 1;
	}
}

moon_Filelines::~moon_Filelines() {
	if (file) {
		file->close();
		delete file;
	}
}
