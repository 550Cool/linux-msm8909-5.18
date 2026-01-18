// SPDX-License-Identifier: GPL-2.0-only
// Copyright (c) 2026 FIXME
// Generated with linux-mdss-dsi-panel-driver-generator from vendor device tree:
//   Copyright (c) 2013, The Linux Foundation. All rights reserved. (FIXME)

#include <linux/backlight.h>
#include <linux/delay.h>
#include <linux/gpio/consumer.h>
#include <linux/mod_devicetable.h>
#include <linux/module.h>

#include <video/mipi_display.h>

#include <drm/drm_mipi_dsi.h>
#include <drm/drm_modes.h>
#include <drm/drm_panel.h>
#include <drm/drm_probe_helper.h>

struct boe_nt35521_5xa {
	struct drm_panel panel;
	struct mipi_dsi_device *dsi;
	struct gpio_desc *reset_gpio;
};

static inline
struct boe_nt35521_5xa *to_boe_nt35521_5xa(struct drm_panel *panel)
{
	return container_of(panel, struct boe_nt35521_5xa, panel);
}

static void boe_nt35521_5xa_reset(struct boe_nt35521_5xa *ctx)
{
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	usleep_range(1000, 2000);
	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	msleep(20);
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	msleep(20);
}

static int boe_nt35521_5xa_on(struct boe_nt35521_5xa *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	ctx->dsi->mode_flags |= MIPI_DSI_MODE_LPM;

	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xff,
					 0xaa, 0x55, 0xa5, 0x80);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x6f, 0x11, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf7, 0x20, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x6f, 0x06);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf7, 0xa0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x6f, 0x19);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf7, 0x12);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x6f, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf7, 0x47);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x6f, 0x17);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf4, 0x70);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x6f, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf9, 0x46);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf0,
					 0x55, 0xaa, 0x52, 0x08, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb1, 0x60);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbd,
					 0x01, 0xa0, 0x10, 0x10, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb8,
					 0x01, 0x02, 0x0c, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbb, 0x11, 0x11);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbc, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb6, 0x04);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc8, 0x80);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcc,
					 0x40, 0x36, 0xba, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x50, 0xff, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd1,
					 0x00, 0x02, 0x04, 0x06, 0x08, 0x0c,
					 0x0e, 0x10, 0x10, 0x10, 0x0e, 0x0c,
					 0x08, 0x06, 0x02, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd7,
					 0x24, 0x23, 0x22, 0x21, 0x00, 0x00,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd8,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00, 0x00, 0x23, 0x22,
					 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf0,
					 0x55, 0xaa, 0x52, 0x08, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb0, 0x09, 0x09);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb1, 0x09, 0x09);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbc, 0x80, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbd, 0x80, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xca, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc0, 0x0c);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb5, 0x03, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb3, 0x19, 0x19);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb4, 0x19, 0x19);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb9, 0x26, 0x26);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xba, 0x24, 0x24);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf0,
					 0x55, 0xaa, 0x52, 0x08, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xee, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb0,
					 0x00, 0x43, 0x00, 0x4a, 0x00, 0x58,
					 0x00, 0x66, 0x00, 0x73, 0x00, 0x89,
					 0x00, 0x9f, 0x00, 0xc4);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb1,
					 0x00, 0xe4, 0x01, 0x1b, 0x01, 0x48,
					 0x01, 0x94, 0x01, 0xd3, 0x01, 0xd5,
					 0x02, 0x11, 0x02, 0x55);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb2,
					 0x02, 0x7f, 0x02, 0xbe, 0x02, 0xe6,
					 0x03, 0x1f, 0x03, 0x44, 0x03, 0x75,
					 0x03, 0x93, 0x03, 0xbc);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb3,
					 0x03, 0xea, 0x03, 0xff);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc0, 0x04);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf0,
					 0x55, 0xaa, 0x52, 0x08, 0x06);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb0, 0x10, 0x12);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb1, 0x14, 0x16);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb2, 0x00, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb3, 0x31, 0x31);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb4, 0x31, 0x34);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb5, 0x34, 0x34);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb6, 0x34, 0x31);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb7, 0x31, 0x31);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb8, 0x31, 0x31);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb9, 0x2d, 0x2e);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xba, 0x2e, 0x2d);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbb, 0x31, 0x31);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbc, 0x31, 0x31);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbd, 0x31, 0x34);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbf, 0x34, 0x31);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc0, 0x31, 0x31);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc1, 0x03, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc2, 0x17, 0x15);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc3, 0x13, 0x11);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe5, 0x31, 0x31);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc4, 0x17, 0x15);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0x13, 0x11);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc6, 0x03, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc7, 0x31, 0x31);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc8, 0x31, 0x34);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc9, 0x34, 0x34);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xca, 0x34, 0x31);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb, 0x31, 0x31);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcc, 0x31, 0x31);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcd, 0x2e, 0x2d);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xce, 0x2d, 0x2e);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcf, 0x31, 0x31);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd0, 0x31, 0x31);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd1, 0x31, 0x34);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd2, 0x34, 0x34);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd3, 0x34, 0x31);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd4, 0x31, 0x31);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd5, 0x00, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd6, 0x10, 0x12);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd7, 0x14, 0x16);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe6, 0x32, 0x32);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd8,
					 0x00, 0x00, 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd9,
					 0x00, 0x00, 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe7, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf0,
					 0x55, 0xaa, 0x52, 0x08, 0x05);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xed, 0x30);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb0, 0x17, 0x06);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb8, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc0, 0x0d);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc1, 0x0b);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc2, 0x23);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc3, 0x40);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc4, 0x84);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0x82);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc6, 0x82);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc7, 0x80);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc8, 0x0b, 0x30);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc9, 0x05, 0x10);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xca, 0x01, 0x10);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb, 0x01, 0x10);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd1,
					 0x03, 0x05, 0x05, 0x07, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd2,
					 0x03, 0x05, 0x09, 0x03, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd3,
					 0x00, 0x00, 0x6a, 0x07, 0x10);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd4,
					 0x30, 0x00, 0x6a, 0x07, 0x10);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf0,
					 0x55, 0xaa, 0x52, 0x08, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb0, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb1, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb2,
					 0x05, 0x00, 0x0a, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb3,
					 0x05, 0x00, 0x0a, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb4,
					 0x05, 0x00, 0x0a, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb5,
					 0x05, 0x00, 0x0a, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb6,
					 0x02, 0x00, 0x0a, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb7,
					 0x02, 0x00, 0x0a, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb8,
					 0x02, 0x00, 0x0a, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb9,
					 0x02, 0x00, 0x0a, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xba,
					 0x53, 0x00, 0x0a, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbb,
					 0x53, 0x00, 0x0a, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbc,
					 0x53, 0x00, 0x0a, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbd,
					 0x53, 0x00, 0x0a, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc4, 0x60);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0x40);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc6, 0x64);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x6f, 0x11);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf3, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf0,
					 0x55, 0xaa, 0x52, 0x08, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe6,
					 0xff, 0xff, 0xfb, 0xfb);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd9, 0x02, 0x09);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_WRITE_POWER_SAVE, 0x81);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_WRITE_CONTROL_DISPLAY,
				     0x24);
	mipi_dsi_dcs_set_display_brightness_multi(&dsi_ctx, 0x0000);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_SET_CABC_MIN_BRIGHTNESS,
				     0x28);
	mipi_dsi_dcs_exit_sleep_mode_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 120);
	mipi_dsi_dcs_set_display_on_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 22);

	return dsi_ctx.accum_err;
}

static int boe_nt35521_5xa_off(struct boe_nt35521_5xa *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	ctx->dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

	mipi_dsi_dcs_set_display_off_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 50);
	mipi_dsi_dcs_enter_sleep_mode_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 120);

	return dsi_ctx.accum_err;
}

static int boe_nt35521_5xa_prepare(struct drm_panel *panel)
{
	struct boe_nt35521_5xa *ctx = to_boe_nt35521_5xa(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	boe_nt35521_5xa_reset(ctx);

	ret = boe_nt35521_5xa_on(ctx);
	if (ret < 0) {
		dev_err(dev, "Failed to initialize panel: %d\n", ret);
		gpiod_set_value_cansleep(ctx->reset_gpio, 1);
		return ret;
	}

	return 0;
}

static int boe_nt35521_5xa_unprepare(struct drm_panel *panel)
{
	struct boe_nt35521_5xa *ctx = to_boe_nt35521_5xa(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	ret = boe_nt35521_5xa_off(ctx);
	if (ret < 0)
		dev_err(dev, "Failed to un-initialize panel: %d\n", ret);

	gpiod_set_value_cansleep(ctx->reset_gpio, 1);

	return 0;
}

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

static int boe_nt35521_5xa_get_modes(struct drm_panel *panel,
				     struct drm_connector *connector)
{
	return drm_connector_helper_get_modes_fixed(connector, &boe_nt35521_5xa_mode);
}

static const struct drm_panel_funcs boe_nt35521_5xa_panel_funcs = {
	.prepare = boe_nt35521_5xa_prepare,
	.unprepare = boe_nt35521_5xa_unprepare,
	.get_modes = boe_nt35521_5xa_get_modes,
};

static int boe_nt35521_5xa_bl_update_status(struct backlight_device *bl)
{
	struct mipi_dsi_device *dsi = bl_get_data(bl);
	u16 brightness = backlight_get_brightness(bl);
	int ret;

	dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

	ret = mipi_dsi_dcs_set_display_brightness(dsi, brightness);
	if (ret < 0)
		return ret;

	dsi->mode_flags |= MIPI_DSI_MODE_LPM;

	return 0;
}

// TODO: Check if /sys/class/backlight/.../actual_brightness actually returns
// correct values. If not, remove this function.
static int boe_nt35521_5xa_bl_get_brightness(struct backlight_device *bl)
{
	struct mipi_dsi_device *dsi = bl_get_data(bl);
	u16 brightness;
	int ret;

	dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

	ret = mipi_dsi_dcs_get_display_brightness(dsi, &brightness);
	if (ret < 0)
		return ret;

	dsi->mode_flags |= MIPI_DSI_MODE_LPM;

	return brightness & 0xff;
}

static const struct backlight_ops boe_nt35521_5xa_bl_ops = {
	.update_status = boe_nt35521_5xa_bl_update_status,
	.get_brightness = boe_nt35521_5xa_bl_get_brightness,
};

static struct backlight_device *
boe_nt35521_5xa_create_backlight(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	const struct backlight_properties props = {
		.type = BACKLIGHT_RAW,
		.brightness = 250,
		.max_brightness = 250,
	};

	return devm_backlight_device_register(dev, dev_name(dev), dev, dsi,
					      &boe_nt35521_5xa_bl_ops, &props);
}

static int boe_nt35521_5xa_probe(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	struct boe_nt35521_5xa *ctx;
	int ret;

	ctx = devm_drm_panel_alloc(dev, struct boe_nt35521_5xa, panel,
				   &boe_nt35521_5xa_panel_funcs,
				   DRM_MODE_CONNECTOR_DSI);
	if (IS_ERR(ctx))
		return PTR_ERR(ctx);

	ctx->reset_gpio = devm_gpiod_get(dev, "reset", GPIOD_OUT_HIGH);
	if (IS_ERR(ctx->reset_gpio))
		return dev_err_probe(dev, PTR_ERR(ctx->reset_gpio),
				     "Failed to get reset-gpios\n");

	ctx->dsi = dsi;
	mipi_dsi_set_drvdata(dsi, ctx);

	dsi->lanes = 4;
	dsi->format = MIPI_DSI_FMT_RGB888;
	dsi->mode_flags = MIPI_DSI_MODE_VIDEO | MIPI_DSI_MODE_VIDEO_BURST |
			  MIPI_DSI_MODE_VIDEO_HSE | MIPI_DSI_MODE_NO_EOT_PACKET |
			  MIPI_DSI_CLOCK_NON_CONTINUOUS;

	ctx->panel.prepare_prev_first = true;

	ctx->panel.backlight = boe_nt35521_5xa_create_backlight(dsi);
	if (IS_ERR(ctx->panel.backlight))
		return dev_err_probe(dev, PTR_ERR(ctx->panel.backlight),
				     "Failed to create backlight\n");

	drm_panel_add(&ctx->panel);

	ret = mipi_dsi_attach(dsi);
	if (ret < 0) {
		drm_panel_remove(&ctx->panel);
		return dev_err_probe(dev, ret, "Failed to attach to DSI host\n");
	}

	return 0;
}

static void boe_nt35521_5xa_remove(struct mipi_dsi_device *dsi)
{
	struct boe_nt35521_5xa *ctx = mipi_dsi_get_drvdata(dsi);
	int ret;

	ret = mipi_dsi_detach(dsi);
	if (ret < 0)
		dev_err(&dsi->dev, "Failed to detach from DSI host: %d\n", ret);

	drm_panel_remove(&ctx->panel);
}

static const struct of_device_id boe_nt35521_5xa_of_match[] = {
	{ .compatible = "boe,nt35521-5xa" }, // FIXME
	{ /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, boe_nt35521_5xa_of_match);

static struct mipi_dsi_driver boe_nt35521_5xa_driver = {
	.probe = boe_nt35521_5xa_probe,
	.remove = boe_nt35521_5xa_remove,
	.driver = {
		.name = "panel-boe-nt35521-5xa",
		.of_match_table = boe_nt35521_5xa_of_match,
	},
};
module_mipi_dsi_driver(boe_nt35521_5xa_driver);

MODULE_AUTHOR("linux-mdss-dsi-panel-driver-generator <fix@me>"); // FIXME
MODULE_DESCRIPTION("DRM driver for BOE_NT35521_5_720P_VIDEO");
MODULE_LICENSE("GPL");
