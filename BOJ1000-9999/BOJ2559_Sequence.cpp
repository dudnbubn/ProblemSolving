#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int arr[100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	int sum = 0, maximum = -1000000000;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
		if (i >= k - 1) {
			maximum = max(maximum, sum);
			sum -= arr[i - k + 1];
		}
	}
	cout << maximum;
	return 0;
}