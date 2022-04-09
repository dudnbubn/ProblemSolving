#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
vector<int> v[10001];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	int p, d, maximum = 0;
	for (int i = 0; i < n; i++) {
		cin >> p >> d;
		v[d].push_back(p);
		maximum = maximum > d ? maximum : d;
	}

	for (int i = 1; i <= maximum; i++) {
		for (int j = 0; j < v[i].size(); j++)	pq.push(v[i][j]);
		while (pq.size() > i)	pq.pop();
	}

	int result = 0;
	while (!pq.empty()) {
		result += pq.top();
		pq.pop();
	}
	cout << result;
	return 0;
}