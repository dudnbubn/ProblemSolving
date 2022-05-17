#include <iostream>

using namespace std;

int r, c;
char board[11][11];
int land_count[11][11];
int di[4] = { -1 ,0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };

int main() {
	cin >> r >> c;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			cin >> board[i][j];

	int adj_i, adj_j;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (board[i][j] == '.')	continue;
			for (int k = 0; k < 4; k++) {
				adj_i = i + di[k];
				adj_j = j + dj[k];
				if (adj_i < 1 || adj_j < 1 || adj_i > r || adj_j > c)
					continue;
				if (board[adj_i][adj_j] == 'X')
					land_count[i][j]++;
			}
		}
	}
	int start_i = r, start_j = c, end_i = 1, end_j = 1;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (land_count[i][j] < 2)
				board[i][j] = '.';

			if (board[i][j] == 'X') {
				start_i = start_i < i ? start_i : i;
				start_j = start_j < j ? start_j : j;
				end_i = end_i > i ? end_i : i;
				end_j = end_j > j ? end_j : j;
			}
		}
	}
	for (int i = start_i; i <= end_i; i++) {
		for (int j = start_j; j <= end_j; j++)
			cout << board[i][j];
		cout << "\n";
	}
	return 0;
}