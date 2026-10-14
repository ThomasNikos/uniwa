#include "Professor.h"

Professor::Professor(const char* code, const string& name, bool gender, const string& specialty)
    : Person(code, name, gender), specialty(specialty) {}

Professor::Professor(const Professor& other)
    : Person(other), specialty(other.specialty) {
    for (Course* c : other.courses)
        courses.push_back(c);
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
    const char* cstr = fullName.c_str();
    int size = strlen(cstr) + 1;
    os << "Καθηγητής | Κωδ: " << code
       << " | Ονομ: " << fullName << "(" << size << ")"
       << " | Φύλο: " << (gender ? "Γυναίκα" : "Άνδρας")
       << " | Ειδικότητα: " << specialty
       << " | Μαθήματα: " << courses.size() << "\n";
}

void Professor::sendEmail() const {
    cout << "[EMAIL Καθηγητή] Αποστολή θεσμικού email στον/στην " << fullName
         << " <" << code << "@university.gr>\n";
}

string Professor::getType() const { return "Professor"; }
