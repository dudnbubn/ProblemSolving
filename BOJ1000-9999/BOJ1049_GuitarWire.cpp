#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m, six = 1000, one = 1000;
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		six = min(six, a);
		one = min(one, b);
	}
	int minimum = min((n / 6 * six) + ((n % 6) * one), n * one);
	minimum = min(minimum, (n + 5) / 6 * six);
	cout << minimum;

	return 0;
}