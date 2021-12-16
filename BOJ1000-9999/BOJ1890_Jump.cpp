#include <iostream>
using namespace std;

int n;
int arr[101][101];
long long dp[101][101] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	dp[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k < i; k++) {
				if ((arr[k][j] + k) == i)
					dp[i][j] += dp[k][j];
			}
			for (int k = 1; k < j; k++) {
				if ((arr[i][k] + k) == j)
					dp[i][j] += dp[i][k];
			}
		}
	}
	cout << dp[n][n];
	return 0;
}