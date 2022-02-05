#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
char board[22][22];
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };
int minimum = 11;

bool esc(int i, int j) {
	if (i < 1 || j < 1 || i > n || j > m)
		return true;
	return false;
}

void Recur(int cnt, int i1, int j1, int i2, int j2) {
	if (cnt > 10)	return;
	bool esc1 = esc(i1, j1);
	bool esc2 = esc(i2, j2);
	if (esc1 != esc2) {
		minimum = min(minimum, cnt);
		return;
	}
	else if (esc1)
		return;

	int next_i1, next_j1, next_i2, next_j2;
	for (int k = 0; k < 4; k++) {
		next_i1 = i1 + di[k];
		next_j1 = j1 + dj[k];
		next_i2 = i2 + di[k];
		next_j2 = j2 + dj[k];
		if (board[next_i1][next_j1] == '#') {
			next_i1 = i1;
			next_j1 = j1;
		}
		if (board[next_i2][next_j2] == '#') {
			next_i2 = i2;
			next_j2 = j2;
		}
		Recur(cnt + 1, next_i1, next_j1, next_i2, next_j2);
	}
}

int main() {
	cin >> n >> m;
	int i1 = 0, j1 = 0, i2 = 0, j2 = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'o') {
				if (i1 == 0) {
					i1 = i;
					j1 = j;
				}
				else {
					i2 = i;
					j2 = j;
				}
			}
		}
	}

	Recur(0, i1, j1, i2, j2);
	cout << (minimum == 11 ? -1 : minimum);
	return 0;
}