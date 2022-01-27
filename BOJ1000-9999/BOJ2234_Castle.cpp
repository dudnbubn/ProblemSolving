#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int board[51][51];
bool visited[51][51];
int di[4] = { 0, -1, 0, 1 };
int dj[4] = { -1, 0, 1, 0 };
int area[51][51];
int sz[2501];
int answer1 = 0, answer2 = 0, answer3 = 0;

void BFS(int index, int i, int j) {
	answer1++;
	int result = 0;
	queue<pair<int, int>> q;
	q.push({ i, j });
	visited[i][j] = true;
	pair<int, int> cur;
	int next_i, next_j;
	int bit;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		result++;
		area[cur.first][cur.second] = index;
		bit = 1;
		for (int k = 0; k < 4; k++) {
			if ((board[cur.first][cur.second] & bit) == 0) {
				next_i = cur.first + di[k];
				next_j = cur.second + dj[k];
				if (!visited[next_i][next_j]) {
					visited[next_i][next_j] = true;
					q.push({ next_i, next_j });
				}
			}	
			bit *= 2;
		}
	}
	sz[index] = result;
	answer2 = max(answer2, result);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}
	}
	int index = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!visited[i][j]) {
				BFS(index++, i, j);
			}
		}
	}
	int next_i, next_j;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 0; k < 4; k++) {
				next_i = i + di[k];
				next_j = j + dj[k];
				if (next_i < 1 || next_j < 1 || next_i > n || next_j > m)
					continue;

				if (area[i][j] != area[next_i][next_j]) {
					answer3 = max(answer3, sz[area[i][j]] + sz[area[next_i][next_j]]);
				}
			}
		}
	}
	cout << answer1 << "\n" << answer2 << "\n" << answer3;
	return 0;
}