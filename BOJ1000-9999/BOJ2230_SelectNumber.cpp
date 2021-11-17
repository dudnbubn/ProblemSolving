#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)	cin >> arr[i];
	sort(arr, arr + n);

	int minimum = (1 << 31) - 1;
	int index = 0;
	for (int i = 0; i < n - 1; i++) {
		index = lower_bound(arr + i, arr + n, arr[i] + m) - arr;
		if(index < n)
			minimum = min(minimum, arr[index] - arr[i]);
	}
	cout << minimum;
	return 0;
}