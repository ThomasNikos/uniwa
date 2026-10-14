#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

// Βασική κλάση εξαίρεσης για το σύστημα
class RegistryException : public std::runtime_error {
public:
    explicit RegistryException(const std::string& message)
        : std::runtime_error(message) {}
};

// Εξαίρεση για μη έγκυρα δεδομένα
class InvalidDataException : public RegistryException {
public:
    explicit InvalidDataException(const std::string& message)
        : RegistryException(message) {}
};

// Εξαίρεση για μη εύρεση στοιχείου
class NotFoundException : public RegistryException {
public:
    explicit NotFoundException(const std::string& message)
        : RegistryException(message) {}
};

// Εξαίρεση για σφάλματα αρχείων
class FileException : public RegistryException {
public:
    explicit FileException(const std::string& message)
        : RegistryException(message) {}
};

// Εξαίρεση για διπλές εγγραφές
class DuplicateEntryException : public RegistryException {
public:
    explicit DuplicateEntryException(const std::string& message)
        : RegistryException(message) {}
};

// Εξαίρεση για μη έγκυρους βαθμούς
class InvalidGradeException : public InvalidDataException {
public:
    explicit InvalidGradeException(const std::string& message)
        : InvalidDataException(message) {}
};

#endif
