#include QMK_KEYBOARD_H

enum custom_keycodes {
    CMD_C = SAFE_RANGE,
    CMD_A,
    CMD_V,
    CMD_X,
    CMD_Z,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
        KC_LGUI, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_HOME, KC_MUTE, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                            KC_LCTL, MO(1),   KC_SPC,  KC_ENT,  MO(2),   KC_RALT
    ),
	[1] = LAYOUT(
        KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
        QK_BOOT, KC_1,    KC_2,    KC_UP,   KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
        KC_LGUI, CMD_A,   KC_LEFT, KC_DOWN, KC_RGHT, KC_LBRC,                   KC_RBRC, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, KC_BSLS,
        KC_LSFT, CMD_Z,   CMD_X,   CMD_C,   CMD_V,   KC_LCBR, KC_NO,   KC_MPLY, KC_RCBR, KC_P1,   KC_P2,   KC_P3,   KC_NO,   KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_DEL,  KC_DEL,  MO(3),   KC_P0
    ),
	[2] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        RGB_TOG, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_F12,
        RGB_MOD, KC_MPRV, LALT(KC_LEFT), KC_VOLU, LALT(KC_RGHT), KC_UNDS,                   KC_EQL,  KC_HOME, RGB_HUI, RGB_SAI, RGB_VAI, KC_BSLS,
        KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS, KC_END,  KC_TRNS, KC_PLUS, KC_END,  RGB_HUD, RGB_SAD, RGB_VAD, KC_TRNS,
                                            KC_TRNS, MO(3),   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [1] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(KC_MRWD, KC_MFFD)  },
    [2] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),           ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  },
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CMD_A:
      if (record->event.pressed) {
          SEND_STRING(SS_LGUI("a"));
      }
      return false;
    case CMD_C:
      if (record->event.pressed) {
          SEND_STRING(SS_LGUI("c"));
      }
      return false;
    case CMD_V:
      if (record->event.pressed) {
          SEND_STRING(SS_LGUI("v"));
      }
      return false;
    case CMD_X:
      if (record->event.pressed) {
          SEND_STRING(SS_LGUI("x"));
      }
      return false;
    case CMD_Z:
      if (record->event.pressed) {
          SEND_STRING(SS_LGUI("z"));
      }
      return false;
    default:
      return true;
  }
}
