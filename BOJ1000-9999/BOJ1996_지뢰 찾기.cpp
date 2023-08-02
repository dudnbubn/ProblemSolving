#include <iostream>

using namespace std;

#define MINE 100

char board[1002][1002];
int results[1002][1002];

int di[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dj[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int main() {
	int N;
	cin >> N;
	
	int mine;
	int ni, nj;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
			if (board[i][j] != '.') {
				results[i][j] = MINE;
				mine = board[i][j] - '0';
				for (int d = 0; d < 8; d++) {
					ni = i + di[d];
					nj = j + dj[d];
					if (ni < 1 || nj < 1 || ni > N || nj > N)	continue;
					results[ni][nj] += mine;
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (results[i][j] >= MINE)	cout << '*';
			else if (results[i][j] >= 10)	cout << 'M';
			else	cout << results[i][j];
		}
		cout << "\n";
	}

}