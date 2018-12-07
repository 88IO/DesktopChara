#include "Screen.h"
#include "Input.h"
#include <windows.h>
#include "DxLib.h"

Screen::Screen() {
    StartFlag_L = FALSE;
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
    switch (mouseClick()) {
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
