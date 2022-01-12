// key point : LIS ( Longest Increasing Subsequence )

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[501];
int cache[501];

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
	cin >> n;
	pair<int, int> input[501];
	for (int i = 0; i < n; i++) 
		cin >> input[i].first >> input[i].second;
	sort(input, input + n);
	for (int i = 0; i < n; i++)
		arr[i] = input[i].second;

	cout << n - LIS();
	return 0;
}