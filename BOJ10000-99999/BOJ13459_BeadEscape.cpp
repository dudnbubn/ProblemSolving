#include <iostream>

using namespace std;

int N, M;

int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };

bool result = false;

void subs(int depth, int prev, char board[][10]) {
	if (result || depth == 10)	return;

	int ni, nj;

	for (int d = 0; d < 4; d++) {
		
		bool red_in = false, blue_in = false;
		char temp_board[10][10];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				temp_board[i][j] = board[i][j];
		if (d == 0 || d == 3) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (temp_board[i][j] != 'R' && temp_board[i][j] != 'B')
						continue;

					ni = i + di[d];
					nj = j + dj[d];

					while (temp_board[ni][nj] == '.') {
						ni += di[d];
						nj += dj[d];
					}

					if (temp_board[ni][nj] == 'O') {
						if (temp_board[i][j] == 'R')	red_in = true;
						else	blue_in = true;
						temp_board[i][j] = '.';
					}
					else {
						ni -= di[d];
						nj -= dj[d];

						if (temp_board[ni][nj] != temp_board[i][j]) {
							temp_board[ni][nj] = temp_board[i][j];
							temp_board[i][j] = '.';
						}
					}
				}
			}
		}
		else {
			for (int i = N - 2; i >= 0; i--) {
				for (int j = M - 2; j >= 0; j--) {
					if (temp_board[i][j] != 'R' && temp_board[i][j] != 'B')
						continue;

					ni = i + di[d];
					nj = j + dj[d];

					while (temp_board[ni][nj] == '.') {
						ni += di[d];
						nj += dj[d];
					}

					if (temp_board[ni][nj] == 'O') {
						if (temp_board[i][j] == 'R')	red_in = true;
						else	blue_in = true;
						temp_board[i][j] = '.';
					}
					else {
						ni -= di[d];
						nj -= dj[d];

						if (i != ni || j != nj) {
							temp_board[ni][nj] = temp_board[i][j];
							temp_board[i][j] = '.';
						}
					}
				}
			}
		}

		if (!blue_in) {
			if(!red_in)
				subs(depth + 1, d, temp_board);
			else {
				result = true;
				return;
			}
		}
	}
}

int main() {
	cin >> N >> M;

	char board[10][10];
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			cin >> board[i][j];

	subs(0, -1, board);
	
	cout << (result ? 1 : 0);
	return 0;
}