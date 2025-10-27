#pragma once
#include "tap_dance.h"

#ifdef TAP_DANCE_ENABLE

// Ctrl - Ctrl+Shift
void ct_shft_finished(tap_dance_state_t *state, void *user_data);
void ct_shft_reset(tap_dance_state_t *state, void *user_data);

#endif
