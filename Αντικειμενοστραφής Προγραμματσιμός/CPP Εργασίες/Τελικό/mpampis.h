#ifndef MPAMPIS_H
#define MPAMPIS_H

#include "player.h"
#include <vector>

using namespace std;

class mpampis : public player {
            vector<string>& map;
        public:
            bool checkmove(int, int);
            bool domove(int, int);
            mpampis(vector<string>& vec);
            virtual ~mpampis();
};

#endif
