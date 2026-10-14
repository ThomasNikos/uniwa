#include "../include/Registry.h"
#include "../include/Exceptions.h"
#include <iostream>

int main() {
    try {
        Registry registry;

        registry.addProfessor("ΑΤ123456", "Γεώργιος Παπαδόπουλος", 1975,
                            "Πατησίων 76, Αθήνα", "2105678901", "gpapadopoulos@gmail.com",
                            "PROF001", "Πληροφορική");
	registry.addProfessor("ΑΤ234567", "Νίκος Θωμάς", 1980,
                            "Δωδεκανήσου 14, Αθήνα", "6947558708", "ice21390068@uniwa.gr",
                            "PROF002", "Μαθηματικά");

        registry.addCourse("CS101", "Εισαγωγή στον Προγραμματισμό", 1, "PROF001");
        registry.addCourse("CS102", "Αντικειμενοστρεφής Προγραμματισμός", 2, "PROF001");
        registry.addCourse("MATH101", "Μαθηματική Ανάλυση", 1, "PROF002");

        registry.addStudent("ΑΤ345678", "Νίκος Αντωνίου", 2000,
                          "Ιπποκράτους 12, Αθήνα", "6912345678", "nantonious@example.com",
                          "2023001", 2);

        registry.addStudent("ΑΤ456789", "Ελένη Παπαδοπούλου", 2001,
                          "Ακαδημίας 34, Αθήνα", "6923456789", "epapadopoulou@example.com",
                          "2023002", 1);

        registry.enrollStudent("2023001", "CS101");
        registry.enrollStudent("2023001", "MATH101");
        registry.enrollStudent("2023002", "CS101");

        registry.setGrade("2023001", "CS101", 8.5);
        registry.setGrade("2023001", "MATH101", 7.0);
        registry.setGrade("2023002", "CS101", 9.0);

        cout << "\n=== 6. Εμφάνιση Στοιχείων ===" << endl;
        registry.displayAllProfessors();
        registry.displayAllCourses();
        registry.displayAllStudents();

        cout << "\nΒαθμοί Φοιτητών:" << endl;
        cout << "Βαθμός φοιτητή 2023001 στο CS101: "
             << registry.getGrade("2023001", "CS101") << endl;
        cout << "Βαθμός φοιτητή 2023001 στο MATH101: "
             << registry.getGrade("2023001", "MATH101") << endl;
        cout << "Βαθμός φοιτητή 2023002 στο CS101: "
             << registry.getGrade("2023002", "CS101") << endl;

        cout << "\n=== 7. Αποστολή Email ===" << endl;
        registry.sendEmailToAllStudents("Καλώς ήρθατε στο νέο εξάμηνο!");
        registry.sendEmailToAllProfessors("Παρακαλώ υποβάλετε τη βαθμολογία έως 30/6");

        cout << "\n=== 8. Αποθήκευση σε CSV ===" << endl;
        registry.saveToCSV();

        cout << "\n=== 9. Φόρτωση από CSV και Επίδειξη ===" << endl;
        Registry newRegistry;
        newRegistry.loadFromCSV();

        cout << "\n--- Δεδομένα μετά τη φόρτωση ---" << endl;
        newRegistry.displayAllProfessors();
        newRegistry.displayAllCourses();
        newRegistry.displayAllStudents();

        cout << "\n=== 10. Επίδειξη Χειρισμού Εξαιρέσεων ===" << endl;
        try {
            registry.addStudent("ΑΤ999999", "Διπλή Εγγραφή", 2000,
                              "Διεύθυνση", "6912345678", "double@example.com",
                              "2023001", 1);
        } catch (const DuplicateEntryException& e) {
            cout << "Σφάλμα: " << e.what() << endl;
        }

        try {
            registry.setGrade("2023001", "CS101", 11);
        } catch (const InvalidGradeException& e) {
            cout << "Σφάλμα: " << e.what() << endl;
        }

        try {
            registry.getGrade("2023001", "CS999");
        } catch (const NotFoundException& e) {
            cout << "Σφάλμα: " << e.what() << endl;
        }

    } catch (const exception& e) {
        cerr << "Κρίσιμο σφάλμα: " << e.what() << endl;
        return 1;
    }

    return 0;
}
