#include "Character.h"
#include "DxLib.h"
#include <windows.h>
#include <iostream>

Character::Character() {
    DxLib::LoadDivGraph("images/sd.png", 12, 4, 3, 200, 485, graphHandle);
    callout = DxLib::LoadGraph("images/callout.png", TRUE);

    Counter = 0;
    sdNum = 0;
    AnimeLoop = 0;
    isCallout = FALSE;
    ActType = None;
}

Character::~Character() {
    DxLib::DeleteGraph(graphHandle[12]);
    DxLib::DeleteGraph(callout);
};

void Character::GetAction() {
    static int tmpSpaceKey[2] = {0, 0};
    tmpSpaceKey[0] = tmpSpaceKey[1];
    tmpSpaceKey[1] = DxLib::CheckHitKey(KEY_INPUT_SPACE);

    Counter++;
    if (ActType != None)  return;

    if (Counter % 600 == 0) {
        ActType = Blink;
    } else if (DxLib::CheckHitKey(KEY_INPUT_DELETE) == 1) {
        ActType = Surprised;
    } else if (tmpSpaceKey[0] < tmpSpaceKey[1]) {
        ActType = Callout;
    }
}

void Character::Update() {
    GetAction();
    switch (ActType) {
    case Blink:
        AnimeLoop++;
        if (AnimeLoop % 8 == 0) {
            sdNum = (sdNum + 1) % 4;
            if (sdNum == 0) {
                ActType = None;
                AnimeLoop = 0;
            }
        }
        break;
    case Surprised:
        AnimeLoop++;
        if (AnimeLoop % 20 == 0) {
            sdNum = (sdNum + 10) % 20;
            if (sdNum == 0) {
                ActType = None;
                AnimeLoop = 0;
            }
        }
        break;
    case Callout:
        if (isCallout == TRUE) {
            isCallout = FALSE;
        } else {
            isCallout = TRUE;
        }
        ActType = None;
        break;
    default:
        break;
    }
}

void Character::Draw() {
    if (isCallout == TRUE) {
        DxLib::DrawGraph(0, 0, callout, TRUE);
        DrawFormatString(40, 50, DxLib::GetColor(0, 0, 0), "テスト!");
    }
    DxLib::DrawGraph(300, 0, graphHandle[sdNum], TRUE);
}
