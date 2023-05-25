#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_N 400
#define MAX_P 10'000

int N, P;
int capacity[MAX_N + 1][MAX_N + 1];
int flow[MAX_N + 1][MAX_N + 1];
int prevs[MAX_N + 1];

queue<int> q;

int max_flow(int source, int sink) {
	int result = 0;

	while (true) {
		for (int i = 1; i <= N; i++)	prevs[i] = -1;
		q = {};

		q.push(source);
		prevs[source] = source;
		int from;
		while (!q.empty()) {
			from = q.front();
			q.pop();

			for (int to = 1; to <= N; to++) {
				if (capacity[from][to] - flow[from][to] > 0 && prevs[to] == -1) {
					q.push(to);
					prevs[to] = from;
				}
			}
		}

		if (prevs[sink] == -1)	break;

		int amount = MAX_P;
		for (int pointer = sink; pointer != source; pointer = prevs[pointer]) {
			amount = min(amount, capacity[prevs[pointer]][pointer] - flow[prevs[pointer]][pointer]);
		}
		
		for (int pointer = sink; pointer != source; pointer = prevs[pointer]) {
			flow[prevs[pointer]][pointer] += amount;
			flow[pointer][prevs[pointer]] -= amount;
		}
		result += amount;
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> P;
	int from, to;
	for (int p = 0; p < P; p++) {
		cin >> from >> to;
		capacity[from][to] = 1;
	}

	cout << max_flow(1, 2);
	return 0;
}