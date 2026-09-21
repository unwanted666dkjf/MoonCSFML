#include <fstream>

#include <iostream>


#include "../../headers/system/moon_utils.h"

#include "../../headers/system/moon_strutils.h"


#include "../../headers/extras/moon_file.h"


struct moon_File {

	moon_File();

	~moon_File();


	unsigned int 	mode;
	std::ifstream* 	in_stream;
	std::ofstream* 	out_stream;

};


static int
moon_File_is_mode_readable(unsigned int mode);

static int
moon_File_is_mode_write(unsigned int mode);

static int
moon_File_is_mode_append(unsigned int mode);

static int
moon_File_is_mode_writable(unsigned int mode);

static int
moon_File_is_mode_binary(unsigned int mode);

static std::ios_base::seekdir
moon_File_translate_position(int position);

static std::ios_base::openmode
moon_File_translate_mode(unsigned int mode);


moon_File*
moon_File_open(
	const char* filepath,
	unsigned int mode
) {
	moon_File* self = new moon_File();
	std::ios_base::openmode opmode = moon_File_translate_mode(mode);
	if (moon_File_is_mode_writable(mode)) {
		self->out_stream = new std::ofstream(filepath, opmode);
		if (!self->out_stream->is_open()) {
			delete self;
			return NULL;
		}
	} else {
		self->in_stream = new std::ifstream(filepath, opmode);
		if (!self->in_stream->is_open()) {
			delete self;
			return NULL;
		}
	}
	self->mode = mode;
	return self;
}

void
moon_File_close(moon_File* self) {
	delete self;
}

int
moon_File_is_mode_read(const moon_File* self) {
	return moon_File_is_mode_readable(self->mode);
}

int
moon_File_is_mode_write(const moon_File* self) {
	return moon_File_is_mode_write(self->mode);
}

int
moon_File_is_mode_append(const moon_File* self) {
	return moon_File_is_mode_append(self->mode);
}

int
moon_File_is_writable(const moon_File* self) {
	return moon_File_is_mode_writable(self->mode);
}

int
moon_File_is_binary(const moon_File* self) {
	return moon_File_is_mode_binary(self->mode);
}

void
moon_File_write(
	moon_File* self,
	const char* str
) {
	(*self->out_stream) << str;
}

void
moon_File_write_ex(
	moon_File* self,
	const char* str,
	unsigned long length
) {
	if (moon_File_is_mode_binary(self->mode)) {
		self->out_stream->write(
			str,
			static_cast<std::streamsize>(length)
		);
	} else {
		self->out_stream->write(str, length);
	}
}

char*
moon_File_read(
	moon_File* self,
	unsigned long* res_length
) {
	std::string tmp(
		std::istreambuf_iterator<char>(*self->in_stream),
		std::istreambuf_iterator<char>()
	);
	(*res_length) = tmp.size();
	if (moon_File_is_mode_binary(self->mode)) {
		char* res = (char*)moon_malloc(sizeof(char) * (*res_length));
		moon_memcpy(res, tmp.data(), (*res_length));
		return res;
	}
	return moon_strcopyA(tmp.c_str(), (*res_length));
}

char*
moon_File_read_ex(
	moon_File* self,
	unsigned long* res_length,
	unsigned long length
) {
	std::string tmp(length, '\0');

	self->in_stream->read(
		&tmp[0],
		static_cast<std::streamsize>(length)
	);

	(*res_length) = static_cast<unsigned long>(
		self->in_stream->gcount()
	);

	tmp.resize((*res_length));
	if (moon_File_is_mode_binary(self->mode)) {
		char* res = (char*)moon_malloc(sizeof(char) * (*res_length));
		moon_memcpy(res, tmp.data(), (*res_length));
		return res;
	}
	return moon_strcopyA(tmp.c_str(), (*res_length));
}

int
moon_File_next_char(moon_File* self) {
	int c = self->in_stream->get();
	if (c != EOF) {
		return c;
	}
	return moon_File_EOF;
}

void
moon_File_seek(
	moon_File* self,
	long long offset,
	int position
) {
	std::ios_base::seekdir pos = moon_File_translate_position(position);
	if (moon_File_is_mode_readable(self->mode)) {
		self->in_stream->clear();
		self->in_stream->seekg(offset, pos);
	} else {
		self->out_stream->clear();
		self->out_stream->seekp(offset, pos);
	}
}

long long
moon_File_tell(moon_File* self) {
	std::streampos pos;
	if (moon_File_is_mode_readable(self->mode)) {
		pos = self->in_stream->tellg();
	} else {
		pos = self->out_stream->tellp();
	}
	if (pos == std::streampos(-1)) {
		return moon_File_EOF;
	}
	return static_cast<long long>(pos);
}


int
moon_File_is_mode_readable(unsigned int mode) {
	return (mode & moon_File_Mode_Read) != 0;
}

int
moon_File_is_mode_write(unsigned int mode) {
	return (mode & moon_File_Mode_Write) != 0;
}

int
moon_File_is_mode_append(unsigned int mode) {
	return (mode & moon_File_Mode_Append) != 0;
}

int
moon_File_is_mode_writable(unsigned int mode) {
	return moon_File_is_mode_write(mode)
		|| moon_File_is_mode_append(mode);
}

int
moon_File_is_mode_binary(unsigned int mode) {
	return (mode & moon_File_Mode_Binary) != 0;
}

std::ios_base::seekdir
moon_File_translate_position(int position) {
	switch (position) {

		case moon_File_Position_Beg:
			return std::ios::beg;
		case moon_File_Position_Cur:
			return std::ios::cur;
		case moon_File_Position_End:
			return std::ios::end;
		default:
			return std::ios::cur;
	}
}

std::ios_base::openmode
moon_File_translate_mode(unsigned int mode) {

	std::ios_base::openmode result = {};

	switch (mode & (moon_File_Mode_Write | moon_File_Mode_Append)) {
		case moon_File_Mode_Read:
			result = std::ios::in;
			break;

		case moon_File_Mode_Write:
			result = std::ios::out;
			break;

		case moon_File_Mode_Append:
			result = std::ios::out | std::ios::app;
			break;

		default:
			result = std::ios::in;
	}

	if (moon_File_is_mode_binary(mode)) {
		result |= std::ios::binary;
	}

	return result;
}


moon_File::moon_File() {
	in_stream 	= nullptr;
	out_stream 	= nullptr;
	mode 		= moon_File_Mode_Unknown;
}

moon_File::~moon_File() {
	if (in_stream) {
		in_stream->close();
		delete in_stream;
	}
	if (out_stream) {
		out_stream->close();
		delete out_stream;
	}
}
