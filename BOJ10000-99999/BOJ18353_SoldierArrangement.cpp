#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[2000];
int cache[2000];

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
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = n - 1; i >= 0; i--)	cin >> arr[i];
	cout << n - LIS();
	return 0;
}