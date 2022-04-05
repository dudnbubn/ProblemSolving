// key point : DP, Bottom Up

#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int n, k, x, y, w;
int D[1001];
int dp[1001];
bool matrix[1001][1001];

long long recur(int x) {
	if (dp[x] != -1)	return dp[x];
	long long result = D[x];
	for (int i = 1; i <= n; i++) {
		if (matrix[i][x])
			result = max(result, recur(i) + D[x]);
	}
	return dp[x] = result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		cin >> n >> k;
		memset(dp, -1, sizeof(dp));
		memset(matrix, 0, sizeof(matrix));
		for (int i = 1; i <= n; i++)	cin >> D[i];
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			matrix[x][y] = true;
		}
		cin >> w;
		cout << recur(w) << "\n";
	}
	return 0;
}