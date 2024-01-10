#include <iostream>

using namespace std;

void table();
void number(int &n);
int & Mod2_0(int Numbers[],int y);
int calc(int a, int b);
double calc(int a, double b);
void default_times(int x = 15, int y=3){
        cout << "Το " << x << " + " << y << " ισούται με: " << x+y << endl;
};


int main(){

//1. Αλλαγή τιμής από const.

const double num = 21.39;
double *p;
p = (double *) &num;
*p = 00.68;
cout << "Έχει αλλάξει αλλά θα εμφανίζει ακόμα: " << num << endl;

/*Όταν χρησιμοποιούμε "const" ο compiler οπουδήποτε υπάρχει το όνομα της μεταβλητής που είναι const, θα βάλει εξαρχής την τιμή της μεταβλητής χωρίς να κάνει περαιτέρω πράξεις.
Για αυτό ακόμα και αν αλλάζουμε την τιμή με την βοήθεια pointer ο compiler θα συνεχίσει να τυπώνει την αρχική τιμή της μεταβλητής που ορίσαμε ως const.*/

//2.

table();

//3.

int y, n;
cout << "Δώσε νούμερο για να πολλαπλασιαστεί με το 3, 5 φορές: " << endl;
cin >> n;
int Numbers[6];
for(int i = 0;i < 5;i++){
	number(n);
	Numbers[i] = n;
}
Numbers[5] = 0;
int & Mod2 = Mod2_0(Numbers,5);
cout << "Ο μεγαλύτερος αριθμός του πίνακα: " << n << endl;
if (Mod2 != 0)
	cout << "Ο μεγαλύτερος αριθμός που μπορεί να διαιρεθεί με το 2 είναι: " << Mod2 << endl;
else
	cout << "Κανένας από τους νέους αριθμούς δεν μπορεί να διαιρεθεί με το 2 και να έχει υπόλοιπο 0" << endl;

//4. Υπερφόρτωση συνάρτησης.
int a=0;
cout << "Με ποιόν αριθμό θα ήθελες να πολλαπλασιάσεις τώρα το " << Mod2 << ", με το (1)2 ή το (2)2.15" << endl;
while((a!=1) && (a!=2)){
	cout << "Γράψε 1 ή 2." << endl;
	cin >> a;
}
if(a == 1)
	cout << "Το αποτέλεσμα είναι: " << calc(Mod2, 2) << endl;
else
	cout << "Το αποτέλεσμα είναι: " << calc(Mod2, 2.15) << endl;
//Default τιμές.
cout << "Με default παραμέτρους: " << endl;
default_times();
//Με άλλες τιμές.
cout << "Με άλλες παραμέτρους: " << endl;
default_times(4, 7);
}

//Χρήση new, new[], delete, delete[].
void table(){
int *p;
p= new int;
*p = 20;
cout << "--" << *p << "--" << endl;
delete p;
int *z, y;
z = new int[8];
//Δημιουργεί πίνακα τύπου int.
for(int i=0;i<8;i++){
	cout << "Δώσε αριθμό για τη " << i << " θέση του πίνακα." << endl;
	cin >> z[i];
}
cout << "Από ποιά θέση του πίνακα θέλεις να εκτυπώσεις το περιεχόμενο;" << endl;
do{
	cin >> y;
}while(y < 0 || y > 7);
cout << "Το περιεχόμενο της θέσης " << y << " του πίνακα είναι: " << z[y] << endl;
delete[] z;
//Το delete απελευθερώνει την μνήμη που δεσμεύσαμε προηγουμένως.
}

//Πολλαπλασιασμός του n και επιστροφή του στο κύριο πρόγραμμα (αναφορά στην παράμετρο).
void number(int &n){
n *= 3;
}

//Επιστρέφει το μεγαλύετο αριθμό του πίνακα που μπορεί να διαιρεθει με το 2 και να έχει υπόλοιπο 0, αν δεν υπάρχει αυτός επιστρέφει το Numbers[5] δηλαδή το 0 (αναφορά συνάρτησης).
int & Mod2_0(int Numbers[], int y){
int result = -1;
for(int i = 0;i < y;i++){
	if(Numbers[i]%2==0)
		result = i;
}
if(result != -1)
	return Numbers[result];
else
	return Numbers[5];
}

//Η int calc εκτελείται μόνο όταν η δεύτερη παράμετρος είναι int.
int calc(int a, int b){
return a * b;
}

//Η double calc εκτελείται μόνο όταν η δεύτερη παράμετρος είναι double.
double calc(int a, double b){
return a * b;
}


