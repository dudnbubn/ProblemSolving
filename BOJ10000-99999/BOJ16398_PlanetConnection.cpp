#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int dist[1001][1001];
int status[1001];

long long MST() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, 1 });
	
	long long result = 0;
	pair<int, int> cur;
	for (int i = 1; i <= n; i++) {
		cur = pq.top();
		pq.pop();
		while (status[cur.second] == 2) {
			cur = pq.top();
			pq.pop();
		}
		
		status[cur.second] = 2;
		result += cur.first;
		for (int j = 1; j <= n; j++) {
			if (j == cur.second)	continue;
			switch (status[j]) {
			case 0:
				status[j] = 1;
			case 1:
				pq.push({ dist[cur.second][j], j });
			}
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> dist[i][j];
	
	cout << MST();
	return 0;
}