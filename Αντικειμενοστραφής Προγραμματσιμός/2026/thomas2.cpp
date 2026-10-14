#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Student {
private:
    char* id;
    string fullName;
    bool gender;  // false = Male, true = Female
    unsigned int semester;

public:

    // Constructor with id and name only (semester = 1)
    Student(const char* id, string name) {
        this->id = new char[strlen(id) + 1];
        strcpy(this->id, id);
        this->fullName = name;
        this->gender = false;
        this->semester = 1;
    }

    // Constructor with all fields
    Student(const char* id, string name, bool gender, unsigned int semester) {
        this->id = new char[strlen(id) + 1];
        strcpy(this->id, id);
        this->fullName = name;
        this->gender = gender;
        this->semester = semester;
    }

    // Copy constructor
    Student(const Student& other) {
        this->id = new char[strlen(other.id) + 1];
        strcpy(this->id, other.id);
        this->fullName = other.fullName;
        this->gender = other.gender;
        this->semester = other.semester;
    }

    // Destructor
    ~Student() {
        delete[] id;
    }

    // --- Getters ---
    char* getID() { return id; }
    string getFullName() { return fullName; }
    bool getGender() { return gender; }
    unsigned int getSemester() { return semester; }

    // --- Setters ---
    void setID(const char* newID) {
        delete[] id;
        id = new char[strlen(newID) + 1];
        strcpy(id, newID);
    }

    void setFullName(string newName) {
        fullName = newName;
    }

    void setGender(bool newGender) {
        gender = newGender;
    }

    void setSemester(unsigned int newSemester) {
        semester = newSemester;
    }

    // Print all fields to any ostream
    void print(ostream& os) {
        const char* cstr = fullName.c_str();
        int size = strlen(cstr) + 1;
        os << "ID: " << id
           << " | Name: " << fullName << "(" << size << ")"
           << " | Gender: " << (gender ? "Female" : "Male")
           << " | Semester: " << semester << "\n";
    }

    // pre-increment ++x
    Student& operator++() {
        semester++;
        return *this;
    }

    // post-increment x++
    Student operator++(int) {
        Student tmp(*this);
        semester++;
        return tmp;
    }

    // +=
    Student& operator+=(unsigned int n) {
        semester += n;
        return *this;
    }

    // -= (minimum semester = 1)
    Student& operator-=(unsigned int n) {
        if (semester > n)
            semester -= n;
        else
            semester = 1;
        return *this;
    }

    // unary - changes gender
    Student operator-() {
        Student tmp(*this);
        tmp.gender = !tmp.gender;
        return tmp;
    }

    friend ostream& operator<<(ostream& os, Student& s) {
        s.print(os);
        return os;
    }
};


int main() {

    int n = 6;
    Student** students = new Student*[n];

    // students with Latin characters
    students[0] = new Student("2019001", "Nikos Papadopoulos", false, 4);
    students[1] = new Student("2021002", "Maria Georgiou", true, 2);
    students[2] = new Student("2022003", "Kostas Nikolaou");  // semester = 1

    // students with Greek characters
    students[3] = new Student("2020004", "Ελενη Δημητριου", true, 3);
    students[4] = new Student("2021005", "Γιωργος Αντωνιου", false, 5);

    // copy constructor - copy of students[0]
    students[5] = new Student(*students[0]);

    cout << "=== All students ===" << endl;
    for (int i = 0; i < n; i++) {
        students[i]->print(cout);
    }

    // test pre-increment
    cout << "\n-- Pre-increment (++students[0]) --" << endl;
    ++(*students[0]);
    cout << *students[0];

    // test post-increment
    cout << "\n-- Post-increment (students[1]++) --" << endl;
    (*students[1])++;
    cout << *students[1];

    // test +=
    cout << "\n-- students[2] += 3 --" << endl;
    *students[2] += 3;
    cout << *students[2];

    // test -=
    cout << "\n-- students[3] -= 2 --" << endl;
    *students[3] -= 2;
    cout << *students[3];

    // test unary - (gender change)
    cout << "\n-- Gender change on students[4] using unary - --" << endl;
    Student changed = -(*students[4]);
    cout << changed;

    // test setter
    cout << "\n-- setSemester(8) on students[5] --" << endl;
    students[5]->setSemester(8);
    cout << *students[5];

    // free memory
    for (int i = 0; i < n; i++) {
        delete students[i];
    }
    delete[] students;

    return 0;
}
