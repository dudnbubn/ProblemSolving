#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int Euclid(int a, int b) {
	int temp = min(a, b);
	a = max(a, b);
	b = temp;
	int n = a % b;
	while (n != 0) {
		a = b;
		b = n;
		n = a % b;
	}
	return b;
}

int main() {
	int n = 0, m = 0;
	string input;
	getline(cin, input, ':');
	for (int i = 0; i < input.size(); i++)	n = (n * 10) + (input[i] - '0');
	getline(cin, input);
	for (int i = 0; i < input.size(); i++)	m = (m * 10) + (input[i] - '0');

	int gcd = Euclid(n, m);

	cout << n / gcd << ":" << m / gcd;
	return 0;
}