#ifndef LOUKAS_H
#define LOUKAS_H

#include <vector>
#include <string>
#include "player.h"

using namespace std;

class loukas : public player {
            vector<string>& map;
        public:
            bool domove(int, int);
            loukas(vector<string>& vec);
            virtual ~loukas();
};

#endif
