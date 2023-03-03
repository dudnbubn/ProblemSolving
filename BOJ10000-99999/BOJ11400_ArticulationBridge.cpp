#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V, E;
int order_index;
int order[100001];
vector<int> next_nodes_of[100001];
vector<pair<int, int>> results;

int DFS(int current, int parent) {
	order[current] = ++order_index;
	
	int result = order[current];

	for (int next_node : next_nodes_of[current]) {
		if (next_node == parent)	continue;
		if (order[next_node]) {
			result = result < order[next_node] ? result : order[next_node];
			continue;
		}

		int dfs = DFS(next_node, current);
		if (dfs > order[current]) {
			int first = current < next_node ? current : next_node;
			int second = current > next_node ? current : next_node;
			results.push_back({ first, second });
		}

		result = result < dfs ? result : dfs;
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> V >> E;
	
	int a, b;
	for (int e = 0; e < E; e++) {
		cin >> a >> b;
		next_nodes_of[a].push_back(b);
		next_nodes_of[b].push_back(a);
	}

	for (int v = 1; v <= V; v++) {
		if (order[v])	continue;
		DFS(v, 0);
	}

	sort(results.begin(), results.end());

	cout << results.size() << "\n";
	for (pair<int, int> result : results) {
		cout << result.first << " " << result.second << "\n";
	}
	return 0;
}