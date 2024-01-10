#include "mpampis.h"

mpampis::mpampis(vector<string>& vec) : map(vec){

}

mpampis::~mpampis(){
    
}

//Έλεγχος για το αν μπορεί να γίνει η κίνηση.

bool mpampis::checkmove(int nx, int ny){
    char ch = map[ny][nx];
    if(ch != '*' && ch != 'L' && ch != '*'){
        return true;
    }else{
        return false;
    }
}

//Αν μπορεί να γίνει η κίνηση τότε ο Μπάμπης κουνιέται.

bool mpampis::domove(int nx, int ny){
    if(checkmove(nx,ny)){
        setx(nx);
        sety(ny);
        return true;
    }else{   
        return false;
    }
}