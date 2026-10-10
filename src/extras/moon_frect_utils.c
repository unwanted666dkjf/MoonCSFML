#include "../../headers/extras/moon_rectutils.h"

#include "../../headers/extras/moon_frect_utils.h"


moon_Vector2f
moon_FRectUtils_get_lefttop(const moon_FloatRect* rect) {
	return moon_RectUtils_get_lefttop(moon_Vector2f, (*rect));
}

moon_Vector2f
moon_FRectUtils_get_leftbottom(const moon_FloatRect* rect) {
	return moon_RectUtils_get_leftbottom(moon_Vector2f, (*rect));
}

moon_Vector2f
moon_FRectUtils_get_righttop(const moon_FloatRect* rect) {
	return moon_RectUtils_get_righttop(moon_Vector2f, (*rect));
}

moon_Vector2f
moon_FRectUtils_get_rightbottom(const moon_FloatRect* rect) {
	return moon_RectUtils_get_rightbottom(moon_Vector2f, (*rect));
}

moon_Vector2f
moon_FRectUtils_get_center(const moon_FloatRect* rect) {
	return moon_RectUtils_get_center(moon_Vector2f, (*rect));
}
