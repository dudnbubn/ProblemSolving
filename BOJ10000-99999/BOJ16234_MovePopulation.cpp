#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int n, l, r;
int board[51][51];
bool visited[51][51];
int di[4] = { -1,1,0,0 };
int dj[4] = { 0,0,-1,1 };
queue<pair<int, int>> save;

bool BFS(int i, int j) {
	while (!save.empty())	save.pop();
	queue<pair<int, int>> q;
	int sum = board[i][j];
	int cnt = 1;
	q.push({ i, j });
	save.push({ i, j });
	visited[i][j] = true;
	int cur_i, cur_j, next_i, next_j;
	while (!q.empty()) {
		cur_i = q.front().first;
		cur_j = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			next_i = cur_i + di[k];
			next_j = cur_j + dj[k];
			if (next_i < 1 || next_j < 1 || next_i > n || next_j > n || visited[next_i][next_j])
				continue;
			int gap = abs(board[cur_i][cur_j] - board[next_i][next_j]);
			if (l <= gap && gap <= r) {
				visited[next_i][next_j] = true;
				sum += board[next_i][next_j];
				cnt++;
				q.push({ next_i, next_j });
				save.push({ next_i,next_j });
			}
		}
	}
	if (cnt == 1)	return false;
	else {
		int update = sum / cnt;
		while (!save.empty()) {
			cur_i = save.front().first;
			cur_j = save.front().second;
			save.pop();
			board[cur_i][cur_j] = update;
		}
		return true;
	}
}
int main() {
	cin >> n >> l >> r;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cin >> board[i][j];
	}
	int result = -1;
	bool flag = true;
	while (flag) {
		result++;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				visited[i][j] = false;
		flag = false;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (!visited[i][j]) {
					flag |= BFS(i, j);
				}
			}
		}
	}
	cout << result;
	return 0;
}