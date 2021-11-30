// Brute force & BFS

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int lab[9][9];
int maximum = 0;
vector<pair<int, int>> blank;
int vsz;
int di[4] = { 0,0,-1,1 };
int dj[4] = { -1,1, 0,0 };

int BFS() {
	int temp[9][9];
	queue<pair<int, int>> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			temp[i][j] = lab[i][j];
			if (temp[i][j] == 2)
				q.push({ i,j });
		}
	}
	pair<int, int> cur;
	int next_i, next_j;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			next_i = cur.first + di[k];
			next_j = cur.second + dj[k];
			if (next_i < 1 || next_i > n || next_j < 1 || next_j > m)
				continue;
			if (temp[next_i][next_j] == 0) {
				temp[next_i][next_j] = 2;
				q.push({ next_i, next_j });
			}
		}
	}
	int result = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (temp[i][j] == 0)
				result++;
	return result;
	
}

void Brute(int k, int cur) {
	if (k == 3) {
		int result = BFS();
		maximum = max(maximum, result);
		return;
	}
	pair<int, int> position;
	for (int i = cur; i < vsz; i++) {
		position = blank[i];
		lab[position.first][position.second] = 1;
		Brute(k + 1, i + 1);
		lab[position.first][position.second] = 0;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> lab[i][j];
			if (lab[i][j] == 0)
				blank.push_back({ i,j });
		}
	}
	vsz = blank.size();
	Brute(0, 0);
	cout << maximum;
	return 0;
}