#include <iomanip>
#include "student.h"

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
	delete[] pairptr;
	delete[] subptr;
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

char * Student::get_AM() const{ //Getter.
	return AM;
}

string Student::get_name() const{ //Getter.
	return name;
}

unsigned int Student::get_semester() const{ //Getter.
	return semester;
}

const vector<pair<Subject *, float>>& Student::get_grade() const{
	return grade;
}

const vector<Subject*>& Student::get_subthissem() const{
	return subthissem;
}

void Student::id(){
	cout << "Ο μαθητής με όνομα " <<  name << " έχει Α.Μ.: " << AM << " και διανύει το " << semester  << "ο εξάμηνο." << endl;
}
void Student::sem_plus(){
	semester++;
}

//Υπερφόρτωση Τελεστών.

Student& Student::operator=(const Student& stud){
	if(this==&stud)
		return *this;
	name = stud.name;
	semester = stud.semester;
	delete[] AM;
	int s = strlen(stud.AM);
	AM = new char[s+1];
	strcpy (AM, stud.AM);
	return *this;
}

bool Student::operator==(const Student &x){
	if(this->semester == x.semester)
		return 1;
	return 0;
}

bool Student::operator!=(const Student &x){
	if(this->semester != x.semester)
		return 1;
	return 0;
}

bool Student::operator<=(const Student &x){
	if(this->semester <= x.semester)
		return 1;
	return 0;
}

bool Student::operator>=(const Student &x){
	if(this->semester >= x.semester)
		return 1;
	return 0;
}

bool Student::operator<(const Student &x){
	if(this->semester < x.semester)
		return 1;
	return 0;
}

bool Student::operator>(const Student &x){
	if(this->semester > x.semester)
		return 1;
	return 0;

}

Student& Student::operator+=(const Subject& sub){
	subptr = new Subject(sub); 
	subthissem.push_back(subptr);
	return *this;
}

//Συνάρτηση για την βαθμολογία σε κάποιο μάθημα φοιτητή.

void Student::set_grades(Subject& sub, float gr){
	pair<Subject*, float> temppair;
	pairptr = new Subject(sub);
	grade.push_back( make_pair(pairptr, gr));
}
	
void Student::subthissem_print(){ //Συνάρτηση για την εκτύπωση των δηλωμένων μαθημάτων στο τρέχον εξάμηνο στην οθόνη και σε αρχείο .
	if(subthissem.size() == 0){
		cout << "Δεν υπάρχουν δηλωμένα μαθήματα για το τρέχον εξάμηνο." << endl;
	}else{
		ofstream stud_file((name + " Δηλωμένα.txt").c_str());
		if(stud_file.is_open()){
			stud_file << name << " (" << AM << ") : : " << "Δηλωμένα Μαθήματα" << endl << "" << endl;
			stud_file << "Κωδικός Μαθήματος" << " " << "Μάθημα" << "              " << "Εξάμηνο Μαθήματος" << endl << "" << endl;
			for(int i = 0; i < subthissem.size(); i++){
				stud_file << subthissem.at(i)->get_sub_id() << "         " << subthissem.at(i)->get_sub_name() << " " << subthissem.at(i)->get_sub_hex() << endl
				 << "                 " << endl;
			}
		}
		stud_file.close();
		cout << name << " (" << AM << ") : : " << "Δηλωμένα Μαθήματα" << endl << "" << endl;
		cout << "Κωδικός Μαθήματος" << " " << "Μάθημα" << "              " << "Εξάμηνο Μαθήματος" << endl << "" << endl;
		for(int i = 0; i < subthissem.size(); i++){
			cout << subthissem.at(i)->get_sub_id() << "         " << 
			subthissem.at(i)->get_sub_name() << " " << subthissem.at(i)->get_sub_hex() 
			<< endl << "                 " << endl;
		}
	}

} 

