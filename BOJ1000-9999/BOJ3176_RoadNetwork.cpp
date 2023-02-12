#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
int parents[100001][20][3];
int depths[100001];
vector<pair<int, int>> adj_list[100001];

#define MAX 1'000'000

void DFS(int current, int depth) {
	depths[current] = depth;

	for (pair<int, int> adj : adj_list[current]) {
		if (depths[adj.first])	continue;
		parents[adj.first][0][0] = current;
		parents[adj.first][0][1] = adj.second;
		parents[adj.first][0][2] = adj.second;

		DFS(adj.first, depth + 1);
	}
}

void set_parents() {
	for (int j = 1; j < 20; j++) {
		for (int i = 1; i <= N; i++) {
			parents[i][j][0] = parents[parents[i][j - 1][0]][j - 1][0];
			parents[i][j][1] = min(parents[i][j - 1][1], parents[parents[i][j - 1][0]][j - 1][1]);
			parents[i][j][2] = max(parents[i][j - 1][2], parents[parents[i][j - 1][0]][j - 1][2]);
		}
	}
}

pair<int, int> get_min_max_distance(int x, int y) {
	pair<int, int> result = { MAX, 0 };

	if (depths[x] > depths[y]) {
		swap(x, y);
	}
	
	for (int i = 19; i >= 0; i--) {
		if (depths[y] - depths[x] >= (1 << i)) {
			result.first = min(result.first, parents[y][i][1]);
			result.second = max(result.second, parents[y][i][2]);
			y = parents[y][i][0];
		}
	}

	if (x == y)	return result;

	for (int i = 19; i >= 0; i--) {
		if (parents[x][i][0] != parents[y][i][0]) {
			result.first = min(result.first, parents[x][i][1]);
			result.second = max(result.second, parents[x][i][2]);
			x = parents[x][i][0];
			result.first = min(result.first, parents[y][i][1]);
			result.second = max(result.second, parents[y][i][2]);
			y = parents[y][i][0];
		}
	}

	result.first = min(result.first, parents[x][0][1]);
	result.second = max(result.second, parents[x][0][2]);
	result.first = min(result.first, parents[y][0][1]);
	result.second = max(result.second, parents[y][0][2]);
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
	
	cin >> K;
	pair<int, int> min_max_distance;
	for (int i = 0; i < K; i++) {
		cin >> a >> b;
		
		min_max_distance = get_min_max_distance(a, b);
		cout << min_max_distance.first << " " << min_max_distance.second << "\n";
	}
	return 0;

}