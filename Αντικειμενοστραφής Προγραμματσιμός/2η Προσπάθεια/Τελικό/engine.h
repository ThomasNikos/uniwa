#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <ncurses.h>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

class engine {
            int height, width;
            vector<string> map;
        public:
            void map_creator();
            void start();
            void print();
            bool check_move(int, int, int);
            engine(char **);
            virtual ~engine();
};


#endif
