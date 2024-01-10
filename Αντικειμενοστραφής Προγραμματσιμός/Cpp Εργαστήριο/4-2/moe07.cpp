#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

class MyString
{
    vector <char> s;
    
public:
    MyString ();
    MyString (char *);
    MyString (const MyString &);
    bool operator == (const MyString &);
    bool operator != (const MyString &);
    MyString operator += (char );
    int size ();
    char * tocstr ();
};

MyString::MyString ()
{
    
}

MyString::MyString (char *x)
{
    for (int i = 0; i < strlen (x); i++)
        s.push_back (x[i]);
}

MyString::MyString (const MyString &k)
{
    s = k.s;
}

bool MyString::operator== (const MyString &x)
{
    if (s == x.s)
        return true;
    else
        return false;

}

bool MyString::operator!= (const MyString &x)
{
    if (! (*this == x))
        return true;
    else
        return false;
}

int MyString::size ()
{
    return s.size ();
}

MyString MyString::operator += (char c)
{
    s.push_back (c);
    return *this;
}

char * MyString::tocstr ()
{
    char *tmp;
    int i;
    tmp = new char [s.size() + 1];
    for (i = 0; i < s.size(); i++)
        tmp[i] = s[i];
    tmp[i] = '\0';
    return tmp;
}

int main (int argc, char **argv)
{
    //Εδώ βάζουμε ό,τι θέλουμε να ελεγξουμε αν θέλουμε
    
    cout << 1 << endl;
    MyString a;
    cout << 2 << endl;
    MyString b ("abcd");
    cout << 3 << endl;
    MyString c = b;
    cout << 4 << endl;
    
    cout << "a:" << a.tocstr () << endl;
    
    cout << "b:" << b.tocstr () << endl;
    
    cout << "c:" << b.tocstr () << endl;
    
    cout << c.size() << endl;
    cout << (b == c) << endl;
    cout << (b != c) << endl;
    
    c += 'x';
    
    cout << c.size() << endl;
    cout << (b == c) << endl;
    cout << (b != c) << endl;
    
    
    
}
    
    
    
