/*
=========================================
C++ φροντιστήριο
Μάθημα 1ο
Υπερφόρτωση συνάρτησης
=========================================
*/

#include <iostream>

using namespace std;

//Δοκιμάστε να σβήσετε (βάζοντας σχόλεια) μία μία τις συναρτήσεις και δείτε τι θα συμβεί

void myfunc1 (int x)
{
    cout << "integer version of myfunc1" << endl;
}

void myfunc1 (long x)
{
    cout << "long version of myfunc1" << endl;
}

void myfunc1 (float x)
{
    cout << "float version of myfunc1" << endl;
}

void myfunc1 (double x)
{
    cout << "double version of myfunc1" << endl;
}

void myfunc1 (double x, int y)
//void myfunc1 (double x, int y = 3)   //Δοκιμάστε και αυτή την περίπτωση 
{
    cout << "extra version of myfunc1" << endl;
}

int main (int argc, char **argv)
{
    myfunc1 (3);
    myfunc1 (3l);
    myfunc1 (3.14159);
    myfunc1 (3.14159f);
    myfunc1 (3.14159, 5);
    myfunc1 (3, 5);
}

