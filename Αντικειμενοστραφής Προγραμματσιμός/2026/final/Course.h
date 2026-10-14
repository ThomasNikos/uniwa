#pragma once
#include <iostream>
#include <string>

using namespace std;

class Professor;

class Course {
private:
    string code;
    string description;
    unsigned int semester;
    Professor* responsible;

public:
    Course(const string& code, const string& desc, unsigned int semester, Professor* resp = nullptr);
    Course(const Course& other);
    ~Course();

    string getCode() const;
    string getDescription() const;
    unsigned int getSemester() const;
    Professor* getResponsible() const;

    void setCode(const string& c);
    void setDescription(const string& d);
    void setSemester(unsigned int s);
    void setResponsible(Professor* p);

    void print(ostream& os) const;
};

ostream& operator<<(ostream& os, const Course& c);
