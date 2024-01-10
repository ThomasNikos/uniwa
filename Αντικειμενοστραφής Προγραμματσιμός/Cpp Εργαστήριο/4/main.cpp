#include <iostream>
#include <cstring>

class MyString
{
    int size;
    char *string;

public:
    MyString();
    MyString(const char *string);
    MyString(MyString &X);
    ~MyString();


    char *GetString();
    int Size();

    int operator==(MyString &X);
    int operator<(MyString &X);
    int operator>(MyString &X);
    int operator!=(MyString &X);
    void operator+=(char character);
};

MyString ::~MyString() { 
	delete[] string;
}

MyString ::MyString()
{
    size = 1;
    string = new char[size];
    strcpy(string, " ");
}

MyString ::MyString(const char *string)
{
    this->size = strlen(string);
    this->string = new char[size];
    strcpy(this->string, string);
}

MyString ::MyString(MyString &X)
{
    this->size = X.size;
    this->string = new char[this->size];
    strcpy(this->string, X.string);
}

int MyString ::operator==(MyString &X)
{
    if (strcmp(this->string, X.string) == 0)
        return 1;
    return 0;
}

int MyString ::operator!=(MyString &X)
{
    if (strcmp(this->string, X.string) != 0)
        return 1;
    return 0;
}

int MyString ::operator<(MyString &X)
{
    if (strlen(this->string) < strlen(X.string))
        return 1;
    return 0;
}

int MyString ::operator>(MyString &X)
{
    if (strlen(this->string) > strlen(X.string))
        return 1;
    return 0;
}

std::ostream &operator<<(std::ostream &C1, MyString &X)
{
    C1 << "Your String : " << X.GetString() << "\n";
    return C1;
}

char *MyString::GetString() { return string; }

int MyString::Size() { return strlen(string); }

void MyString ::operator+=(char character)
{
    char *temp = new char[size];
    strcpy(temp, string);
    delete[] string;
    size += 1;
    string = new char[size];
    strcpy(string, temp);
    string[size - 1] = character;
    delete[] temp;
}

int main(int argc, char *argv[])
{
    MyString String1;
    MyString String2("Nikos");
    MyString String3("Thomas");

    String3.operator+=('A');
    std::cout << String3;

    return 0;
}
