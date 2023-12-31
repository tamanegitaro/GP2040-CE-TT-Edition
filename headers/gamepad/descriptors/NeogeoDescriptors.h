/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: Copyright (c) 2021 Jason Skuby (mytechtoybox.com)
 */

#pragma once

#include <stdint.h>

#define NEOGEO_ENDPOINT_SIZE 64

// HAT report (4 bits)
#define NEOGEO_HAT_UP        0x00
#define NEOGEO_HAT_UPRIGHT   0x01
#define NEOGEO_HAT_RIGHT     0x02
#define NEOGEO_HAT_DOWNRIGHT 0x03
#define NEOGEO_HAT_DOWN      0x04
#define NEOGEO_HAT_DOWNLEFT  0x05
#define NEOGEO_HAT_LEFT      0x06
#define NEOGEO_HAT_UPLEFT    0x07
#define NEOGEO_HAT_NOTHING   0x0f

// Button report (16 bits)
#define NEOGEO_MASK_Y       (1U <<  0)
#define NEOGEO_MASK_X       (1U <<  1)
#define NEOGEO_MASK_R       (1U <<  3)
#define NEOGEO_MASK_L       (1U <<  4)
#define NEOGEO_MASK_MINUS   (1U <<  11)
#define NEOGEO_MASK_PLUS    (1U <<  10)


#define NEOGEO_JOYSTICK_MID  0x7f

typedef struct __attribute((packed, aligned(1)))
{
	uint16_t buttons;
	uint8_t hat;
	uint8_t const0;
	uint8_t const1;
	uint8_t const2;
	uint8_t const3;
	uint8_t const4;
	uint8_t const5;
	uint8_t const6;
	uint8_t const7;
	uint8_t const8;
	uint8_t const9;
	uint8_t const10;
	uint8_t const11;
	uint8_t const12;
	uint8_t const13;
	uint8_t const14;
	uint8_t const15;
	uint8_t const16;
	uint8_t const17;
} NeogeoReport;

typedef struct
{
	uint16_t buttons;
	uint8_t hat;
	uint8_t const0;
	uint8_t const1;
	uint8_t const2;
	uint8_t const3;
	uint8_t const4;
	uint8_t const5;
	uint8_t const6;
	uint8_t const7;
	uint8_t const8;
	uint8_t const9;
	uint8_t const10;
	uint8_t const11;
	uint8_t const12;
	uint8_t const13;
	uint8_t const14;
	uint8_t const15;
	uint8_t const16;
	uint8_t const17;
} NeogeoOutReport;

static const uint8_t neogeo_string_language[]     = { 0x09, 0x04 };
static const uint8_t neogeo_string_manufacturer[] = "Dummy3";
static const uint8_t neogeo_string_product[]      = "Dummy3";
static const uint8_t neogeo_string_version[]      = "1.0";

static const uint8_t *neogeo_string_descriptors[] __attribute__((unused)) =
{
	neogeo_string_language,
	neogeo_string_manufacturer,
	neogeo_string_product,
	neogeo_string_version
};

static const uint8_t neogeo_device_descriptor[] =
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00
};

static const uint8_t neogeo_hid_descriptor[] =
{
	0x09,        // bLength
	0x21,        // bDescriptorType (HID)
	0x11, 0x01,  // bcdHID 1.11
	0x00,        // bCountryCode
	0x01,        // bNumDescriptors
	0x22,        // bDescriptorType[0] (HID)
	0x56, 0x00   // wDescriptorLength[0] 86
};

static const uint8_t neogeo_configuration_descriptor[] =
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00
};

static const uint8_t neogeo_report_descriptor[] =
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
