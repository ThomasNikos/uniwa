#include "../include/Professor.h"
#include "../include/Exceptions.h"
#include <iostream>

// Constructor
Professor::Professor(const string& id, const string& fullName, int birthYear,
                   const string& address, const string& phone, const string& email,
                   const string& code, const string& specialization)
    : Person(id, fullName, birthYear, address, phone, email),
      code(code), specialization(specialization) {
    if (code.empty()) {
        throw InvalidDataException("Ο κωδικός καθηγητή δεν μπορεί να είναι κενός");
    }
    if (specialization.empty()) {
        throw InvalidDataException("Η ειδικότητα δεν μπορεί να είναι κενή");
    }
}

// Copy constructor
Professor::Professor(const Professor& other)
    : Person(other), code(other.code), specialization(other.specialization) {
}

// Getters
string Professor::getCode() const {
    return code;
}

string Professor::getSpecialization() const {
    return specialization;
}

// Setters
void Professor::setCode(const string& code) {
    if (code.empty()) {
        throw InvalidDataException("Ο κωδικός καθηγητή δεν μπορεί να είναι κενός");
    }
    this->code = code;
}

void Professor::setSpecialization(const string& specialization) {
    if (specialization.empty()) {
        throw InvalidDataException("Η ειδικότητα δεν μπορεί να είναι κενή");
    }
    this->specialization = specialization;
}

// Υλοποίηση της virtual μεθόδου display
void Professor::display() const {
    Person::display();
    cout << "Κωδικός Καθηγητή: " << code << endl;
    cout << "Ειδικότητα: " << specialization << endl;
}

// Υλοποίηση της pure virtual μεθόδου sendEmail
void Professor::sendEmail(const string& message) {
    cout << "Αποστολή email στον/στην καθηγητή/τρια " << getFullName()
         << " (" << getEmail() << ")" << endl;
    cout << "Μήνυμα: " << message << endl;
}
