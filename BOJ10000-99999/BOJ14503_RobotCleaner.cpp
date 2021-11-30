#include <iostream>
using namespace std;

int n, m;
int robot_r, robot_c, robot_dir;
int board[51][51];
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

int cleanning(int r, int c, int dir) {
	int next_r, next_c, next_dir;
	while (1) {
		if(board[r][c] == 0)
			board[r][c] = 2;
		bool flag = true;
		for (int k = 1; k <= 4; k++) {
			next_dir = (dir + 4 - k) % 4;
			next_r = r + dr[next_dir];
			next_c = c + dc[next_dir];
			if (board[next_r][next_c] == 0) {
				flag = false;
				r = next_r;
				c = next_c;
				dir = next_dir;
				break;
			}
		}
		if (flag) {
			next_dir = (dir + 2) % 4;
			next_r = r + dr[next_dir];
			next_c = c + dc[next_dir];
			if (board[next_r][next_c] == 1) 
				break;
			else {
				r = next_r;
				c = next_c;
				continue;
			}
		}
	}
	int result = 0;
	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++)
			if (board[i][j] == 2)
				result++;

	return result;
}

int main() {
	cin >> n >> m;
	cin >> robot_r >> robot_c >> robot_dir;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	cout << cleanning(robot_r, robot_c, robot_dir);

	return 0;
}