#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[1001];

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, d, w, range = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> d >> w;
		v[d].push_back(w);
		range = range > d ? range : d;
	}
	
	for (int i = 1; i <= range; i++) {
		for (int j = 0; j < v[i].size(); j++)
			pq.push(v[i][j]);
		while (pq.size() > i)
			pq.pop();
	}

	int result = 0;
	while (!pq.empty()) {
		result += pq.top();
		pq.pop();
	}
	cout << result;

	return 0;
}