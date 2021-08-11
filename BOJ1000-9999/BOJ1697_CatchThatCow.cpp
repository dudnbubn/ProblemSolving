#include <iostream>
#include <queue>
using namespace std;

bool visited[100001] = { 0, };

int main() {
	int n, k;
	cin >> n >> k;
	int sec = 0;
	if (n == k) {
		cout << sec;
		return 0;
	}
	queue<int> q;
	q.push(n);
	visited[n] = true;
	while (!q.empty()) {
		sec++;
		int qsz = q.size();
		for (int i = 0; i < qsz; i++) {
			int cur = q.front();
			q.pop();
			if (cur + 1 == k || cur - 1 == k || 2 * cur == k) {
				cout << sec;
				return 0;
			}
			if (cur + 1 <= 100000 && !visited[cur + 1]) {
				q.push(cur + 1);
				visited[cur + 1] = true;
			}
			if (cur - 1 >= 0 && !visited[cur - 1]) {
				q.push(cur - 1);
				visited[cur - 1] = true;
			}
			if (2 * cur <= 100000 && !visited[cur * 2]) {
				q.push(2 * cur);
				visited[2 * cur] = true;
			}
		}
	}
	return 0;
}