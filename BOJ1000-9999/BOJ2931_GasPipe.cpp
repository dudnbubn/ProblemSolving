#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

int R, C;
char board[26][26];
bool visited[26][26];
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };
vector<vector<int>> roads;
queue<pair<int, int>> q;
unordered_map<char, int> um;

bool is_linked(int r1, int c1, int r2, int c2) {
	bool one2two = false, two2one = false;

	int b1 = um[board[r1][c1]], b2 = um[board[r2][c2]];
	int ni, nj;
	for (int d : roads[b1]) {
		ni = r1 + di[d];
		nj = c1 + dj[d];

		if (ni < 1 || nj < 1 || ni > R || nj > C)
			continue;

		if (ni == r2 && nj == c2)	one2two = true;
	}
	for (int d : roads[b2]) {
		ni = r2 + di[d];
		nj = c2 + dj[d];

		if (ni < 1 || nj < 1 || ni > R || nj > C)
			continue;

		if (ni == r1 && nj == c1)	two2one = true;
	}

	return one2two && two2one;
}

pair<int, int> get_position(int ci, int cj) {
	q.push({ ci, cj });
	visited[ci][cj] = true;

	pair<int, int> cur;
	int ni, nj;
	while (!q.empty()) {
		cur = q.front();
		q.pop();

		ci = cur.first;
		cj = cur.second;

		if (board[ci][cj] == '.')	return { ci, cj };

		int number = um[board[ci][cj]];
		for (int d : roads[number]) {
			ni = ci + di[d];
			nj = cj + dj[d];

			if (ni < 1 || nj < 1 || ni > R || nj > C || visited[ni][nj])
				continue;

			visited[ni][nj] = true;
			q.push({ ni, nj });
		}
	}
	return { 0, 0 };
}

int main() {
	cin >> R >> C;
	string line;
	int mi = 0, mj = 0;
	for (int i = 1; i <= R; i++) {
		cin >> line;
		for (int j = 1; j <= C; j++) {
			board[i][j] = line[j - 1];
			if (board[i][j] == 'M') {
				mi = i;
				mj = j;
			}
		}
	}

	roads = {
		{},
		{1, 2},
		{0, 1},
		{0, 3},
		{2, 3},
		{0, 2},
		{1, 3},
		{0, 1, 2, 3}
	};

	um['1'] = 1;	um['2'] = 2;	um['3'] = 3;	um['4'] = 4;
	um['|'] = 5;	um['-'] = 6;	um['+'] = 7;

	visited[mi][mj] = true;

	int ni, nj, ri, rj;

	for (int d = 0; d < 4; d++) {
		ni = mi + di[d];
		nj = mj + dj[d];
		if (ni < 1 || nj < 1 || ni > R || nj > C || visited[ni][nj] || board[ni][nj] == '.')
			continue;

		pair<int, int> position = get_position(ni, nj);
		ri = position.first;
		rj = position.second;
	}

	bool flag;
	for (int b = 1; b <= 7; b++) {
		switch (b) {
		case 1:	board[ri][rj] = '1';	break;
		case 2:	board[ri][rj] = '2';	break;
		case 3:	board[ri][rj] = '3';	break;
		case 4:	board[ri][rj] = '4';	break;
		case 5:	board[ri][rj] = '|';	break;
		case 6:	board[ri][rj] = '-';	break;
		case 7:	board[ri][rj] = '+';	break;
		}

		flag = true;

		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (board[i][j] == '.' || board[i][j] == 'M' || board[i][j] == 'Z')	continue;
				int number = um[board[i][j]];
				for (int d : roads[number]) {
					ni = i + di[d];
					nj = j + dj[d];
					if (ni < 1 || nj < 1 || ni > R || nj > C || board[ni][nj] == 'M' || board[ni][nj] == 'Z' || board[ni][nj] == '.')
						continue;

					if (!is_linked(i, j, ni, nj)) {
						flag = false;
						break;
					}
				}
				if (!flag) break;
			}
			if (!flag)	break;
		}
		if (flag)	break;
	}
	cout << ri << " " << rj << " " << board[ri][rj];
	return 0;
}