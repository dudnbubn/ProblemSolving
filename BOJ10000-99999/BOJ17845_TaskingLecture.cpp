#include <iostream>
#include <algorithm>

using namespace std;

int N, K;

int dp[1001][10001];
int weight[1001];
int value[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;

	for (int i = 1; i <= K; i++) 
		cin >> value[i] >> weight[i];

	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= N; j++) {
			if (weight[i] > j)	dp[i][j] = dp[i - 1][j];
			else	dp[i][j] = max(dp[i - 1][j - weight[i]] + value[i], dp[i - 1][j]);
		}
	}
	cout << dp[K][N];
	return 0;
}