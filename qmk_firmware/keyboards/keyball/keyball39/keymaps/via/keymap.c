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
#include "tap_dance.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Default
  [0] = LAYOUT_universal(
    KC_Q            , KC_W           , KC_E           , KC_R           , KC_T           ,                                   KC_Y           , KC_U           , KC_I           , KC_O           , TD(P_LAYR)     ,
    KC_A            , KC_S           , KC_D           , KC_F           , KC_G           ,                                   KC_H           , KC_J           , KC_K           , KC_L           , LT(5, KC_ENT)  ,
    KC_Z            , KC_X           , KC_C           , KC_V           , KC_B           ,                                   KC_N           , KC_M           , KC_BSPC        , KC_DEL         , KC_TAB         ,
    KC_ESC          , KC_PSCR        , KC_LGUI        , KC_LSFT        , TD(CT_SHFT)    , MO(1)          , MO(2)          , RALT_T(KC_SPC) , _______        , _______        , _______        , MO(3)
  ),

  // Number/Functions
  [1] = LAYOUT_universal(
    _______         , _______        , _______        , _______        , _______        ,                                   _______        , _______        , _______        , _______        , _______        ,
    KC_F1           , KC_F2          , KC_F3          , KC_F4          , KC_F5          ,                                   KC_1           , KC_2           , KC_3           , KC_4           , KC_5           ,
    KC_F6           , KC_F7          , KC_F8          , KC_F9          , KC_F10         ,                                   KC_6           , KC_7           , KC_8           , KC_9           , KC_0           ,
    KC_F11          , KC_F12         , KC_F13         , _______        , _______        , _______        , _______        , _______        , _______        , _______        , _______        , _______
  ),

  // Symbol
  [2] = LAYOUT_universal(
    S(KC_9)         , S(KC_0)        , S(KC_1)        , S(KC_4)        , S(KC_7)        ,                                   S(KC_GRV)      , KC_GRV         , KC_QUOT	       , S(KC_QUOT)     , KC_SLSH        ,
    KC_LBRC         , KC_RBRC        , S(KC_2)        , S(KC_5)        , S(KC_8)        ,                                   S(KC_SCLN)     , KC_SCLN        , KC_COMM        , KC_DOT         , S(KC_NUBS)     ,
    S(KC_LBRC)      , S(KC_RBRC)     , S(KC_3)        , S(KC_6)        , _______        ,                                   S(KC_EQL)      , KC_MINS        , KC_EQL         , S(KC_MINS)     , KC_NUBS        ,
    S(KC_COMM)      , S(KC_DOT)      , _______        , _______        , _______        , _______        , _______        , _______        , _______        , _______        , _______        , S(KC_SLSH)
  ),

  // Arrow
  [3] = LAYOUT_universal(
    _______         , _______        , _______        , _______        , _______        ,                                   _______        , _______        , _______        , _______        , _______        ,
    _______         , KC_PGUP        , KC_UP          , KC_PGDN        , _______        ,                                   _______        , _______        , _______        , _______        , _______        ,
    _______         , KC_LEFT        , KC_DOWN        , KC_RGHT        , _______        ,                                   _______        , _______        , _______        , _______        , _______        ,
    _______         , _______        , _______        , _______        , _______        , _______        , _______        , _______        , _______        , _______        , _______        , _______
  ),

  // Mouse
  [4] = LAYOUT_universal(
    _______         , _______        , _______        , _______        , _______        ,                                   _______        , _______        , _______        , _______        , _______        ,
    _______         , _______        , _______        , _______        , _______        ,                                   _______        , KC_BTN1        , KC_BTN3        , KC_BTN2        , _______        ,
    _______         , _______        , _______        , _______        , _______        ,                                   _______        , _______        , _______        , _______        , _______        ,
    _______         , _______        , _______        , _______        , _______        , _______        , KC_BTN4        , KC_BTN5        , _______        , _______        , _______        , _______
  ),

  // Scroll
  [5] = LAYOUT_universal(
    KBC_SAVE        , _______        , _______        , _______        , AML_TO         ,                                   _______        , _______        , _______        , _______        , _______        ,
    _______         , _______        , _______        , CPI_I100       , AML_I50        ,                                   _______        , _______        , _______        , _______        , _______        ,
    EE_CLR          , _______        , _______        , CPI_D100       , AML_D50        ,                                   _______        , _______        , _______        , _______        , _______        ,
    _______         , _______        , _______        , _______        , _______        , _______        , _______        , _______        , _______        , _______        , _______        , _______
  ),

  // Left-hand Device
  [6] = LAYOUT_universal(
    KC_Q            , KC_W           , KC_E           , KC_R           , KC_T           ,                                   KC_1           , KC_2           , KC_3           , KC_4           , TD(P_LAYR)     ,
    KC_A            , KC_S           , KC_D           , KC_F           , KC_G           ,                                   _______        , KC_BTN1        , KC_BTN3        , KC_BTN2        , _______        ,
    KC_Z            , KC_X           , KC_C           , KC_V           , KC_B           ,                                   _______        , _______        , _______        , _______        , _______        ,
    KC_ESC          , _______        , _______        , KC_SPC         , KC_LCTL        , KC_LSFT        , KC_BTN4        , KC_BTN5        , _______        , _______        , _______        , _______
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 5
    keyball_set_scroll_mode(get_highest_layer(state) == 5);
    return state;
}

#ifdef OLED_ENABLE

#include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}

#endif
