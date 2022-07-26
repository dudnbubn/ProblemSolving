#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int arr[10001];
int dif[10001];

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
	sort(arr, arr + N);
	for (int i = 0; i < N - 1; i++)
		dif[i] = arr[i + 1] - arr[i];
	
	sort(dif, dif + N - 1);
	
	int result = 0;
	for (int i = 0; i < N - K; i++)
		result += dif[i];

	cout << result;

	return 0;
}