#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void menu();
void deposit(double& bal);
void withdraw(double& bal);



int main(int argc, char** argv) {
	int option;
	double balance = 50;
	do{
	menu();
	cout << "Choose action (1, 2, 3)\n" << endl;
	cin >> option;
	switch(option){
		case 1: cout << "\nYour Balance:" << balance << "\n" << endl;break;
		case 2: deposit(balance);break;
		case 3: withdraw(balance);break;
		case 4: exit(0);
		default: cout << "Wrong arguement, please give 1, 2, 3, 4" << endl;
	}
}while(1);
	return 0;
}

void menu(){
	cout << "1. Check Balance\n2. Deposit\n3. Withdraw\n4. Exit\n";
}

void deposit(double& bal){
	double amount;
	cout << "Give amount to deposit:\n" << endl;
	cin >> amount;
	bal += amount;
	cout << "New Balance: " << bal << "\n" << endl;
}

void withdraw(double& bal){
	double amount;
	cout << "Give amount to withdraw:\n" << endl;
	cin >> amount;
	if(amount <= bal){
		bal -= amount;	
		cout << "New Balance: " << bal << "\n" << endl;
	}
	else{
		cout << "Not enough money, check your balance." << endl;
	}

}
