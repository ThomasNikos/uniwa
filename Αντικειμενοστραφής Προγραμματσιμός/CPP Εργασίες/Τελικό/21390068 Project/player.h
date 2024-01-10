#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <ncurses.h>

using namespace std;

class player {
            int x, y;
        public:
            void setx(int); 
            void sety(int);
            int getx();
            int gety();
            bool get_move(int c);
            virtual bool domove(int, int);
            player();
            virtual ~player();

};

#endif