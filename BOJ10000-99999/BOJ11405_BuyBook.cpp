#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_N 100
#define MAX_M 100
#define SOURCE 0
#define DESTINATION MAX_N + MAX_M + 1
#define INF 2'147'483'647

int N, M;
int capacities[DESTINATION + 1][DESTINATION + 1];
int flows[DESTINATION + 1][DESTINATION + 1];
int costs[DESTINATION + 1][DESTINATION + 1];
vector<int> adj_list[DESTINATION + 1];

queue<int> q;
bool in_queue[DESTINATION + 1];
int distances[DESTINATION + 1];
int prevs[DESTINATION + 1];

int MCMF() {
	int result = 0;

	int current;
	int from, to;
	while (true) {
		q = {};
		fill(in_queue, in_queue + DESTINATION + 1, false);
		fill(distances, distances + DESTINATION + 1, INF);
		fill(prevs, prevs + DESTINATION + 1, -1);

		q.push(SOURCE);
		in_queue[SOURCE] = true;
		distances[SOURCE] = 0;
		prevs[SOURCE] = SOURCE;

		while (!q.empty()) {
			from = q.front();
			q.pop();

			in_queue[from] = false;
			for(int to : adj_list[from]) {
				if (capacities[from][to] - flows[from][to] > 0 && distances[to] > distances[from] + costs[from][to]) {
					distances[to] = distances[from] + costs[from][to];
					prevs[to] = from;
					if (!in_queue[to]) {
						in_queue[to] = true;
						q.push(to);
					}
				}
			}
		}

		if (prevs[DESTINATION] == -1)	break;

		int flow = INF;
		for (to = DESTINATION; to != SOURCE; to = prevs[to]) {
			from = prevs[to];
			flow = min(flow, capacities[from][to] - flows[from][to]);
		}

		for (to = DESTINATION; to != SOURCE; to = prevs[to]) {
			from = prevs[to];
			result += flow * costs[from][to];
			
			flows[from][to] += flow;
			flows[to][from] -= flow;
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	for (int n = 1; n <= N; n++) {
		cin >> capacities[SOURCE][n];
		adj_list[SOURCE].push_back(n);
		adj_list[n].push_back(SOURCE);
	}

	for (int m = 1; m <= M; m++) {
		cin >> capacities[m + MAX_N][DESTINATION];
		adj_list[m + MAX_N].push_back(DESTINATION);
		adj_list[DESTINATION].push_back(m + MAX_N);
	}

	for (int m = 1; m <= M; m++) {
		for (int n = 1; n <= N; n++) {
			cin >> costs[n][m + MAX_N];
			costs[m + MAX_N][n] = -costs[n][m + MAX_N];
			capacities[n][m + MAX_N] = INF;
			adj_list[n].push_back(m + MAX_N);
			adj_list[m + MAX_N].push_back(n);
		}
	}

	cout << MCMF();
	return 0;
}