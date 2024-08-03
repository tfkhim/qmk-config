/* This file is part of https://github.com/tfkhim/qmk-config
 *
 * Copyright (c) 2023 Thomas Himmelstoss
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
#include QMK_KEYBOARD_H
#include "keymap_german.h"

enum layers {
    _QWERTZ = 0,
    _SYM_LEFT,
    _SYM_RIGHT,
    _NAV,
    _NUM,
    _FUNCTION,
};

#define DE_DOTS RALT(DE_DOT)

#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define NUM      MO(_NUM)
#define FKEYS    MO(_FUNCTION)

#define GUI_ESC    MT(MOD_LGUI, KC_ESC)
#define GUI_ADIA   MT(MOD_RGUI, DE_ADIA)
#define CTL_ENT    MT(MOD_LCTL, KC_ENT)
#define NUM_SPC    LT(_NUM, KC_SPC)
#define SYM_BSPC   LT(_SYM_RIGHT, KC_BSPC)
#define SYM_DEL    LT(_SYM_LEFT, KC_DEL)
#define NAV_SPC    LT(_NAV, KC_SPC)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTZ
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Z  |   U  |   I  |   O  |   P  |   Ü    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |LGUI/Esc|   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  |   Ö  | RGUI/Ä |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Y  |   X  |   C  |   V  |   B  |      |      |  |      |F-keys|   N  |   M  |   ,  |   .  |   -  | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      | LAlt | Ctrl/| Space| Sym  |  | Sym  | Space| Ctrl | AltGr|      |
 *                        |      |      | Enter|      | Right|  | Left |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTZ] = LAYOUT(
      KC_TAB , DE_Q ,  DE_W   ,  DE_E  ,   DE_R ,   DE_T ,                                        DE_Z,   DE_U ,  DE_I ,   DE_O ,  DE_P , DE_UDIA,
     GUI_ESC , DE_A ,  DE_S   ,  DE_D  ,   DE_F ,   DE_G ,                                        DE_H,   DE_J ,  DE_K ,   DE_L ,DE_ODIA,GUI_ADIA,
     KC_LSFT , DE_Y ,  DE_X   ,  DE_C  ,   DE_V ,   DE_B , XXXXXXX, XXXXXXX, XXXXXXX,   FKEYS,    DE_N,   DE_M ,DE_COMM, DE_DOT ,DE_MINS, KC_RSFT,
                                XXXXXXX, KC_LALT, CTL_ENT, NUM_SPC,SYM_BSPC, SYM_DEL, NAV_SPC, KC_RCTL, KC_RALT, XXXXXXX
    ),

/*
 * Left Symbol Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  …   |  _   |  [   |  ]   |  ^   |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  \   |  /   |  {   |  }   |  *   |                              |      | Shift| Ctrl |  Alt |  GUI |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   #  |  $   |  |   |  ~   |  `   |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      | Space|      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM_LEFT] = LAYOUT(
     XXXXXXX , DE_DOTS, DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX , DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR,                                     XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
     XXXXXXX , DE_HASH, DE_DLR , DE_PIPE, DE_TILD, DE_GRV , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                 XXXXXXX, XXXXXXX, KC_ENT , _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

/*
 * Right Symbol Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |   !  |  <   |  >   |  =   |  &   |   ß    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  GUI |  Alt | Ctrl | Shift|      |                              |   ?  |  (   |  )   |  -   |  :   |   @    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |   +  |  %   |  "   |  '   |  ;   |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      | Space|      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM_RIGHT] = LAYOUT(
     XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     DE_EXLM, DE_LABK, DE_RABK,  DE_EQL, DE_AMPR,  DE_SS ,
     XXXXXXX , KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                                     DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN,  DE_AT ,
     XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN, XXXXXXX,
                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
    ),

/*
 * Nav Layer: Navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | PgUp | Bcksp|  ↑   | Del  |PgDown|                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | Home |  ←   |  ↓   |  →   | End  |                              |      | Shift| Ctrl |  Alt |  GUI |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  Esc |  Tab |  Ins | Enter| Undo |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      XXXXXXX, KC_PGUP, KC_BSPC,  KC_UP , KC_DEL , KC_PGDN,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END ,                                     XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
      XXXXXXX, KC_ESC , KC_TAB , KC_SPC , KC_ENT , KC_UNDO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                 XXXXXXX, XXXXXXX, KC_ENT , _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

/*
 * Num Layer: Numbers
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |   7  |   8  |   9  |   +  |    -   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  GUI |  Alt | Ctrl | Shift|      |                              |   .  |   4  |   5  |   6  |   ,  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |   :  |   1  |   2  |   3  |   ;  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |   0  |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NUM] = LAYOUT(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX,   DE_7 ,   DE_8 ,   DE_9 , DE_PLUS, DE_MINS,
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                                     DE_DOT ,   DE_4 ,   DE_5 ,   DE_6 , DE_COMM, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DE_COLN,   DE_1 ,   DE_2 ,   DE_3 , DE_SCLN, XXXXXXX,
                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,   DE_0 , XXXXXXX, XXXXXXX
    ),

/*
 * Function Layer: Function keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  F9  | F10  | F11  | F12  |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F5  |  F6  |  F7  |  F8  |      |                              |      | Shift| Ctrl |  Alt |  GUI |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FUNCTION] = LAYOUT(
      XXXXXXX,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , XXXXXXX,                                     XXXXXXX, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, XXXXXXX,
      XXXXXXX,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
};
