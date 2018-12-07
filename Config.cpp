#include "Config.h"
#include <windows.h>
#include "DxLib.h"

int setup() {
    DxLib::ChangeWindowMode(TRUE);
    DxLib::SetGraphMode(500, 500, 32);
    DxLib::SetWindowStyleMode(2);
    DxLib::SetUseBackBufferTransColorFlag(TRUE);
    DxLib::SetDrawScreen(DX_SCREEN_BACK);
    DxLib::SetAlwaysRunFlag(TRUE);
    DxLib::SetFontSize(80);
    DxLib::SetFontThickness(10);
    DxLib::ChangeFont("メイリオ");
    DxLib::ChangeFontType(DX_FONTTYPE_ANTIALIASING);
    DxLib::DxLib_Init();
    return 0;
}
