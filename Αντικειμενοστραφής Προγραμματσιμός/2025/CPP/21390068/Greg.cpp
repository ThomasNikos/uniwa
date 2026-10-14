#include "Greg.h"
#include "Maze.h"
#include <cstdlib>

Greg::Greg(int x, int y) : Hero(x, y) {}

void Greg::move(const Maze &maze)
{
    if (trapped())
        return;

    static const int dx[] = {-1, 1, 0, 0};
    static const int dy[] = {0, 0, -1, 1};

    for (int d = 0; d < 4; ++d)
    {
        int nx = x + dx[d], ny = y + dy[d];
        if (maze.isWalkable(nx, ny) && !remembers(nx, ny))
        {
            setPosition(nx, ny);
            return;
        }
    }

    int dir = rand() % 4;
    int nx = x + dx[dir], ny = y + dy[dir];
    if (maze.isWalkable(nx, ny))
    {
        setPosition(nx, ny);
    }
}
