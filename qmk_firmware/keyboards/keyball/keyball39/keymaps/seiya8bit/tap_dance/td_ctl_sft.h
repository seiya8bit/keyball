#pragma once
#include "tap_dance.h"

#ifdef TAP_DANCE_ENABLE

void td_ctl_sft_finished(tap_dance_state_t *state, void *user_data);
void td_ctl_sft_reset(tap_dance_state_t *state, void *user_data);

#endif
