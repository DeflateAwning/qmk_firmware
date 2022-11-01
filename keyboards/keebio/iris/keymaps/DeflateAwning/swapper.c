#include "swapper.h"

// Original Source: https://github.com/qmk/qmk_firmware/blob/e90ff84c31905932849164204c10ea58255ddad2/users/callum/swapper.c

bool update_swapper(
    bool *active,
    uint16_t cmdish,
    uint16_t tabish,
    uint16_t trigger,
    uint16_t keycode,
    keyrecord_t *record,
	bool escape_on_shift, // best option: false
	bool escape_on_esc, // best option: false
	bool shift_on_nearby_keys // best option: true
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
	else if (*active) { // "cmdish" key is down I think
        if (((keycode == KC_LSFT) || (keycode == KC_RSFT)) && !escape_on_shift) {
			// do nothing; allow the shift key
		}
		else if (((keycode == KC_ESC) || (keycode == KC_GRAVE)) && !escape_on_esc) {
			// do nothing; allow the esc key (or current key in the ESC spot on that layer)
			if (record->event.pressed) {
				register_code(KC_ESC);
				return false;
			}
			else {
				unregister_code(KC_ESC);
				return false;
			}
		}
		else if (shift_on_nearby_keys && (keycode == KC_QUOT || keycode == KC_COMM || keycode == KC_1)) {
			// send shift key instead of the key pressed
			if (record->event.pressed) {
				register_code(KC_LSFT);
				return false;
			}
			else {
				unregister_code(KC_LSFT);
				return false;
			}
		}
		else {
			unregister_code(cmdish);
    	    *active = false;
		}
    }

	return true;
}

