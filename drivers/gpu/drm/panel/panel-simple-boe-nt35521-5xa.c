// SPDX-License-Identifier: GPL-2.0-only
// Copyright (c) 2013, The Linux Foundation. All rights reserved.

static const struct drm_display_mode boe_nt35521_5xa_mode = {
	.clock = (720 + 84 + 12 + 84) * (1280 + 20 + 3 + 20) * 60 / 1000,
	.hdisplay = 720,
	.hsync_start = 720 + 84,
	.hsync_end = 720 + 84 + 12,
	.htotal = 720 + 84 + 12 + 84,
	.vdisplay = 1280,
	.vsync_start = 1280 + 20,
	.vsync_end = 1280 + 20 + 3,
	.vtotal = 1280 + 20 + 3 + 20,
	.width_mm = 62,
	.height_mm = 110,
	.type = DRM_MODE_TYPE_DRIVER,
};

static const struct panel_desc_dsi boe_nt35521_5xa = {
	.desc = {
		.modes = &boe_nt35521_5xa_mode,
		.num_modes = 1,
		.bpc = 8,
		.size = {
			.width = 62,
			.height = 110,
		},
		.connector_type = DRM_MODE_CONNECTOR_DSI,
	},
	.flags = MIPI_DSI_MODE_VIDEO | MIPI_DSI_MODE_VIDEO_BURST |
		 MIPI_DSI_MODE_VIDEO_HSE | MIPI_DSI_MODE_NO_EOT_PACKET |
		 MIPI_DSI_CLOCK_NON_CONTINUOUS,
	.format = MIPI_DSI_FMT_RGB888,
	.lanes = 4,
};
