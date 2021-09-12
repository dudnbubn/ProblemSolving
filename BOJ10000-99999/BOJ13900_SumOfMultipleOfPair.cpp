#include <iostream>
using namespace std;

int n;
long long arr[100001] = { 0, };
long long sum[100001] = { 0, };

int main() {
	cin >> n;
	long long result = 0;
	for (int i = 1; i <= n; i++)	cin >> arr[i];
	for (int i = 1; i < n; i++) {
		sum[i] = sum[i - 1] + arr[i];
		result += (sum[i] * arr[i + 1]);
	}
	cout << result;
	return 0;
}