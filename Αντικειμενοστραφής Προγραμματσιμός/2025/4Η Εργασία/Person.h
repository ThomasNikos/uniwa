#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
private:
    char* id;             // Αριθμός Ταυτότητας
    string fullName;      // Ονοματεπώνυμο
    int birthYear;        // Έτος Γέννησης
    string address;       // Διεύθυνση κατοικίας
    string phone;         // Τηλέφωνο
    string email;         // Email

public:
    // General constructors
    Person(const char* id, const string& fullName, int birthYear, const string& address, 
           const string& phone, const string& email);
    Person(const char* id, const string& fullName, int birthYear);

    // Copy constructor
    Person(const Person& other);

    // Destructor
    ~Person();

    // Getters
    const char* getId() const;
    string getFullName() const;
    int getBirthYear() const;
    string getAddress() const;
    string getPhone() const;
    string getEmail() const;

    // Setters
    void setId(const char* newId);
    void setFullName(const string& newFullName);
    void setBirthYear(int newBirthYear);
    void setAddress(const string& newAddress);
    void setPhone(const string& newPhone);
    void setEmail(const string& newEmail);

    // Υπολογισμός ηλικίας
    int getAge() const;

    // Μέθοδος εμφάνισης στοιχείων
    void display() const;
};

#endif
