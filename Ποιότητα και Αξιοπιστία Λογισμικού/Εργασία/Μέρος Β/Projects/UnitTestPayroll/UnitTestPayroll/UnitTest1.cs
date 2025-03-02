using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using Payroll_Lib;

namespace UnitTestPayrollLib
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestCheckPhone()
        {
            string resultPhoneCountry = string.Empty;
            Payroll_Lib.EmployeePayment phone = new Payroll_Lib.EmployeePayment();

            object[,] testcases =
            {
                {1, "301234567890", true},
                {2, "00301234567890", true},
                {3, "+3571234567890", true},
                {4, "00391234567890", true},
                {5, "+441234567890", true},
                {6, "1234567890", false},
                {7, "30123", false}
            };

            bool failed = false;

            for (int i = 0; i < testcases.GetLength(0); i++)
            {
                try
                {
                    bool validPhone = false;

                    validPhone = phone.CheckPhone((string)testcases[i, 1], ref resultPhoneCountry);

                    Assert.AreEqual((bool)testcases[i, 2], validPhone);

                    if (validPhone)
                    {
                        Assert.IsFalse(string.IsNullOrEmpty(resultPhoneCountry), "Country should not be null or empty for valid phone numbers.");
                    }
                    else
                    {
                        Assert.IsTrue(string.IsNullOrEmpty(resultPhoneCountry), "Country should be null or empty for invalid phone numbers.");
                    }
                }
                catch (Exception e)
                {
                    failed = true;
                    Console.WriteLine("Failed Test Case: {0}: {1} - {2}. \n \t Reason: {3} ",
                        (int)testcases[i, 0], (string)testcases[i, 1], (bool)testcases[i, 2], e.Message);
                }
            }

            //Στην περίπτωση που κάποια περίπτωση ελέγχου απέτυχε, πέταξε εξαίρεση.
            if (failed) Assert.Fail();
        }

        [TestMethod]
        public void TestCheckIBAN()
        {
            string resultIBANCountry = string.Empty;
            Payroll_Lib.EmployeePayment ibanChecker = new Payroll_Lib.EmployeePayment();

            object[,] testcases =
            {
                {1, "GR1601101250000000012300695", true, "Ελλάδα"},
                {2, "GB29NWBK60161331926819", true, "Αγγλία"},
                {3, "IT60X0542811101000000123456", true, "Ιταλία"},
                {4, "CY17002001280000001200527600", true, "Κύπρος"},
                {5, "XX00000000000000000000", false, ""},
                {6, "GR123", false, ""},
            };

            bool failed = false;
            for (int i = 0; i < testcases.GetLength(0); i++)
            {
                try
                {
                    bool validIBAN = ibanChecker.CheckIBAN((string)testcases[i, 1], ref resultIBANCountry);
                    Assert.AreEqual((bool)testcases[i, 2], validIBAN);
                    Assert.AreEqual((string)testcases[i, 3], resultIBANCountry);
                }
                catch (Exception e)
                {
                    failed = true;
                    Console.WriteLine("Απέτυχε η δοκιμή: {0}: {1} - {2}. Σφάλμα: {3}", (int)testcases[i, 0], (string)testcases[i, 1], (bool)testcases[i, 2], e.Message);
                }
            }

            if (failed) Assert.Fail("Κάποιες δοκιμές απέτυχαν.");
        }



        [TestMethod]
        public void TestCheckZipCode()
        {
            Payroll_Lib.EmployeePayment zipChecker = new Payroll_Lib.EmployeePayment();

            object[,] testcases =
            {
                {1, 47890, true},
                {2, 47899, true},
                {3, 10100, true},
                {4, 120, true},
                {5, 9999999, false},
                {6, 12345, false}
            };

            bool failed = false;
            for (int i = 0; i < testcases.GetLength(0); i++)
            {
                try
                {
                    bool validZip = zipChecker.CheckZipCode((int)testcases[i, 1]);
                    Assert.AreEqual((bool)testcases[i, 2], validZip);
                }
                catch (Exception e)
                {
                    failed = true;
                    Console.WriteLine("Απέτυχε η δοκιμή: {0}: {1} - {2}. Σφάλμα: {3}", (int)testcases[i, 0], (int)testcases[i, 1], (bool)testcases[i, 2], e.Message);
                }
            }


            //Στην περίπτωση που κάποια περίπτωση ελέγχου απέτυχε, πέταξε εξαίρεση.
            if (failed) Assert.Fail();
        }

        [TestMethod]
        public void TestCalculateSalary()
        {
            Payroll_Lib.EmployeePayment salaryCalculator = new Payroll_Lib.EmployeePayment();
            // Δημιουργία test cases
            var testCases = new[]
            {
               // 1. Junior Developer χωρίς εμπειρία και παιδιά
               new
               {
                   Employee = new Payroll_Lib.EmployeePayment.Employee
                   {
                       Position = "Junior Developer",
                       WorkExperience = 0,
                       Children = 0
                   },
                   ExpectedAnnualGross = 12000.0,    // 1000 * 12
                   ExpectedNetAnnual = 9340.24,      // 12000 - 1692 - 967.76
                   ExpectedNetMonthly = 778.35       // 9340.24 / 12
               },
       
               // 2. Junior Developer με 5 χρόνια εμπειρία και 1 παιδί
               new
               {
                   Employee = new Payroll_Lib.EmployeePayment.Employee
                   {
                       Position = "Junior Developer",
                       WorkExperience = 5,
                       Children = 1
                   },
                   ExpectedAnnualGross = 18800.0,    // (1000 * (1 + (0.03 * 5)) * 12) + 5000
                   ExpectedNetAnnual = 13896.376,    // 18800 - 2650.8 - 2252.824
                   ExpectedNetMonthly = 1158.03      // 13896.376 / 12
               },
       
               // 3. Senior Developer με 10 χρόνια εμπειρία και 2 παιδιά
               new
               {
                   Employee = new Payroll_Lib.EmployeePayment.Employee
                   {
                       Position = "Senior Developer",
                       WorkExperience = 10,
                       Children = 2
                   },
                   ExpectedAnnualGross = 41200.0,    // (2000 * (1 + (0.03 * 10)) * 12) + 10000
                   ExpectedNetAnnual = 27550.112,    // 41200 - 5809.2 - 7840.688
                   ExpectedNetMonthly = 2295.84      // 27550.112 / 12
               },
       
                // 4. IT Manager με 15 χρόνια εμπειρία και 3 παιδιά
                new
                {
                    Employee = new Payroll_Lib.EmployeePayment.Employee
                    {
                        Position = "IT Manager",
                        WorkExperience = 15,
                        Children = 3
                    },
                    ExpectedAnnualGross = 75000.0,    // (5000 * 12) + 15000
                    ExpectedNetAnnual = 44178.0,      // 75000 - 10575 - 20247
                    ExpectedNetMonthly = 3681.5       // 44178 / 12
                }
           };

            foreach (var testCase in testCases)
            {
                double annualGross = 0, netAnnual = 0, netMonthly = 0, tax = 0, insurance = 0;
                salaryCalculator.CalculateSalary(
                    testCase.Employee,
                    ref annualGross,
                    ref netAnnual,
                    ref netMonthly,
                    ref tax,
                    ref insurance
                );

                // Έλεγχος με ανοχή 0.01 για στρογγυλοποιήσεις
                Assert.AreEqual(testCase.ExpectedAnnualGross, annualGross, 0.01,
                    $"Λάθος στον υπολογισμό μικτού ετήσιου για {testCase.Employee.Position}");
                Assert.AreEqual(testCase.ExpectedNetAnnual, netAnnual, 0.01,
                    $"Λάθος στον υπολογισμό καθαρού ετήσιου για {testCase.Employee.Position}");
                Assert.AreEqual(testCase.ExpectedNetMonthly, netMonthly, 0.01,
                    $"Λάθος στον υπολογισμό καθαρού μηνιαίου για {testCase.Employee.Position}");
            }
        }

        [TestMethod]
        public void TestNumOfEmployees()
        {
            Payroll_Lib.EmployeePayment empCounter = new Payroll_Lib.EmployeePayment();

            Payroll_Lib.EmployeePayment.Employee[] employees = new Payroll_Lib.EmployeePayment.Employee[]
            {
                new Payroll_Lib.EmployeePayment.Employee { Position = "Junior Developer" },
                new Payroll_Lib.EmployeePayment.Employee { Position = "Junior Developer" },
                new Payroll_Lib.EmployeePayment.Employee { Position = "Senior Developer" }
            };

            object[,] testcases =
            {
                {1, employees, "Junior Developer", 2},
                {2, employees, "Senior Developer", 1},
                {3, employees, "IT Manager", 0},
                {4, new Payroll_Lib.EmployeePayment.Employee[] { }, "Junior Developer", 0}
            };

            bool failed = false;
            for (int i = 0; i < testcases.GetLength(0); i++)
            {
                try
                {
                    int count = empCounter.NumofEmployees((Payroll_Lib.EmployeePayment.Employee[])testcases[i, 1], (string)testcases[i, 2]);
                    Assert.AreEqual((int)testcases[i, 3], count);
                }
                catch (Exception e)
                {
                    failed = true;
                    Console.WriteLine("Απέτυχε η δοκιμή: {0}: Σφάλμα: {1}", (int)testcases[i, 0], e.Message);
                }
            }

            if (failed) Assert.Fail("Κάποιες δοκιμές απέτυχαν.");
        }

        [TestMethod]
        public void TestGetBonus()
        {
            Payroll_Lib.EmployeePayment employeePayment = new Payroll_Lib.EmployeePayment();

            // Test Case 1: TotalIncome = 120000
            Payroll_Lib.EmployeePayment.Employee[] employees1 = new Payroll_Lib.EmployeePayment.Employee[]
            {
                new Payroll_Lib.EmployeePayment.Employee { Department = "Δικτύων", Income = 60000 },
                new Payroll_Lib.EmployeePayment.Employee { Department = "Δικτύων", Income = 60000 }
            };
            bool result1 = employeePayment.GetBonus(ref employees1, "Δικτύων", 100000, 10000);
            Assert.AreEqual(true, result1);
            Assert.AreEqual(5000, employees1[0].Bonus, 0.01);  // 60000/120000 * 10000
            Assert.AreEqual(5000, employees1[1].Bonus, 0.01);  // 60000/120000 * 10000

            // Test Case 2: TotalIncome = 90000
            Payroll_Lib.EmployeePayment.Employee[] employees2 = new Payroll_Lib.EmployeePayment.Employee[]
            {
                new Payroll_Lib.EmployeePayment.Employee { Department = "Δικτύων", Income = 45000 },
                new Payroll_Lib.EmployeePayment.Employee { Department = "Δικτύων", Income = 45000 }
            };
            bool result2 = employeePayment.GetBonus(ref employees2, "Δικτύων", 100000, 10000);
            Assert.AreEqual(false, result2);
            Assert.AreEqual(0, employees2[0].Bonus, 0.01);
            Assert.AreEqual(0, employees2[1].Bonus, 0.01);

            // Test Case 3: TotalIncome = 12000 (Ανύπαρκτο τμήμα)
            Payroll_Lib.EmployeePayment.Employee[] employees3 = new Payroll_Lib.EmployeePayment.Employee[]
            {
                new Payroll_Lib.EmployeePayment.Employee { Department = "Δικτύων", Income = 60000 },
                new Payroll_Lib.EmployeePayment.Employee { Department = "Δικτύων", Income = 60000 }
            };
            bool result3 = employeePayment.GetBonus(ref employees3, "Ανύπαρκτο", 100000, 10000);
            Assert.AreEqual(false, result3);
            Assert.AreEqual(0, employees3[0].Bonus, 0.01);
            Assert.AreEqual(0, employees3[1].Bonus, 0.01);
        }
    }
    }
