#include "Course.h"
#include "Professor.h"
#include <stdexcept>

Course::Course(const string& code, const string& desc, unsigned int semester, Professor* resp) {
    if (code.empty())
        throw invalid_argument("Course code cannot be empty");
    if (semester == 0)
        throw invalid_argument("Semester must be greater than 0");
    this->code = code;
    this->description = desc;
    this->semester = semester;
    this->responsible = resp;
}

Course::Course(const Course& other)
    : code(other.code), description(other.description),
      semester(other.semester), responsible(other.responsible) {}

Course::~Course() {}

string Course::getCode() const { return code; }
string Course::getDescription() const { return description; }
unsigned int Course::getSemester() const { return semester; }
Professor* Course::getResponsible() const { return responsible; }

void Course::setCode(const string& c) {
    if (c.empty())
        throw invalid_argument("Course code cannot be empty");
    code = c;
}

void Course::setDescription(const string& d) { description = d; }

void Course::setSemester(unsigned int s) {
    if (s == 0)
        throw invalid_argument("Semester must be greater than 0");
    semester = s;
}

void Course::setResponsible(Professor* p) { responsible = p; }

void Course::print(ostream& os) const {
    os << "  [" << code << "] " << description << " | Εξάμηνο: " << semester << " | Υπεύθυνος: ";
    if (responsible != nullptr)
        os << responsible->getFullName();
    else
        os << "-";
    os << "\n";
}

ostream& operator<<(ostream& os, const Course& c) {
    c.print(os);
    return os;
}
