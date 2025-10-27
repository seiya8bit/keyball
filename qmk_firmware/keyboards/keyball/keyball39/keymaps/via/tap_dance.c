// https://docs.qmk.fm/features/tap_dance#example-6

#include QMK_KEYBOARD_H

#include "quantum.h"
#include "tap_dance.h"

#ifdef TAP_DANCE_ENABLE

// Determine the current tap dance state
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }
    if (state->count == 2) {
        if (!state->pressed) return TD_DOUBLE_TAP;
        else return TD_DOUBLE_HOLD;
    }
    if (state->count == 3) {
        if (!state->pressed) return TD_TRIPPLE_TAP;
        else return TD_TRIPLE_HOLD;
    }
    return TD_UNKNOWN;
}

// Associate our tap dance key with its functionality
tap_dance_action_t tap_dance_actions[] = {
    [P_LHDEV] = ACTION_TAP_DANCE_FN_ADVANCED(
        NULL,
        td_p_lhdev_finished,
        td_p_lhdev_reset,
    ),
    [CTL_SFT] = ACTION_TAP_DANCE_FN_ADVANCED(
        NULL,
        td_ctl_sft_finished,
        td_ctl_sft_reset,
    )
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
