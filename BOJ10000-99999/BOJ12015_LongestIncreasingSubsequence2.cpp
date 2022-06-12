#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[1000001];
int cache[1000001];

int LIS() {
	int index = 0;
	cache[0] = A[0];
	for (int i = 1; i < N; i++) {
		if (cache[index] < A[i]) {
			index++;
			cache[index] = A[i];
		}
		else {
			int index2 = lower_bound(cache, cache + index, A[i]) - cache;
			cache[index2] = A[i];
		}
	}
	return index + 1;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> A[i];

	cout << LIS();
	return 0;
}