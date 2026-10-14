#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <map>
#include "Professor.h"

using namespace std;

class Course {
private:
    string code;              // Κωδικός μαθήματος
    string name;              // Λεκτικό (όνομα) μαθήματος
    int semester;             // Εξάμηνο διδασκαλίας
    Professor* professor;     // Διδάσκων καθηγητής
    map<string, float> grades; // Βαθμοί φοιτητών (AM -> βαθμός)

public:
    // Constructor
    Course(const string& code, const string& name, int semester, Professor* professor);

    // Copy constructor
    Course(const Course& other);

    // Destructor
    ~Course();

    // Getters
    string getCode() const;
    string getName() const;
    int getSemester() const;
    Professor* getProfessor() const;
    float getGrade(const string& studentId) const;
    const map<string, float>& getAllGrades() const;

    // Setters
    void setCode(const string& code);
    void setName(const string& name);
    void setSemester(int semester);
    void setProfessor(Professor* professor);

    // Διαχείριση βαθμών
    void setGrade(const string& studentId, float grade);
    void removeGrade(const string& studentId);
    bool hasGrade(const string& studentId) const;

    // Εμφάνιση πληροφοριών μαθήματος
    void display() const;
};

#endif
