/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: Copyright (c) 2021 Jason Skuby (mytechtoybox.com)
 */

#pragma once

#include <stdint.h>

#define ASTRO_ENDPOINT_SIZE 64

// HAT report (4 bits)
#define ASTRO_HAT_UP        0x00
#define ASTRO_HAT_UPRIGHT   0x01
#define ASTRO_HAT_RIGHT     0x02
#define ASTRO_HAT_DOWNRIGHT 0x03
#define ASTRO_HAT_DOWN      0x04
#define ASTRO_HAT_DOWNLEFT  0x05
#define ASTRO_HAT_LEFT      0x06
#define ASTRO_HAT_UPLEFT    0x07
#define ASTRO_HAT_NOTHING   0x08

// Button report (16 bits)
#define ASTRO_MASK_Y       (1U <<  7)
#define ASTRO_MASK_B       (1U <<  6)
#define ASTRO_MASK_A       (1U <<  5)
#define ASTRO_MASK_X       (1U <<  4)
#define ASTRO_MASK_R       (1U <<  8)
#define ASTRO_MASK_ZR      (1U <<  9)
#define ASTRO_MASK_MINUS   (1U <<  13)
#define ASTRO_MASK_PLUS    (1U <<  12)

// Switch analog sticks only report 8 bits
#define ASTRO_JOYSTICK_MIN 0x00
//#define ASTRO_JOYSTICK_MID 0x80
#define ASTRO_JOYSTICK_MID 0x7F
#define ASTRO_JOYSTICK_MAX 0xFF

typedef struct __attribute((packed, aligned(1)))
{
	uint8_t const0;
	uint8_t const1;
	uint8_t const2;
	uint8_t lx;
	uint8_t ly;
	uint16_t buttons;
	uint8_t const3;
} AstroReport;

typedef struct
{
	uint8_t const0;
	uint8_t const1;
	uint8_t const2;
	uint8_t lx;
	uint8_t ly;
	uint16_t buttons;
	uint8_t const3;
} AstroOutReport;

static const uint8_t astro_string_language[]     = { 0x09, 0x04 };
static const uint8_t astro_string_manufacturer[] = "Dummy1";
static const uint8_t astro_string_product[]      = "Dummy1";
static const uint8_t astro_string_version[]      = "1.0";

static const uint8_t *astro_string_descriptors[] __attribute__((unused)) =
{
	astro_string_language,
	astro_string_manufacturer,
	astro_string_product,
	astro_string_version
};

static const uint8_t astro_device_descriptor[] =
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00
};

static const uint8_t astro_hid_descriptor[] =
{
	0x09,        // bLength
	0x21,        // bDescriptorType (HID)
	0x11, 0x01,  // bcdHID 1.11
	0x00,        // bCountryCode
	0x01,        // bNumDescriptors
	0x22,        // bDescriptorType[0] (HID)
	0x56, 0x00   // wDescriptorLength[0] 86
};

static const uint8_t astro_configuration_descriptor[] =
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00
};

static const uint8_t astro_report_descriptor[] =
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
	0x00, 0x00, 0x00, 0x00, 0x00
};
