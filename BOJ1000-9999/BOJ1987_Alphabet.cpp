#include <iostream>
#include <algorithm>
using namespace std;

int r, c;
char board[21][21];
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };
int maximum = 0;

void DFS(int i, int j, int cnt, int check) {
	bool flag = true;
	int next_i, next_j;
	for (int k = 0; k < 4; k++) {
		next_i = i + di[k];
		next_j = j + dj[k];
		if (next_i < 1 || next_j < 1 || next_i > r || next_j > c)
			continue;

		if (!(check & (1 << board[next_i][next_j] - 'A'))) {
			DFS(next_i, next_j, cnt + 1, check | (1 << board[next_i][next_j] - 'A'));
			flag = false;
		}
	}
	if (flag) {
		maximum = max(maximum, cnt);
		return;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> r >> c;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			cin >> board[i][j];

	DFS(1, 1, 1, (1 << board[1][1] - 'A'));
	cout << maximum;
	return 0;
}