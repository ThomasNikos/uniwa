/*
=========================================
C++ φροντιστήριο
Μάθημα 1ο
References σε συναρτήσεις
=========================================
*/

#include <iostream>

using namespace std;

void swap (int &x, int &y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

char &GetElement (char pin[], int pos)
{
    return pin[pos];
}

int &SomeFunction ()
{
    int tmp = 100;
    static int tmp1 = 100;
    return tmp;       //Warning
    return tmp1;      //Correct
}

int main (int argc, char **argv)
{
    int a = 3;
    int b = 4;
    swap (a, b);
    cout << a << " " << b << endl;
    cout << "==================================" << endl;
    char mat[] = "ABCDEFGHI";
    char c;
    c = GetElement (mat, 2);
    c = 'c';
    cout << mat << " " << c << endl;
    char &d = GetElement (mat, 2);
    d = 'c';
    cout << mat << endl;
    GetElement (mat, 6) = 'g';
    cout << mat << endl;
    
}

