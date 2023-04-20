#include <iostream>
#include <queue>

using namespace std;

#define ENDPOINT 500'000
#define NOT_VISITED -1

int visited[ENDPOINT + 1][2];

queue<int> q;

int main() {
	int N, K;
	cin >> N >> K;

	for (int i = 0; i <= ENDPOINT; i++)	
		visited[i][0] = visited[i][1] = NOT_VISITED;

	visited[N][0] = visited[N][1] = 0;
	q.push(N);

	int current;
	int level = 0, qsz;
	while (!q.empty()) {
		level++;
		qsz = q.size();
		for (int sz = 0; sz < qsz; sz++) {
			current = q.front();
			q.pop();

			if (current > 0 && visited[current - 1][level & 1] == NOT_VISITED) {
				visited[current - 1][level & 1] = level;
				q.push(current - 1);
			}
			if (current < ENDPOINT && visited[current + 1][level & 1] == NOT_VISITED) {
				visited[current + 1][level & 1] = level;
				q.push(current + 1);
			}
			if (current * 2 <= ENDPOINT && visited[current * 2][level & 1] == NOT_VISITED) {
				visited[current * 2][level & 1] = level;
				q.push(current * 2);
			}
		}
	}
	
	int result = -1;
	int interval = 0, gap;
	while (K <= ENDPOINT) {
		gap = interval - visited[K][interval & 1];
		if (gap >= 0 && !(gap & 1)) {
			cout << "K = " << K << ", interval = " << interval << "\n";
			result = interval;
			break;
		}
		interval++;
		K += interval;
	}
	cout << result;
	return 0;
}