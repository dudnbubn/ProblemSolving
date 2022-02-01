#include <iostream>
#include <queue>
using namespace std;

int n, m;
char board[1001][1001];
bool visited[1001][1001];
bool burnt[1001][1001];
queue<pair<int, int>> fire;
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };


int BFS(int i, int j) {
	int result = 0;
	queue<pair<int, int>> q;
	q.push({ i, j });

	pair<int, int> cur;
	int next_i, next_j, qsz, fsz;
	while (!q.empty()) {
		result++;
		fsz = fire.size();
		for (int i = 0; i < fsz; i++) {
			cur = fire.front();
			fire.pop();
			for (int k = 0; k < 4; k++) {
				next_i = cur.first + di[k];
				next_j = cur.second + dj[k];
				if (next_i < 1 || next_j < 1 || next_i > n || next_j > m)
					continue;
				if (!burnt[next_i][next_j] && (board[next_i][next_j] == '.' || board[next_i][next_j] == '@')) {
					burnt[next_i][next_j] = true;
					board[next_i][next_j] = '*';
					fire.push({ next_i, next_j });
				}
			}
		}

		qsz = q.size();
		for (int i = 0; i < qsz; i++) {
			cur = q.front();
			q.pop();
	
			if (cur.first == 1 || cur.first == n || cur.second == 1 || cur.second == m)
				return result;

			for (int k = 0; k < 4; k++) {
				next_i = cur.first + di[k];
				next_j = cur.second + dj[k];
				if (next_i < 1 || next_j < 1 || next_i > n || next_j > m)
					continue;

				if (!visited[next_i][next_j] && board[next_i][next_j] == '.') {
					visited[next_i][next_j] = true;
					q.push({ next_i, next_j });
				}
			}
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		cin >> m >> n;
		while (!fire.empty())	fire.pop();

		int start_i = 0, start_j = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> board[i][j];
				visited[i][j] = false;
				burnt[i][j] = false;
				if (board[i][j] == '@') {
					start_i = i;
					start_j = j;
				}
				else if (board[i][j] == '*')
					fire.push({ i, j });
			}
		}
		int result = BFS(start_i, start_j);
		if (result > 0)	cout << result << "\n";
		else	cout << "IMPOSSIBLE\n";
	}
	return 0;
}