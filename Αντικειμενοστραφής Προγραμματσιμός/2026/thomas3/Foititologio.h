#pragma once
#include "Person.h"
#include "Student.h"
#include "Professor.h"
#include "Course.h"
#include <stdexcept>

class Foititologio {
private:
    Person** members;
    int memberCount;
    int memberCapacity;

    Course** courses;
    int courseCount;
    int courseCapacity;

    void expandMembers();
    void expandCourses();

public:
    Foititologio();
    Foititologio(const Foititologio&) = delete;
    ~Foititologio();

    void addMember(Person* p);
    void removeMember(const char* code);
    Person* findMember(const char* code) const;

    void addCourse(Course* c);
    void removeCourse(const string& code);
    Course* findCourse(const string& code) const;

    void emailStudents() const;
    void emailProfessors() const;

    void printMembers(ostream& os) const;
    void printCourses(ostream& os) const;

    void saveToCSV(const string& dir = ".") const;
    void loadFromCSV(const string& dir = ".");
};
