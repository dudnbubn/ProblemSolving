#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_C 20'000

int C, N;
int chickens[MAX_C];
bool is_visited[MAX_C];

struct compare {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.second == b.second)	return a.first > b.first;
		return a.second > b.second;
	}
};

priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> C >> N;
	for (int c = 0; c < C; c++)	cin >> chickens[c];
	sort(chickens, chickens + C);

	int a, b;
	for (int n = 0; n < N; n++) {
		cin >> a >> b;
		pq.push({ a,b });
	}

	int result = 0;
	pair<int, int> current;
	int index;
	while (!pq.empty()) {
		current = pq.top();
		pq.pop();

		a = current.first;
		b = current.second;
		index = lower_bound(chickens, chickens + C, a) - chickens;
		while (index < C && chickens[index] <= b) {
			if (is_visited[index]) {
				index++;
				continue;
			}

			result++;
			is_visited[index] = true;
			break;
		}
	}
	cout << result;
	return 0;
}