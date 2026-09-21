#ifndef MOON_CSFML_SYSTEM_STR_UTILS_HPP
#define MOON_CSFML_SYSTEM_STR_UTILS_HPP


#include <cmath>



#include "./moon_utils.h"

#include "./moon_strutils.h"


template <typename StrT>
StrT moon_nullterminator() {
	return static_cast<StrT>(moon_Utils_StringNullTerminator);
}

template <typename StrT>
unsigned long moon_strlen(const StrT* str) {
	unsigned long length = 0UL;
	StrT null = moon_nullterminator<StrT>();
	for(; str[length] != null; length++);
	return length;
}

template <typename StrT>
StrT* moon_strnull() {
	StrT* str = (StrT*)moon_malloc(sizeof(StrT));
	if (!str) {
		return NULL;
	}
	str[0] = moon_nullterminator<StrT>();
	return str;
}

template <typename StrT>
StrT* moon_strslice(
	const StrT* str,
	long long start,
	long long stop,
	long long step
) {
	if (step == 0LL) {
		return moon_strnull<StrT>();
	}
	double length = std::abs(
		(1. * stop - 1. * start)
		/ 1. * step
	);
	unsigned long expected_length = static_cast<unsigned long>(length);
	if (static_cast<double>(expected_length) < length) {
		expected_length++;
	}
	expected_length++;		// Ensure there is at least 1.
	StrT* slice = (StrT*)moon_malloc(sizeof(StrT) * expected_length);
	unsigned long ind = 0UL;
	if (step < 0) {
		for (; stop >= start; stop += step) {
			slice[ind++] = str[stop];
		}
	} else {
		for (; start < stop; start += step) {
			slice[ind++] = str[start];
		}
	}
	slice[ind] = moon_nullterminator<StrT>();
	return slice;
}

template <typename StrT>
StrT* moon_strcat(
	const StrT* str1,
	const StrT* str2,
	long long str1_length,
	long long str2_length
) {
	if (str1_length == moon_Utils_StringLengthUnknown) {
		str1_length = moon_strlen<StrT>(str1);
	}
	if (str2_length == moon_Utils_StringLengthUnknown) {
		str2_length = moon_strlen<StrT>(str2);
	}
	StrT* res = (StrT*)moon_malloc(
		sizeof(StrT) * (str1_length + str2_length + 1LL)
	);
	if (!res) {
		return NULL;
	}
	StrT null = moon_nullterminator<StrT>();
	long long i = 0UL;
	for (; i < str1_length; i++) {
		res[i] = str1[i];
	}
	for (long long j = 0UL; j < str2_length; j++) {
		res[i++] = str2[j];
	}
	res[i] = null;
	return res;
}

template <typename StrT>
StrT* moon_strcopy(const StrT* ansi, unsigned long length) {
	StrT* res = (StrT*)moon_malloc(sizeof(StrT) * (length + 1UL));
	if (!res) {
		return NULL;
	}
	unsigned long i = 0UL;
	for (; i < length; i++) {
		res[i] = ansi[i];
	}
	res[i] = moon_nullterminator<StrT>();
	return res;
}

template <typename StrT>
int moon_str_is_equal(const StrT* str1, const StrT* str2) {
	unsigned long i = 0UL;
	StrT null = moon_nullterminator<StrT>();
	for (; str1[i] != null && str2[i] != null; i++) {
		if (str1[i] != str2[i]) {
			return 0;
		}
	}
	return str1[i] == str2[i];
}

template <typename StrT>
long long moon_str_nowhitespace_rind(const StrT* str, long long str_length) {
	str_length--;
	for (; str_length >= 0LL; str_length--) {
		if (!moon_char_is_whitespace(str[str_length])) {
			break;
		}
	}
	return str_length;
}

template <typename StrT>
long long moon_str_nowhitespace_lind(const StrT* str, long long str_length) {
	long long ind = 0LL;
	for (; ind < str_length; ind++) {
		if (!moon_char_is_whitespace(str[ind])) {
			break;
		}
	}
	return ind;
}

template <typename StrT>
StrT* moon_str_rstrip_whitespace(const StrT* str, long long str_length) {
	StrT null = moon_nullterminator<StrT>();
	if (!str || str[0] == null) {
		return moon_strnull<StrT>();
	}
	if (str_length == moon_Utils_StringLengthUnknown) {
		str_length = moon_strlen<StrT>(str);
	}
	long long rind = moon_str_nowhitespace_rind(str, str_length);
	if (rind < 0LL) {
		return moon_strnull<StrT>();
	}
	return moon_strslice<StrT>(str, 0LL, rind + 1LL, 1LL);
}

template <typename StrT>
StrT* moon_str_lstrip_whitespace(const StrT* str, long long str_length) {
	StrT null = moon_nullterminator<StrT>();
	if (!str || str[0] == null) {
		return moon_strnull<StrT>();
	}
	if (str_length == moon_Utils_StringLengthUnknown) {
		str_length = moon_strlen<StrT>(str);
	}
	long long lind = moon_str_nowhitespace_lind(str, str_length);
	if (lind >= str_length) {
		return moon_strnull<StrT>();
	}
	return moon_strslice<StrT>(str, lind, str_length, 1LL);
}

template <typename StrT>
StrT* moon_str_strip_whitespace(const StrT* str, long long str_length) {
	StrT null = moon_nullterminator<StrT>();
	if (!str || str[0] == null) {
		return moon_strnull<StrT>();
	}
	if (str_length == moon_Utils_StringLengthUnknown) {
		str_length = moon_strlen<StrT>(str);
	}
	long long rind = moon_str_nowhitespace_rind(str, str_length);
	if (rind < 0LL) {
		return moon_strnull<StrT>();
	}
	long long lind = moon_str_nowhitespace_lind(str, str_length);
	return moon_strslice<StrT>(str, lind, rind + 1LL, 1LL);
}

template <typename StrT, typename stdStrT>
StrT* moon_format_strnum(const stdStrT& text) {
	long long text_size = static_cast<long long>(text.size()) - 1LL;
	unsigned int code_zero = 48;
	StrT char_zero = static_cast<StrT>(code_zero);
	for (
		; text_size >= 0LL
		&& text[text_size] == char_zero
		; text_size--
	);
	StrT zero[2];
	zero[0] = char_zero;
	zero[1] = moon_nullterminator<StrT>();
	if (text_size < 0LL) {
		return moon_strcopy<StrT>(zero, 1);
	}
	if (text[text_size] == static_cast<StrT>(46)) {	// '.'
		text_size--;
		if (text_size < 0LL) {
			return moon_strcopy<StrT>(zero, 1);
		}
	}
	return moon_strcopy<StrT>(text.c_str(), text_size + 1LL);
}

template <typename StrT, typename stdStrT>
StrT* moon_format_strprec(const stdStrT& text, int precision) {
	stdStrT buffer;
	buffer.reserve(text.size() + 1UL);
	StrT dot = static_cast<StrT>(46);	// '.'
	unsigned long i = 0UL;
	for (; i < text.size() && text[i] != dot; i++) {
		buffer.push_back(text[i]);
	}
	if (i >= text.size()) {
		return moon_strcopy<StrT>(buffer.c_str(), buffer.size());
	}
	buffer.push_back(text[i++]);
	for (int j = 0; j < precision && i < text.size(); j++) {
		buffer.push_back(text[i++]);
	}
	while (!buffer.empty() && (buffer.back() == dot)) {
		buffer.pop_back();
	}
	if (buffer.empty()) {
		buffer.push_back(static_cast<StrT>(48));	// push '0'
	}
	return moon_strcopy<StrT>(buffer.c_str(), buffer.size());
}


#endif
