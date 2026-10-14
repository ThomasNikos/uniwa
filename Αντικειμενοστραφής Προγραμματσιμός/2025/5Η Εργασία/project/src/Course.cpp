#include "../include/Course.h"
#include "../include/Exceptions.h"
#include <iostream>

// Constructor
Course::Course(const string& code, const string& name, int semester, Professor* professor)
    : code(code), name(name), semester(semester), professor(professor) {
    if (semester < 1 || semester > 8) {
        throw InvalidDataException("Μη έγκυρο εξάμηνο μαθήματος");
    }
    if (!professor) {
        throw InvalidDataException("Δεν έχει οριστεί καθηγητής για το μάθημα");
    }
}

// Copy constructor
Course::Course(const Course& other)
    : code(other.code), name(other.name), semester(other.semester),
      professor(other.professor), grades(other.grades) {
}

// Destructor
Course::~Course() {
    // Δεν διαγράφουμε τον καθηγητή λόγω Registry
}

// Getters
string Course::getCode() const {
    return code;
}

string Course::getName() const {
    return name;
}

int Course::getSemester() const {
    return semester;
}

Professor* Course::getProfessor() const {
    return professor;
}

float Course::getGrade(const string& studentId) const {
    auto it = grades.find(studentId);
    if (it == grades.end()) {
        throw NotFoundException("Δεν βρέθηκε βαθμός για τον συγκεκριμένο φοιτητή");
    }
    return it->second;
}

const map<string, float>& Course::getAllGrades() const {
    return grades;
}

// Setters
void Course::setCode(const string& code) {
    if (code.empty()) {
        throw InvalidDataException("Ο κωδικός μαθήματος δεν μπορεί να είναι κενός");
    }
    this->code = code;
}

void Course::setName(const string& name) {
    if (name.empty()) {
        throw InvalidDataException("Το όνομα μαθήματος δεν μπορεί να είναι κενό");
    }
    this->name = name;
}

void Course::setSemester(int semester) {
    if (semester < 1 || semester > 8) {
        throw InvalidDataException("Μη έγκυρο εξάμηνο μαθήματος");
    }
    this->semester = semester;
}

void Course::setProfessor(Professor* professor) {
    if (!professor) {
        throw InvalidDataException("Δεν έχει οριστεί καθηγητής για το μάθημα");
    }
    this->professor = professor;
}

// Διαχείριση βαθμών
void Course::setGrade(const string& studentId, float grade) {
    if (grade < 0 || grade > 10) {
        throw InvalidGradeException("Ο βαθμός πρέπει να είναι μεταξύ 0 και 10");
    }
    grades[studentId] = grade;
}

void Course::removeGrade(const string& studentId) {
    auto it = grades.find(studentId);
    if (it == grades.end()) {
        throw NotFoundException("Δεν βρέθηκε βαθμός για τον συγκεκριμένο φοιτητή");
    }
    grades.erase(it);
}

bool Course::hasGrade(const string& studentId) const {
    return grades.find(studentId) != grades.end();
}

// Εμφάνιση πληροφοριών μαθήματος
void Course::display() const {
    cout << "Κωδικός Μαθήματος: " << code << endl;
    cout << "Όνομα Μαθήματος: " << name << endl;
    cout << "Εξάμηνο: " << semester << endl;
    cout << "Διδάσκων: " << professor->getFullName() << endl;
    cout << "Αριθμός εγγεγραμμένων βαθμών: " << grades.size() << endl;
}
