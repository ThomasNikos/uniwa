#include "student.h"
#include "subject.h"
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

ostream& operator<<(ostream&, const Student&);
void grade_printer_file(const Student&);

int main() {	
	setlocale(LC_ALL,"");
	//Δημιουργία όλων των μαθημάτων.
	Subject math("ICE1-1002", "Γραμμική Άλγεβρα", 1);
	Subject c("ICE1-2004", "Προγραμματισμός ", 2);
	Subject ld("ICE1-2005", "Ψηφιακή Σχεδίαση", 2);
	Subject data("ICE1-5001", "Βάσεις Δεδομένων   ", 3);
	Subject dmath("ICE1-1005", "Διακριτά Μαθηματικά", 3);
	//Προσθήκη όλων των μαθημάτων σε αρχείο.
	ofstream subjects("all_subjects.txt");
	if (subjects.is_open()){
		subjects << "Όλα τα μαθήματα:" << endl;
		subjects << "Κωδικός Μαθήματος " << "Λεκτικό μαθήματος   " << "Εξάμηνο μαθήματος" << endl;
		subjects << math.sub_id << "         " << math.sub_name << "    " << math.sub_hex << endl;
		subjects << c.sub_id << "         " << c.sub_name << "    " << c.sub_hex << endl;
		subjects << ld.sub_id << "         " << ld.sub_name << "    " << ld.sub_hex << endl;
		subjects << data.sub_id << "         " << data.sub_name << ' ' << data.sub_hex << endl;
		subjects << dmath.sub_id << "         " << dmath.sub_name << ' ' << dmath.sub_hex << endl;
	}
	
	subjects.close();
	
	char AM[15] = "21390068";
	Student nick("Νικόλαος Θωμάς", AM, 3); //Constructor με default εξάμηνο 1.
	char AMS[15] = "2121212121";
	Student random("Τυχαίο Όνομα", AMS, 2); //Constructor με 2ο εξάμηνο για παράμετρο.
	//Προσθήκη βαθμών για τα μαθήματα του Νικόλαου Θωμά.
	nick.set_grades(math, 5);
	nick.set_grades(ld, 8);
	nick.set_grades(c, 6.9);
	nick.subthissem_print(); //Εκτύπωση των δηλωμένων μαθημάτων χωρίς να υπάρχει κανένα.
	cout << endl;
	//Προσθήκη μαθήματος στα δηλωμένα μαθήματα του Νικόλαου Θωμά.
	nick += data;
	//Εκτύπωση των δηλωμένων μαθημάτων του Νικόλαου Θωμά.
	nick.subthissem_print();
	//Προσθήκη μαθήματος στα δηλωμένα μαθήματα του Νικόλαου Θωμά.
	nick += dmath;
	//Εκτύπωση των δηλωμένων μαθημάτων του Νικόλαου Θωμά.
	nick.subthissem_print();
	//Εκτύπωση της αναλυτικής βαθμολογίας του Νικόλαου Θωμά.
	cout << nick;
	cout << endl;
	//Αντιγραφή όλων των στοιχείων του Νικόλαου Θωμά στον Τυχαίο Όνομα.
	random = nick;
	//Προσθήκη της αναλυτικής βαθμολογίας του Νικόλαου Θωμά σε αρχείο.
	grade_printer_file(nick);
	Student s1 = nick; // Copy constructor.
	nick.id(); //Εμφάνιση ονόματος, ΑΜ και εξαμήνου.
	random.id(); //Εμφάνιση ονόματος, ΑΜ και εξαμήνου.
	s1.id(); //Εμφάνιση ονόματος, ΑΜ και εξαμήνου.
	cout << "Αύξηση εξαμήνου κατα 1:"  << endl;
	nick.sem_plus(); //Αύξηση εξαμήνου κατα 1.
	nick.id(); //Εμφάνιση ονόματος, ΑΜ και εξαμήνου.
	random.sem_plus(); //Αύξηση εξαμήνου κατα 1.
	random.id(); //Εμφάνιση ονόματος, ΑΜ και εξαμήνου.
	s1.sem_plus(); //Αύξηση εξαμήνου κατα 1.
	s1.id(); //Εμφάνιση ονόματος, ΑΜ και εξαμήνου.
	return 0;
}

//Υπερφόρτωση του τελεστή << για την εκύπωση της αναλυτικής βαθμολογίας του φοιτητή.
ostream& operator<<(ostream& ostr, const Student& stud){
	float mo = 0;
	int quantity = stud.get_grade().size();
	ostr<< stud.get_name() << " (" << stud.get_AM() << ") : : " << "Αναλυτική Βαθμολογία" << endl << "" << endl;
	ostr << "Κωδικός Μαθήματος" << " " << "Μάθημα" << "           " << "Εξάμηνο Μαθήματος" << " " << "Βαθμός" << endl << "" << endl;
	for(int i = 0; i < quantity; i++){
		mo = mo + stud.get_grade().at(i).second;
		ostr << stud.get_grade().at(i).first->get_sub_id() << "         " << stud.get_grade().at(i).first->get_sub_name() << " " << stud.get_grade().at(i).first->get_sub_hex();
		ostr << "                 " << stud.get_grade().at(i).second << endl << "" << endl;
	}
	if( quantity != 0)
		mo = mo/quantity;
		ostr << "Μέσος όρος: " <<fixed<< setprecision(1) << mo << endl;
	return ostr;
}


//Συνάρτηση για την προσθήκη της αναλυτικής βαθμολογίας φοιτητή σε αρχείο.
void grade_printer_file(const Student &stud){
	ofstream stud_file((stud.get_name() + ".txt").c_str());
	if(stud_file.is_open()){
		stud_file << stud;
	}
	stud_file.close();
}



