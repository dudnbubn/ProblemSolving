#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int board[101][101];
bool visited[101][101][4];
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };

typedef pair<pair<int, int>, int> info;
queue<info> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> board[i][j];
	
	int s_i, s_j, s_d, e_i, e_j, e_d;
	cin >> s_i >> s_j >> s_d >> e_i >> e_j >> e_d;
	s_d %= 4;	e_d %= 4;
	if (s_d == 2)		s_d = 3;
	else if(s_d == 3)	s_d = 2;
	if (e_d == 2)		e_d = 3;
	else if(e_d == 3)	e_d = 2;

	info cur;
	int result = -1, qsz, next_i, next_j, next_dir;
	q.push({ {s_i, s_j},s_d });
	visited[s_i][s_j][s_d] = true;
	while (!q.empty()) {
		result++;
		qsz = q.size();
		for (int i = 0; i < qsz; i++) {
			cur = q.front();
			q.pop();
			if (cur == make_pair(make_pair(e_i, e_j), e_d)) {
				cout << result;
				return 0;
			}

			if (!visited[cur.first.first][cur.first.second][(cur.second + 1) % 4]) {
				visited[cur.first.first][cur.first.second][(cur.second + 1) % 4] = true;
				q.push({ cur.first, (cur.second + 1) % 4 });
			}
			if (!visited[cur.first.first][cur.first.second][(cur.second + 3) % 4]) {
				visited[cur.first.first][cur.first.second][(cur.second + 3) % 4] = true;
				q.push({ cur.first, (cur.second + 3) % 4 });
			}

			for (int k = 1; k <= 3; k++) {
				next_i = cur.first.first + k * di[cur.second];
				next_j = cur.first.second + k * dj[cur.second];

				if (next_i < 1 || next_j < 1 || next_i > n || next_j > m || board[next_i][next_j] == 1)
					break;

				if (!visited[next_i][next_j][cur.second]) {
					visited[next_i][next_j][cur.second] = true;
					q.push({ {next_i,next_j},cur.second });
				}
			}
		}
	}
	return 0;
}