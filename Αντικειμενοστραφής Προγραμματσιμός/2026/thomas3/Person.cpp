#include "Person.h"
#include <stdexcept>

Person::Person(const char* code, const string& name, bool gender) {
    if (code == nullptr || strlen(code) == 0)
        throw invalid_argument("Code cannot be empty");
    if (name.empty())
        throw invalid_argument("Name cannot be empty");
    this->code = new char[strlen(code) + 1];
    strcpy(this->code, code);
    this->fullName = name;
    this->gender = gender;
}

Person::Person(const Person& other) {
    this->code = new char[strlen(other.code) + 1];
    strcpy(this->code, other.code);
    this->fullName = other.fullName;
    this->gender = other.gender;
}

Person::~Person() {
    delete[] code;
}

char* Person::getCode() const { return code; }
string Person::getFullName() const { return fullName; }
bool Person::getGender() const { return gender; }

void Person::setCode(const char* newCode) {
    if (newCode == nullptr || strlen(newCode) == 0)
        throw invalid_argument("Code cannot be empty");
    delete[] code;
    code = new char[strlen(newCode) + 1];
    strcpy(code, newCode);
}

void Person::setFullName(const string& name) {
    if (name.empty())
        throw invalid_argument("Name cannot be empty");
    fullName = name;
}

void Person::setGender(bool g) { gender = g; }

ostream& operator<<(ostream& os, const Person& p) {
    p.print(os);
    return os;
}
