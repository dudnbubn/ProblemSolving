#include <iostream>

using namespace std;

#define N 10
#define INF 987654321

int board[11][11];
int result = INF;
int di[5] = { 0, 0, 1, 0, -1 };
int dj[5] = { 0, -1, 0, 1, 0 };

bool exist_light() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			if (board[i][j])	return true;
	}
	return false;
}

void recur(int position, int cnt) {
	int pi = (position - 1) / 10, pj = (position - 1) % 10 + 1;
	
	if (board[pi][pj])	return;
	if (position == 100) {
		if (exist_light())	return;
		result = result < cnt ? result : cnt;
		return;
	}
	
	recur(position + 1, cnt);
	int i = position / 10 + 1, j = position % 10 + 1;
	int ni, nj;
	for (int d = 0; d < 5; d++) {
		ni = i + di[d];
		nj = j + dj[d];
		if (ni < 1 || nj < 1 || ni > N || nj > N)
			continue;
		
		board[ni][nj] = (board[ni][nj] + 1) % 2;
	}
	recur(position + 1, cnt + 1);
	for (int d = 0; d < 5; d++) {
		ni = i + di[d];
		nj = j + dj[d];
		if (ni < 1 || nj < 1 || ni > N || nj > N)
			continue;

		board[ni][nj] = (board[ni][nj] + 1) % 2;
	}
}

int main() {
	string input;
	for (int i = 1; i <= N; i++) {
		cin >> input;
		for (int j = 1; j <= N; j++)
			board[i][j] = (input[j - 1] == 'O' ? 1 : 0);
	}

	recur(0, 0);
	
	cout << (result == INF ? -1 : result);
	return 0;
}