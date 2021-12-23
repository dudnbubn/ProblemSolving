#include <iostream>
using namespace std;

int one_count(int k) {
	int result = 0;
	for (int i = 16777216; i > 0; i /= 2) {
		if (k >= i) {
			result++;
			k -= i;
		}
	}
	return result;
}

int main() {
	int n, k;
	cin >> n >> k;

	int bin = 1;
	int buy = 0;
	while (1) {
		while (n % 2 == 0) {
			n /= 2;
			bin *= 2;
		}
		if (one_count(n) <= k) {
			cout << buy;
			return 0;
		}
		else {
			n++;
			buy += bin;
		}
	}
	cout << -1;
	return 0;
}