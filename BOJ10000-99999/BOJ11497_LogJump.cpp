#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[10000];
int result[10000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	int n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)		cin >> arr[i];
		sort(arr, arr + n);

		for (int i = 0, start = 0, end = n - 1; i < n; i++, start++, end--) {
			result[start] = arr[i];
			if (i < n - 1)
				result[end] = arr[++i];
		}

		int gap = abs(result[n - 1] - result[0]);
		for (int i = 1; i < n; i++) {
			gap = max(gap, abs(result[i] - result[i - 1]));
		}
		cout << gap << "\n";
	}
	return 0;
}