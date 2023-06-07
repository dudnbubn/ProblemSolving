#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX_V 1000
#define INF 2'147'483'647

int capacities[(MAX_V + 1) * 2][(MAX_V + 1) * 2];
int flows[(MAX_V + 1) * 2][(MAX_V + 1) * 2];
int costs[(MAX_V + 1) * 2][(MAX_V + 1) * 2];

vector<int> adj_list[(MAX_V + 1) * 2];

int distances[(MAX_V + 1) * 2];
bool in_queue[(MAX_V + 1) * 2];
int prevs[(MAX_V + 1) * 2];

queue<int> q;

void init() {
	for (int i = 0; i < (MAX_V + 1) * 2; i++) {
		for (int j = 0; j < (MAX_V + 1) * 2; j++) {
			capacities[i][j] = 0;
			flows[i][j] = 0;
			costs[i][j] = 0;
		}
		adj_list[i] = {};
	}
}

int MCMF(int source, int destination) {
	int result = 0;
	for (int i = 0; i < 2; i++) {
		fill(distances, distances + (MAX_V + 1) * 2, INF);
		fill(in_queue, in_queue + (MAX_V + 1) * 2, false);
		fill(prevs, prevs + (MAX_V + 1) * 2, -1);
		
		q = {};
		prevs[source] = source;
		distances[source] = 0;
		in_queue[source] = true;
		q.push(source);

		int from;
		while (!q.empty()) {
			from = q.front();
			q.pop();

			in_queue[from] = false;
			for (int to : adj_list[from]) {
				if (capacities[from][to] > flows[from][to] && distances[to] > distances[from] + costs[from][to]) {
					distances[to] = distances[from] + costs[from][to];
					prevs[to] = from;
					if (!in_queue[to]) {
						in_queue[to] = true;
						q.push(to);
					}
				}
			}
		}
		if (prevs[destination] == -1)	break;
		int flow = INF;
		for (int to = destination; to != source; to = prevs[to]) {
			from = prevs[to];
			flow = min(flow, capacities[from][to] - flows[from][to]);
		}
		for (int to = destination; to != source; to = prevs[to]) {
			from = prevs[to];
			result += costs[from][to];
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

	int V, E;
	while (true) {
		cin >> V >> E;
		if (cin.eof() == true)	break;

		init();
		int from, to, weight;
		int from_in, from_out, to_in, to_out;

		for (int v = 1; v <= V; v++) {
			capacities[v * 2][v * 2 + 1] = 1;
			adj_list[v * 2].push_back(v * 2 + 1);
		}

		for (int e = 0; e < E; e++) {
			cin >> from >> to >> weight;

			from_in = from * 2;
			from_out = from_in + 1;
			to_in = to * 2;
			to_out = to_in + 1;

			capacities[from_out][to_in] = 1;
			costs[from_out][to_in] = weight;
			costs[to_in][from_out] = -weight;
			adj_list[from_out].push_back(to_in);
			adj_list[to_in].push_back(from_out);
		}

		cout << MCMF(3, V * 2) << "\n";
	}
	return 0;
}