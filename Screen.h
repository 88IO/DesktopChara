#include <windows.h>

#ifndef INCLUDE_SCREEN_H
#define INCLUDE_SCREEN_H

class Screen {
private:
    bool StartFlag_L;
    POINT StartCursorPos, NowCursorPos, StartWindowPos;

    enum MouseCondition { None, Click_L, Click_R };
    MouseCondition mc;

    int MouseClick();
    void MoveWindow();
    void ContextMenu();
public:
    Screen();
    void Update();
};

#endif /* end of include guard: INCLUDE_SCREEN_H */
