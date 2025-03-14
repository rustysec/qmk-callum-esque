/*
Copyright 2022 Cole Smith <cole@boadsource.xyz>

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [Base] = LAYOUT_eg(
    L1_0101, L1_0102, L1_0103, L1_0104, L1_0105, /**/ L1_0106, L1_0107, L1_0108, L1_0109, L1_0110,
    L1_0201, L1_0202, L1_0203, L1_0204, L1_0205, /**/ L1_0206, L1_0207, L1_0208, L1_0209, L1_0210,
    L1_0301, L1_0302, L1_0303, L1_0304, L1_0305, /**/ L1_0306, L1_0307, L1_0308, L1_0309, L1_0310,
                      XXXXXXX, L1_0401, L1_0402, /**/ L1_0403, L1_0404, XXXXXXX
  ),

  [Nav] = LAYOUT_eg(
    L2_0101, L2_0102, L2_0103, L2_0104, L2_0105, /**/ L2_0106, L2_0107, L2_0108, L2_0109, L2_0110,
    L2_0201, L2_0202, L2_0203, L2_0204, L2_0205, /**/ L2_0206, L2_0207, L2_0208, L2_0209, L2_0210,
    L2_0301, L2_0302, L2_0303, L2_0304, L2_0305, /**/ L2_0306, L2_0307, L2_0308, L2_0309, L2_0310,
                      XXXXXXX, L2_0401, L2_0402, /**/ L2_0403, L2_0404, XXXXXXX
  ),

  [Num] = LAYOUT_eg(
    L3_0101, L3_0102, L3_0103, L3_0104, L3_0105, /**/ L3_0106, L3_0107, L3_0108, L3_0109, L3_0110,
    L3_0201, L3_0202, L3_0203, L3_0204, L3_0205, /**/ L3_0206, L3_0207, L3_0208, L3_0209, L3_0210,
    L3_0301, L3_0302, L3_0303, L3_0304, L3_0305, /**/ L3_0306, L3_0307, L3_0308, L3_0309, L3_0310,
                      XXXXXXX, L3_0401, L3_0402, /**/ L3_0403, L3_0404, XXXXXXX
  ),

  [Fun] = LAYOUT_eg(
    L4_0101, L4_0102, L4_0103, L4_0104, L4_0105, /**/ L4_0106, L4_0107, L4_0108, L4_0109, L4_0110,
    L4_0201, L4_0202, L4_0203, L4_0204, L4_0205, /**/ L4_0206, L4_0207, L4_0208, L4_0209, L4_0210,
    L4_0301, L4_0302, L4_0303, L4_0304, L4_0305, /**/ L4_0306, L4_0307, L4_0308, L4_0309, L4_0310,
                      XXXXXXX, L4_0401, L4_0402, /**/ L4_0403, L4_0404, XXXXXXX
  )
};
