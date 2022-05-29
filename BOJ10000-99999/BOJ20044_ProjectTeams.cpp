#include <iostream>
#include <algorithm>

using namespace std;

int arr[10000];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < 2 * n; i++)	cin >> arr[i];
	sort(arr, arr + 2 * n);

	int result = 200000;
	for (int i = 0; i < n; i++) 
		result = min(result, arr[i] + arr[2 * n - 1 - i]);

	cout << result;
	return 0;
}