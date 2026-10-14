#pragma once
#include "Person.h"
#include "Course.h"
#include <vector>

class Professor : public Person {
private:
    string specialty;
    vector<Course*> courses;

public:
    Professor(const char* code, const string& name, bool gender, const string& specialty);
    Professor(const Professor& other);
    ~Professor();

    string getSpecialty() const;
    void setSpecialty(const string& s);

    void addCourse(Course* c);
    void removeCourse(const string& courseCode);
    const vector<Course*>& getCourses() const;

    void print(ostream& os) const;
    void sendEmail() const;
    string getType() const;
};
