/*
=========================================
C++ φροντιστήριο
Μάθημα 1ο
Dynamic Memory Allocation
=========================================
*/

#include <iostream>

using namespace std;

int main (int argc, char **argv)
{
    int *a;
    int *b;
    
    a = new int(5);
    cout << *a << endl;
    b = new int[5];
    for (int i = 0; i < 5; i++)
        cout << b[i]<< " ";
    delete a;
    delete[] b;
    
    //delete[] a;   Συντακτικά Σωστό....
    //delete b;     ... πλην όμως....
}

