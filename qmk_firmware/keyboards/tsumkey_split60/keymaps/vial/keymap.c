#include QMK_KEYBOARD_H
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {};

enum custom_keycodes {
    ROT_R15 = SAFE_RANGE,
    ROT_L15
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ROT_R15:
            if (record->event.pressed) {
                angle += 15;
                // 必要に応じて最大値・最小値の制御
            }
            return false;
        case ROT_L15:
            if (record->event.pressed) {
                angle -= 15;
                // 必要に応じて最大値・最小値の制御
            }
            return false;
    }
    return true;
}