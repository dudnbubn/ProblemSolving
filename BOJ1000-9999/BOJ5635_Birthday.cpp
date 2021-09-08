#include <iostream>
using namespace std;

int n;
int maximum = 0;
int minimum = 20110000;
string old, young;

int main() {
	cin >> n;
	string name;
	int y, m, d;
	for (int i = 0; i < n; i++) {
		cin >> name >> d >> m >> y;
		int birthdate = y * 10000 + m * 100 + d;
		if (maximum < birthdate) {
			maximum = birthdate;
			young = name;
		}
		if (minimum > birthdate) {
			minimum = birthdate;
			old = name;
		}
	}
	cout << young << "\n" << old;
	return 0;
}