#include QMK_KEYBOARD_H

// to change keymap, use
// make lily58:(any folder):avrdude

enum layer_number {
    BSE = 0,
    LWR,
    RSE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BSE] = LAYOUT(
            KC_ESC,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRV,
            KC_TAB,  KC_QUOT, KC_COMM,  KC_DOT,    KC_P,    KC_Y,                      KC_F,    KC_G,    KC_C,    KC_R,    KC_L, KC_BSLS,
            KC_LCTL,    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                      KC_D,    KC_H,    KC_T,    KC_N,    KC_S, KC_MINS,
            KC_LSFT, KC_SCLN,    KC_Q,    KC_J,    KC_K,    KC_X, KC_SLSH,  KC_EQL,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, KC_RSFT,
            KC_LALT, KC_LGUI, MO(LWR),  KC_SPC,  KC_ENT, KC_BSPC,  KC_DEL,  MO(RSE)
            ),

    [LWR] = LAYOUT( // I need the 3 key for Minecraft's F3 + 3 hotkey
             KC_F11,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F12,
            _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX, XXXXXXX,
            _______, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX,                   KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, KC_CAPS,
            _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
            _______, _______, _______, _______, _______, _______, _______, _______
            ),

    [RSE] = LAYOUT( // stupid Windows and their ALT codes
            _______, XXXXXXX, XXXXXXX, MS_WHLU, XXXXXXX, XXXXXXX,                    KC_INS, KC_PSCR, KC_SCRL, KC_PAUS, XXXXXXX, XXXXXXX,
            _______, XXXXXXX, XXXXXXX,   MS_UP, XXXXXXX, MS_ACL0,                    KC_NUM,   KC_P7,   KC_P8,   KC_P9, XXXXXXX, XXXXXXX,
            _______, MS_BTN2, MS_LEFT, MS_DOWN, MS_RGHT, MS_ACL1,                   XXXXXXX,   KC_P4,   KC_P5,   KC_P6, XXXXXXX, KC_CAPS,
            _______, XXXXXXX, XXXXXXX, MS_WHLD, XXXXXXX, MS_ACL2, MS_BTN3, _______,   KC_P0,   KC_P1,   KC_P2,   KC_P3, KC_PDOT, _______,
            _______, _______, _______, MS_BTN1, _______, _______, _______, _______
            )

};

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_left())
        return OLED_ROTATION_270;
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_left()) {
        // Host Keyboard Layer Status
        switch (get_highest_layer(layer_state)) {
            case BSE:
                oled_write_P(PSTR("     \n"), false);
                break;
            case LWR:
                oled_write_P(PSTR("LOWER\n"), false);
                break;
            case RSE:
                oled_write_P(PSTR("RAISE\n"), false);
                break;
            default:
                // Or use the write_ln shortcut over adding '\n' to the end of your string
                oled_write_ln_P(PSTR("UNDEF\n"), false);
        }

        // Host Keyboard LED Status
        led_t led_state = host_keyboard_led_state();
        oled_write_ln_P(led_state.num_lock ? PSTR("NUM ") : PSTR(""), false);
        oled_write_ln_P(led_state.caps_lock ? PSTR("CAPS") : PSTR(""), false);
        oled_write_ln_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR(""), false);
    }
    return false;
}
#endif
