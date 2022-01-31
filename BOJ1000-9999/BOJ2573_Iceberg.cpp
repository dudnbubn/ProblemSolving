#include <iostream>
#include <queue>
#include <set>
using namespace std;

int n, m;
int board[301][301];
bool visited[301][301];
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };
set<pair<int, int>> s;
set<pair<int, int>>::iterator iter;

void BFS(int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i, j });
	visited[i][j] = true;
	
	pair<int, int> cur;
	int next_i, next_j;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			next_i = cur.first + di[k];
			next_j = cur.second + dj[k];
			if (next_i < 1 || next_j < 1 || next_i > n || next_j > m)
				continue;
			
			if (board[next_i][next_j] && !visited[next_i][next_j]) {
				visited[next_i][next_j] = true;
				q.push({ next_i, next_j });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	queue<pair<int, int>> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
			if (board[i][j])
				q.push({ i, j });
		}
	}
	
	int result = 0;
	int year = 0, cnt, qsz;
	pair<int, int> cur;
	int next_i, next_j;
	while (!q.empty()) {
		s.clear();
		for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= m; j++) 
				visited[i][j] = false;

		result = 0;
		year++;
		qsz = q.size();
		for (int i = 0; i < qsz; i++) {
			cur = q.front();
			q.pop();
			cnt = 0;
			for (int k = 0; k < 4; k++) {
				next_i = cur.first + di[k];
				next_j = cur.second + dj[k];
				if (next_i < 1 || next_j < 1 || next_i > n || next_j > m)
					continue;
				if (board[next_i][next_j] == 0)	cnt++;
			}
			if (board[cur.first][cur.second] <= cnt) {
				s.insert(cur);
			}
			else {
				board[cur.first][cur.second] -= cnt;
				q.push(cur);
			}
		}
		for (iter = s.begin(); iter != s.end(); iter++) {
			board[iter->first][iter->second] = 0;
		}
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (board[i][j] && !visited[i][j]) {
					BFS(i, j);
					result++;
				}
			}
		}
		if (result > 1) {
			cout << year;
			return 0;
		}
	}
	cout << 0;
	return 0;
}