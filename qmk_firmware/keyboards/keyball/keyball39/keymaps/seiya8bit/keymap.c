/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#include "quantum.h"

enum layers {
    _BASE,
    _NUM,    // numbers and function keys
    _SYM,
    _ARROW,
    _MOUSE,  // auto mouse layer
    _SCROLL, // also trackball settings and numpad
    _GAME,
};

_Static_assert(_MOUSE == AUTO_MOUSE_DEFAULT_LAYER, "Update AUTO_MOUSE_DEFAULT_LAYER in config.h");

enum custom_keycodes {
    // Ctrl, or Ctrl+Shift when pressed right after a lone tap
    CTL_SFT = KEYBALL_SAFE_RANGE,
};

// How long a lone tap of CTL_SFT arms Shift for the next press
#define CTL_SFT_ARM_TERM 500

enum tap_dances {
    TD_GAME,
};

// Double tap toggles the game layer
static void td_game_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        layer_invert(_GAME);
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_GAME] = ACTION_TAP_DANCE_FN(td_game_finished),
};

// Layer taps on home row keys
#define D_SCRL  LT(_SCROLL, KC_D)
#define F_MOUSE LT(_MOUSE, KC_F)
#define J_ARROW LT(_ARROW, KC_J)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_universal(
    KC_Q            , KC_W           , KC_E           , KC_R           , KC_T           ,                                   KC_Y           , KC_U           , KC_I           , KC_O           , KC_P           ,
    KC_A            , KC_S           , D_SCRL         , F_MOUSE        , KC_G           ,                                   KC_H           , J_ARROW        , KC_K           , KC_L           , KC_ENT         ,
    KC_Z            , KC_X           , KC_C           , KC_V           , KC_B           ,                                   KC_N           , KC_M           , KC_BSPC        , KC_DEL         , KC_TAB         ,
    KC_LGUI         , KC_ESC         , KC_PSCR        , KC_LSFT        , CTL_SFT        , MO(_NUM)       , MO(_SYM)        , RALT_T(KC_SPC) , XXXXXXX        , XXXXXXX        , XXXXXXX        , TD(TD_GAME)
  ),

  [_NUM] = LAYOUT_universal(
    _______         , _______        , _______        , _______        , _______        ,                                   _______        , _______        , _______        , _______        , _______        ,
    KC_F1           , KC_F2          , KC_F3          , KC_F4          , KC_F5          ,                                   KC_1           , KC_2           , KC_3           , KC_4           , KC_5           ,
    KC_F6           , KC_F7          , KC_F8          , KC_F9          , KC_F10         ,                                   KC_6           , KC_7           , KC_8           , KC_9           , KC_0           ,
    KC_F11          , KC_F12         , KC_F13         , _______        , _______        , _______        , _______        , _______        , _______        , _______        , _______        , _______
  ),

  [_SYM] = LAYOUT_universal(
    S(KC_9)         , S(KC_0)        , S(KC_1)        , S(KC_4)        , S(KC_7)        ,                                   S(KC_GRV)      , S(KC_MINS)     , KC_GRV         , S(KC_EQL)      , KC_SLSH        ,
    KC_LBRC         , KC_RBRC        , S(KC_2)        , S(KC_5)        , S(KC_8)        ,                                   S(KC_SCLN)     , KC_SCLN        , KC_QUOT        , KC_MINS        , S(KC_NUBS)     ,
    S(KC_LBRC)      , S(KC_RBRC)     , S(KC_3)        , S(KC_6)        , S(KC_SLSH)     ,                                   KC_COMM        , KC_DOT         , S(KC_QUOT)     , KC_EQL         , KC_NUBS        ,
    S(KC_COMM)      , S(KC_DOT)      , _______        , _______        , _______        , _______        , _______        , _______        , _______        , _______        , _______        , _______
  ),

  [_ARROW] = LAYOUT_universal(
    _______         , KC_PGUP        , KC_UP          , KC_PGDN        , _______        ,                                   _______        , _______        , _______        , _______        , _______        ,
    _______         , KC_LEFT        , KC_DOWN        , KC_RGHT        , _______        ,                                   _______        , _______        , _______        , _______        , _______        ,
    _______         , _______        , _______        , _______        , _______        ,                                   _______        , _______        , _______        , _______        , _______        ,
    _______         , _______        , _______        , _______        , _______        , _______        , _______        , _______        , _______        , _______        , _______        , _______
  ),

  [_MOUSE] = LAYOUT_universal(
    _______         , _______        , _______        , _______        , _______        ,                                   _______        , _______        , _______        , _______        , _______        ,
    _______         , _______        , _______        , _______        , _______        ,                                   _______        , KC_BTN1        , KC_BTN3        , KC_BTN2        , _______        ,
    _______         , _______        , _______        , _______        , _______        ,                                   _______        , _______        , _______        , _______        , _______        ,
    _______         , _______        , _______        , _______        , _______        , _______        , KC_BTN4        , KC_BTN5        , _______        , _______        , _______        , _______
  ),

  [_SCROLL] = LAYOUT_universal(
    _______         , DT_PRNT        , DT_UP          , DT_DOWN        , AML_TO         ,                                   KC_PSLS        , KC_7           , KC_8           , KC_9           , KC_PMNS        ,
    KBC_SAVE        , _______        , _______        , CPI_I100       , AML_I50        ,                                   KC_DOT         , KC_4           , KC_5           , KC_6           , KC_PPLS        ,
    _______         , _______        , _______        , CPI_D100       , AML_D50        ,                                   KC_0           , KC_1           , KC_2           , KC_3           , _______        ,
    _______         , _______        , _______        , _______        , _______        , _______        , _______        , _______        , _______        , _______        , _______        , EE_CLR
  ),

  [_GAME] = LAYOUT_universal(
    KC_Q            , KC_W           , KC_E           , KC_R           , KC_T           ,                                   KC_1           , KC_2           , KC_3           , KC_4           , KC_5           ,
    KC_A            , KC_S           , KC_D           , KC_F           , KC_G           ,                                   KC_F2          , KC_BTN1        , KC_BTN3        , KC_BTN2        , _______        ,
    KC_Z            , KC_X           , KC_C           , KC_V           , KC_B           ,                                   KC_LEFT        , KC_DOWN        , KC_UP          , KC_RGHT        , _______        ,
    KC_ESC          , _______        , _______        , KC_SPC         , KC_LCTL        , KC_LSFT        , KC_BTN4        , KC_BTN5        , _______        , _______        , _______        , TD(TD_GAME)
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    keyball_set_scroll_mode(get_highest_layer(state) == _SCROLL);
    return state;
}

// Longer term for the double tap of TD_GAME
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    return IS_QK_TAP_DANCE(keycode) ? 275 : g_tapping_term;
}

// Layer taps sit on letter keys, so fast rolls must stay taps
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    return !IS_QK_LAYER_TAP(keycode);
}

// Keep the auto mouse layer when CTL_SFT is pressed on it, for Ctrl+click.
// Release must return the same result as press to keep the key tracker balanced.
bool is_mouse_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool ctl_sft_on_mouse_layer = false;
    if (keycode != CTL_SFT) {
        return false;
    }
    if (record->event.pressed) {
        ctl_sft_on_mouse_layer = layer_state_is(get_auto_mouse_layer());
    }
    return ctl_sft_on_mouse_layer;
}

// CTL_SFT sends Ctrl immediately on press. If the previous press was a lone
// tap, Shift is added once another key or the ball is used during this press.
// Releasing without using anything else is a plain Ctrl tap, so a double tap
// still sends Ctrl twice.
static bool     ctl_sft_armed;       // previous press was a lone tap
static bool     ctl_sft_shift_ready; // this press adds Shift on next use
static bool     ctl_sft_shifted;     // Shift was registered by this press
static bool     ctl_sft_lone;        // nothing else was used during this press
static uint16_t ctl_sft_tap_time;

static void ctl_sft_use(void) {
    if (ctl_sft_shift_ready) {
        register_code(KC_LSFT);
        ctl_sft_shifted     = true;
        ctl_sft_shift_ready = false;
    }
    ctl_sft_lone = false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == CTL_SFT) {
        if (record->event.pressed) {
            ctl_sft_shift_ready = ctl_sft_armed && timer_elapsed(ctl_sft_tap_time) < CTL_SFT_ARM_TERM;
            ctl_sft_lone        = true;
            register_code(KC_LCTL);
        } else {
            if (ctl_sft_shifted) {
                unregister_code(KC_LSFT);
                ctl_sft_shifted = false;
            }
            unregister_code(KC_LCTL);
            // A second lone tap disarms, so a double tap leaves plain Ctrl
            ctl_sft_armed       = ctl_sft_lone && !ctl_sft_shift_ready;
            ctl_sft_shift_ready = false;
            ctl_sft_tap_time    = timer_read();
        }
        return false;
    }
    if (record->event.pressed) {
        ctl_sft_use();
        ctl_sft_armed = false;
    }
    return true;
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (mouse_report.x || mouse_report.y || mouse_report.h || mouse_report.v) {
        ctl_sft_use();
    }
    return mouse_report;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}

#endif
