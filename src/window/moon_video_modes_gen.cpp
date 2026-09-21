#include "../../headers/window/moon_video_modes_gen.h"


#ifndef _WIN32

#	include <X11/Xlib.h>

#	include <X11/extensions/Xrandr.h>


	static XRROutputInfo*
	get_output_info(
		int* output_index,
		Display* display,
		XRRScreenResources* resources
	);


	struct moon_VideoModesGen {
		int has_next 					= 0;
		int mode_index 					= 0;
		int output_index 				= 0;
		unsigned int bits_per_pixel 	= 0;

		Display* display 				= nullptr;
		XRROutputInfo* output_info 		= nullptr;
		XRRScreenResources* resources 	= nullptr;

		moon_VideoModesGen() {
			display = XOpenDisplay(nullptr);
			if (!display) {
				return;
			}

			Window root = DefaultRootWindow(display);

			resources = XRRGetScreenResourcesCurrent(display, root);
			if (!resources) {
				XCloseDisplay(display);
				display = nullptr;
				return;
			}

			int screen = DefaultScreen(display);

			int count = 0;
			int depth = DefaultDepth(display, screen);
			XPixmapFormatValues* formats = XListPixmapFormats(display, &count);
			if (formats) {
				for (int i = 0; i < count; ++i) {
					if (formats[i].depth == depth) {
						bits_per_pixel = formats[i].bits_per_pixel;
						break;
					}
				}

				XFree(formats);
			} else {
				bits_per_pixel = moon_VideoMode_DefaultBitsPerPixel;
			}

			output_info = get_output_info(
				&output_index,
				display,
				resources
			);

			if (!output_info || output_index >= resources->noutput) {
				has_next = 0;
				return;
			}

			has_next = 1;
		}

		~moon_VideoModesGen() {
			if (output_info) {
				XRRFreeOutputInfo(output_info);
				output_info = nullptr;
			}

			if (resources) {
				XRRFreeScreenResources(resources);
				resources = nullptr;
			}

			if (display) {
				XCloseDisplay(display);
				display = nullptr;
			}
		}
	};


	moon_VideoModesGen*
	moon_VideoModesGen_create() {
		return new moon_VideoModesGen();
	}

	void
	moon_VideoModesGen_destroy(moon_VideoModesGen* self) {
		delete self;
	}

	int
	moon_VideoModesGen_has_next(const moon_VideoModesGen* self) {
		return self->has_next;
	}

	moon_VideoMode
	moon_VideoModesGen_next(moon_VideoModesGen* self) {
		RRMode mode_id = self->output_info->modes[self->mode_index];
		self->mode_index++;
		if (self->mode_index >= self->output_info->nmode) {
			self->output_index++;
			self->mode_index = 0;
		}
		moon_VideoMode res = {0, 0, 0};
		for (int i = 0; i < self->resources->nmode; ++i) {
			const XRRModeInfo& mode = self->resources->modes[i];

			if (mode.id == mode_id) {
				res.width 			= mode.width;
				res.height 			= mode.height;
				res.bits_per_pixel 	= self->bits_per_pixel;
				break;
			}
		}
		XRRFreeOutputInfo(self->output_info);
		self->output_info = get_output_info(
			&self->output_index,
			self->display,
			self->resources
		);
		if (
			!res.width
			|| !self->output_info
			|| self->output_index >= self->resources->noutput
		) {
			self->has_next = 0;
		}
		return res;
	}


	XRROutputInfo*
	get_output_info(
		int* output_index,
		Display* display,
		XRRScreenResources* resources
	) {
		while ((*output_index) < resources->noutput) {
			RROutput output = resources->outputs[*output_index];
			XRROutputInfo* output_info =
				XRRGetOutputInfo(display, resources, output);
			if (!output_info) {
				(*output_index)++;
				continue;
			}
			if (
				output_info->connection != RR_Connected
				|| output_info->crtc == 0
				|| output_info->nmode == 0
			) {
				XRRFreeOutputInfo(output_info);
				(*output_index)++;
				continue;
			}
			return output_info;
		}
		return nullptr;
	}


#else

#	include <windows.h>


	struct moon_VideoModesGen {
		int has_next;
		DWORD index;
		DEVMODEA dev_mode;
	};


	moon_VideoModesGen*
	moon_VideoModesGen_create() {
		moon_VideoModesGen* self = new moon_VideoModesGen();
		self->dev_mode = {};
		self->dev_mode.dmSize = sizeof(self->dev_mode);
		self->index = 0;
		if (EnumDisplaySettingsA(nullptr, self->index, &self->dev_mode)) {
			self->has_next = 1;
		} else {
			self->has_next = 0;
		}
		return self;
	}

	void
	moon_VideoModesGen_destroy(moon_VideoModesGen* self) {
		delete self;
	}

	int
	moon_VideoModesGen_has_next(const moon_VideoModesGen* self) {
		return self->has_next;
	}

	moon_VideoMode
	moon_VideoModesGen_next(moon_VideoModesGen* self) {
		moon_VideoMode res = {0, 0, 0};
		while (
			EnumDisplaySettingsA(nullptr, self->index, &self->dev_mode)
		) {
			if (
				(self->dev_mode.dmFields & DM_PELSWIDTH)
				&& (self->dev_mode.dmFields & DM_PELSHEIGHT)
				&& (self->dev_mode.dmFields & DM_BITSPERPEL)
			) {
				res.width 			= static_cast<unsigned int>(self->dev_mode.dmPelsWidth);
				res.height 			= static_cast<unsigned int>(self->dev_mode.dmPelsHeight);
				res.bits_per_pixel 	= static_cast<unsigned int>(self->dev_mode.dmBitsPerPel);
				self->index++;
				break;
			}
			self->index++;
			self->dev_mode = {};
			self->dev_mode.dmSize = sizeof(self->dev_mode);
		}
		if (
			!res.width
			|| !EnumDisplaySettingsA(nullptr, self->index, &self->dev_mode)
		) {
			self->has_next = 0;
		}
		return res;
	}


#endif
