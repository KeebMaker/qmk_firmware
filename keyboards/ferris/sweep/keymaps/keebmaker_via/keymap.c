// Copyright 2026 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum sweep_layers {
    _BASE,
    _LOWER,
    _RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * BASE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |                           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|                           |------+------+------+------+------|
 * | A/SHFT|  S  |   D  |F/RSE |   G  |                           |   H  |   J  |   K  |   L  |QUOT/SHFT|
 * |------+------+------+------+------|                           |------+------+------+------+------|
 * | Z/ALT |  X  |   C  |   V  |   B  |                           |   N  |   M  |   ,  |   .  |   /  |
 * `-----------------------------------------+--------.   ,--------+-----------------------------------------'
 *                       |TAB/CTRL|ENT/LOWER |   |SPC/RAISE|BSPC/CTRL|
 *                       `-----------------'   `-----------------'
 */
[_BASE] = LAYOUT(
  KC_Q,               KC_W,    KC_E,    KC_R,    KC_T,                                  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  LSFT_T(KC_A),       KC_S,    KC_D,    LT(_RAISE, KC_F), KC_G,                          KC_H,    KC_J,    KC_K,    KC_L,    LSFT_T(KC_QUOT),
  LALT_T(KC_Z),       KC_X,    KC_C,    KC_V,    KC_B,                                   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                            LCTL_T(KC_TAB), LT(_LOWER, KC_ENT),     LT(_RAISE, KC_SPC), LCTL_T(KC_BSPC)
),
/*
 * LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ESC |      |      |      |      |                           |      | HOME |  UP  | END  |   {  |
 * |------+------+------+------+------|                           |------+------+------+------+------|
 * | CTRL | SHFT | ALT  | WIN  |      |                           |   ;  | LEFT | DOWN |RIGHT |   }  |
 * |------+------+------+------+------|                           |------+------+------+------+------|
 * | BOOT |SYSRST|      |      |      |                           |   \  |   (  |   )  |   [  |   ]  |
 * `-----------------------------------------+--------.   ,--------+-----------------------------------------'
 *                       |      |      |   |      |      |
 *                       `-----------------'   `-----------------'
 */
[_LOWER] = LAYOUT(
  KC_ESC,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                               XXXXXXX, KC_HOME, KC_UP,   KC_END,  KC_LCBR,
  KC_LCTL,            KC_LSFT, KC_LALT, KC_LGUI, XXXXXXX,                               KC_SCLN, KC_LEFT, KC_DOWN, KC_RGHT, KC_RCBR,
  QK_BOOT,            EE_CLR,  XXXXXXX, XXXXXXX, XXXXXXX,                               KC_BSLS, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC,
                            XXXXXXX, XXXXXXX,                XXXXXXX, XXXXXXX
),
/*
 * RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   ~  |   %  |   |  |   &  |   =  |                           |  F1  |   7  |   8  |   9  |  F4  |
 * |------+------+------+------+------|                           |------+------+------+------+------|
 * |   !  |   @  |   #  |   $  |   >  |                           |  F2  |   4  |   5  |   6  |  F5  |
 * |------+------+------+------+------|                           |------+------+------+------+------|
 * |   ^  |   *  |   _  |   +  |   -  |                           |  F3  |   1  |   2  |   3  |  F6  |
 * `-----------------------------------------+--------.   ,--------+-----------------------------------------'
 *                       |      |      |   |  ENT   |   0  |
 *                       `-----------------'   `-----------------'
 */
[_RAISE] = LAYOUT(
  KC_TILD,            KC_PERC, KC_PIPE, KC_AMPR, KC_EQL,                                 KC_F1,   KC_7,    KC_8,    KC_9,    KC_F4,
  KC_EXLM,            KC_AT,   KC_HASH, KC_DLR,  S(KC_DOT),                              KC_F2,   KC_4,    KC_5,    KC_6,    KC_F5,
  KC_CIRC,            KC_ASTR, KC_UNDS, KC_PLUS, KC_MINS,                                KC_F3,   KC_1,    KC_2,    KC_3,    KC_F6,
                            XXXXXXX, XXXXXXX,                KC_ENT,  KC_0
)
};
