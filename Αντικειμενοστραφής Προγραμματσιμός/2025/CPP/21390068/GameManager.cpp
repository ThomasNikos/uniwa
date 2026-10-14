#include "GameManager.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <ncurses.h>
#include <locale.h>

GameManager::GameManager(const std::string &mapFile)
    : maze(mapFile), key(0, 0), stairs(0, 0), greg(0, 0), asimenia(0, 0)
{
    srand(time(nullptr));

    std::pair<int, int> g_pos, a_pos;
    do
    {
        g_pos = randomEmptyPosition();
        a_pos = randomEmptyPosition();
    } while (!isFarEnough(g_pos.first, g_pos.second, a_pos.first, a_pos.second));

    greg = Greg(g_pos.first, g_pos.second);
    asimenia = Asimenia(a_pos.first, a_pos.second);

    key = Key(randomEmptyPosition().first, randomEmptyPosition().second);
    stairs = Stairs(randomEmptyPosition().first, randomEmptyPosition().second);

    traps.emplace_back(randomEmptyPosition().first, randomEmptyPosition().second);
    traps.emplace_back(randomEmptyPosition().first, randomEmptyPosition().second);
}

std::pair<int, int> GameManager::randomEmptyPosition() const
{
    int x, y;
    do
    {
        x = rand() % maze.getRows();
        y = rand() % maze.getCols();
    } while (!maze.isWalkable(x, y));
    return {x, y};
}

bool GameManager::isFarEnough(int x1, int y1, int x2, int y2) const
{
    return std::abs(x1 - x2) >= 7 || std::abs(y1 - y2) >= 7;
}

void GameManager::run()
{
    initscr();
    start_color();
    use_default_colors();
    setlocale(LC_ALL, "");

    init_pair(1, COLOR_GREEN, -1);
    init_pair(2, COLOR_MAGENTA, -1);
    init_pair(3, COLOR_RED, -1);
    init_pair(4, COLOR_BLUE, -1);
    init_pair(5, COLOR_YELLOW, -1);
    init_pair(6, COLOR_CYAN, -1);
    init_pair(7, COLOR_WHITE, -1);

    while (turns < 1000 && !finished)
    {
        maze.setTile(greg.getPosition().first, greg.getPosition().second, ' ');
        maze.setTile(asimenia.getPosition().first, asimenia.getPosition().second, ' ');

        if (!phaseAfterMeeting)
        {
            greg.move(maze);
            asimenia.move(maze);
        }
        else
        {
            if (!wallsToClear.empty())
            {
                auto [wx, wy] = wallsToClear.back();
                wallsToClear.pop_back();
                maze.setTile(wx, wy, ' ');
            }

            auto [lx, ly] = std::make_pair(stairs.x, stairs.y);
            auto [gx, gy] = greg.getPosition();
            auto [sx, sy] = asimenia.getPosition();

            if (!greg.trapped() && !(gx == lx && gy == ly))
            {
                if (gx < lx)
                    gx++;
                else if (gx > lx)
                    gx--;
                else if (gy < ly)
                    gy++;
                else if (gy > ly)
                    gy--;
                greg.setPosition(gx, gy);
            }
            else
                gregAtStairs = true;

            if (!asimenia.trapped() && !(sx == lx && sy == ly))
            {
                if (sx < lx)
                    sx++;
                else if (sx > lx)
                    sx--;
                else if (sy < ly)
                    sy++;
                else if (sy > ly)
                    sy--;
                asimenia.setPosition(sx, sy);
            }
            else
                asimeniaAtStairs = true;

            if (gregAtStairs && asimeniaAtStairs)
            {
                clear();
                mvprintw(0, 0, "Happy End! Οι ήρωες έφυγαν από το κάστρο μαζί!");
                mvprintw(2, 0, "Πατήστε οποιοδήποτε πλήκτρο για έξοδο...");
                refresh();
                getch();
                endwin();
                finished = true;
                return;
            }
        }

        checkEvents();
        turns++;

        if (greg.trapped())
            maze.setTile(greg.getPosition().first, greg.getPosition().second, 'C');
        else
            maze.setTile(greg.getPosition().first, greg.getPosition().second, 'G');

        if (asimenia.trapped())
            maze.setTile(asimenia.getPosition().first, asimenia.getPosition().second, 'C');
        else
            maze.setTile(asimenia.getPosition().first, asimenia.getPosition().second, 'S');

        maze.setTile(key.x, key.y, key.taken ? ' ' : 'K');
        maze.setTile(stairs.x, stairs.y, 'L');

        for (const auto &trap : traps)
        {
            if (!greg.trapped() && !asimenia.trapped())
                maze.setTile(trap.x, trap.y, trap.triggered ? 'C' : 'T');
        }

        clear();
        for (int i = 0; i < maze.getRows(); ++i)
        {
            for (int j = 0; j < maze.getCols(); ++j)
            {
                char ch = maze.getTile(i, j);
                int color = 7;
                switch (ch)
                {
                case 'G':
                    color = 1;
                    break;
                case 'S':
                    color = 2;
                    break;
                case 'C':
                    color = 3;
                    break;
                case 'T':
                    color = 4;
                    break;
                case 'K':
                    color = 5;
                    break;
                case 'L':
                    color = 6;
                    break;
                default:
                    color = 7;
                }
                attron(COLOR_PAIR(color));
                mvaddch(i, j, ch);
                attroff(COLOR_PAIR(color));
            }
        }
        mvprintw(maze.getRows(), 0, "Turn: %d", turns);
        refresh();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    endwin();

    if (!finished)
        std::cout << "Game Over: Έληξαν τα 1000 τέρμινα!\n";
}

void GameManager::checkEvents()
{
    auto [gx, gy] = greg.getPosition();
    auto [sx, sy] = asimenia.getPosition();

    if (!key.taken)
    {
        if (gx == key.x && gy == key.y)
        {
            greg.pickKey();
            key.taken = true;
        }
        else if (sx == key.x && sy == key.y)
        {
            asimenia.pickKey();
            key.taken = true;
        }
    }

    for (auto &trap : traps)
    {
        if (!trap.triggered)
        {
            if (trap.check(gx, gy, "G"))
            {
                greg.trap();
                maze.setTile(trap.x, trap.y, 'C');
            }
            if (trap.check(sx, sy, "S"))
            {
                asimenia.trap();
                maze.setTile(trap.x, trap.y, 'C');
            }
        }
    }

    for (auto &trap : traps)
    {
        if (trap.triggered && maze.getTile(trap.x, trap.y) == 'C')
        {
            if (trap.whoTrapped == "S" && gx == trap.x && gy == trap.y && greg.carriesKey())
            {
                asimenia.release();
                maze.setTile(trap.x, trap.y, ' ');
            }
            if (trap.whoTrapped == "G" && sx == trap.x && sy == trap.y && asimenia.carriesKey())
            {
                greg.release();
                maze.setTile(trap.x, trap.y, ' ');
            }
        }
    }

    if (!greg.trapped() && !asimenia.trapped())
    {
        if (gx == sx && gy == sy && !phaseAfterMeeting)
        {
            for (int i = 0; i < maze.getRows(); ++i)
                for (int j = 0; j < maze.getCols(); ++j)
                    if (maze.getTile(i, j) == '*')
                        wallsToClear.push_back({i, j});
            phaseAfterMeeting = true;
        }
    }

    if (greg.trapped() && asimenia.trapped())
    {
        clear();
        mvprintw(0, 0, "Game Over: Και οι δύο ήρωες παγιδεύτηκαν.");
        mvprintw(2, 0, "Πατήστε πλήκτρο για έξοδο...");
        refresh();
        getch();
        endwin();
        finished = true;
    }
}
