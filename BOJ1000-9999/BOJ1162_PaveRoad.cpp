#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX_N 10000
#define MAX_M 50000
#define MAX_K 20

int N, M, K;
vector<pair<int, int>> next_nodes_of[MAX_N + 1];
bool is_visited[MAX_N + 1][MAX_K + 1];

typedef pair<long long, pair<int, int>> Node;

priority_queue<Node, vector<Node>, greater<Node>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;

	int a, b, c;
	for (int m = 0; m < M; m++) {
		cin >> a >> b >> c;
		next_nodes_of[a].push_back({ b,c });
		next_nodes_of[b].push_back({ a,c });
	}

	pq.push({ 0, {1, 0} });

	Node current;
	long long time;
	int number, pave;
	int next_number, next_time;

	long long result = 50'000'000'000;

	while (!pq.empty()) {
		current = pq.top();
		pq.pop();

		time = current.first;
		number = current.second.first;
		pave = current.second.second;


		if (is_visited[number][pave])	continue;
		is_visited[number][pave] = true;

		if (number == N) {
			result = result < time ? result : time;
			continue;
		}

		for (pair<int, int> next_node : next_nodes_of[number]) {
			next_number = next_node.first;
			next_time = next_node.second;
			if (pave < K && !is_visited[next_number][pave + 1]) {
				
				pq.push({ time, {next_number, pave + 1} });
			}
			if (!is_visited[next_number][pave])
				pq.push({ time + next_time, {next_number, pave} });
		}
	}
	

	cout << result;
	return 0;
}