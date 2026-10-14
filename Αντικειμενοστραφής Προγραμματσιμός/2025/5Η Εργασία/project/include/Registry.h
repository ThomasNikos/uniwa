#ifndef REGISTRY_H
#define REGISTRY_H

#include "Course.h"
#include "Student.h"
#include "Professor.h"
#include <vector>
#include <string>

class Registry {
private:
    vector<Course*> courses;        // Μέλη
    vector<Person*> members;        // Μαθήματα

    // Βοηθητικές μέθοδοι
    Student* findStudent(const string& registrationNumber);
    Professor* findProfessor(const string& code);
    Course* findCourse(const string& code);

    // Για CSV
    void saveEnrollmentsToCSV() const;
    void loadEnrollmentsFromCSV();
    void saveMembersToCSV() const;
    void loadMembersFromCSV();
    void saveCoursesToCSV() const;
    void loadCoursesFromCSV();

public:
    // Constructor & Destructor
    Registry();
    ~Registry();

    // Διαχείριση μαθημάτων
    void addCourse(const string& code, const string& name, int semester, const string& professorCode);
    void updateCourse(const string& code, const string& name, int semester, const string& professorCode);
    void deleteCourse(const string& code);

    // Διαχείριση μελών
    void addStudent(const string& id, const string& fullName, int birthYear,
                   const string& address, const string& phone, const string& email,
                   const string& registrationNumber, int semester);

    void addProfessor(const string& id, const string& fullName, int birthYear,
                     const string& address, const string& phone, const string& email,
                     const string& code, const string& specialization);

    void updateMember(const string& identifier, const string& fullName, int birthYear,
                     const string& address, const string& phone, const string& email);

    void deleteMember(const string& identifier);

    // Διαχείριση εγγραφών σε μαθήματα
    void enrollStudent(const string& studentRegNumber, const string& courseCode);

    // Διαχείριση βαθμών
    void setGrade(const string& studentRegNumber, const string& courseCode, float grade);
    float getGrade(const string& studentRegNumber, const string& courseCode) const;

    // Αποστολή email
    void sendEmailToAllStudents(const string& message);
    void sendEmailToAllProfessors(const string& message);

    // Διαχείριση CSV αρχείων
    void saveToCSV() const;
    void loadFromCSV();

    // Εμφάνιση πληροφοριών
    void displayAllCourses() const;
    void displayAllStudents() const;
    void displayAllProfessors() const;

    // Κάνουμε τη findStudent public για να μπορεί να χρησιμοποιηθεί στο main
    friend class Student;  // Επιτρέπουμε στην Student να έχει πρόσβαση στο findCourse
};

#endif
