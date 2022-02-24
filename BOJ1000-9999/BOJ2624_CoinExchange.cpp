#include <iostream>
#include <algorithm>
using namespace std;

int dp[101][10001];
pair<int, int> arr[101];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)	cin >> arr[i].first >> arr[i].second;
	sort(arr + 1, arr + m + 1);
	dp[0][0] = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= arr[i].second; j++) {
			for (int k = arr[i].first * j; k <= n; k++) {
				dp[i][k] += dp[i - 1][k - arr[i].first * j];
			}
		}
	}
	cout << dp[m][n];
	return 0;
}