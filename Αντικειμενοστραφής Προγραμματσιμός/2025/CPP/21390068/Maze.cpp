#include "Maze.h"
#include <fstream>
#include <iostream>

Maze::Maze(const std::string &filename)
{
    std::ifstream in(filename);
    std::string line;
    while (getline(in, line))
    {
        grid.push_back(line);
    }
    rows = grid.size();
    cols = (rows > 0) ? grid[0].size() : 0;
}

void Maze::display() const
{
    for (const auto &row : grid)
        std::cout << row << std::endl;
}

char Maze::getTile(int x, int y) const
{
    if (x >= 0 && y >= 0 && x < rows && y < cols)
        return grid[x][y];
    return '*';
}

void Maze::setTile(int x, int y, char ch)
{
    if (x >= 0 && y >= 0 && x < rows && y < cols)
        grid[x][y] = ch;
}

bool Maze::isWalkable(int x, int y) const
{
    char tile = getTile(x, y);
    return tile == ' ' || tile == 'L' || tile == 'K';
}

int Maze::getRows() const { return rows; }
int Maze::getCols() const { return cols; }
