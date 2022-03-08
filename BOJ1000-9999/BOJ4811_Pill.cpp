#include <iostream>

using namespace std;

long long ncr[61][61];

long long nCr(int n, int r) {
	if (r == 0)	return 1;
	if (n < r)	return 0;
	if (ncr[n][r] != 0)	return ncr[n][r];

	return ncr[n][r] = nCr(n - 1, r - 1) + nCr(n - 1, r);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	while (n) {
		if (n == 1)	cout << 1 << "\n";
		else if (n == 2)	cout << 2 << "\n";
		else	cout << nCr((n - 1) * 2, n - 1) - nCr((n - 1) * 2, n - 3) << "\n";
		cin >> n;
	}
	return 0;
}