#include <iostream>

using namespace std;

int n, k;
int arr[100000];

int withdraw(int p) {
	int result = 0;
	int remain = 0;
	for (int i = 0; i < n; i++) {
		if (remain < arr[i]) {
			result++;
			remain = p - arr[i];
		}
		else
			remain -= arr[i];
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k;
	int start = 0, end = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		start = start > arr[i] ? start : arr[i];
		end += arr[i];
	}

	while (start <= end) {
		int mid = (start + end) / 2;

		if (withdraw(mid) > k)	start = mid + 1;
		else	end = mid - 1;
	}
	cout << start;
	return 0;
}