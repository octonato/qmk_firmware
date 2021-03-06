#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum nyquist_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _MOUSE,
  _FN_MEDIA,
  _CODE,
  _DANGER
};

enum nyquist_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  MOUSE,
  FN_MEDIA,
  CODE,
  DANGER,

  U_EQ_LT,    // <=
  U_GT_EQ,    // >=
  U_EQ_GT,    // =>
  U_LT_HY,    // <-
  U_HY_GT,    // ->

  U_BACK,     // cmd + [
  U_FWD,      // cmd + ]
  U_CMD_BSPC, // cmd + backspace (useful for deleting emails in Airmail)

  // Scala
  U_FUNC,     // '{  => }' (back 5)
  U_MCASE,    // 'case  => '(back 4)
  U_LGUI,
  U_TASK,
  U_LINK,
  U_WINK,
  U_SMILE,

  U_TRAIT,  // trait        t
  U_OBJ,    // object       o
  U_CLASS,  // class        c
  U_CASE,   // case         x
  U_ABS,    // abstract     a
  U_SLD,    // sealed       s
  U_FINAL,  // final        f
  U_EXT,    // extends      e
  U_WITH,   // with         w
  U_MATCH,  // match case   m
  U_PRIV,   // private      p
  U_PTLN,   // println      n
  U_PCKG,   // package      g
  U_DEF,    // def          d
  U_VAL,    // val          v
  U_OVRD,   // override     r
  U_IMPL,   // implicit     ,
  U_IMPT,   // import       k
  U_YIELD,  // yield        y
  U_LAZY,   // lazy         l
  U_THRW,   // throw        b
  U_FOR,    // for yield    j
  U_MDONE,  // map to Done  j
  U_DEBUG,
  U_APPLY,


  //  RGB
  RGB_TOGG
  };


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* Qwerty
 * ,-----------------------------------------.   ´-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   |   Y  |   U  |   I  |   O  |   P  | Enter|
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   |   N  |   M  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |  FN  | Ctrl | Alt  | GUI  |Lower |  Spc |   |  Spc  |Raise | Left | Down |  Up  |Right|
 * `-----------------------------------------,   `-----------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,      KC_5,    /**/   KC_6,       KC_7,       KC_8,       KC_9,        KC_0,        KC_BSPC, \
  KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,      KC_T,    /**/   KC_Y,       KC_U,       KC_I,       KC_O,        KC_P,        KC_ENT,  \
  CODE,       KC_A,       KC_S,       KC_D,       KC_F,      KC_G,    /**/   KC_H,       KC_J,       KC_K,       KC_L,        KC_SCLN,     KC_QUOT, \
  KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,      KC_B,    /**/   KC_N,       KC_M,       KC_COMM,    KC_DOT,      KC_SLSH,     KC_RSFT,  \
  FN_MEDIA,   KC_LCTL,    KC_LALT,    U_LGUI,     LOWER,     KC_SPC,  /**/   KC_SPC,     RAISE,      KC_LEFT,    KC_DOWN,     KC_UP,       KC_RGHT  \
),

/* Lower
 * ,-----------------------------------------.   ´-----------------------------------------.
 * | Esc  |   !  |   @  |   #  |   $  |   %  |   |   ^  |   &  |   *  |   -  |   =  | Del  |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Tab  | forw | btn1 |  up  | btn2 |  <=  |   |  >=  |  =>  |  up  |   [  |   ]  | Enter|
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Code | back | left | down | right|  <-  |   |  ->  | left | down | right|   :  |  '   |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |  <   |   |   >  |   M  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |  FN  | Ctrl | Alt  | GUI  |Lower | spce |   | spce |Raise | home | pgdw | pgup |  end |
 * `-----------------------------------------,   `-----------------------------------------'
 */
[_LOWER] = LAYOUT( \
  KC_ESC,     KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,    KC_PERC,  /**/   KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_MINUS,    KC_EQUAL,     KC_DEL,  \
  KC_ENT,     U_FWD,      KC_BTN1,    KC_UP,      KC_BTN2,   U_EQ_LT,  /**/   U_GT_EQ,    U_EQ_GT,    KC_UP,      KC_LBRC,     KC_RBRC,      KC_ENT,  \
  U_CMD_BSPC, U_BACK,     KC_LEFT,    KC_DOWN,    KC_RGHT,   U_LT_HY,  /**/   U_HY_GT,    KC_LEFT,    KC_DOWN,    KC_RGHT,     KC_COLN,      KC_QUOT, \
  KC_LSFT,    KC_TILD,    _______,    _______,    _______,   KC_LT,    /**/   KC_GT,      _______,    KC_LT,      KC_GT,       KC_PIPE,      KC_RSFT, \
  FN_MEDIA,   KC_LCTL,    KC_LALT,    U_LGUI,     LOWER,     KC_SPC,   /**/   KC_SPC,     RAISE,      KC_HOME,    KC_PGDN,     KC_PGUP,      KC_END   \
),


/* Raise
 * ,-----------------------------------------.   ´-----------------------------------------.
 * | Esc  |   !  |   @  |   #  |   $  |   %  |   |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Tab  |      |      | pgup |      |  <=  |   |  >=  |  =>  |  up  |   [  |   ]  | Enter|
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Code |      | home | pgdw | end  |  <-  |   |  ->  | left | down | right|   :  |  '   |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Shift|   ~  |      |      |      |  <   |   |   >  |      |   <  |   >  |   \  | Shift|
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |  FN  | Ctrl | Alt  | GUI  |Lower | spce |   | spce |Raise | home | pgdw | pgup |  end |
 * `-----------------------------------------,   `-----------------------------------------'
 */
[_RAISE] = LAYOUT( \
  KC_TILD,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,    KC_PERC,  /**/   KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,     KC_RPRN,      KC_DEL,  \
  KC_TAB,     _______,    _______,    KC_PGUP,    _______,   U_EQ_LT,  /**/   U_GT_EQ,    U_EQ_GT,    KC_UP,      KC_LBRC,     KC_RBRC,      KC_ENT,  \
  CODE,       _______,    KC_HOME,    KC_PGDN,    KC_END,    U_LT_HY,  /**/   U_HY_GT,    KC_LEFT,    KC_DOWN,    KC_RGHT,     KC_COLN,      KC_QUOT, \
  KC_LSFT,    KC_TILD,    _______,    _______,    _______,   KC_LT,    /**/   KC_GT,      _______,    KC_LT,      KC_GT,       KC_BSLS,      KC_RSFT, \
  FN_MEDIA,   KC_LCTL,    KC_LALT,    U_LGUI,     LOWER,     KC_SPC,   /**/   KC_SPC,     RAISE,      KC_HOME,    KC_PGDN,     KC_PGUP,      KC_END   \
),


/* Code
 * ,-----------------------------------------.   ´-----------------------------------------.
 * | Esc  |  F1  |  F2  |  F3  |  F4  |  F5  |   |  F6  |  F7  |  F8  |  F9  |  F10 | F11  |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | F12  | thrw | with | ext  | ovrd | trait|   | yield|  =>  | pipe |  [   |   ]  | Enter|
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Code | abs  | sld  | def  | final| pckg |   | ptln | for  | impl | lazy | apply| thrw |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Shift| impt | case |  cls | val  | obj  |   | debug| match| mcase| mdone| func | Shift|
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |  FN  | Ctrl | Alt  | GUI  |Lower | spce |   | spce |Raise | :-)  | ;-)  | - [] | []() |
 * `-----------------------------------------,   `-----------------------------------------'
 */
[_CODE] = LAYOUT( \
  KC_TILD,    KC_F1,      KC_F2,      KC_F3,      KC_F4,     KC_F5,    /**/   KC_F6,      KC_F7,      KC_F8,      KC_F9,       KC_F10,       KC_F11, \
  KC_F12,     U_THRW,     U_WITH,     U_EXT,      U_OVRD,    U_TRAIT,  /**/   U_YIELD,    U_EQ_GT,    KC_PIPE,    KC_LBRC,     KC_RBRC,      KC_ENT ,\
  CODE,       U_ABS,      U_SLD,      U_DEF,      U_FINAL,   U_PCKG,   /**/   U_PTLN,     U_FOR,      U_IMPL,     U_LAZY,      U_APPLY,      KC_QUOT, \
  KC_LSFT,    U_IMPT,     U_CASE,     U_CLASS,    U_VAL,     U_OBJ,    /**/   U_DEBUG,    U_MATCH,    U_MCASE,    U_MDONE,     U_FUNC,       KC_RSFT, \
  FN_MEDIA,   KC_LCTL,    KC_LALT,    U_LGUI,     LOWER,     KC_SPC,   /**/   KC_SPC,     RAISE,      U_SMILE,    U_WINK,      U_TASK,       U_LINK\
),


/* Media
 * ,-----------------------------------------.   ´-----------------------------------------.
 * | Esc  |   F1 |  F2  |  F3  |  F4  |  F5  |   |  F6  |  F7  |  F8  |  F9  |  F10 | Del  |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Tab  | F11  | F12  |      |      |      |   |      |      |      | mute | play | Enter|
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Code |      |      |danger|      |      |   |      |      |      |      |      |  '   |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Shift|      | RGB  | brid | briu |      |   |      |      |      |      |      | Shift|
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |  FN  | Ctrl | Alt  | GUI  | mous | spce |   | spce | mous | prev | vold | volup| next |
 * `-----------------------------------------,   `-----------------------------------------'
 */
[_FN_MEDIA] = LAYOUT( \
  _______,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,    /**/  KC_F6,      KC_F7,      KC_F8,      KC_F9,       KC_F10,       KC_DEL,  \
  KC_DEL,     KC_F11,     KC_F12,     _______,    _______,    _______,  /**/  _______,    _______,    _______,    KC__MUTE,    KC_MPLY,      KC_ENT,  \
  CODE,       _______,    _______,    DANGER,     _______,    _______,  /**/  _______,    _______,    _______,    _______,     _______,      _______, \
  KC_LSFT,    _______,    RGB_TOGG,   KC_BRID,    KC_BRIU,    _______,   /**/  _______,   _______,    _______,    _______,     _______,      KC_RSFT, \
  FN_MEDIA,   KC_LCTL,    KC_LALT,    U_LGUI,     MOUSE,      KC_SPC,   /**/  KC_SPC,     MOUSE,     KC_MRWD,    KC__VOLDOWN, KC__VOLUP,    KC_MNXT  \
),


/* Mouse
 * ,-----------------------------------------.   ´-----------------------------------------.
 * | Esc  |   !  |   @  |   #  |   $  |   %  |   |   ^  |   &  |   *  |   -  |   =  | Del  |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Tab  |      | btn1 | MSWU | btn2 |      |   |      | btn1 | MSWU | btn2 |      | Enter|
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Code |      | MSWL | MSWD | MSWR |      |   |      | MSWL | MSWD | MSWR |      |  '   |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |   |      |      |      |      |      | Shift|
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |  FN  | Ctrl | Alt  | GUI  |Lower | spce |   | spce |Raise | home | pgdw | pgup |  end |
 * `-----------------------------------------,   `-----------------------------------------'
 */
[_MOUSE] = LAYOUT( \
  KC_DEL,     KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,    KC_PERC,  /**/   KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_MINUS,    KC_EQUAL,     KC_DEL,  \
  KC_TAB,     _______,    KC_BTN1,    KC_WH_U,    KC_BTN2,   _______,  /**/   _______,    KC_BTN1,    KC_WH_U,    KC_BTN2,     _______,      KC_ENT,  \
  CODE,       _______,    KC_WH_L,    KC_WH_D,    KC_WH_R,   _______,  /**/   _______,    KC_WH_L,    KC_WH_D,    KC_WH_R,     _______,      KC_QUOT, \
  KC_LSFT,    _______,    _______,    _______,    _______,   _______,  /**/   _______,    _______,    _______,    _______,     _______,      KC_RSFT, \
  FN_MEDIA,   KC_LCTL,    KC_LALT,    U_LGUI,     LOWER,     KC_SPC,   /**/   KC_SPC,     RAISE,      KC_HOME,    KC_PGDN,     KC_PGUP,      KC_END   \
),

[_DANGER] = LAYOUT( \
  _______,    _______,    _______,    _______,    _______,    _______,  /**/   DF(_QWERTY),   _______,        _______,          _______,    _______,    RESET,\
  _______,    _______,    _______,    _______,    _______,    _______,  /**/   _______,       _______,        _______,          _______,    _______,    DEBUG,\
  _______,    _______,    _______,    _______,    _______,    _______,  /**/   _______,       _______,        _______,          _______,    AG_NORM,    AG_SWAP,\
  _______,    _______,    _______,    _______,    _______,    _______,  /**/   _______,       _______,        _______,          _______,    _______,    _______,\
  _______,    _______,    _______,    _______,    _______,    _______,  /**/   _______,       _______,        _______,          _______,    _______,    _______\
)

};

bool rgb_on = false;


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

#define COLOR_QWERTY        HSV_PURPLE

#define COLOR_LAYER         HSV_SPRINGGREEN
#define COLOR_MOUSE         HSV_GREEN
#define COLOR_FN_MEDIA      HSV_CYAN
#define COLOR_CODE          HSV_MAGENTA
#define COLOR_DANGER        HSV_RED

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
                rgblight_sethsv_noeeprom(COLOR_QWERTY);
            }
          }

        return true;
        break;

        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            rgblight_sethsv_noeeprom(COLOR_LAYER);
          } else {
            layer_off(_LOWER);
            rgblight_sethsv_noeeprom(COLOR_QWERTY);
          }
          return false;
          break;


        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            rgblight_sethsv_noeeprom(COLOR_LAYER);
          } else {
            layer_off(_RAISE);
            rgblight_sethsv_noeeprom(COLOR_QWERTY);
          }
          return false;
          break;


        case FN_MEDIA:
          if (record->event.pressed) {
            layer_on(_FN_MEDIA);
            rgblight_sethsv_noeeprom(COLOR_FN_MEDIA);
          } else {
            layer_off(_FN_MEDIA);
            rgblight_sethsv_noeeprom(COLOR_QWERTY);
          }
          return false;
          break;

        case CODE:
          if (record->event.pressed) {
            layer_on(_CODE);
            rgblight_sethsv_noeeprom(COLOR_CODE);
          }else {
            layer_off(_CODE);
            rgblight_sethsv_noeeprom(COLOR_QWERTY);
          }
          return false;
          break;


        case MOUSE:
          if (record->event.pressed) {
            layer_on(_MOUSE);
            rgblight_sethsv_noeeprom(COLOR_MOUSE);
          } else {
            layer_off(_MOUSE);
            rgblight_sethsv_noeeprom(COLOR_QWERTY);
          }
          return false;
          break;

        case DANGER:
          if (record->event.pressed) {
            layer_on(_DANGER);
            rgblight_sethsv_noeeprom(COLOR_DANGER);
          } else {
            layer_off(_DANGER);
            rgblight_sethsv_noeeprom(COLOR_QWERTY);
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

        case U_MCASE:
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

        case U_TRAIT:
          if (record->event.pressed) {
            SEND_STRING("trait ");
          }
          return true;
          break;

        case U_OBJ:
          if (record->event.pressed) {
            SEND_STRING("object ");
          }
          return true;
          break;

        case U_CLASS:
          if (record->event.pressed) {
            SEND_STRING("class ");
          }
          return true;
          break;

        case U_CASE:
          if (record->event.pressed) {
            SEND_STRING("case ");
          }
          return true;
          break;

        case U_ABS:
          if (record->event.pressed) {
            SEND_STRING("abstract ");
          }
          return true;
          break;

        case U_SLD:
          if (record->event.pressed) {
            SEND_STRING("sealed ");
          }
          return true;
          break;

        case U_FINAL:
          if (record->event.pressed) {
            SEND_STRING("final ");
          }
          return true;
          break;


        case U_EXT:
          if (record->event.pressed) {
            SEND_STRING("extends ");
          }
          return true;
          break;

        case U_WITH:
          if (record->event.pressed) {
            SEND_STRING("with ");
          }
          return true;
          break;

        case U_MATCH:
          if (record->event.pressed) {
            SEND_STRING("match {}");
            SEND_STRING(SS_TAP(X_LEFT) SS_TAP(X_ENTER));
            SEND_STRING("case  => ");
          } else {
            SEND_STRING(SS_TAP(X_LEFT));
            SEND_STRING(SS_TAP(X_LEFT));
            SEND_STRING(SS_TAP(X_LEFT));
            SEND_STRING(SS_TAP(X_LEFT));
          }
          return true;
          break;

        case U_PRIV:
          if (record->event.pressed) {
            SEND_STRING("private ");
          }
          return true;
          break;

        case U_PCKG:
          if (record->event.pressed) {
            SEND_STRING("package ");
          }
          return true;
          break;

        case U_PTLN:
          if (record->event.pressed) {
            SEND_STRING("println(");
          }
          return true;
          break;

        case U_DEBUG:
          if (record->event.pressed) {
            SEND_STRING("println(s\"[DEBUG] >=> \")");
          } else {
              SEND_STRING(SS_TAP(X_LEFT) SS_TAP(X_LEFT));
          }
          return true;
          break;

        case U_APPLY:
          if (record->event.pressed) {
            SEND_STRING("apply(");
          }
          return true;
          break;
        case U_DEF:
          if (record->event.pressed) {
            SEND_STRING("def ");
          }
          return true;
          break;

        case U_VAL:
          if (record->event.pressed) {
            SEND_STRING("val ");
          }
          return true;
          break;

        case U_OVRD:
          if (record->event.pressed) {
            SEND_STRING("override ");
          }
          return true;
          break;

        case U_IMPL:
          if (record->event.pressed) {
            SEND_STRING("implicit ");
          }
          return true;
          break;

        case U_IMPT:
          if (record->event.pressed) {
            SEND_STRING("import ");
          }
          return true;
          break;

        case U_YIELD:
          if (record->event.pressed) {
            SEND_STRING("yield ");
          }
          return true;
          break;

        case U_FOR:
          if (record->event.pressed) {
            SEND_STRING("for {} yield ");
          } else {
            SEND_STRING(SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
            SEND_STRING(SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
            SEND_STRING(SS_TAP(X_ENTER));
          }

          return true;
          break;

        case U_LAZY:
          if (record->event.pressed) {
            SEND_STRING("lazy ");
          }
          return true;
          break;

        case U_THRW:
          if (record->event.pressed) {
            SEND_STRING("throw new ");
          }
          return true;
          break;

        case U_MDONE:
          if (record->event.pressed) {
            SEND_STRING(".map(_ => Done)");
          }
          return true;
          break;

        case U_BACK:
          if (record->event.pressed) {
            SEND_STRING (SS_DOWN(X_LGUI) SS_DOWN(X_LBRC) SS_UP(X_LBRC) SS_UP(X_LGUI));
          }
          return true;
          break;

        case U_FWD:
          if (record->event.pressed) {
            SEND_STRING (SS_DOWN(X_LGUI) SS_DOWN(X_RBRC) SS_UP(X_RBRC) SS_UP(X_LGUI));
          }
          return true;
          break;

        case U_CMD_BSPC:
          if (record->event.pressed) {
            SEND_STRING (SS_DOWN(X_LGUI) SS_DOWN(X_BSPC) SS_UP(X_BSPC) SS_UP(X_LGUI));
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
