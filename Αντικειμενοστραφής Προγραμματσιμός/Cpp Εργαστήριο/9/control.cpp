#include "control.h"
#include <vector>

control::control(string n){
    name = n;
}

control::~control(){

}

void control::size(){
    fstream file;
    char Buff[1024];
    int Br, size = 0;
    
    file.open (name, ios::in | ios::binary);
    if (!file.good ())
    {
        cout << "Cannot open source file..." << endl;
        exit (2);
    }
    
    do
    {
        file.read (Buff, 100);
        size += Br = file.gcount ();
    }
    while (Br); 

    file.close ();
    cout << "Το μέγεθος του αρχείου είναι:" << size << endl;

}

void control::copy(string dest){
    fstream InpF, OutF;
    char Buff[1024];
    int Br;
    
    InpF.open (name, ios::in | ios::binary);
    if (!InpF.good ())
    {
        cout << "Δεν μπορεί να ανοίξει το αρχείο." << endl;
        exit (2);
    }
    
    OutF.open (dest, ios::out | ios::binary);
    if (!OutF.good ())
    {
        cout << "Δεν μπορεί να ανοίξει το αρχείο." << endl;
        exit (2);
    }
    
    do
    {
        InpF.read (Buff, 100);
        Br = InpF.gcount ();
        if (Br)
            OutF.write (Buff, Br);
    }
    while (Br); 
    InpF.close ();
    OutF.close ();

}

void control::newf(string newfilen){
    fstream InpF, OutF;
    vector<string> linef;
    string line;
    
    InpF.open (name, ios::in | ios::binary);
    if (!InpF.good ())
    {
        cout << "Δεν μπορεί να ανοίξει το αρχείο." << endl;
        exit (2);
    }
    
    OutF.open (newfilen, ios::out | ios::binary);
    if (!OutF.good ())
    {
        cout << "Δεν μπορεί να ανοίξει το αρχείο." << endl;
        exit (2);
    }
    
    while(getline(InpF, line)){
        linef.push_back(line);
    }
    for(int i = linef.size() - 1;i > -1;i--){
        for(int y = linef[i].length() - 1;y> -1;y--){
            OutF << linef[i][y];
            }
        OutF << endl;
    }

    InpF.close ();
    OutF.close ();
}