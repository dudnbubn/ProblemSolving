#include <iostream>
#include <queue>
using namespace std;

bool visited[1000001] = { 0, };

int main() {
	queue<int> q;
	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;
	int dh[2] = { u, (-1 * d) };

	q.push(s);
	visited[s] = true;
	int cur, next, qsz, move = -1;
	while (!q.empty()) {
		move++;
		qsz = q.size();
		for (int i = 0; i < qsz; i++) {
			cur = q.front();
			if (cur == g) {
				cout << move;
				return 0;
			}
			q.pop();
			for (int j = 0; j < 2; j++) {
				next = cur + dh[j];
				if (next < 1 || next > f)	continue;
				if (!visited[next]) {
					visited[next] = true;
					q.push(next);
				}
			}
			
		}
	}
	cout << "use the stairs";
	return 0;
}