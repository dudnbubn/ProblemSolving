// priority_queue 를 이용한 BFS

#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, pair<int, int>> vxy;

int n, k;
int board[201][201] = { 0, };
int di[4] = { 0,0,-1,1 };
int dj[4] = { -1,1,0,0 };
priority_queue<vxy, vector<vxy>, greater<vxy>> pq;
queue<vxy> q;

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
			if (board[i][j])
				pq.push({ board[i][j], {i, j} });
		}
	}
	int s, x, y;
	cin >> s >> x >> y;
	while (s--) {
		int qsz = pq.size();
		for (int i = 0; i < qsz; i++) {
			q.push(pq.top());
			pq.pop();
		}
		while (!q.empty()) {
			vxy cur = q.front();
			q.pop();
			int next_i, next_j;
			for (int k = 0; k < 4; k++) {
				next_i = cur.second.first + di[k];
				next_j = cur.second.second + dj[k];
				if (next_i < 1 || next_j < 1 || next_i > n || next_j > n)
					continue;
				if (board[next_i][next_j] == 0) {
					board[next_i][next_j] = cur.first;
					pq.push({ cur.first, {next_i, next_j} });
				}
			}
		}
	}
	cout << board[x][y];
	return 0;
}