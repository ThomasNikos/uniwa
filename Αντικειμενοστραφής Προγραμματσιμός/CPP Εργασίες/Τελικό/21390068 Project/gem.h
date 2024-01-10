#ifndef GEM_H
#define GEM_H

#include <vector>
#include <string>

using namespace std;

class gem {
        int x,y;
        vector<string>& map;
    public:
        void setx(int);
        void sety(int);
        int getx();
        int gety();
        bool check_move();
        bool do_move();
        gem(vector<string>& vec);
        virtual ~gem();
};

#endif
