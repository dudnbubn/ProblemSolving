// key point : Longest Increasing Subsequence

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[201];
int cache[201];

int LIS() {
	int index = 0;
	cache[0] = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > cache[index]) {
			index++;
			cache[index] = arr[i];
		}
		else {
			int index2 = lower_bound(cache, cache + index, arr[i]) - cache;
			cache[index2] = arr[i];
		}
	}
	return index + 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++)	cin >> arr[i];

	cout << n - LIS();
	return 0;
}