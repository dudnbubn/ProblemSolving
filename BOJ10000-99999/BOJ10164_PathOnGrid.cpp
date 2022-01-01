#include <iostream>
using namespace std;

int n, m, k;
int dp[16][16];

int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)	dp[i][1] = 1;
	for (int i = 1; i <= m; i++)	dp[1][i] = 1;

	if (k == 0) {
		for (int i = 2; i <= n; i++) {
			for (int j = 2; j <= m; j++) {
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]);
			}
		}
		cout << dp[n][m];
	}
	else {
		int robot_r, robot_c;
		robot_r = (k - 1) / m + 1;
		robot_c = (k - 1) % m + 1;

		for (int i = 2; i <= robot_r; i++) {
			for (int j = 2; j <= robot_c; j++) {
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]);
			}
		}
		for (int i = robot_r + 1; i <= n; i++)	dp[i][robot_c] = dp[robot_r][robot_c];
		for (int i = robot_c + 1; i <= m; i++)	dp[robot_r][i] = dp[robot_r][robot_c];

		for (int i = robot_r + 1; i <= n; i++) {
			for (int j = robot_c + 1; j <= m; j++) {
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]);
			}
		}
		cout << dp[n][m];
	}

	return 0;
}