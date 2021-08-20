// BFS
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int snake[100] = { 0, };
int ladder[100] = { 0, };
int minimum = 1000000000;
int visited[101] = { 0, };
queue<int> q;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		ladder[x] = y;
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		snake[x] = y;
	}
	int move = 0;
	q.push(1);
	while (!q.empty()) {
		move++;
		int qsz = q.size();
		for (int i = 0; i < qsz; i++) {
			int cur = q.front();
			if (ladder[cur] != 0) {
				cur = ladder[cur];
				visited[cur] = true;
			}
			if (snake[cur] != 0) {
				cur = snake[cur];
				visited[cur] = true;
			}
			q.pop();
			for (int j = 1; j <= 6; j++) {
				if (cur + j > 100)
					continue;
				if (cur + j == 100) {
					cout << move;
					return 0;
				}
				if (!visited[cur + j]) {
					visited[cur + j] = true;
					q.push(cur + j);
				}
			}
		}
	}
	return 0;
}