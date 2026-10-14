#include "Asimenia.h"
#include "Maze.h"
#include <cstdlib>

Asimenia::Asimenia(int x, int y) : Hero(x, y) {}

void Asimenia::move(const Maze &maze)
{
    if (trapped())
        return;

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    int randDir = rand() % 4;
    int nx = x + dx[randDir];
    int ny = y + dy[randDir];

    if (maze.isWalkable(nx, ny))
    {
        setPosition(nx, ny);
    }
}
