#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1000];
int darr[1000];
int lis[1000];
int lds[1000];

int LDS(int end) {
	int index = 0;
	for (int i = 0; i < N; i++)	lds[i] = 0;

	lds[0] = darr[0];
	for (int i = 1; i < N - end; i++) {
		if (lds[index] < darr[i]) {
			index++;
			lds[index] = darr[i];
		}
		else {
			int index2 = lower_bound(lds, lds + index, darr[i]) - lds;
			lds[index2] = darr[i];
		}
	}
	return index + 1;
}

int LIS() {
	int result = LDS(0);
	int index = 0;
	
	lis[0] = arr[0];
	for (int i = 1; i < N; i++) {
		if (lis[index] < arr[i]) {
			index++;
			lis[index] = arr[i];
		}
		else {
			int index2 = lower_bound(lis, lis + index, arr[i]) - lis;
			lis[index2] = arr[i];
		}
		result = max(result, index + LDS(i));
	}
	return result;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		darr[N - i - 1] = arr[i];
	}

	cout << LIS();
	return 0;
}