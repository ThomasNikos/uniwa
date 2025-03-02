using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;

namespace Payroll_Lib
{
    public class EmployeePayment
    {
        public struct Employee
        {
            public string FirstName { get; set; }
            public string Surname { get; set; }
            public int Children { get; set; }
            public string Department { get; set; }
            public string Position { get; set; }
            public int WorkExperience { get; set; }
            public int Income { get; set; }
            public double Bonus { get; set; }
        }

        public bool CheckPhone(string Phone, ref string PhoneCountry)
        {
            if (!Phone.StartsWith("+") && !Phone.StartsWith("00"))
            {
                Phone = "+" + Phone;
            }

            string pattern = @"^(00|\+)(\d{10,15})$";
            Regex regex = new Regex(pattern);
            if (!regex.IsMatch(Phone))
            {
                PhoneCountry = "";
                return false;
            }

            if (Phone.Contains("30") && (Phone.StartsWith("0030") || Phone.StartsWith("+30")))
                PhoneCountry = "Ελλάδα";
            else if (Phone.Contains("357") && (Phone.StartsWith("00357") || Phone.StartsWith("+357")))
                PhoneCountry = "Κύπρος";
            else if (Phone.Contains("39") && (Phone.StartsWith("0039") || Phone.StartsWith("+39")))
                PhoneCountry = "Ιταλία";
            else if (Phone.Contains("44") && (Phone.StartsWith("0044") || Phone.StartsWith("+44")))
                PhoneCountry = "Αγγλία";
            else
            {
                PhoneCountry = "";
                return false;
            }
            return true;
        }

        public bool CheckIBAN(string IBAN, ref string IBANCountry)
        {
            // 1. Ελέγξτε το μήκος και την αρχική χώρα
            if (IBAN.Length < 15 || IBAN.Length > 34)
            {
                IBANCountry = "";
                return false;
            }

            // Καθορισμός χώρας από τα πρώτα δύο γράμματα
            string country = IBAN.Substring(0, 2).ToUpper();
            switch (country)
            {
                case "GR":
                    IBANCountry = "Ελλάδα";
                    break;
                case "CY":
                    IBANCountry = "Κύπρος";
                    break;
                case "IT":
                    IBANCountry = "Ιταλία";
                    break;
                case "GB":
                    IBANCountry = "Αγγλία";
                    break;
                default:
                    IBANCountry = "";
                    break;
            }

            if (IBANCountry == null) return false;

            // 2. Μετακίνηση των 4 πρώτων γραμμάτων στο τέλος
            string rearrangedIBAN = IBAN.Substring(4) + IBAN.Substring(0, 4);

            // 3. Μετατροπή γραμμάτων σε αριθμούς
            StringBuilder numericIBAN = new StringBuilder();
            foreach (char ch in rearrangedIBAN)
            {
                if (char.IsLetter(ch))
                {
                    // Α = 10, B = 11, ..., Z = 35
                    numericIBAN.Append((ch - 'A' + 10).ToString());
                }
                else if (char.IsDigit(ch))
                {
                    numericIBAN.Append(ch);
                }
                else
                {
                    return false; // Μη αποδεκτός χαρακτήρας
                }
            }

            // 4. Υπολογισμός Modulo 97
            string ibanNumber = numericIBAN.ToString();
            int mod97 = Mod97(ibanNumber);

            // Επιστροφή true αν το υπόλοιπο είναι 1
            return mod97 == 1;
        }

        private int Mod97(string number)
        {
            long remainder = 0;

            foreach (char digit in number)
            {
                remainder = (remainder * 10 + (digit - '0')) % 97;
            }

            return (int)remainder;
        }


        public bool CheckZipCode(int zipCode)
        {
            if (zipCode == 120)
                return true;

            if (zipCode < 10000 || zipCode > 99999)
                return false;

            if (zipCode >= 47890 && zipCode <= 47899)
                return true;

            int provinceCode = zipCode / 1000;

            if (provinceCode >= 1 && provinceCode <= 99)
            {
                if ((zipCode >= 118 && zipCode <= 199) ||       // Rome (00118–00199)
                    (zipCode >= 20100 && zipCode <= 20199) ||   // Milan (20100–20199)
                    (zipCode >= 30100 && zipCode <= 30124) ||   // Venice (30100–30124)
                    (zipCode >= 56121 && zipCode <= 56128) ||   // Pisa (56121–56128)
                    (zipCode >= 10100 && zipCode <= 10159) ||   // Torino (10100–10159)
                    (zipCode == 12100) ||                      // Cuneo
                    (zipCode == 14100) ||                      // Asti
                    (zipCode == 11100) ||                      // Aosta
                    (zipCode == 16100) ||                      // Genoa
                    (zipCode == 17100) ||                      // Savona
                    (zipCode == 19100) ||                      // La Spezia
                    (zipCode == 20900) ||                      // Monza
                    (zipCode == 31100) ||                      // Treviso
                    (zipCode == 32100) ||                      // Belluno
                    (zipCode >= 37100 && zipCode <= 37139))    // Verona (37100–37139)
                {
                    return true;
                }

                return false;
            }

            return false;
        }

        public void CalculateSalary(Employee EmplX, ref double AnnualGrossSalary,
                              ref double NetAnnualIncome, ref double NetMonthIncome,
                              ref double Tax, ref double Insurance)
        {
            // Validation
            if (EmplX.WorkExperience < 0) throw new ArgumentException("Η προϋπηρεσία δεν μπορεί να είναι αρνητική");
            if (EmplX.Children < 0) throw new ArgumentException("Ο αριθμός παιδιών δεν μπορεί να είναι αρνητικός");

            // 1. Καθορισμός βασικού μηνιαίου μισθού και ανώτατου ορίου βάσει θέσης
            double baseMonthSalary = 0;
            double maxMonthSalary = 0;

            switch (EmplX.Position)
            {
                case "Junior Developer":
                    baseMonthSalary = 1000;
                    maxMonthSalary = 1400;
                    break;
                case "Mid-level Developer":
                    baseMonthSalary = 1500;
                    maxMonthSalary = 2000;
                    break;
                case "Senior Developer":
                    baseMonthSalary = 2000;
                    maxMonthSalary = 2800;
                    break;
                case "IT Manager":
                    baseMonthSalary = 3500;
                    maxMonthSalary = 5000;
                    break;
                default:
                    throw new ArgumentException("Μη έγκυρη θέση εργασίας");
            }

            // 2. Υπολογισμός προσαύξησης λόγω προϋπηρεσίας (3% ανά έτος)
            double experienceMultiplier = 1 + (0.03 * EmplX.WorkExperience);
            double monthSalaryWithExperience = baseMonthSalary * experienceMultiplier;

            // 3. Έλεγχος αν ξεπερνάει το ανώτατο όριο της θέσης
            double finalMonthSalary = Math.Min(monthSalaryWithExperience, maxMonthSalary);

            // 4. Υπολογισμός ετήσιου μικτού μισθού (12 μήνες + επίδομα παιδιών)
            AnnualGrossSalary = (finalMonthSalary * 12) + (EmplX.Children * 5000);

            // 5. Υπολογισμός ασφαλιστικών εισφορών (14.1%)
            Insurance = AnnualGrossSalary * 0.141;

            // 6. Υπολογισμός φόρου με προοδευτική κλίμακα σύμφωνα με aftertax.gr
            double taxableIncome = AnnualGrossSalary - Insurance;
            Tax = 0;

            // Φορολογική κλίμακα
            if (taxableIncome > 40000)
            {
                Tax += (taxableIncome - 40000) * 0.44;
                taxableIncome = 40000;
            }
            if (taxableIncome > 30000)
            {
                Tax += (taxableIncome - 30000) * 0.36;
                taxableIncome = 30000;
            }
            if (taxableIncome > 20000)
            {
                Tax += (taxableIncome - 20000) * 0.28;
                taxableIncome = 20000;
            }
            if (taxableIncome > 10000)
            {
                Tax += (taxableIncome - 10000) * 0.22;
                taxableIncome = 10000;
            }
            Tax += taxableIncome * 0.09;

            // 7. Υπολογισμός καθαρών αποδοχών
            NetAnnualIncome = AnnualGrossSalary - Tax - Insurance;
            NetMonthIncome = NetAnnualIncome / 12;
        }

        public int NumofEmployees(Employee[] Empls, string Position)
        {
            int count = 0;
            foreach (var emp in Empls)
            {
                if (emp.Position == Position)
                    count++;
            }
            return count;
        }

        public bool GetBonus(ref Employee[] Empls, string Department, double IncomeGoal, double Bonus)
        {
            // Calculate total department income
            double totalDepartmentIncome = 0;
            foreach (var emp in Empls)
            {
                if (emp.Department == Department)
                {
                    totalDepartmentIncome += emp.Income;
                }
            }

            // Check if goal is met
            if (totalDepartmentIncome <= IncomeGoal)
            {
                return false;
            }

            // Calculate and assign bonus for each employee using for loop to allow modifications
            for (int i = 0; i < Empls.Length; i++)
            {
                if (Empls[i].Department == Department)
                {
                    // Calculate contribution percentage
                    double contributionPercentage = Empls[i].Income / totalDepartmentIncome;
                    // Calculate bonus based on contribution
                    Empls[i].Bonus = contributionPercentage * Bonus;
                }
            }

            return true;
        }

    }
}
