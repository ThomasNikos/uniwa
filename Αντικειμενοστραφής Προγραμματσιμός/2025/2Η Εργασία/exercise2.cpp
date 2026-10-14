#include <iostream>
using namespace std;

// Συνάρτηση που υπολογίζει το άθροισμα από 1 έως Ν και το Ν παραγοντικό
void calculate(const unsigned int N, unsigned long long& sum, unsigned long long& factorial) {
    sum = 0;
    factorial = 1;
    
    // Υπολογισμός αθροίσματος 1 έως Ν
    for (unsigned int i = 1; i <= N; i++) {
        unsigned long long prev_sum = sum;
        sum += i;
        
        // Έλεγχος για υπερχείλιση μετά την πρόσθεση
        if (sum < prev_sum) {
            sum = 0;
            break;
        }
    }
    
    // Υπολογισμός παραγοντικού
    for (unsigned int i = 1; i <= N; i++) {
        unsigned long long prev_factorial = factorial;
        factorial *= i;
        
        // Έλεγχος για υπερχείλιση μετά τον πολλαπλασιασμό
        if (factorial < prev_factorial && i > 1) {
            factorial = 0;
            break;
        }
    }
}

int main() {
    const int NUM_VALUES = 1000000;
    unsigned int number;
    unsigned long long sum, factorial;
    
    // Μετρητές για τους έγκυρους υπολογισμούς
    unsigned int validSums = 0;
    unsigned int validFactorials = 0;
    
    // Αθροιστές για τον υπολογισμό των μέσων όρων
    long double sumTotal = 0;
    long double factorialTotal = 0;
    
    // Διάβασμα των 1,000,000 αριθμών
    for (int i = 0; i < NUM_VALUES; i++) {
        cin >> number;
        
        // Κλήση της συνάρτησης για υπολογισμό
        calculate(number, sum, factorial);
        
        // Ενημέρωση των αθροιστών για τους μέσους όρους (αν δεν είναι 0)
        if (sum != 0) {
            sumTotal += sum;
            validSums++;
        }
        
        if (factorial != 0) {
            factorialTotal += factorial;
            validFactorials++;
        }
    }
    
    // Υπολογισμός και εμφάνιση των μέσων όρων
    cout.precision(10);
    cout << "Average sum: " << (validSums > 0 ? sumTotal / validSums : 0) << endl;
    cout << "Average factorial: " << (validFactorials > 0 ? factorialTotal / validFactorials : 0) << endl;
    
    return 0;
}
