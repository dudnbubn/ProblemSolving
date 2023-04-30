#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 30'000

int N, M;
int depths[MAX_N + 1];
vector<int> next_nodes_of[MAX_N + 1];
bool is_visited[MAX_N + 1];
int parents[16][MAX_N + 1];

void DFS(int current, int depth) {
	is_visited[current] = true;
	depths[current] = depth;
	
	for (int next_node : next_nodes_of[current]) {
		if (is_visited[next_node])	continue;
		
		parents[0][next_node] = current;
		DFS(next_node, depth + 1);
	}
}

void set_parents() {
	for (int i = 1; i < 16; i++) {
		for (int j = 1; j <= N; j++) {
			parents[i][j] = parents[i - 1][parents[i - 1][j]];
		}
	}
}

int get_distance(int x, int y) {
	int result = 0;

	if (depths[x] > depths[y]) {
		int temp = x;
		x = y;
		y = temp;
	}
	for (int i = 15; i >= 0; i--) {
		if (depths[y] - depths[x] >= (1 << i)) {
			result += (1 << i);
			y = parents[i][y];
		}
	}

	if (x == y) {
		return result;
	}

	for (int i = 15; i >= 0; i--) {
		if (parents[i][x] != parents[i][y]) {
			result += (1 << (i + 1));
			x = parents[i][x];
			y = parents[i][y];
		}
	}
	return result + 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	int from, to;
	for (int i = 1; i < N; i++) {
		cin >> from >> to;
		next_nodes_of[from].push_back(to);
		next_nodes_of[to].push_back(from);
	}
	DFS(1, 0);
	set_parents();

	cin >> M;
	int current = 1, next;
	int result = 0;
	for (int i = 0; i < M; i++) {
		cin >> next;
		result += get_distance(current, next);
		current = next;
	}
	cout << result;
	return 0;
}