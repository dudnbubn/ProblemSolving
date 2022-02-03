#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<pair<int, int>, pair<int, int>> info;

int n, m;
int start_i, start_j;
char board[101][101];
int status[101][101][4];
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };
priority_queue<info, vector<info>, greater<info>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> m >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'C') {
				start_i = i;
				start_j = j;
			}
		}
	}

	info cur;
	int next_i, next_j;
	
	for (int k = 0; k < 4; k++) {
		status[start_i][start_j][k] = 2;
		next_i = start_i + di[k];
		next_j = start_j + dj[k];
		if (next_i < 1 || next_j < 1 || next_i > n || next_j > m)
			continue;

		if (board[next_i][next_j] == '.') {
			status[next_i][next_j][k] = 1;
			pq.push({ {0, k}, {next_i, next_j} });
		}
	}
	while (1) {
		cur = pq.top();
		pq.pop();
		while (status[cur.second.first][cur.second.second][cur.first.second] == 2) {
			cur = pq.top();
			pq.pop();
		}
		status[cur.second.first][cur.second.second][cur.first.second] = 2;
		if (board[cur.second.first][cur.second.second] == 'C') {
			cout << cur.first.first;
			return 0;
		}
		for (int k = 0; k < 4; k++) {
			next_i = cur.second.first + di[k];
			next_j = cur.second.second + dj[k];
			if (next_i < 1 || next_j < 1 || next_i > n || next_j > m)
				continue;


			if (board[next_i][next_j] != '*') {
				switch (status[next_i][next_j][k]) {
				case 0:
					status[next_i][next_j][k] = 1;
				case 1:
					if (cur.first.second == k) 
						pq.push({ {cur.first.first, k}, {next_i,next_j } });
					else if (cur.first.second % 2 != k % 2) {
						pq.push({ {cur.first.first + 1, k}, {next_i,next_j} });
					}
				}
			}
		}
	}
	return 0;
}