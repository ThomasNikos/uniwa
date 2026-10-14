#ifndef KEY_H
#define KEY_H

struct Key
{
    int x, y;
    bool taken = false;

    Key(int x, int y) : x(x), y(y) {}
    bool atPosition(int hx, int hy);
};

#endif
