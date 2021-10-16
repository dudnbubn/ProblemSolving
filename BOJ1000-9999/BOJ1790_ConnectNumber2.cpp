#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	long long div = 1;
	while (n / div)
		div *= 10;
	div /= 10;
	long long tot = 0;
	long long nine = 9, len = 1;
	while (nine < div) {
		tot += nine * len;
		nine *= 10;
		len++;
	}
	tot += len * (n - div + 1);
	if (tot < k)	cout << -1;
	else {
		nine = 9; len = 1;
		while (nine * len < k) {
			k -= nine * len;
			nine *= 10;
			len++;
		}
		div = nine / 9;
		long long result = div + ((k - 1) / len);
		int index = (k - 1) % len;
		for (int i = 0; i < index; i++)	div /= 10;
		cout << (result / div) % 10;
	}
	return 0;
}