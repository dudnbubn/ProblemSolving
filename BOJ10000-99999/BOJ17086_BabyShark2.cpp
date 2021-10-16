#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int board[51][51];
bool visited[51][51] = { 0, };
int di[8] = { -1,-1,-1,0,0,1,1,1 };
int dj[8] = { -1,0,1,-1,1,-1,0,1 };

void BFS(int i, int j) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			visited[i][j] = false;
	queue<pair<int, int>> q;
	q.push({ i,j });
	visited[i][j] = true;
	int move = 0;
	while (!q.empty()) {
		move++;
		int qsz = q.size();
		int cur_i, cur_j, next_i, next_j;
		for (int i = 0; i < qsz; i++) {
			cur_i = q.front().first;
			cur_j = q.front().second;
			q.pop();
			for (int k = 0; k < 8; k++) {
				next_i = cur_i + di[k];
				next_j = cur_j + dj[k];
				if (next_i < 1 || next_j < 1 || next_i > n || next_j > m)
					continue;
				if (board[next_i][next_j] >= 0 && !visited[next_i][next_j]) {
					visited[next_i][next_j] = true;
					board[next_i][next_j] = min(board[next_i][next_j], move);
					q.push({ next_i,next_j });
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	vector<pair<int, int>> sharks;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
			if (board[i][j])
				sharks.push_back({ i,j });
			if (board[i][j])	board[i][j] = -1;
			else	board[i][j] = 1000;
		}
	}
	for (int i = 0; i < sharks.size(); i++)
		BFS(sharks[i].first, sharks[i].second);
	int result = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			result = max(result, board[i][j]);
	cout << result;
	return 0;
}