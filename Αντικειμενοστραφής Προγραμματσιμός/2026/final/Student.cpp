#include "Student.h"
#include <stdexcept>
#include <iostream>

Student::Student(const char* id, const string& name)
    : Person(id, name, false), semester(1) {}

Student::Student(const char* id, const string& name, bool gender, unsigned int semester)
    : Person(id, name, gender), semester(semester) {
    if (semester == 0)
        throw invalid_argument("Το εξάμηνο πρέπει να είναι > 0");
}

Student::Student(const Student& other)
    : Person(other), semester(other.semester) {
    for (int i = 0; i < (int)other.courses.size(); i++)
        courses.push_back(other.courses[i]);
}

Student::~Student() {}

unsigned int Student::getSemester() const { return semester; }

void Student::setSemester(unsigned int s) {
    if (s == 0)
        throw invalid_argument("Το εξάμηνο πρέπει να είναι > 0");
    semester = s;
}

void Student::addCourse(Course* c) { courses.push_back(c); }

void Student::removeCourse(const string& courseCode) {
    for (int i = 0; i < (int)courses.size(); i++) {
        if (courses[i]->getCode() == courseCode) {
            courses.erase(courses.begin() + i);
            return;
        }
    }
}

const vector<Course*>& Student::getCourses() const { return courses; }

void Student::print(ostream& os) const {
    os << "Φοιτητής  | ΑΜ: " << code
       << " | Ονοματεπώνυμο: " << fullName
       << " | Φύλο: " << (gender ? "Γυναίκα" : "Άνδρας")
       << " | Εξάμηνο: " << semester
       << " | Μαθήματα: " << courses.size() << "\n";
}

void Student::sendEmail() const {
    cout << "[EMAIL Φοιτητή] Αποστολή ενημερωτικού email στον/στην "
         << fullName << " <" << code << "@students.uniwa.gr>\n";
}

string Student::getType() const { return "Student"; }

Student& Student::operator++() {
    semester++;
    return *this;
}

Student Student::operator++(int) {
    Student tmp(*this);
    semester++;
    return tmp;
}

Student& Student::operator+=(unsigned int n) {
    semester += n;
    return *this;
}

Student& Student::operator-=(unsigned int n) {
    if (semester > n)
        semester -= n;
    else
        semester = 1;
    return *this;
}

Student Student::operator-() const {
    Student tmp(*this);
    tmp.gender = !tmp.gender;
    return tmp;
}
