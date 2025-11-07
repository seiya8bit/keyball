RGBLIGHT_ENABLE = yes

OLED_ENABLE = yes

VIA_ENABLE = yes

DYNAMIC_TAPPING_TERM_ENABLE = yes

TAP_DANCE_ENABLE = yes

SRC += tap_dance.c \
       tap_dance/td_ctl_sft.c \
       tap_dance/td_lhdev.c
