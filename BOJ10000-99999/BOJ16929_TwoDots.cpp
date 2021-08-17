// 좌표가 최대 50 * 50 이기 때문에 DFS를 모든 점에 대해 돌면서 사이클이 있는지 판단해줄 수 있다.

#include <iostream>
using namespace std;

int n, m;
int start_i, start_j;
char board[51][51] = { 0, };
bool visited[51][51] = { 0, };
int di[4] = { -1,0,1,0 };
int dj[4] = { 0,1,0,-1 };

void DFS(int i, int j, int len) {
	visited[i][j] = true;
	
	for (int k = 0; k < 4; k++) {
		int temp_i = i + di[k];
		int temp_j = j + dj[k];
		if (temp_i < 1 || temp_j < 1 || temp_i > n || temp_j > m)
			continue;
		if (board[i][j] == board[temp_i][temp_j]) {
			if ((temp_i == start_i) && (temp_j == start_j) && len > 2) {
				cout << "Yes";
				exit(0);
			}
			if (visited[temp_i][temp_j] == false)
				DFS(temp_i, temp_j, len + 1);
		}
	}
	visited[i][j] = false;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cin >> board[i][j];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			start_i = i;
			start_j = j;
			DFS(i, j, 0);
		}
	}
	cout << "No";
	return 0;
}