// Dijkstra Algorithm

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 2100000000;

int n, m, k, u, v, w;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;	// weight, number
int status[20001];
vector<pair<int, int>> edges[20001];
int result[20001];

void Dijkstra(int start) {
	for (int i = 1; i <= n; i++) {
		result[i] = -1;
		status[i] = 0;
	}
	int tree_cnt = 1;
	result[start] = 0;
	status[start] = 2;
	for (int i = 0; i < edges[start].size(); i++) {
		status[edges[start][i].second] = 1;
		pq.push(edges[start][i]);
	}
	pair<int, int> cur, next;
	while (tree_cnt < n && !pq.empty()) {
		cur = pq.top();
		pq.pop();
		while (status[cur.second] == 2) {
			if (pq.empty())	return;
			cur = pq.top();
			pq.pop();
		}
		result[cur.second] = cur.first;
		status[cur.second] = 2;
		for (int i = 0; i < edges[cur.second].size(); i++) {
			next = edges[cur.second][i];
			if (status[next.second] <= 1) {
				status[next.second] = 1;
				pq.push({ next.first + cur.first,next.second });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		edges[u].push_back({ w, v });
	}
	Dijkstra(k);
	for (int i = 1; i <= n; i++)
		if (result[i] == -1)	cout << "INF\n";
		else	cout << result[i] << "\n";
	return 0;
}