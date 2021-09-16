#include <iostream>
#include <algorithm>
using namespace std;

long long Euclid(long long a, long long b) {
	int n = max(a, b);
	b = min(a, b);
	a = n;
	n = a % b;
	while (n != 0) {
		a = b;
		b = n;
		n = a % b;
	}
	return b;
}

int main() {
	long long a, b, gcd;
	cin >> a >> b;
	gcd = Euclid(a, b);
	cout << a * b / gcd;
	return 0;
}