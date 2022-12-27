#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> adj_list[1000001];

pair<int, int> DFS(int cur, int prev) {
	int fir = 1, sec = 0;

	pair<int, int> dfs;

	for (int adj : adj_list[cur]) {
		if (adj == prev)	continue;
		dfs = DFS(adj, cur);
		fir += min(dfs.first, dfs.second);
		sec += dfs.first;
	}

	return { fir, sec };
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	int a, b;
	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}
	
	pair<int, int> result = DFS(1, 0);
	cout << (result.first < result.second ? result.first : result.second);
	return 0;
}