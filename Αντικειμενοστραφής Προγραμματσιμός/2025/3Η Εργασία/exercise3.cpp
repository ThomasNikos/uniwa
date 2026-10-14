#include <iostream>
#include <cstring>
using namespace std;

void insertString(char**& strings, int& count, const char* newString) {
    // Έλεγχος διπλότυπων
    for (int i = 0; i < count; i++) {
        if (strcmp(strings[i], newString) == 0) {
            return;  // Αν υπάρχει ήδη, δεν προσθέτουμε
        }
    }

    // Δημιουργία νέου πίνακα με ένα επιπλέον στοιχείο
    char** temp = new char*[count + 1];

    // Αντιγραφή υπαρχόντων συμβολοσειρών
    for (int i = 0; i < count; i++) {
        temp[i] = strings[i];
    }

    // Προσθήκη νέας συμβολοσειράς
    int len = strlen(newString);
    temp[count] = new char[len + 1];
    strcpy(temp[count], newString);

    // Απελευθέρωση παλιού πίνακα
    delete[] strings;
    strings = temp;
    count++;
}

void deleteString(char**& strings, int& count, const char* stringToDelete) {
    for (int i = 0; i < count; i++) {
        if (strcmp(strings[i], stringToDelete) == 0) {
            // Απελευθέρωση μνήμης της συγκεκριμένης συμβολοσειράς
            delete[] strings[i];

            // Δημιουργία νέου πίνακα με ένα λιγότερο στοιχείο
            char** temp = new char*[count - 1];

            // Αντιγραφή πριν τη διαγραφή του στοιχείου
            for (int j = 0; j < i; j++) {
                temp[j] = strings[j];
            }

            // Αντιγραφή μετά τη διαγραφή του στοιχείου
            for (int j = i + 1; j < count; j++) {
                temp[j - 1] = strings[j];
            }

            // Απελευθέρωση παλιού πίνακα
            delete[] strings;
            strings = temp;
            count--;
            return;
        }
    }
}

void printStrings(char** strings, int count) {
    for (int i = 0; i < count; i++) {
        cout << strings[i] << endl;
    }
}

int main() {
    char** strings = nullptr;
    int count = 0;

    insertString(strings, count, "nikos thomas");
    insertString(strings, count, "test string");
    insertString(strings, count, "nikos thomas");  // Διπλότυπο
    printStrings(strings, count);

    deleteString(strings, count, "nikos thomas");
    printStrings(strings, count);

    // Απελευθέρωση μνήμης
    for (int i = 0; i < count; i++) {
        delete[] strings[i];
    }
    delete[] strings;

    return 0;
}
