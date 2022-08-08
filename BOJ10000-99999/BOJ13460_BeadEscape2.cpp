#include <iostream>

using namespace std;

int N, M;
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0 ,-1 };
int result = 11;

void recur(int cnt, char board[][11]) {
	if (cnt == 11)	return;

	char temp[11][11];
	bool rflag = false, bflag = false;

	for (int d = 0; d < 4; d++) {
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				temp[i][j] = board[i][j];
		rflag = false;	bflag = false;

		if (d == 0 || d == 3) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= M; j++) {
					if (temp[i][j] != 'R' && temp[i][j] != 'B')	continue;

					int ni = i + di[d], nj = j + dj[d];
					while (temp[ni][nj] == '.') {
						ni += di[d];
						nj += dj[d];
					}
					if (temp[ni][nj] == 'O') {
						if (temp[i][j] == 'B') bflag = true;
						else	rflag = true;
						temp[i][j] = '.';
					}
					else {
						ni -= di[d];
						nj -= dj[d];
						if (temp[ni][nj] != temp[i][j]) {
							temp[ni][nj] = temp[i][j];
							temp[i][j] = '.';
						}
					}
				}
			}
		}
		else {
			for (int i = N - 1; i >= 0; i--) {
				for (int j = M - 1; j >= 0; j--) {
					if (temp[i][j] != 'R' && temp[i][j] != 'B')	continue;

					int ni = i + di[d], nj = j + dj[d];
					while (temp[ni][nj] == '.') {
						ni += di[d];
						nj += dj[d];
					}
					if (temp[ni][nj] == 'O') {
						if (temp[i][j] == 'B') bflag = true;
						else	rflag = true;
						temp[i][j] = '.';
					}
					else {
						ni -= di[d];
						nj -= dj[d];
						if (temp[ni][nj] != temp[i][j]) {
							temp[ni][nj] = temp[i][j];
							temp[i][j] = '.';
						}
					}
				}
			}
		}
		if (!bflag) {
			if(!rflag)
				recur(cnt + 1, temp);
			else {
				result = result < cnt ? result : cnt;
				return;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	char board[11][11];
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> board[i][j];

	recur(1, board);
	if (result == 11)	cout << -1;
	else	cout << result;

	return 0;
}