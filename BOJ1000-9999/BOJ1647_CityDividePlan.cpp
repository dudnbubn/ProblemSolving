// kruskal's algorithm - Minimum Spanning Tree

#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, pair<int, int>> edge;

priority_queue<edge, vector<edge>, greater<edge>> pq;

int root[100001];

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
	cin.tie(NULL);

	int n, m;
	int a, b, c;

	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		root[i] = i;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		pq.push({ c, {a,b} });
	}

	edge e;
	int weight = 0;
	for (int i = 0; i < n - 1; i++) {
		e = pq.top();
		pq.pop();
		while (Find(e.second.first) == Find(e.second.second)) {
			e = pq.top();
			pq.pop();
		}
		Union(e.second.first, e.second.second);
		weight += e.first;
	}
	cout << weight - e.first;
	return 0;
}