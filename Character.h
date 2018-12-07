#ifndef INCLUDE_CHARACTER_H
#define INCLUDE_CHARACTER_H

enum Actions {
    None,
    Blink,
    Surprised,
    Callout,
};

class Character {
private:
    int graphHandle[12], callout;
    int Counter;

    int sdNum;
    int AnimeLoop;

    bool isCallout;
    Actions ActType;

    void GetAction();
public:
    Character();
    ~Character();

    void Update();
    void Draw();
};

#endif /* end of include guard: INCLUDE_CHARACTER_H */
