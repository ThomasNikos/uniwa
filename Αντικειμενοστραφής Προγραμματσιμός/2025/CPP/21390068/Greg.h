#ifndef GREG_H
#define GREG_H

#include "Hero.h"

class Greg : public Hero
{
public:
    Greg(int x, int y);
    void move(const Maze &maze) override;
};

#endif
