#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX_N 400
#define MAX_M 400
#define SOURCE 0
#define DESTINATION MAX_N + MAX_M + 1
#define INF 2'147'483'647

int capacities[DESTINATION + 1][DESTINATION + 1];
int flows[DESTINATION + 1][DESTINATION + 1];
int costs[DESTINATION + 1][DESTINATION + 1];
vector<int> adj_list[DESTINATION + 1];

int prevs[DESTINATION + 1];
bool in_queue[DESTINATION + 1];
int distances[DESTINATION + 1];
queue<int> q;

pair<int, int> MCMF() {
	pair<int, int> result = { 0, 0 };

	while (true) {
		fill(distances, distances + DESTINATION + 1, INF);
		fill(prevs, prevs + DESTINATION + 1, -1);
		fill(in_queue, in_queue + DESTINATION + 1, false);

		q = {};

		q.push(SOURCE);
		prevs[SOURCE] = SOURCE;
		in_queue[SOURCE] = true;
		distances[SOURCE] = 0;

		int current;
		while (!q.empty()) {
			current = q.front();
			q.pop();

			in_queue[current] = false;
			for (int adj : adj_list[current]) {
				if (capacities[current][adj] - flows[current][adj] > 0 && distances[adj] > distances[current] + costs[current][adj]) {
					distances[adj] = distances[current] + costs[current][adj];
					prevs[adj] = current;
					if (!in_queue[adj]) {
						in_queue[adj] = true;
						q.push(adj);
					}
				}
			}
		}

		if (prevs[DESTINATION] == -1)	break;

		int flow = INF;
		int from, to;
		for (int pointer = DESTINATION; pointer != SOURCE; pointer = prevs[pointer]) {
			from = prevs[pointer];
			to = pointer;

			flow = min(flow, capacities[from][to] - flows[from][to]);
		}

		for (int pointer = DESTINATION; pointer != SOURCE; pointer = prevs[pointer]) {
			from = prevs[pointer];
			to = pointer;

			result.second += flow * costs[from][to];
			flows[from][to] += flow;
			flows[to][from] -= flow;
		}

		result.first++;
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	for (int n = 1; n <= N; n++) {
		capacities[SOURCE][n] = 1;
		adj_list[SOURCE].push_back(n);
		adj_list[n].push_back(SOURCE);
	}
	for (int m = 1; m <= M; m++) {
		capacities[MAX_N + m][DESTINATION] = 1;
		adj_list[MAX_N + m].push_back(DESTINATION);
		adj_list[DESTINATION].push_back(MAX_N + m);
	}

	for (int n = 1; n <= N; n++) 
		for (int m = 1; m <= M; m++) 
			costs[n][m + MAX_N] = INF;

	int E, to, pay;
	for (int from = 1; from <= N; from++) {
		cin >> E;
		for (int e = 0; e < E; e++) {
			cin >> to >> pay;
			costs[from][to + MAX_N] = pay;
			costs[to + MAX_N][from] = -pay;
			adj_list[from].push_back(to + MAX_N);
			adj_list[to + MAX_N].push_back(from);
			capacities[from][to + MAX_N] = 1;
		}
	}

	pair<int, int> result = MCMF();
	cout << result.first << "\n" << result.second;
	return 0;
}