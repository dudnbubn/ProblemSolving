#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 500'000

int arr[MAX_N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	int sum = 0;
	for (int n = 0; n < N; n++) {
		cin >> arr[n];
		sum += arr[n];
	}

	sort(arr, arr + N);
	
	long long result = 0;
	for (int n = 0; n < N; n++) {
		result = result + (arr[n] * (sum - arr[n]));
		sum -= arr[n];
	}
	cout << result;
}