#include <iostream>
#include <queue>
using namespace std;

char board[1001][1001];
bool visited[1001][1001];
queue<pair<int, int>> q;
queue<pair<int, int>> fire;
int di[4] = { -1, 0, 1 ,0 };
int dj[4] = { 0, 1, 0, -1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int r, c;
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'J') {
				q.push({ i, j });
				visited[i][j] = true;
			}
			else if (board[i][j] == 'F') {
				fire.push({ i, j });
			}
		}
	}
	int result = 0;
	pair<int, int> cur;
	int next_i, next_j, qsz, fsz;

	while (!q.empty()) {
		result++;
		qsz = q.size();
		for (int i = 0; i < qsz; i++) {
			cur = q.front();
			q.pop();
			if (board[cur.first][cur.second] == 'F')	continue;
	
			for (int k = 0; k < 4; k++) {
				next_i = cur.first + di[k];
				next_j = cur.second + dj[k];
				if (next_i < 1 || next_j < 1 || next_i > r || next_j > c) {
					cout << result;
					return 0;
				}
				if (!visited[next_i][next_j] && board[next_i][next_j] == '.') {
					visited[next_i][next_j] = true;
					q.push({ next_i, next_j });
				}
			}
		}
		fsz = fire.size();
		for (int i = 0; i < fsz; i++) {
			cur = fire.front();
			fire.pop();
			for (int k = 0; k < 4; k++) {
				next_i = cur.first + di[k];
				next_j = cur.second + dj[k];
				if (next_i < 1 || next_j < 1 || next_i > r || next_j > c)
					continue;
				if (board[next_i][next_j] == '.' || board[next_i][next_j] == 'J') {
					board[next_i][next_j] = 'F';
					fire.push({ next_i, next_j });
				}
			}
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}