#ifndef TRAP_H
#define TRAP_H

#include <string>

struct Trap
{
    int x, y;
    bool triggered = false;
    std::string whoTrapped = ""; // "G" ή "S"

    Trap(int x, int y) : x(x), y(y) {}
    bool check(int hx, int hy, const std::string &name);
};

#endif
