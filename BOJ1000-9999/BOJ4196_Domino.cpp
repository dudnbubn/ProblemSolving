#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_N 100'000

int in_degree[MAX_N + 1];
vector<int> next_nodes_of[MAX_N + 1];
queue<int> q;
int index_of[MAX_N + 1];

void init(int N) {
	q = {};

	for (int i = 1; i <= N; i++) {
		in_degree[i] = 0;
		next_nodes_of[i] = {};
		index_of[i] = MAX_N;
	}
}

bool topological_sort(int index) {
	bool result = true;

	int current;
	while (!q.empty()) {
		current = q.front();
		q.pop();
		
		index_of[current] = index;
		
		for (int next_node : next_nodes_of[current]) {
			if (index_of[next_node] < index)	result = false;
			if (!in_degree[next_node])	continue;
			in_degree[next_node] = 0;
			q.push(next_node);
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int TC;
	cin >> TC;

	int N, M;
	while (TC--) {
		cin >> N >> M;
		init(N);

		int x, y;
		for (int i = 0; i < M; i++) {
			cin >> x >> y;
			next_nodes_of[x].push_back(y);
			in_degree[y]++;
		}
;
		for (int i = 1; i <= N; i++) {
			if (in_degree[i])	continue;
			q.push(i);
		}

		int result = q.size();
		topological_sort(MAX_N);

		int index = 0;
		for (int i = 1; i <= N; i++) {
			if (!in_degree[i])	continue;
			in_degree[i] = 0;
			q.push(i);
			if(topological_sort(++index))
				result++;
		}
		cout << result << "\n";
	}
	return 0;
}