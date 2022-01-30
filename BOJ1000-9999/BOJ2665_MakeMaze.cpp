#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, pair<int, int>> info;

int n;
int board[51][51];
int status[51][51];
int result[51][51];
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };
priority_queue<info, vector<info>, greater<info>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	char input;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> input;
			if (input == '1')	board[i][j] = 0;
			else	board[i][j] = 1;
		}
	}
	pq.push({ 0, {1, 1} });
	info cur;
	int next_i, next_j;
	for (int i = 1; i <= n * n; i++) {
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
			if (next_i < 1 || next_j < 1 || next_i > n || next_j > n)
				continue;

			switch (status[next_i][next_j]) {
			case 0:
				status[next_i][next_j] = 1;
			case 1:
				pq.push({ cur.first + board[next_i][next_j], {next_i, next_j} });
			}
		}
	}
	cout << result[n][n];
	return 0;
}