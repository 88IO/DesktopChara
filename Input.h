#ifndef INCLUDE_INPUT_H
#define INCLUDE_INPUT_H

extern int Key[256];

enum MouseCondition {
    Click_L,
    Click_R,
    NoClick,
};

int UpdateKey();
int mouseClick();

#endif /* end of include guard: INCLUDE_INPUT_H */
