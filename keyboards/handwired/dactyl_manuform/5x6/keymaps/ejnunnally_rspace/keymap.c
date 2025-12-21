#include QMK_KEYBOARD_H

enum layer_number {
    BSE = 0,
    LWR,
    RSE
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BSE] = LAYOUT_5x6(
         KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRV,
         KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
        KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_APO,
        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
                          KC_LEFT, KC_RGHT,                                                       KC_DOWN,   KC_UP,
                                             KC_SPC, KC_LBRC,                   KC_RBRC,  KC_SPC,
                                            KC_LGUI, KC_MINS,                    KC_EQL,  KC_ENT,
                                            KC_LALT, MO(LWR),                   KC_BSPC, MO(RSE)
                                            // lower, space, slsh               eql, enter, bspc
                                            // lalt, lgui, lbrc                 rbrc, del, raise
    ),

    [LWR] = LAYOUT_5x6(
         KC_F11,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F12,
        _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX, XXXXXXX,
        _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                   KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                          KC_HOME,  KC_END,                                                       KC_PGDN, KC_PGUP,
                                            _______, XXXXXXX,                   XXXXXXX, _______,
                                            _______, XXXXXXX,                   XXXXXXX, _______,
                                            _______, _______,                   _______, _______
    ),

    [RSE] = LAYOUT_5x6(
        _______, MS_ACL0, MS_ACL1, MS_ACL2, _______, _______,                    KC_INS, KC_PSCR, KC_SCRL, KC_PAUS, XXXXXXX, XXXXXXX,
        _______, _______, _______,   MS_UP, _______, _______,                    KC_NUM,   KC_P7,   KC_P8,   KC_P9, XXXXXXX, XXXXXXX,
        _______, MS_BTN2, MS_LEFT, MS_DOWN, MS_RGHT, _______,                   XXXXXXX,   KC_P4,   KC_P5,   KC_P6, XXXXXXX, KC_CAPS,
        _______, _______, _______, _______, _______, _______,                     KC_P0,   KC_P1,   KC_P2,   KC_P3, KC_PDOT, _______,
                          MS_WHLL, MS_WHLR,                                                       MS_WHLD, MS_WHLU,
                                            MS_BTN1, MS_BTN3,                   XXXXXXX, _______,
                                            _______, XXXXXXX,                   XXXXXXX, _______,
                                            _______, _______,                   _______, _______
    )
};
