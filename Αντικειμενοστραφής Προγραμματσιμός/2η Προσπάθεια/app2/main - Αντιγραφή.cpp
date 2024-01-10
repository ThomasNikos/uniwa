#include <iostream>
#include <cstring>

using namespace std;

class Student { //Κλάση Student.
                char * AM;
                string name;
                unsigned int semester;
        public:
                Student(string, char *, unsigned int = 1); //Σε περίπτωση που θα δωθούν 2 παράμετροι και όχι 3, το εξάμηνο θα είναι 1.
                Student(const Student &stud);
                void set_AM(char * set_am);
                void set_name(string set_na);
                void set_semester(unsigned int set_sem);
                char * get_AM();
                string get_name();
                unsigned int get_semester();
		void id();
		void sem_plus();
		Student & operator+=(int);
                Student & operator-=(int);
                ~Student();
};

int main() {
	int ans;
	char AM[15] = "21390068";
	Student stud("Νικόλαος Θωμάς", AM); //Constructor με default εξάμηνο 1.
	char AMS[15] = "2121212121";
	Student studs("Τυχαίο Όνομα", AMS, 2); //Constructor με 2ο εξάμηνο για παράμετρο.
	Student s1 = stud; // Copy constructor.
	stud.id(); //Εμφάνιση ονόματος, ΑΜ και εξαμήνου.
	studs.id(); //Εμφάνιση ονόματος, ΑΜ και εξαμήνου.
	s1.id(); //Εμφάνιση ονόματος, ΑΜ και εξαμήνου.
	cout << "Αύξηση εξαμήνου κατα 1:"  << endl;
	stud.sem_plus(); //Αύξηση εξαμήνου κατα 1.
	stud.id(); //Εμφάνιση ονόματος, ΑΜ και εξαμήνου.
	cout << "Αύξηση εξαμήνου κατα 1:"  << endl;
	studs.sem_plus(); //Αύξηση εξαμήνου κατα 1.
	studs.id(); //Εμφάνιση ονόματος, ΑΜ και εξαμήνου.
	cout << "Αύξηση εξαμήνου κατα 5:"  << endl;	
	s1 += 5; //Αύξηση εξαμήνου κατα 5.
	s1.id(); //Εμφάνιση ονόματος, ΑΜ και εξαμήνου.
	cout << "Μείωση εξαμήνου κατα 5:"  << endl;
	s1 -= 5; //Μείωση εξαμήνου κατα 5.
	s1.id(); //Εμφάνιση ονόματος, ΑΜ και εξαμήνου.
	return 0;
}

Student::Student (string in_name, char * in_AM, unsigned int in_semester){ //Constructor με 3 παραμέτρους.
        semester = in_semester;
        name = in_name;
		int s = strlen(in_AM);
        AM = new char[s+1];
        strcpy (AM, in_AM);
}

Student::Student (const Student &stud){ //Copy contructor.
        semester = stud.semester;
        name = stud.name;
		int s = strlen(stud.AM);
		AM = new char[s+1];
        strcpy(AM, stud.AM);
}

Student::~Student (){ //Destructor.
	delete[] AM;
}

void Student::set_AM(char * set_am){ //Setter.
	delete[] AM;
    int s = strlen(set_am);
    AM = new char[s+1];
    strcpy (AM, set_am);
}

void Student::set_name(string set_na){ //Setter.
	name = set_na;
}

void Student::set_semester(unsigned int set_sem){ //Setter.
	semester = set_sem;
}

char * Student::get_AM(){ //Getter.
	return AM;
}

string Student::get_name(){ //Getter.
	return name;
}

unsigned int Student::get_semester(){ //Getter.
	return semester;
}

void Student::id(){
	cout << "Ο μαθητής με όνομα " <<  name << " έχει Α.Μ.: " << AM << " και διανύει το " << semester  << "ο εξάμηνο." << endl;
}
void Student::sem_plus(){
	semester++;
}

Student& Student::operator+=(int n){ //Υπερφόρτωση του τελεστή += για την αύξηση του εξαμήνου.
	semester = semester + n;
	return *this;	
}

Student& Student::operator-=(int n){ //Υπερφόρτωση του τελεστή -= για την μείωση του εξαμήνου.
	if(semester > n){
		semester = semester - n;
	}
	return *this;
}