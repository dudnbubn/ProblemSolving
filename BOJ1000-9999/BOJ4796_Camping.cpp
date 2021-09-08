#include <iostream>
using namespace std;

int main() {
	int l, p, v, testcase = 0;
	int q, r, day;
	cin >> l >> p >> v;
	while (l + p + v) {
		q = v / p;
		r = v % p;
		day = q * l;
		if (l >= r)	day += r;
		else	day += l;
		testcase++;
		cout << "Case " << testcase << ": " << day << "\n";
		cin >> l >> p >> v;
	}
	return 0;
}