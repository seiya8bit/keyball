#pragma once
#include "tap_dance.h"

#ifdef TAP_DANCE_ENABLE

#define LHDEV_LAYER 6

void td_lhdev_finished(tap_dance_state_t *state, void *user_data);
void td_lhdev_reset(tap_dance_state_t *state, void *user_data);

#endif
