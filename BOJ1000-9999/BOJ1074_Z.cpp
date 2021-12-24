#include <iostream>
using namespace std;

int n, r, c;

int main() {
	cin >> n >> r >> c;
	r++;
	c++;
	int result = 0;
	int l = 1;
	for (int i = 0; i < n; i++)	l *= 2;
	int a = l * l;

	while (a) {
		l /= 2;
		a /= 4;
		if (r <= l) {
			if (c <= l) {

			}
			else {
				result += a;
				c -= l;
			}
		}
		else {
			if (c <= l) {
				result += a * 2;
				r -= l;
			}
			else {
				result += a * 3;
				r -= l;
				c -= l;
			}
		}
	}
	cout << result;
	return 0;
}