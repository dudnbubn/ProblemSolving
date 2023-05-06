#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 200
#define MAX_M 200

int shirts[MAX_N + 1];
int collars[MAX_M + 1];

vector<int> linked_nodes[MAX_N + 1];
bool is_visited[MAX_N + 1];
int owner[MAX_M + 1];

bool is_linked(int i, int j) {
	if (shirts[j] / 2 <= collars[i] && collars[i] <= shirts[j] * 3 / 4)	return true;
	if (shirts[j] <= collars[i] && collars[i] <= shirts[j] * 5 / 4)	return true;
	return false;
}

bool DFS(int current) {
	if (is_visited[current])	return false;
	is_visited[current] = true;

	for (int linked_node : linked_nodes[current]) {
		if (!owner[linked_node] || DFS(owner[linked_node])) {
			owner[linked_node] = current;
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> shirts[i];
		shirts[i] *= 4;
	}
	for (int i = 1; i <= M; i++) {
		cin >> collars[i];
		collars[i] *= 4;
		for (int j = 1; j <= N; j++) {
			if (is_linked(i, j))	linked_nodes[j].push_back(i);
		}
	}

	int result = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)	is_visited[j] = false;
		if (DFS(i))	result++;
	}
	cout << result;
	return 0;
}