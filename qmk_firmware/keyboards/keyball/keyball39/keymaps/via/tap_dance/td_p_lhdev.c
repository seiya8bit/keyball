#include "tap_dance/td_p_lhdev.h"

#ifdef TAP_DANCE_ENABLE

static td_tap_t td_p_lhdev_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void td_p_lhdev_finished(tap_dance_state_t *state, void *user_data) {
    td_p_lhdev_state.state = cur_dance(state);
    switch (td_p_lhdev_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_P);
            break;
        case TD_SINGLE_HOLD:
            layer_on(LHDEV_LAYER);
            break;
        case TD_TRIPPLE_TAP:
            if (layer_state_is(LHDEV_LAYER)) {
                layer_off(LHDEV_LAYER);
            } else {
                layer_on(LHDEV_LAYER);
            }
            break;
        default:
            break;
    }
}

void td_p_lhdev_reset(tap_dance_state_t *state, void *user_data) {
    if (td_p_lhdev_state.state == TD_SINGLE_HOLD) {
        layer_off(LHDEV_LAYER);
    }
    td_p_lhdev_state.state = TD_NONE;
}

#endif
