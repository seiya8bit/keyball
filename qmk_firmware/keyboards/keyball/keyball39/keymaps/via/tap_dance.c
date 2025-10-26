// https://docs.qmk.fm/features/tap_dance#example-6

#include QMK_KEYBOARD_H

#include "quantum.h"
#include "tap_dance.h"

#ifdef TAP_DANCE_ENABLE
// Define a type for as many tap dance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_TRIPPLE_TAP
} td_state_t;

#define PL_LAYER 6

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Declare the functions to be used with your tap dance key(s)

// Function associated with all tap dances
td_state_t cur_dance(tap_dance_state_t *state);

// Functions associated with individual tap dances
void pl_finished(tap_dance_state_t *state, void *user_data);
void pl_reset(tap_dance_state_t *state, void *user_data);

// Determine the current tap dance state
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 3) return TD_TRIPPLE_TAP;
    else return TD_UNKNOWN;
}

// Initialize tap structure associated with example tap dance key
static td_tap_t pl_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Functions that control what our tap dance key does
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
            // Check to see if the layer is already set
            if (layer_state_is(PL_LAYER)) {
                // If already set, then switch it off
                layer_off(PL_LAYER);
            } else {
                // If not already set, then switch the layer on
                layer_on(PL_LAYER);
            }
            break;
        default:
            break;
    }
}

void pl_reset(tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (pl_tap_state.state == TD_SINGLE_HOLD) {
        layer_off(PL_LAYER);
    }
    pl_tap_state.state = TD_NONE;
}

// Associate our tap dance key with its functionality
tap_dance_action_t tap_dance_actions[] = {
    [P_LAYR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, pl_finished, pl_reset)
};

// Set a long-ish tapping term for tap-dance keys
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            return 275;
        default:
            return TAPPING_TERM;
    }
}
#endif
