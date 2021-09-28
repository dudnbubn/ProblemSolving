#include <iostream>
#include <queue>
using namespace std;

int n, m;
int board[501][501];
bool visited[501][501] = { 0, };
int di[4] = { -1,1,0,0 };
int dj[4] = { 0,0,-1,1 };

int BFS(int i, int j) {
	int result = 0;
	queue<pair<int, int>> q;
	visited[i][j] = true;
	q.push({ i,j });
	int cur_i, cur_j, next_i, next_j;
	while (!q.empty()) {
		result++;
		cur_i = q.front().first;
		cur_j = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			next_i = cur_i + di[k];
			next_j = cur_j + dj[k];
			if (next_i < 1 || next_j < 1 || next_i > n || next_j > m)
				continue;
			if (board[next_i][next_j] == 1 && !visited[next_i][next_j]) {
				visited[next_i][next_j] = true;
				q.push({ next_i,next_j });
			}
		}
	}
	return result;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> board[i][j];

	int maximum = 0, cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j] == 1 && !visited[i][j]) {
				cnt++;
				maximum = max(maximum, BFS(i, j));
			}
		}
	}
	cout << cnt << "\n" << maximum;
	return 0;
}