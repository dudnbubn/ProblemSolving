#include <iostream>
using namespace std;

int arr[51];
bool dp[51][1001];

int main() {
	int n, m, s;
	cin >> n >> s >> m;
	for (int i = 0; i < n; i++)	cin >> arr[i];
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			dp[i][j] = 0;

	dp[0][s] = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			if (dp[i][j]) {
				if (j - arr[i] >= 0)	dp[i + 1][j - arr[i]] = true;
				if (j + arr[i] <= m)	dp[i + 1][j + arr[i]] = true;
			}
		}
	}
	for (int i = m; i >= 0; i--) {
		if (dp[n][i]) {
			cout << i;
			return 0;
		}
	}
	cout << -1;
	return 0;
}