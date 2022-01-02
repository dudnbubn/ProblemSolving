#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001][3];
int dp[100001][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, t = 1;
	cin >> n;
	while (n > 0) {
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 3; j++)
				cin >> arr[i][j];
		}
		
		dp[1][0] = arr[1][0];
		dp[1][1] = arr[1][1];
		dp[1][2] = arr[1][1] + arr[1][2];
		
		dp[2][0] = dp[1][1] + arr[2][0];
		dp[2][1] = min(min(dp[2][0], dp[1][1]), dp[1][2]) + arr[2][1];
		dp[2][2] = min(min(dp[2][1], dp[1][1]), dp[1][2]) + arr[2][2];

		for (int i = 3; i <= n; i++) {
			dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][0];
			dp[i][1] = min(dp[i - 1][0], min(dp[i - 1][1], min(dp[i - 1][2], dp[i][0]))) + arr[i][1];
			dp[i][2] = min(dp[i - 1][1], min(dp[i - 1][2], dp[i][1])) + arr[i][2];
		}
		
		cout << t++ << ". " << dp[n][1] << "\n";
		cin >> n;
	}
	return 0;
}