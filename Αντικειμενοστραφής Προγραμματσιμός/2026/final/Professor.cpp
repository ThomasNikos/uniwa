#include "Professor.h"
#include <iostream>

Professor::Professor(const char* code, const string& name, bool gender, const string& specialty)
    : Person(code, name, gender), specialty(specialty) {}

Professor::Professor(const Professor& other)
    : Person(other), specialty(other.specialty) {
    for (int i = 0; i < (int)other.courses.size(); i++)
        courses.push_back(other.courses[i]);
}

Professor::~Professor() {}

string Professor::getSpecialty() const { return specialty; }
void Professor::setSpecialty(const string& s) { specialty = s; }

void Professor::addCourse(Course* c) {
    courses.push_back(c);
}

void Professor::removeCourse(const string& courseCode) {
    for (int i = 0; i < (int)courses.size(); i++) {
        if (courses[i]->getCode() == courseCode) {
            courses.erase(courses.begin() + i);
            return;
        }
    }
}

const vector<Course*>& Professor::getCourses() const { return courses; }

void Professor::print(ostream& os) const {
    os << "Καθηγητής | Κωδ: " << code
       << " | Ονοματεπώνυμο: " << fullName
       << " | Φύλο: " << (gender ? "Γυναίκα" : "Άνδρας")
       << " | Ειδικότητα: " << specialty
       << " | Μαθήματα: " << courses.size() << "\n";
}

void Professor::sendEmail() const {
    cout << "[EMAIL Καθηγητή] Αποστολή θεσμικού email στον/στην "
         << fullName << " <" << code << "@uniwa.gr>\n";
}

string Professor::getType() const { return "Professor"; }
