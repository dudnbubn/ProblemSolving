#include <iostream>
#include <algorithm>


int arr[20000];
int sum[20000] = { 0, };

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)	std::cin >> arr[i];
	std::sort(arr, arr + n);
	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + arr[i - 1];
	}
	int minimum = 1000000000;
	int index = 0;
	int cnt = 0, subsum;
	for (int i = 1; i <= arr[n - 1]; i++) {
		cnt = std::upper_bound(arr, arr + n, i) - arr;
		subsum = (cnt * i - sum[cnt]) + ((sum[n] - sum[cnt]) - (n - cnt) * i);
		if (minimum > subsum) {
			minimum = subsum;
			index = i;
		}
	}
	std::cout << index;
	return 0;
}