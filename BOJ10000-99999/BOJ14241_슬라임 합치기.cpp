#include <iostream>
#include <algorithm>

using namespace std;

int arr[100];

int main() {
	int N;
	cin >> N;
	for (int n = 0; n < N; n++)	cin >> arr[n];
	sort(arr, arr + N);

	long long result = 0;
	for (int n = N - 1; n > 0; n--) {
		result += arr[n] * arr[n - 1];
		arr[n - 1] += arr[n];
	}
	cout << result;
	return 0;
}