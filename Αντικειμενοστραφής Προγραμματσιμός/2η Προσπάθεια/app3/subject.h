#ifndef SUBJECT_H
#define SUBJECT_H
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class Subject { //Κλάση Subject.
        public:
		string sub_id;
		string sub_name;
		unsigned int sub_hex;
		Subject(string, string, unsigned int = 1);
		string get_sub_name() const;
		string get_sub_id() const;
		unsigned int get_sub_hex() const;
};


#endif 
