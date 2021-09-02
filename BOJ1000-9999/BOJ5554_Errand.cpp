#include <iostream>
using namespace std;

int main() {
	int total = 0;
	for (int i = 0; i < 4; i++) {
		int t;
		cin >> t;
		total += t;
	}
	cout << total / 60 << "\n";
	cout << total % 60;
	return 0;
}