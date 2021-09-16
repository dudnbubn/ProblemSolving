#include <iostream>
using namespace std;

long long fibo[117];

int main() {
	int n;
	cin >> n;
	fibo[1] = 1; fibo[2] = 1;	fibo[3] = 1;
	for (int i = 4; i <= n; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 3];
	}
	cout << fibo[n];
	return 0;
}