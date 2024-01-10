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