#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int root[1001];
char gender[1001];

typedef pair<int, pair<int, int>> info;
priority_queue<info, vector<info>, greater<info>> pq;

int Find(int x) {
	if (x == root[x])	return x;
	return root[x] = Find(root[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	root[y] = x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> gender[i];
		root[i] = i;
	}
	int u, v, d;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> d;
		if (gender[u] != gender[v])	pq.push({ d, {u, v} });
	}
	int cnt = 0, result = 0;
	info cur;
	while (!pq.empty() && cnt < n) {
		cur = pq.top();
		pq.pop();
		while (!pq.empty() && Find(cur.second.first) == Find(cur.second.second)) {
			cur = pq.top();
			pq.pop();
		}
		if (Find(cur.second.first) == Find(cur.second.second)) break;
		result += cur.first;
		cnt++;
		Union(cur.second.first, cur.second.second);
	}
	if (cnt == n - 1)	cout << result;
	else	cout << -1;
	return 0;
}