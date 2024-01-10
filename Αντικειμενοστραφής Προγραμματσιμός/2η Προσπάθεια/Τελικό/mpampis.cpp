#include "mpampis.h"

mpampis::mpampis(vector<string>& vec) : map(vec){

}

mpampis::~mpampis(){

}

bool mpampis::domove(int gemx, int gemy){
    int mx = getx();
    int my = gety();
    int intmap[map.size()][map.at(0).size()];
    int tempx = gemx;
    int tempy = gemy;
    int i = 1;
    if(((gemx == getx() + 1) && (gemy == gety())) || ((gemx == getx() - 1) && (gemy == gety())) || ((gemx == getx()) && (gemy == gety() + 1)) || ((gemx == getx()) && (gemy == gety() - 1))){
        setx(gemx);
        sety(gemy);
        return true;
    }

    //Δημιουργία χάρτη με βήματα για την εύρεση της κοντινότερης απόστασης του Λουκά από το διαμάντι.

    for(int i = 0;i < map.size();i++){
        for(int z = 0;z< map.at(0).size();z++){
            if(map[i][z] == '*'){
                intmap[i][z] = 1000;
            }
            if(map[i][z] == 'M'){
                intmap[i][z] = 1001;
            }
            if(map[i][z] == '!'){
                intmap[i][z] = 1002;
            }
            if(map[i][z] == 'L'){
                intmap[i][z] = 1003;
            }
            if(map[i][z] == ' '){
                intmap[i][z] = 1004;
            }
        }
    }

    //Έυρεση βημάτων.

    int count = 1;
    while(count<1000){
        if(intmap[tempy][tempx + 1] == 1004){
            tempx++;
            intmap[tempy][tempx] = i;
        }else if(intmap[tempy][tempx - 1] == 1004){
            tempx--;
            intmap[tempy][tempx] = i;
        }else if(intmap[tempy + 1][tempx] == 1004){
            tempy++;
            intmap[tempy][tempx] = i;
        }else if(intmap[tempy - 1][tempx] == 1004){
            tempy--;
            intmap[tempy][tempx] = i;
        }
        if(intmap[tempy][tempx] == 1004){
            intmap[tempy][tempx] = i;
        }
        if(intmap[tempy][tempx] != i){
            i = 0;
            tempx = gemx;
            tempy = gemy;
            count++;
        }
        i++;
    }

    //Έλεγχος στο χάρτη με τα βήματα για την πιο κοντινή απόσταση.

    if((intmap[gety() + 1][getx()] >= intmap[gety() - 1][getx()]) && (intmap[gety()][getx() + 1] >= intmap[gety()-1][getx()]) && (intmap[gety()][getx()-1] >= intmap[gety()-1][getx()]) && (intmap[gety() - 1][getx()] > 0)){
        if(intmap[gety() - 1][getx()] != 1000 && intmap[gety() - 1][getx()] != 1001 ){
            sety(gety()-1);
        }
    }else if(((intmap[gety() + 1][getx()] <= intmap[gety() - 1][getx()])) && (intmap[gety()][getx() + 1] >= intmap[gety()+1][getx()]) && (intmap[gety()][getx()-1] >= intmap[gety()+1][getx()]) && (intmap[gety() + 1][getx()] > 0)){
        if(intmap[gety() + 1][getx()] != 1000 && intmap[gety() + 1][getx()] != 1001){   
            sety(gety()+1);
        }
    }else if((intmap[gety() + 1][getx()] >= intmap[gety()][getx() + 1]) && (intmap[gety() - 1][getx()] >= intmap[gety()][getx() + 1]) && (intmap[gety()][getx()-1] >= intmap[gety()][getx() + 1]) && (intmap[gety()][getx()+1] > 0)){
        if(intmap[gety()][getx() + 1] != 1000 && intmap[gety()][getx() + 1] != 1001){
            setx(getx()+1);
        }
    }else if((intmap[gety() + 1][getx()] >= intmap[gety()][getx() - 1]) && (intmap[gety() - 1][getx()] >= intmap[gety()][getx() - 1]) && (intmap[gety()][getx()-1] >= intmap[gety()][getx() - 1]) && (intmap[gety()][getx()-1] > 0)){
        if(intmap[gety()][getx() - 1] != 1000 && intmap[gety()][getx() - 1] != 1001){
            setx(getx()-1);
        }
    }
            
    //Σε περίπτωση που δεν κινηθεί κάνε μία τυχαία κίνηση που γίνεται.

    if(mx == getx() && my == gety()){
        if(intmap[gety() - 1][getx()] != 1000 && intmap[gety() - 1][getx()] != 1001 ){
            sety(gety()-1);
        }else if(intmap[gety() + 1][getx()] != 1000 && intmap[gety() + 1][getx()] != 1001){   
            sety(gety()+1);
        }else if(intmap[gety()][getx() + 1] != 1000 && intmap[gety()][getx() + 1] != 1001){
            setx(getx()+1);
        }else if(intmap[gety()][getx() - 1] != 1000 && intmap[gety()][getx() - 1] != 1001){
            setx(getx()-1);
        }
    }
    return true;
}
