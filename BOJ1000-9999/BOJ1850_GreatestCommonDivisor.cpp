#include <iostream>
#include <algorithm>
using namespace std;

long long Euclid(long long a, long long b) {
	long long n = a % b;
	while (n != 0) {
		a = b;
		b = n;
		n = a % b;
	}
	return b;
}
int main() {
	long long a, b;
	cin >> a >> b;
	long long end = Euclid(max(a, b), min(a,b));
	for (int i = 0; i < end; i++)	cout << 1;
	return 0;
}