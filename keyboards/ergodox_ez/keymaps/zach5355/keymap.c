#include QMK_KEYBOARD_H
#include "version.h"


#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_MINUS,                                       KC_EQUAL,       KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSLASH,
    KC_TAB,         KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,           KC_LBRACKET,                                    KC_RBRACKET,    KC_J,           KC_L,           KC_U,           KC_Y,           KC_SCOLON,      KC_GRAVE,
    KC_CAPSLOCK,    KC_A,           KC_R,           KC_S,           KC_T,           KC_G,                                                                           KC_M,           KC_N,           KC_E,           KC_I,           KC_O,           KC_QUOTE,
    KC_LSPO,        KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,           KC_TRANSPARENT,                                 KC_MEH,         KC_K,           KC_H,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RSPC,
    KC_LCTRL,       KC_LGUI,        KC_LALT,        KC_DELETE,      KC_TRANSPARENT,                                                                                                 TG(1),          TG(2),          KC_TRANSPARENT, KC_TRANSPARENT, KC_RCTRL,
                                                                                                    KC_AUDIO_MUTE,  KC_AUDIO_VOL_UP,KC_LEFT,        KC_RIGHT,
                                                                                                                    KC_AUDIO_VOL_DOWN,KC_UP,
                                                                                    KC_SPACE,       KC_TAB,         KC_MEDIA_PLAY_PAUSE,KC_DOWN,        KC_ENTER,       KC_BSPACE
  ),
  [1] = LAYOUT_ergodox_pretty(
    WEBUSB_PAIR,    KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_TRANSPARENT, KC_SLASH,       KC_7,           KC_8,           KC_9,           KC_PLUS,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_SLASH,       KC_7,           KC_8,           KC_9,           KC_PLUS,        KC_F12,
    KC_TRANSPARENT, KC_ASTR,        KC_4,           KC_5,           KC_6,           KC_MINUS,                                                                       KC_ASTR,        KC_4,           KC_5,           KC_6,           KC_MINUS,       KC_TRANSPARENT,
    KC_TRANSPARENT, KC_BSPACE,      KC_1,           KC_2,           KC_3,           KC_EQUAL,       KC_TAB,                                         KC_TAB,         KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_EQUAL,       KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_DOT,         KC_0,           KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_MINUS,                                       KC_EQUAL,       KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSLASH,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_LBRACKET,                                    KC_RBRACKET,    KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_GRAVE,
    KC_CAPSLOCK,    KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_QUOTE,
    KC_LSPO,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_V,                                           KC_TRANSPARENT, KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RSPC,
    KC_LCTRL,       KC_LGUI,        KC_LALT,        KC_DELETE,      KC_V,                                                                                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RESET,
                                                                                                    KC_AUDIO_MUTE,  KC_AUDIO_VOL_UP,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,
                                                                                                                    KC_AUDIO_VOL_DOWN,KC_TRANSPARENT,
                                                                                    KC_SPACE,       KC_TAB,         KC_MEDIA_PLAY_PAUSE,KC_TRANSPARENT, KC_TRANSPARENT, KC_BSPACE
  ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
	  autoshift_disable();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
	  autoshift_enable();
      break;
  }
  return state;
};
