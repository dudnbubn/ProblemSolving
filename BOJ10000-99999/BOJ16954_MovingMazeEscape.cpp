#include <iostream>
#include <queue>

using namespace std;

char board[10][10];
bool visited[10][10];
int di[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dj[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 8; i >= 1; i--)
		for (int j = 1; j <= 8; j++) 
			cin >> board[i][j];
	
	queue<pair<int, int>> q;
	q.push({ 1,1 });
	pair<int, int> cur;
	int next_i, next_j, qsz;
	while (!q.empty()) {
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8; j++)
				visited[i][j] = false;

		qsz = q.size();
		for (int i = 0; i < qsz; i++) {
			cur = q.front();
			q.pop();
			if (cur.first == 8 && cur.second == 8) {
				cout << 1;
				return 0;
			}
			if (board[cur.first][cur.second] == '#') 
				continue;
			q.push(cur);
			visited[cur.first][cur.second] = true;
			for (int k = 0; k < 8; k++) {
				next_i = cur.first + di[k];
				next_j = cur.second + dj[k];
				if (next_i < 1 || next_j < 1 || next_i > 8 || next_j > 8)
					continue;
				if (!visited[next_i][next_j] && board[next_i][next_j] != '#') {
					visited[next_i][next_j] = true;
					q.push({ next_i, next_j });
				}
			}
		}
		for (int i = 1; i <= 8; i++) {
			for (int j = 1; j <= 8; j++) {
				if (board[i][j] == '#') {
					board[i][j] = '.';
					board[i - 1][j] = '#';
				}
			}
		}
	}
	cout << 0;
	return 0;
}