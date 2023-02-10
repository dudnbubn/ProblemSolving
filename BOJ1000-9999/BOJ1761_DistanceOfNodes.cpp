#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<pair<int, int>> adj_list[40001];
pair<int, int> parents[40001][20];
int depths[40001];

void DFS(int node, int depth) {
	depths[node] = depth;

	for (pair<int, int> adj : adj_list[node]) {
		if (depths[adj.first])	continue;
		parents[adj.first][0] = { node, adj.second };
		DFS(adj.first, depth + 1);
	}
}

void set_parents() {
	for (int j = 1; j < 20; j++) {
		for (int i = 1; i <= N; i++) {
			parents[i][j].first = parents[parents[i][j - 1].first][j - 1].first;
			parents[i][j].second = parents[parents[i][j - 1].first][j - 1].second + parents[i][j - 1].second;
		}
	}
}

int lca(int x, int y) {
	int result = 0;
	// x의 depth가 더 크면 x가 y보다 루트랑 가깝도록 스왑
	if (depths[x] > depths[y])
		swap(x, y);

	for (int i = 19; i >= 0; i--) {
		if (depths[y] - depths[x] >= (1 << i)) {
			result += parents[y][i].second;
			y = parents[y][i].first;
		}
	}
	if (x == y)	return result;
	for (int i = 19; i >= 0; i--) {
		if (parents[x][i].first != parents[y][i].first) {
			result += (parents[x][i].second + parents[y][i].second);
			x = parents[x][i].first;
			y = parents[y][i].first;

		}
	}
	result += parents[x][0].second + parents[y][0].second;
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	int a, b, c;
	for (int i = 1; i < N; i++) {
		cin >> a >> b >> c;
		adj_list[a].push_back({ b,c });
		adj_list[b].push_back({ a,c });
	}
	DFS(1, 1);

	set_parents();

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		cout << lca(a, b) << "\n";
	}
}