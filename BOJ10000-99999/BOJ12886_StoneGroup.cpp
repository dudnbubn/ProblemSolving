// BFS

#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

set<vector<int>> s;
queue<vector<int>> q;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if ((a + b + c) % 3 == 0) {
		vector<int> v(3);
		v[0] = a;
		v[1] = b;
		v[2] = c;
		sort(v.begin(), v.end());
		s.insert(v);
		q.push(v);
		vector<int> cur(3);
		vector<int> next(3);
		while (!q.empty()) {
			cur = q.front();
			q.pop();
			if (cur[0] == cur[2]) {
				cout << 1;
				return 0;
			}
			if (cur[0] != cur[1]) {
				next[0] = cur[0] * 2;
				next[1] = cur[1] - cur[0];
				next[2] = cur[2];
				sort(next.begin(), next.end());
				if (s.find(next) == s.end()) {
					s.insert(next);
					q.push(next);
				}
			}
			if (cur[1] != cur[2]) {
				next[0] = cur[0];
				next[1] = cur[1] * 2;
				next[2] = cur[2] - cur[1];
				sort(next.begin(), next.end());
				if (s.find(next) == s.end()) {
					s.insert(next);
					q.push(next);
				}
			}
			if (cur[0] != cur[2]) {
				next[0] = cur[0] * 2;
				next[1] = cur[1];
				next[2] = cur[2] - cur[0];
				sort(next.begin(), next.end());
				if (s.find(next) == s.end()) {
					s.insert(next);
					q.push(next);
				}
			}
		}
		cout << 0;
	}
	else
		cout << 0;

	return 0;
}