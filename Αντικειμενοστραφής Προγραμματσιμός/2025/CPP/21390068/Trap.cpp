#include "Trap.h"

bool Trap::check(int hx, int hy, const std::string &name)
{
    if (x == hx && y == hy && !triggered)
    {
        triggered = true;
        whoTrapped = name;
        return true;
    }
    return false;
}
