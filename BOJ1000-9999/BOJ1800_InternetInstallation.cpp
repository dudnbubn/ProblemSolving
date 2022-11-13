#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<pair<int, int>, int> Info;	// 제일비싼거, 공짜, 번호

int N, P, K;
bool visited[1001][1001];
vector<pair<int, int>> adj_list[1001];
priority_queue<Info, vector<Info>, greater<Info>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> P >> K;
	
	int a, b, c;
	for (int i = 0; i < P; i++) {
		cin >> a >> b >> c;
		adj_list[a].push_back({ c, b });
		adj_list[b].push_back({ c, a });
	}

	pq.push({ {0, 0}, 1 });

	Info cur;
	int most_expensive, free, number;
	int result = -1;
	while (!pq.empty()) {
		cur = pq.top();
		pq.pop();
		most_expensive = cur.first.first;
		free = cur.first.second;
		number = cur.second;

		if (visited[number][free])	continue;

		visited[number][free] = true;
		if (number == N) {
			result = most_expensive;
			break;
		}
		
		for (pair<int, int> adj : adj_list[number]) {
			if (!visited[adj.second][free])
				pq.push({ {max(most_expensive, adj.first), free}, adj.second });
			if(free < K && !visited[adj.second][free+1])
				pq.push({ {most_expensive, free + 1}, adj.second });
		}
	}

	cout << result;
	return 0;
}