#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, t;
int board[101][101];
bool visited[101][101] = { 0, };
int di[4] = { -1,1,0,0 };
int dj[4] = { 0,0,-1,1 };

queue<pair<int, int>> q;

int main() {
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++)
			cin >> board[i][j];
	q.push({ 1,1 });
	visited[1][1] = true;
	int minimum = 987654321;
	int arrive = -1;
	int qsz, cur_i, cur_j, next_i, next_j;
	while (!q.empty() && arrive < t) {
		arrive++;
		qsz = q.size();
		for (int i = 0; i < qsz; i++) {
			cur_i = q.front().first;
			cur_j = q.front().second;
			if ((cur_i == n) && (cur_j == m)) {
				minimum = min(minimum, arrive);
				if (minimum <= t)
					cout << minimum;
				else
					cout << "Fail";
				return 0;
			}
			if (board[cur_i][cur_j] == 2) {
				minimum = min(minimum, arrive + ((n - cur_i) + (m - cur_j)));
			}
			q.pop();
			for (int k = 0; k < 4; k++) {
				next_i = cur_i + di[k];
				next_j = cur_j + dj[k];
				if (next_i < 1 || next_j < 1 || next_i > n || next_j > m)
					continue;
				if (!visited[next_i][next_j] && (board[next_i][next_j] != 1)) {
					visited[next_i][next_j] = true;
					q.push({ next_i,next_j });
				}
			}
		}
	}
	if (minimum == 987654321 || minimum > t)
		cout << "Fail";
	else 
		cout << minimum;

	return 0;
}