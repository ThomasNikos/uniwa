#include <iostream>
#include "GameManager.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    if (argc < 2)
    {
        std::cerr << "Χρήση: ./maze_game map1.txt\n";
        return 1;
    }

    GameManager game(argv[1]);
    game.run();
    return 0;
}
