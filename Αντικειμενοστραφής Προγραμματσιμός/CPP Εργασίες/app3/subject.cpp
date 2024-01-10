#include "subject.h"

Subject::Subject(string in_sub_id, string in_sub_name, unsigned int in_sub_hex){
		sub_id = in_sub_id;
		sub_name = in_sub_name;
		sub_hex = in_sub_hex;
}

string Subject::get_sub_id() const{
	return sub_id;
}

string Subject::get_sub_name() const{
	return sub_name;
}

unsigned int Subject::get_sub_hex() const{
	return sub_hex;
}


