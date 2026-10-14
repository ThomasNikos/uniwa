#include "Student.h"
#include <stdexcept>

Student::Student(const char* id, const string& name)
    : Person(id, name, false), semester(1) {}

Student::Student(const char* id, const string& name, bool gender, unsigned int semester)
    : Person(id, name, gender), semester(semester) {
    if (semester == 0)
        throw invalid_argument("Semester must be greater than 0");
}

Student::Student(const Student& other)
    : Person(other), semester(other.semester) {
    for (Course* c : other.courses)
        courses.push_back(c);
}

Student::~Student() {}

unsigned int Student::getSemester() const { return semester; }

void Student::setSemester(unsigned int s) {
    if (s == 0)
        throw invalid_argument("Semester must be greater than 0");
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
    const char* cstr = fullName.c_str();
    int size = strlen(cstr) + 1;
    os << "Φοιτητής  | ΑΜ: " << code
       << " | Ονομ: " << fullName << "(" << size << ")"
       << " | Φύλο: " << (gender ? "Γυναίκα" : "Άνδρας")
       << " | Εξάμηνο: " << semester
       << " | Μαθήματα: " << courses.size() << "\n";
}

void Student::sendEmail() const {
    cout << "[EMAIL Φοιτητή] Αποστολή ενημερωτικού email στον/στην " << fullName
         << " <" << code << "@students.university.gr>\n";
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
