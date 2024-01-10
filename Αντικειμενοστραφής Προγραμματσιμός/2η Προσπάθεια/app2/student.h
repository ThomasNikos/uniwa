#ifndef STUDENT_H
#define STUDENT_H
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


#endif 
