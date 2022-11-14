#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, D, E;
int height[100001];
bool visited[100001];
vector<pair<int, int>> adj_list[100001];

long long dist[100001][2];

typedef pair<long long, pair<int, int>> Info;	// 거리, 번호, 현재높이
priority_queue<Info, vector<Info>, greater<Info>> pq;
void Dijkstra(int start) {
	for (int i = 1; i <= N; i++)	visited[i] = false;
	int index = (start == 1) ? 0 : 1;
	pq = {};
	pq.push({ 0, {start, height[start]} });
	Info cur;
	long long weight;
	int number, h;
	while (!pq.empty()) {
		cur = pq.top();
		pq.pop();

		weight = cur.first;
		number = cur.second.first;
		h = cur.second.second;
		if (visited[number])	continue;

		visited[number] = true;
		dist[number][index] = weight;
		for (pair<int, int> adj : adj_list[number]) {
			if (visited[adj.second])	continue;
			if (height[number] < height[adj.second])
				pq.push({ weight + adj.first, {adj.second, height[adj.second] } });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> D >> E;
	for (int i = 1; i <= N; i++) {
		cin >> height[i];
		dist[i][0] = dist[i][1] = -1;
	}

	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		adj_list[a].push_back({ c, b });
		adj_list[b].push_back({ c, a });
	}

	Dijkstra(1);
	Dijkstra(N);

	long long result = -987654321987654321;
	for (int i = 2; i < N; i++) {
		long long toTarget = dist[i][0];
		long long toN = dist[i][1];
		if (toTarget == -1 || toN == -1)	continue;
		long long temp = (long long)height[i] * E - ((long long)toTarget + toN) * D;
		result = result > temp ? result : temp;
	}

	if (result == -987654321987654321)	cout << "Impossible";
	else	cout << result;
	return 0;
}