#ifndef ASIMENIA_H
#define ASIMENIA_H

#include "Hero.h"

class Asimenia : public Hero
{
public:
    Asimenia(int x, int y);
    void move(const Maze &maze) override;
};

#endif
