#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int board[101][101];
int dist[101][101];
bool visited[101][101];
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0 ,1, 0, -1 };

queue<pair<int, int>> q;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> board[i][j];

	int index = 0;
	pair<int, int> cur;
	int next_i, next_j;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visited[i][j] && board[i][j]) {
				index++;

				q.push({ i, j });
				visited[i][j] = true;

				while (!q.empty()) {
					cur = q.front();
					q.pop();
					board[cur.first][cur.second] = index;

					for (int k = 0; k < 4; k++) {
						next_i = cur.first + di[k];
						next_j = cur.second + dj[k];
						if (next_i < 1 || next_j < 1 || next_i > N || next_j > N)
							continue;

						if (!visited[next_i][next_j] && board[next_i][next_j]) {
							visited[next_i][next_j] = true;
							q.push({ next_i, next_j });
						}
					}
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			visited[i][j] = false;
			if (board[i][j]) {
				visited[i][j] = true;
				bool flag = false;
				for (int k = 0; k < 4; k++) {
					next_i = i + di[k];
					next_j = j + dj[k];

					if (next_i < 1 || next_j < 1 || next_i > N || next_j > N)
						continue;

					if (board[next_i][next_j] == 0) {
						flag = true;
						break;
					}
				}
				if (flag)
					q.push({ i,j });
			}
		}
	}

	int result = 987654321;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			next_i = cur.first + di[k];
			next_j = cur.second + dj[k];

			if (next_i < 1 || next_j < 1 || next_i > N || next_j > N)
				continue;

			if (!visited[next_i][next_j]) {
				visited[next_i][next_j] = true;
				board[next_i][next_j] = board[cur.first][cur.second];
				dist[next_i][next_j] = dist[cur.first][cur.second] + 1;
				q.push({ next_i, next_j });
			}
			else {
				if (board[next_i][next_j] != board[cur.first][cur.second]) {
					result = min(result, dist[cur.first][cur.second] + dist[next_i][next_j]);
				}
			}
		}
	}
	cout << result;
	return 0;
}