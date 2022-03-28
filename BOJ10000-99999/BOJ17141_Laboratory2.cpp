#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int board[51][51];
int temp[51][51];
bool visited[51][51];
vector<pair<int, int>> virus;
bool used[10];
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };
int minimum = 987654321;
queue<pair<int, int>> q;

void Brute(int k, int prev) {
	if (k == m) {
		for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= n; j++) 
				visited[i][j] = false;

		for (int i = 0; i < 10; i++) {
			if (used[i]) {
				visited[virus[i].first][virus[i].second] = true;
				q.push(virus[i]);
			}
		}

		pair<int, int> cur;
		int next_i, next_j;
		int cnt = -1, qsz;
		while (!q.empty()) {
			cnt++;
			qsz = q.size();
			for (int i = 0; i < qsz; i++) {
				cur = q.front();
				q.pop();
				for (int k = 0; k < 4; k++) {
					next_i = cur.first + di[k];
					next_j = cur.second + dj[k];
					if (next_i < 1 || next_j < 1 || next_i > n || next_j > n)
						continue;
					if (!visited[next_i][next_j] && board[next_i][next_j] != 1) {
						visited[next_i][next_j] = true;
						q.push({ next_i, next_j });
					}
				}
			}
		}
		bool flag = true;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (board[i][j] != 1 && !visited[i][j]) {
					flag = false;
					break;
				}
			}
			if (!flag)	break;
		}
		if(flag)
			minimum = minimum < cnt ? minimum : cnt;
		return;
	}

	for (int i = prev + 1; i < virus.size(); i++) {
		if (!used[i]) {
			used[i] = true;
			Brute(k + 1, i);
			used[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
				virus.push_back({ i, j });
			}
		}
	}

	Brute(0, -1);

	cout << (minimum == 987654321 ? -1 : minimum);
	return 0;
}