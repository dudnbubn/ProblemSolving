#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int maze[101][101];
int visited[101][101];
int di[4] = { 0, -1, 0, 1 };
int dj[4] = { -1, 0, 1, 0 };

int main() {
	cin >> n >> m;
	queue<pair<int, int>> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char temp;
			cin >> temp;
			maze[i][j] = temp - '0';
		}
	}
	q.push({ 1,1 });
	int dist = 0;
	visited[1][1] = true;
	while (!q.empty()) {
		int qsz = q.size();
		dist++;
		for (int i = 0; i < qsz; i++) {
			pair<int, int> cur = q.front();
			q.pop();
			for (int k = 0; k < 4; k++) {
				int temp_i = cur.first + di[k];
				int temp_j = cur.second + dj[k];
				if (temp_i < 1 || temp_i > n || temp_j < 1 || temp_j > m)
					continue;
				if (maze[temp_i][temp_j] && !visited[temp_i][temp_j]) {
					visited[temp_i][temp_j] = true;
					q.push({ temp_i, temp_j });
				}
				if (temp_i == n && temp_j == m) {
					cout << dist + 1;
					return 0;
				}
			}
		}
	}
	return 0;
}