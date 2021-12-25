#include <iostream>
#include <algorithm>
using namespace std;

int n;
int board[101][101];
bool visited[101][101];
int di[4] = { -1,1,0,0 };
int dj[4] = { 0,0,-1,1 };

void DFS(int i, int j, int h) {
	visited[i][j] = true;
	int next_i, next_j;
	for (int k = 0; k < 4; k++) {
		next_i = i + di[k];
		next_j = j + dj[k];
		if (next_i < 1 || next_j < 1 || next_i > n || next_j > n)
			continue;
		if (board[next_i][next_j] > h && !visited[next_i][next_j]) {
			DFS(next_i, next_j, h);
		}
	}
}

int main() {
	cin >> n;
	int maximum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
			maximum = max(maximum, board[i][j]);
		}
	}
	
	int result = 0;
	int cnt;
	for (int h = 0; h < maximum; h++) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				visited[i][j] = false;
		
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (board[i][j] > h && !visited[i][j]) {
					DFS(i, j, h);
					cnt++;
				}
			}
		}
		result = max(result, cnt);
	}
	cout << result;
	return 0;
}