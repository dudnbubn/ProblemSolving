#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int board[101][101];
queue<pair<int, int>> q;
queue<pair<int, int>> cheeses;
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0 ,-1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
			if (board[i][j])	cheeses.push({ i, j });
		}
	}

	pair<int, int> cur;
	int next_i, next_j;
	q.push({ 1,1 });
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			next_i = cur.first + di[k];
			next_j = cur.second + dj[k];
			if (next_i < 1 || next_j < 1 || next_i > n || next_j > m)
				continue;

			if (!board[next_i][next_j]) {
				board[next_i][next_j] = 2;
				q.push({ next_i, next_j });
			}
		}
	}
	int result = 0, qsz, cnt;
	while (!cheeses.empty()) {
		result++;
		qsz = cheeses.size();
		for (int i = 0; i < qsz; i++) {
			cur = cheeses.front();
			cheeses.pop();
			cnt = 0;
			for (int k = 0; k < 4; k++) {
				next_i = cur.first + di[k];
				next_j = cur.second + dj[k];
				if (board[next_i][next_j] == 2)
					cnt++;
			}
			
			if (cnt >= 2) 
				q.push(cur);
			else
				cheeses.push(cur);
		}

		while (!q.empty()) {
			cur = q.front();
			q.pop();
			board[cur.first][cur.second] = 2;
			for (int k = 0; k < 4; k++) {
				next_i = cur.first + di[k];
				next_j = cur.second + dj[k];

				if (!board[next_i][next_j]) {
					board[next_i][next_j] = 2;
					q.push({ next_i, next_j });
				}
			}
		}
	}
	cout << result;
	return 0;
}