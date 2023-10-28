![gp2040-ce-logo](https://github.com/tamanegitaro/GP2040-CE-TT-Edition/assets/28869075/7716dc5b-80c7-4b54-81ac-c99af01d39fa)


<p align="center">
  Multi-Platform Gamepad Firmware for RP2040 customized by tamanegi_taro
</p>

## Compatibility
This firmware is customized by tamanegi_taro. Added compatibility with following mini series:
* Astrocity mini
* Astrocity V mini
* Mega drive mini
* Mega drive 2 mini
* Genesis mini
* Genesis 2 mini
* Egret II mini
* Neogeo mini
* Neogeo international mini
* PC Engine mini
* Core Grafx mini
* TurboGrafx-16 mini	

This project does not include USB descriptors for controllers of mini series so you'll need to supply USB descriptor by yourselves.
Don't worry. I will provide steps to achieve USB descriptors from your controller pads in moment.

In my project, following descriptors need to be modified by you for mini series compatibility:

GP2040-CE\headers\gamepad\descriptors\AstroDescriptors.h
* astro_string_manufacturer[]
* astro_string_product[]
* astro_device_descriptor[]
* astro_configuration_descriptor[]
* astro_report_descriptor[]

GP2040-CE\headers\gamepad\descriptors\EgretDescriptors.h
* egret_string_manufacturer[]
* egret_string_product[]
* egret_device_descriptor[]
* egret _configuration_descriptor[]
* egret _report_descriptor[]

GP2040-CE\headers\gamepad\descriptors\NeogeoDescriptors.h
* neogeo_string_manufacturer[]
* neogeo_string_product[]
* neogeo_device_descriptor[]
* neogeo_configuration_descriptor[]
* neogeo_report_descriptor[]

GP2040-CE\headers\gamepad\descriptors\PCEngineDescriptors.h
* pcengine_string_manufacturer[]
* pcengine_string_product[]
* pcengine_device_descriptor[]
* pcengine_configuration_descriptor[]
* pcengine_report_descriptor[]

## Preparation
You need following gamepads to find missing arrays, respectively.

* Megadrive mini 6 button pad(For Astrocity, Mega drive and Genesis mini support)
* Egret II mini pad(For Egret II mini support)
* Neogeo mini pad(For Neogeo mini support)
* PC Engine mini Turbopad(For PC Engine, CoreGrafx and TG-16 mini support)

![image](https://github.com/tamanegitaro/GP2040-CE-TT-Edition/assets/28869075/b6bda750-4f73-42eb-aacf-001699a5020b)
![image](https://github.com/tamanegitaro/GP2040-CE-TT-Edition/assets/28869075/b0ef4bf9-a1ed-44a6-8580-0fa5d74d1916)
![image](https://github.com/tamanegitaro/GP2040-CE-TT-Edition/assets/28869075/84ffa1a0-f134-4a99-a2f6-13b63f80ce3c)
![image](https://github.com/tamanegitaro/GP2040-CE-TT-Edition/assets/28869075/3d184753-4c50-46d0-a2b7-a3e3ea2dd279)

You also need USB-C extension cable + logic analyzer(USB protocol) for Neogeo mini support.

## Dumping USB Descriptors(Mega Drive, Egret II, PC Engine mini pads)
Here is how you get descriptors for each controllers(For Astrocity/Mega Drive, EgretII and PC Engine. Neogeo is different.).

* (1) Install Wireshark with USB Cap
* (2) Run Wireshark with USB Cap and start recording USB packets
* (3) Plug your controller to your PC
* (4) Stop Wireshark recording
* (5) Scroll up until you find descriptors of your controller

Click on "GET DESCRIPTOR Response DEVICE" then click on "DEVICE DESCRIPTOR". The binary array is highlighted in blue. Use this 18 byte array for xx_device_descriptor[] array.
![image](https://github.com/tamanegitaro/GP2040-CE-TT-Edition/assets/28869075/379b797f-250e-4777-869c-6c9c129839cd)

There is two "GET DESCRIPTOR Response CONFIGURATION". Click on second one. Also click on "CONFIGURATION DESCRIPTOR" to highlight what you will need for xx_configuration_descriptor[] array.
![image](https://github.com/tamanegitaro/GP2040-CE-TT-Edition/assets/28869075/31bfedc5-32a2-4178-995d-095279e8061a)

This configuration descriptor include several "ENDPOINT DESCRIPTOR". Click on it to find byte which corresponds to bInterval byte. There are several ENDPOINT and bInterval in this descriptor. If these are not 0x01, change them to 0x01 for fastest response.
![image](https://github.com/tamanegitaro/GP2040-CE-TT-Edition/assets/28869075/12b90ee0-da40-426a-ad7d-afc9e30ab317)

Click on "GET DESCRIPTOR Response HID Report" and "HID Report". The binary array is highlighted in blue. Use this array for xx_report_descriptor[] array.
![image](https://github.com/tamanegitaro/GP2040-CE-TT-Edition/assets/28869075/a0428280-50de-497d-aa32-16ebb92def4b)

For xx_string_manufacturer[] and xx_string_product[], open game controller configuration in windows settings. You can see gamepad's name.("6B controller" in this example image.). Use this string for both xx_string_manufacturer[] and xx_string_product[].
![image](https://github.com/tamanegitaro/GP2040-CE-TT-Edition/assets/28869075/94952e56-8f3a-46d2-b251-69db97ec84af)

## Neogeo
For Neogeo pad, it is little difficult because you will need logic analyzer. Connect logic analyzer between Neogeo pad and Neogeo mini.

Neogeo mini will apply reset on Neogeo pad and USB descriptor will change.
![image](https://github.com/tamanegitaro/GP2040-CE-TT-Edition/assets/28869075/2414566f-1dc3-400e-87a8-7f5b86af1b84)

You need to dump this second USB descriptor. Find descriptor which starts from 0x12 0x01. This is descriptor for neogeo_device_descriptor[].

Find descriptor which starts from 0x09 0x02. This is configuration descryptor. There are several configuration descriptors. Find longer one and use it as neogeo_configuration_descriptor[].

Next, find string descriptor which start from 0x06 0x03. Search in google for ASCII table and find which character is used for this string descriptor. For example, if value of descriptor is 0x06 0x03 0x42 0x00 0x42 0x00, string will be "BB". Use string you found for both xx_string_manufacturer[] and xx_string_product[]. This is important. Without this string, Neogeo mini will not recognize your fight stick as pad.

Next, find descriptor which start from 0x05 0x01. This descriptor might be divied into multiple transfers if the array was too long. Combine them and used this for neogeo_report_descriptor[].



--------------------------------------------------------------
--------------------------------------------------------------




<p align="center">
  <img src="https://img.shields.io/github/license/OpenStickCommunity/GP2040-CE" />
  <img src="https://img.shields.io/github/actions/workflow/status/OpenStickCommunity/GP2040-CE/cmake.yml" />
  <br />
  <img src="https://img.shields.io/badge/inputlag.science-0.86%20ms-blue" />
  <img src="https://img.shields.io/badge/MiSTer%20latency-0.765%20ms-blue" />
</p>

<p>
  GP2040-CE (Community Edition) is a gamepad firmware for the Raspberry Pi Pico and other boards based on the RP2040 microcontrollers that combines multi-platform compatibility, low latency and a rich feature set to provide endless customization possibilities without sacrificing performance.
</p>

<p>
  GP2040-CE is compatible with PC, PS3 and PS4, Nintendo Switch, Steam Deck, MiSTer and Android.
</p>

## Links

[Downloads](https://gp2040-ce.info/#/download) | [Installation](https://gp2040-ce.info/#/installation) | [Wiring](https://gp2040-ce.info/#/wiring) | [Usage](https://gp2040-ce.info/#/usage) | [FAQ](https://gp2040-ce.info/#/faq) | [GitHub](https://github.com/OpenStickCommunity/GP2040-CE)

Full documentation can be found at <https://gp2040-ce.info>

## Features

* Select from 5 input modes: XInput, Nintendo Switch, PS4, PS3 and Keyboard
* Overclocked polling rate for less than 1 ms of input latency in all modes.
* Multiple SOCD cleaning modes - Up Priority (a.k.a. Stickless), Neutral, and Second Input Priority.
* Left and Right stick emulation via D-pad inputs as well as dedicated toggle switches.
* Dual direction via D-pad + LS/RS.
* Reversed input via a button.
* [Turbo and Turbo LED](https://gp2040-ce.info/#/add-ons/turbo) with selectable speed
* Per-button RGB LED support.
* PWM Player indicator LED support (XInput only).
* Multiple LED profiles support.
* Support for 128x64 monochrome I2C displays - SSD1306, SH1106, and SH1107 compatible.
* Custom startup splash screen and easy image upload via web configuration.
* Support for passive buzzer speaker (3v or 5v).
* [Built-in, embedded web configuration](https://gp2040-ce.info/#/web-configurator) - No download required!

Visit the [GP2040-CE Usage](https://gp2040-ce.info/#/usage) page for more details.

## Performance

Input latency is tested using the methodology outlined at [WydD's inputlag.science website](https://inputlag.science/controller/methodology), using the default 1000 Hz (1 ms) polling rate in the firmware.

| Version | Mode | Poll Rate | Min | Max | Avg | Stdev | % on time | %1f skip | %2f skip |
| - | - | - | - | - | - | - | - | - | - |
| v0.7.0 | All modes (except PS4) | 1 ms | 0.53 ms | 1.36 ms | 0.86 ms | 0.25 ms | 95.91% | 4.09% | 0% |
| v0.7.0 | PS4 Mode | 1 ms | 1.45 ms | 2.14 ms | 1.86 ms | 0.16 ms | 90.26% | 9.74% | 0% |

Full results can be found in the [GP2040-CE Firmware Latency Test Results](https://docs.google.com/spreadsheets/d/1OLmVg04e2q4aY0tqSJuaHtD8YMNCQnP-MzzSTtQLVm4) Google Sheet.

## Support

If you would like to discuss features, issues or anything else related to GP2040-CE please [create an issue](https://github.com/OpenStickCommunity/GP2040-CE/issues/new) or join the [OpenStick GP2040-CE Discord](https://discord.gg/k2pxhke7q8) support channel.

## Contributing

Want to help improve GP2040-CE? There are a bunch of ways to contribute!

### Community Participation

Have an idea for a cool new feature, or just want to discuss some technical details with the developers? Join the [OpenStick GP2040-CE Discord](https://discord.gg/k2pxhke7q8) server to participate in our active and ever-growing community!

### Pull Requests

Pull requests are welcome and encouraged for enhancements, bug fixes and documentation updates.

Please respect the coding style of the file(s) you are working in, and enforce the use of the `.editorconfig` file when present.

## Acknowledgements

* [FeralAI](https://github.com/FeralAI) for building [GP2040](https://github.com/FeralAI/GP2040) and laying the foundation for this community project
* Ha Thach's excellent [TinyUSB library](https://github.com/hathach/tinyusb) examples
* fluffymadness's [tinyusb-xinput](https://github.com/fluffymadness/tinyusb-xinput) sample
* Kevin Boone's [blog post on using RP2040 flash memory as emulated EEPROM](https://kevinboone.me/picoflash.html)
* [bitbank2](https://github.com/bitbank2) for the [OneBitDisplay](https://github.com/bitbank2/OneBitDisplay) and [BitBang_I2C](https://github.com/bitbank2/BitBang_I2C) libraries, which were ported for use with the Pico SDK
* [arntsonl](https://github.com/arntsonl) for the amazing cleanup and feature additions that brought us to v0.5.0
* [alirin222](https://github.com/alirin222) for the awesome turbo code ([@alirin222](https://twitter.com/alirin222) on Twitter)
* [deeebug](https://github.com/deeebug) for improvements to the web-UI and fixing the PS3 home button issue
* [TheTrain](https://github.com/TheTrainGoes/GP2040-Projects) and [Fortinbra](https://github.com/Fortinbra) for helping keep our community chugging along
* [PassingLink](https://github.com/passinglink/passinglink) for the technical details and code for PS4 implementation
* [Youssef Habchi](https://youssef-habchi.com/) for allowing us to purchase a license to use Road Rage font for the project
