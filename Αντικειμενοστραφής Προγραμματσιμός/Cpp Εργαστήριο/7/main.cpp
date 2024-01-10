#include <iostream>
#include <string>
#include <vector>

using namespace std;

class date{
        int day, month, year;
    public:
        date(int, int, int);
        date(date &);
        string date_string(){
            string date_str;
            date_str.append(to_string(day));
            date_str.append("η Ημέρα ");
            date_str.append(to_string(month));
            date_str.append("ος Μήνας ");
            date_str.append(" ");
            date_str.append(to_string(year));
            date_str.append(" Έτος");
            return date_str;
        }
        void operator+(int x){
            if(this->month + x > 12){
                this->month = this->month + x - 12;
                this->year++;
            }else{
                this->month = this->month + x;
            }
        }
        bool operator>(const date & x){
	        if(this->year > x.year){
		        return 1;
            }else if(this->year == x.year){
                if(this->month > x.month){
                    return 1;
                }else if(this->month == x.month){
                    if(this->day > x.day){
                        return 1;
                    }
                }
            }
	        return 0;
        };

};

date::date(int day_in, int month_in, int year_in){
    day = day_in;
    month = month_in;
    year = year_in;
}

date::date(date &x){
    day = x.day;
    month = x.month;
    year = x.year;
}

void bbsort(date *arr[3]){
    int i,j;
    for (i = 0; i < 3 - 1; i++){
        for (j = 0; j < 3 - i - 1; j++){
            if (*arr[j] > *arr[j + 1]){
                date * temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    date hey1(1,2,2006);
    date hey2(0,2,2007);
    date hey3(0,5,2005);
    date * arr[3];
    arr[0] = &hey1;    
    arr[1] = &hey2;    
    arr[2] = &hey3;    
    bbsort(arr);
    hey1 + 2;
    cout << hey1.date_string() << endl;
    cout << arr[0]->date_string() << endl;
    cout << arr[1]->date_string() << endl;
    cout << arr[2]->date_string() << endl;

}
