#ifndef MOON_CSFML_IMPORT_MACRO_H
#define MOON_CSFML_IMPORT_MACRO_H


#if defined(_WIN32) || defined(_WIN64)
	#ifdef MOON_CSFML_EXPORTS
		#define MOON_CSFML_API __declspec(dllexport)
	#else
		#define MOON_CSFML_API
	#endif
#else
	#ifdef MOON_CSFML_EXPORTS
		#define MOON_CSFML_API __attribute__((visibility("default")))
	#else
		#define MOON_CSFML_API
	#endif
#endif


#endif
