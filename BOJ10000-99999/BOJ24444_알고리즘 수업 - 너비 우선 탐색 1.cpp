#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 100'000

vector<int> next_nodes_of[MAX_N + 1];
int index_of[MAX_N + 1];

queue<int> q;

void BFS(int start) {
	int index = 1;

	q.push(start);
	index_of[start] = index;

	int current;
	while (!q.empty()) {
		current = q.front();
		q.pop();

		for (int next_node : next_nodes_of[current]) {
			if (index_of[next_node])	continue;
			index_of[next_node] = ++index;
			q.push(next_node);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M, R;
	cin >> N >> M >> R;

	int u, v;
	for (int m = 0; m < M; m++) {
		cin >> u >> v;
		next_nodes_of[u].push_back(v);
		next_nodes_of[v].push_back(u);
	}
	for (int n = 1; n <= N; n++)
		sort(next_nodes_of[n].begin(), next_nodes_of[n].end());

	BFS(R);
	for (int n = 1; n <= N; n++)
		cout << index_of[n] << "\n";

	return 0;
}