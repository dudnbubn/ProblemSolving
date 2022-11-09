#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<pair<int, int>, pair<int, int>> Info;	// <<g통과, g인접>, <좌표>>

int N, M;
char board[50][50];
bool visited[50][50];
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0 ,-1 };
priority_queue<Info, vector<Info>, greater<Info>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> board[i];
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 'S') {
				pq.push({ {0, 0},{i, j} });
				visited[i][j] = true;
			}
		}
	}
	
	Info cur;
	int thr, adj, ci, cj;
	int ni, nj;
	while (!pq.empty()) {
		cur = pq.top();
		pq.pop();

		thr = cur.first.first;
		adj = cur.first.second;
		ci = cur.second.first;
		cj = cur.second.second;

		if (board[ci][cj] == 'F') {
			cout << thr << " " << adj;
			return 0;
		}

		for (int d = 0; d < 4; d++) {
			ni = ci + di[d];
			nj = cj + dj[d];

			if (ni < 0 || nj < 0 || ni >= N || nj >= M || visited[ni][nj])
				continue;

			visited[ni][nj] = true;
			if (board[ni][nj] == 'g')
				pq.push({ {thr + 1, adj},{ni, nj} });
			else {
				bool flag = true;
				for (int a = 0; a < 4; a++) {
					if (board[ni + di[a]][nj + dj[a]] == 'g')
						flag = false;
				}
				if (board[ni][nj] =='F' || flag)	pq.push({{thr, adj},{ni, nj}});
				else	pq.push({ {thr, adj + 1}, {ni, nj} });
			}
		}
	}

	
}