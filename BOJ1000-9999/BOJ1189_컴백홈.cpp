#include <iostream>

using namespace std;

int R, C, K;
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };

char board[5][5];
bool is_visited[5][5];
int result;

bool in_board(int r, int c) {
	if (r < 0 || c < 0 || r >= R || c >= C)	return false;
	return true;
}

void DFS(int r, int c, int k) {
	if (r == 0 && c == C - 1) {
		if(k == K)	result++;
		return;
	}
	is_visited[r][c] = true;

	int nr, nc;
	for (int d = 0; d < 4; d++) {
		nr = r + di[d];
		nc = c + dj[d];

		if (!in_board(nr, nc) || is_visited[nr][nc] || board[nr][nc] == 'T')	continue;
		DFS(nr, nc, k+1);
	}

	is_visited[r][c] = false;
}


int main() {
	cin >> R >> C >> K;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> board[r][c];
		}
	}

	DFS(R - 1, 0, 1);
	cout << result;
	return 0;
}