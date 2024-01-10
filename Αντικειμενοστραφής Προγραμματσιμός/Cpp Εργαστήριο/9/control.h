#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class control {
    private:
        string name;

    public:
        void size();
        void copy(string);
        void newf(string);
        control(string);
        ~control();
};




#endif