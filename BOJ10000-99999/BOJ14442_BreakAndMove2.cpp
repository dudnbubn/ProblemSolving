#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, K;
char board[1001][1001];
bool visited[11][1001][1001];
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };

typedef pair<pair<int, int>, pair<int, int>> info;
queue<info> q;

int Dijkstra() {
	info cur;
	int next_i, next_j;

	q.push({ {1, 0}, {1, 1} });
	visited[0][1][1] = true;
	while (!q.empty()) {
		cur = q.front();
		q.pop();

		if (cur.second.first == N && cur.second.second == M) {
			return cur.first.first;
		}
		for (int k = 0; k < 4; k++) {
			next_i = cur.second.first + di[k];
			next_j = cur.second.second + dj[k];
			if (next_i < 1 || next_j < 1 || next_i > N || next_j > M)
				continue;

			if (board[next_i][next_j] == '1') {
				if (cur.first.second < K && !visited[cur.first.second + 1][next_i][next_j]) {
					visited[cur.first.second + 1][next_i][next_j] = true;
					q.push({ {cur.first.first + 1, cur.first.second + 1}, { next_i, next_j} });
				}
			}
			else {
				if (!visited[cur.first.second][next_i][next_j]) {
					visited[cur.first.second][next_i][next_j] = true;
					q.push({ {cur.first.first + 1, cur.first.second}, { next_i, next_j} });
				}
			}
		}
	}
	return -1;
}

int main() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> board[i][j];

	cout << Dijkstra();
	return 0;
}