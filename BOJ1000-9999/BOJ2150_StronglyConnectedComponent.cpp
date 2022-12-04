#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int V, E;
vector<int> adj_list[10001];
vector<int> reverse_adj_list[10001];
stack<int> post_order;
bool visited[10001];

vector<vector<int>> results;
vector<int> result;

bool compare(vector<int> a, vector<int> b) {
	return a[0] < b[0];
}

void connect_vertices(int from, int to) {
	adj_list[from].push_back(to);
	reverse_adj_list[to].push_back(from);
}

void post_order_traversal(int node) {
	visited[node] = true;

	for (int adj : adj_list[node]) {
		if (visited[adj])	continue;
		post_order_traversal(adj);
	}
	post_order.push(node);
}

void DFS(int node) {
	visited[node] = true;
	result.push_back(node);
	for (int reverse_adj : reverse_adj_list[node]) {
		if (visited[reverse_adj])	continue;
		DFS(reverse_adj);
	}
}

void reverse_traversal() {
	for (int v = 1; v <= V; v++)	visited[v] = false;

	while(!post_order.empty()){
		int top = post_order.top();
		post_order.pop();
		if (visited[top])	continue;
		DFS(top);
		sort(result.begin(), result.end());
		results.push_back(result);
		result = {};
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> V >> E;
	int from, to;
	for (int e = 0; e < E; e++) {
		cin >> from >> to;
		connect_vertices(from, to);
	}

	for (int v = 1; v <= V; v++) {
		if (visited[v])	continue;
		post_order_traversal(v);
	}
	reverse_traversal();
	sort(results.begin(), results.end(), compare);

	cout << results.size() << '\n';
	for (vector<int> res : results) {
		for (int node : res)
			cout << node << " ";
		cout << "-1\n";
	}

	return 0;
}