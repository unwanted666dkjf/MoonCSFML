#include <string>

#include <cstdlib>



#include "../../headers/system/moon_strutils.h"

#include "../../headers/system/StrUtils.hpp"


int
moon_char_is_whitespace(unsigned int c) {
	if (c == 32) {
		return 1;
	}
	return c > 8 && c < 14;
}

float
moon_strofA(const char* str) {
	char* end = nullptr;
	return std::strtof(str, &end);
}

float
moon_strofW(const wchar_t* str) {
	wchar_t* end = nullptr;
	return std::wcstof(str, &end);
}

double
moon_strtodA(const char* str) {
	char* end = nullptr;
	return std::strtod(str, &end);
}

double
moon_strtodW(const wchar_t* str) {
	wchar_t* end = nullptr;
	return std::wcstod(str, &end);
}

long
moon_strtolA(const char* str, int base) {
	char* end = nullptr;
	return std::strtol(str, &end, base);
}

long
moon_strtolW(const wchar_t* str, int base) {
	wchar_t* end = nullptr;
	return std::wcstol(str, &end, base);
}

unsigned long
moon_strlenA(const char* str) {
	return moon_strlen<char>(str);
}

unsigned long
moon_strlenW(const wchar_t* str) {
	return moon_strlen<wchar_t>(str);
}

char*
moon_strnullA() {
	return moon_strnull<char>();
}

wchar_t*
moon_strnullW() {
	return moon_strnull<wchar_t>();
}

char*
moon_str_remove_external_quotesA(
	const char* str,
	long long str_length
) {
	return moon_str_remove_external_quotes<char>(str, str_length);
}

wchar_t*
moon_str_remove_external_quotesW(
	const wchar_t* str,
	long long str_length
) {
	return moon_str_remove_external_quotes<wchar_t>(str, str_length);
}

char*
moon_ftostrA(float number) {
	std::string text = std::to_string(number);
	return moon_format_strnum<char, std::string>(text);
}

wchar_t*
moon_ftostrW(float number) {
	std::wstring text = std::to_wstring(number);
	return moon_format_strnum<wchar_t, std::wstring>(text);
}

char*
moon_dtostrA(double number) {
	std::string text = std::to_string(number);
	return moon_format_strnum<char, std::string>(text);
}

wchar_t*
moon_dtostrW(double number) {
	std::wstring text = std::to_wstring(number);
	return moon_format_strnum<wchar_t, std::wstring>(text);
}

char*
moon_strprecfA(
	float number,
	int precision
) {
	std::string text = std::to_string(number);
	return moon_format_strprec<char, std::string>(text, precision);
}

wchar_t*
moon_strprecfW(
	float number,
	int precision
) {
	std::wstring text = std::to_wstring(number);
	return moon_format_strprec<wchar_t, std::wstring>(text, precision);
}

char*
moon_strsliceA(
	const char* str,
	long long start,
	long long stop,
	long long step
) {
	return moon_strslice<char>(str, start, stop, step);
}

wchar_t*
moon_strsliceW(
	const wchar_t* str,
	long long start,
	long long stop,
	long long step
) {
	return moon_strslice<wchar_t>(str, start, stop, step);
}

char*
moon_strcatA(
	const char* str1,
	const char* str2,
	long long str1_length,
	long long str2_length
) {
	return moon_strcat<char>(str1, str2, str1_length, str2_length);
}

const wchar_t*
moon_strcatW(
	const wchar_t* str1,
	const wchar_t* str2,
	long long str1_length,
	long long str2_length
) {
	return moon_strcat<wchar_t>(str1, str2, str1_length, str2_length);
}

char*
moon_strcopyA(const char* ansi, unsigned long length) {
	return moon_strcopy<char>(ansi, length);
}

wchar_t*
moon_strcopyW(const wchar_t* wide, unsigned long length) {
	return moon_strcopy<wchar_t>(wide, length);
}

int
moon_str_is_equalA(const char* str1, const char* str2) {
	return moon_str_is_equal<char>(str1, str2);
}

int
moon_str_is_equalW(const wchar_t* str1, const wchar_t* str2) {
	return moon_str_is_equal<wchar_t>(str1, str2);
}

char*
moon_str_lstrip_whitespaceA(
	const char* str,
	long long str_length
) {
	return moon_str_lstrip_whitespace<char>(str, str_length);
}

wchar_t*
moon_str_lstrip_whitespaceW(
	const wchar_t* str,
	long long str_length
) {
	return moon_str_lstrip_whitespace<wchar_t>(str, str_length);
}

char*
moon_str_rstrip_whitespaceA(
	const char* str,
	long long str_length
) {
	return moon_str_rstrip_whitespace<char>(str, str_length);
}

wchar_t*
moon_str_rstrip_whitespaceW(
	const wchar_t* str,
	long long str_length
) {
	return moon_str_rstrip_whitespace<wchar_t>(str, str_length);
}

char*
moon_str_strip_whitespaceA(
	const char* str,
	long long str_length
) {
	return moon_str_strip_whitespace<char>(str, str_length);
}

wchar_t*
moon_str_strip_whitespaceW(
	const wchar_t* str,
	long long str_length
) {
	return moon_str_strip_whitespace<wchar_t>(str, str_length);
}
