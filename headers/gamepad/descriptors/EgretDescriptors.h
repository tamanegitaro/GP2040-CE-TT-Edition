/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: Copyright (c) 2021 Jason Skuby (mytechtoybox.com)
 */

#pragma once

#include <stdint.h>

#define EGRET_ENDPOINT_SIZE 64

// HAT report (4 bits)
#define EGRET_HAT_UP        0x00
#define EGRET_HAT_UPRIGHT   0x01
#define EGRET_HAT_RIGHT     0x02
#define EGRET_HAT_DOWNRIGHT 0x03
#define EGRET_HAT_DOWN      0x04
#define EGRET_HAT_DOWNLEFT  0x05
#define EGRET_HAT_LEFT      0x06
#define EGRET_HAT_UPLEFT    0x07
#define EGRET_HAT_NOTHING   0x08

// Button report (16 bits)
#define EGRET_MASK_Y       (1U <<  8)
#define EGRET_MASK_B       (1U <<  4)
#define EGRET_MASK_A       (1U <<  2)
#define EGRET_MASK_X       (1U <<  3)
#define EGRET_MASK_R       (1U <<  0)
#define EGRET_MASK_ZR      (1U <<  1)
#define EGRET_MASK_MINUS   (1U <<  7)
#define EGRET_MASK_PLUS    (1U <<  6)
#define EGRET_MASK_HOME    (1U <<  9)

// Switch analog sticks only report 8 bits
#define EGRET_JOYSTICK_MIN 0x00
//#define EGRET_JOYSTICK_MID 0x80
#define EGRET_JOYSTICK_MID 0x7F
#define EGRET_JOYSTICK_MAX 0xFF

typedef struct __attribute((packed, aligned(1)))
{
	uint16_t buttons;
	uint8_t lx;
	uint8_t ly;
} EgretReport;

typedef struct
{
	uint16_t buttons;
	uint8_t lx;
	uint8_t ly;
} EgretOutReport;

static const uint8_t egret_string_language[]     = { 0x09, 0x04 };
static const uint8_t egret_string_manufacturer[] = "Dummy2";
static const uint8_t egret_string_product[]      = "Dummy2";
static const uint8_t egret_string_version[]      = "1.0";

static const uint8_t *egret_string_descriptors[] __attribute__((unused)) =
{
	egret_string_language,
	egret_string_manufacturer,
	egret_string_product,
	egret_string_version
};

static const uint8_t egret_device_descriptor[] =
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00
};

static const uint8_t egret_hid_descriptor[] =
{
	0x09,        // bLength
	0x21,        // bDescriptorType (HID)
	0x11, 0x01,  // bcdHID 1.11
	0x00,        // bCountryCode
	0x01,        // bNumDescriptors
	0x22,        // bDescriptorType[0] (HID)
	0x56, 0x00   // wDescriptorLength[0] 86
};

static const uint8_t egret_configuration_descriptor[] =
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00
};

static const uint8_t egret_report_descriptor[] =
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00
};
