#include <iostream>
#include <queue>
using namespace std;

bool visited[100001] = { 0, };

int d[6] = { -1, 1, 0, 0, 0, 0 };

int main() {
	int a, b, n, m;
	cin >> a >> b >> n >> m;
	d[2] = (-1) * a;	d[3] = a;
	d[4] = (-1) * b;	d[5] = b;
	queue<int> q;
	q.push(n);
	visited[n] = true;
	int move = -1;
	while (!q.empty()) {
		move++;
		int qsz = q.size();
		for (int i = 0; i < qsz; i++) {
			int cur = q.front();
			if (cur == m) {
				cout << move;
				return 0;
			}
			q.pop();
			int next;
			for (int j = 0; j < 6; j++) {
				next = cur + d[j];
				if (next < 0 || next > 100000)	continue;
				if (!visited[next]) {
					visited[next] = true;
					q.push(next);
				}
			}
			next = cur * a;
			if ((0 <= next && next <= 100000) && !visited[next]) {
				visited[next] = true;
				q.push(next);
			}
			next = cur * b;
			if ((0 <= next && next <= 100000) && !visited[next]) {
				visited[next] = true;
				q.push(next);
			}
		}
	}
}