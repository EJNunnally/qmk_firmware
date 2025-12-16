#include QMK_KEYBOARD_H

// to change keymap, use
// make lily58:(any folder):avrdude

enum layer_number {
  _BASE = 0,
  _LAYER1,
  _LAYER2,
  _LAYER3
};

// Things I'm thinking about so far...

// tap-holds (on every layer)
// X: LALT
// C: LGUI
// V: LCTL
// M: RCTL
// ,: RGUI
// .: RALT

#define MT_X LALT_T(KC_X)
#define MT_C LGUI_T(KC_C)
#define MT_V LCTL_T(KC_V)
#define MT_F10 LALT_T(KC_F10)
#define MT_F11 LGUI_T(KC_F11)
#define MT_F12 LCTL_T(KC_F12)
#define MT_M RCTL_T(KC_M)
#define MT_COMM RGUI_T(KC_COMM)
#define MT_DOT RALT_T(KC_DOT)
#define MT_P1 RCTL_T(KC_P1)
#define MT_P2 RGUI_T(KC_P2)
#define MT_P3 RALT_T(KC_P3)

// combos
// QW -> ESC
// AS -> TAB
// OP -> BSPC
// UI -> DEL
// L; -> QUOT

enum combos {
  QW_ESC,
  AS_TAB,
  OP_BSPC,
  UI_DEL,
  LSCLN_QUOT
};

const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM as_combo[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM op_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM lscln_combo[] = {KC_L, KC_SCLN, COMBO_END};

combo_t key_combos[] = {
  [QW_ESC] = COMBO(qw_combo, KC_ESC),
  [AS_TAB] = COMBO(as_combo, KC_TAB),
  [OP_BSPC] = COMBO(op_combo, KC_BSPC),
  [UI_DEL] = COMBO(ui_combo, KC_DEL),
  [LSCLN_QUOT] = COMBO(lscln_combo, KC_QUOT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_BASE] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, XXXXXXX,
  XXXXXXX,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, XXXXXXX,
  XXXXXXX,    KC_Z,    MT_X,    MT_C,    MT_V,    KC_B, XXXXXXX, XXXXXXX,    KC_N,    MT_M, MT_COMM,  MT_DOT, KC_SLSH, XXXXXXX,
                             XXXXXXX, XXXXXXX, KC_LSFT,  KC_SPC,  KC_ENT,   MO(1), XXXXXXX, XXXXXXX
),

 [_LAYER1] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  _______,  KC_GRV, XXXXXXX, XXXXXXX, KC_LBRC, KC_MINS,                    KC_EQL, KC_RBRC, XXXXXXX, XXXXXXX, KC_BSLS, _______,
  _______, XXXXXXX, KC_LALT, KC_LGUI, KC_LCTL, XXXXXXX, _______, _______,   TO(2), KC_RCTL, KC_RGUI, KC_RALT,   TO(3), _______,
                             _______, _______, _______,   TO(0), _______, _______, _______, _______
),

 [_LAYER2] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4, XXXXXXX,                   KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX, _______,
  _______,   KC_F5,   KC_F6,   KC_F7,   KC_F8, XXXXXXX,                   KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, _______,
  _______,   KC_F9,  MT_F10,  MT_F11,  MT_F12, XXXXXXX, _______, _______,   TO(2), KC_RCTL, KC_RGUI, KC_RALT,   TO(3), _______,
                             _______, _______, _______,   TO(0), _______, _______, _______, _______
),

 [_LAYER3] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, XXXXXXX, KC_PSCR, KC_SCRL, KC_PAUS, XXXXXXX,                    KC_NUM,   KC_P7,   KC_P8,   KC_P9, XXXXXXX, _______,
  _______, XXXXXXX,  KC_INS,  KC_APP, KC_CAPS, XXXXXXX,                   XXXXXXX,   KC_P4,   KC_P5,   KC_P6, XXXXXXX, _______,
  _______, XXXXXXX, KC_LALT, KC_LGUI, KC_LCTL, XXXXXXX, _______, _______,   KC_P0,   MT_P1,   MT_P2,   MT_P3, KC_PDOT, _______,
                             _______, _______, _______,   TO(0), _______,   TO(2), _______, _______
)

};

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
