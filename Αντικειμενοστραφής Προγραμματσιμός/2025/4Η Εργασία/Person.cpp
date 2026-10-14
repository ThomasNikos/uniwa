#include "Person.h"
#include <iostream>
#include <cstring>
#include <ctime>

// Πρώτος constructor με όλα τα πεδία
Person::Person(const char* id, const string& fullName, int birthYear, const string& address, 
               const string& phone, const string& email) {
    // Δέσμευση μνήμης για το id και αντιγραφή της τιμής
    this->id = new char[strlen(id) + 1];
    strcpy(this->id, id);

    this->fullName = fullName;
    this->birthYear = birthYear;
    this->address = address;
    this->phone = phone;
    this->email = email;
}

// Δεύτερος constructor με βασικά πεδία
Person::Person(const char* id, const string& fullName, int birthYear) {
    // Δέσμευση μνήμης για το id και αντιγραφή της τιμής
    this->id = new char[strlen(id) + 1];
    strcpy(this->id, id);

    this->fullName = fullName;
    this->birthYear = birthYear;
    this->address = "Μη διαθέσιμη";
    this->phone = "Μη διαθέσιμο";
    this->email = "Μη διαθέσιμο";
}

// Copy constructor
Person::Person(const Person& other) {
    // Δέσμευση νέας μνήμης και αντιγραφή του id
    this->id = new char[strlen(other.id) + 1];
    strcpy(this->id, other.id);

    // Αντιγραφή των υπόλοιπων πεδίων
    this->fullName = other.fullName;
    this->birthYear = other.birthYear;
    this->address = other.address;
    this->phone = other.phone;
    this->email = other.email;
}

// Destructor
Person::~Person() {
    // Αποδέσμευση της μνήμης που δεσμεύσαμε για το id
    delete[] id;
}

// Getters
const char* Person::getId() const {
    return id;
}

string Person::getFullName() const {
    return fullName;
}

int Person::getBirthYear() const {
    return birthYear;
}

string Person::getAddress() const {
    return address;
}

string Person::getPhone() const {
    return phone;
}

string Person::getEmail() const {
    return email;
}

// Setters
void Person::setId(const char* newId) {
    // Αποδέσμευση της παλιάς μνήμης
    delete[] id;
    // Δέσμευση νέας μνήμης και αντιγραφή της νέας τιμής
    id = new char[strlen(newId) + 1];
    strcpy(id, newId);
}

void Person::setFullName(const string& newFullName) {
    fullName = newFullName;
}

void Person::setBirthYear(int newBirthYear) {
    birthYear = newBirthYear;
}

void Person::setAddress(const string& newAddress) {
    address = newAddress;
}

void Person::setPhone(const string& newPhone) {
    phone = newPhone;
}

void Person::setEmail(const string& newEmail) {
    email = newEmail;
}

// Υπολογισμός ηλικίας
int Person::getAge() const {
    // Λήψη του τρέχοντος έτους από το σύστημα
    time_t t = time(nullptr);
    tm* timePtr = localtime(&t);
    int currentYear = timePtr->tm_year + 1900;

    return currentYear - birthYear;
}

// Μέθοδος εμφάνισης στοιχείων
void Person::display() const {
    cout << "Αριθμός Ταυτότητας: " << id << endl;
    cout << "Ονοματεπώνυμο: " << fullName << endl;
    cout << "Έτος Γέννησης: " << birthYear << " (Ηλικία: " << getAge() << ")" << endl;
    cout << "Διεύθυνση: " << address << endl;
    cout << "Τηλέφωνο: " << phone << endl;
    cout << "Email: " << email << endl;
}
