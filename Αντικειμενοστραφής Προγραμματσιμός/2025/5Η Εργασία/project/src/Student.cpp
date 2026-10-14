#include "../include/Student.h"
#include "../include/Exceptions.h"
#include <iostream>
#include <algorithm>

// Constructor
Student::Student(const string& id, const string& fullName, int birthYear,
                const string& address, const string& phone, const string& email,
                const string& registrationNumber, int semester)
    : Person(id, fullName, birthYear, address, phone, email),
      registrationNumber(registrationNumber), semester(semester) {
    if (registrationNumber.empty()) {
        throw InvalidDataException("Ο αριθμός μητρώου δεν μπορεί να είναι κενός");
    }
    if (semester < 1 || semester > 8) {
        throw InvalidDataException("Μη έγκυρο εξάμηνο φοίτησης");
    }
}

// Copy constructor
Student::Student(const Student& other)
    : Person(other), registrationNumber(other.registrationNumber),
      semester(other.semester), courses(other.courses) {
}

// Getters
string Student::getRegistrationNumber() const {
    return registrationNumber;
}

int Student::getSemester() const {
    return semester;
}

const vector<Course*>& Student::getCourses() const {
    return courses;
}

// Setters
void Student::setRegistrationNumber(const string& registrationNumber) {
    if (registrationNumber.empty()) {
        throw InvalidDataException("Ο αριθμός μητρώου δεν μπορεί να είναι κενός");
    }
    this->registrationNumber = registrationNumber;
}

void Student::setSemester(int semester) {
    if (semester < 1 || semester > 8) {
        throw InvalidDataException("Μη έγκυρο εξάμηνο φοίτησης");
    }
    this->semester = semester;
}

// Διαχείριση μαθημάτων
void Student::addCourse(Course* course) {
    if (!course) {
        throw InvalidDataException("Το μάθημα δεν μπορεί να είναι κενό");
    }

    // Έλεγχος αν το μάθημα υπάρχει ήδη
    if (isEnrolledIn(course->getCode())) {
        throw DuplicateEntryException("Ο φοιτητής είναι ήδη εγγεγραμμένος στο μάθημα");
    }

    // Έλεγχος εξαμήνου
    if (course->getSemester() > semester) {
        throw InvalidDataException("Δεν επιτρέπεται η δήλωση μαθήματος μεγαλύτερου εξαμήνου");
    }

    courses.push_back(course);
}

void Student::removeCourse(const string& courseCode) {
    auto it = find_if(courses.begin(), courses.end(),
                     [&courseCode](Course* c) { return c->getCode() == courseCode; });

    if (it == courses.end()) {
        throw NotFoundException("Το μάθημα δεν βρέθηκε στα δηλωμένα μαθήματα του φοιτητή");
    }

    courses.erase(it);
}

bool Student::isEnrolledIn(const string& courseCode) const {
    return find_if(courses.begin(), courses.end(),
                  [&courseCode](Course* c) { return c->getCode() == courseCode; }) != courses.end();
}

float Student::getGrade(const string& courseCode) const {
    auto it = find_if(courses.begin(), courses.end(),
                     [&courseCode](Course* c) { return c->getCode() == courseCode; });

    if (it == courses.end()) {
        throw NotFoundException("Το μάθημα δεν βρέθηκε στα δηλωμένα μαθήματα του φοιτητή");
    }

    return (*it)->getGrade(registrationNumber);
}

// Υλοποίηση της virtual μεθόδου display
void Student::display() const {
    Person::display();
    cout << "Αριθμός Μητρώου: " << registrationNumber << endl;
    cout << "Εξάμηνο: " << semester << endl;
    cout << "Δηλωμένα Μαθήματα:" << endl;
    for (const auto& course : courses) {
        cout << "  - " << course->getCode() << ": " << course->getName();
        try {
            float grade = course->getGrade(registrationNumber);
            cout << " (Βαθμός: " << grade << ")";
        } catch (const NotFoundException&) {
            cout << " (Χωρίς βαθμό)";
        }
        cout << endl;
    }
}

// Pure virtual sendEmail
void Student::sendEmail(const string& message) {
    cout << "Αποστολή email στον/στην φοιτητή/τρια " << getFullName()
         << " (AM: " << registrationNumber << ", " << getEmail() << ")" << endl;
    cout << "Μήνυμα: " << message << endl;
}
