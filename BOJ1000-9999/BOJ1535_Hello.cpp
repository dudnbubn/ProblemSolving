// Brute Force

#include <iostream>
#include <algorithm>
using namespace std;

int n, maximum = 0;
int L[21];
int J[21];

void Brute(int life, int joy, int index) {
	if (life >= 100)	return;

	maximum = max(maximum, joy);
	for (int i = index + 1; i <= n; i++) {
		Brute(life + L[i], joy + J[i], i);
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)	cin >> L[i];
	for (int i = 1; i <= n; i++)	cin >> J[i];

	Brute(0, 0, 0);
	cout << maximum;
	return 0;
}