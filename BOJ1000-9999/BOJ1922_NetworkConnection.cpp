// key point : Minimum Spanning Tree

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int status[1001] = { 0, };
vector<pair<int, int>> v[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (a == b)	continue;
		v[a].push_back({ c,b });
		v[b].push_back({ c,a });
	}

	int cnt = n - 1;
	int result = 0;

	status[1] = 2;
	for (int i = 0; i < v[1].size(); i++) {
		pq.push(v[1][i]);
		status[v[1][i].second] = 1;
	}

	pair<int, int> cur;
	while (cnt) {
		cur = pq.top();
		pq.pop();
		while (status[cur.second] == 2) {
			cur = pq.top();
			pq.pop();
		}
		result += cur.first;
		cnt--;
		status[cur.second] = 2;
		for (int i = 0; i < v[cur.second].size(); i++) {
			switch (status[v[cur.second][i].second]) {
			case 0:
				status[v[cur.second][i].second] = 1;
				pq.push(v[cur.second][i]);
				break;
			case 1:
				pq.push(v[cur.second][i]);
				break;
			}
		}
	}
	cout << result;
	return 0;
}