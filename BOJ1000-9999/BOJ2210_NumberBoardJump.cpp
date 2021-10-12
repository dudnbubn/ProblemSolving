#include <iostream>
#include <set>
using namespace std;

char board[6][6];
set<string> setString;
int di[4] = { 0,0,-1,1 };
int dj[4] = { -1,1,0,0 };

void DFS(int cur_i, int cur_j, int cnt, string num) {
	if (cnt == 6) {
		setString.insert(num);
		return;
	}
	int next_i, next_j;
	for (int k = 0; k < 4; k++) {
		next_i = cur_i + di[k];
		next_j = cur_j + dj[k];
		if (next_i < 1 || next_j < 1 || next_i > 5 || next_j > 5)
			continue;
		DFS(next_i, next_j, cnt + 1, num + board[cur_i][cur_j]);
	}
}

int main() {
	for (int i = 1; i <= 5; i++)
		for (int j = 1; j <= 5; j++)
			cin >> board[i][j];
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++)
			DFS(i, j, 0, "");
	}
	cout << setString.size();
	return 0;
}