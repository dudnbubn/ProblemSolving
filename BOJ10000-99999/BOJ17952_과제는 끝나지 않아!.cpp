#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, pair<int, int>> piii;

priority_queue<piii, vector<piii>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	int result = 0;
	int command, A, T;
	piii current;
	for (int n = 0; n < N; n++) {
		cin >> command;
		if (command) {
			cin >> A >> T;
			pq.push({ n, {A, T} });
		}
		if (!pq.empty()) {
			current = pq.top();
			pq.pop();
			pq.push({ current.first, {current.second.first, current.second.second - 1} });

			if(pq.top().second.second == 0) {
				result += pq.top().second.first;
				pq.pop();
			}
		}
	}
	cout << result;

}