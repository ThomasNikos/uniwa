#ifndef MPAMPIS_H
#define MPAMPIS_H

#include <vector>
#include <string>
#include "player.h"

using namespace std;

class mpampis : public player {
            vector<string>& map;
        public:
            bool domove(int, int);
            mpampis(vector<string>& vec);
            virtual ~mpampis();
};

#endif
