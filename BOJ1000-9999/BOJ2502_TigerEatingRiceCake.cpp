#include <iostream>
using namespace std;

int fibo[26];

int main() {
	fibo[1] = 1;
	fibo[2] = 1;
	for (int i = 3; i < 26; i++)	fibo[i] = fibo[i - 1] + fibo[i - 2];

	int d, k;
	cin >> d >> k;
	int a, b = 0;
	while (1) {
		b++;
		for (a = 1; a <= b; a++) {
			if (a * fibo[d - 2] + b * fibo[d - 1] == k) {
				cout << a << "\n" << b;
				return 0;
			}
		}
	}
}