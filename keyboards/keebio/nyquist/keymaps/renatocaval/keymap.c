#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum nyquist_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _CODE,
  _FN_MEDIA,
  _DANGER
};

enum nyquist_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  CODE,
  FN_MEDIA,
  DANGER,

  U_EQ,       // ==
  U_NOT_EQ,   // !=
  U_AND,      // &&
  U_OR,       // ||
  U_EQ_LT,    // <=
  U_GT_EQ,    // >=
  U_EQ_GT,    // =>
  U_LT_HY,    // <-
  U_HY_GT,    // ->
  U_LT_CL,    // <:
  U_CL_LT,    // :<
  U_CL_SPC,   // ': '
  U_TR_TK,    // '``````' triple back-tick (back 3)
  U_TR_QT,    // '""""""' triple quote (back 3)
  U_CMT1,     // '/** */'
  U_CMT2,     // '/* */'
  U_EC_SAVE,  // emacs save and quit
  // Scala
  U_FUNC,     // '{  => }' (back 5)
  U_FUNC2,    // '{ () => }' (back 6)
  U_CASE,      // 'case  => '(back 4)
  U_LGUI,
  U_TASK,
  U_LINK,
  U_WINK,
  U_SMILE,

  //  RGB colors
  PURPLE,
  GREEN,
  RED,
  ORANGE
  };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT( \
  KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,      KC_5,       KC_6,       KC_7,       KC_8,       KC_9,        KC_0,        KC_BSPC, \
  KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,      KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,        KC_P,        KC_ENT,  \
  CODE,       KC_A,       KC_S,       KC_D,       KC_F,      KC_G,       KC_H,       KC_J,       KC_K,       KC_L,        KC_SCLN,     KC_QUOT, \
  KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,      KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,      KC_SLSH,     KC_RSFT,  \
  FN_MEDIA,   KC_LCTL,    KC_LALT,    U_LGUI,     LOWER,     KC_SPC,     KC_SPC,     RAISE,      KC_LEFT,    KC_DOWN,     KC_UP,       KC_RGHT  \
),


[_LOWER] = LAYOUT( \
  KC_ESC,     KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,    KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_MINUS,    KC_EQUAL,     KC_DEL,  \
  KC_TAB,     KC_Q,       KC_W,       KC_COLN,    KC_R,      U_EQ_LT,    U_GT_EQ,    U_EQ_GT,    KC_UP,      KC_LBRC,     KC_RBRC,      KC_ENT,  \
  CODE,       KC_PIPE,    KC_SLSH,    KC_D,       KC_F,      U_LT_HY,    U_HY_GT,    KC_LEFT,    KC_DOWN,    KC_RGHT,     KC_COLN,      KC_DQUO, \
  KC_LSFT,    KC_TILD,    KC_X,       KC_C,       KC_LT,     U_LT_CL,    U_CL_LT,    KC_GT,      KC_COMM,    KC_DOT,      KC_BSLS,      KC_RSFT,\
  FN_MEDIA,   KC_LCTL,    KC_LALT,    U_LGUI,     LOWER,     KC_SPC,     KC_SPC,     RAISE,      KC_HOME,    KC_PGDN,     KC_PGUP,      KC_END  \
),

[_RAISE] = LAYOUT( \
  KC_ESC,     KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,    KC_PERC,    KC_CIRC,   KC_AMPR,    KC_ASTR,    KC_LPRN,     KC_RPRN,      KC_DEL,  \
  KC_TAB,     KC_Q,       KC_W,       KC_COLN,    KC_R,      U_EQ_LT,    U_GT_EQ,   U_EQ_GT,    KC_UP,      KC_LBRC,     KC_RBRC,      KC_ENT,  \
  CODE,       KC_PIPE,    KC_SLSH,    KC_D,       KC_F,      U_LT_HY,    U_HY_GT,   KC_LEFT,    KC_DOWN,    KC_RGHT,     KC_COLN,      KC_DQUO, \
  KC_LSFT,    KC_TILD,    KC_X,       KC_C,       KC_LT,     U_LT_CL,    U_CL_LT,   KC_GT,      KC_COMM,    KC_DOT,      KC_BSLS,      KC_RSFT,\
  FN_MEDIA,   KC_LCTL,    KC_LALT,    U_LGUI,     LOWER,     KC_SPC,     KC_SPC,    RAISE,      KC_HOME,    KC_PGDN,     KC_PGUP,      KC_END  \
),

[_CODE] = LAYOUT( \
  U_TR_TK,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,    KC_CIRC,   KC_AMPR,    KC_ASTR,    KC_LPRN,     KC_RPRN,      KC_DEL,  \
  KC_TAB,     U_NOT_EQ,   U_EQ,       U_CL_SPC,   KC_EXLM,    U_EQ_LT,    U_GT_EQ,   U_EQ_GT,    KC_PIPE,    U_TASK,      U_LINK,       KC_ENT,  \
  CODE,       KC_A,       U_EC_SAVE,  KC_PIPE,    KC_QUES,    U_LT_HY,    U_HY_GT,   U_CASE,     U_FUNC,     U_FUNC2,     U_WINK,       U_TR_QT, \
  KC_LSFT,    KC_NO,      U_CMT2,     U_CMT1,     KC_LT,      U_LT_CL,    U_CL_LT,   U_AND,      U_OR,       KC_DOT,      U_SMILE,      KC_RSFT,\
  FN_MEDIA,   KC_LCTL,    KC_LALT,    U_LGUI,     LOWER,      KC_SPC,     KC_SPC,    RAISE,      KC_HOME,    KC_PGDN,     KC_PGUP,      KC_END  \
),

[_FN_MEDIA ] = LAYOUT( \
  KC_NO,      KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,     KC_F7,      KC_F8,      KC_F9,        KC_F10,      KC_F11,  \
  KC_TAB,     KC_F12,     KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,     KC_BRID,    KC_BRIU,    KC__MUTE,     KC_MPLY,     KC_NO,  \
  KC_NO,      KC_NO,      KC_NO,      DANGER,     KC_NO,      KC_NO,      KC_NO,     KC_NO,      KC_NO,      KC_NO,        KC_NO,       KC_NO, \
  KC_LSFT,    KC_NO,      RGB_TOG,    RGB_MOD,    PURPLE,     GREEN,      RED,       ORANGE,     KC_NO,      KC_NO,        KC_NO,       KC_RSFT,  \
  FN_MEDIA,   KC_LCTL,    KC_LALT,    U_LGUI,     LOWER,      KC_SPC,     KC_SPC,    RAISE,      KC_MRWD,    KC__VOLDOWN,  KC__VOLUP,   KC_MNXT  \
),

[_DANGER] = LAYOUT( \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    RESET,\
  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    DEBUG,\
  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,\
  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,\
  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______\
)

};

#ifdef AUDIO_ENABLE
  #define STARTUP_SONG SONG(STARTUP_SOUND)
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {

        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _FN_MEDIA);
            debug("lower on\n");
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _FN_MEDIA);
            debug("lower off\n");
          }
          return false;
          break;

        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _FN_MEDIA);
            debug("raise on\n");
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _FN_MEDIA);
            debug("raise off\n");
          }
          return false;
          break;

        case CODE:
          if (record->event.pressed) {
            layer_on(_CODE);
            debug("code on\n");
          } else {
            layer_off(_CODE);
            debug("code off\n");
          }
          return false;
          break;


        case FN_MEDIA:
          if (record->event.pressed) {
            layer_on(_FN_MEDIA);
            debug("FN on\n");
          } else {
            layer_off(_FN_MEDIA);
            debug("FN off\n");
          }
          return false;
          break;

        case DANGER:
          if (record->event.pressed) {
            layer_on(_DANGER);
            debug("DANGER on\n");
          } else {
            layer_off(_DANGER);
            debug("DANGER off\n");
          }
          return false;
          break;

        case U_LGUI:
          if (record->event.pressed) {
            SEND_STRING (SS_DOWN(X_LGUI));
          } else {
            SEND_STRING (SS_UP(X_LGUI));
          }

          return true;
          break;

        case U_EQ:
          if (record->event.pressed) {
            SEND_STRING("== ");
          }
          return true;
          break;

        case U_NOT_EQ:
          if (record->event.pressed) {
            SEND_STRING("!= ");
          }
          return true;
          break;

        case U_AND:
          if (record->event.pressed) {
            SEND_STRING("&& ");
          }
          return true;
          break;

        case U_OR:
          if (record->event.pressed) {
            SEND_STRING("|| ");
          }
          return true;
          break;

        case U_EQ_LT:
          if (record->event.pressed) {
            SEND_STRING("<= ");
          }
          return true;
          break;

        case U_GT_EQ:
          if (record->event.pressed) {
            SEND_STRING(">= ");
          }
          return true;
          break;

        case U_EQ_GT:
          if (record->event.pressed) {
            SEND_STRING("=> ");
          }
          return true;
          break;

        case U_LT_HY:
          if (record->event.pressed) {
            SEND_STRING("<- ");
          }
          return true;
          break;

        case U_HY_GT:
          if (record->event.pressed) {
            SEND_STRING("-> ");
          }
          return true;
          break;

        case U_LT_CL:
          if (record->event.pressed) {
            SEND_STRING("<: ");
          }
          return true;
          break;

        case U_CL_LT:
          if (record->event.pressed) {
            SEND_STRING(":> ");
          }
          return true;
          break;

        case U_CL_SPC:
          if (record->event.pressed) {
            SEND_STRING(": ");
          }
          return true;
          break;

        case U_TR_QT:
          if (record->event.pressed) {
            SEND_STRING("\"\"\"\"\"\"");
          } else {
            SEND_STRING(SS_TAP(X_LEFT));
            SEND_STRING(SS_TAP(X_LEFT));
            SEND_STRING(SS_TAP(X_LEFT));
          }
          return true;
          break;

        case U_TR_TK:
          if (record->event.pressed) {
            SEND_STRING("``````");
          } else {
            SEND_STRING(SS_TAP(X_LEFT));
            SEND_STRING(SS_TAP(X_LEFT));
            SEND_STRING(SS_TAP(X_LEFT));
            SEND_STRING (SS_DOWN(X_LSHIFT) SS_TAP(X_ENTER) SS_UP(X_LSHIFT));
            SEND_STRING(SS_TAP(X_LEFT));
          }

          return true;
          break;

        case U_CMT1:
          if (record->event.pressed) {
            SEND_STRING("/**");
          } else {
            SEND_STRING(SS_TAP(X_ENTER));
          }
          return true;
          break;

        case U_CMT2:
          if (record->event.pressed) {
            SEND_STRING("/*");
          } else {
            SEND_STRING(SS_TAP(X_ENTER));
          }
          return true;
          break;

        case U_EC_SAVE:
          if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTRL) "xc" SS_UP(X_LCTRL));
          }
          return true;
          break;

        // Scala
        case U_FUNC:
          if (record->event.pressed) {
            SEND_STRING(" _ => ");
          } else {
            SEND_STRING(SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
            SEND_STRING(SS_TAP(X_LEFT) SS_TAP(X_LEFT));
          }
          return true;
          break;

        case U_FUNC2:
          if (record->event.pressed) {
            SEND_STRING(" (_, _) => ");
          } else {
            SEND_STRING(SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
            SEND_STRING(SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
            SEND_STRING(SS_TAP(X_LEFT) SS_TAP(X_LEFT));

          }
          return true;
          break;

        case U_CASE:
          if (record->event.pressed) {
            SEND_STRING("case  => ");
          } else {
            SEND_STRING(SS_TAP(X_LEFT));
            SEND_STRING(SS_TAP(X_LEFT));
            SEND_STRING(SS_TAP(X_LEFT));
            SEND_STRING(SS_TAP(X_LEFT));
          }
          return true;
          break;

        case U_TASK:
          if (record->event.pressed) {
            SEND_STRING("- [ ] ");
          }
          return true;
          break;

        case U_LINK:
          if (record->event.pressed) {
            SEND_STRING("[]()");
          } else {
            SEND_STRING(SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
          }
          return true;
          break;

        case U_WINK:
          if (record->event.pressed) {
            SEND_STRING(";-)");
          }
          return true;
          break;

        case U_SMILE:
          if (record->event.pressed) {
            SEND_STRING(":-)");
          }
          return true;
          break;

        case PURPLE:
            rgblight_setrgb_purple();
            return true;
            break;
        case GREEN:
            rgblight_setrgb_green();
            return true;
            break;
        case RED:
            rgblight_setrgb_red();
            return true;
            break;
        case ORANGE:
            rgblight_setrgb_orange();
            return true;
            break;
      }
    return true;
};
