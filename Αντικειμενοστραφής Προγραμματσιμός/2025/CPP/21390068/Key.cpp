#include "Key.h"

bool Key::atPosition(int hx, int hy)
{
    return !taken && x == hx && y == hy;
}
