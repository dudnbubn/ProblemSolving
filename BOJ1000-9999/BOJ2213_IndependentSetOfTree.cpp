#include <iostream>
#include <vector>

using namespace std;

#define SELECTED 2
#define NOT_SELECTED 1

int N;
int weights[10001];
int dp[10001][2];
bool visited[10001];
vector<int> adjacent_nodes_of[10001];
int is_selected[10001];	// 2 : selected, 1 : not selected

void DFS(int current) {
	visited[current] = true;

	for (int adjacent_node : adjacent_nodes_of[current]) {
		if (visited[adjacent_node])	continue;
		DFS(adjacent_node);
		dp[current][0] += dp[adjacent_node][1];
		dp[current][1] += max(dp[adjacent_node][0], dp[adjacent_node][1]);
	}
}

void select(int current) {
	if (is_selected[current]) {
		for (int adjacent_node : adjacent_nodes_of[current]) {
			if (is_selected[adjacent_node])	continue;
			select(adjacent_node);
		}
	}
	else {
		if (dp[current][0] > dp[current][1]) {
			is_selected[current] = SELECTED;
			for (int adjacent_node : adjacent_nodes_of[current]) {
				if (is_selected[adjacent_node])	continue;
				is_selected[adjacent_node] = NOT_SELECTED;
				select(adjacent_node);
			}
		}
		else {
			is_selected[current] = NOT_SELECTED;
			for (int adjacent_node : adjacent_nodes_of[current]) {
				if (is_selected[adjacent_node])	continue;
				select(adjacent_node);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> weights[i];
		dp[i][0] = weights[i];
	}
	int a, b;
	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		adjacent_nodes_of[a].push_back(b);
		adjacent_nodes_of[b].push_back(a);
	}

	DFS(1);
	select(1);

	cout << max(dp[1][0], dp[1][1]) << "\n";
	for (int i = 1; i <= N; i++)
		if (is_selected[i] == SELECTED)
			cout << i << " ";
	return 0;
}