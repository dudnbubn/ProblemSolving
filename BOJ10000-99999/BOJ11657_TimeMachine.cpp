// key point : Bellman Ford & SPFA(Shortest Path Faster Algorithm)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 1000000000
typedef pair<int, int> pii;

long long dist[501];
vector<pii> adj_list[501];

int main() {
	int n, m;
	cin >> n >> m;
	
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		adj_list[a].push_back({ b,c });
	}

	fill(dist, dist + 501, INF);

	dist[1] = 0;
	pii next;
	bool cycle = false;

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (dist[i] == INF)	continue;
			for (int j = 0; j < adj_list[i].size(); j++) {
				next = adj_list[i][j];
				if (dist[next.first] > dist[i] + next.second) {
					dist[next.first] = dist[i] + next.second;
					if (k == n)
						cycle = true;
				}
			}
		}
	}

	if (cycle)	cout << -1;
	else {
		for (int i = 2; i <= n; i++)
			cout << (dist[i] != INF ? dist[i] : -1) << "\n";
	}
	return 0;
}