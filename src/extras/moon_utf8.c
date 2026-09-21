#include <stdlib.h>

#include <string.h>

#ifdef _WIN32
	#include <windows.h>
#else
	#include <iconv.h>
#endif


#include "../../headers/extras/moon_utf8.h"


char*
moon_UTF8_wstr_to_utf8(const wchar_t* wstr) {
	if (!wstr) {
		return NULL;
	}
	#ifdef _WIN32
		int needed = WideCharToMultiByte(
			CP_UTF8, 0,
			wstr, -1,
			NULL, 0,
			NULL, NULL
		);
		if (needed <= 0) {
			return NULL;
		}
		char* res = (char*)malloc((size_t)needed);
		if (!res) {
			return NULL;
		}
		if (
			!WideCharToMultiByte(
				CP_UTF8, 0,
				wstr, -1,
				res, needed,
				NULL, NULL
			)
		) {
			free(res);
			return NULL;
		}
		return res;
	#else
		const char* from_charset =
			#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
				"UTF-32LE";
			#else
				"UTF-32BE";
			#endif
		const char* to_charset = "UTF-8";
		size_t in_wlen = wcslen(wstr) + 1; // +1 for terminating L'\0'
		size_t in_bytes = in_wlen * sizeof(wchar_t);

		// up to 4 byte for utf-8 and '\0'
		size_t out_cap = in_wlen * 4;
		char* out = (char*)malloc(out_cap);
		if (!out) {
			return NULL;
		}

		char* out_ptr = out;
		size_t out_bytes_left = out_cap;

		const char* in_ptr = (const char*)wstr;

		iconv_t cd = iconv_open(to_charset, from_charset);
		if (cd == (iconv_t)-1) {
			free(out);
			return NULL;
		}

		if (iconv(cd, (char**)&in_ptr, &in_bytes, &out_ptr, &out_bytes_left) == (size_t)-1) {
			iconv_close(cd);
			free(out);
			return NULL;
		}
		*out_ptr = '\0';

		iconv_close(cd);

		return out;
	#endif
}

wchar_t*
moon_UTF8_utf8_to_wstr(const char* utf8) {
	if (!utf8) {
		return NULL;
	}
	#ifdef _WIN32
		int needed = MultiByteToWideChar(
			CP_UTF8,          // input code page
			0,
			utf8,
			-1,               // NUL-terminated input
			NULL,
			0
		);
		if (needed <= 0) {
			return NULL;
		}

		wchar_t* out = (wchar_t*)malloc((size_t)needed * sizeof(wchar_t));
		if (!out) {
			return NULL;
		}

		int written = MultiByteToWideChar(
			CP_UTF8, 0,
			utf8,
			-1,
			out,
			needed
		);
		if (written == 0) {
			free(out);
			return NULL;
		}
		return out; // contains terminating L'\0'
	#else
		const char* to_charset =
			#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
				"UTF-32LE";
			#else
				"UTF-32BE";
			#endif
		const char* from_charset = "UTF-8";

		// Length in bytes + 1 '\0'
		size_t in_bytes = strlen(utf8) + 1;

		// Upper bound: UTF-8 -> UTF-32 1 byte is at most 1 wchar_t,
		size_t out_cap_w = in_bytes + 1;
		wchar_t* out = (wchar_t*)malloc(out_cap_w * sizeof(wchar_t));
		if (!out) {
			return NULL;
		}

		char* out_ptr = (char*)out;
		size_t out_bytes_left = out_cap_w * sizeof(wchar_t);

		iconv_t cd = iconv_open(to_charset, from_charset);
		if (cd == (iconv_t)-1) {
			free(out);
			return NULL;
		}

		const char* in_ptr_const = utf8;
		char* in_ptr = (char*)in_ptr_const;

		size_t res = iconv(cd, &in_ptr, &in_bytes, &out_ptr, &out_bytes_left);
		if (res == (size_t)-1) { // conversion error
			free(out);
			return NULL;
		}

		iconv_close(cd);

		if (out_bytes_left >= sizeof(wchar_t)) {
			((wchar_t*)out)[out_cap_w - 1] = L'\0';
		} else {
			free(out);
			return NULL;
		}

		return out;
	#endif
}
