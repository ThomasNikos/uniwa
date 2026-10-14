#pragma once
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Person {
protected:
    char* code;
    string fullName;
    bool gender; // false = Άνδρας, true = Γυναίκα

public:
    Person(const char* code, const string& name, bool gender);
    Person(const Person& other);
    virtual ~Person();

    char* getCode() const;
    string getFullName() const;
    bool getGender() const;

    void setCode(const char* newCode);
    void setFullName(const string& name);
    void setGender(bool g);

    virtual void print(ostream& os) const = 0;
    virtual void sendEmail() const = 0;
    virtual string getType() const = 0;
};

ostream& operator<<(ostream& os, const Person& p);
