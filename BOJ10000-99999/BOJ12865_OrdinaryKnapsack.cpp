#include <iostream>

using namespace std;

int n, k;
int weight[101], value[101];
int dp[101][100001];

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) 
		cin >> weight[i] >> value[i];

	for (int i = 1; i <= n; i++) {
		for (int w = 1; w <= k; w++) {
			if (weight[i] <= w) {
				if (value[i] + dp[i - 1][w - weight[i]] > dp[i - 1][w])
					dp[i][w] = value[i] + dp[i - 1][w - weight[i]];
				else
					dp[i][w] = dp[i - 1][w];
			}
			else
				dp[i][w] = dp[i - 1][w];
		}
	}
	cout << dp[n][k];
	return 0;
}