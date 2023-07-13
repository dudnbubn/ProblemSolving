#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_N 600
#define MAX_M 600

int N, M;
char board[MAX_N][MAX_M];

queue<pair<int, int>> q;
bool is_visited[MAX_N][MAX_M];

int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };

bool in_board(int ni, int nj) {
	if (ni < 0 || nj < 0 || ni >= N || nj >= M)	return false;
	return true;
}

int BFS(pair<int, int> start) {
	int result = 0;

	int ci, cj;
	ci = start.first;
	cj = start.second;

	q.push(start);
	is_visited[ci][cj] = true;

	pair<int, int> current;
	int ni, nj;
	while (!q.empty()) {
		current = q.front();
		q.pop();

		ci = current.first;
		cj = current.second;

		for (int d = 0; d < 4; d++) {
			ni = ci + di[d];
			nj = cj + dj[d];

			if (!in_board(ni, nj) || is_visited[ni][nj] || board[ni][nj] == 'X')	continue;

			is_visited[ni][nj] = true;
			if (board[ni][nj] == 'P')	result++;
			q.push({ ni ,nj });
		}
	}
	return result;
}

int main() {
	cin >> N >> M;

	pair<int, int> start;
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			cin >> board[n][m];
			if (board[n][m] == 'I') {
				start = { n, m };
			}
		}
	}

	int result = BFS(start);
	if (result)	cout << result;
	else	cout << "TT";

	return 0;
}