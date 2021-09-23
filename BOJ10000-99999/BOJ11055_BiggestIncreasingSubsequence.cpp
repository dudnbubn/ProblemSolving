#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001] = { 0, };
int sum[1001] = { 0, };
int maximum = 0;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)	cin >> arr[i];
	for (int i = 1; i <= n; i++) {
		sum[i] = arr[i];
		for (int j = i - 1; j >= 1; j--) {
			if (arr[j] < arr[i]) {
				sum[i] = max(sum[i], sum[j] + arr[i]);
			}
		}
		maximum = max(maximum, sum[i]);
	}
	cout << maximum;
	return 0;
}