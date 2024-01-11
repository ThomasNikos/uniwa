#include <iostream>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main() {
	float wei, hei, bmi;
	cout << "Give weight:\n";
	cin >> wei;
	cout << "Give height:\n";
	cin >> hei;
	bmi = wei/(hei*hei);
	if(bmi < 18.5)
	cout << "UnderWeight\n";
	else if(bmi > 25)
	cout << "OverWeight\n";
	else
	cout << "Normal Weight\n";
	cout << "Your bmi :" << bmi;	
	
	return 0;
}
