/* Copyright 2021 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "debug.h"
#include QMK_KEYBOARD_H
#include "features/achordion.h"
#include "print.h"

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    debug_enable = true;
    debug_matrix = true;
    // debug_keyboard=true;
    // debug_mouse=true;
}
// clang-format off

enum layers{
    BASE,
    BASEMOD,
    NAV,
    NUM,
    SYM,
    NAVMOD,
    MOUSE,
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌──────┬──────┬──────┬────┬────┬────┬────┬────┬────┬────┬──────┬───────┬──────┬──────┐      ┌───────┐
//    │ esc  │  f1  │  f2  │ f3 │ f4 │ f5 │ f6 │ f7 │ f8 │ f9 │ f10  │  f11  │ f12  │ del  │      │ DF(1) │
//    ├──────┼──────┼──────┼────┼────┼────┼────┼────┼────┼────┼──────┼───────┼──────┼──────┤      ├───────┤
//    │  `   │  1   │  2   │ 3  │ 4  │ 5  │ 6  │ 7  │ 8  │ 9  │  0   │   -   │  =   │ bspc │      │ home  │
//    ├──────┼──────┼──────┼────┼────┼────┼────┼────┼────┼────┼──────┼───────┼──────┼──────┤      ├───────┤
//    │ tab  │  q   │  w   │ e  │ r  │ t  │ y  │ u  │ i  │ o  │  p   │   [   │  ]   │  \   │      │ pgup  │
//    ├──────┼──────┼──────┼────┼────┼────┼────┼────┼────┼────┼──────┼───────┼──────┴──────┤      ├───────┤
//    │ caps │  a   │  s   │ d  │ f  │ g  │ h  │ j  │ k  │ l  │  ;   │   '   │     ent     │      │ pgdn  │
//    ├──────┴──────┼──────┼────┼────┼────┼────┼────┼────┼────┼──────┼───────┼─────────────┼──────┼───────┘
//    │    lsft     │  z   │ x  │ c  │ v  │ b  │ n  │ m  │ ,  │  .   │   /   │    rsft     │  up  │
//    ├──────┬──────┼──────┼────┴────┴────┴────┴────┴────┴────┼──────┼───────┼──────┬──────┼──────┼───────┐
//    │ lctl │ lgui │ lalt │               spc                │ ralt │ MO(3) │ rctl │ left │ down │ rght  │
//    └──────┴──────┴──────┴──────────────────────────────────┴──────┴───────┴──────┴──────┴──────┴───────┘
[BASE] = LAYOUT_ansi_82(
  KC_ESC  , KC_F1   , KC_F2   , KC_F3 , KC_F4 , KC_F5 , KC_F6 , KC_F7 , KC_F8 , KC_F9   , KC_F10  , KC_F11  , KC_F12  , KC_DEL  ,           DF(1)  ,
  KC_GRV  , KC_1    , KC_2    , KC_3  , KC_4  , KC_5  , KC_6  , KC_7  , KC_8  , KC_9    , KC_0    , KC_MINS , KC_EQL  , KC_BSPC ,           KC_HOME,
  KC_TAB  , KC_Q    , KC_W    , KC_E  , KC_R  , KC_T  , KC_Y  , KC_U  , KC_I  , KC_O    , KC_P    , KC_LBRC , KC_RBRC , KC_BSLS ,           KC_PGUP,
  KC_CAPS , KC_A    , KC_S    , KC_D  , KC_F  , KC_G  , KC_H  , KC_J  , KC_K  , KC_L    , KC_SCLN , KC_QUOT ,            KC_ENT ,           KC_PGDN,
  KC_LSFT           , KC_Z    , KC_X  , KC_C  , KC_V  , KC_B  , KC_N  , KC_M  , KC_COMM , KC_DOT  , KC_SLSH ,           KC_RSFT , KC_UP            ,
  KC_LCTL , KC_LGUI , KC_LALT ,                         KC_SPC                          , KC_RALT , MO(3)   , KC_RCTL , KC_LEFT , KC_DOWN , KC_RGHT
),

//    ┌──────┬───────────┬───────────┬───────────┬───────────┬────┬───────┬────┬───────────┬───────────┬───────────┬─────────────┬─────┬───────┐      ┌───────┐
//    │ esc  │    f1     │    f2     │    f3     │    f4     │ f5 │  f6   │ f7 │    f8     │    f9     │    f10    │     f11     │ f12 │ TG(5) │      │ DF(0) │
//    ├──────┼───────────┼───────────┼───────────┼───────────┼────┼───────┼────┼───────────┼───────────┼───────────┼─────────────┼─────┼───────┤      ├───────┤
//    │  `   │     1     │     2     │     3     │     4     │ 5  │   6   │ =  │     7     │     8     │     9     │      0      │  -  │  no   │      │ TG(2) │
//    ├──────┼───────────┼───────────┼───────────┼───────────┼────┼───────┼────┼───────────┼───────────┼───────────┼─────────────┼─────┼───────┤      ├───────┤
//    │ S(,) │     q     │     w     │     e     │     r     │ t  │ TD(0) │ y  │     u     │     i     │     o     │      p      │  p  │   \   │      │ TG(3) │
//    ├──────┼───────────┼───────────┼───────────┼───────────┼────┼───────┼────┼───────────┼───────────┼───────────┼─────────────┼─────┴───────┤      ├───────┤
//    │ f13  │ LCTL_T(a) │ LSFT_T(s) │ LGUI_T(d) │ LALT_T(f) │ g  │  no   │ h  │ RALT_T(j) │ RGUI_T(k) │ RSFT_T(l) │  RCTL_T(;)  │     ent     │      │ TG(4) │
//    ├──────┴───────────┼───────────┼───────────┼───────────┼────┼───────┼────┼───────────┼───────────┼───────────┼─────────────┼─────────────┼──────┼───────┘
//    │        '         │     z     │     x     │     c     │ v  │   b   │ no │     n     │     m     │     b     │      y      │      /      │  up  │
//    ├──────┬───────────┼───────────┼───────────┴───────────┴────┴───────┴────┴───────────┴───────────┼───────────┼─────────────┼─────┬───────┼──────┼───────┐
//    │ lctl │   MO(4)   │   MO(3)   │                          LT(NAV, spc)                           │   lsft    │ LT(6, bspc) │ del │ left  │ down │ rght  │
//    └──────┴───────────┴───────────┴─────────────────────────────────────────────────────────────────┴───────────┴─────────────┴─────┴───────┴──────┴───────┘
[BASEMOD] = LAYOUT_ansi_82(
  KC_ESC     , KC_F1        , KC_F2        , KC_F3        , KC_F4        , KC_F5 , KC_F6 , KC_F7  , KC_F8        , KC_F9        , KC_F10       , KC_F11          , KC_F12  , TG(5)   ,           DF(0)  ,
  KC_GRV     , KC_1         , KC_2         , KC_3         , KC_4         , KC_5  , KC_6  , KC_EQL , KC_7         , KC_8         , KC_9         , KC_0            , KC_MINS , KC_NO   ,           TG(2)  ,
  S(KC_COMM) , KC_Q         , KC_W         , KC_E         , KC_R         , KC_T  , TD(0) , KC_Y   , KC_U         , KC_I         , KC_O         , KC_P            , KC_P    , KC_BSLS ,           TG(3)  ,
  KC_F13     , LCTL_T(KC_A) , LSFT_T(KC_S) , LGUI_T(KC_D) , LALT_T(KC_F) , KC_G  , KC_NO , KC_H   , RALT_T(KC_J) , RGUI_T(KC_K) , RSFT_T(KC_L) , RCTL_T(KC_SCLN) ,            KC_ENT ,           TG(4)  ,
  KC_QUOT                   , KC_Z         , KC_X         , KC_C         , KC_V  , KC_B  , KC_NO  , KC_N         , KC_M         , KC_B         , KC_Y            ,           KC_SLSH , KC_UP            ,
  KC_LCTL    , MO(4)        , MO(3)        ,                                  LT(NAV, KC_SPC)                                   , KC_LSFT      , LT(6, KC_BSPC)  , KC_DEL  , KC_LEFT , KC_DOWN , KC_RGHT
),

//    ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬──────┐      ┌───────┐
//    │   esc   │   f1    │   f2    │   f3    │   f4    │   f5    │   f6    │   f7    │   f8    │   f9    │   f10   │   f11   │   f12   │ del  │      │ TG(2) │
//    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼──────┤      ├───────┤
//    │ RALT(`) │ RALT(1) │ RALT(2) │ RALT(3) │ RALT(4) │ RALT(5) │ RALT(6) │ RALT(=) │ RALT(7) │ RALT(8) │ RALT(9) │ RALT(0) │ RALT(-) │  no  │      │       │
//    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼──────┤      ├───────┤
//    │  S(,)   │   esc   │ LCTL(z) │ LCTL(x) │ LCTL(v) │ LCTL(b) │   no    │   no    │  S(9)   │  S([)   │    [    │  S(5)   │   no    │  no  │      │  no   │
//    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┴──────┤      ├───────┤
//    │   f13   │  lctl   │  lsft   │  lgui   │  lalt   │ SGUI(d) │   no    │   no    │  left   │  down   │   up    │  rght   │      ent       │      │  no   │
//    ├─────────┴─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼────────────────┼──────┼───────┘
//    │         /         │   no    │   no    │   no    │   tab   │   no    │   no    │  S(,)   │    =    │  S(1)   │  kp_*   │      kp_/      │  up  │
//    ├─────────┬─────────┼─────────┼─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┼─────────┼─────────┼─────────┬──────┼──────┼───────┐
//    │  lctl   │  lgui   │   no    │                                MO(5)                                │  MO(5)  │  bspc   │   del   │ left │ down │ rght  │
//    └─────────┴─────────┴─────────┴─────────────────────────────────────────────────────────────────────┴─────────┴─────────┴─────────┴──────┴──────┴───────┘
[NAV] = LAYOUT_ansi_82(
  KC_ESC       , KC_F1      , KC_F2      , KC_F3      , KC_F4      , KC_F5      , KC_F6      , KC_F7        , KC_F8      , KC_F9      , KC_F10     , KC_F11     , KC_F12        , KC_DEL  ,           TG(2)  ,
  RALT(KC_GRV) , RALT(KC_1) , RALT(KC_2) , RALT(KC_3) , RALT(KC_4) , RALT(KC_5) , RALT(KC_6) , RALT(KC_EQL) , RALT(KC_7) , RALT(KC_8) , RALT(KC_9) , RALT(KC_0) , RALT(KC_MINS) , KC_NO   ,           KC_TRNS,
  S(KC_COMM)   , KC_ESC     , LCTL(KC_Z) , LCTL(KC_X) , LCTL(KC_V) , LCTL(KC_B) , KC_NO      , KC_NO        , S(KC_9)    , S(KC_LBRC) , KC_LBRC    , S(KC_5)    , KC_NO         , KC_NO   ,           KC_NO  ,
  KC_F13       , KC_LCTL    , KC_LSFT    , KC_LGUI    , KC_LALT    , SGUI(KC_D) , KC_NO      , KC_NO        , KC_LEFT    , KC_DOWN    , KC_UP      , KC_RIGHT   ,                  KC_ENT ,           KC_NO  ,
  KC_SLSH                   , KC_NO      , KC_NO      , KC_NO      , KC_TAB     , KC_NO      , KC_NO        , S(KC_COMM) , KC_EQL     , S(KC_1)    , KC_PAST    ,                 KC_PSLS , KC_UP            ,
  KC_LCTL      , KC_LGUI    , KC_NO      ,                                           MO(5)                                            , MO(5)      , KC_BSPC    , KC_DEL        , KC_LEFT , KC_DOWN , KC_RGHT
),

//    ┌──────┬───────────────┬───────────────┬───────────────┬───────────────┬─────────┬─────┬──────┬──────┬──────┬──────┬──────┬──────┬─────┐     ┌───────┐
//    │      │               │               │               │               │         │     │ mprv │ mply │ mnxt │ mute │ vold │ volu │     │     │ TG(3) │
//    ├──────┼───────────────┼───────────────┼───────────────┼───────────────┼─────────┼─────┼──────┼──────┼──────┼──────┼──────┼──────┼─────┤     ├───────┤
//    │  no  │      no       │      no       │      no       │      no       │   no    │ no  │  no  │  no  │  no  │  no  │  no  │  no  │ no  │     │       │
//    ├──────┼───────────────┼───────────────┼───────────────┼───────────────┼─────────┼─────┼──────┼──────┼──────┼──────┼──────┼──────┼─────┤     ├───────┤
//    │ S(,) │      esc      │    LCTL(z)    │    LCTL(x)    │    LCTL(v)    │ LCTL(b) │ no  │  no  │  5   │  6   │  7   │  8   │  no  │ no  │     │       │
//    ├──────┼───────────────┼───────────────┼───────────────┼───────────────┼─────────┼─────┼──────┼──────┼──────┼──────┼──────┼──────┴─────┤     ├───────┤
//    │ f13  │ OSM(MOD_LCTL) │ OSM(MOD_LSFT) │ OSM(MOD_LGUI) │ OSM(MOD_LALT) │   no    │ no  │  -   │  1   │  2   │  3   │  4   │  LSFT(=)   │     │       │
//    ├──────┴───────────────┼───────────────┼───────────────┼───────────────┼─────────┼─────┼──────┼──────┼──────┼──────┼──────┼────────────┼─────┼───────┘
//    │          /           │      no       │      no       │      no       │   tab   │ no  │  no  │  9   │  0   │  no  │  no  │     '      │     │
//    ├──────┬───────────────┼───────────────┼───────────────┴───────────────┴─────────┴─────┴──────┴──────┴──────┼──────┼──────┼──────┬─────┼─────┼───────┐
//    │ lctl │     lgui      │     bspc      │                                spc                                 │ lsft │ bspc │ del  │     │     │       │
//    └──────┴───────────────┴───────────────┴────────────────────────────────────────────────────────────────────┴──────┴──────┴──────┴─────┴─────┴───────┘
[NUM] = LAYOUT_ansi_82(
  KC_TRNS    , KC_TRNS       , KC_TRNS       , KC_TRNS       , KC_TRNS       , KC_TRNS    , KC_TRNS , KC_MPRV , KC_MPLY , KC_MNXT , KC_MUTE , KC_VOLD , KC_VOLU , KC_TRNS ,           TG(3)  ,
  KC_NO      , KC_NO         , KC_NO         , KC_NO         , KC_NO         , KC_NO      , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,           KC_TRNS,
  S(KC_COMM) , KC_ESC        , LCTL(KC_Z)    , LCTL(KC_X)    , LCTL(KC_V)    , LCTL(KC_B) , KC_NO   , KC_NO   , KC_5    , KC_6    , KC_7    , KC_8    , KC_NO   , KC_NO   ,           KC_TRNS,
  KC_F13     , OSM(MOD_LCTL) , OSM(MOD_LSFT) , OSM(MOD_LGUI) , OSM(MOD_LALT) , KC_NO      , KC_NO   , KC_MINS , KC_1    , KC_2    , KC_3    , KC_4    ,      LSFT(KC_EQL) ,           KC_TRNS,
  KC_SLSH                    , KC_NO         , KC_NO         , KC_NO         , KC_TAB     , KC_NO   , KC_NO   , KC_9    , KC_0    , KC_NO   , KC_NO   ,           KC_QUOT , KC_TRNS          ,
  KC_LCTL    , KC_LGUI       , KC_BSPC       ,                                       KC_SPC                                       , KC_LSFT , KC_BSPC , KC_DEL  , KC_TRNS , KC_TRNS , KC_TRNS
),

//    ┌──────┬───────────────┬───────────────┬───────────────┬───────────────┬─────────┬─────────┬──────┬──────┬──────┬──────┬──────┬──────┬─────┐     ┌───────┐
//    │      │     bRID      │     bRIU      │      f3       │      f4       │ RGB_VAD │ RGB_VAI │ mprv │ mply │ mnxt │ mute │ vold │ volu │     │     │ TG(4) │
//    ├──────┼───────────────┼───────────────┼───────────────┼───────────────┼─────────┼─────────┼──────┼──────┼──────┼──────┼──────┼──────┼─────┤     ├───────┤
//    │  no  │      no       │      no       │      no       │      no       │   no    │   no    │  no  │  no  │  no  │  no  │  no  │  no  │ no  │     │       │
//    ├──────┼───────────────┼───────────────┼───────────────┼───────────────┼─────────┼─────────┼──────┼──────┼──────┼──────┼──────┼──────┼─────┤     ├───────┤
//    │ S(,) │      esc      │    LCTL(z)    │    LCTL(x)    │    LCTL(v)    │ LCTL(b) │   no    │  no  │ S(2) │ S(3) │ S(4) │ S(5) │  no  │ no  │     │       │
//    ├──────┼───────────────┼───────────────┼───────────────┼───────────────┼─────────┼─────────┼──────┼──────┼──────┼──────┼──────┼──────┴─────┤     ├───────┤
//    │ f13  │ OSM(MOD_LCTL) │ OSM(MOD_LSFT) │ OSM(MOD_LGUI) │ OSM(MOD_LALT) │   no    │   no    │  -   │ S(9) │ S([) │  [   │ S(,) │  LSFT(=)   │     │       │
//    ├──────┴───────────────┼───────────────┼───────────────┼───────────────┼─────────┼─────────┼──────┼──────┼──────┼──────┼──────┼────────────┼─────┼───────┘
//    │          /           │      no       │      no       │      no       │   tab   │   no    │  no  │  no  │  no  │  no  │  no  │     '      │     │
//    ├──────┬───────────────┼───────────────┼───────────────┴───────────────┴─────────┴─────────┴──────┴──────┴──────┼──────┼──────┼──────┬─────┼─────┼───────┐
//    │  no  │      no       │     MO(5)     │                                 MO(3)                                  │ lsft │ bspc │ del  │     │     │       │
//    └──────┴───────────────┴───────────────┴────────────────────────────────────────────────────────────────────────┴──────┴──────┴──────┴─────┴─────┴───────┘
[SYM] = LAYOUT_ansi_82(
  KC_TRNS    , KC_BRID       , KC_BRIU       , KC_F3         , KC_F4         , RGB_VAD    , RGB_VAI , KC_MPRV , KC_MPLY , KC_MNXT    , KC_MUTE , KC_VOLD    , KC_VOLU , KC_TRNS ,           TG(4)  ,
  KC_NO      , KC_NO         , KC_NO         , KC_NO         , KC_NO         , KC_NO      , KC_NO   , KC_NO   , KC_NO   , KC_NO      , KC_NO   , KC_NO      , KC_NO   , KC_NO   ,           KC_TRNS,
  S(KC_COMM) , KC_ESC        , LCTL(KC_Z)    , LCTL(KC_X)    , LCTL(KC_V)    , LCTL(KC_B) , KC_NO   , KC_NO   , S(KC_2) , S(KC_3)    , S(KC_4) , S(KC_5)    , KC_NO   , KC_NO   ,           KC_TRNS,
  KC_F13     , OSM(MOD_LCTL) , OSM(MOD_LSFT) , OSM(MOD_LGUI) , OSM(MOD_LALT) , KC_NO      , KC_NO   , KC_MINS , S(KC_9) , S(KC_LBRC) , KC_LBRC , S(KC_COMM) ,      LSFT(KC_EQL) ,           KC_TRNS,
  KC_SLSH                    , KC_NO         , KC_NO         , KC_NO         , KC_TAB     , KC_NO   , KC_NO   , KC_NO   , KC_NO      , KC_NO   , KC_NO      ,           KC_QUOT , KC_TRNS          ,
  KC_NO      , KC_NO         , MO(5)         ,                                         MO(3)                                         , KC_LSFT , KC_BSPC    , KC_DEL  , KC_TRNS , KC_TRNS , KC_TRNS
),

//    ┌──────┬──────┬───────────────┬───────────────┬───────────────┬───────────────┬─────┬──────┬──────┬──────┬──────┬──────┬─────┬─────┐     ┌───────┐
//    │      │      │               │               │               │               │     │      │      │      │      │      │     │     │     │ TG(5) │
//    ├──────┼──────┼───────────────┼───────────────┼───────────────┼───────────────┼─────┼──────┼──────┼──────┼──────┼──────┼─────┼─────┤     ├───────┤
//    │  no  │  no  │      no       │      no       │      no       │      no       │ no  │  no  │  no  │  no  │  no  │  no  │ no  │ no  │     │       │
//    ├──────┼──────┼───────────────┼───────────────┼───────────────┼───────────────┼─────┼──────┼──────┼──────┼──────┼──────┼─────┼─────┤     ├───────┤
//    │  no  │ esc  │ LCTL(LSFT(z)) │ LCTL(LSFT(x)) │ LCTL(LSFT(v)) │ LCTL(LSFT(b)) │ no  │  no  │  no  │  no  │  no  │  no  │ no  │ no  │     │       │
//    ├──────┼──────┼───────────────┼───────────────┼───────────────┼───────────────┼─────┼──────┼──────┼──────┼──────┼──────┼─────┴─────┤     ├───────┤
//    │  no  │ aCL0 │     wh_d      │     wh_u      │     aCL2      │      no       │ no  │ S(-) │ home │ pgdn │ pgup │ end  │  LSFT(4)  │     │       │
//    ├──────┴──────┼───────────────┼───────────────┼───────────────┼───────────────┼─────┼──────┼──────┼──────┼──────┼──────┼───────────┼─────┼───────┘
//    │    lsft     │      no       │      no       │      no       │      tab      │ no  │  no  │  no  │  no  │  no  │  no  │     '     │     │
//    ├──────┬──────┼───────────────┼───────────────┴───────────────┴───────────────┴─────┴──────┴──────┴──────┼──────┼──────┼─────┬─────┼─────┼───────┐
//    │ lctl │ lgui │     lalt      │                                  TG(5)                                   │ lsft │ bspc │ del │     │     │       │
//    └──────┴──────┴───────────────┴──────────────────────────────────────────────────────────────────────────┴──────┴──────┴─────┴─────┴─────┴───────┘
[NAVMOD] = LAYOUT_ansi_82(
  KC_TRNS , KC_TRNS , KC_TRNS          , KC_TRNS          , KC_TRNS          , KC_TRNS          , KC_TRNS , KC_TRNS    , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,           TG(5)  ,
  KC_NO   , KC_NO   , KC_NO            , KC_NO            , KC_NO            , KC_NO            , KC_NO   , KC_NO      , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,           KC_TRNS,
  KC_NO   , KC_ESC  , LCTL(LSFT(KC_Z)) , LCTL(LSFT(KC_X)) , LCTL(LSFT(KC_V)) , LCTL(LSFT(KC_B)) , KC_NO   , KC_NO      , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,           KC_TRNS,
  KC_NO   , KC_ACL0 , KC_WH_D          , KC_WH_U          , KC_ACL2          , KC_NO            , KC_NO   , S(KC_MINS) , KC_HOME , KC_PGDN , KC_PGUP , KC_END  ,        LSFT(KC_4) ,           KC_TRNS,
  KC_LSFT           , KC_NO            , KC_NO            , KC_NO            , KC_TAB           , KC_NO   , KC_NO      , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,           KC_QUOT , KC_TRNS          ,
  KC_LCTL , KC_LGUI , KC_LALT          ,                                               TG(5)                                               , KC_LSFT , KC_BSPC , KC_DEL  , KC_TRNS , KC_TRNS , KC_TRNS
),

//    ┌─────┬───────┬──────┬──────┬──────┬─────────┬─────────┬──────┬──────┬──────┬──────┬──────┬──────┬─────┐     ┌───────┐
//    │     │ bRID  │ bRIU │  f3  │  f4  │ RGB_VAD │ RGB_VAI │ mprv │ mply │ mnxt │ mute │ vold │ volu │     │     │ TG(6) │
//    ├─────┼───────┼──────┼──────┼──────┼─────────┼─────────┼──────┼──────┼──────┼──────┼──────┼──────┼─────┤     ├───────┤
//    │     │       │      │      │      │         │         │      │      │      │      │      │      │     │     │       │
//    ├─────┼───────┼──────┼──────┼──────┼─────────┼─────────┼──────┼──────┼──────┼──────┼──────┼──────┼─────┤     ├───────┤
//    │     │  esc  │ btn3 │ btn2 │ btn1 │         │         │      │      │      │      │      │      │     │     │       │
//    ├─────┼───────┼──────┼──────┼──────┼─────────┼─────────┼──────┼──────┼──────┼──────┼──────┼──────┴─────┤     ├───────┤
//    │     │ aCL0  │ wh_d │ wh_u │ aCL1 │         │         │      │ ms_l │ ms_d │ ms_u │ ms_r │            │     │       │
//    ├─────┴───────┼──────┼──────┼──────┼─────────┼─────────┼──────┼──────┼──────┼──────┼──────┼────────────┼─────┼───────┘
//    │             │      │      │      │         │         │      │      │      │      │      │            │     │
//    ├─────┬───────┼──────┼──────┴──────┴─────────┴─────────┴──────┴──────┴──────┼──────┼──────┼──────┬─────┼─────┼───────┐
//    │     │ TG(6) │  no  │                         aCL2                         │ bspc │ del  │      │     │     │       │
//    └─────┴───────┴──────┴──────────────────────────────────────────────────────┴──────┴──────┴──────┴─────┴─────┴───────┘
[MOUSE] = LAYOUT_ansi_82(
  KC_TRNS , KC_BRID , KC_BRIU , KC_F3   , KC_F4   , RGB_VAD , RGB_VAI , KC_MPRV , KC_MPLY , KC_MNXT , KC_MUTE , KC_VOLD , KC_VOLU , KC_TRNS ,           TG(6)  ,
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,           KC_TRNS,
  KC_TRNS , KC_ESC  , KC_BTN3 , KC_BTN2 , KC_BTN1 , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,           KC_TRNS,
  KC_TRNS , KC_ACL0 , KC_WH_D , KC_WH_U , KC_ACL1 , KC_TRNS , KC_TRNS , KC_TRNS , KC_MS_L , KC_MS_D , KC_MS_U , KC_MS_R ,           KC_TRNS ,           KC_TRNS,
  KC_TRNS           , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,           KC_TRNS , KC_TRNS          ,
  KC_TRNS , TG(6)   , KC_NO   ,                               KC_ACL2                               , KC_BSPC , KC_DEL  , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS
)
};

// clang-format on

tap_dance_action_t tap_dance_actions[] = {[0] = ACTION_TAP_DANCE_DOUBLE(LSFT(KC_9), LSFT(KC_0)), [1] = ACTION_TAP_DANCE_DOUBLE(LSFT(KC_LBRC), LSFT(KC_RBRC)), [2] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC), [3] = ACTION_TAP_DANCE_DOUBLE(LSFT(KC_COMM), LSFT(KC_DOT))};

enum combo_events {
    CAPS_LOCK_COMBO,
    SHIFT_GUI_COMBO,
    CTRL_SHIFT_COMBO,
    CTRL_GUI_COMBO,
    CTRL_R_COMBO,
    NAV_SHIFT_COMBO, // New combo
    COMBO_LENGTH
};

// Define the key combinations
const uint16_t PROGMEM combo_g_h[]       = {KC_G, KC_H, COMBO_END};
const uint16_t PROGMEM combo_lsft_lgui[] = {OSM(MOD_LSFT), OSM(MOD_LGUI), COMBO_END};
const uint16_t PROGMEM combo_lctl_lsft[] = {OSM(MOD_LCTL), OSM(MOD_LSFT), COMBO_END};
const uint16_t PROGMEM combo_lctl_lgui[] = {OSM(MOD_LCTL), OSM(MOD_LGUI), COMBO_END};
const uint16_t PROGMEM combo_lctrl_r[]   = {LCTL_T(KC_A), LSFT_T(KC_S), COMBO_END};
const uint16_t PROGMEM combo_lt_shift[]  = {LT(NAV, KC_SPC), KC_LSFT, COMBO_END}; // New combo

// Define the combo actions
combo_t key_combos[COMBO_LENGTH] = {
    [CAPS_LOCK_COMBO] = COMBO(combo_g_h, KC_CAPS),
    [SHIFT_GUI_COMBO] = COMBO(combo_lsft_lgui, OSM(MOD_LSFT | MOD_LGUI)),
    [CTRL_SHIFT_COMBO] = COMBO(combo_lctl_lsft, OSM(MOD_LCTL | MOD_LSFT)),
    [CTRL_GUI_COMBO] = COMBO(combo_lctl_lgui, OSM(MOD_LCTL | MOD_LGUI)),
    [CTRL_R_COMBO] = COMBO(combo_lctrl_r, LCTL(LSFT(KC_NO))),
    [NAV_SHIFT_COMBO] = COMBO(combo_lt_shift, MO(NAVMOD))
};

static bool ik_ralt_pressed = false; // For combo to layer NAVMOD
bool        combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (combo_index) {
        case NAV_SHIFT_COMBO:

            if (!ik_ralt_pressed) {
                return false;
            }
            break;
    }

    return true;
}
void process_combo_event(uint16_t combo_index, bool pressed) {}

#define KC_LBRACKET KC_LBRC
#define KC_RBRACKET KC_RBRC
#define KC_BSLASH KC_BACKSLASH

// ' "
const key_override_t override_quote_ast   = ko_make_with_layers_and_negmods(MOD_MASK_SA, KC_QUOTE, S(KC_8), 0xFFFF, 0);
const key_override_t override_quote_grave = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_QUOTE, KC_GRAVE, 0xFFFF, 0);

// ({[]})
const key_override_t override_shift_9_0               = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, S(KC_9), S(KC_0), 0xFFFF, 0);
const key_override_t override_shift_lbracket_rbracket = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, S(KC_LBRACKET), S(KC_RBRACKET), 0xFFFF, 0);
const key_override_t override_lbracket_rbracket       = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_LBRACKET, KC_RBRACKET, 0xFFFF, 0);

// < > = ~
const key_override_t override_shift_comma_equal = ko_make_with_layers_and_negmods(MOD_MASK_SA, S(KC_COMMA), KC_EQUAL, 0xFFFE, 0);
const key_override_t override_shift_comma_dot   = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, S(KC_COMMA), S(KC_DOT), 0xFFFF, 0);
const key_override_t override_shift_comma_grave = ko_make_with_layers_and_negmods(MOD_MASK_ALT, S(KC_COMMA), S(KC_GRAVE), 0xFFFE, 0);

// /\&|
const key_override_t override_slash_shift7       = ko_make_with_layers_and_negmods(MOD_MASK_SA, KC_SLASH, S(KC_7), 0xFFFE, 0);
const key_override_t override_slash_bslash_shift = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_SLASH, KC_BSLASH, 0xFFFE, 0);
const key_override_t override_slash_bslash_ag    = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_SLASH, S(KC_BSLASH), 0xFFFE, 0);

// .,?!
const key_override_t override_f13_shift1      = ko_make_with_layers_and_negmods(MOD_MASK_SA, KC_F13, S(KC_1), 0xFFFE, 0);
const key_override_t override_f13_comma       = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_F13, KC_COMMA, 0xFFFE, 0);
const key_override_t override_f13_shift_slash = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_F13, S(KC_SLASH), 0xFFFF, 0);
const key_override_t override_f13_dot         = ko_make_basic(0, KC_F13, KC_DOT);

// Create an array of pointers to the key overrides
const key_override_t *key_overrides[] = {
    &override_quote_ast,
    &override_quote_grave,
    &override_shift_9_0,
    &override_shift_lbracket_rbracket,
    &override_lbracket_rbracket,
    &override_shift_comma_equal,
    &override_shift_comma_dot,
    &override_slash_shift7,
    &override_slash_bslash_shift,
    &override_slash_bslash_ag,
    &override_shift_comma_grave,
    &override_f13_shift1,
    &override_f13_comma,
    &override_f13_shift_slash,
    &override_f13_dot,
    NULL // Null terminate the array
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) {
        return false;
    }
    if (record->event.key.row * MATRIX_COLS + record->event.key.col == IK_RALT) {
        ik_ralt_pressed = record->event.pressed;
    }
    /* #ifdef CONSOLE_ENABLE */
    /*     print("active modif "); */
    /*     dprint("Debug enabled") */
    /*     uprintf("%s active_modifiers" , active_modifiers); */
    /* #endif */
    /* active_modifiers = get_mods() | get_oneshot_mods() ;  */
    /* dprintf("\n\n\npressed kc: 0x%04X\n", keycode); */
    /* dprintf("LCTL_T: 0x%04X, RCTL_T: 0x%04X, LCTL: 0x%04X\n", LCTL_T(KC_A),RCTL_T(KC_SCLN), KC_LCTL); */
    /*     dprintf("LSFT_T(KC_S): 0x%04X, kc_s: 0x%04X\n\n\n", LSFT_T(KC_S), KC_S); */
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    // To change tap term per key
    return TAPPING_TERM;
    /* switch (keycode) { */
    /*     case SFT_T(KC_SPC): */
    /*         return TAPPING_TERM + 1250; */
    /*     case LT(1, KC_GRV): */
    /*         return 130; */
    /*     default: */
    /*         return TAPPING_TERM; */
    /* } */
}
void matrix_scan_user(void) {
    achordion_task();
}
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // RGB_MATRIX_INDICATOR_SET_COLOR(index, red, green, blue);

    uint8_t mod_state = get_mods() | get_oneshot_mods();
    /* get_mods(); */
    if (mod_state) {
        if (mod_state & MOD_BIT(KC_RALT)) { // Right Alt
            rgb_matrix_set_color(IK_F9, 255, 255, 255);
        }
        if (mod_state & MOD_BIT(KC_RGUI)) { // Right GUI
            rgb_matrix_set_color(IK_F10, 255, 255, 255);
        }
        if (mod_state & MOD_BIT(KC_RSFT)) { // Right Shift
            rgb_matrix_set_color(IK_F11, 255, 255, 255);
        }
        if (mod_state & MOD_BIT(KC_RCTL)) { // Right Control
            rgb_matrix_set_color(IK_F12, 255, 255, 255);
        }

        // Left side modifiers (using explicit LEFT masks)
        if (mod_state & MOD_BIT(KC_LALT)) { // Left Alt
            rgb_matrix_set_color(IK_F4, 255, 255, 255);
        }
        if (mod_state & MOD_BIT(KC_LGUI)) { // Left GUI
            rgb_matrix_set_color(IK_F3, 255, 255, 255);
        }
        if (mod_state & MOD_BIT(KC_LSFT)) { // Left Shift
            rgb_matrix_set_color(IK_F2, 255, 255, 255);
        }
        if (mod_state & MOD_BIT(KC_LCTL)) { // Left Control
            rgb_matrix_set_color(IK_F1, 255, 255, 255);
        }
    }
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case 6:
            rgb_matrix_sethsv(HSV_LAYOUT_6);
            rgb_matrix_set_color(HOME_KEY_LED_INDEX, RGB_LAYOUT_0);
            break;
        case 5:
            rgb_matrix_sethsv(HSV_LAYOUT_5);
            rgb_matrix_set_color(HOME_KEY_LED_INDEX, RGB_LAYOUT_0);
            break;
        case 4:
            rgb_matrix_sethsv(HSV_LAYOUT_4);
            rgb_matrix_set_color(HOME_KEY_LED_INDEX, RGB_LAYOUT_0);
            break;
        case 3:
            rgb_matrix_sethsv(HSV_LAYOUT_3); // Cyan
            rgb_matrix_set_color(HOME_KEY_LED_INDEX, RGB_LAYOUT_0);
            break;
        case 2:
            /* rgb_matrix_set_color(i, RGB_BLUE); */
            rgb_matrix_sethsv(HSV_LAYOUT_2); // Red
            rgb_matrix_set_color(HOME_KEY_LED_INDEX, RGB_LAYOUT_0);
            break;
        case 1:
            /* rgb_matrix_set_color(i, RGB_YELLOW); */
            rgb_matrix_sethsv(HSV_LAYOUT_1); // Green
            rgb_matrix_set_color(IK_INSERT, RGB_LAYOUT_0);
            break;
        case 0:
            /* rgb_matrix_set_color(i, RGB_GREEN); */
            rgb_matrix_sethsv(HSV_LAYOUT_0); // Purple

            rgb_matrix_set_color(IK_INSERT, RGB_LAYOUT_1);
            break;
        default:
            break;
    }
    for (uint8_t i = led_min; i < led_max; i++) {
        if (host_keyboard_led_state().caps_lock) {
            if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
                rgb_matrix_set_color(i, 255, 255, 255);
            }
        }
    }
    return false;
}
