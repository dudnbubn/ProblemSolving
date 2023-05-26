#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_N 400
#define MAX_P 10'000
#define INF 2'147'483'647

int N, P;
int capacities[(MAX_N + 1) * 2][(MAX_N + 1) * 2];
int flows[(MAX_N + 1) * 2][(MAX_N + 1) * 2];
int prevs[(MAX_N + 1) * 2];

queue<int> q;

int max_flow(int source, int sink) {
	int result = 0;

	while (true) {
		for (int i = 1; i <= N * 2 + 1; i++)	prevs[i] = -1;
		q = {};

		q.push(source);
		prevs[source] = source;
		int from;
		while (!q.empty()) {
			from = q.front();
			q.pop();

			for (int to = 1; to <= N * 2 + 1; to++) {
				if (capacities[from][to] - flows[from][to] > 0 && prevs[to] == -1) {
					q.push(to);
					prevs[to] = from;
				}
			}
		}

		if (prevs[sink] == -1)	break;

		int flow = MAX_P;
		for (int to = sink; to != source; to = prevs[to]) {
			from = prevs[to];
			flow = min(flow, capacities[from][to] - flows[from][to]);
		}

		for (int to = sink; to != source; to = prevs[to]) {
			from = prevs[to];
			
			flows[from][to] += flow;
			flows[to][from] -= flow;
		}

		result += flow;
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> P;
	int from, to;
	int from_in, from_out, to_in, to_out;

	for (int i = 1; i <= N; i++) {
		capacities[i * 2][i * 2 + 1] = 1;
	}
	for (int p = 0; p < P; p++) {
		cin >> from >> to;
		from_in = from * 2;
		from_out = from_in + 1;
		to_in = to * 2;
		to_out = to_in + 1;
		
		capacities[from_out][to_in] = INF;
		capacities[to_out][from_in] = INF;
	}

	int source_out = 1 * 2 + 1, sink_in = 2 * 2;
	cout << max_flow(source_out, sink_in);
	return 0;

	
}