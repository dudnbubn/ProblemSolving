#include <iostream>
#include <queue>
using namespace std;

int n;
char grid[101][101];
int visited[101][101];
int di[4] = { -1,1,0,0 };
int dj[4] = { 0,0,-1,1 };

void BFS(int i, int j, char alp, int cnt) {
	queue<pair<int, int>> q;
	q.push({ i,j });
	int cur_i, cur_j, next_i, next_j;
	while (!q.empty()) {
		cur_i = q.front().first;
		cur_j = q.front().second;
		q.pop();
		visited[cur_i][cur_j] = cnt;
		for (int k = 0; k < 4; k++) {
			next_i = cur_i + di[k];
			next_j = cur_j + dj[k];
			if (next_i < 1 || next_j < 1 || next_i > n || next_j > n)
				continue;
			if (visited[next_i][next_j] == 0 && grid[next_i][next_j] == alp) {
				visited[next_i][next_j] = cnt;
				q.push({ next_i,next_j });
			}
		}
	}
}

void BlinedBFS(int i, int j, char alp, int cnt) {
	queue<pair<int, int>> q;
	q.push({ i,j });
	int cur_i, cur_j, next_i, next_j;
	while (!q.empty()) {
		cur_i = q.front().first;
		cur_j = q.front().second;
		q.pop();
		visited[cur_i][cur_j] = cnt;
		for (int k = 0; k < 4; k++) {
			next_i = cur_i + di[k];
			next_j = cur_j + dj[k];
			if (next_i < 1 || next_j < 1 || next_i > n || next_j > n)
				continue;
			if (visited[next_i][next_j] == 0) {
				if (alp == 'B' && grid[next_i][next_j] == 'B') {
					visited[next_i][next_j] = cnt;
					q.push({ next_i,next_j });
				}
				else if ((alp == 'R' || alp == 'G') && (grid[next_i][next_j] == 'R' || grid[next_i][next_j] == 'G')) {
					visited[next_i][next_j] = cnt;
					q.push({ next_i,next_j });
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> grid[i][j];
			visited[i][j] = 0;
		}
	}
	int cnt = 1, blined_cnt = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (visited[i][j] == 0) {
				BFS(i, j, grid[i][j], cnt);
				cnt++;
			}
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			visited[i][j] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (visited[i][j] == 0) {
				BlinedBFS(i, j, grid[i][j], blined_cnt);
				blined_cnt++;
			}
		}
	}
	cout << cnt - 1 << " " << blined_cnt - 1;
	return 0;
}