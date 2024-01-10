#include "loukas.h"

loukas::loukas(vector<string>& vec) : map(vec){

}

loukas::~loukas(){
    
}

//Έλεγχος για το αν μπορεί να γίνει η κίνηση.

bool loukas::checkmove(int nx, int ny){
    char ch = map[ny][nx];
    if(ch != '*' && ch != 'M' && ch != '*'){
        return true;
    }else{
        return false;
    }
}

//Αν μπορεί να γίνει η κίνηση τότε ο Μπάμπης κουνιέται.

bool loukas::domove(int nx, int ny){
    if(checkmove(nx,ny)){
        setx(nx);
        sety(ny);
        return true;
    }else{   
        return false;
    }
}