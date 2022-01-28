#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, pair<int, int>> info;
int board[125][125];
int result[125][125];
int status[125][125];
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };
priority_queue<info, vector<info>, greater<info>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t = 0, n;
	cin >> n;
	while (n != 0) {
		t++;
		while (!pq.empty())	pq.pop();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
				status[i][j] = 0;
			}
		}
		info cur;
		int next_i, next_j;
		status[0][0] = 2;

		for (int k = 0; k < 4; k++) {
			next_i = di[k];
			next_j = dj[k];
			if (next_i < 0 || next_j < 0 || next_i >= n || next_j >= n)
				continue;

			status[next_i][next_j] = 1;
			pq.push({ board[0][0] + board[next_i][next_j] , { next_i, next_j} });
		}
		for (int i = 1; i < n * n; i++) {
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
				if (next_i < 0 || next_j < 0 || next_i >= n || next_j >= n)
					continue;

				switch (status[next_i][next_j]) {
				case 0:
					status[next_i][next_j] = 1;
				case 1:
					pq.push({ cur.first + board[next_i][next_j], {next_i, next_j} });
				}
			}
		}
		cout << "Problem " << t << ": " << result[n - 1][n - 1] << "\n";

		cin >> n;
	}
	return 0;
}