#include <iostream>
using namespace std;

int arr[100];

int main() {
	int n, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> arr[i];
	for (int i = n - 2; i >= 0; i--) {
		if (arr[i] < arr[i + 1])	continue;
		cnt += (arr[i] - arr[i + 1] + 1);
		arr[i] = arr[i + 1] - 1;
	}
	cout << cnt;
	return 0;
}