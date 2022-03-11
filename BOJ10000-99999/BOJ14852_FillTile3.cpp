#include <iostream>

using namespace std;

#define DIV 1000000007

unsigned int dp[1000001][3];

int main() {
	dp[1][0] = 1;	dp[1][2] = 1;
	dp[2][0] = 3;	dp[2][1] = 2;	dp[2][2] = 2;

	int n;
	cin >> n;
	for (int i = 3; i <= n; i++) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] * 2) % DIV;
		dp[i][1] = (dp[i - 1][1] + (2 * dp[i - 1][2])) % DIV;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % DIV;
	}

	cout <<  (dp[n][0] + dp[n][1] + dp[n][2]) % DIV;
	return 0;
}