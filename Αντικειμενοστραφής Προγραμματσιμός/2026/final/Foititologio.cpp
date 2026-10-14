#include "Foititologio.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>

Foititologio::Foititologio()
    : members(nullptr), memberCount(0), memberCapacity(0),
      courses(nullptr), courseCount(0), courseCapacity(0) {}

Foititologio::~Foititologio() {
    for (int i = 0; i < memberCount; i++)
        delete members[i];
    delete[] members;
    for (int i = 0; i < courseCount; i++)
        delete courses[i];
    delete[] courses;
}

void Foititologio::expandMembers() {
    int newCap = (memberCapacity == 0) ? 4 : memberCapacity * 2;
    Person** newArr = new Person*[newCap];
    for (int i = 0; i < memberCount; i++)
        newArr[i] = members[i];
    delete[] members;
    members = newArr;
    memberCapacity = newCap;
}

void Foititologio::expandCourses() {
    int newCap = (courseCapacity == 0) ? 4 : courseCapacity * 2;
    Course** newArr = new Course*[newCap];
    for (int i = 0; i < courseCount; i++)
        newArr[i] = courses[i];
    delete[] courses;
    courses = newArr;
    courseCapacity = newCap;
}

void Foititologio::addMember(Person* p) {
    if (findMember(p->getCode()) != nullptr)
        throw invalid_argument(string("Μέλος με κωδικό ") + p->getCode() + " υπάρχει ήδη");
    if (memberCount == memberCapacity)
        expandMembers();
    members[memberCount++] = p;
}

void Foititologio::removeMember(const char* code) {
    for (int i = 0; i < memberCount; i++) {
        if (strcmp(members[i]->getCode(), code) == 0) {
            if (members[i]->getType() == "Professor") {
                for (int j = 0; j < courseCount; j++) {
                    if (courses[j]->getResponsible() == members[i])
                        courses[j]->setResponsible(nullptr);
                }
            }
            delete members[i];
            for (int j = i; j < memberCount - 1; j++)
                members[j] = members[j + 1];
            memberCount--;
            return;
        }
    }
    throw invalid_argument(string("Μέλος με κωδικό ") + code + " δεν βρέθηκε");
}

Person* Foititologio::findMember(const char* code) const {
    for (int i = 0; i < memberCount; i++) {
        if (strcmp(members[i]->getCode(), code) == 0)
            return members[i];
    }
    return nullptr;
}

void Foititologio::addCourse(Course* c) {
    if (findCourse(c->getCode()) != nullptr)
        throw invalid_argument("Μάθημα με κωδικό " + c->getCode() + " υπάρχει ήδη");
    if (courseCount == courseCapacity)
        expandCourses();
    courses[courseCount++] = c;
}

void Foititologio::removeCourse(const string& code) {
    for (int i = 0; i < courseCount; i++) {
        if (courses[i]->getCode() == code) {
            for (int j = 0; j < memberCount; j++) {
                if (members[j]->getType() == "Student")
                    dynamic_cast<Student*>(members[j])->removeCourse(code);
                else
                    dynamic_cast<Professor*>(members[j])->removeCourse(code);
            }
            delete courses[i];
            for (int j = i; j < courseCount - 1; j++)
                courses[j] = courses[j + 1];
            courseCount--;
            return;
        }
    }
    throw invalid_argument("Μάθημα με κωδικό " + code + " δεν βρέθηκε");
}

Course* Foititologio::findCourse(const string& code) const {
    for (int i = 0; i < courseCount; i++) {
        if (courses[i]->getCode() == code)
            return courses[i];
    }
    return nullptr;
}

int Foititologio::getMemberCount() const { return memberCount; }

Person* Foititologio::getMemberAt(int i) const {
    if (i < 0 || i >= memberCount)
        throw out_of_range("Μη έγκυρος δείκτης μέλους");
    return members[i];
}

int Foititologio::getCourseCount() const { return courseCount; }

Course* Foititologio::getCourseAt(int i) const {
    if (i < 0 || i >= courseCount)
        throw out_of_range("Μη έγκυρος δείκτης μαθήματος");
    return courses[i];
}

void Foititologio::emailStudents() const {
    cout << "=== Αποστολή email σε όλους τους φοιτητές ===\n";
    for (int i = 0; i < memberCount; i++) {
        if (members[i]->getType() == "Student")
            members[i]->sendEmail();
    }
}

void Foititologio::emailProfessors() const {
    cout << "=== Αποστολή email σε όλους τους καθηγητές ===\n";
    for (int i = 0; i < memberCount; i++) {
        if (members[i]->getType() == "Professor")
            members[i]->sendEmail();
    }
}

void Foititologio::printMembers(ostream& os) const {
    os << "=== Μέλη (" << memberCount << ") ===\n";
    for (int i = 0; i < memberCount; i++)
        members[i]->print(os);
}

void Foititologio::printCourses(ostream& os) const {
    os << "=== Μαθήματα (" << courseCount << ") ===\n";
    for (int i = 0; i < courseCount; i++)
        courses[i]->print(os);
}

// CSV format:
//   professors.csv: code,name,gender,specialty,course1;course2;...
//   students.csv:   code,name,gender,semester,course1;course2;...
//   courses.csv:    code,description,semester,responsible_code

void Foititologio::saveToCSV(const string& dir) const {
    {
        ofstream f(dir + "/professors.csv");
        if (!f.is_open())
            throw runtime_error("Αδυναμία ανοίγματος professors.csv για εγγραφή");
        f << "code,name,gender,specialty,courses\n";
        for (int i = 0; i < memberCount; i++) {
            Professor* p = dynamic_cast<Professor*>(members[i]);
            if (!p) continue;
            f << p->getCode() << ","
              << p->getFullName() << ","
              << (p->getGender() ? "F" : "M") << ","
              << p->getSpecialty() << ",";
            const vector<Course*>& pc = p->getCourses();
            for (int j = 0; j < (int)pc.size(); j++) {
                if (j > 0) f << ";";
                f << pc[j]->getCode();
            }
            f << "\n";
        }
    }
    {
        ofstream f(dir + "/courses.csv");
        if (!f.is_open())
            throw runtime_error("Αδυναμία ανοίγματος courses.csv για εγγραφή");
        f << "code,description,semester,responsible\n";
        for (int i = 0; i < courseCount; i++) {
            Course* c = courses[i];
            f << c->getCode() << ","
              << c->getDescription() << ","
              << c->getSemester() << ",";
            if (c->getResponsible() != nullptr)
                f << c->getResponsible()->getCode();
            f << "\n";
        }
    }
    {
        ofstream f(dir + "/students.csv");
        if (!f.is_open())
            throw runtime_error("Αδυναμία ανοίγματος students.csv για εγγραφή");
        f << "code,name,gender,semester,courses\n";
        for (int i = 0; i < memberCount; i++) {
            Student* s = dynamic_cast<Student*>(members[i]);
            if (!s) continue;
            f << s->getCode() << ","
              << s->getFullName() << ","
              << (s->getGender() ? "F" : "M") << ","
              << s->getSemester() << ",";
            const vector<Course*>& sc = s->getCourses();
            for (int j = 0; j < (int)sc.size(); j++) {
                if (j > 0) f << ";";
                f << sc[j]->getCode();
            }
            f << "\n";
        }
    }
}

void Foititologio::loadFromCSV(const string& dir) {
    for (int i = 0; i < memberCount; i++) delete members[i];
    memberCount = 0;
    for (int i = 0; i < courseCount; i++) delete courses[i];
    courseCount = 0;

    string line;

    // 1. Φόρτωση καθηγητών (χωρίς links μαθημάτων)
    {
        ifstream f(dir + "/professors.csv");
        if (!f.is_open())
            throw runtime_error("Αδυναμία ανοίγματος professors.csv για ανάγνωση");
        getline(f, line);
        while (getline(f, line)) {
            if (line.empty()) continue;
            istringstream ss(line);
            string pcode, name, gstr, spec, clist;
            getline(ss, pcode, ',');
            getline(ss, name, ',');
            getline(ss, gstr, ',');
            getline(ss, spec, ',');
            getline(ss, clist);
            bool g = (gstr == "F");
            addMember(new Professor(pcode.c_str(), name, g, spec));
        }
    }

    // 2. Φόρτωση μαθημάτων
    {
        ifstream f(dir + "/courses.csv");
        if (!f.is_open())
            throw runtime_error("Αδυναμία ανοίγματος courses.csv για ανάγνωση");
        getline(f, line);
        while (getline(f, line)) {
            if (line.empty()) continue;
            istringstream ss(line);
            string ccode, desc, semStr, respCode;
            getline(ss, ccode, ',');
            getline(ss, desc, ',');
            getline(ss, semStr, ',');
            getline(ss, respCode);
            unsigned int sem = (unsigned int)stoi(semStr);
            Professor* resp = nullptr;
            if (!respCode.empty()) {
                Person* p = findMember(respCode.c_str());
                if (p) resp = dynamic_cast<Professor*>(p);
            }
            addCourse(new Course(ccode, desc, sem, resp));
        }
    }

    // 3. Φόρτωση φοιτητών
    {
        ifstream f(dir + "/students.csv");
        if (!f.is_open())
            throw runtime_error("Αδυναμία ανοίγματος students.csv για ανάγνωση");
        getline(f, line);
        while (getline(f, line)) {
            if (line.empty()) continue;
            istringstream ss(line);
            string scode, name, gstr, semStr, clist;
            getline(ss, scode, ',');
            getline(ss, name, ',');
            getline(ss, gstr, ',');
            getline(ss, semStr, ',');
            getline(ss, clist);
            bool g = (gstr == "F");
            unsigned int sem = (unsigned int)stoi(semStr);
            Student* s = new Student(scode.c_str(), name, g, sem);
            if (!clist.empty()) {
                istringstream cs(clist);
                string cc;
                while (getline(cs, cc, ';')) {
                    Course* c = findCourse(cc);
                    if (c) s->addCourse(c);
                }
            }
            addMember(s);
        }
    }

    // 4. Δεύτερο πέρασμα: links μαθημάτων για καθηγητές
    {
        ifstream f(dir + "/professors.csv");
        if (!f.is_open())
            throw runtime_error("Αδυναμία ανοίγματος professors.csv για ανάγνωση");
        getline(f, line);
        while (getline(f, line)) {
            if (line.empty()) continue;
            istringstream ss(line);
            string pcode, name, gstr, spec, clist;
            getline(ss, pcode, ',');
            getline(ss, name, ',');
            getline(ss, gstr, ',');
            getline(ss, spec, ',');
            getline(ss, clist);
            if (clist.empty()) continue;
            Person* p = findMember(pcode.c_str());
            Professor* prof = dynamic_cast<Professor*>(p);
            if (!prof) continue;
            istringstream cs(clist);
            string cc;
            while (getline(cs, cc, ';')) {
                Course* c = findCourse(cc);
                if (c) prof->addCourse(c);
            }
        }
    }
}
