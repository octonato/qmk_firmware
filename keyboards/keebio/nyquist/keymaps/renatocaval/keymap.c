#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum nyquist_layers {
  _QWERTY,
  _COLEMAK,
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
  // Scala
  U_FUNC,     // '{  => }' (back 5)
  U_FUNC2,    // '{ () => }' (back 6)
  U_CASE,      // 'case  => '(back 4)
  U_LGUI,
  U_TASK,
  U_LINK,
  U_WINK,
  U_SMILE,

  //  RGB
  RGB_TOGG
  };


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,      KC_5,       KC_6,       KC_7,       KC_8,       KC_9,        KC_0,        KC_BSPC, \
  KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,      KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,        KC_P,        KC_ENT,  \
  CODE,       KC_A,       KC_S,       KC_D,       KC_F,      KC_G,       KC_H,       KC_J,       KC_K,       KC_L,        KC_SCLN,     KC_QUOT, \
  KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,      KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,      KC_SLSH,     KC_RSFT,  \
  FN_MEDIA,   KC_LCTL,    KC_LALT,    U_LGUI,     LOWER,     KC_SPC,     KC_SPC,     RAISE,      KC_LEFT,    KC_DOWN,     KC_UP,       KC_RGHT  \
),


/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT( \
  KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,      KC_5,      KC_6,        KC_7,       KC_8,       KC_9,        KC_0,        KC_BSPC, \
  KC_TAB,     KC_Q,       KC_W,       KC_F,       KC_P,      KC_G,      KC_J,        KC_L,       KC_U,       KC_Y,        KC_SCLN,     KC_ENT, \
  CODE,       KC_A,       KC_R,       KC_S,       KC_T,      KC_D,      KC_H,        KC_N,       KC_E,       KC_I,        KC_O,        KC_QUOT, \
  KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,      KC_B,      KC_K,        KC_M,       KC_COMM,    KC_DOT,      KC_SLSH,     KC_RSFT , \
  FN_MEDIA,   KC_LCTL,    KC_LALT,    U_LGUI,     LOWER,     KC_SPC,     KC_SPC,     RAISE,      KC_LEFT,    KC_DOWN,     KC_UP,       KC_RGHT  \
),


[_LOWER] = LAYOUT( \
  KC_ESC,     KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,    KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_MINUS,    KC_EQUAL,     KC_DEL,  \
  KC_TAB,     KC_TRNS,    KC_TRNS,    KC_UP,      KC_PIPE,   U_EQ_LT,    U_GT_EQ,    U_EQ_GT,    KC_UP,      KC_LBRC,     KC_RBRC,      KC_ENT,  \
  CODE,       KC_TRNS,    KC_LEFT,    KC_DOWN,    KC_RGHT,   U_LT_HY,    U_HY_GT,    KC_LEFT,    KC_DOWN,    KC_RGHT,     KC_COLN,      KC_DQUO, \
  KC_LSFT,    KC_TILD,    KC_TRNS,    KC_TRNS,    KC_LT,     U_LT_CL,    U_CL_LT,    KC_GT,      KC_COMM,    KC_DOT,      KC_BSLS,      KC_RSFT,\
  FN_MEDIA,   KC_LCTL,    KC_LALT,    U_LGUI,     LOWER,     KC_SPC,     KC_SPC,     RAISE,      KC_HOME,    KC_PGDN,     KC_PGUP,      KC_END  \
),

[_RAISE] = LAYOUT( \
  KC_ESC,     KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,    KC_PERC,    KC_CIRC,   KC_AMPR,    KC_ASTR,    KC_LPRN,     KC_RPRN,      KC_DEL,  \
  KC_TAB,     KC_TRNS,    KC_TRNS,    KC_UP,      KC_PIPE,   U_EQ_LT,    U_GT_EQ,   U_EQ_GT,    KC_UP,      KC_LBRC,     KC_RBRC,      KC_ENT,  \
  CODE,       KC_TRNS,    KC_LEFT,    KC_DOWN,    KC_RGHT,   U_LT_HY,    U_HY_GT,   KC_LEFT,    KC_DOWN,    KC_RGHT,     KC_COLN,      KC_DQUO, \
  KC_LSFT,    KC_TILD,    KC_TRNS,    KC_TRNS,    KC_LT,     U_LT_CL,    U_CL_LT,   KC_GT,      KC_COMM,    KC_DOT,      KC_BSLS,      KC_RSFT,\
  FN_MEDIA,   KC_LCTL,    KC_LALT,    U_LGUI,     LOWER,     KC_SPC,     KC_SPC,    RAISE,      KC_HOME,    KC_PGDN,     KC_PGUP,      KC_END  \
),

[_CODE] = LAYOUT( \
  U_TR_TK,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,     KC_F7,      KC_F8,      KC_F9,        KC_F10,      KC_F11,  \
  KC_TAB,     U_NOT_EQ,   U_EQ,       U_CL_SPC,   KC_EXLM,    U_EQ_LT,    U_GT_EQ,   U_EQ_GT,    KC_TRNS,    U_TASK,      U_LINK,       KC_ENT,  \
  CODE,       KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_QUES,    U_LT_HY,    U_HY_GT,   U_CASE,     U_FUNC,     U_FUNC2,     U_WINK,       U_TR_QT, \
  KC_LSFT,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_LT,      U_LT_CL,    U_CL_LT,   U_AND,      U_OR,       KC_DOT,      U_SMILE,      KC_RSFT,\
  FN_MEDIA,   KC_LCTL,    KC_LALT,    U_LGUI,     LOWER,      KC_SPC,     KC_SPC,    RAISE,      KC_HOME,    KC_PGDN,     KC_PGUP,      KC_END  \
),

[_FN_MEDIA ] = LAYOUT( \
  KC_TRNS,    KC_F1,      KC_F2,      KC_F3,            KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,        KC_F10,      KC_F11,  \
  KC_TAB,     KC_F12,     KC_TRNS,    KC_TRNS,          KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_BRID,    KC_BRIU,    KC__MUTE,     KC_MPLY,     KC_TRNS,  \
  DANGER,     KC_TRNS,    KC_TRNS,    KC_TRNS,          KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,      KC_TRNS,     KC_TRNS, \
  KC_LSFT,    KC_TRNS,    RGB_TOGG,   RGB_MODE_PLAIN,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,      KC_TRNS,     KC_RSFT,  \
  FN_MEDIA,   KC_LCTL,    KC_LALT,    U_LGUI,           LOWER,      KC_SPC,     KC_SPC,     RAISE,      KC_MRWD,    KC__VOLDOWN,  KC__VOLUP,   KC_MNXT  \
),

[_DANGER] = LAYOUT( \
  _______,    _______,    _______,    _______,    _______,    _______,    DF(_QWERTY),   DF(_COLEMAK),   _______,    _______,    _______,    RESET,\
  _______,    _______,    _______,    _______,    _______,    _______,    _______,       _______,        _______,    _______,    _______,    DEBUG,\
  _______,    _______,    _______,    _______,    _______,    _______,    _______,       _______,        _______,    _______,    _______,    _______,\
  _______,    _______,    _______,    _______,    _______,    _______,    _______,       _______,        _______,    _______,    _______,    _______,\
  _______,    _______,    _______,    _______,    _______,    _______,    _______,       _______,        _______,    _______,    _______,    _______\
)

};

bool rgb_on = false;


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

#define COLOR_LOWER     HSV_CYAN
#define COLOR_RAISE     HSV_CYAN
#define COLOR_FN_MEDIA  HSV_ORANGE
#define COLOR_CODE      HSV_MAGENTA
#define COLOR_DANGER    HSV_RED
#define COLOR_QWERTY    HSV_PURPLE
#define COLOR_COLEMAK   HSV_GREEN

void change_layer_color(void) {
    if (default_layer_state == 1 << _COLEMAK) {
        rgblight_sethsv(HSV_GREEN);
    } else {
        rgblight_sethsv(HSV_PURPLE);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {

        case RGB_TOGG:

          if (record->event.pressed) {
            if (rgb_on) {
                rgblight_disable();
                rgb_on = false;
            } else {
                rgblight_enable();
                rgb_on = true;
            }
          } else {
            if (rgb_on) {
                change_layer_color();
            }
          }

        return true;
        break;

        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            rgblight_sethsv(COLOR_LOWER);
            update_tri_layer(_LOWER, _RAISE, _FN_MEDIA);
            debug("lower on\n");
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _FN_MEDIA);
            change_layer_color();
            debug("lower off\n");
          }
          return false;
          break;

        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            rgblight_sethsv(COLOR_RAISE);
            update_tri_layer(_LOWER, _RAISE, _FN_MEDIA);
            debug("raise on\n");
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _FN_MEDIA);
            change_layer_color();
            debug("raise off\n");
          }
          return false;
          break;

        case CODE:
          if (record->event.pressed) {
            layer_on(_CODE);
            rgblight_sethsv(COLOR_CODE);
            debug("code on\n");
          } else {
            layer_off(_CODE);
            change_layer_color();
            debug("code off\n");
          }
          return false;
          break;


        case FN_MEDIA:
          if (record->event.pressed) {
            layer_on(_FN_MEDIA);
            rgblight_sethsv(COLOR_FN_MEDIA);
            debug("FN on\n");
          } else {
            layer_off(_FN_MEDIA);
            change_layer_color();
            debug("FN off\n");
          }
          return false;
          break;

        case DANGER:
          if (record->event.pressed) {
            layer_on(_DANGER);
            rgblight_sethsv(COLOR_DANGER);
            debug("DANGER on\n");
          } else {
            layer_off(_DANGER);
            change_layer_color();
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

      }
    return true;
};
