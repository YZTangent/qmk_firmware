// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H

enum layer_names {
  _BL,
  _L2,
  _L3,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Esc│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │Bsp│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Tab│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │Ent│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Alt│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │PRS│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │Ctl├───┐           ┌───┤GUI│
      *               └───┤Sft├───┐   ┌───┤   ├───┘
      *                   └───┤_L2│   │_L3├───┘
      *                       └───┘   └───┘
      */
    [_BL] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_PSCR,
                                            MO(_L2), KC_LSFT, KC_LALT,          MO(_L3), KC_SPC, KC_LGUI
    ),

     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Esc│   │ 9 │ 8 │ 7 │ - │       │ \ │'^'│ ^ │ $ │ P │Bsp│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Tab│   │ 3 │ 2 │ 1 │ = │       │ 0 │ < │ v │ > │ ; │Ent│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Alt│   │ 6 │ 5 │ 4 │ ` │       │ ( │ ) │ ' │ [ │ ] │PRS│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │Ctl├───┐           ┌───┤GUI│
      *               └───┤Sft├───┐   ┌───┤   ├───┘
      *                   └───┤_L2│   │_L3├───┘
      *                       └───┘   └───┘
      */
    [_L2] = LAYOUT_split_3x6_3(
        _______, KC_Q,    KC_9,    KC_8,    KC_7,    KC_MINS,                            KC_BSLS,    S(KC_6),    KC_UP,   S(KC_4),  KC_P,    KC_BSPC,
        _______, KC_A,    KC_3,    KC_2,    KC_1,    KC_EQL,                             KC_0,       KC_LEFT,    KC_DOWN, KC_RIGHT, KC_SCLN, KC_QUOT,
        _______, KC_Z,    KC_6,    KC_5,    KC_4,    KC_GRV,                             S(KC_9),    S(KC_0),    KC_QUOT, KC_LBRC,  KC_RBRC, _______,
                                            _______, _______, _______,          _______, _______, _______
    ),

     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Esc│   │ 9 │ 8 │ 7 │ - │       │ \ │'^'│SRC│BRU│VLU│PWR│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Tab│   │ 3 │ 2 │ 1 │ = │       │ 0 │BRB│BRF│BRD│VLD│SLP│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Alt│   │ 6 │ 5 │ 4 │ ` │       │ ( │ ) │ ' │ [ │MUT│WAK│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │Ctl├───┐           ┌───┤GUI│
      *               └───┤Sft├───┐   ┌───┤   ├───┘
      *                   └───┤_L2│   │_L3├───┘
      *                       └───┘   └───┘
      */
    [_L3] = LAYOUT_split_3x6_3(
        _______, KC_Q,    KC_9,    KC_8,    KC_7,    KC_MINS,                            KC_BSLS,    _______,     KC_WSCH,      KC_BRIU,    KC_VOLU,    KC_PWR,
        _______, KC_A,    KC_3,    KC_2,    KC_1,    KC_EQL,                             KC_0,       KC_WBAK,    KC_WFWD,    KC_BRID,  KC_VOLD, KC_SLEP,
        _______, KC_Z,    KC_6,    KC_5,    KC_4,    KC_GRV,                             KC_N,    KC_M,       KC_QUOT, KC_LBRC,  KC_MUTE, KC_WAKE,
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

