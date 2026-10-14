#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
private:
    string id;             // Αριθμός Ταυτότητας
    string fullName;      // Ονοματεπώνυμο
    int birthYear;        // Έτος Γέννησης
    string address;       // Διεύθυνση κατοικίας
    string phone;         // Τηλέφωνο
    string email;         // Email

public:
    // Constructor
    Person(const string& id, const string& fullName, int birthYear,
           const string& address = "", const string& phone = "", const string& email = "");

    // Virtual destructor
    virtual ~Person();

    // Getters
    string getId() const;
    string getFullName() const;
    int getBirthYear() const;
    string getAddress() const;
    string getPhone() const;
    string getEmail() const;

    // Setters
    void setId(const string& newId);
    void setFullName(const string& newFullName);
    void setBirthYear(int newBirthYear);
    void setAddress(const string& newAddress);
    void setPhone(const string& newPhone);
    void setEmail(const string& newEmail);

    // Υπολογισμός ηλικίας
    int getAge() const;

    // Μέθοδος εμφάνισης στοιχείων
    virtual void display() const;

    // Pure virtual μέθοδος για αποστολή email
    virtual void sendEmail(const string& message) = 0;
};

#endif
