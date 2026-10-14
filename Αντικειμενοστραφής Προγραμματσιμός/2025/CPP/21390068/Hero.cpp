#include "Hero.h"

Hero::Hero(int startX, int startY) : x(startX), y(startY)
{
    remember(x, y);
}

void Hero::setPosition(int newX, int newY)
{
    x = newX;
    y = newY;
    remember(x, y);
}

std::pair<int, int> Hero::getPosition() const
{
    return {x, y};
}

void Hero::remember(int rx, int ry)
{
    memory.insert({rx, ry});
}

bool Hero::remembers(int rx, int ry) const
{
    return memory.find({rx, ry}) != memory.end();
}

void Hero::release()
{
    isTrapped = false;
}

void Hero::trap() { isTrapped = true; }
bool Hero::trapped() const { return isTrapped; }

void Hero::pickKey() { hasKey = true; }
bool Hero::carriesKey() const { return hasKey; }
