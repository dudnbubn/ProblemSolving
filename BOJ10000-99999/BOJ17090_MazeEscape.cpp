#include <iostream>

using namespace std;

int N, M;
char board[501][501];
bool visited[501][501];
bool escape[501][501];

bool DFS(int i, int j) {
	if (i < 1 || j < 1 || i > N || j > M) return escape[i][j] = true;
	if (visited[i][j]) return escape[i][j];

	visited[i][j] = true;
	switch (board[i][j]) {
	case 'U':	return escape[i][j] = DFS(i - 1, j);
	case 'R':	return escape[i][j] = DFS(i, j + 1);
	case 'D':	return escape[i][j] = DFS(i + 1, j);
	case 'L':	return escape[i][j] = DFS(i, j - 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	string input;
	for (int i = 1; i <= N; i++) {
		cin >> input;
		for (int j = 0; j < M; j++) 
			board[i][j + 1] = input[j];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (!visited[i][j]) {
				escape[i][j] = DFS(i, j);
			}
		}
	}

	int result = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (escape[i][j])
				result++;
		}
	}
	cout << result;

	return 0;
}