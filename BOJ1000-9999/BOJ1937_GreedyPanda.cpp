#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int board[501][501];
int dp[501][501];
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };
vector<pair<int, int>> v;

bool compare(pair<int, int> a, pair<int, int> b) {
	return board[a.first][a.second] > board[b.first][b.second];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
			v.push_back({ i, j });
		}
	}

	sort(v.begin(), v.end(), compare);
	
	int result = 0;
	int next_i, next_j;
	for (pair<int, int> p : v) {
		for (int k = 0; k < 4; k++) {
			next_i = p.first + di[k];
			next_j = p.second + dj[k];

			if (next_i < 1 || next_j < 1 || next_i > n || next_j > n)
				continue;

			if (board[p.first][p.second] < board[next_i][next_j]) 
				dp[p.first][p.second] = max(dp[p.first][p.second], dp[next_i][next_j]);
		}
		dp[p.first][p.second]++;
		result = max(result, dp[p.first][p.second]);
	}
	cout << result;
	return 0;
}