#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 987654321

int n, k;
int dp[101][10001];
set<int> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> x;
		s.insert(x);
	}

	n = s.size();

	vector<int> v(s.begin(), s.end());
	
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 10001; j++)
			dp[i][j] = INF;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j * v[i] <= k; j++) {
			dp[i][j * v[i]] = j;
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= v[i]) {
				dp[i][j] = min(min(dp[i - 1][j - v[i]], dp[i][j - v[i]]) + 1, dp[i - 1][j]);
				//cout << "dp[" << i << "][" << j << "] = min(min(" << dp[i - 1][j - v[i]] << ", " << dp[i][j - v[i]] << ") + 1, " << dp[i - 1][j] << ") = " << dp[i][j] << "\n";
			}
			else {
				dp[i][j] = dp[i - 1][j];
				//cout << "dp[" << i << "][" << j << "] = " << dp[i - 1][j] << "\n";
			}
		}
	}
	if (dp[n - 1][k] >= INF)
		cout << -1;
	else
		cout << dp[n - 1][k];
	return 0;
}