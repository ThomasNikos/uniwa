#ifndef HERO_H
#define HERO_H

#include <set>
#include <utility>

class Maze;

class Hero
{
protected:
    int x, y;
    bool hasKey = false;
    bool isTrapped = false;
    std::set<std::pair<int, int>> memory;

public:
    Hero(int startX, int startY);
    virtual void move(const Maze &maze) = 0;
    void setPosition(int newX, int newY);
    std::pair<int, int> getPosition() const;
    void remember(int x, int y);
    bool remembers(int x, int y) const;
    void release();
    void trap();
    bool trapped() const;
    void pickKey();
    bool carriesKey() const;
    virtual ~Hero() = default;
};

#endif
