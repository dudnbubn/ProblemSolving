#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, h;
int di[6] = { -1,0,1,0,0,0 };
int dj[6] = { 0,1,0,-1,0,0 };
int dk[6] = { 0,0,0,0,-1,1 };
int board[101][101][101];
bool visited[101][101][101] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<pair<pair<int, int>, int>> q;
	cin >> m >> n >> h;
	for (int k = 1; k <= h; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> board[i][j][k];
				if (board[i][j][k] == 1) {
					q.push({ {i,j},k });
					visited[i][j][k] = true;
				}
			}
		}
	}
	int result = -1;
	pair<pair<int, int>, int> cur;
	int qsz, next_i, next_j, next_k;
	while (!q.empty()) {
		result++;
		qsz = q.size();
		for (int a = 0; a < qsz; a++) {
			cur = q.front();
			q.pop();
			for (int b = 0; b < 6; b++) {
				next_i = cur.first.first + di[b];
				next_j = cur.first.second + dj[b];
				next_k = cur.second + dk[b];
				if (visited[next_i][next_j][next_k] || next_i < 1 || next_j < 1 || next_k < 1 || next_i > n || next_j > m || next_k > h)
					continue;
				if (board[next_i][next_j][next_k] == 0) {
					board[next_i][next_j][next_k] = 1;
					visited[next_i][next_j][next_k] = true;
					q.push({ {next_i,next_j}, next_k });
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 1; k <= h; k++) {
				if (board[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
			}
		}
	}
	cout << result;
	return 0;
}