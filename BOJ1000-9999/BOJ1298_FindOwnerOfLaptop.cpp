#include <iostream>
#include <vector>

using namespace std;

int N, M;
int owner_of[101];
bool is_visited[101];
vector<int> next_nodes_of[101];

bool binary_matching(int current) {
	if (is_visited[current])	return false;
	is_visited[current] = true;

	for (int next_node : next_nodes_of[current]) {
		if (!owner_of[next_node] || binary_matching(owner_of[next_node])) {
			owner_of[next_node] = current;
			return true;
		}
	}
	return false;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	int a, b;
	for (int m = 0; m < M; m++) {
		cin >> a >> b;
		next_nodes_of[a].push_back(b);
	}

	int result = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)	is_visited[j] = false;
		if (binary_matching(i))	result++;
	}
	cout << result;
	return 0;

}