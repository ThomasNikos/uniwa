#pragma once
#include "Person.h"
#include "Course.h"
#include <vector>

class Student : public Person {
private:
    unsigned int semester;
    vector<Course*> courses;

public:
    Student(const char* id, const string& name);
    Student(const char* id, const string& name, bool gender, unsigned int semester);
    Student(const Student& other);
    ~Student();

    unsigned int getSemester() const;
    void setSemester(unsigned int s);

    void addCourse(Course* c);
    void removeCourse(const string& courseCode);
    const vector<Course*>& getCourses() const;

    void print(ostream& os) const override;
    void sendEmail() const override;
    string getType() const override;

    Student& operator++();
    Student operator++(int);
    Student& operator+=(unsigned int n);
    Student& operator-=(unsigned int n);
    Student operator-() const;
};
