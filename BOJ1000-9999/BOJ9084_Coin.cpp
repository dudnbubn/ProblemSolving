#include <iostream>
using namespace std;

int n, m;
int dp[21][10001];
int arr[21];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < 21; i++)
			for (int j = 0; j < 10001; j++)
				dp[i][j] = 0;

		cin >> n;
		for (int i = 1; i <= n; i++)	cin >> arr[i];
		cin >> m;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				dp[i][j] = dp[i - 1][j];
				if (j == arr[i])	dp[i][j]++;
				
				if(j >= arr[i])
					dp[i][j] += dp[i][j - arr[i]];
			}
		}

		cout << dp[n][m] << "\n";
	}
	return 0;
}