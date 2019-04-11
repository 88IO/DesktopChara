#include "Character.h"
#include "Screen.h"
#include "Config.h"
#include "DxLib.h"
#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    if (setup() != 0)  return -1;
    Character chara;
    Screen sc;

    while (DxLib::ScreenFlip() == 0 && DxLib::ProcessMessage() == 0 &&
            DxLib::ClearDrawScreen() == 0 && DxLib::CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
        chara.Update();
        chara.Draw();
        sc.Update();
    }

    DxLib::DxLib_End();

    return 0;
}
