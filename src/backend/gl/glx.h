// SPDX-License-Identifier: MPL-2.0
// Copyright (c) Yuxuan Shui <yshuiv7@gmail.com>
#pragma once
#include <X11/Xlib.h>
#include <epoxy/glx.h>
#include <stdbool.h>
#include <xcb/render.h>
#include <xcb/xcb.h>

#include "compiler.h"
#include "log.h"
#include "utils.h"
#include "x.h"

struct glx_fbconfig_info {
	GLXFBConfig cfg;
	int texture_tgts;
	int texture_fmt;
	int y_inverted;
};

/// The search criteria for glx_find_fbconfig
struct glx_fbconfig_criteria {
	/// Bit width of the red component
	int red_size;
	/// Bit width of the green component
	int green_size;
	/// Bit width of the blue component
	int blue_size;
	/// Bit width of the alpha component
	int alpha_size;
	/// The depth of X visual
	int visual_depth;
};

struct glx_fbconfig_info *glx_find_fbconfig(struct x_connection *, struct xvisual_info);

struct glxext_info {
	bool initialized;
	bool has_GLX_SGI_video_sync;
	bool has_GLX_SGI_swap_control;
	bool has_GLX_OML_sync_control;
	bool has_GLX_MESA_swap_control;
	bool has_GLX_EXT_swap_control;
	bool has_GLX_EXT_texture_from_pixmap;
	bool has_GLX_ARB_create_context;
	bool has_GLX_EXT_buffer_age;
	bool has_GLX_MESA_query_renderer;
	bool has_GLX_ARB_create_context_robustness;
};

extern struct glxext_info glxext;

void glxext_init(Display *, int screen);
