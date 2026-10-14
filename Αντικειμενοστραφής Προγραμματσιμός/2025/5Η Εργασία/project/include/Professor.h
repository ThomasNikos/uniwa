#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Person.h"
#include <string>

class Professor : public Person {
private:
    string code;           // Κωδικός καθηγητή
    string specialization; // Ειδικότητα

public:
    // Constructor
    Professor(const string& id, const string& fullName, int birthYear,
             const string& address, const string& phone, const string& email,
             const string& code, const string& specialization);

    // Copy constructor
    Professor(const Professor& other);

    // Getters
    string getCode() const;
    string getSpecialization() const;

    // Setters
    void setCode(const string& code);
    void setSpecialization(const string& specialization);

    // Υλοποίηση της virtual μεθόδου display
    virtual void display() const override;

    // Υλοποίηση της pure virtual μεθόδου sendEmail
    virtual void sendEmail(const string& message) override;
};

#endif
