#include <iostream>

using namespace std;

#define MOD 1000000007

int n, m;
int dp[1001][1001];

int main() {
	cin >> n >> m;
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			dp[i][j] = ((dp[i - 1][j] + dp[i][j - 1]) % MOD + dp[i - 1][j - 1]) % MOD;

	cout << dp[n][m];
	return 0;
}