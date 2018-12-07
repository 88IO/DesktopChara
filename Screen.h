#include <windows.h>

#ifndef INCLUDE_SCREEN_H
#define INCLUDE_SCREEN_H

class Screen {
private:
    bool StartFlag_L;
    POINT StartCursorPos, NowCursorPos, StartWindowPos;

    void MoveWindow();
    void ContextMenu();
public:
    Screen();
    void Update();
};

#endif /* end of include guard: INCLUDE_SCREEN_H */
