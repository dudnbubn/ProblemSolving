#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int board[201][201];
bool visited[201][201][31];
int monkey_i[4] = { -1, 0, 1, 0 };
int monkey_j[4] = { 0, 1, 0, -1 };
int horse_i[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int horse_j[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

typedef pair<pair<int, int>, int> info;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int K, w, h;
	cin >> K >> w >> h;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			cin >> board[i][j];
	
	queue<info> q;
	info cur;
	int next_i, next_j;
	q.push({ {1, 1}, 0 });
	for (int k = 0; k <= K; k++)	visited[1][1][k] = true;
	int move = -1, qsz;
	while (!q.empty()) {
		move++;
		qsz = q.size();
		for (int i = 0; i < qsz; i++) {
			cur = q.front();
			q.pop();
			if (cur.first.first == h && cur.first.second == w) {
				cout << move;
				return 0;
			}

			for (int k = 0; k < 4; k++) {
				next_i = cur.first.first + monkey_i[k];
				next_j = cur.first.second + monkey_j[k];
				if (next_i < 1 || next_j < 1 || next_i > h || next_j > w)
					continue;
				
				if (!visited[next_i][next_j][cur.second] && board[next_i][next_j] == 0) {
					visited[next_i][next_j][cur.second] = true;
					q.push({ {next_i, next_j}, cur.second });
				}
			}
			if (cur.second < K) {
				for (int k = 0; k < 8; k++) {
					next_i = cur.first.first + horse_i[k];
					next_j = cur.first.second + horse_j[k];
					if (next_i < 1 || next_j < 1 || next_i > h || next_j > w)
						continue;

					if (!visited[next_i][next_j][cur.second + 1] && board[next_i][next_j] == 0) {
						visited[next_i][next_j][cur.second + 1] = true;
						q.push({ {next_i, next_j}, cur.second + 1 });
					}
				}
			}
		}
	}
	cout << -1;
	return 0;
}