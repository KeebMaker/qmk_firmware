// Copyright 2026 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum crkbd_layers {
    _BASE,
    _LOWER,
    _RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * BASE
 * ,-----------------------------------------------------.                    ,-----------------------------------------------------.
 * |  ESC |   Q  |   W  |   E  |   R  |   T  |                                 |   Y  |   U  |   I  |   O  |   P  |  DEL |
 * |------+------+------+------+------+------|                                 |------+------+------+------+------+------|
 * |  TAB |   A  |   S  |   D  |F/RSE |   G  |                                 |   H  |   J  |   K  |   L  |   ;  |QUOT/ |
 * |SHFT/T|      |      |      |      |      |                                 |      |      |      |      |      |SHFT/T|
 * |------+------+------+------+------+------|                                 |------+------+------+------+------+------|
 * |  ALT |   Z  |   X  |   C  |   V  |   B  |                                 |   N  |   M  |   ,  |   .  |   /  |   \  |
 * `-----------------------------------------+--------+--------.    ,--------+--------+-----------------------------------------'
 *                          | GUI  |TAB/CTRL|ENT/LOWER|    |SPC/RAISE|BSPC/CTRL| RGUI |
 *                          `-----------------------'    `-----------------------'
 */
[_BASE] = LAYOUT_split_3x6_3(
  KC_ESC,                  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  MT(MOD_LSFT, KC_TAB),    KC_A,    KC_S,    KC_D,    LT(_RAISE, KC_F), KC_G,                          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, MT(MOD_LSFT, KC_QUOT),
  KC_LALT,                 KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
                                       KC_LGUI, MT(MOD_LCTL, KC_TAB), LT(_LOWER, KC_ENT),     LT(_RAISE, KC_SPC), MT(MOD_RCTL, KC_BSPC), KC_RGUI
),
/*
 * LOWER
 * ,-----------------------------------------------------.                    ,-----------------------------------------------------.
 * | BOOT |      |      |      |      |      |                                 |      | HOME |  UP  | END  |   {  |      |
 * |------+------+------+------+------+------|                                 |------+------+------+------+------+------|
 * |SYSRST| CTRL | SHFT | ALT  | GUI  |      |                                 |      | LEFT | DOWN |RIGHT |   }  |      |
 * |------+------+------+------+------+------|                                 |------+------+------+------+------+------|
 * |      |RGBTOG|RGBMOD|RGBVD |RGBVI |      |                                 |      |   (  |   )  |   [  |   ]  |      |
 * `-----------------------------------------+--------+--------.    ,--------+--------+-----------------------------------------'
 *                          | GUI  |      |        |    |        |      | RGUI |
 *                          `-----------------------'    `-----------------------'
 */
[_LOWER] = LAYOUT_split_3x6_3(
  QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                               XXXXXXX, KC_HOME, KC_UP,   KC_END,  KC_LCBR, XXXXXXX,
  EE_CLR,  KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, XXXXXXX,                               XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_RCBR, XXXXXXX,
  XXXXXXX, UG_TOGG, UG_NEXT, UG_VALD, UG_VALU, XXXXXXX,                               XXXXXXX, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, XXXXXXX,
                                       KC_LGUI, _______, _______,      _______, _______, KC_RGUI
),
/*
 * RAISE
 * ,-----------------------------------------------------.                    ,-----------------------------------------------------.
 * |   ~  |   %  |   |  |   &  |   =  |      |                                 |      |   7  |   8  |   9  |  F1  |  F2  |
 * |------+------+------+------+------+------|                                 |------+------+------+------+------+------|
 * |   !  |   @  |   #  |   $  |   >  |      |                                 |      |   4  |   5  |   6  |  F3  |  F4  |
 * |------+------+------+------+------+------|                                 |------+------+------+------+------+------|
 * |   ^  |   *  |   _  |   +  |   -  |      |                                 |      |   1  |   2  |   3  |  F5  |  F6  |
 * `-----------------------------------------+--------+--------.    ,--------+--------+-----------------------------------------'
 *                          | GUI  |      |        |    |  ENT   |   0  |      |
 *                          `-----------------------'    `-----------------------'
 */
[_RAISE] = LAYOUT_split_3x6_3(
  KC_TILD, KC_PERC, KC_PIPE, KC_AMPR, KC_EQL,  XXXXXXX,                               XXXXXXX, KC_7,    KC_8,    KC_9,    KC_F1,   KC_F2,
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_GT,   XXXXXXX,                               XXXXXXX, KC_4,    KC_5,    KC_6,    KC_F3,   KC_F4,
  KC_CIRC, KC_ASTR, KC_UNDS, KC_PLUS, KC_MINS, XXXXXXX,                               XXXXXXX, KC_1,    KC_2,    KC_3,    KC_F5,   KC_F6,
                                       KC_LGUI, _______, _______,      KC_ENT,  KC_0,    _______
)
};

#ifdef OLED_ENABLE
// Bold 5x7 block glyphs for the letters in "KEEBMAKER", scaled up to fill
// the offhand OLED. Each byte is one row, bits 4..0 are columns left..right.
static const uint8_t PROGMEM font_glyph_K[7] = {0x11, 0x12, 0x14, 0x18, 0x14, 0x12, 0x11};
static const uint8_t PROGMEM font_glyph_E[7] = {0x1F, 0x10, 0x10, 0x1E, 0x10, 0x10, 0x1F};
static const uint8_t PROGMEM font_glyph_B[7] = {0x1E, 0x11, 0x11, 0x1E, 0x11, 0x11, 0x1E};
static const uint8_t PROGMEM font_glyph_M[7] = {0x11, 0x1B, 0x15, 0x11, 0x11, 0x11, 0x11};
static const uint8_t PROGMEM font_glyph_A[7] = {0x0E, 0x11, 0x11, 0x1F, 0x11, 0x11, 0x11};
static const uint8_t PROGMEM font_glyph_R[7] = {0x1E, 0x11, 0x11, 0x1E, 0x14, 0x12, 0x11};

static const uint8_t *oled_glyph_for(char c) {
    switch (c) {
        case 'K': return font_glyph_K;
        case 'E': return font_glyph_E;
        case 'B': return font_glyph_B;
        case 'M': return font_glyph_M;
        case 'A': return font_glyph_A;
        case 'R': return font_glyph_R;
        default:  return NULL;
    }
}

#define OLED_GLYPH_COLS 5
#define OLED_GLYPH_ROWS 7
#define OLED_GLYPH_SCALE_Y 4
#define OLED_GLYPH_SCALE_X_BOLD 3   // "KEEB" -- thicker strokes
#define OLED_GLYPH_SCALE_X_NORMAL 2 // "MAKER"
#define OLED_GLYPH_GAP 2
#define OLED_BOLD_LETTER_COUNT 4 // first 4 letters of "KEEBMAKER" are bold

static void oled_draw_glyph(const uint8_t *glyph, uint8_t x0, uint8_t y0, uint8_t scale_x) {
    for (uint8_t row = 0; row < OLED_GLYPH_ROWS; row++) {
        uint8_t bits = pgm_read_byte(&glyph[row]);
        for (uint8_t col = 0; col < OLED_GLYPH_COLS; col++) {
            if (bits & (1 << (OLED_GLYPH_COLS - 1 - col))) {
                for (uint8_t dy = 0; dy < OLED_GLYPH_SCALE_Y; dy++) {
                    for (uint8_t dx = 0; dx < scale_x; dx++) {
                        oled_write_pixel(x0 + col * scale_x + dx, y0 + row * OLED_GLYPH_SCALE_Y + dy, true);
                    }
                }
            }
        }
    }
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        return true;
    }

    // The logo is static, so draw it once instead of re-walking ~2500
    // oled_write_pixel calls every scan -- that CPU load was jittering the
    // split serial link timing and showing up as a flickering column.
    static bool drawn = false;
    if (drawn) {
        return false;
    }
    drawn = true;

    // Clear any stale buffer contents before drawing. (oled_advance_page's
    // per-line clear rounds down to whole characters, leaving a sliver of
    // stale pixels when OLED_DISPLAY_WIDTH isn't a multiple of the font
    // width -- oled_clear() wipes every pixel byte-exactly instead.)
    oled_clear();

    static const char word[]       = "KEEBMAKER";
    const uint8_t      letter_count = sizeof(word) - 1;
    const uint8_t      letter_h     = OLED_GLYPH_ROWS * OLED_GLYPH_SCALE_Y;

    // Sum actual per-letter widths (bold letters are wider) so centering
    // accounts for the mixed weights instead of assuming a fixed cell size.
    uint8_t word_w = OLED_GLYPH_GAP * (letter_count - 1);
    for (uint8_t i = 0; i < letter_count; i++) {
        uint8_t scale_x = (i < OLED_BOLD_LETTER_COUNT) ? OLED_GLYPH_SCALE_X_BOLD : OLED_GLYPH_SCALE_X_NORMAL;
        word_w += OLED_GLYPH_COLS * scale_x;
    }

#define OLED_Y_OFFSET (-2) // max safe nudge without clipping at current letter height
    uint8_t       x = (OLED_DISPLAY_WIDTH - word_w) / 2;
    const uint8_t y = (OLED_DISPLAY_HEIGHT - letter_h) / 2 + OLED_Y_OFFSET;

    for (uint8_t i = 0; i < letter_count; i++) {
        uint8_t        scale_x = (i < OLED_BOLD_LETTER_COUNT) ? OLED_GLYPH_SCALE_X_BOLD : OLED_GLYPH_SCALE_X_NORMAL;
        const uint8_t *glyph   = oled_glyph_for(word[i]);
        if (glyph) {
            oled_draw_glyph(glyph, x, y, scale_x);
        }
        x += OLED_GLYPH_COLS * scale_x + OLED_GLYPH_GAP;
    }

    return false;
}
#endif
