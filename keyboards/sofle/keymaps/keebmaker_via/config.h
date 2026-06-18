#pragma once

// Matches the known-working pin/LED-count config from
// https://github.com/klee813/qmk_firmware/blob/master/keyboards/sofle/keymaps/rgb_default/config.h
// -- our info.json-declared rgblight block (led_count 72/split 36+36) caused
// a reproducible idle hang on real hardware; this explicit count does not.
// (RGBLED_NUM/RGBLED_SPLIT are deprecated aliases in this QMK version and
// don't propagate to every translation unit -- use the modern macro name.)
#define WS2812_DI_PIN D3
#undef RGBLIGHT_LED_COUNT
#define RGBLIGHT_LED_COUNT 70

// Their reference caps RGB Matrix at 150/255 brightness -- likely working
// around a USB power brown-out at full brightness with this many LEDs.
// Cap RGBLIGHT the same way.
#define RGBLIGHT_LIMIT_VAL 150
