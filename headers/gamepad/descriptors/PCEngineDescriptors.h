/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: Copyright (c) 2021 Jason Skuby (mytechtoybox.com)
 */

#pragma once

#include <stdint.h>

#define PCENGINE_ENDPOINT_SIZE 64

// HAT report (4 bits)
#define PCENGINE_HAT_UP        0x00
#define PCENGINE_HAT_UPRIGHT   0x01
#define PCENGINE_HAT_RIGHT     0x02
#define PCENGINE_HAT_DOWNRIGHT 0x03
#define PCENGINE_HAT_DOWN      0x04
#define PCENGINE_HAT_DOWNLEFT  0x05
#define PCENGINE_HAT_LEFT      0x06
#define PCENGINE_HAT_UPLEFT    0x07
#define PCENGINE_HAT_NOTHING   0x0f

// Button report (16 bits)
#define PCENGINE_MASK_Y       (1U <<  1)
#define PCENGINE_MASK_X       (1U <<  2)
#define PCENGINE_MASK_MINUS   (1U <<  8)
#define PCENGINE_MASK_PLUS    (1U <<  9)


#define PCENGINE_JOYSTICK_MID  0x7f

typedef struct __attribute((packed, aligned(1)))
{
	uint16_t buttons;
	uint8_t hat;
	uint8_t const0;
	uint8_t const1;
	uint8_t const2;
	uint8_t const3;
	uint8_t const4;
} PCEngineReport;

typedef struct
{
	uint16_t buttons;
	uint8_t hat;
	uint8_t const0;
	uint8_t const1;
	uint8_t const2;
	uint8_t const3;
	uint8_t const4;
} PCEngineOutReport;

static const uint8_t pcengine_string_language[]     = { 0x09, 0x04 };
static const uint8_t pcengine_string_manufacturer[] = "Dummy4";
static const uint8_t pcengine_string_product[]      = "Dummy4";
static const uint8_t pcengine_string_version[]      = "1.0";

static const uint8_t *pcengine_string_descriptors[] __attribute__((unused)) =
{
	pcengine_string_language,
	pcengine_string_manufacturer,
	pcengine_string_product,
	pcengine_string_version
};

static const uint8_t pcengine_device_descriptor[] =
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00
};

static const uint8_t pcengine_hid_descriptor[] =
{
	0x09,        // bLength
	0x21,        // bDescriptorType (HID)
	0x11, 0x01,  // bcdHID 1.11
	0x00,        // bCountryCode
	0x01,        // bNumDescriptors
	0x22,        // bDescriptorType[0] (HID)
	0x56, 0x00   // wDescriptorLength[0] 86
};

static const uint8_t pcengine_configuration_descriptor[] =
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00
};

static const uint8_t pcengine_report_descriptor[] =
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
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
