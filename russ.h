#ifdef TAPPING_TERM
#undef TAPPING_TERM
#endif
#ifdef COMBO_TERM
#undef COMBO_TERM
#endif

#define ONESHOT_TIMEOUT 5000
#define ONESHOT_TAP_TOGGLE 2
#define HOLD_ON_OTHER_KEY_PRESS
#define TAPPING_TERM 120
#define COMBO_TERM 40

enum Layers {
  Base,
  Nav,
  Num,
  Fun,
};

/* Base layer */
#define L1_0101 KC_Q
#define L1_0102 KC_W
#define L1_0103 KC_F
#define L1_0104 KC_P
#define L1_0105 KC_G
#define L1_0106 KC_J
#define L1_0107 KC_L
#define L1_0108 KC_U
#define L1_0109 KC_Y
#define L1_0110 KC_QUOT

#define L1_0201 KC_A
#define L1_0202 KC_R
#define L1_0203 KC_S
#define L1_0204 KC_T
#define L1_0205 KC_D
#define L1_0206 KC_H
#define L1_0207 KC_N
#define L1_0208 KC_E
#define L1_0209 KC_I
#define L1_0210 KC_O

#define L1_0301 KC_Z
#define L1_0302 KC_X
#define L1_0303 KC_C
#ifdef MANTA
#define L1_0304 MO(Nav)
#define L1_0305 KC_BSPC
#define L1_0306 KC_SPC
#define L1_0307 MO(Num)
#else
#define L1_0304 KC_V
#define L1_0305 KC_B
#define L1_0306 KC_K
#define L1_0307 KC_M
#endif
#define L1_0308 KC_COMM
#define L1_0309 KC_DOT
#define L1_0310 KC_SLSH

#define L1_0401 MO(Nav)
#define L1_0402 KC_BSPC
#define L1_0403 KC_SPC
#define L1_0404 MO(Num)

/* Navigation layer */
#define L2_0101 RGB_TOG
#define L2_0102 RGB_MOD
#define L2_0103 RGB_HUI
#define L2_0104 RGB_SAI
#define L2_0105 RGB_VAI
#define L2_0106 KC_MPLY
#define L2_0107 KC_VOLD
#define L2_0108 KC_VOLU
#define L2_0109 XXXXXXX
#define L2_0110 _______

#define L2_0201 KC_LGUI
#define L2_0202 KC_LALT
#define L2_0203 KC_LCTL
#define L2_0204 KC_LSFT
#define L2_0205 XXXXXXX
#define L2_0206 KC_LEFT
#define L2_0207 KC_DOWN
#define L2_0208 KC_UP
#define L2_0209 KC_RIGHT
#define L2_0210 KC_DEL

#define L2_0301 RGB_SPI
#define L2_0302 RGB_SPD
#define L2_0303 RGB_HUD
#define L2_0304 RGB_SAD
#define L2_0305 RGB_VAD
#define L2_0306 XXXXXXX
#define L2_0307 KC_HOME
#define L2_0308 KC_END
#define L2_0309 _______
#define L2_0310 _______

#define L2_0401 XXXXXXX
#define L2_0402 XXXXXXX
#define L2_0403 XXXXXXX
#define L2_0404 XXXXXXX

/* Number layer */
#define L3_0101 KC_LBRC
#define L3_0102 KC_7
#define L3_0103 KC_8
#define L3_0104 KC_9
#define L3_0105 KC_RBRC
#define L3_0106 XXXXXXX
#define L3_0107 XXXXXXX
#define L3_0108 XXXXXXX
#define L3_0109 XXXXXXX
#define L3_0110 XXXXXXX

#define L3_0201 KC_SCLN
#define L3_0202 KC_4
#define L3_0203 KC_5
#define L3_0204 KC_6
#define L3_0205 KC_EQL
#define L3_0206 XXXXXXX
#define L3_0207 KC_RSFT
#define L3_0208 KC_RCTL
#define L3_0209 KC_RALT
#define L3_0210 KC_RGUI

#define L3_0301 KC_GRAVE
#define L3_0302 KC_1
#define L3_0303 KC_2
#define L3_0304 KC_3
#define L3_0305 KC_BSLS
#define L3_0306 KC_0
#define L3_0307 KC_HOME
#define L3_0308 KC_END
#define L3_0309 KC_DOT
#define L3_0310 XXXXXXX

#define L3_0401 KC_0
#define L3_0402 KC_MINS
#define L3_0403 XXXXXXX
#define L3_0404 XXXXXXX

/* Function layer */
#define L4_0101 KC_F12
#define L4_0102 KC_F7
#define L4_0103 KC_F8
#define L4_0104 KC_F9
#define L4_0105 KC_PSCR
#define L4_0106 XXXXXXX
#define L4_0107 XXXXXXX
#define L4_0108 XXXXXXX
#define L4_0109 XXXXXXX
#define L4_0110 QK_BOOT

#define L4_0201 KC_F11
#define L4_0202 KC_F4
#define L4_0203 KC_F5
#define L4_0204 KC_F6
#define L4_0205 KC_SCRL
#define L4_0206 XXXXXXX
#define L4_0207 KC_RSFT
#define L4_0208 KC_RCTL
#define L4_0209 KC_RALT
#define L4_0210 KC_RGUI

#define L4_0301 KC_F10
#define L4_0302 KC_F1
#define L4_0303 KC_F2
#define L4_0304 KC_F3
#define L4_0305 KC_PAUS
#define L4_0306 XXXXXXX
#define L4_0307 XXXXXXX
#define L4_0308 XXXXXXX
#define L4_0309 XXXXXXX
#define L4_0310 XXXXXXX

#define L4_0401 XXXXXXX
#define L4_0402 XXXXXXX
#define L4_0403 XXXXXXX
#define L4_0404 XXXXXXX

enum combos {
  TAB,
  ESC,
  ENT,
  FUN,
  CW,
#ifdef MANTA
  V,
  B,
  M,
  K,
  BSLS,
#endif
  COMBO_LENGTH,
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM tab_combo[] = {L1_0204, L1_0304, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {L3_0202, L3_0203, COMBO_END};
const uint16_t PROGMEM ent_combo[] = {L1_0207, L1_0307, COMBO_END};
const uint16_t PROGMEM fun_combo[] = {L1_0401, L1_0404, COMBO_END};
const uint16_t PROGMEM cw_combo[] = {L3_0105, L3_0205, COMBO_END};
#ifdef MANTA
const uint16_t PROGMEM v_combo[] = {L1_0304, L1_0305, COMBO_END};
const uint16_t PROGMEM b_combo[] = {L1_0303, L1_0304, COMBO_END};
const uint16_t PROGMEM m_combo[] = {L1_0306, L1_0307, COMBO_END};
const uint16_t PROGMEM k_combo[] = {L1_0307, L1_0308, COMBO_END};
const uint16_t PROGMEM bsls_combo[] = {L3_0303, L3_0304, COMBO_END};
#endif

combo_t key_combos[] = {
    [TAB] = COMBO(tab_combo, KC_TAB),
    [ESC] = COMBO(esc_combo, KC_ESC),
    [ENT] = COMBO(ent_combo, KC_ENT),
    [FUN] = COMBO(fun_combo, MO(Fun)),
    [CW] = COMBO(cw_combo, QK_CAPS_WORD_TOGGLE),
#ifdef MANTA
    [V] = COMBO(v_combo, KC_V),
    [B] = COMBO(b_combo, KC_B),
    [K] = COMBO(k_combo, KC_K),
    [M] = COMBO(m_combo, KC_M),
    [BSLS] = COMBO(bsls_combo, KC_BSLS),
#endif
};

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  // debug_enable = false;
  // debug_matrix = true;
  // debug_keyboard = true;
  // debug_mouse = true;
}
