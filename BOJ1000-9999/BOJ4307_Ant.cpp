#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	int minimum, maximum;
	while (t--) {
		minimum = 0;
		maximum = 0;
		int n, l;
		cin >> l >> n;
		for (int i = 0; i < n; i++)	cin >> arr[i];
		sort(arr, arr + n);

		for (int i = 0; i < n; i++) {
			minimum = max(minimum, min(arr[i], l - arr[i]));
			if (i == 0 || i == n - 1)
				maximum = max(maximum, max(arr[i], l - arr[i]));
			else
				maximum = max(maximum, max(((arr[i] - arr[i - 1]) / 2) * 2 + l - arr[i], ((arr[i + 1] - arr[i]) / 2) * 2 + arr[i]));
		}
		cout << minimum << " " << maximum << "\n";
	}
	return 0;
}