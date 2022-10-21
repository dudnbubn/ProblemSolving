#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int H, W, dirty;
char board[20][20];
bool visited[20][20];
bool pqvisited[20][20][1 << 10];
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };

int BFS(int ci, int cj) {
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			visited[i][j] = false;

	int result = 0;
	queue<pair<int, int>> q;

	q.push({ ci, cj });
	visited[ci][cj] = true;
	pair<int, int> cur;
	int ni, nj;
	while (!q.empty()) {
		cur = q.front();
		q.pop();

		ci = cur.first;
		cj = cur.second;
		if ('0' <= board[ci][cj] && board[ci][cj] <= '9')	result++;

		for (int d = 0; d < 4; d++) {
			ni = ci + di[d];
			nj = cj + dj[d];
			if (ni < 0 || nj < 0 || ni >= H || nj >= W || visited[ni][nj] || board[ni][nj] == 'x')
				continue;

			visited[ni][nj] = true;
			q.push({ ni, nj });
		}
	}
	return result;
}

typedef pair<pair<int, int>, pair<int, int>> Info;

struct compare {
	bool operator()(Info a, Info b) {
		if (a.first.first == b.first.first)
			return a.first.second < b.first.second;
		return a.first.first > b.first.first;
	}
};
priority_queue<Info, vector<Info>, compare> pq;
int cleanning(int ci, int cj) {
	pq = {};
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			for (int k = 0; k < (1 << 10); k++)
				pqvisited[i][j][k] = false;

	pq.push({ {0, 0}, {ci, cj} });
	pqvisited[ci][cj][0] = true;

	Info cur;
	int ni, nj, move, bit;
	while (!pq.empty()) {
		cur = pq.top();
		pq.pop();

		move = cur.first.first;
		bit = cur.first.second;
		ci = cur.second.first;
		cj = cur.second.second;

		if (bit == (1 << dirty) - 1) {
			return move;
		}

		for (int d = 0; d < 4; d++) {
			ni = ci + di[d];
			nj = cj + dj[d];
			if (ni < 0 || nj < 0 || ni >= H || nj >= W || pqvisited[ni][nj][bit] || board[ni][nj] == 'x')
				continue;

			if ('0' <= board[ni][nj] && board[ni][nj] <= '9') {
				pqvisited[ni][nj][bit | (1 << board[ni][nj] - '0')] = true;
				pq.push({ {move + 1, bit | (1 << board[ni][nj] - '0')}, {ni, nj} });
			}
			else {
				pqvisited[ni][nj][bit] = true;
				pq.push({ {move + 1, bit},{ni, nj} });
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> W >> H;
	while (W != 0) {
		dirty = 0;
		int ci = 0, cj = 0;
		int index = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> board[i][j];
				if (board[i][j] == '*') {
					board[i][j] = (char)(index + '0');
					dirty++;
					index++;
				}
				else if (board[i][j] == 'o') {
					ci = i;
					cj = j;
				}
			}
		}


		if (BFS(ci, cj) < dirty)	cout << -1 << "\n";
		else	cout << cleanning(ci, cj) << "\n";

		cin >> W >> H;
	}
	return 0;
}