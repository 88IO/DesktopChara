#include "Screen.h"
#include "DxLib.h"
#include <windows.h>

Screen::Screen() {
    StartFlag_L = FALSE;
    mc = None;
}

int Screen::MouseClick() {
    if (DxLib::GetMouseInput() & MOUSE_INPUT_LEFT) {
        mc = Click_L;
    } else if (DxLib::GetMouseInput() & MOUSE_INPUT_RIGHT) {
        mc = Click_R;
    } else {
        mc = None;
    }
    return mc;
}

void Screen::MoveWindow() {
    GetCursorPos(&NowCursorPos);

    if (StartFlag_L == FALSE) {
        StartFlag_L = TRUE;
        StartCursorPos = NowCursorPos;
        DxLib::GetWindowPosition((int*)&StartWindowPos.x, (int*)&StartWindowPos.y);
    } else {
        DxLib::SetWindowPosition(
            StartWindowPos.x + NowCursorPos.x - StartCursorPos.x,
            StartWindowPos.y + NowCursorPos.y - StartCursorPos.y
        );
    }
}

void Screen::ContextMenu() {
    system("explorer command\\GodMode.{ED7BA470-8E54-465E-825C-99712043E01C}");
}

void Screen::Update() {
    switch (MouseClick()) {
    case MouseCondition::Click_L:
        MoveWindow();
        break;
    case MouseCondition::Click_R:
        ContextMenu();
        break;
    default:
        StartFlag_L = FALSE;
        break;
    }
}
