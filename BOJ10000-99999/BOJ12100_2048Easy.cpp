#include <iostream>

using namespace std;

int N;
int result = 0;
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0 ,-1 };
bool visited[21][21];

void recur(int cnt, int board[][21]) {
	if (cnt == 5) {
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				result = result > board[i][j] ? result : board[i][j];
		return;
	}
	
	int temp[21][21];
	for (int d = 0; d < 4; d++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				temp[i][j] = board[i][j];
				visited[i][j] = false;
			}
		}
		int ni, nj;
		if (d == 0 || d == 3) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					if (temp[i][j] == 0)	continue;
					ni = i + di[d];
					nj = j + dj[d];
					while (1 <= ni && ni <= N && 1 <= nj && nj <= N && temp[ni][nj] == 0 && !visited[ni][nj]) {
						ni += di[d];
						nj += dj[d];
					}
					
					if (1 <= ni && ni <= N && 1 <= nj && nj <= N) {
						if (temp[ni][nj] == temp[i][j] && !visited[ni][nj]) {
							temp[ni][nj] *= 2;
							temp[i][j] = 0;
							visited[ni][nj] = true;
						}
						else {
							ni -= di[d];
							nj -= dj[d];
							if (i != ni || j != nj) {
								temp[ni][nj] = temp[i][j];
								temp[i][j] = 0;
							}
						}
					}
					else {
						ni -= di[d];
						nj -= dj[d];
						if (i != ni || j != nj) {
							temp[ni][nj] = temp[i][j];
							temp[i][j] = 0;
						}
					}
				}
			}
		}
		else {
			for (int i = N; i >= 1; i--) {
				for (int j = N; j >= 1; j--) {
					if (temp[i][j] == 0)	continue;
					ni = i + di[d];
					nj = j + dj[d];
					while (1 <= ni && ni <= N && 1 <= nj && nj <= N && temp[ni][nj] == 0 && !visited[ni][nj]) {
						ni += di[d];
						nj += dj[d];
					}

					if (1 <= ni && ni <= N && 1 <= nj && nj <= N) {
						if (temp[ni][nj] == temp[i][j] && !visited[ni][nj]) {
							temp[ni][nj] *= 2;
							temp[i][j] = 0;
							visited[ni][nj] = true;
						}
						else {
							ni -= di[d];
							nj -= dj[d];
							if (i != ni || j != nj) {
								temp[ni][nj] = temp[i][j];
								temp[i][j] = 0;
							}
						}
					}
					else {
						ni -= di[d];
						nj -= dj[d];
						if (i != ni || j != nj) {
							temp[ni][nj] = temp[i][j];
							temp[i][j] = 0;
						}
					}
				}
			}
		}
		recur(cnt + 1, temp);
	}
}

int main() {
	cin >> N;

	int board[21][21];
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> board[i][j];

	recur(0, board);

	cout << result;

	return 0;
}