#include <iostream>
using namespace std;

int main() {
	int stone;
	cin >> stone;
	if (stone % 2 == 1)	cout << "SK";
	else	cout << "CY";
	return 0;
}