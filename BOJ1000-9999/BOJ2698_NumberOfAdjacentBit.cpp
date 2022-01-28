#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> input[1000];
int dp[101][101][2];

int main() {
	int t;
	cin >> t;
	int maximum = 0;
	for (int i = 0; i < t; i++) {
		cin >> input[i].first >> input[i].second;
		maximum = max(maximum, input[i].first);
	}

	dp[1][0][0] = 1;
	dp[1][0][1] = 1;
	for (int i = 2; i <= maximum; i++) {
		dp[i][0][0] = dp[i - 1][0][0] + dp[i - 1][0][1];
		dp[i][0][1] = dp[i - 1][0][0];
		for (int j = 1; j < i - 1; j++) {
			dp[i][j][0] = dp[i-1][j][0] + dp[i - 1][j][1];
			dp[i][j][1] = dp[i - 1][j - 1][1] + dp[i - 1][j][0];
		}
		dp[i][i - 1][0] = 0;
		dp[i][i - 1][1] = 1;
	}
	
	for (int i = 0; i < t; i++) {
		cout << dp[input[i].first][input[i].second][0] + dp[input[i].first][input[i].second][1] << "\n";
	}
	return 0;
}