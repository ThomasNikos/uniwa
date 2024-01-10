#include <iostream>
#include <fstream>
#include "control.h"
using namespace std;


int main (int argc, char **argv)
{
    string namef = "nikos.txt";
    string dest = "nikos2.txt";
    string newfile = "nikos3.txt";
    control file(namef);
    file.size();
    file.copy(dest);
    file.newf(newfile);
}
