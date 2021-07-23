#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int square[317] = { 0, };

int main() {
	int n;
	cin >> n;
	int sq = sqrt(n);
	if (sq * sq == n)
		cout << 1;
	else {
		if (n % 2 == 0)
			cout << 2;
		else {
			int cnt = 0;
			while (n != 0) {
				if (n >= sq * sq) {
					cnt += (n / (sq * sq));
					n %= (sq * sq);
				}
				sq--;
			}
			cout << min(cnt, 3);
		}
	}
	return 0;
}