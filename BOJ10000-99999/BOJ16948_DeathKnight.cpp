// BFS
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n;
bool visited[201][201] = { 0, };
int di[6] = { -2,-2,0,0,2,2 };
int dj[6] = { -1,1,-2,2,-1,1 };
queue<pair<int, int>> q;

int main() {
	cin >> n;
	pair<int, int> start, end;
	cin >> start.first >> start.second;
	cin >> end.first >> end.second;
	q.push(start);
	visited[start.first][start.second] = true;
	int move = -1;
	while (!q.empty()) {
		move++;
		int qsz = q.size();
		for (int i = 0; i < qsz; i++) {
			pair<int, int> cur = q.front();
			q.pop();
			for (int k = 0; k < 6; k++) {
				int temp_i = cur.first + di[k];
				int temp_j = cur.second + dj[k];
				if (temp_i < 0 || temp_j < 0 || temp_i >= n || temp_j >= n)
					continue;
				if (cur == end) {
					cout << move;
					return 0;
				}
				if (!visited[temp_i][temp_j]) {
					visited[temp_i][temp_j] = true;
					q.push({ temp_i, temp_j });
				}
			}
		}
	}
	cout << -1;
	return 0;
}