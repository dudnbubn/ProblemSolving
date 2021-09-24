#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
char grid[1001][1001];
bool visited[1001][1001] = { 0, };
int di[4] = { -1, 1, 0, 0 };
int dj[4] = { 0, 0, -1, 1 };

bool BFS(int cur_i, int cur_j) {
	queue<pair<int, int>> q;
	visited[cur_i][cur_j] = true;
	q.push({ cur_i,cur_j });
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		if (cur.first == n)	return true;
		int next_i, next_j;
		for (int k = 0; k < 4; k++) {
			next_i = cur.first + di[k];
			next_j = cur.second + dj[k];
			if (next_i < 1 || next_j < 1 || next_i > n || next_j > m)
				continue;
			if (grid[next_i][next_j] == '0' && !visited[next_i][next_j]) {
				visited[next_i][next_j] = true;
				q.push({ next_i, next_j });
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> grid[i][j];

	bool flag = false;
	for (int i = 1; i <= m; i++) {
		if (grid[1][i] == '0' && !visited[1][i]) {
			flag = (flag || BFS(1, i));
		}
	}
	if (flag)	cout << "YES";
	else	cout << "NO";
	return 0;
}