#ifndef INCLUDE_CHARACTER_H
#define INCLUDE_CHARACTER_H


class Character {
private:
    int graphHandle[12], callout;
    int Counter;

    int sdNum;
    int AnimeLoop;

    bool isCallout;
    enum Actions { None, Blink, Surprised, Callout };
    Actions ActType;

    void GetAction();
public:
    Character();
    ~Character();

    void Update();
    void Draw();
};

#endif /* end of include guard: INCLUDE_CHARACTER_H */
