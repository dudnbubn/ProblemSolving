#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 100'000

vector<int> next_nodes_of[MAX_N + 1];
int index_of[MAX_N + 1];

int index = 0;

void DFS(int current) {
	index_of[current] = ++index;
	for (int next_node : next_nodes_of[current]) {
		if (index_of[next_node])	continue;
		DFS(next_node);
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
	
	for (int n = 1; n <= N; n++) {
		sort(next_nodes_of[n].begin(), next_nodes_of[n].end());
	}

	DFS(R);

	for (int n = 1; n <= N; n++)
		cout << index_of[n] << "\n";
	return 0;
}