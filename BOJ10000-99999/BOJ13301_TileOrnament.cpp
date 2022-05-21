#include <iostream>

using namespace std;

long long fibo[82];

int main() {
	fibo[1] = 1;	fibo[2] = 1;
	int n;
	cin >> n;
	for (int i = 3; i <= n + 1; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	
	cout << 2 * (fibo[n] + fibo[n + 1]);
	return 0;
}