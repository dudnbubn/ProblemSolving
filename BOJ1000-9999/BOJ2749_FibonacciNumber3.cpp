// key point : 피사노 주기(pisano period)
//				주기 k(10^n) = 15 * 10^(n-1)


#include <iostream>

using namespace std;

int main() {
	long long n;
	cin >> n;

	int a = 0, b = 1, c = 1;
	for (int i = 1; i < n % 1500000; i++) {
		c = (a + b) % 1000000;
		a = b;
		b = c;
	}
	cout << c;

	return 0;
}