#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

queue<pair<int, int>> q;

int N, M;
int board[1000][1000];
bool is_visited[1000][1000];
int distances[1000][1000];

int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			cin >> board[n][m];
			if (board[n][m] == 2) {
				is_visited[n][m] = true;
				q.push({ n, m });
			}

			distances[n][m] = -1;
		}
	}

	int dist = -1, qsz;
	pair<int, int> current;

	int ci, cj, ni, nj;
	while (!q.empty()) {
		dist++;
		qsz = q.size();
		while (qsz--) {
			current = q.front();
			q.pop();

			ci = current.first;
			cj = current.second;
			distances[ci][cj] = dist;
			
			for (int d = 0; d < 4; d++) {
				ni = ci + di[d];
				nj = cj + dj[d];
				if (ni < 0 || ni >= N || nj < 0 || nj >= M || !board[ni][nj] || is_visited[ni][nj])
					continue;
				
				is_visited[ni][nj] = true;
				q.push({ ni, nj });
			}
		}
	}

	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			cout << (board[n][m] ? distances[n][m] : 0) << " ";
		}
		cout << "\n";
	}
}