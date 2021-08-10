// 처음에 안익은 토마토(0)를 기준으로 BFS를 돌렸더니 시간초과가 발생했다.
// 익은 토마토(1)를 기준으로 돌리니 잘 해결된다. set을 이용해 같은 토마토를 여러번 익게 하지 않도록 주의해야한다.
#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

int n, m;
int box[1001][1001];
int di[4] = { 0, -1, 0, 1 };
int dj[4] = { -1, 0, 1, 0 };
queue<pair<int, int>> q;
set<pair<int, int>> save;
set<pair<int, int>>::iterator iter;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1)
				q.push({ i,j });
		}
	}
	int date = -1;
	while (!q.empty()) {
		date++;
		save.clear();
		int qsz = q.size();
		for (int i = 0; i < qsz; i++) {
			pair<int, int> cur = q.front();
			q.pop();
			for (int k = 0; k < 4; k++) {
				int temp_i = cur.first + di[k];
				int temp_j = cur.second + dj[k];
				if (temp_i < 1 || temp_i > n || temp_j < 1 || temp_j > m)
					continue;
				if (box[temp_i][temp_j] == 0)
					save.insert({ temp_i,temp_j });
			}
		}
		for (iter = save.begin(); iter != save.end(); iter++) {
			box[iter->first][iter->second] = 1;
			q.push({ iter->first, iter->second });
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (box[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << date;

	return 0;
}