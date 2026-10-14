#include "../include/Registry.h"
#include "../include/Exceptions.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

// Constructor & Destructor
Registry::Registry() {}

Registry::~Registry() {
    for (auto course : courses) {
        delete course;
    }
    for (auto member : members) {
        delete member;
    }
}

// Βοηθητικές μέθοδοι εύρεσης
Student* Registry::findStudent(const string& registrationNumber) {
    for (auto member : members) {
        if (auto* student = dynamic_cast<Student*>(member)) {
            if (student->getRegistrationNumber() == registrationNumber) {
                return student;
            }
        }
    }
    return nullptr;
}

Professor* Registry::findProfessor(const string& code) {
    for (auto member : members) {
        if (auto* professor = dynamic_cast<Professor*>(member)) {
            if (professor->getCode() == code) {
                return professor;
            }
        }
    }
    return nullptr;
}

Course* Registry::findCourse(const string& code) {
    for (auto course : courses) {
        if (course->getCode() == code) {
            return course;
        }
    }
    return nullptr;
}

// Διαχείριση μαθημάτων
void Registry::addCourse(const string& code, const string& name, int semester, const string& professorCode) {
    if (findCourse(code)) {
        throw DuplicateEntryException("Υπάρχει ήδη μάθημα με αυτόν τον κωδικό");
    }

    auto* professor = findProfessor(professorCode);
    if (!professor) {
        throw NotFoundException("Δεν βρέθηκε καθηγητής με τον συγκεκριμένο κωδικό");
    }

    courses.push_back(new Course(code, name, semester, professor));
}

void Registry::updateCourse(const string& code, const string& name, int semester, const string& professorCode) {
    auto* course = findCourse(code);
    if (!course) {
        throw NotFoundException("Δεν βρέθηκε το μάθημα");
    }

    auto* professor = findProfessor(professorCode);
    if (!professor) {
        throw NotFoundException("Δεν βρέθηκε καθηγητής με τον συγκεκριμένο κωδικό");
    }

    course->setName(name);
    course->setSemester(semester);
    course->setProfessor(professor);
}

void Registry::deleteCourse(const string& code) {
    auto it = find_if(courses.begin(), courses.end(),
        [&code](Course* c) { return c->getCode() == code; });

    if (it == courses.end()) {
        throw NotFoundException("Δεν βρέθηκε το μάθημα");
    }

    delete *it;
    courses.erase(it);
}

// Διαχείριση μελών
void Registry::addStudent(const string& id, const string& fullName, int birthYear,
                        const string& address, const string& phone, const string& email,
                        const string& registrationNumber, int semester) {
    if (findStudent(registrationNumber)) {
        throw DuplicateEntryException("Υπάρχει ήδη φοιτητής με αυτόν τον αριθμό μητρώου");
    }

    members.push_back(new Student(id, fullName, birthYear, address, phone, email,
                                registrationNumber, semester));
}

void Registry::addProfessor(const string& id, const string& fullName, int birthYear,
                          const string& address, const string& phone, const string& email,
                          const string& code, const string& specialization) {
    if (findProfessor(code)) {
        throw DuplicateEntryException("Υπάρχει ήδη καθηγητής με αυτόν τον κωδικό");
    }

    members.push_back(new Professor(id, fullName, birthYear, address, phone, email,
                                  code, specialization));
}

void Registry::updateMember(const string& identifier, const string& fullName, int birthYear,
                          const string& address, const string& phone, const string& email) {
    Person* member = findStudent(identifier);
    if (!member) {
        member = findProfessor(identifier);
    }

    if (!member) {
        throw NotFoundException("Δεν βρέθηκε μέλος με το συγκεκριμένο αναγνωριστικό");
    }

    member->setFullName(fullName);
    member->setBirthYear(birthYear);
    member->setAddress(address);
    member->setPhone(phone);
    member->setEmail(email);
}

void Registry::deleteMember(const string& identifier) {
    auto it = find_if(members.begin(), members.end(),
        [&identifier](Person* p) {
            if (auto* student = dynamic_cast<Student*>(p)) {
                return student->getRegistrationNumber() == identifier;
            }
            if (auto* professor = dynamic_cast<Professor*>(p)) {
                return professor->getCode() == identifier;
            }
            return false;
        });

    if (it == members.end()) {
        throw NotFoundException("Δεν βρέθηκε μέλος με το συγκεκριμένο αναγνωριστικό");
    }

    delete *it;
    members.erase(it);
}

// Διαχείριση εγγραφών σε μαθήματα
void Registry::enrollStudent(const string& studentRegNumber, const string& courseCode) {
    Student* student = findStudent(studentRegNumber);
    if (!student) {
        throw NotFoundException("Δεν βρέθηκε ο φοιτητής");
    }

    Course* course = findCourse(courseCode);
    if (!course) {
        throw NotFoundException("Δεν βρέθηκε το μάθημα");
    }

    student->addCourse(course);
}

// Διαχείριση βαθμών
void Registry::setGrade(const string& studentRegNumber, const string& courseCode, float grade) {
    auto* student = findStudent(studentRegNumber);
    if (!student) {
        throw NotFoundException("Δεν βρέθηκε ο φοιτητής");
    }

    auto* course = findCourse(courseCode);
    if (!course) {
        throw NotFoundException("Δεν βρέθηκε το μάθημα");
    }

    if (!student->isEnrolledIn(courseCode)) {
        throw InvalidDataException("Ο φοιτητής δεν είναι εγγεγραμμένος στο μάθημα");
    }

    course->setGrade(studentRegNumber, grade);
}

float Registry::getGrade(const string& studentRegNumber, const string& courseCode) const {
    for (auto member : members) {
        if (auto* student = dynamic_cast<Student*>(member)) {
            if (student->getRegistrationNumber() == studentRegNumber) {
                return student->getGrade(courseCode);
            }
        }
    }
    throw NotFoundException("Δεν βρέθηκε ο φοιτητής");
}

// Αποστολή email
void Registry::sendEmailToAllStudents(const string& message) {
    for (auto member : members) {
        if (auto* student = dynamic_cast<Student*>(member)) {
            student->sendEmail(message);
        }
    }
}

void Registry::sendEmailToAllProfessors(const string& message) {
    for (auto member : members) {
        if (auto* professor = dynamic_cast<Professor*>(member)) {
            professor->sendEmail(message);
        }
    }
}

// Διαχείριση CSV αρχείων
void Registry::saveToCSV() const {
    saveMembersToCSV();
    saveCoursesToCSV();
    saveEnrollmentsToCSV();
}

void Registry::loadFromCSV() {
    loadMembersFromCSV();
    loadCoursesFromCSV();
    loadEnrollmentsFromCSV();
}

void Registry::saveMembersToCSV() const {
    ofstream studentsFile("students.csv");
    ofstream professorsFile("professors.csv");

    if (!studentsFile || !professorsFile) {
        throw FileException("Αδυναμία δημιουργίας αρχείων CSV");
    }

    // Αποθήκευση επικεφαλίδων
    studentsFile << "\xEF\xBB\xBF";
    professorsFile << "\xEF\xBB\xBF";
    studentsFile << "id,fullName,birthYear,address,phone,email,registrationNumber,semester\n";
    professorsFile << "id,fullName,birthYear,address,phone,email,code,specialization\n";

    // Αποθήκευση μελών
    for (const Person* person : members) {
        const Student* student = dynamic_cast<const Student*>(person);
        if (student) {
            studentsFile << student->getId() << ","
                        << student->getFullName() << ","
                        << student->getBirthYear() << ","
                        << student->getAddress() << ","
                        << student->getPhone() << ","
                        << student->getEmail() << ","
                        << student->getRegistrationNumber() << ","
                        << student->getSemester() << "\n";
        }

        const Professor* professor = dynamic_cast<const Professor*>(person);
        if (professor) {
            professorsFile << professor->getId() << ","
                         << professor->getFullName() << ","
                         << professor->getBirthYear() << ","
                         << professor->getAddress() << ","
                         << professor->getPhone() << ","
                         << professor->getEmail() << ","
                         << professor->getCode() << ","
                         << professor->getSpecialization() << "\n";
        }
    }
}

void Registry::saveCoursesToCSV() const {
    ofstream coursesFile("courses.csv");
    if (!coursesFile) {
        throw FileException("Αδυναμία δημιουργίας αρχείου courses.csv");
    }

    // Αποθήκευση επικεφαλίδας
    coursesFile << "\xEF\xBB\xBF";
    coursesFile << "code,name,semester,professorCode\n";

    // Αποθήκευση μαθημάτων
    for (const Course* course : courses) {
        coursesFile << course->getCode() << ","
                   << course->getName() << ","
                   << course->getSemester() << ","
                   << course->getProfessor()->getCode() << "\n";
    }
}

void Registry::saveEnrollmentsToCSV() const {
    ofstream enrollmentsFile("enrollments.csv");
    if (!enrollmentsFile) {
        throw FileException("Αδυναμία δημιουργίας αρχείου enrollments.csv");
    }

    // Αποθήκευση επικεφαλίδας
    enrollmentsFile << "\xEF\xBB\xBF";
    enrollmentsFile << "registrationNumber,courseCode,grade\n";

    // Αποθήκευση εγγραφών και βαθμών
    for (const Person* person : members) {
        const Student* student = dynamic_cast<const Student*>(person);
        if (student) {
            for (const Course* course : student->getCourses()) {
                float grade = -1;  // -1 για μη καταχωρημένο βαθμό
                try {
                    grade = student->getGrade(course->getCode());
                } catch (...) {
                    // Αν δεν υπάρχει βαθμός, συνεχίζουμε με -1
                }
                enrollmentsFile << student->getRegistrationNumber() << ","
                              << course->getCode() << ","
                              << grade << "\n";
            }
        }
    }
}

void Registry::loadMembersFromCSV() {
    // Καθαρισμός υπάρχοντων μελών
    for (Person* person : members) {
        delete person;
    }
    members.clear();

    // Φόρτωση φοιτητών
    ifstream studentsFile("students.csv");
    if (studentsFile) {
        string line;
        getline(studentsFile, line);  // Παράλειψη επικεφαλίδας
        while (getline(studentsFile, line)) {
            stringstream ss(line);
            string id, fullName, address, phone, email, regNumber;
            int birthYear, semester;

            getline(ss, id, ',');
            getline(ss, fullName, ',');
            ss >> birthYear; ss.ignore();
            getline(ss, address, ',');
            getline(ss, phone, ',');
            getline(ss, email, ',');
            getline(ss, regNumber, ',');
            ss >> semester;

            addStudent(id, fullName, birthYear, address, phone, email, regNumber, semester);
        }
    }

    // Φόρτωση καθηγητών
    ifstream professorsFile("professors.csv");
    if (professorsFile) {
        string line;
        getline(professorsFile, line);  // Παράλειψη επικεφαλίδας
        while (getline(professorsFile, line)) {
            stringstream ss(line);
            string id, fullName, address, phone, email, code, specialization;
            int birthYear;

            getline(ss, id, ',');
            getline(ss, fullName, ',');
            ss >> birthYear; ss.ignore();
            getline(ss, address, ',');
            getline(ss, phone, ',');
            getline(ss, email, ',');
            getline(ss, code, ',');
            getline(ss, specialization);

            addProfessor(id, fullName, birthYear, address, phone, email, code, specialization);
        }
    }
}

void Registry::loadCoursesFromCSV() {
    // Καθαρισμός υπάρχοντων μαθημάτων
    for (Course* course : courses) {
        delete course;
    }
    courses.clear();

    ifstream coursesFile("courses.csv");
    if (coursesFile) {
        string line;
        getline(coursesFile, line);  // Παράλειψη επικεφαλίδας
        while (getline(coursesFile, line)) {
            stringstream ss(line);
            string code, name, professorCode;
            int semester;

            getline(ss, code, ',');
            getline(ss, name, ',');
            ss >> semester; ss.ignore();
            getline(ss, professorCode);

            addCourse(code, name, semester, professorCode);
        }
    }
}

void Registry::loadEnrollmentsFromCSV() {
    ifstream enrollmentsFile("enrollments.csv");
    if (enrollmentsFile) {
        string line;
        getline(enrollmentsFile, line);  // Παράλειψη επικεφαλίδας
        while (getline(enrollmentsFile, line)) {
            stringstream ss(line);
            string regNumber, courseCode;
            float grade;

            getline(ss, regNumber, ',');
            getline(ss, courseCode, ',');
            ss >> grade;

            Student* student = findStudent(regNumber);
            Course* course = findCourse(courseCode);

            if (student && course) {
                student->addCourse(course);
                if (grade >= 0) {  // Αν υπάρχει βαθμός
                    setGrade(regNumber, courseCode, grade);
                }
            }
        }
    }
}

// Εμφάνιση πληροφοριών
void Registry::displayAllCourses() const {
    cout << "\n=== ΛΙΣΤΑ ΜΑΘΗΜΑΤΩΝ ===" << endl;
    for (auto course : courses) {
        course->display();
        cout << "------------------------" << endl;
    }
}

void Registry::displayAllStudents() const {
    cout << "\n=== ΛΙΣΤΑ ΦΟΙΤΗΤΩΝ ===" << endl;
    for (auto member : members) {
        if (auto* student = dynamic_cast<Student*>(member)) {
            student->display();
            cout << "------------------------" << endl;
        }
    }
}

void Registry::displayAllProfessors() const {
    cout << "\n=== ΛΙΣΤΑ ΚΑΘΗΓΗΤΩΝ ===" << endl;
    for (auto member : members) {
        if (auto* professor = dynamic_cast<Professor*>(member)) {
            professor->display();
            cout << "------------------------" << endl;
        }
    }
}
