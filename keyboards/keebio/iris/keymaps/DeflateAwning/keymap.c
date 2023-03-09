
#include QMK_KEYBOARD_H
#include "swapper.h"
#include "keymap_steno.h"


enum my_layers {
   _DVORAK,
   _QWERTY, // access with button on the _LOWER layer
   _LOWER, // access with left-hand layer key
   _RAISE, // access with right-hand layer key
   _VI_ARROWS, // access by pressing "OEU" as a chord/combo
   _PLOVER_GEM,
   _ADJUST
};

#define COMBO_COUNT 2
const uint16_t PROGMEM combo_oeu[] = {KC_O, KC_E, KC_U, COMBO_END};
const uint16_t PROGMEM combo_sdf[] = {KC_S, KC_D, KC_F, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
   COMBO(combo_oeu, MO(_VI_ARROWS)),
   COMBO(combo_sdf, MO(_VI_ARROWS))
};
uint16_t COMBO_LEN = COMBO_COUNT;

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define B_QWE DF(_QWERTY) // set default base layer
#define B_DVO DF(_DVORAK) // set default base layer

bool sw_alt_active = false;

enum custom_keycodes {
   BSP_DEL = SAFE_RANGE,
   SW_WIN,
   PLO_GEM,
   EXT_PLV
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DVORAK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    BSP_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                               KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                               KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_MPLY,          KC_MNXT, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    LOWER,   KC_LGUI,  KC_LSFT,                   KC_SPC,  KC_RALT, RAISE
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  
  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    BSP_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    B_DVO,            B_DVO,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    LOWER,   KC_LGUI,  KC_LSFT,                   KC_SPC,  KC_RALT, RAISE
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRAVE, KC_EXLM, KC_AT,  KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, BSP_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     SW_WIN,   KC_1,    KC_COMM, KC_DOT,  KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_LEFT,  KC_UP,  KC_DOWN, KC_RGHT, KC_LBRC,                            KC_RBRC,  KC_4,    KC_5,    KC_6,   KC_PLUS, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, _______, _______, B_QWE  , KC_BSLS, KC_LCBR, KC_MPLY,          KC_MNXT, KC_RCBR,  KC_1,    KC_2,    KC_3,   KC_MINS, KC_PIPE,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, KC_LGUI, KC_LSFT,                   KC_LSFT,  KC_0,    KC_DOT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  
  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, KC_UNDS,                            KC_EQL,  KC_HOME, RGB_HUI, RGB_SAI, RGB_VAI, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, PLO_GEM, KC_MPLY,          KC_MNXT, KC_PLUS, KC_END,  RGB_HUD, RGB_SAD, RGB_VAD, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, KC_LGUI, KC_LSFT,                   _______, KC_RALT, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),


  [_VI_ARROWS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, BSP_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, _______, _______, _______, _______, _______,                            KC_HOME, KC_LEFT, KC_DOWN,  KC_UP,  KC_RGHT, KC_END,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, KC_LGUI, KC_LSFT,                   _______, KC_RALT, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_PLOVER_GEM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     EXT_PLV, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,                            STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2,                            STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  STN_N6,  KC_MPLY,          KC_MNXT, STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,  STN_NC,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    XXXXXXX, STN_A,   STN_O,                     STN_E,   STN_U,   XXXXXXX
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_TOG, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_MOD, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

   uint16_t temp_keycode = keycode;
   static uint8_t saved_mods = 0;

   
   // Press ALT+TAB with LOWER key
   // Source (docs): https://github.com/qmk/qmk_firmware/tree/master/users/callum#swapper
   // Source (example): https://github.com/qmk/qmk_firmware/blob/868c7b52930fc6d3f44a57cb257fcc39e60ac3d0/users/callum/callum.c#L99
   if (! update_swapper(
        &sw_alt_active, KC_LALT, KC_TAB, SW_WIN,
        keycode, record, false, false, true
    )) return false;


   switch (temp_keycode) {

      // Turn Shift+Backspace into a forwards Delete
      // Source: https://github.com/rpbaptist/qmk_firmware/blob/2eb9f227c10a242996dba746b8a2b9ed2edd315c/keyboards/crkbd/keymaps/rpbaptist/keymap.c#L504
      case BSP_DEL:
         if (record->event.pressed) {
               saved_mods = get_mods() & MOD_MASK_SHIFT;

               if (saved_mods == MOD_MASK_SHIFT) {  // Both shifts pressed
                  register_code(KC_DEL);
               } else if (saved_mods) {   // One shift pressed
                  del_mods(saved_mods);  // Remove any Shifts present
                  register_code(KC_DEL);
                  add_mods(saved_mods);  // Add shifts again
               } else {
                  register_code(KC_BSPC);
               }
         } else {
               unregister_code(KC_DEL);
               unregister_code(KC_BSPC);
         }
         return false;
         break;

      case PLO_GEM:
         
         layer_off(_RAISE);
         layer_off(_LOWER);
         layer_off(_ADJUST);
         layer_on(_PLOVER_GEM);

         return false;
         break;

      case EXT_PLV:
         layer_off(_PLOVER_GEM);
         return false;
         break;

   }

   return true;

}

bool encoder_update_user(uint8_t index, bool clockwise) {
   if (index == 0) {
      // left encoder
      switch(biton32(layer_state)) {

         case _QWERTY:
         case _DVORAK:
            if (clockwise) {
               tap_code(KC_VOLU);
            } else {
               tap_code(KC_VOLD);
            }
            break;

         case _LOWER:
            if(clockwise) {
               tap_code(KC_PGUP);
            } else {
               tap_code(KC_PGDN);
            }
            break;

         case _RAISE:
            if (clockwise) {
               tap_code(KC_VOLU);
            } else {
               tap_code(KC_VOLD);
            }
            break;
      }
   }
   else if (index == 1) {
      // right encoder

      // useful for going forward and back in history if Ctrl is held
      if (clockwise) {
         tap_code(KC_RGHT);
      } else {
         tap_code(KC_LEFT);
      }
   }

   return false; // from example
}



void matrix_init_user() {
  // set the steno protocol
  steno_set_mode(STENO_MODE_GEMINI);

  // set the bootup layer
  //layer_on(_PLOVER_GEM);
}

