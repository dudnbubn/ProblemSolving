#include <iostream>
#include <cmath>

using namespace std;

int main() {
	long long n, q;
	cin >> n;
	
	q = sqrt(n);
	if (q * q >= n)	cout << q;
	else	cout << q + 1;
	return 0;
}