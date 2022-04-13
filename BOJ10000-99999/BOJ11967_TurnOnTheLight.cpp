#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int board[101][101];
bool visited[101][101];
bool temp_visited[101][101];
bool on[101][101];
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };
vector<pair<int, int>> v[101][101];
queue<pair<int, int>> q;
bool flag = true;

void BFS() {
	int x, y, a, b;

	flag = false;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			temp_visited[i][j] = false;

	q.push({ 1,1 });
	temp_visited[1][1] = true;
	pair<int, int> cur;
	int next_i, next_j;
	while (!q.empty()) {
		cur = q.front();
		q.pop();

		x = cur.first;	y = cur.second;

		for (int k = 0; k < 4; k++) {
			next_i = x + di[k];
			next_j = y + dj[k];
			if (next_i < 1 || next_j < 1 || next_i > n || next_j > n)
				continue;
			if (!temp_visited[next_i][next_j] && on[next_i][next_j]) {
				temp_visited[next_i][next_j] = true;
				q.push({ next_i, next_j });
				if (!visited[next_i][next_j]) {
					visited[next_i][next_j] = true;
					for (int i = 0; i < v[next_i][next_j].size(); i++) {
						if (!on[v[next_i][next_j][i].first][v[next_i][next_j][i].second]) {
							on[v[next_i][next_j][i].first][v[next_i][next_j][i].second] = true;
							flag = true;
						}
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	int x, y, a, b;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> a >> b;
		v[x][y].push_back({ a,b });
	}
	visited[1][1] = true;	on[1][1] = true;
	for (int i = 0; i < v[1][1].size(); i++) 
		on[v[1][1][i].first][v[1][1][i].second] = true;

	
	while (flag)
		BFS();
	
	int result = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (on[i][j])
				result++;
	cout << result;

	return 0;
}