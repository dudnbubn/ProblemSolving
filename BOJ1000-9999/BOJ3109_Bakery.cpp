#include <iostream>

using namespace std;

int R, C, result;
char board[10000][500];
bool visited[10000][500];
int di[3] = { -1, 0, 1 };
bool check;

void recur(int i, int j) {
	if (check)	return;
	
	visited[i][j] = true;
	if (j == C - 1) {
		result++;
		check = true;
		return;
	}

	int ni, nj;
	for (int d = 0; d < 3; d++) {
		ni = i + di[d];
		nj = j + 1;

		if (ni < 0 || ni >= R || nj < 0 || nj >= C)
			continue;

		if (!visited[ni][nj] && board[ni][nj] == '.') 
			recur(ni, nj);
	}
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> board[i][j];

	for (int i = 0; i < R; i++) {
		check = false;
		recur(i, 0);
	}

	cout << result;

	return 0;
}