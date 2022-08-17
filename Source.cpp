
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
using namespace std;

int main() {

	int a = 0;
	int b = 0;

	while (a != 3) {
		cout << "Enter Num: " << endl;
		cin >> a;

		if (a == 1) {
			cout << "Table" << endl;
			cout << "Enter Val: ";
			cin >> b;
			cout << b * 2 << endl;
			continue;
			
		}
		if (a == 2) {
			cout << "Double" << endl;
			cin >> b;
			cout << b * b << endl;
			continue;
		}
		if (a == 3) {
			break;
		}
		cout << "Enter Num again: ";
		cin >> a;
		continue;
	}
	cout << "Closing" << endl;



	return 0;
}
