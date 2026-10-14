#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

int main() {
    // Μέγεθος πίνακα ατόμων
    const int arraySize = 4;

    // Δημιουργία δυναμικού πίνακα ατόμων
    Person** peopleArray = new Person*[arraySize];

    // Άτομο 1 - Πλήρης constructor
    peopleArray[0] = new Person("21390068", "Θωμάς Νικόλαος", 2003,
                               "Ηράκλειο Αττικής", "6947558708", "thomasnikos1@gmail.com");
    // Άτομο 2 - Βασικός constructor
    peopleArray[1] = new Person("21000000", "Δεύτερο Άτομο", 1990);

    // Άτομο 3 - Πλήρης constructor
    peopleArray[2] = new Person("21000001", "Τρίτο Άτομο", 1975,
                               "Καλαμάτα 15", "2106789012", "random@random.gr");

    // Άτομο 4 - Copy constructor (αντιγραφή του ατόμου 3)
    peopleArray[3] = new Person(*peopleArray[2]);

    // Εμφάνιση όλων των ατόμων
    cout << "\nΕΜΦΑΝΙΣΗ ΟΛΩΝ ΤΩΝ ΑΤΟΜΩΝ:" << endl;
    for (int i = 0; i < arraySize; i++) {
        cout << "\nΆτομο " << (i + 1) << ":" << endl;
        peopleArray[i]->display();
    }

    // Αλλαγές μέσω setters
    cout << "\nΑΛΛΑΓΗ ΣΤΟΙΧΕΙΩΝ ΤΟΥ ΑΤΟΜΟΥ 2:" << endl;
    peopleArray[1]->setAddress("Αθήνα 14");
    peopleArray[1]->setPhone("2310987654");
    peopleArray[1]->setEmail("random@random.gr");
    peopleArray[1]->display();

    // Επίδειξη αντιγραφής - Αλλαγή στοιχείων του ατόμου 4 (που είναι αντίγραφο του 3)
    cout << "\nΑΛΛΑΓΗ ΣΤΟΙΧΕΙΩΝ ΤΟΥ ΑΤΟΜΟΥ 4 (ΑΝΤΙΓΡΑΦΟ ΤΟΥ ΑΤΟΜΟΥ 3):" << endl;
    cout << "Αρχικά στοιχεία (αντίγραφο):" << endl;
    peopleArray[3]->display();

    peopleArray[3]->setFullName("Gmele");
    peopleArray[3]->setBirthYear(1978);

    cout << "\nΜετά την αλλαγή:" << endl;
    peopleArray[3]->display();

    // Μέθοδος getAge()
    cout << "\nΗΛΙΚΙΕΣ ΟΛΩΝ ΤΩΝ ΑΤΟΜΩΝ:" << endl;
    for (int i = 0; i < arraySize; i++) {
        cout << "Το άτομο " << peopleArray[i]->getFullName() 
             << " έχει ηλικία " << peopleArray[i]->getAge() << " ετών." << endl;
    }

    // Αποδέσμευση μνήμης
    for (int i = 0; i < arraySize; i++) {
        delete peopleArray[i];
    }
    delete[] peopleArray;

    return 0;
}
