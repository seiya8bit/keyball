// https://docs.qmk.fm/features/tap_dance#example-6

#pragma once

#include QMK_KEYBOARD_H

#ifdef TAP_DANCE_ENABLE

// Define a type for as many tap dance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_TRIPPLE_TAP,
    TD_TRIPLE_HOLD,
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

td_state_t cur_dance(tap_dance_state_t *state);

enum {
    P_LHDEV,
    CTL_SHFT,
};

#include "tap_dance/td_ctl_sft.h"
#include "tap_dance/td_p_lhdev.h"

#endif
