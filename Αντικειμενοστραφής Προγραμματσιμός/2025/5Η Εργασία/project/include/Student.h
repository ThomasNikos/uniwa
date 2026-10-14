#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include "Course.h"
#include <string>
#include <vector>

class Student : public Person {
private:
    string registrationNumber;  // Μητρώου
    int semester;              // Εξάμηνο
    vector<Course*> courses;   // Δηλωμένα μαθήματα

public:
    // Constructor
    Student(const string& id, const string& fullName, int birthYear,
           const string& address, const string& phone, const string& email,
           const string& registrationNumber, int semester);

    // Copy constructor
    Student(const Student& other);

    // Getters
    string getRegistrationNumber() const;
    int getSemester() const;
    const vector<Course*>& getCourses() const;

    // Setters
    void setSemester(int semester);
    void setRegistrationNumber(const string& registrationNumber);

    // Διαχείριση μαθημάτων
    void addCourse(Course* course);
    void removeCourse(const string& courseCode);
    bool isEnrolledIn(const string& courseCode) const;
    float getGrade(const string& courseCode) const;

    // Υλοποίηση της virtual μεθόδου display
    virtual void display() const override;


    virtual void sendEmail(const string& message) override;
};

#endif
