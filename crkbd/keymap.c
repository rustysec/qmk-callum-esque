/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "../russ.h"
#include <stdio.h>

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [Base] = LAYOUT_split_3x6_3(
    XXXXXXX, L1_0101, L1_0102, L1_0103, L1_0104, L1_0105, /**/ L1_0106, L1_0107, L1_0108, L1_0109, L1_0110, XXXXXXX,
    XXXXXXX, L1_0201, L1_0202, L1_0203, L1_0204, L1_0205, /**/ L1_0206, L1_0207, L1_0208, L1_0209, L1_0210, XXXXXXX,
    XXXXXXX, L1_0301, L1_0302, L1_0303, L1_0304, L1_0305, /**/ L1_0306, L1_0307, L1_0308, L1_0309, L1_0310, XXXXXXX,
                               XXXXXXX, L1_0401, L1_0402, /**/ L1_0403, L1_0404, XXXXXXX
  ),

  [Nav] = LAYOUT_split_3x6_3(
    XXXXXXX, L2_0101, L2_0102, L2_0103, L2_0104, L2_0105, /**/ L2_0106, L2_0107, L2_0108, L2_0109, L2_0110, XXXXXXX,
    XXXXXXX, L2_0201, L2_0202, L2_0203, L2_0204, L2_0205, /**/ L2_0206, L2_0207, L2_0208, L2_0209, L2_0210, XXXXXXX,
    XXXXXXX, L2_0301, L2_0302, L2_0303, L2_0304, L2_0305, /**/ L2_0306, L2_0307, L2_0308, L2_0309, L2_0310, XXXXXXX,
                               XXXXXXX, L2_0401, L2_0402, /**/ L2_0403, L2_0404, XXXXXXX
  ),

  [Num] = LAYOUT_split_3x6_3(
    XXXXXXX, L3_0101, L3_0102, L3_0103, L3_0104, L3_0105, /**/ L3_0106, L3_0107, L3_0108, L3_0109, L3_0110, XXXXXXX,
    XXXXXXX, L3_0201, L3_0202, L3_0203, L3_0204, L3_0205, /**/ L3_0206, L3_0207, L3_0208, L3_0209, L3_0210, XXXXXXX,
    XXXXXXX, L3_0301, L3_0302, L3_0303, L3_0304, L3_0305, /**/ L3_0306, L3_0307, L3_0308, L3_0309, L3_0310, XXXXXXX,
                               XXXXXXX, L3_0401, L3_0402, /**/ L3_0403, L3_0404, XXXXXXX
  ),

  [Fun] = LAYOUT_split_3x6_3(
    XXXXXXX, L4_0101, L4_0102, L4_0103, L4_0104, L4_0105, /**/ L4_0106, L4_0107, L4_0108, L4_0109, L4_0110, XXXXXXX,
    XXXXXXX, L4_0201, L4_0202, L4_0203, L4_0204, L4_0205, /**/ L4_0206, L4_0207, L4_0208, L4_0209, L4_0210, XXXXXXX,
    XXXXXXX, L4_0301, L4_0302, L4_0303, L4_0304, L4_0305, /**/ L4_0306, L4_0307, L4_0308, L4_0309, L4_0310, XXXXXXX,
                               XXXXXXX, L4_0401, L4_0402, /**/ L4_0403, L4_0404, XXXXXXX
  )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE
