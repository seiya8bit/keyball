#include "tap_dance/td_ctl_sft.h"

#ifdef TAP_DANCE_ENABLE

static td_tap_t td_ctl_sft_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void td_ctl_sft_finished(tap_dance_state_t *state, void *user_data) {
    td_ctl_sft_state.state = cur_dance(state);
    switch (td_ctl_sft_state.state) {
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

void td_ctl_sft_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_ctl_sft_state.state) {
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
    td_ctl_sft_state.state = TD_NONE;
}

#endif
