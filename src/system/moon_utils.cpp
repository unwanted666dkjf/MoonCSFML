#include <ctime>

#include <cmath>

#include <cwchar>

#include <cstdio>

#include <clocale>

#include <cstdlib>

#include <cstring>

#include <cstdarg>


#include "../../headers/system/moon_utils.h"


int
moon_printf(const char* format, ...) {
	va_list ap;
	va_start(ap, format);
	int r = vprintf(format, ap);
	va_end(ap);
	if (r == EOF) {
		return -1;
	}
	return r;
}

int
moon_wprintf(const wchar_t* format, ...) {
	va_list ap;
	va_start(ap, format);
	int r = vwprintf(format, ap);
	va_end(ap);
	if (r == EOF) {
		return -1;
	}
	return r;
}

int
moon_scanf(const char* format, ...) {
	va_list ap;
	va_start(ap, format);
	int r = std::vscanf(format, ap);
	va_end(ap);
	if (r == EOF) {
		return -1;
	}
	return r;
}

int
moon_wscanf(const wchar_t* format, ...) {
	va_list ap;
	va_start(ap, format);
	int r = std::vwscanf(format, ap);
	va_end(ap);
	if (r == EOF) {
		return -1;
	}
	return r;
}

double
moon_round(double value, int digits) {
	double factor = std::pow(10., digits);
	return std::round(value * factor) / factor;
}

float
moon_roundf(float value, int digits) {
	float factor = std::powf(10.f, static_cast<float>(digits));
	return std::roundf(value * factor) / factor;
}

double
moon_ceil(double value) {
	return std::ceil(value);
}

float
moon_ceilf(float value) {
	return std::ceilf(value);
}

double
moon_floor(double value) {
	return std::floor(value);
}

float
moon_floorf(float value) {
	return std::floorf(value);
}

void*
moon_memcpy(
	void* destination,
	const void* source,
	unsigned long count
) {
	return std::memcpy(destination, source, count);
}

float*
moon_farray_create(unsigned long size) {
	return new float[size + 1UL];
}

void
moon_farray_destroy(float* arr) {
	delete arr;
}

float
moon_farray_get(
	const float* arr,
	unsigned long index
) {
	return arr[index];
}

void
moon_farray_set(
	float* arr,
	unsigned long index,
	float value
) {
	arr[index] = value;
}

int
moon_random(int low, int high) {
	int range = high - low + 1;
	int delta = static_cast<int>(
		static_cast<float>(rand())
		/ (static_cast<float>(RAND_MAX) + 1.f)
		* range
	);
	return low + delta;
}

unsigned int
moon_time_null_seed() {
	return static_cast<unsigned int>(time(NULL));
}

void
moon_srand(unsigned int seed) {
	srand(seed);
}

void*
moon_malloc(unsigned long size) {
	return std::malloc(size);
}

void
moon_free(void* ptr) {
	std::free(ptr);
}

void
moon_setlocale(int category, const char* locale_name) {
	std::setlocale(category, locale_name);
}

int
moon_locale_LC_ALL() {
	return LC_ALL;
}

int
moon_locale_LC_CTYPE() {
	return LC_CTYPE;
}

int
moon_locale_LC_NUMERIC() {
	return LC_NUMERIC;
}

int
moon_locale_LC_TIME() {
	return LC_TIME;
}

int
moon_locale_LC_COLLATE() {
	return LC_COLLATE;
}

int
moon_locale_LC_MONETARY() {
	return LC_MONETARY;
}
