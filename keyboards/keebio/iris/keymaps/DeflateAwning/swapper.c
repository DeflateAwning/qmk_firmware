#include "swapper.h"

// Original Source: https://github.com/qmk/qmk_firmware/blob/e90ff84c31905932849164204c10ea58255ddad2/users/callum/swapper.c

void update_swapper(
    bool *active,
    uint16_t cmdish,
    uint16_t tabish,
    uint16_t trigger,
    uint16_t keycode,
    keyrecord_t *record,
	bool escape_on_shift // best option: false
) {
    if (keycode == trigger) { // "tab" key in keymap just pressed
        if (record->event.pressed) {
            if (!*active) {
                *active = true;
                register_code(cmdish);
            }
            register_code(tabish);
		} else {
            unregister_code(tabish);
            // Don't unregister cmdish until some other key is hit or released.
        }
	}
	else if (((keycode == KC_LSFT) || (keycode == KC_RSFT)) && !escape_on_shift) {
		// do nothing; allow the shift key
    } else if (*active) {
        unregister_code(cmdish);
        *active = false;
    }
}

