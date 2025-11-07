#include "tap_dance/td_lhdev.h"

#ifdef TAP_DANCE_ENABLE

static td_tap_t td_lhdev_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void td_lhdev_finished(tap_dance_state_t *state, void *user_data) {
    td_lhdev_state.state = cur_dance(state);
    switch (td_lhdev_state.state) {
        case TD_DOUBLE_TAP:
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

void td_lhdev_reset(tap_dance_state_t *state, void *user_data) {
    td_lhdev_state.state = TD_NONE;
}

#endif
