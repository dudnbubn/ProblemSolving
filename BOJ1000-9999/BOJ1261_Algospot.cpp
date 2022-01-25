// key point : Dijkstra Algorithm

#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, pair<int, int>> info;
priority_queue<info, vector<info>, greater<info>> pq;
int board[101][101];
int status[101][101];
int di[4] = { -1,0,1,0 };
int dj[4] = { 0,1,0,-1 };
int result[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> m >> n;
	char input;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> input;
			board[i][j] = input - '0';
		}
	}
	info cur;
	int next_i, next_j;
	
	status[1][1] = 2;
	for (int k = 0; k < 4; k++) {
		next_i = 1 + di[k];
		next_j = 1 + dj[k];
		if (next_i < 1 || next_j < 1 || next_i > n || next_j > m)
			continue;

		status[next_i][next_j] = 1;
		pq.push({ board[next_i][next_j], {next_i, next_j} });
	}
	for (int i = 2; i <= n * m; i++) {
		cur = pq.top();
		pq.pop();
		while (status[cur.second.first][cur.second.second] == 2) {
			cur = pq.top();
			pq.pop();
		}
		status[cur.second.first][cur.second.second] = 2;
		result[cur.second.first][cur.second.second] = cur.first;
		
		for (int k = 0; k < 4; k++) {
			next_i = cur.second.first + di[k];
			next_j = cur.second.second + dj[k];
			if (next_i < 1 || next_j < 1 || next_i > n || next_j > m)
				continue;

			switch (status[next_i][next_j]) {
			case 0:
				status[next_i][next_j] = 1;
				pq.push({ cur.first + board[next_i][next_j], {next_i, next_j} });
				break;
			case 1:
				pq.push({ cur.first + board[next_i][next_j], {next_i, next_j} });
				break;
			}
		}
	}
	cout << result[n][m];
	return 0;
}