#include "Input.h"
#include <windows.h>
#include "DxLib.h"

int Key[256];
MouseCondition mc;

int UpdateKey() {
    char tmpkey[256];
    DxLib::GetHitKeyStateAll(tmpkey);
    for (int i = 0; i < 256; i++) {
        if (tmpkey[i] != 0) {
            Key[i]++;
        } else {
            Key[i] = 0;
        }
    }
    return 0;
}

int GetKey(const int KeyCode) {
    return Key[KeyCode];
}

int mouseClick() {
    if (DxLib::GetMouseInput() & MOUSE_INPUT_LEFT) {
        mc = Click_L;
    } else if (DxLib::GetMouseInput() & MOUSE_INPUT_RIGHT) {
        mc = Click_R;
    } else {
        mc = NoClick;
    }
    return mc;
}
