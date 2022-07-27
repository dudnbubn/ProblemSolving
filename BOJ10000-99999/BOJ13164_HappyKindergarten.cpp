#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int arr[300001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;

	int prev, cur;
	cin >> prev;
	for (int i = 0;i < N - 1;i++) {
		cin >> cur;
		arr[i] = cur - prev;
		prev = cur;
	}

	sort(arr, arr + N - 1);

	int result = 0;
	for (int i = 0;i < N - K;i++) 
		result += arr[i];
	cout << result;

	return 0;
}