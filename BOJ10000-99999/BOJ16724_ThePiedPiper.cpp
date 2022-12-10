#include <iostream>

using namespace std;

int N, M;
int board[1000][1000];	
int status[1000][1000];		// 좌표 상태, 0 : 방문 X, 1 : 방문, 2: SAFE ZONE

int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };

int result;

void DFS(int cur_i, int cur_j) {
	int d = board[cur_i][cur_j];
	int next_i = cur_i + di[d];
	int next_j = cur_j + dj[d];

	status[cur_i][cur_j] = 1;

	if (status[next_i][next_j] == 0)	DFS(next_i, next_j);
	if (status[next_i][next_j] == 1)	result++;
	status[cur_i][cur_j] = 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	char input;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> input;
			if (input == 'U')	board[i][j] = 0;
			else if (input == 'R')	board[i][j] = 1;
			else if (input == 'D')	board[i][j] = 2;
			else if (input == 'L')	board[i][j] = 3;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (status[i][j])	continue;
			DFS(i, j);
		}
	}
	cout << result;
	return 0;
}