#include "tap_dance/ct_shft.h"

#ifdef TAP_DANCE_ENABLE

#define PL_LAYER 6

static td_tap_t pl_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void pl_finished(tap_dance_state_t *state, void *user_data) {
    pl_tap_state.state = cur_dance(state);
    switch (pl_tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_P);
            break;
        case TD_SINGLE_HOLD:
            layer_on(PL_LAYER);
            break;
        case TD_TRIPPLE_TAP:
            if (layer_state_is(PL_LAYER)) {
                layer_off(PL_LAYER);
            } else {
                layer_on(PL_LAYER);
            }
            break;
        default:
            break;
    }
}

void pl_reset(tap_dance_state_t *state, void *user_data) {
    if (pl_tap_state.state == TD_SINGLE_HOLD) {
        layer_off(PL_LAYER);
    }
    pl_tap_state.state = TD_NONE;
}

#endif
