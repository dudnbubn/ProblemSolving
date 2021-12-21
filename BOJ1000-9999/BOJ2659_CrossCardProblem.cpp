#include <iostream>
#include <algorithm>
using namespace std;

bool clock_number[10000] = { 0, };

int main() {
	int a, b, c, d;
	int i, j, k, l;
	int minimum;
	for (i = 1; i < 10; i++) {
		for (j = 1; j < 10; j++) {
			for (k = 1; k < 10; k++) {
				for (l = 1; l < 10; l++) {
					a = i * 1000 + j * 100 + k * 10 + l;
					b = i + j * 1000 + k * 100 + l * 10;
					c = i * 10 + j + k * 1000 + l * 100;
					d = i * 100 + j * 10 + k + l * 1000;
					minimum = min(min(a, b), min(c, d));
					clock_number[minimum] = true;
				}
			}
		}
	}
	cin >> i >> j >> k >> l;
	a = i * 1000 + j * 100 + k * 10 + l;
	b = i + j * 1000 + k * 100 + l * 10;
	c = i * 10 + j + k * 1000 + l * 100;
	d = i * 100 + j * 10 + k + l * 1000;
	minimum = min(min(a, b), min(c, d));

	int cnt = 1;
	for (int i = 1111; i < 10000; i++) {
		if (i == minimum) {
			cout << cnt;
			break;
		}
		if (clock_number[i])
			cnt++;
	}
	return 0;
}