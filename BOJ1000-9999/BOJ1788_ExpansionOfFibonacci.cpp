#include <iostream>
using namespace std;

long long fibo[2000000];

int main() {
	int n;
	cin >> n;
	fibo[1000000] = 0;
	fibo[1000001] = 1;
	if (n > 0) {
		for (int i = 2; i <= n; i++)
			fibo[i + 1000000] = (fibo[i + 1000000 - 1] + fibo[i + 1000000 - 2]) % 1000000000;
	}
	else {
		for (int i = -1; i >= n; i--)
			fibo[i + 1000000] = (fibo[i + 1000000 + 2] - fibo[i + 1000000 + 1]) % 1000000000;
	}
	if (fibo[n + 1000000] > 0)	cout << 1;
	else if (fibo[n + 1000000] == 0)	cout << 0;
	else {
		cout << -1;
		fibo[n + 1000000] *= -1;
	}
	cout << "\n" << fibo[n + 1000000];
	return 0;
}