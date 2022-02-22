#include <iostream>

using namespace std;

int Euclid(int a, int b) {
	if (a == 0 || b == 0)	return 0;
	int n = (a < b ? a : b);
	a = (a > b ? a : b);
	b = n;
	n = a % b;
	while (n != 0) {
		a = b;
		b = n;
		n = a % b;
	}
	return b;
}

int main() {
	int n, m;
	cin >> n >> m;
	int gcd = Euclid(n, m);
	cout << m - gcd;
	return 0;
}