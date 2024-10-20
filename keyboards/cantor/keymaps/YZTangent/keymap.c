// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H

enum layer_names {
  _BL,
  _L2,
  _L3,
  _L5,
  _G1,
  _G2,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Esc│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │Bsp│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Tab│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │Ent│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │Del│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │Sft├───┐           ┌───┤GUI│
      *               └───┤_L2├───┐   ┌───┤   ├───┘
      *                   └───┤Alt│   │_L3├───┘
      *                       └───┘   └───┘
      */
    [_BL] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_DEL,
                                            KC_LSFT, MO(_L2), KC_LALT,          MO(_L3), KC_SPC, KC_LGUI
    ),

     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Esc│   │ 9 │ 8 │ 7 │ - │       │ \ │ ( │ ) │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Tab│   │ 6 │ 5 │ 4 │ = │       │ 0 │ { │ } │   │ : │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│   │ 3 │ 2 │ 1 │ ` │       │ | │ [ │ ] │   │   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │Sft├───┐           ┌───┤GUI│
      *               └───┤_L2├───┐   ┌───┤   ├───┘
      *                   └───┤Alt│   │_L5├───┘
      *                       └───┘   └───┘
      */
    [_L2] = LAYOUT_split_3x6_3(
        _______,  XXXXXXX,    KC_9,    KC_8,    KC_7,    KC_MINS,                            KC_BSLS,    S(KC_9),     S(KC_0),      XXXXXXX,  XXXXXXX,     _______,
        _______,  XXXXXXX,    KC_6,    KC_5,    KC_4,    KC_EQL,                             KC_0,       S(KC_LBRC),  S(KC_RBRC),   XXXXXXX,  S(KC_SCLN),  _______,
        _______,  XXXXXXX,    KC_3,    KC_2,    KC_1,    KC_GRV,                             KC_PIPE,    KC_LBRC,     KC_RBRC,      XXXXXXX,  XXXXXXX,     _______,
                                            _______, _______, _______,          MO(_L5), _______, _______
    ),

     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Esc│   │ ( │ * │ & │ _ │       │ \ │'^'│ ^ │ $ │   │Bsp│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Tab│   │ # │ @ │ ! │ + │       │ 0 │ < │ v │ > │ : │Ent│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│   │ ^ │ % │ $ │ ~ │       │ | │ ' │ " │   │   │PRS│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │Sft├───┐           ┌───┤GUI│
      *               └───┤_L2├───┐   ┌───┤   ├───┘
      *                   └───┤Alt│   │_L3├───┘
      *                       └───┘   └───┘
      */
    [_L3] = LAYOUT_split_3x6_3(
        _______, XXXXXXX,    S(KC_9),    S(KC_8),    S(KC_7),    S(KC_MINS),                      KC_BSLS,   S(KC_6),    KC_UP,    S(KC_4),   S(KC_5),     _______,
        _______, XXXXXXX,    S(KC_3),    S(KC_2),    S(KC_1),    S(KC_EQL),                       KC_0,      KC_LEFT,    KC_DOWN,  KC_RIGHT,  S(KC_SCLN),  _______,
        _______, XXXXXXX,    S(KC_6),    S(KC_5),    S(KC_4),    S(KC_GRV),                       KC_PIPE,   KC_QUOT, S(KC_QUOT),  XXXXXXX,   XXXXXXX,     KC_PSCR,
                                            _______, _______, _______,          MO(_L3), _______, _______
    ),

     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Esc│   │   │SCH│VLU│BRU│       │   │   │   │   │   │   │   MOUSE CONTROL LAYER
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Tab│   │BRB│BRF│VLD│BRD│       │   │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Alt│PWR│WAK│SLP│MUT│   │       │   │   │   │   │   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │Sft├───┐           ┌───┤GAM│
      *               └───┤_L2├───┐   ┌───┤   ├───┘
      *                   └───┤Alt│   │_L5├───┘
      *                       └───┘   └───┘
      */
    [_L5] = LAYOUT_split_3x6_3(
        _______, XXXXXXX, XXXXXXX, KC_WSCH,    KC_VOLU,    KC_BRIU,                            KC_WH_U,   KC_BTN1,  KC_MS_U, KC_BTN2,  XXXXXXX, XXXXXXX,
        _______, XXXXXXX, KC_WBAK, KC_WFWD,    KC_VOLD,    KC_BRID,                            KC_WH_D,   KC_MS_L,  KC_MS_D, KC_MS_R,  XXXXXXX, XXXXXXX,
        _______, KC_PWR,  KC_WAKE, KC_SLEP,    KC_MUTE,    XXXXXXX,                            KC_WH_L,   KC_WH_R,  KC_BTN3, KC_BTN4,  XXXXXXX, XXXXXXX,
                                            _______, _______, _______,          MO(_L5), _______, TG(_G1)
    ),

      /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Esc│ T │ Q │ W │ E │ R │       │ Y │ U │ I │ O │ P │Bsp│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Tab│Sft│ A │ S │ D │ F │       │ H │ J │ K │ L │ ; │Ent│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │ C │Ctl│ Z │ X │ V │ G │       │ B │ N │ M │ , │ . │Del│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │Alt├───┐           ┌───┤_L1│
      *               └───┤_L2├───┐   ┌───┤   ├───┘
      *                   └───┤_G2│   │_L5├───┘
      *                       └───┘   └───┘
      */
    [_G1] = LAYOUT_split_3x6_3(
        KC_ESC, KC_T,     KC_Q,    KC_W,    KC_E,    KC_R,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB, KC_LSFT,  KC_A,    KC_S,    KC_D,    KC_F,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_C,   KC_LCTL,  KC_Z,    KC_X,    KC_V,    KC_G,                               KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_DEL,
                                            KC_LALT, KC_SPC, MO(_G2),          MO(_L5), KC_SPC, TG(_G1)
    ),

      /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Esc│F4 │F3 │F2 │F1 │ - │       │ \ │'^'│ ^ │ $ │   │Bsp│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Tab│ 4 │ 3 │ 2 │ 1 │ = │       │ 0 │ < │ v │ > │ : │Ent│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Alt│   │ 6 │ 5 │ 4 │ ` │       │   │ % │ ' │ " │   │PRS│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │Sft├───┐           ┌───┤GUI│
      *               └───┤_L2├───┐   ┌───┤   ├───┘
      *                   └───┤Alt│   │Sft├───┘
      *                       └───┘   └───┘
      */
    [_G2] = LAYOUT_split_3x6_3(
        _______,  XXXXXXX,    KC_9,    KC_8,    KC_7,    KC_MINS,                            KC_BSLS,    S(KC_6),    KC_UP,   S(KC_4),    S(KC_5),    _______,
        _______,  KC_4,       KC_3,    KC_2,    KC_1,    KC_EQL,                             KC_0,       KC_LEFT,    KC_DOWN, KC_RIGHT,   S(KC_SCLN), _______,
        _______,  XXXXXXX,    KC_6,    KC_5,    KC_4,    KC_GRV,                             XXXXXXX,    S(KC_5),    KC_QUOT, S(KC_QUOT), XXXXXXX,    KC_PSCR,
                                            _______, _______, _______,          _______, _______, _______
    ),
};

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//       case KC_CRT:
//         if (record->event.pressed) {
//             SEND_STRING(SS_LSHIFT("6"));
//         }
//         return false;

//       case KC_DRS:
//         if (record->event.pressed) {
//             SEND_STRING(SS_LSHIFT("4"));
//         }
//         return false;
//   }

//   return true;
// }

