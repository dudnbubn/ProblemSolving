#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 2e9
typedef pair<pair<int, int>, int> Edge;
int dist[501];

bool BellmanFord(int N, const vector<Edge>& edges) {
	for (int i = 1; i <= N; i++)	dist[i] = INF;
	dist[1] = 0;

	int S, E, T;
	for (int k = 1; k <= N - 1; k++) {
		for (Edge edge : edges) {
			S = edge.first.first;
			E = edge.first.second;
			T = edge.second;
			
			dist[E] = min(dist[E], dist[S] + T);
		}
	}
	for (Edge edge : edges) {
		S = edge.first.first;
		E = edge.first.second;
		T = edge.second;

		if (dist[E] > dist[S] + T)
			return true;
	}
	return false;
}

int main() {
	int TC;
	cin >> TC;

	int N, M, W, S, E, T;
	vector<Edge> edges;
	for (int tc = 1; tc <= TC; tc++) {
		edges = {};
		cin >> N >> M >> W;

		for (int i = 1; i <= M; i++) {
			cin >> S >> E >> T;
			edges.push_back({ {S, E}, T });
			edges.push_back({ {E, S}, T });
		}
		for (int i = 1; i <= W; i++) {
			cin >> S >> E >> T;
			edges.push_back({ {S, E}, -T });
		}

		if (BellmanFord(N, edges))	cout << "YES\n";
		else	cout << "NO\n";
	}
	return 0;
}