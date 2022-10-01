#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
char board[50][50];
bool visited[50][50][1 << 5];
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };

typedef pair<pair<int, int>, int> Position;
queue<Position> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> M >> N;
	string input;
	int cnt = 0;
	int ci = 0, cj = 0;
	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = 0; j < M; j++) {
			board[i][j] = input[j];
			if (board[i][j] == 'S') {
				ci = i;
				cj = j;
			}
			else if (board[i][j] == 'X') {
				board[i][j] = (char)(cnt + '0');
				cnt++;
			}
		}
	}

	q.push({ { ci, cj }, 0 });
	visited[ci][cj][0] = true;

	Position cur;
	int ni, nj, k, level = -1, qsz;
	bool flag = false;
	char last = (char)(cnt + '0');
	while (!q.empty()) {
		level++;
		qsz = q.size();
		for (int sz = 0; sz < qsz; sz++) {
			cur = q.front();
			q.pop();
			ci = cur.first.first;
			cj = cur.first.second;
			k = cur.second;


			if (board[ci][cj] == 'E') {
				if (k == (1 << cnt) - 1) {
					flag = true;
					break;
				}
				continue;
			}

			for (int d = 0; d < 4; d++) {
				ni = ci + di[d];
				nj = cj + dj[d];

				if (board[ni][nj] == '#' || visited[ni][nj][k])	continue;


				if ('0' <= board[ni][nj] && board[ni][nj] <= last) {
					visited[ni][nj][k | (1 << board[ni][nj] - '0')] = true;
					q.push({ {ni, nj}, k | (1 << board[ni][nj] - '0') });
				}
				else {
					visited[ni][nj][k] = true;
					q.push({ {ni, nj}, k });
				}
			}
		}
		if (flag) break;
	}
	cout << level;
	
	return 0;
}