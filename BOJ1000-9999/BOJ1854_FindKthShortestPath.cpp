#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, K;
int counts[1001];
int results[1001];
vector<pair<int, int>> adj_list[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)	counts[i] = K;

	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		adj_list[a].push_back({ c, b });
	}
	
	pq.push({ 0, 1 });

	pair<int, int> current;
	int weight, number;
	while (!pq.empty()) {
		current = pq.top();
		pq.pop();

		weight = current.first;
		number = current.second;
		if (!counts[number])	continue;

		counts[number]--;
		if (!counts[number])	results[number] = weight;

		for (pair<int, int> adj : adj_list[number]) {
			if (!counts[adj.second])	continue;
			pq.push({ weight + adj.first, adj.second });
		}
	}

	for (int i = 1; i <= N; i++) {
		if (counts[i])	cout << -1 << "\n";
		else	cout << results[i] << "\n";
	}
	return 0;
}