#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[200000];
int cache[200000];

int LIS() {
	int index = 0;
	cache[0] = arr[0];
	for (int i = 1; i < N; i++) {
		if (cache[index] < arr[i]) {
			cache[++index] = arr[i];
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

	cin >> N;
	for (int i = 0; i < N; i++)	cin >> arr[i];

	cout << N - LIS();
	return 0;

}