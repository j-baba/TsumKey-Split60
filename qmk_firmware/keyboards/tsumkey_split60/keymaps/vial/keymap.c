//#include QMK_KEYBOARD_H
//const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {};

#include QMK_KEYBOARD_H
#include <math.h>

// スクロール角度（初期値はズレ補正 -40°）
float scroll_angle_deg = -40.0f;

// カスタムキーコード
enum custom_keycodes {
    KEY_SCROLL_ROT_CW = SAFE_RANGE,    // +10度
    KEY_SCROLL_ROT_CCW,                // -10度
};

// キーマップ
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {};

// キー入力でスクロール角度を調整
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case KEY_SCROLL_ROT_CW:
                scroll_angle_deg += 10.0f;
                if (scroll_angle_deg > 180.0f) scroll_angle_deg -= 360.0f;
                return false;
            case KEY_SCROLL_ROT_CCW:
                scroll_angle_deg -= 10.0f;
                if (scroll_angle_deg < -180.0f) scroll_angle_deg += 360.0f;
                return false;
        }
    }
    return true;
}