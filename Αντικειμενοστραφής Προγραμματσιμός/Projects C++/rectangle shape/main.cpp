#include <iostream>
#include <iomanip>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int hei, wid, i, j;
	char symbol;
	cout << "Give height:\n";
	cin >> hei;
	cout << "Give width:\n";
	cin >> wid;
	cout << "Give symbol:\n";
	cin >> symbol;
	for(j=0;j < hei;j++){
		for(i = 0;i < wid;i++){
			cout << setw(2) << symbol;
		}
		cout << endl;
	}
	
	return 0;
}
