#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<pair<int, int>> dist[1001];
bool visited[1001];

int BFS(int start, int end) {
	for (int i = 1; i <= n; i++)	visited[i] = false;
	queue<pair<int, int>> q;
	q.push({ start, 0 });
	visited[start] = true;

	pair<int, int> cur, next;
	while (!q.empty()) {
		cur = q.front();
		q.pop();

		if (cur.first == end)
			return cur.second;

		for (int i = 0; i < dist[cur.first].size(); i++) {
			next = dist[cur.first][i];
			if (!visited[next.first]) {
				visited[next.first] = true;
				q.push({ next.first, cur.second + next.second });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	int a, b, c;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		dist[a].push_back({ b, c });
		dist[b].push_back({ a,c });
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << BFS(a, b) << "\n";
	}
	return 0;
}