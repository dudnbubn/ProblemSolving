#include <iostream>

using namespace std;

int main() {
	bool asc = true, desc = true;
	int num;
	for (int i = 1; i <= 8; i++) {
		cin >> num;
		if (num != i)	asc = false;
		if (num != 8 - i + 1)	desc = false;
	}

	if (asc)	cout << "ascending";
	else if (desc)	cout << "descending";
	else	cout << "mixed";
	return 0;
}