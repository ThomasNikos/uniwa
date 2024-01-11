#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int x, y, i, j;
	char symbol;
	cout << "Give Height, Width, Symbol :\n";
	cin >> x >> y >> symbol;
	for(i=1;i<=x;i++){
		for(j=1;j<=i;j++){
			cout << symbol;
		}
		cout << endl;
	}
	return 0;
}
