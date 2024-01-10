#include "player.h"

player::player(){

}

player::~player(){

}

bool player::domove(int nx, int ny){
        return false;
}

void player::setx(int nx){
    x = nx;
}

void player::sety(int ny){
    y = ny;
}

int player::getx(){
    return x;
}

int player::gety(){
    return y;
}

bool player::get_move(int c){
        switch(c){
                case KEY_UP:
                    domove(x,(y-1));
                    return true;
                    break;
                case KEY_DOWN:
                    domove(x,(y+1));
                    return true;
                    break;
                case KEY_LEFT:
                    domove((x-1),y);
                    return true;
                    break;
                case KEY_RIGHT:
                    domove((x+1),y);
                    return true;
                    break;
                case 32:
                    domove(x,y);
                    return true;
                    break;
                case 27:
                    return false;
                    break;
                default:
                    return true;
                    break;
        }
}