#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

#define INF 2'000'000'000

typedef pair<pair<int, int>, int> TimeCostNode;

int N, M, K, result;
int dp[101][10001];	// 노드, 요금에 대한 시간 저장
vector<TimeCostNode> next_nodes_of[101];
priority_queue<TimeCostNode, vector<TimeCostNode>, greater<TimeCostNode>> p_queue;

void init() {
	for (int i = 1; i <= 100; i++) {
		next_nodes_of[i] = {};
		for (int j = 0; j <= 10000; j++)
			dp[i][j] = INF;
	}
	result = INF;
	p_queue = {};
}

void Dijkstra() {
	int limit = M, destination = N;
	p_queue.push({ {0,0},1 });

	TimeCostNode current;
	int time, cost, node;
	int next_time, next_cost, next_number;
	while (!p_queue.empty()) {
		current = p_queue.top();
		p_queue.pop();

		time = current.first.first;
		cost = current.first.second;
		node = current.second;

		if (dp[node][cost] < time)	continue;

		dp[node][cost] = time;

		for (TimeCostNode next_node : next_nodes_of[node]) {
			next_time = next_node.first.first + time;
			next_cost = next_node.first.second + cost;
			next_number = next_node.second;

			if ((next_cost > limit) || dp[next_number][next_cost] <= next_time)
				continue;
			dp[next_number][next_cost] = next_time;
			
			p_queue.push({ {next_time, next_cost}, next_number });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int TC;
	cin >> TC;

	int u, v, c, d;
	while (TC--) {
		init();
		cin >> N >> M >> K;
		for (int k = 0; k < K; k++) {
			cin >> u >> v >> c >> d;
			next_nodes_of[u].push_back({ {d, c}, v });
		}

		Dijkstra();

		int result = INF;
		for (int i = 0; i <= M; i++)
			result = min(result, dp[N][i]);

		if (result == INF)
			cout << "Poor KCM\n";
		else
			cout << result << "\n";
	}
	return 0;
}