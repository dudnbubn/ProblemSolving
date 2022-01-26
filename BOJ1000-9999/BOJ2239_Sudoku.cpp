#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

char board[10][10];
vector<pair<int, int>> v;

void DFS(int k) {
	if (k == v.size()) {
		for (int i = 1; i < 10; i++) {
			for (int j = 1; j < 10; j++)
				cout << board[i][j];
			cout << "\n";
		}
		exit(0);
	}
	pair<int, int> cur = v[k];
	bool flag;
	for (int num = 1; num < 10; num++) {
		flag = true;
		for (int i = 1; i < 10; i++) {
			if (i == cur.second)	continue;
			if (board[cur.first][i] == '0' + num) {
				flag = false;
				break;
			}
		}
		if (!flag) continue;
		for (int i = 1; i < 10; i++) {
			if (i == cur.first)	continue;
			if (board[i][cur.second] == '0' + num) {
				flag = false;
				break;
			}
		}
		if (!flag) continue;
		int start_i = cur.first - (cur.first - 1) % 3;
		int start_j = cur.second - (cur.second - 1) % 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if ((start_i + i) == cur.first && (start_j + j) == cur.second)
					continue;
				if (board[start_i + i][start_j + j] == '0' + num) {
					flag = false;
					break;
				}
			}
			if (!flag)	break;
		}
		if (flag) {
			board[cur.first][cur.second] = '0' + num;
			DFS(k + 1);
			board[cur.first][cur.second] = '0';
		}
	}
}

int main() {
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			cin >> board[i][j];
			if (board[i][j] == '0')
				v.push_back({ i, j });
		}
	}

	DFS(0);
	return 0;
}