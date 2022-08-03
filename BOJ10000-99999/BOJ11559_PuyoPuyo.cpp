#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

char board[13][7];
char temp_board[13][7];
bool visited[13][7];
bool pung[13][7];
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> q;
vector<pair<int, int>> v;

int main() {
	for (int i = 1; i <= 12; i++)
		for (int j = 1; j <= 6; j++)
			cin >> board[i][j];

	int link = -1, pop_cnt;
	bool pop = true;
	char puyo;
	pair<int, int> cur;
	int next_i, next_j;
	do{
		link++;
		pop = false;
		for (int i = 1; i <= 12; i++) {
			for (int j = 1; j <= 6; j++) {
				visited[i][j] = false;
				pung[i][j] = false;
				temp_board[i][j] = '.';
			}
		}
				

		for (int i = 1; i <= 12; i++) {
			for (int j = 1; j <= 6; j++) {
				puyo = board[i][j];
				if (!visited[i][j] && puyo != '.') {
					v = {};
					pop_cnt = 1;
					visited[i][j] = true;
					q.push({ i, j });
					v.push_back({ i, j });
					
					while (!q.empty()) {
						cur = q.front();
						q.pop();

						for (int k = 0; k < 4; k++) {
							next_i = cur.first + di[k];
							next_j = cur.second + dj[k];

							if (next_i < 1 || next_j < 1 || next_i > 12 || next_j > 6)
								continue;

							if (!visited[next_i][next_j] && board[next_i][next_j] == puyo) {
								pop_cnt++;
								visited[next_i][next_j] = true;
								v.push_back({ next_i, next_j });
								q.push({ next_i, next_j });
							}
						}
					}

					if (pop_cnt >= 4) {
						pop = true;
						for (pair<int, int> p : v)
							pung[p.first][p.second] = true;
					}
				}
			}
		}

		for (int j = 1; j <= 6; j++) {
			int index = 12;
			for (int i = 12; i >= 1; i--) {
				if (pung[i][j])	continue;
				temp_board[index--][j] = board[i][j];
			}
		}
		for (int i = 1; i <= 12; i++) {
			for (int j = 1; j <= 6; j++) 
				board[i][j] = temp_board[i][j];
		}

	} while (pop);

	cout << link;

	return 0;
}