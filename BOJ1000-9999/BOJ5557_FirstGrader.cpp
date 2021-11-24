#include <iostream>
using namespace std;

int n;
int arr[101];
long long dp[101][21] = { 0, };

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)	cin >> arr[i];
	dp[1][arr[1]] = 1;

	for (int i = 2; i < n; i++) {
		for (int j = 0; j <= 20 - arr[i]; j++) {
			dp[i][j + arr[i]] += dp[i - 1][j];
		}
		for (int j = 20; j >= arr[i]; j--) {
			dp[i][j - arr[i]] += dp[i - 1][j];
		}
	}
	cout << dp[n - 1][arr[n]];
	return 0;
}