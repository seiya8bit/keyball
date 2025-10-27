#pragma once
#include "tap_dance.h"

#ifdef TAP_DANCE_ENABLE

// P - Layer6
void pl_finished(tap_dance_state_t *state, void *user_data);
void pl_reset(tap_dance_state_t *state, void *user_data);

#endif
