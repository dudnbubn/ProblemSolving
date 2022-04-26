#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100000];
int cache[100000];

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
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (true) {
		cin >> n;
		if (cin.eof())		break;
		for (int i = 0; i < n; i++)		cin >> arr[i];
		cout << LIS() << "\n";
	}
	return 0;
}