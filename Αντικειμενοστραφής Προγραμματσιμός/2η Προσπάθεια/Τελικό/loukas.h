#ifndef LOUKAS_H
#define LOUKAS_H

#include "player.h"
#include <vector>

using namespace std;

class loukas : public player {
            vector<string>& map;
        public:
            bool checkmove(int, int);
            bool domove(int, int);
            loukas(vector<string>& vec);
            virtual ~loukas();
};

#endif
