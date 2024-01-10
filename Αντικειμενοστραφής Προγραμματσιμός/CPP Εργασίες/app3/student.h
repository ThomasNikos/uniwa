#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
#include "subject.h"

using namespace std;

class Student { //Κλάση Student.
        	char * AM;
        	string name;
        	unsigned int semester;
		vector<Subject*> subthissem; //Δηλωμένα μαθήματα για το τρέχον εξάμηνο.
		vector<pair<Subject*, float>> grade; //Μάθημα και βαθμός φοιτητή.
		Subject * pairptr; //Δείκτης σε μάθημα που χρησιμοποιείται στο pair.
		Subject * subptr; //Δείκτης σε μάθημα που χρησιμοποιείται στα δηλωμένα μαθήματα του φοιτητη.
        public:
		Student(string, char *, unsigned int = 1); //Σε περίπτωση που θα δωθούν 2 παράμετροι και όχι 3, το εξάμηνο θα είναι 1.
		Student(const Student &stud);
		void set_AM(char * set_am);
		void set_name(string set_na);
		void set_semester(unsigned int set_sem);
		void set_grades(Subject&, float);
		char * get_AM() const;
		string get_name() const;
		unsigned int get_semester() const;
		const vector<pair<Subject*, float>>& get_grade() const;
		const vector<Subject*>& get_subthissem() const;
		void id();
		void sem_plus();
		void subthissem_print();
		//Υπερφόρτωση Τελεστών.
		Student& operator=(const Student&);
		bool operator==(const Student &);
		bool operator!=(const Student &);
		bool operator<=(const Student &);
		bool operator>=(const Student &);
		bool operator<(const Student &);
		bool operator>(const Student &);
		Student& operator+=(const Subject &);
		Student& operator-=(const Subject &);
		virtual ~Student();
};

#endif 
