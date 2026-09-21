// In C we don't have access modifiers anyway.

#define private public

#define protected public


#include <SFML/System/String.hpp>


#include <SFML/Window/VideoMode.hpp>



#include "../../headers/window/Converters.hpp"

#include "../../headers/window/EventStruct.hpp"


#include "../../headers/graphics/moon_render_window.h"

#include "../../headers/graphics/Converters.hpp"

#include "../../headers/graphics/ImageStruct.hpp"

#include "../../headers/graphics/RenderWindowStruct.hpp"


moon_RenderWindow*
moon_RenderWindow_default() {
	return new moon_RenderWindow();
}

moon_RenderWindow*
moon_RenderWindow_createA(
	unsigned int width,
	unsigned int height,
	unsigned int bits_per_pixel,
	const char* title,
	unsigned int style
) {
	return new moon_RenderWindow(
		width, height, bits_per_pixel,
		title, style
	);
}

moon_RenderWindow*
moon_RenderWindow_createA_ex(
	unsigned int width,
	unsigned int height,
	unsigned int bits_per_pixel,
	const char* title,
	unsigned int style,
	const moon_ContextSettings* settings
) {
	return new moon_RenderWindow(
		width, height, bits_per_pixel,
		title, style, settings
	);
}

moon_RenderWindow*
moon_RenderWindow_createW(
	unsigned int width,
	unsigned int height,
	unsigned int bits_per_pixel,
	const wchar_t* title,
	unsigned int style
) {
	return new moon_RenderWindow(
		width, height, bits_per_pixel,
		title, style
	);
}

moon_RenderWindow*
moon_RenderWindow_createW_ex(
	unsigned int width,
	unsigned int height,
	unsigned int bits_per_pixel,
	const wchar_t* title,
	unsigned int style,
	const moon_ContextSettings* settings
) {
	return new moon_RenderWindow(
		width, height, bits_per_pixel,
		title, style, settings
	);
}

void
moon_RenderWindow_destroy(moon_RenderWindow* self) {
	delete self;
}

void
moon_RenderWindow_close(moon_RenderWindow* self) {
	self->close();
}

int
moon_RenderWindow_is_open(const moon_RenderWindow* self) {
	return self->isOpen();
}

int
moon_RenderWindow_poll_event(
	moon_RenderWindow* self,
	moon_Event* event
) {
	return self->pollEvent(
		*(static_cast<sf::Event*>(event))
	);
}

int
moon_RenderWindow_wait_event(
	moon_RenderWindow* self,
	moon_Event* event
) {
	return self->waitEvent(
		*(static_cast<sf::Event*>(event))
	);
}

moon_Vector2i
moon_RenderWindow_get_position(const moon_RenderWindow* self) {
	sf::Vector2i pos = self->getPosition();
	return {pos.x, pos.y};
}

void
moon_RenderWindow_set_position(
	moon_RenderWindow* self,
	int x, int y
) {
	self->setPosition(sf::Vector2i(x, y));
}

moon_Vector2u
moon_RenderWindow_get_size(const moon_RenderWindow* self) {
	sf::Vector2u size = self->getSize();
	return {size.x, size.y};
}

void
moon_RenderWindow_set_size(
	moon_RenderWindow* self,
	unsigned int x, unsigned int y
) {
	self->setSize(sf::Vector2u(x, y));
}

void
moon_RenderWindow_set_titleA(
	moon_RenderWindow* self,
	const char* title
) {
	self->setTitle(sf::String(title));
}

void
moon_RenderWindow_set_titleW(
	moon_RenderWindow* self,
	const wchar_t* title
) {
	self->setTitle(sf::String(title));
}

void
moon_RenderWindow_set_icon(
	moon_RenderWindow* self,
	unsigned int icon_width,
	unsigned int icon_height,
	const moon_Image* icon
) {
	self->setIcon(icon_width, icon_height, icon->getPixelsPtr());
}

void
moon_RenderWindow_set_visible(
	moon_RenderWindow* self,
	int is_visible
) {
	self->setVisible(is_visible);
}

void
moon_RenderWindow_set_mouse_cursor_visible(
	moon_RenderWindow* self,
	int is_mvisible
) {
	self->setMouseCursorVisible(is_mvisible);
}

void
moon_RenderWindow_set_mouse_cursor_grabbed(
	moon_RenderWindow* self,
	int is_mgrabbed
) {
	self->setMouseCursorGrabbed(is_mgrabbed);
}

void
moon_RenderWindow_set_key_repeat_enabled(
	moon_RenderWindow* self,
	int is_krenabled
) {
	self->setKeyRepeatEnabled(is_krenabled);
}

void
moon_RenderWindow_request_focus(moon_RenderWindow* self) {
	self->requestFocus();
}

int
moon_RenderWindow_has_focus(const moon_RenderWindow* self) {
	return self->hasFocus();
}

moon_WindowHandle
moon_RenderWindow_get_system_handle(const moon_RenderWindow* self) {
	return self->getSystemHandle();
}

moon_ContextSettings
moon_RenderWindow_get_settings(const moon_RenderWindow* self) {
	return context_settings_sf_to_moon(self->getSettings());
}

void
moon_RenderWindow_set_vertical_sync_enabled(
	moon_RenderWindow* self,
	int is_vsenabled
) {
	self->setVerticalSyncEnabled(is_vsenabled);
}

void
moon_RenderWindow_set_framerate_limit(
	moon_RenderWindow* self,
	unsigned int limit
) {
	self->setFramerateLimit(limit);
}

int
moon_RenderWindow_set_active(
	moon_RenderWindow* self,
	int is_oglactive
) {
	return self->setActive(is_oglactive);
}

void
moon_RenderWindow_display(moon_RenderWindow* self) {
	self->display();
}

void
moon_RenderWindow_clear(
	moon_RenderWindow* self,
	const moon_Color* color
) {
	self->clear(color_moon_to_sf(*color));
}

void
moon_RenderWindow_set_view(
	moon_RenderWindow* self,
	const moon_View* view
) {
	self->setView(view_moon_to_sf(*view));
}

moon_View
moon_RenderWindow_get_view(const moon_RenderWindow* self) {
	return view_sf_to_moon(self->getView());
}

moon_View
moon_RenderWindow_get_default_view(const moon_RenderWindow* self) {
	return view_sf_to_moon(self->getDefaultView());
}

moon_IntRect
moon_RenderWindow_get_viewport(
	const moon_RenderWindow* self,
	const moon_View* view
) {
	const moon_FloatRect* viewport = &view->viewport;
	sf::Vector2u size = self->getSize();
	return {
		static_cast<int>(0.5f + size.x  * viewport->left),
		static_cast<int>(0.5f + size.y 	* viewport->top),
		static_cast<int>(0.5f + size.x  * viewport->width),
		static_cast<int>(0.5f + size.y 	* viewport->height)
	};
}

moon_Vector2f
moon_RenderWindow_map_pixel_to_coords(
	const moon_RenderWindow* self,
	int x, int y
) {
	sf::Vector2f res = self->mapPixelToCoords(sf::Vector2i(x, y));
	return {res.x, res.y};
}

moon_Vector2f
moon_RenderWindow_map_pixel_to_coords_ex(
	const moon_RenderWindow* self,
	int x, int y,
	const moon_View* view,
	const moon_Transform* view_inversed_transform
) {
	const moon_IntRect viewport = moon_RenderWindow_get_viewport(self, view);
	return moon_Transform_transform_point(
		view_inversed_transform,
		-1.f + 2.f
			* (static_cast<float>(x) - viewport.left) / viewport.width,
		1.f - 2.f
			* (static_cast<float>(y) - viewport.top)  / viewport.height
	);
}

moon_Vector2i
moon_RenderWindow_map_coords_to_pixel(
	const moon_RenderWindow* self,
	float x, float y
) {
	sf::Vector2i res = self->mapCoordsToPixel(sf::Vector2f(x, y));
	return {res.x, res.y};
}

moon_Vector2i
moon_RenderWindow_map_coords_to_pixel_ex(
	const moon_RenderWindow* self,
	float x, float y,
	const moon_View* view,
	const moon_Transform* view_transform
) {
	const moon_IntRect viewport = moon_RenderWindow_get_viewport(self, view);
	moon_Vector2f normalized 	= moon_Transform_transform_point(view_transform, x, y);
	return {
		static_cast<int>(( normalized.x + 1.f) / 2.f * viewport.width  + viewport.left),
		static_cast<int>((-normalized.y + 1.f) / 2.f * viewport.height + viewport.top)
	};
}

int
moon_RenderWindow_is_srgb(const moon_RenderWindow* self) {
	return self->isSrgb();
}

void
moon_RenderWindow_push_gl_states(moon_RenderWindow* self) {
	self->pushGLStates();
}

void
moon_RenderWindow_pop_gl_states(moon_RenderWindow* self) {
	self->popGLStates();
}

void
moon_RenderWindow_reset_gl_states(moon_RenderWindow* self) {
	self->resetGLStates();
}

void
moon_RenderWindow_move(
	moon_RenderWindow* self,
	int dx, int dy
) {
	sf::Vector2i pos = self->getPosition();
	self->setPosition(sf::Vector2i(pos.x + dx, pos.y + dy));
}


moon_RenderWindow::moon_RenderWindow() : sf::RenderWindow() {
	//
}

moon_RenderWindow::moon_RenderWindow(
	unsigned int width,
	unsigned int height,
	unsigned int bits_per_pixel,
	const char* title,
	unsigned int style
) : sf::RenderWindow(
		sf::VideoMode(width, height, bits_per_pixel),
		sf::String(title),
		style
) {
	//
}

moon_RenderWindow::moon_RenderWindow(
	unsigned int width,
	unsigned int height,
	unsigned int bits_per_pixel,
	const char* title,
	unsigned int style,
	const moon_ContextSettings* settings
) : sf::RenderWindow(
		sf::VideoMode(width, height, bits_per_pixel),
		sf::String(title),
		style,
		context_settings_moon_to_sf(*settings)
) {
	//
}

moon_RenderWindow::moon_RenderWindow(
	unsigned int width,
	unsigned int height,
	unsigned int bits_per_pixel,
	const wchar_t* title,
	unsigned int style
) : sf::RenderWindow(
		sf::VideoMode(width, height, bits_per_pixel),
		sf::String(title),
		style
) {
	//
}

moon_RenderWindow::moon_RenderWindow(
	unsigned int width,
	unsigned int height,
	unsigned int bits_per_pixel,
	const wchar_t* title,
	unsigned int style,
	const moon_ContextSettings* settings
) : sf::RenderWindow(
		sf::VideoMode(width, height, bits_per_pixel),
		sf::String(title),
		style,
		context_settings_moon_to_sf(*settings)
) {
	//
}


#undef private

#undef protected
