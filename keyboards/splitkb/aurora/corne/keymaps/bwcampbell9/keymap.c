/* Copyright 2022 splitkb.com <support@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

// wait DELAY ms before unregistering media keys
#define MEDIA_KEY_DELAY 10

#define TPR KC_TRANSPARENT

enum layers {
    _DEFAULT = 0,
    _SYMBOLS = 1,
    _NAVIGATION = 2,
    _GAMING = 3,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT_split_3x6_3(
        KC_ESCAPE,      KC_W, KC_F, KC_M, KC_P, KC_V,                           KC_SLASH, KC_DOT, KC_Q, S(KC_QUOTE), KC_QUOTE, KC_Z,
        KC_TAB,         KC_R, LCTL_T(KC_S), LALT_T(KC_N), LGUI_T(KC_T), KC_B,   KC_COMMA, RGUI_T(KC_A), RALT_T(KC_E), RCTL_T(KC_I), KC_H, KC_J,
        KC_BACKSPACE,   KC_X, KC_C, KC_L, KC_D, KC_G,                           KC_MINUS, KC_U, KC_O, KC_Y, KC_K, KC_ENTER,
                                KC_NO, TO(1), OSM(MOD_LSFT),                      OSM(MOD_RCTL), MT(KC_MEH, KC_SPACE), KC_NO
    ),
    [_SYMBOLS] = LAYOUT_split_3x6_3(
        TPR, KC_1, KC_2, KC_3, KC_4, KC_5,                                          KC_6, KC_7, KC_8, KC_9, KC_0, KC_F11,
        TPR, KC_QUES, LCTL_T(KC_PLUS), LALT_T(KC_PMNS), LGUI_T(KC_PEQL), KC_PAST,   KC_SLASH, RGUI_T(KC_LPRN), RALT_T(KC_RPRN), RCTL_T(KC_BACKSLASH), KC_SCLN, KC_NO,
        TPR, KC_EXLM, KC_LABK, KC_RABK, KC_AMPR, KC_TILDE,                          KC_LBRC, KC_LCBR, KC_RCBR, KC_RBRC, KC_NO, TPR,
                                TPR, TO(2), TPR,                                  TPR, TO(0), TPR
    ),
    [_NAVIGATION] = LAYOUT_split_3x6_3(
        TPR, KC_MPRV, KC_WH_L, KC_MS_U, KC_WH_R, KC_MNXT,                           KC_WBAK, LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), KC_WFWD, KC_DEL, KC_NO,
        TPR, LGUI(LSFT(KC_S)), KC_MS_L, KC_MS_D, KC_MS_R, KC_PGUP,                  KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT, KC_BRIU, KC_NO,
        TPR, KC_NO, KC_NO, KC_WH_U, KC_WH_D, KC_PGDN,                               KC_BTN1, KC_BTN2, KC_WREF, KC_WSCH, KC_BRID, TPR,
                                TPR, TO(3), OSM(MOD_LGUI),                        TPR, TO(0), TPR
    ),
    [_GAMING] = LAYOUT_split_3x6_3(
        TPR, KC_Q, KC_W, KC_E, KC_R, KC_T,                              BL_UP,   RGB_MOD,  RGB_VAI, KC_NO,   KC_F13, KC_F14,
        TPR, KC_A, KC_S, KC_D, KC_F, KC_G,                              BL_DOWN, RGB_RMOD, RGB_VAD, KC_NO,   KC_F15, KC_F16,
        TPR, KC_Z, KC_X, KC_C, KC_V, KC_B,                              BL_TOGG, RGB_TOG,  KC_NO,   BL_BRTG, KC_F17, KC_F18,
                                TPR, KC_1, KC_2,                      TPR, TO(0), TPR
    )
};

// #ifdef RGBLIGHT_ENABLE
// void keyboard_post_init_user(void) {
//   rgblight_enable_noeeprom(); // enables RGB, without saving settings
//   rgblight_sethsv_noeeprom(HSV_RED); // sets the color to red without saving
//   rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3); // sets mode to Fast breathing without saving
// }
// #endif

bool encoder_update_user(uint8_t index, bool clockwise) {
    // 0 is left-half encoder,
    // 1 is right-half encoder
    if (index == 0) {
        if (clockwise) {
            tap_code16(KC_LEFT);
        } else {
            tap_code16(KC_RIGHT);
        }
        // uint16_t held_keycode_timer = timer_read();
        // if (clockwise) {
        //     register_code(KC_VOLU);
        //     while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY) {
        //     // no-op
        //     }
        //     unregister_code(KC_VOLU);
        // } else {
        //     register_code(KC_VOLD);
        //     while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY) {
        //     // no-op
        //     }
        //     unregister_code(KC_VOLD);
        // }
    } else if (index == 1) {
        if (clockwise) {
            tap_code16(KC_LEFT);
        } else {
            tap_code16(KC_RIGHT);
        }
    }
    return false;
}

// #ifdef OLED_ENABLE
// bool oled_task_user(void) {
//     // A 128x32 OLED rotated 90 degrees is 5 characters wide and 16 characters tall
//     // This example string should fill that neatly
//     const char *text = PSTR("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789!@#$%^&*()[]{}-=_+?");

//     if (is_keyboard_master()) {
//         oled_write_P(text, false);
//     } else {
//         oled_write_P(text, false);
//     }
//     return false;
// }
// #endif
