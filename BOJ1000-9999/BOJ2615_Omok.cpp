#include <iostream>
using namespace std;

int board[20][20] = { 0, };
int di[4] = { -1, 0, 1, 1 };
int dj[4] = { 1, 1, 1, 0 };
bool black = false, white = false;

void DFS(int k, int color, int dir, int cur_i, int cur_j) {
	if (k == 4) {
		cout << cur_i << ", " << cur_j << " 오목 도달, 육목 확인\n";
		int check_i = cur_i + di[dir];
		int check_j = cur_j + dj[dir];
		if (check_i >= 1 && check_j >= 1 && check_i <= 19 && check_j <= 19) 
			if (board[check_i][check_j] == color)	return;
		check_i -= 6 * di[dir];
		check_j -= 6 * dj[dir];
		if (check_i >= 1 && check_j >= 1 && check_i <= 19 && check_j <= 19)
			if (board[check_i][check_j] == color)	return;

		if (color == 1)	black = true;
		else	white = true;
		return;
	}
	if (k == 0) {
		int next_i, next_j;
		for (int i = 0; i < 4; i++) {
			next_i = cur_i + di[i];
			next_j = cur_j + dj[i];
			if (next_i < 1 || next_j < 1 || next_i > 19 || next_j > 19)
				continue;
			if (board[next_i][next_j] == color) 
				DFS(k + 1, color, i, next_i, next_j);
		}
	}
	else {
		if (board[cur_i + di[dir]][cur_j + dj[dir]] == color)
			DFS(k + 1, color, dir, cur_i + di[dir], cur_j + dj[dir]);
	}
}

int main() {
	int result_i = 0, result_j = 0;
	for (int i = 1; i <= 19; i++)
		for (int j = 1; j <= 19; j++)
			cin >> board[i][j];
	for (int i = 1; i <= 19; i++) {
		for (int j = 1; j <= 19; j++) {
			if (board[i][j] == 0)	continue;
			DFS(0, board[i][j], 0, i, j);
			if (black || white) {
				result_i = i;
				result_j = j;
				break;
			}
		}
		if (black || white)	break;
	}
	if (!black && !white)	cout << 0;
	else {
		if (black)	cout << 1 << "\n";
		else	cout << 2 << "\n";
		cout << result_i << " " << result_j;
	}
	return 0;
}