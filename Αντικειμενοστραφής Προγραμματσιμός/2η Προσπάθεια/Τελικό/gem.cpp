#include "gem.h"

gem::gem(vector<string>& vec) : map(vec){

}

gem::~gem(){

}

void gem::setx(int nx){
    x = nx;
}

void gem::sety(int ny){
    y = ny;
}

int gem::getx(){
    return x;
}

int gem::gety(){
    return y;
}

bool gem::check_move(){
    if(map[y][x] == '*' || map[y][x] == 'M' || map[y][x] == 'L'){
        return true;
    }
    return false;

}

bool gem::do_move(){

    //Κίνηση του διαμαντιού σε τυχαίες θέσεις σε "τυχαία" χρονικά διαστήματα.

    if(int i = 85 < rand() % 100){
        if(map[y][x] == '!')
            map[y][x] = ' ';
        do{
            setx(rand() % (map.at(0).size()));
            sety(rand() % (map.size()));
        }while(check_move());
        return true;
    }
    return false;
}