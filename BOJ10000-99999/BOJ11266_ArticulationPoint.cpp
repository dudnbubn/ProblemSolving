// key point : articulation point algorithm

#include <iostream>
#include <vector>

using namespace std;

int V, E;
vector<int> adj_list[10001];
int root;
int visited[10001];
int order;
int cut_count;
bool is_cut[10001];

int DFS(int current) {
	visited[current] = ++order;

	int result = visited[current];
	int child = 0;

	for (int adj : adj_list[current]) {
		if (visited[adj]) {
			result = result < visited[adj] ? result : visited[adj];
			continue;
		}
		child++;
		int dfs = DFS(adj);

		if ((current != root) && (dfs >= visited[current]))
			is_cut[current] = true;

		result = result < dfs ? result : dfs;
	}
	if ((current == root) && (child >= 2))
		is_cut[current] = true;

	return result;
}

int main() {
	cin >> V >> E;

	int a, b;
	for (int i = 0; i < E; i++) {
		cin >> a >> b;
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}

	for (int i = 1; i <= V; i++) {
		if (visited[i])	continue;
		root = i;
		DFS(i);
	}

	int result = 0;
	for (int i = 1; i <= V; i++)
		if (is_cut[i])
			result++;
	cout << result << "\n";
	for (int i = 1; i <= V; i++)
		if (is_cut[i])
			cout << i << " ";
	return 0;
}