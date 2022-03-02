#include <iostream>

using namespace std;

int n;
int board[17][17];
int dp[17][17][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> board[i][j];

	dp[1][2][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!(board[i][j - 1] || board[i][j]))
				dp[i][j][0] += (dp[i][j - 1][0] + dp[i][j - 1][1]);
			if (!(board[i - 1][j] || board[i - 1][j - 1] || board[i][j - 1] || board[i][j]))
				dp[i][j][1] += (dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2]);
			if (!(board[i - 1][j] || board[i][j]))
				dp[i][j][2] += (dp[i - 1][j][1] + dp[i - 1][j][2]);
		}
	}

	cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
	return 0;
}