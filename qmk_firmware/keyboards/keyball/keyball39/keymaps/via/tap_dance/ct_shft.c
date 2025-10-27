#include "tap_dance/ct_shft.h"

#ifdef TAP_DANCE_ENABLE

static td_tap_t ct_shft_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void ct_shft_finished(tap_dance_state_t *state, void *user_data) {
    ct_shft_tap_state.state = cur_dance(state);
    switch (ct_shft_tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_LCTL);
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_LCTL);
            break;
        case TD_DOUBLE_HOLD:
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            break;
        default:
            break;
    }
}

void ct_shft_reset(tap_dance_state_t *state, void *user_data) {
    switch (ct_shft_tap_state.state) {
        case TD_SINGLE_HOLD:
            unregister_code(KC_LCTL);
            break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_LCTL);
            unregister_code(KC_LSFT);
            break;
        default:
            break;
    }
    ct_shft_tap_state.state = TD_NONE;
}

#endif
