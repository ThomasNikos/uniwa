#include <iostream>
#include "Foititologio.h"

using namespace std;

int main() {
    Foititologio reg;

    // Δημιουργία καθηγητών
    Professor* p1 = new Professor("P001", "Γιάννης Παπαδόπουλος", false, "Τεχνητή Νοημοσύνη");
    Professor* p2 = new Professor("P002", "Μαρία Αντωνίου", true, "Δίκτυα Υπολογιστών");
    Professor* p3 = new Professor("P003", "John Smith", false, "Αλγόριθμοι");

    reg.addMember(p1);
    reg.addMember(p2);
    reg.addMember(p3);

    // Δημιουργία μαθημάτων
    Course* c1 = new Course("CS101", "Εισαγωγή στον Προγραμματισμό", 1, p1);
    Course* c2 = new Course("CS201", "Δομές Δεδομένων", 3, p3);
    Course* c3 = new Course("CS301", "Δίκτυα Η/Υ", 5, p2);
    Course* c4 = new Course("CS401", "Τεχνητή Νοημοσύνη", 7, p1);

    reg.addCourse(c1);
    reg.addCourse(c2);
    reg.addCourse(c3);
    reg.addCourse(c4);

    // Ανάθεση μαθημάτων σε καθηγητές
    p1->addCourse(c1);
    p1->addCourse(c4);
    p2->addCourse(c3);
    p3->addCourse(c2);

    // Δημιουργία φοιτητών
    Student* s1 = new Student("2019001", "Νίκος Παπαδόπουλος", false, 4);
    Student* s2 = new Student("2021002", "Ελένη Γεωργίου", true, 2);
    Student* s3 = new Student("2022003", "Alice Johnson");      // εξάμηνο = 1
    Student* s4 = new Student("2020004", "Γιώργος Αντωνίου", false, 6);

    reg.addMember(s1);
    reg.addMember(s2);
    reg.addMember(s3);
    reg.addMember(s4);

    // Εγγραφή φοιτητών σε μαθήματα
    s1->addCourse(c1);
    s1->addCourse(c2);
    s2->addCourse(c1);
    s2->addCourse(c3);
    s3->addCourse(c1);
    s4->addCourse(c2);
    s4->addCourse(c3);
    s4->addCourse(c4);

    // Εκτύπωση όλων
    cout << "\n";
    reg.printMembers(cout);
    cout << "\n";
    reg.printCourses(cout);

    // Τελεστές (από άσκηση 2)
    cout << "\n=== Τελεστές ===\n";
    cout << "Πριν ++s1: " << *s1;
    ++(*s1);
    cout << "Μετά ++s1: " << *s1;

    (*s2)++;
    cout << "Μετά s2++: " << *s2;

    *s4 += 2;
    cout << "Μετά s4+=2: " << *s4;

    *s1 -= 3;
    cout << "Μετά s1-=3: " << *s1;

    Student changed = -(*s3);
    cout << "Αλλαγή φύλου s3 (unary -): " << changed;

    // Αναζήτηση
    cout << "\n=== Αναζήτηση ===\n";
    Person* found = reg.findMember("2021002");
    if (found)
        cout << "Βρέθηκε: " << *found;

    Course* fc = reg.findCourse("CS201");
    if (fc)
        fc->print(cout);

    // Διόρθωση
    cout << "\n=== Διόρθωση ===\n";
    Person* toEdit = reg.findMember("2022003");
    if (toEdit) {
        toEdit->setFullName("Alice Johnson-Smith");
        cout << "Μετά αλλαγή ονόματος: " << *toEdit;
    }
    Student* toEditSem = dynamic_cast<Student*>(reg.findMember("2019001"));
    if (toEditSem) {
        toEditSem->setSemester(8);
        cout << "Μετά setSemester(8): " << *toEditSem;
    }

    // Email
    cout << "\n";
    reg.emailStudents();
    cout << "\n";
    reg.emailProfessors();

    // Χειρισμός εξαιρέσεων
    cout << "\n=== Εξαιρέσεις ===\n";
    {
        Student* dup = new Student("2019001", "Διπλός Φοιτητής");
        try {
            reg.addMember(dup);
        } catch (const invalid_argument& e) {
            cout << "Εξαίρεση: " << e.what() << "\n";
            delete dup;
        }
    }
    try {
        reg.removeMember("NOTEXIST");
    } catch (const invalid_argument& e) {
        cout << "Εξαίρεση: " << e.what() << "\n";
    }
    try {
        reg.addCourse(new Course("CS101", "Διπλό μάθημα", 1));
    } catch (const invalid_argument& e) {
        cout << "Εξαίρεση: " << e.what() << "\n";
    }

    // Διαγραφή μέλους
    cout << "\n=== Διαγραφή P003 ===\n";
    reg.removeMember("P003");
    reg.printMembers(cout);
    cout << "\n";
    reg.printCourses(cout); // CS201 responsible = "-" τώρα

    // Αποθήκευση σε CSV
    cout << "\n=== Αποθήκευση CSV ===\n";
    try {
        reg.saveToCSV(".");
    } catch (const runtime_error& e) {
        cout << "Σφάλμα: " << e.what() << "\n";
    }

    // Φόρτωση από CSV σε νέο Foititologio
    cout << "\n=== Φόρτωση CSV ===\n";
    Foititologio reg2;
    try {
        reg2.loadFromCSV(".");
    } catch (const runtime_error& e) {
        cout << "Σφάλμα: " << e.what() << "\n";
        return 1;
    }
    cout << "\n";
    reg2.printMembers(cout);
    cout << "\n";
    reg2.printCourses(cout);

    return 0;
}
