#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int k, c;
	cin >> k >> c;
	int n, m;
	for (int i = 0; i < c; i++) {
		cin >> m >> n;
		if (m == n)	cout << "1\n";
		else if (m > n) {
			if ((m - n) <= (k - m + 2))	cout << "1\n";
			else	cout << "0\n";
		}
		else {
			if ((n - m) <= (k - n + 1))	cout << "1\n";
			else	cout << "0\n";
		}
	}
	return 0;
}