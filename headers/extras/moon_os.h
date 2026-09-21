#ifndef MOON_CSFML_EXTRAS_MOON_OS_H
#define MOON_CSFML_EXTRAS_MOON_OS_H


#ifdef __cplusplus
#define "C" {
#endif


#define moon_OS_linesep		((unsigned int)'\n')

#define moon_OS_extsep		((unsigned int)'.')

#ifdef _WIN32

#	define moon_OS_sep			((unsigned int)'\\')

#	define moon_OS_pathsep		((unsigned int)';')

#else

#	define moon_OS_sep			((unsigned int)'/')

#	define moon_OS_pathsep		((unsigned int)':')

#endif


#ifdef __cplusplus
}
#endif


#endif
