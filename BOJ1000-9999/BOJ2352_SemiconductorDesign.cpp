// key point : LIS

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[40000];
int cache[40000];

int LIS() {
	int index = 0, index2;
	cache[0] = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > cache[index]) {
			index++;
			cache[index] = arr[i];
		}
		else {
			index2 = lower_bound(cache, cache + index, arr[i]) - cache;
			cache[index2] = arr[i];
		}
	}
	return index + 1;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> arr[i];
	cout << LIS();
	return 0;
}