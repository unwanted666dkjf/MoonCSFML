#ifndef MOON_CSFML_EXTRAS_MOON_RECTUTILS_H
#define MOON_CSFML_EXTRAS_MOON_RECTUTILS_H


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Returns position of left-top corner as 2D
 *vector.
 */
#define moon_RectUtils_get_lefttop(	\
	ResTypeV2,						\
	rect							\
)	\
	(ResTypeV2){rect.left, rect.top}

/**
 * Returns position of left-bottom corner as 2D
 *vector.
 */
#define moon_RectUtils_get_leftbottom(	\
	ResTypeV2,							\
	rect								\
)	\
	(ResTypeV2){rect.left, rect.top + rect.height}

/**
 * Returns position of right-top corner as 2D
 *vector.
 */
#define moon_RectUtils_get_righttop(	\
	ResTypeV2,							\
	rect								\
)	\
	(ResTypeV2){rect.left + rect.width, rect.top}

/**
 * Returns position of right-bottom corner as 2D
 *vector.
 */
#define moon_RectUtils_get_rightbottom(	\
	ResTypeV2,							\
	rect								\
)	\
	(ResTypeV2){rect.left + rect.width, rect.top + rect.height}

/**
 * Returns position of center as 2D
 *vector.
 */
#define moon_RectUtils_get_center(	\
	ResTypeV2,						\
	rect							\
)	\
	(ResTypeV2){rect.left + (rect.width * .5f), rect.top + (rect.height * .5f)}


#ifdef __cplusplus
}
#endif


#endif
