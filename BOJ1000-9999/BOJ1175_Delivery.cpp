#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
char board[50][50];
bool visited[50][50][4][4];

int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };

typedef pair<pair<int, int>, pair<int, int>> Info;	// 좌표, 방향, 비트

queue<Info> q;

int BFS(int si, int sj) {
	q.push({ {si, sj}, {-1, 0} });
	Info cur;
	int ci, cj, cd, bit, ni, nj, qsz, level = -1;
	while (!q.empty()) {
		level++;
		qsz = q.size();
		for (int sz = 0; sz < qsz; sz++) {
			cur = q.front();
			q.pop();

			ci = cur.first.first;
			cj = cur.first.second;
			cd = cur.second.first;
			bit = cur.second.second;

			if (bit == 3)
				return level;

			for (int d = 0; d < 4; d++) {
				if (d == cd)	continue;
				ni = ci + di[d];
				nj = cj + dj[d];

				if (ni < 0 || nj < 0 || ni >= N || nj >= M)
					continue;
				if (visited[ni][nj][d][bit] || board[ni][nj] == '#')
					continue;

				visited[ni][nj][d][bit] = true;
				if (board[ni][nj] == 'A' || board[ni][nj] == 'B')
					q.push({ {ni, nj}, {d, bit | (1 << (board[ni][nj] - 'A'))} });
				else
					q.push({ {ni, nj}, {d, bit} });
			}
		}
	}
	return -1;
}

int main() {
	cin >> N >> M;

	int si, sj;
	bool flag = true;
	string input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = 0; j < M; j++) {
			board[i][j] = input[j];
			if (board[i][j] == 'S') {
				si = i;
				sj = j;
			}
			else if (board[i][j] == 'C') {
				if (flag) {
					flag = false;
					board[i][j] = 'A';
				}
				else
					board[i][j] = 'B';
			}
		}
	}

	cout << BFS(si, sj);
	return 0;
}