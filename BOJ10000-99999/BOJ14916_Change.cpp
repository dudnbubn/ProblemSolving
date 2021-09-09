#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int change, minimum = 100000, two;
	cin >> change;
	for (int i = 0; i * 5 <= change; i++) {
		if ((change - (i * 5)) % 2 == 0)
			minimum = min(minimum, i + (change - (i * 5)) / 2);
	}
	if (minimum == 100000)	cout << -1;
	else	cout << minimum;

	return 0;
}