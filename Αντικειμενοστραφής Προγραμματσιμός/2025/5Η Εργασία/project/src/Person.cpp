#include "../include/Person.h"
#include <iostream>
#include <ctime>

// Constructor
Person::Person(const string& id, const string& fullName, int birthYear,
               const string& address, const string& phone, const string& email)
    : id(id), fullName(fullName), birthYear(birthYear),
      address(address), phone(phone), email(email) {
}

// Destructor
Person::~Person() {
}

// Getters
string Person::getId() const {
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
void Person::setId(const string& newId) {
    id = newId;
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
