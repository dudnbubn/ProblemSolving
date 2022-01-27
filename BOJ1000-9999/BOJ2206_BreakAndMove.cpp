#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
char board[1001][1001];
bool visited[1001][1001][2];
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };
queue<pair<pair<int, int>, int>> q;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> board[i][j];

	q.push({ {1,1},0 });
	visited[1][1][0] = true;
	pair<pair<int, int>, int > cur;
	int next_i, next_j, qsz;
	int result = 0;
	while (!q.empty()) {
		result++;
		qsz = q.size();
		for (int i = 0; i < qsz; i++) {
			cur = q.front();
			q.pop();
			if ((cur.first.first == n) && (cur.first.second == m)) {
				cout << result;
				return 0;
			}
			for (int k = 0; k < 4; k++) {
				next_i = cur.first.first + di[k];
				next_j = cur.first.second + dj[k];
				if (next_i < 1 || next_j < 1 || next_i > n || next_j > m)
					continue;
				if (!visited[next_i][next_j][cur.second]) {
					visited[next_i][next_j][cur.second] = true;
					if (board[next_i][next_j] == '0') {
						q.push({ {next_i, next_j}, cur.second });
					}
					else {
						if (cur.second == 0) {
							q.push({ {next_i, next_j}, 1 });
						}
					}
				}
			}
		}
	}
	cout << -1;
	return 0;
}