#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int result[50001];
bool visited[50001];

typedef pair<int, int> Edge;
vector<Edge> adj_list[50001];
priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

int main() {
	cin >> N >> M;

	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		adj_list[a].push_back({ c, b });
		adj_list[b].push_back({ c, a });
	}

	pq.push({ 0, 1 });

	Edge cur;
	int weight, node;
	while (!pq.empty()) {
		cur = pq.top();
		pq.pop();

		weight = cur.first;
		node = cur.second;
		if (visited[node])	continue;

		visited[node] = true;
		result[node] = weight;
		cout << "result[" << node << "] = " << weight << "\n";

		for (Edge e : adj_list[node]) {
			if (visited[e.second])	continue;
			pq.push({ weight + e.first, e.second });
		}
	}

	cout << result[N];
	return 0;
}