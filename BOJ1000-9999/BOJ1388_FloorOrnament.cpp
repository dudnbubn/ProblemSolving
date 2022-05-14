#include <iostream>

using namespace std;

int n, m;
char board[51][51];
bool visited[51][51];
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };

void DFS(int i, int j) {
	if (board[i][j] == '|') {
		if (i < n && board[i + 1][j] == '|') {
			visited[i + 1][j] = true;
			DFS(i + 1, j);
		}
	}
	else {
		if (j < m && board[i][j + 1] == '-') {
			visited[i][j + 1] = true;
			DFS(i, j + 1);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> board[i][j];

	int result = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!visited[i][j]) {
				result++;
				DFS(i, j);
			}
		}
	}
	cout << result;
	return 0;
}