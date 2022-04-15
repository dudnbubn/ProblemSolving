#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[200001];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int a, b, range = 0;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		range = range > a ? range : a;
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