#include <iostream>
#include <algorithm>

using namespace std;

#define INF 987654321

pair<int, int> arr[21];
int dp[21][100001];

bool comp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main() {
	int c, n;
	cin >> c >> n;

	for (int i = 1; i <= n; i++)	cin >> arr[i].first >> arr[i].second;
	sort(arr + 1, arr + n + 1, comp);
	
	for (int j = 0; j < 100001; j++)	dp[0][j] = INF;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 100000; j++) {
			if (j < arr[i].second)	dp[i][j] = dp[i - 1][j];
			else	dp[i][j] = min(dp[i - 1][j], dp[i][j - arr[i].second] + arr[i].first);
		}
	}
	
	int result = INF;
	for (int i = c; i <= 100000; i++)
		if(dp[n][i] != 0)
			result = result < dp[n][i] ? result : dp[n][i];
	
	cout << result;
	return 0;
}