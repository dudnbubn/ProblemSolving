#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
queue<pair<int, int>> air;
queue<pair<int, int>> cheese;
int board[101][101];
bool visited[101][101];
int di[4] = { -1,1,0,0 };
int dj[4] = { 0,0,-1,1 };
int save = 0;

int BFS() {
	int result = -1;
	visited[1][1] = true;
	air.push({ 1, 1 });
	pair<int, int> cur;
	int next_i, next_j, qsz;
	

	while (!air.empty()) {
		result++;
		while (!air.empty()) {
			cur = air.front();
			air.pop();
			for (int k = 0; k < 4; k++) {
				next_i = cur.first + di[k];
				next_j = cur.second + dj[k];
				if (next_i < 1 || next_j < 1 || next_i > n || next_j > m)
					continue;
				if (!visited[next_i][next_j]) {
					visited[next_i][next_j] = true;
					if (board[next_i][next_j] == 0) {
						air.push({ next_i, next_j });
					}
					else if (board[next_i][next_j] == 1) {
						cheese.push({ next_i, next_j });
					}
				}
			}
		}
		if (!cheese.empty()) {
			save = cheese.size();
			air = cheese;
			while (!cheese.empty())	cheese.pop();
		}
	}
	return result;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) 
			cin >> board[i][j];

	cout << BFS() << "\n";
	cout << save;

	return 0;
}