#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Maze.h"
#include "Greg.h"
#include "Asimenia.h"
#include "Trap.h"
#include "Key.h"
#include "Stairs.h"
#include <vector>

class GameManager
{
private:
    Maze maze;
    Greg greg;
    Asimenia asimenia;
    std::vector<Trap> traps;
    Key key;
    Stairs stairs;
    int turns = 0;
    bool finished = false;
    bool phaseAfterMeeting = false;
    bool gregAtStairs = false;
    bool asimeniaAtStairs = false;
    std::vector<std::pair<int, int>> wallsToClear;
    std::pair<int, int> randomEmptyPosition() const;
    bool isFarEnough(int x1, int y1, int x2, int y2) const;

public:
    GameManager(const std::string &mapFile);
    void run();
    void checkEvents();
};

#endif
