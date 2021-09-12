#include <iostream>
using namespace std;

long long dp[36] = { 0, };

int main() {
	dp[0] = 1;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= (i - 1) / 2; j++) {
			dp[i] += (2 * dp[j] * dp[i - j - 1]);
		}
		if (i % 2 == 1) dp[i] -= dp[i / 2] * dp[i / 2];
	}
	cout << dp[n];
	return 0;
}