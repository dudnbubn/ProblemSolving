#include <iostream>

using namespace std;

int R, C, T;
int cur_status[51][51];
int next_status[51][51];
int cleaner;
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };

void cycle() {
	next_status[cleaner - 1][1] = next_status[cleaner][1] = -1;

	int next_i, next_j, spread, dif;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (cur_status[i][j] == 0 || cur_status[i][j] == -1)	continue;

			spread = 0;
			for (int k = 0; k < 4; k++) {
				next_i = i + di[k];
				next_j = j + dj[k];
				if (next_i < 1 || next_j < 1 || next_i > R || next_j > C)
					continue;

				if (cur_status[next_i][next_j] != -1) {
					dif = cur_status[i][j] / 5;
					next_status[next_i][next_j] += dif;
					spread += dif;
				}
			}
			next_status[i][j] += cur_status[i][j] - spread;
		}
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cur_status[i][j] = next_status[i][j];
			next_status[i][j] = 0;
		}
	}

	int cur_i = cleaner - 2, cur_j = 1, dir = 0;
	while (cur_i != cleaner - 1 || cur_j != 2) {
		next_i = cur_i + di[dir];
		next_j = cur_j + dj[dir];
		if (next_i < 1 || next_j < 1 || next_i >= cleaner || next_j > C) {
			dir = (dir + 1) % 4;
			continue;
		}
		cur_status[cur_i][cur_j] = cur_status[next_i][next_j];
		cur_i = next_i;
		cur_j = next_j;
	}
	cur_status[cur_i][cur_j] = 0;

	cur_i = cleaner + 1, cur_j = 1, dir = 2;
	while (cur_i != cleaner || cur_j != 2) {
		next_i = cur_i + di[dir];
		next_j = cur_j + dj[dir];
		if (next_i < cleaner || next_j < 1 || next_i > R || next_j > C) {
			dir = (dir + 3) % 4;
			continue;
		}
		cur_status[cur_i][cur_j] = cur_status[next_i][next_j];
		cur_i = next_i;
		cur_j = next_j;
	}
	cur_status[cur_i][cur_j] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> R >> C >> T;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> cur_status[i][j];
			if (cur_status[i][j] == -1)
				cleaner = i;
		}
	}

	for (int i = 0; i < T; i++)
		cycle();

	int result = 0;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (cur_status[i][j] == -1)	continue;
			result += cur_status[i][j];
		}
	}

	cout << result;

	return 0;
}