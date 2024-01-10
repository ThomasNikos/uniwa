/*
=========================================
C++ φροντιστήριο
Μάθημα 1ο
Consts
=========================================
*/

#include <iostream>

using namespace std;

int main (int argc, char **argv)
{
	//volatile const double pi = 3.14159265;
	const double pi = 3.14159265;
	double *changepi;
	cout << pi << endl;  //Τυπώνονται όλα τα δεκαδικά;;;;
	changepi = (double *) &pi;      //Χωρίς casting συντακτικό λάθος
	*changepi = 5;
	cout << pi << " " << *changepi << " " << endl;
	
	cout << "===========================================================" << endl;
	char ch1 = 'A';
	char ch2 = 'B';
	
	const char *p1 = &ch1;	//Ο p1 δείχνει σε χαρακτήρα ο οποίος είναι σταθερός (δεν μπορεί να αλλάξει ο χαρακτήρας μέσω του p1
	p1 = &ch2; 				//Σωστό
	//*p1 = 'C';				//Συντακτικό Λάθος
	
	char * const p2 = &ch1;	//Ο p2 είναι σταθερός δείκτης (δεν μπορεί να δείξει κάπου αλλού). Υποχρεωτική αρχικοποίηση
	//p2 = &ch2;				//Συντακτικό Λάθος
	*p2 = 'C';				//Σωστό
	
	char const * p3;		//Ίδιο με p1
	p3 = &ch2;				//Σωστό
	//*p3 = 'C';				//Συντακτικό λαθος
	
	const char * const p4 = &ch1;	//Όλα σταθερά
	//p4 = &ch2;					//Συντακτικό Λάθος
	//*p4 = 'C';					//Συντακτικό Λάθος
	
	const char *mess;				//Δείτε τι θα γίνει και στις δύο περιπτώσεις
	char *mess;
	mess = "hello world";
	*(mess + 2) = 'A';
	cout << mess;
	
}