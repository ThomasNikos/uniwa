#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <string>

class Maze
{
private:
    std::vector<std::string> grid;
    int rows;
    int cols;

public:
    Maze(const std::string &filename);
    void display() const;
    char getTile(int x, int y) const;
    void setTile(int x, int y, char ch);
    bool isWalkable(int x, int y) const;
    int getRows() const;
    int getCols() const;
};

#endif
