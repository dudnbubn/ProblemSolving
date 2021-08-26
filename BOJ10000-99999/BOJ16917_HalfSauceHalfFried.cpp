#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	if (a + b <= 2 * c) {
		cout << x * a + y * b;
	}
	else {
		int half = (x <= y) ? x : y;
		int price = half * c * 2;
		x -= half;
		y -= half;
		a = min(a, c * 2);
		b = min(b, c * 2);
		price += (x * a + y * b);
		cout << price;
	}
	return 0;
}