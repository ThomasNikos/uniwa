#include <iostream>
#include <ncurses.h>
#include <fstream>
#include <cstring>
#include <vector>
#include "engine.h"

using namespace std;

void arguments_check(int);

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "");
    srand(time(NULL));
    arguments_check(argc);
    engine game(argv);
    game.start();
}

//Έλεγχος για το αν έχει δωθεί ως παράμετρος ένα όνομα χάρτη.

void arguments_check(int argc){
    if(argc < 2){
        cout << "Δώσε όνομα χάρτη." << endl;
        exit(EXIT_FAILURE);
    }
}